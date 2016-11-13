#pragma once

#include "IMenuAction.h";

namespace l2
{

    namespace gameobjects
    {

        class MenuUseAction : IMenuAction
        {
        public:
            MenuUseAction(const std::shared_ptr<Menu> menu) : IMenuAction(menu) {}

            virtual const Menu::MenuActionReturn ExecuteAction()
            {
                if (!assignedMenu_)
                    return Menu::NoAction;

                Menu::MenuActionReturn rc = assignedMenu_->ActivateSelected();
                assignedMenu_->Draw();
                return rc;
            }
        };

    }

}