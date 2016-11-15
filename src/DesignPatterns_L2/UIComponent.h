#pragma once

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

        protected:
            std::string componentName_;
            UIComponent * parent_;

            UIComponent() : parent_(nullptr), componentName_("") {}
            virtual const bool ValidationHook() const { return true; }

        public:
            UIComponent(UIComponent * parent, const std::string & name) : parent_(parent), componentName_(name) { }
            UIComponent(const UIComponent & right) : parent_(right.parent_), componentName_(right.componentName_) { }
            
            /// Denotes wether any action should be taken after command execution
            enum MenuActionReturn
            {
                //Take no action upon command execution
                NoAction = 0,
                //Should transition forward to next menu in the transition list
                RequestFwdTransition,
                //Should transition backward to previous menu in the transition list
                RequestBwdTransition
            };

            virtual MenuActionReturn Use() = 0;
            virtual MenuActionReturn Next() = 0;
            virtual MenuActionReturn Previous() = 0;
            virtual MenuActionReturn Exit() = 0;

            /// NOTES FOR ADDING MENU TO MENU:
            ///
            /// WHEN ADDING A MENU AS A CHILD KEEP IN MIND THAT:
            /// 1. It should be rendered as a standard list item ("button")
            ///    therefore a button is added first - before adding a menu on top of it
            /// 2. When adding a child menu - the menu might be offset by the width
            ///    of either the parent menu or it's own
            virtual void AddChild(UIComponent * component) = 0;
            virtual void RemoveChild(UIComponent * component) = 0;

            const UIComponent * const GetParent() const { return parent_; }

            // Validate UI component if it has required information for functionality
            // For root object parent can be null
            // For child object children count can be 0
            virtual const bool Validate(const bool checkParent = false) const
            { return ( ValidationHook() && ((parent_ != nullptr || checkParent))); }

            virtual void Draw() = 0;
        };

    }

}