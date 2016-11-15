#pragma once

#include "IMenuAction.h";

namespace l2
{

    namespace gameobjects
    {

        class MenuExitAction : IMenuAction
        {
        public:
            MenuExitAction(const std::shared_ptr<UIComponent> menu) : IMenuAction(menu) {}

            virtual const UIComponent::MenuActionReturn ExecuteAction()
            {
                if (assignedMenu_ && assignedMenu_->UIComponent::RequestExitVerification())
                    return UIComponent::RequestBwdTransition;

                return UIComponent::NoAction;
            }
        };

    }

}