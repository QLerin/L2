#include "Colorizer.h"
#include "Frame.h"
#include "Logger.h"

using namespace std;
using namespace l2::rendering;

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
	switch (attributes.foregroundColor)
	{
	case White:
		return FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
	case Red:
		return FOREGROUND_RED;
	case Green:
		return FOREGROUND_GREEN;
	case Blue:
		return FOREGROUND_BLUE;
	case Yellow:
		return FOREGROUND_BLUE | FOREGROUND_GREEN;
	case Brown:
		return FOREGROUND_GREEN | FOREGROUND_RED;
	case Purple:
		return FOREGROUND_BLUE | FOREGROUND_RED;
	}

	return 0;
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