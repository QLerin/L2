#pragma once

#include <functional>
#include "SUIComponent.h"

namespace l2
{

    namespace gameobjects
    {
        /// Base for all ui components
        /// 
        /// Acts as a transition table of sorts
        class SUICallbackComponent : public SUIComponent
        {
        protected:
            std::function<MenuActionReturn()> onUseCallback_;
        public:
            void SetComponentCallback(const std::function<MenuActionReturn()> && cbfun) { onUseCallback_ = cbfun; }
            
            virtual MenuActionReturn Use() { if (onUseCallback_) return onUseCallback_(); return NoAction; }
        };

    }

}