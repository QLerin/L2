#include "Frame.h"
#include "IDrawable.h"
#include "Colorizer.h"
#include <string>
#include "Logger.h"

using namespace std;
using namespace l2::sys;
using namespace l2::rendering;

uint16_t Frame::numActiveBuffers_ = 0;

static const uint16_t ASCII_CP = 20127;

Frame::Frame(const bool isConsoleApp)
{
    if (isConsoleApp && !numActiveBuffers_)
    {
        LOG_INFO("Initializing first console buffer from provided standard output.");
        frameBuffer_ = GetStdHandle(STD_OUTPUT_HANDLE);
        if (frameBuffer_ == INVALID_HANDLE_VALUE)
        {
            LOG_ERROR("Retrieval of standard output buffer failed. Exiting.");
            exit(-1);
        }
        LOG_INFO("Framebuffer with handle: " + std::to_string((PTR_TYPE)frameBuffer_) + " retrieved");
    }
	else
	{
		if (!numActiveBuffers_)
		{
            if (AllocConsole())
            {
                AttachConsole(ATTACH_PARENT_PROCESS);
                SetConsoleCP(ASCII_CP);
                SetConsoleOutputCP(ASCII_CP);
            }
            else
                LOG_WARNING("Allocation of console failed!");
		}
		frameBuffer_ = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
        if (frameBuffer_ == INVALID_HANDLE_VALUE)
        {
            LOG_INFO("Allocation of console output buffer No: " + std::to_string(numActiveBuffers_ + 1) + "has failed. Exiting.");
            exit(-1);
        }
	}
    
    // Make cursor invisible and set to full-screen (maximized) mode
    if (frameBuffer_ != 0)
    {
        CONSOLE_CURSOR_INFO cursor;
        ZeroMemory(&cursor, sizeof(cursor));
        cursor.bVisible = FALSE;
        cursor.dwSize = 100;
        SetConsoleCursorInfo(frameBuffer_, &cursor);

        COORD size = GetLargestConsoleWindowSize(frameBuffer_);
        SetConsoleScreenBufferSize(frameBuffer_, size);

        SMALL_RECT windowSize;
        ZeroMemory(&windowSize, sizeof(windowSize));

        // Set to (N-1) because function fails if param is GEQ N
        windowSize.Bottom = size.Y-1;
        windowSize.Right = size.X-1;

        width_ = size.X;
        height_ = size.Y;

        BOOL result = SetConsoleWindowInfo(frameBuffer_, TRUE, &windowSize);
        if (result == 0)
        {
            DWORD error = GetLastError();
            LOG_ERROR("Failed to set console window to full-screen. Error code: " + to_string(error));
        }
    }
    
	++numActiveBuffers_;
}

Frame::~Frame()
{
	CloseHandle(frameBuffer_);
	if (!(--numActiveBuffers_))
		FreeConsole();
}

void Frame::WriteBuffer(const IDrawable & drawable)
{	
	COORD cursorPosition;
	ZeroMemory(&cursorPosition, sizeof(cursorPosition));
	for (uint16_t i = 0; i < drawable.height_; ++i)
	{
		cursorPosition.Y = drawable.y_ + i;
		cursorPosition.X = drawable.x_;
		SetConsoleCursorPosition(frameBuffer_, cursorPosition);

		{
			DWORD actualCharsWritten(0);
			BOOL rc = WriteConsole(frameBuffer_, &(drawable.drawableData_.c_str()[drawable.width_*i]), drawable.width_, &actualCharsWritten, nullptr);
            if (!rc)
                LOG_ERROR("Error while attempting to write console output buffer. \n DATA DUMP: " + drawable.drawableData_);
        }
	}
}

void Frame::Clear(const uint16_t x, const uint16_t y, uint16_t width, uint16_t height)
{
	if (!x && !y && !width && !height)
	{
        LOG_INFO("Full-screen clear requested.");
		width = width_;
		height = height_;
	}
	
	CONSOLE_SCREEN_BUFFER_INFO colorInformation;
	ZeroMemory(&colorInformation, sizeof(colorInformation));
	GetConsoleScreenBufferInfo(frameBuffer_, &colorInformation);

	Colorizer::COLOR_ATTRIBUTES attributes;
	ZeroMemory(&attributes, sizeof(attributes));
	attributes.backgroundColor = Colorizer::Black;
	attributes.foregroundColor = Colorizer::White;
	Colorizer::GetInstance()->Colorize(*this, attributes);

	shared_ptr<char> clearBuffer(new char[width], default_delete<char[]>());
	memset(clearBuffer.get(), ' ', sizeof(char) * width);

	COORD cursorPosition;
	ZeroMemory(&cursorPosition, sizeof(cursorPosition));

	for (uint16_t i = 0; i < height; ++i)
	{
		cursorPosition.Y = i;
		DWORD actual(0);
        if (!WriteConsole(frameBuffer_, clearBuffer.get(), width_, &actual, nullptr))
            LOG_ERROR("Error occured while clearing BackBuffer");
	}
    
    LOG_INFO("BackBuffer cleared with foreground: White and background: Black");

	Colorizer::GetInstance()->Colorize(*this, colorInformation.wAttributes);
}

void Frame::Draw()
{
    LOG_INFO("Swapping active console buffers");
	SetConsoleActiveScreenBuffer(frameBuffer_);
}