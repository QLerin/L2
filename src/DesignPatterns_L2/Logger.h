#pragma once

#ifdef _WINDOWS
#include <Windows.h>
#endif

#include <fstream>
#include <atomic>
#include <iomanip>
#include <thread>
#include <mutex>
#include <queue>
#include <sstream>

#include "Singleton.h"

namespace l2
{

	namespace sys
	{
		typedef std::queue<std::string *> t_logQueue;

		class Logger : public Singleton<Logger>
		{
            friend Singleton<Logger>;
		private:
            Logger();
            Logger(const Logger & right) = delete;
			t_logQueue logQueue_;
			std::thread logThread_;
            std::mutex writeGuard_;

			std::atomic<bool> isInitialized_;
            HANDLE hSemaphore_;
            std::ofstream output_;
			std::string filePath_;

			void LoggerProcess();

			/// Logs a formed message
			///
			/// Called from function with specifig log levels
			void LogMessage(const std::string & header, const std::string & functionName, const std::string & errMsg);
		public:
            ~Logger();

			void LogError(const std::string & functionName, const std::string & errMsg);
			void LogInfo(const std::string & functionName, const std::string & errMsg);
			void LogWarning(const std::string & functionName, const std::string & errMsg);

			const bool IsInitialized() { return isInitialized_; }
            bool Initialize(const std::string & logFile);
            void Stop();
		};

#ifndef LOG_DEFINES

#define LOG_ERROR(message)          Logger::GetInstance()->LogError(__FUNCTION__, message)
#define LOG_INFO(message)           Logger::GetInstance()->LogInfo(__FUNCTION__, message)
#define LOG_WARNING(message)        Logger::GetInstance()->LogWarning(__FUNCTION__, message)

#endif

	}

}