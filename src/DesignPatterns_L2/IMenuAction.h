#pragma once

#include <memory>
#include "UIComponent.h"

namespace l2
{

    namespace gameobjects
    {

        class IMenuAction
        {
        private:
            IMenuAction(const IMenuAction & right) = delete;
            IMenuAction(const IMenuAction && right) = delete;
        protected:
            UIComponent * assignedMenu_;
        public:
            IMenuAction() : assignedMenu_(nullptr) { }
            IMenuAction(UIComponent * menu) : assignedMenu_(menu) { }

            virtual const UIComponent::MenuActionReturn ExecuteAction() = 0;

            void SetMenu(UIComponent * menu) { assignedMenu_ = menu; }

            const bool IsMenuSet() const { return (assignedMenu_ != nullptr); }
        };

    }

}