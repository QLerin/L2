#pragma once

#include "Item.h"
#include "Logger.h"

namespace l2
{

    namespace gameobjects
    {

        class UsableItem : public Item
        {
        private:
            UsableItem() = delete;
        protected:
            UsableItem(const UsableItem & other) = default;
            UsableItem(const std::string & name) : Item(name, true, false) { }
        public:
#pragma warning (push)
#pragma warning (disable : 4100) //Warning disabled for unused parameter in base class function
            virtual void UseItem(CharacterStatistics & stats) { LOG_INFO((this->objectName_ + " was used.").c_str()); }
#pragma warning (pop)
        };

    }

}