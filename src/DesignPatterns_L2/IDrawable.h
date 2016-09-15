#pragma once

#include "RenderDefines.h"
#include <stdint.h>
#include <vector>
#include <memory>

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
			t_ImageBuffer imageBuffer_;

			uint16_t x_, y_;
			std::shared_ptr<Frame> parentFrame_;
		public:
			/// The only non-deleted constructor
			///
			/// Drawable should operate with preset values
			IDrawable(const uint16_t width, const uint16_t height, const std::shared_ptr<Frame> parentFrame);

			/// Set the ASCII image for drawing inside the console window
			///
			/// ASCII image should meet requirements set by constructor;
			void SetImage(const t_ImageBuffer & asciiImage);
			void Draw();

			void MovePosition(const uint16_t x, const uint16_t y);
			void SetPosition(const uint16_t x, const uint16_t y);
		};

	}

}