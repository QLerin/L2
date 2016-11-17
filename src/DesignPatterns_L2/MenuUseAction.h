#pragma once

#include "IMenuAction.h";

namespace l2
{

    namespace gameobjects
    {

        class MenuUseAction : public IMenuAction
        {
        public:
            MenuUseAction() { }
            MenuUseAction(UIComponent * menu) : IMenuAction(menu) {}

            virtual const UIComponent::MenuActionReturn ExecuteAction()
            {
                if (!assignedMenu_)
                    return UIComponent::NoAction;

                return assignedMenu_->Use();
            }
        };

    }

}