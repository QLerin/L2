#pragma once

#include "IMenuAction.h";

namespace l2
{

    namespace gameobjects
    {

        class MenuNextAction : public IMenuAction
        {
        public:
            MenuNextAction() : IMenuAction() { }
            MenuNextAction(UIComponent * menu) : IMenuAction(menu) {}

            virtual const UIComponent::MenuActionReturn ExecuteAction()
            {
                if (!assignedMenu_)
                    return UIComponent::NoAction;

                return assignedMenu_->Next();
            }
        };

    }

}