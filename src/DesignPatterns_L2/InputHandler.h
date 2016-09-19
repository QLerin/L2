#pragma once

#include "InputManager.h"

namespace l2
{

	namespace sys
	{

		class InputHandler
		{
		protected:
			InputHandler() = default;
			InputHandler(const InputHandler & right) = delete;
		public:
			virtual void HandleInput(const InputManager::ConsoleInput inputEvent) = 0;
		};

	}

}