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
			std::shared_ptr<ConsoleWindow> parentWindow_;
			std::string drawableData_;

			bool isDataSet_;
			bool isSpaceSet_;

			uint16_t x_, y_, width_, height_;
		public:
            IDrawable() : parentWindow_(nullptr), drawableData_(""), isDataSet_(false), isSpaceSet_(false),
                          x_(0), y_(0), width_(0), height_(0) { }
			IDrawable(const IDrawable & right);
			IDrawable(std::shared_ptr<ConsoleWindow> parentWindow);

			void SetDrawableData(const std::string & data);
			std::string & GetDrawableData() { return drawableData_; }

			void SetDrawableSpace(const uint16_t x, const uint16_t y, const uint16_t width, const uint16_t height);
            const bool GetDrawableSpace(uint16_t & x, uint16_t & y, uint16_t & width, uint16_t & height) const
            {
                x = x_; y = y_; width = width_; height = height_;

                return isSpaceSet_;
            }

			const bool IsDataSet() const { return isDataSet_; }
			const bool IsSpaceSet() const { return isSpaceSet_; }

            void SetParentWindow(std::shared_ptr<ConsoleWindow> parent) { parentWindow_ = parent; }

			virtual void Draw();
		};

	}

}