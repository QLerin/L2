#pragma once

#include "IMenuAction.h";

namespace l2
{

    namespace gameobjects
    {

        class MenuNextAction : IMenuAction
        {
        public:
            MenuNextAction(const std::shared_ptr<UIComponent> menu) : IMenuAction(menu) {}

            virtual const UIComponent::MenuActionReturn ExecuteAction()
            {
                if (!assignedMenu_)
                    return UIComponent::NoAction;

                return assignedMenu_->Next();
            }
        };

    }

}