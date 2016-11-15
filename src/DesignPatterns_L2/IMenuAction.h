#pragma once

#include <memory>
#include "UIComponent.h";

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
            std::shared_ptr<UIComponent> assignedMenu_;
        public:
            IMenuAction() : assignedMenu_(nullptr) { }
            IMenuAction(const std::shared_ptr<UIComponent> menu) : assignedMenu_(menu) { }

            virtual const UIComponent::MenuActionReturn ExecuteAction() = 0;

            void SetMenu(const std::shared_ptr<UIComponent> menu) { assignedMenu_ = menu; }

            const bool IsMenuSet() const { return (assignedMenu_ != nullptr); }
        };

    }

}