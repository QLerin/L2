#pragma once

#include <Windows.h>
#include <stdint.h>

namespace l2
{

	namespace rendering
	{

		class IDrawable;

		class Frame
		{
		private:
			/// Handle to the frame buffer ( a console window buffer )
			HANDLE frameBuffer_;
			uint16_t width_, height_;
			static uint16_t numActiveBuffers_;
		public:
			Frame() = delete;
			Frame(const Frame & right) = delete;
			Frame(const bool isConsoleApp);
			~Frame();

			/// Retrieves the assigned framebuffer handle
			const HANDLE GetBufferHandle() const { return frameBuffer_; }
			void WriteBuffer(const IDrawable & drawable);

			/// Clears the entire framebuffer
			void Clear(const uint16_t x = 0, const uint16_t y = 0, uint16_t width = 0, uint16_t height = 0);
			/// Displays the associated frame buffer
			///
			/// \note this finalizes a buffer swap from ConsoleWindow
			void Draw();

			static const uint16_t GetNumActiveBuffers() { return numActiveBuffers_; }
		};

	}

}