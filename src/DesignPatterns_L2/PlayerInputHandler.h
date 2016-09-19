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
			virtual void OnKeyQ();
			virtual void OnKeyW();
			virtual void OnKeyE();
			virtual void OnKeyR();
			virtual void OnKeyESC();
			virtual void OnKeyI();
		public:
			PlayerInputHandler() = default;
			virtual void HandleInput(const InputManager::ConsoleInput inputEvent);
		};

	}

}