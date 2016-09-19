#include "ConsoleWindow.h"
#include "ColorizedDrawable.h"

using namespace std;
using namespace l2::rendering;

ColorizedDrawable::ColorizedDrawable(const ColorizedDrawable & right) : IDrawable(right.parentWindow_)
{
	drawableData_ = right.drawableData_;
	x_ = right.x_;
	y_ = right.y_;
	width_ = right.width_;
	height_ = right.height_;
}

ColorizedDrawable::ColorizedDrawable(std::shared_ptr<ConsoleWindow> parentWindow) : IDrawable(parentWindow)
{
}

void ColorizedDrawable::SetColor(const Colorizer::Color foregroundColor, const Colorizer::Color backgroundColor)
{
	colorInfo_.backgroundColor = backgroundColor;
	colorInfo_.foregroundColor = foregroundColor;
}

void ColorizedDrawable::Draw()
{
	parentWindow_->SetColor(colorInfo_);
	__super::Draw();
}