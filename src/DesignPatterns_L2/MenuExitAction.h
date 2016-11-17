#pragma once

#include "IMenuAction.h";

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
                if (assignedMenu_)
                    return assignedMenu_->Exit();

                return UIComponent::NoAction;
            }
        };

    }

}