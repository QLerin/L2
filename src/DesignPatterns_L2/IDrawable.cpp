#include "IDrawable.h"
#include "Frame.h"
#include <string>

using namespace std;
using namespace l2::rendering;

IDrawable::IDrawable(const uint16_t width, const uint16_t height) : x_(0), y_(0)
{
	imageBuffer_.resize(height);
	for (std::vector<char> & row : imageBuffer_)
		row.resize(width);
}

void IDrawable::SetImage(const char * const asciiImage)
{
	if (asciiImage)
		return;
}

void IDrawable::Draw(Frame & frame)
{
	frame.Draw(*this);
}