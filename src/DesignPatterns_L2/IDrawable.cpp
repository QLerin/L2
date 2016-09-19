#include "ConsoleWindow.h"
#include "IDrawable.h"

using namespace std;
using namespace l2::rendering;

IDrawable::IDrawable(const IDrawable & right) : isDataSet_(right.isDataSet_), isSpaceSet_(right.isSpaceSet_), parentWindow_(right.parentWindow_),
												x_(right.x_), y_(right.y_), width_(right.width_), height_(right.height_)
{
}

IDrawable::IDrawable(shared_ptr<ConsoleWindow> parentWindow)
{
	parentWindow_ = parentWindow;
}

void IDrawable::SetDrawableSpace(const uint16_t x, const uint16_t y, const uint16_t width, const uint16_t height)
{
	x_ = x;
	y_ = y;
	width_ = width;
	height_ = height;

	isSpaceSet_ = true;
}

void IDrawable::SetDrawableData(const string & data)
{
	drawableData_ = data;
	isDataSet_ = true;
}

void IDrawable::Draw()
{
	if (parentWindow_ && isDataSet_ && isSpaceSet_)
		parentWindow_->Draw(*this);
}