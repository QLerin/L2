#include "Colorizer.h"
#include "Frame.h"
#include "Logger.h"

using namespace std;
using namespace l2::rendering;

const Colorizer::Color Colorizer::GetColorFromChar(const char id)
{
	switch (id)
	{
	case 'W': //White
		return Colorizer::White;
	case 'O': //Black (O for Onyx)
		return Colorizer::Black;
	case 'R': //Red
		return Colorizer::Red;
	case 'G': //Green
		return Colorizer::Green;
	case 'B': //Blue
		return Colorizer::Blue;
	case 'Y': //Yellow
		return Colorizer::Yellow;
	case 'P': //Purple
		return Colorizer::Purple;
	case 'M': //Brown (M for Maroon)
		return Colorizer::Brown;
	}
	return Colorizer::White;
}

void Colorizer::Colorize(const Frame & frame, const WORD attributes)
{
	SetConsoleTextAttribute(frame.GetBufferHandle(), attributes);
}

void Colorizer::Colorize(const Frame & frame, const COLOR_ATTRIBUTES attributes)
{
	if (!SetConsoleTextAttribute(frame.GetBufferHandle(), GetConsoleColor(attributes)))
	{
        LOG_WARNING("Failed to set frame color. Framebuffer handle: " + std::to_string((PTR_TYPE)frame.GetBufferHandle()));
	}
}

WORD Colorizer::GetConsoleColor(const COLOR_ATTRIBUTES attributes)
{
	return GetForegroundColor(attributes) | GetBackgroundColor(attributes);
}

WORD Colorizer::GetForegroundColor(const COLOR_ATTRIBUTES attributes)
{
#define intensify(arg) (FOREGROUND_INTENSITY | (arg))

    WORD rc = 0;

	switch (attributes.foregroundColor)
	{
	case White:
		rc = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
        break;
	case Red:
		return FOREGROUND_RED;
        break;
	case Green:
        rc = FOREGROUND_GREEN;
        break;
	case Blue:
        rc = FOREGROUND_BLUE;
        break;
	case Yellow:
        rc = FOREGROUND_BLUE | FOREGROUND_GREEN;
        break;
	case Brown:
        rc = FOREGROUND_GREEN | FOREGROUND_RED;
        break;
	case Purple:
        rc = FOREGROUND_BLUE | FOREGROUND_RED;
        break;
	}
    
	return intensify(rc);
}

WORD Colorizer::GetBackgroundColor(const COLOR_ATTRIBUTES attributes)
{
	switch (attributes.backgroundColor)
	{
	case White:
		return BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED;
	case Red:
		return BACKGROUND_RED;
	case Green:
		return BACKGROUND_GREEN;
	case Blue:
		return BACKGROUND_BLUE;
	case Yellow:
		return BACKGROUND_BLUE | BACKGROUND_GREEN;
	case Brown:
		return BACKGROUND_GREEN | BACKGROUND_RED;
	case Purple:
		return BACKGROUND_BLUE | BACKGROUND_RED;
	}

	
	return 0;
}