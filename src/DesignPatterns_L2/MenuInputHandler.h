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
			virtual void OnKeyUp();
			virtual void OnKeyDown();
			virtual void OnKeyLeft();
			virtual void OnKeyRight();
			virtual void OnKeyEnter();
			virtual void OnKeyEsc();
		public:
			MenuInputHandler() = default;
			virtual void HandleInput(const InputManager::ConsoleInput inputEvent);
		};
	}
}