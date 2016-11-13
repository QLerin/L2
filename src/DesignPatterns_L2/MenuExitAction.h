#pragma once

#include "IMenuAction.h";

namespace l2
{

    namespace gameobjects
    {

        class MenuExitAction : IMenuAction
        {
        public:
            MenuExitAction(const std::shared_ptr<Menu> menu) : IMenuAction(menu) {}

            virtual const MenuActionReturn ExecuteAction()
            {
                if (assignedMenu_ && assignedMenu_->RequestExitVerification())
                    return RequestBwdTransition;

                return NoAction;
            }
        };

    }

}