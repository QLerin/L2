#pragma once

#include <Windows.h>
#include "Singleton.h"
#include <memory>

namespace l2s = l2::sys;

namespace l2
{

	namespace rendering
	{

		class Frame;

		class Colorizer : public l2s::Singleton<Colorizer>
		{
			friend l2s::Singleton<Colorizer>;
		public:
			enum Color
			{
				White = 0,
				Red,
				Green,
				Blue,
				Yellow,
				Brown,
				Purple,
				Black
			};

			struct COLOR_ATTRIBUTES
			{
				Color backgroundColor;
				Color foregroundColor;
			};

		private:
			Colorizer() : Singleton<Colorizer>() { }
			Colorizer(const Colorizer & right) = delete;

			WORD GetForegroundColor(const COLOR_ATTRIBUTES attributes);
			WORD GetBackgroundColor(const COLOR_ATTRIBUTES attributes);
			WORD GetConsoleColor(const COLOR_ATTRIBUTES attributes);
		public:
			void Colorize(const Frame & frame, const WORD attributes);
			void Colorize(const Frame & frame, const COLOR_ATTRIBUTES attributes);
		};

	}

}