#include "ConsoleWindow.h"
#include "Colorizer.h"
#include "Logger.h"

using namespace std;
using namespace l2::sys;
using namespace l2::rendering;

static const std::string WINDOW_TITLE = "Placeholder Title";

ConsoleWindow::ConsoleWindow(const bool isConsoleApp) : currentBuffer_(FRONT_BUFFER),
														frontBuffer_(new Frame(isConsoleApp)),
														backBuffer_(new Frame(isConsoleApp))
{
    //ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
    SetConsoleTitle(WINDOW_TITLE.c_str());
    //SetWindowLong(GetConsoleWindow(), GWL_STYLE, WS_CAPTION | DS_MODALFRAME | WS_OVERLAPPED);
    //SetWindowPos(GetConsoleWindow(), NULL, 0, 0, 0, 0, SWP_NOSIZE | SWP_SHOWWINDOW);

    SetActiveWindow(GetConsoleWindow());
}

void ConsoleWindow::SwapBuffers()
{
    LOG_INFO("Swapping active screen buffers...");
	switch (currentBuffer_)
	{
	case FRONT_BUFFER:
        LOG_INFO("Swapping to Front buffer");
		currentBuffer_ = BACK_BUFFER;
		if(backBuffer_)
			backBuffer_->Draw();
		break;
	case BACK_BUFFER:
        LOG_INFO("Swapping to back buffer");
		currentBuffer_ = FRONT_BUFFER;
		if(frontBuffer_)
			frontBuffer_->Draw();
	}
}

void ConsoleWindow::Draw(const IDrawable & drawable)
{
	switch (currentBuffer_)
	{
	case FRONT_BUFFER:
		if (backBuffer_)
			backBuffer_->WriteBuffer(drawable);
		break;
	case BACK_BUFFER:
		if (frontBuffer_)
			frontBuffer_->WriteBuffer(drawable);
	}
}

void ConsoleWindow::ClearActiveBuffer()
{
	switch (currentBuffer_)
	{
	case FRONT_BUFFER:
		if (backBuffer_)
			backBuffer_->Clear();
		break;
	case BACK_BUFFER:
		if (frontBuffer_)
			frontBuffer_->Clear();
	}
}

void ConsoleWindow::SetColor(const Colorizer::COLOR_ATTRIBUTES & attributes)
{
	switch (currentBuffer_)
	{
	case FRONT_BUFFER:
		if (backBuffer_)
			Colorizer::GetInstance()->Colorize(*backBuffer_, attributes);
		break;
	case BACK_BUFFER:
		if (frontBuffer_)
			Colorizer::GetInstance()->Colorize(*frontBuffer_, attributes);
	}
}