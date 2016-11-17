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
            UIComponent * child_;
        public:
            virtual ~SUIComponent();

            virtual UIComponent * GetActiveComponent();

            virtual void SetParentWindow(const std::shared_ptr<rendering::ConsoleWindow> & window);

            MenuActionReturn Next();
            MenuActionReturn Previous();
            MenuActionReturn Exit();

            const UIComponent * GetChild() { return child_; }
            virtual void AddChild(UIComponent * component);

            /// Removing child from a single component (simply nulls the child)
            virtual void RemoveChild(UIComponent * component);

            // Validate UI component if it has required information for functionality
            // For root object parent can be null
            // For child object children count can be 0
            virtual const bool Validate(const bool checkParent = false) const;
        };

    }

}