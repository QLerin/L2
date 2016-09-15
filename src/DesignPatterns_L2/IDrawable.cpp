#include "GameManager.h"
#include "IDrawable.h"
#include "Frame.h"
#include <string>

using namespace std;
using namespace l2::rendering;

IDrawable::IDrawable(const uint16_t width, const uint16_t height, const std::shared_ptr<Frame> parentFrame) : x_(0), y_(0), parentFrame_(parentFrame)
{
	imageBuffer_.resize(height);
	for (string & row : imageBuffer_)
		row.resize(width, FD_EMPTY);
}

void IDrawable::SetImage(const t_ImageBuffer & asciiImage)
{
	if (asciiImage.size())
		return;
}

void IDrawable::Draw()
{
	if (parentFrame_)
		parentFrame_->Draw(*this);
}

void IDrawable::MovePosition(const uint16_t x, const uint16_t y)
{
	x_ += x;
	y_ += y;
}

void IDrawable::SetPosition(const uint16_t x, const uint16_t y)
{
	x_ = x;
	y_ = y;
}