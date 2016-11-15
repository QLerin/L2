#pragma once

#include "IMenuAction.h";

namespace l2
{

    namespace gameobjects
    {

        class MenuNextAction : IMenuAction
        {
        public:
            MenuNextAction(const std::shared_ptr<Menu> menu) : IMenuAction(menu) {}

            virtual const Menu::MenuActionReturn ExecuteAction()
            {
                if (!assignedMenu_)
                    return Menu::NoAction;

                return assignedMenu_->Next();
            }
        };

    }

}