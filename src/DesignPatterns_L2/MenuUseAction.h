#pragma once

#include "IMenuAction.h"

namespace l2
{

    namespace gameobjects
    {

        class MenuUseAction : public IMenuAction
        {
        public:
            MenuUseAction() : IMenuAction() { }
            MenuUseAction(UIComponent * menu) : IMenuAction(menu) {}

            virtual const UIComponent::MenuActionReturn ExecuteAction()
            {
                if (!assignedMenu_ || !assignedMenu_->GetActiveComponent())
                    return UIComponent::NoAction;

                return assignedMenu_->GetActiveComponent()->Use();
            }
        };

    }

}