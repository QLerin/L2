#include "ConsoleWindow.h"
#include "Colorizer.h"

using namespace std;
using namespace l2::rendering;

ConsoleWindow::ConsoleWindow(const bool isConsoleApp) : currentBuffer_(FRONT_BUFFER),
														frontBuffer_(new Frame(isConsoleApp)),
														backBuffer_(new Frame(isConsoleApp))
{
}

void ConsoleWindow::SwapBuffers()
{
	switch (currentBuffer_)
	{
	case FRONT_BUFFER:
		currentBuffer_ = BACK_BUFFER;
		if(backBuffer_)
			backBuffer_->Draw();
		break;
	case BACK_BUFFER:
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