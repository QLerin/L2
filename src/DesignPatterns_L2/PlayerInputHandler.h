#pragma once

#include "InputHandler.h"

namespace l2
{

	namespace sys
	{

		class PlayerInputHandler : public InputHandler
		{
		private:
			PlayerInputHandler(const PlayerInputHandler & right) = delete;
		protected:
			void (*OnKeyQ)();
			void (*OnKeyW)();
			void (*OnKeyE)();
			void (*OnKeyR)();
			void (*OnKeyESC)();
			void (*OnKeyI)();
		public:
			PlayerInputHandler() = default;
			virtual void HandleInput(const InputManager::ConsoleInput inputEvent);
		};

	}

}