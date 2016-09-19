#include "Frame.h"
#include "IDrawable.h"
#include "Colorizer.h"
#include <string>

using namespace std;
using namespace l2::rendering;

uint16_t Frame::numActiveBuffers_ = 0;

static const uint16_t ASCII_CP = 20127;

Frame::Frame(const bool isConsoleApp)
{
 	if (isConsoleApp && !numActiveBuffers_)
		frameBuffer_ = GetStdHandle(STD_OUTPUT_HANDLE);
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
		}
		frameBuffer_ = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
#ifdef _DEBUG
		if (frameBuffer_ == INVALID_HANDLE_VALUE)
		{
			DWORD rc = GetLastError();
			printf("%d", rc);
		}
#endif
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
	//Clear(drawable.x_, drawable.y_, drawable.width_, drawable.height_);

	COORD cursorPosition;
	ZeroMemory(&cursorPosition, sizeof(cursorPosition));
	for (uint16_t i = 0; i < drawable.height_; ++i)
	{
		cursorPosition.Y = drawable.y_ + i;
		cursorPosition.X = drawable.x_;
		SetConsoleCursorPosition(frameBuffer_, cursorPosition);

		{
			DWORD actualCharsWritten(0);
			WriteConsole(frameBuffer_, &(drawable.drawableData_.c_str()[drawable.width_*i]), drawable.width_, &actualCharsWritten, nullptr);
			
#pragma message ("If actual characters written does not match the argument provided, an error probably occured. LOG THIS")
			printf("placeholder");
		}
	}
}

void Frame::Clear(const uint16_t x, const uint16_t y, uint16_t width, uint16_t height)
{
	if (!x && !y && !width && !height)
	{
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
	memset(clearBuffer.get(), '*', sizeof(char) * width);

	COORD cursorPosition;
	ZeroMemory(&cursorPosition, sizeof(cursorPosition));

	for (uint16_t i = 0; i < height; ++i)
	{
		cursorPosition.Y = i;
		DWORD actual(0);
		WriteConsole(frameBuffer_, clearBuffer.get(), width_, &actual, nullptr);
	}

	Colorizer::GetInstance()->Colorize(*this, colorInformation.wAttributes);
}

void Frame::Draw()
{
	SetConsoleActiveScreenBuffer(frameBuffer_);
}