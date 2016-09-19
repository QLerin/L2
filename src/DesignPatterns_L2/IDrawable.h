#pragma once

#include <Windows.h>
#include <memory>
#include <vector>

namespace l2
{

	namespace rendering
	{

		class Frame;
		class ConsoleWindow;

		class IDrawable
		{
			friend Frame;
			friend ConsoleWindow;
		protected:
			IDrawable() = delete;

			std::shared_ptr<ConsoleWindow> parentWindow_;
			std::string drawableData_;

			bool isDataSet_;
			bool isSpaceSet_;

			uint16_t x_, y_, width_, height_;
		public:
			IDrawable(const IDrawable & right);
			IDrawable(std::shared_ptr<ConsoleWindow> parentWindow);
			void SetDrawableData(const std::string & data);
			void SetDrawableSpace(const uint16_t x, const uint16_t y, const uint16_t width, const uint16_t height);

			const bool IsDataSet() { return isDataSet_; }
			const bool IsSpaceSet() { return isSpaceSet_; }

			virtual void Draw();
		};

	}

}