#pragma once

#include "InputHandler.h"
#include "MenuActionMessage.h"


namespace l2
{
	namespace sys
	{
		class MenuInputHandler : public InputHandler
		{
        protected:
            const bool ValidateMessage(const std::shared_ptr<Message> & message) const
            {
                if (message && message->GetMessageType() == MenuActionMessage::MENU_ACTION_MESSAGE)
                    return true;
                return false;
            }
        public:
            MenuInputHandler() { }
		};
	}
}