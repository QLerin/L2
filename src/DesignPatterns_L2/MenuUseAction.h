#pragma once

#include "IMenuAction.h";

namespace l2
{

    namespace gameobjects
    {

        class MenuUseAction : IMenuAction
        {
        public:
            MenuUseAction(const std::shared_ptr<UIComponent> menu) : IMenuAction(menu) {}

            virtual const UIComponent::MenuActionReturn ExecuteAction()
            {
                if (!assignedMenu_)
                    return UIComponent::NoAction;

                UIComponent::MenuActionReturn rc = assignedMenu_->ActivateSelected();
                assignedMenu_->Draw();
                return rc;
            }
        };

    }

}