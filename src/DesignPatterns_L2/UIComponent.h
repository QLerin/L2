#pragma once

#include "ColorizedDrawable.h"

namespace l2
{

    namespace gameobjects
    {
        /// Base for all ui components
        /// 
        /// Acts as a transition table of sorts
        class UIComponent
        {
        private:
            UIComponent(const UIComponent && right) = delete;

            uint16_t yOffset_;
            uint16_t xOffset_;
        protected:
            /// DO NOT DELETE ---------+
            UIComponent * parent_;//---|
            ///------------------------+

            std::string componentName_;
            rendering::ColorizedDrawable drawable_;
            std::shared_ptr<rendering::ConsoleWindow> window_;

            UIComponent() : parent_(nullptr), componentName_(""), yOffset_(0), xOffset_(0) {}
            virtual const bool ValidationHook() const { return true; }
        public:
            /// Denotes wether any action should be taken after command execution
            enum MenuActionReturn
            {
                // Take no action upon command execution
                NoAction = 0,
                // Should transition forward to next menu in the transition list
                RequestFwdTransition,
                // Should transition backward to previous menu in the transition list
                RequestBwdTransition,
                // Child UI component has items inside it, show that transition still possible inside a nested menu
                MenuSwitch,
                // Child UI component can no longer use nested internals (use self or parent)
                MenuNoSwitch
            };
        public:
            UIComponent(UIComponent * parent, const std::string & name) : parent_(parent), componentName_(name), yOffset_(0), xOffset_(0) { }
            UIComponent(const UIComponent & right) : parent_(right.parent_), componentName_(right.componentName_), yOffset_(0), xOffset_(0) { }


            /// NOTES FOR ADDING MENU TO MENU:
            ///
            /// WHEN ADDING A MENU AS A CHILD KEEP IN MIND THAT:
            /// 1. It should be rendered as a standard list item ("button")
            ///    therefore a button is added first - before adding a menu on top of it
            /// 2. When adding a child menu - the menu might be offset by the width
            ///    of either the parent menu or it's own
            virtual void AddChild(UIComponent * component) = 0;
            virtual void RemoveChild(UIComponent * component) = 0;

            // Get/set the parent component
            const UIComponent * const GetParent() const { return parent_; }
            void SetParent(UIComponent * const parent) { parent_ = parent; }

            // Validate UI component if it has required information for functionality
            // For root object parent can be null
            // For child object children count can be 0
            virtual const bool Validate(const bool checkParent = false) const;

            void SetComponentName(const std::string & name) { componentName_ = name; }
            const std::string & GetComponentName() { return componentName_; }

            // Mehods to set and get the drawable
            void SetDrawable(const rendering::ColorizedDrawable & drawable) { drawable_ = drawable; }
            const rendering::ColorizedDrawable & GetDrawable() { return drawable_; }

            // Methods for parent window
            virtual void SetParentWindow(const std::shared_ptr<rendering::ConsoleWindow> & window);
            std::shared_ptr<rendering::ConsoleWindow> GetParentWindow() { return window_; }

            // Methods to set item offset
            void SetOffsetX(const uint16_t offset);
            const uint16_t GetOffsetX() const { return xOffset_; }
            void SetOffsetY(const uint16_t offset);
            const uint16_t GetOffsetY() { return yOffset_; }
            void SetOffsets(const uint16_t xOffset, const uint16_t yOffset);

            // Get the active component (in the component chain)
            virtual UIComponent * GetActiveComponent() = 0;

            virtual MenuActionReturn Use() = 0;
            virtual MenuActionReturn Next() = 0;
            virtual MenuActionReturn Previous() = 0;
            virtual MenuActionReturn Exit() = 0;

            virtual void Draw() = 0;

			virtual const bool CanBeSelected() const { return true; }
			virtual const bool UseMenuColorScheme() const { return true; }
        };

    }

}