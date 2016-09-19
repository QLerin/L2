#pragma once

#include "DrawableGameObject.h"
#include "InputHandler.h"

namespace l2s = l2::sys;

namespace l2
{

	namespace gameobjects
	{

		class ControlledGameObject : public DrawableGameObject
		{
		protected:
			/// The input handler for the game object
			///
			std::shared_ptr<l2s::InputHandler> inputHandler_;
		public:
			ControlledGameObject(const ControlledGameObject & right);
			ControlledGameObject(const DrawableGameObject & right, l2s::InputHandler * inputHandler);

			void SetInputHandler(l2s::InputHandler * inputHandler);
			void SetInputHandler(std::shared_ptr<l2s::InputHandler> inputHandler);

			void React(const l2s::InputManager::ConsoleInput input);
		};

	}

}