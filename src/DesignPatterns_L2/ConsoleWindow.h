#pragma once

#include "Frame.h"
#include <memory>
#include "Colorizer.h"

namespace l2
{

	namespace rendering
	{

		class ConsoleWindow
		{
		private:
			ConsoleWindow() = delete;
			ConsoleWindow(const ConsoleWindow & right) = delete;

			static const uint16_t FRONT_BUFFER = 1;
			static const uint16_t BACK_BUFFER  = 2;

			std::shared_ptr<Frame> frontBuffer_;
			std::shared_ptr<Frame> backBuffer_;

			uint16_t currentBuffer_;
		public:
			ConsoleWindow(const bool isConsoleApp);

			void SetColor(const Colorizer::COLOR_ATTRIBUTES & attributes);

			void SwapBuffers();
			void Draw(const IDrawable & drawable);
			void ClearActiveBuffer();
		};

	}

}