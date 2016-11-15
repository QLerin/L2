#pragma once

#include <memory>
#include "UIComponent.h"
#include "Logger.h"

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

            virtual void AddChild(UIComponent * component)
            {
                if (!component)
                {
                    LOG_WARNING("Attempting to add null component to " + componentName_);
                    return;
                }

                if (child_)
                    LOG_WARNING("Replacing children in " + componentName_);

                child_ = std::make_shared<UIComponent>(component);
            }

            /// Removing child from a single component simply nulls the child
            virtual void RemoveChild(UIComponent * component) { child_ = nullptr; }

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