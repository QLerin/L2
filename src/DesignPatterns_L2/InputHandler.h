#pragma once

#include "Message.h"
#include "Receiver.h"
#include "InputManager.h"

namespace l2
{

	namespace sys
	{

		class InputHandler : public Receiver<Message>
		{
		protected:
			InputHandler() = default;    
			InputHandler(const InputHandler & right) = delete;
		public:
			virtual void HandleMessage(const std::shared_ptr<Message> & message) = 0;
		};

	}

}