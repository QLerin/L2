#include "RenderDefines.h"
#include "Frame.h"
#include <memory>
#include <iostream>

using namespace std;
using namespace l2::rendering;

Frame::Frame(const uint16_t width, const uint16_t height) : width_(width), height_(height)
{
	if (width > MAX_WIDTH || height > MAX_HEIGHT)
	{
		isInitialized_ = false;
		return;
	}

	frameBuffer_ = vector<string>(height, string(width, ' '));

	isInitialized_ = true;

	WriteBounds();
}

void Frame::WriteBounds()
{
	if (!isInitialized_)
		return;

	frameBuffer_[0].replace(frameBuffer_[0].begin(), frameBuffer_[0].end(), width_, FD_WALL);
	frameBuffer_[height_ - 1].replace(frameBuffer_[height_-1].begin(), frameBuffer_[height_-1].end(), width_, FD_WALL);

	for (uint16_t i = 1; i < height_-1; ++i)
	{
		frameBuffer_[i][0] = FD_WALL;
		frameBuffer_[i][width_ - 1] = FD_WALL;
	}
}

void Frame::ClearArea(const uint16_t rowBegin, const uint16_t rowEnd, const uint16_t colBegin, const uint16_t colEnd, const char clearSymbol)
{
	if (!isInitialized_)
		return;

	for (uint16_t i = colBegin; i < colEnd; ++i)
		for (uint16_t j = rowBegin; j < rowEnd; ++j)
			frameBuffer_[i].replace(static_cast<size_t>(rowBegin), static_cast<size_t>(rowEnd), to_string(clearSymbol).c_str());
}

void Frame::Clear()
{
	if (!isInitialized_)
		return;
	ClearArea(0, width_, 0, width_, ' ');
}

Frame::~Frame()
{
}

void Frame::Draw(const IDrawable & drawable)
{
	drawable.x_;
}

void Frame::Display() const
{
	for (uint16_t i = 0; i < frameBuffer_.size(); ++i)
		cout << frameBuffer_[i] << endl;
}