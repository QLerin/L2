#pragma once

#include "Message.h"
#include "IMenuAction.h"

namespace l2
{

    namespace sys
    {

        namespace go = gameobjects;

        class MenuActionMessage : public Message
        {
        private:
            MenuActionMessage(const MenuActionMessage & right) = delete;
            MenuActionMessage(const MenuActionMessage && right) = delete;

            std::shared_ptr<go::IMenuAction> menuAction_;
        public:
            static const uint64_t MENU_ACTION_MESSAGE = 0x80000000;

            MenuActionMessage() : Message(MENU_ACTION_MESSAGE), menuAction_(nullptr) { }
            MenuActionMessage(const std::shared_ptr<go::IMenuAction> menuAction) : Message(MENU_ACTION_MESSAGE), menuAction_(menuAction) { }

            void SetMenuAction(std::shared_ptr<go::IMenuAction> menuAction) { menuAction_ = menuAction; }
            const std::shared_ptr<go::IMenuAction> GetMenuAction() const { return menuAction_; }
        };

    }

}