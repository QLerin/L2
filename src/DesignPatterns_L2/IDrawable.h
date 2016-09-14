#pragma once

#include <stdint.h>
#include <vector>

namespace l2
{

	namespace rendering
	{
		class Frame;

		class IDrawable
		{
			friend Frame;
		private:
			IDrawable() = delete;
			IDrawable(const IDrawable * right);
			std::vector<std::vector<char>> imageBuffer_;

			uint16_t x_, y_;
		public:
			IDrawable(const uint16_t width, const uint16_t height);
			void SetImage(const char * const asciiImage);
			void Draw(Frame & frame);
		};

	}

}