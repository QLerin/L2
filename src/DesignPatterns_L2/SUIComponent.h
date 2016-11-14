#pragma once

#include <memory>
#include "UIComponent.h"

namespace l2
{

    namespace gameobjects
    {
        /// Base for all ui components
        /// 
        /// Acts as a transition table of sorts
        class SUIComponent : public UIComponent
        {
        protected:
            std::shared_ptr<UIComponent> child_;
        public:
            const std::shared_ptr<UIComponent> & GetChild() { return child_; }

            virtual MenuActionReturn Next() { return UIComponent::NoAction; }
            virtual MenuActionReturn Previous() { return UIComponent::NoAction; }

            // Validate UI component if it has required information for functionality
            // For root object parent can be null
            // For child object children count can be 0
            virtual const bool Validate(const bool checkParent = false) const
            {
                return ( __super::Validate(checkParent) && (child_ != nullptr || !checkParent));
            }
        };

    }

}