#pragma once

#include "InputHandler.h"

namespace l2
{
	namespace sys
	{
		class MenuInputHandler : public InputHandler
		{
		private:
			MenuInputHandler(const MenuInputHandler & right) = delete;
		protected:
			void (*OnKeyUp)();
			void (*OnKeyDown)();
			void (*OnKeyLeft)();
			void (*OnKeyRight)();
			void (*OnKeyEnter)();
			void (*OnKeyEsc)();
		public:
			MenuInputHandler() = default;
			void HandleInput(const InputManager::ConsoleInput inputEvent);
		};
	}
}