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

            void TransitionRight();
            void TransitionLeft();
        public:
            sys::ArrayStorage<UIComponent> & GetChildren() { return children_; }

            // Validate UI component if it has required information for functionality
            // For root object parent can be null
            // For child object children count can be 0
            virtual const bool Validate(const bool checkParent = false) const
            {
                return (__super::Validate(checkParent) && (children_.GetStorageSize()>0 || !checkParent));
            }
        };

    }

}