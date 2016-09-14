#pragma once

#include "RenderDefines.h"
#include "IDrawable.h"
#include <vector>
#include <string>

namespace l2
{

	namespace rendering
	{

		class Frame
		{
		private:
			static const uint16_t MAX_WIDTH = 1920;
			static const uint16_t MAX_HEIGHT = 1080;

			Frame() = delete;
			Frame(const Frame & original) = delete;
			std::vector<std::string> frameBuffer_;

			uint16_t width_;
			uint16_t height_;

			bool isInitialized_;

			void WriteBounds();
		protected:
			void ClearArea(const uint16_t rowBegin, const uint16_t rowEnd, const uint16_t colBegin, const uint16_t colEnd, const char clearSymbol = ' ');
		public:
			Frame(const uint16_t width, const uint16_t height);
			virtual ~Frame();
			void Clear();

			const uint16_t GetRowBegin() { return 1; }
			const uint16_t GetColumnBegin() { return 1; }
			const uint16_t GetRowEnd() { return width_ - 2; }
			const uint16_t GetColumnEnd() { return height_ - 2; }

			void Draw(const IDrawable & drawable);
			void Display() const;
		};

	}

}