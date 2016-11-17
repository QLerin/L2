#pragma once

#include "ArrayStorage.h"
#include "UIComponent.h"

namespace l2
{

    namespace gameobjects
    {

        class PUIComponent : public UIComponent
        {
        protected:
            sys::ArrayStorage<UIComponent> children_;

            uint32_t selectedIndex_;

            virtual const bool TransitionRight();
            virtual const bool TransitionLeft();
        public:
            PUIComponent() : UIComponent(), selectedIndex_(0) { }
            virtual ~PUIComponent();

            sys::ArrayStorage<UIComponent> & GetChildren() { return children_; }

            virtual void AddChild(UIComponent * component);

            /// Remove from components by way of search
            virtual void RemoveChild(UIComponent * component);

            // Validate UI component if it has required information for functionality
            // For root object parent can be null
            // For child object children count can be 0
            virtual const bool Validate(const bool checkParent = false) const;

            virtual UIComponent * GetActiveComponent();
            virtual void SetParentWindow(const std::shared_ptr<rendering::ConsoleWindow> & window);
        };

    }

}