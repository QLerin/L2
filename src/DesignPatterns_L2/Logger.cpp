#include "Logger.h"
#include <comdef.h>

using namespace std;
using namespace l2::sys;

const unsigned int MAX_HRESULT_ERRMSG_SIZE = 1024;
const long SEMAPHORE_MAX_COUNT = 100000;

static inline const std::string FormatHeader(const std::string & header)
{
	ostringstream oss;
	oss << left << "[" << setw(10) << header << setw(10) << "]";
	return oss.str();
}

static inline const std::string FormatFName(const std::string & functionName)
{
	ostringstream oss;
	oss << left << setw(10) << "In function: " "[" << setw(10) << functionName << setw(10) << "]:" << setw(10);
	return oss.str();
}

Logger::Logger() : hSemaphore_(NULL),
				   isInitialized_(false),
				   filePath_("")
								
{
}

Logger::~Logger()
{
    Stop();
}

bool Logger::Initialize(const std::string & logFile)
{
	// Just to be safe
	lock_guard<mutex> lock(writeGuard_);
	
	if (isInitialized_)
		return true;

	filePath_ = logFile;
	output_.open(filePath_);

	if (!output_.is_open())
		return false;

	hSemaphore_ = CreateSemaphore(NULL, 0, SEMAPHORE_MAX_COUNT, "LoggerSemaphore");

	if (!hSemaphore_)
	{
		output_.close();
		return false;
	}

	logThread_ = thread(bind(&Logger::LoggerProcess, this));

	isInitialized_ = true;

	return true;
}

void Logger::LogMessage(const string & header, const string & functionName, const std::string & errMsg)
{
	logQueue_.push(new string(header + functionName + errMsg));
	ReleaseSemaphore(hSemaphore_, 1, nullptr);
}

void Logger::LogError(const string & functionName, const string & errMsg)
{
	lock_guard<mutex> lock(writeGuard_);
	if (!isInitialized_)
		return;
	LogMessage(FormatHeader("ERROR"), FormatFName(functionName), errMsg);
}

void Logger::LogInfo(const string & functionName, const string & errMsg)
{
	lock_guard<mutex> lock(writeGuard_);
	if (!isInitialized_)
		return;

	LogMessage(FormatHeader("INFO"), FormatFName(functionName), errMsg);
}

void Logger::LogWarning(const string & functionName, const string & errMsg)
{
	lock_guard<mutex> lock(writeGuard_);
	if (!isInitialized_)
		return;

    LogMessage(FormatHeader("WARNING"), FormatFName(functionName) , errMsg);
}


void Logger::LoggerProcess()
{
    string * message = nullptr;

    while (true)
    {
        WaitForSingleObject(hSemaphore_, INFINITE);

        {
            lock_guard<mutex> lock(writeGuard_);
            message = (string *)logQueue_.front();
            logQueue_.pop();
        }

        if (message)
        {
            if (message->empty())
            {
                delete message;
                message = nullptr;
                break;
            }
            output_ << *message << endl;
        }

        delete message;
        message = nullptr;
    }

    lock_guard<mutex> lock(writeGuard_);

    while (logQueue_.size())
    {
        message = logQueue_.front();
        if (!message)
            continue;

        output_ << *message << endl;
        logQueue_.pop();

        delete message;
        message = nullptr;
    }

    output_ << "Logger exiting........" << endl;
}

void Logger::Stop()
{
    if (!isInitialized_)
    	return;

    {
        lock_guard<mutex> lock(writeGuard_);
        logQueue_.push(new string(""));
        ReleaseSemaphore(hSemaphore_, 1, nullptr);
    }

    logThread_.join();
    output_.close();
    CloseHandle(hSemaphore_);

    isInitialized_ = false;
}