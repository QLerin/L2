#pragma once

#include "IMenuAction.h";

namespace l2
{

    namespace gameobjects
    {

        class MenuPreviousAction : public IMenuAction
        {
        public:
            MenuPreviousAction() : IMenuAction() { }
            MenuPreviousAction(UIComponent * menu) : IMenuAction(menu) {}

            virtual const UIComponent::MenuActionReturn ExecuteAction()
            {
                if (!assignedMenu_)
                    return UIComponent::NoAction;

                return assignedMenu_->Previous();
            }
        };

    }

}