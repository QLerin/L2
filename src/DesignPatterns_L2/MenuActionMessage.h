#pragma once

#include "Message.h"
#include "IMenuAction.h"

namespace l2
{

    namespace sys
    {

        class MenuActionMessage : public Message
        {
        private:
            MenuActionMessage(const MenuActionMessage & right) = delete;
            MenuActionMessage(const MenuActionMessage && right) = delete;

            std::shared_ptr<gameobjects::IMenuAction> menuAction_;
        public:
            MenuActionMessage() : menuAction_(nullptr) { }
            MenuActionMessage(const std::shared_ptr<gameobjects::IMenuAction> menuAction) : menuAction_(menuAction) { }

            const std::shared_ptr<gameobjects::IMenuAction> GetMenuAction() const { return menuAction_; }
            void SetMenuAction(std::shared_ptr<gameobjects::IMenuAction> menuAction) { menuAction_ = menuAction; }
        };

    }

}