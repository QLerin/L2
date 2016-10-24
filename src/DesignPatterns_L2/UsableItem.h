#pragma once

#include "Item.h"

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
            UsableItem(const std::string & name) : Item(name, true) { }
        public:
            virtual void UseItem(CharacterStatistics & stats) = 0;
        };

    }

}