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

            virtual const bool TransitionRight()
            {
                if (++selectedIndex_ >= children_.GetStorageSize())
                {
                    selectedIndex_ = children_.GetStorageSize() - 1;
                    return true;
                }
                return false;
            }
            virtual const bool TransitionLeft()
            {
                if (selectedIndex_ == 0)
                    return true;
                --selectedIndex_;
                return false;
            }
        public:
            PUIComponent() : UIComponent(), selectedIndex_(0) { }
            sys::ArrayStorage<UIComponent> & GetChildren() { return children_; }

            virtual void AddChild(UIComponent * component);

            /// Remove from components by way of search
            virtual void RemoveChild(UIComponent * component);

            // Validate UI component if it has required information for functionality
            // For root object parent can be null
            // For child object children count can be 0
            virtual const bool Validate(const bool checkParent = false) const
            {
                return (__super::Validate(checkParent) && (children_.GetStorageSize()>0 || !checkParent));
            }

            virtual UIComponent * GetActiveComponent() { if (children_.GetStorageSize() > 0 && children_[selectedIndex_] != nullptr) return children_[selectedIndex_]; else return this; }
        
            virtual void SetParentWindow(const std::shared_ptr<rendering::ConsoleWindow> & window)
            {
                __super::SetParentWindow(window);
                for (uint16_t i = 0; i < children_.GetStorageSize(); ++i)
                    if (children_[i])
                        children_[i]->SetParentWindow(window);
            }
        };

    }

}