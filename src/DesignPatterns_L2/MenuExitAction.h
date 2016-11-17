#pragma once

#include "IMenuAction.h"

namespace l2
{

    namespace gameobjects
    {

        class MenuExitAction : public IMenuAction
        {
        public:
            MenuExitAction() : IMenuAction() { }
            MenuExitAction(UIComponent * menu) : IMenuAction(menu) {}

            virtual const UIComponent::MenuActionReturn ExecuteAction()
            {
                if (assignedMenu_ && assignedMenu_->GetActiveComponent())
                    return assignedMenu_->GetActiveComponent()->Exit();

                return UIComponent::NoAction;
            }
        };

    }

}