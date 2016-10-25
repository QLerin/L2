#pragma once

#include "EquippableItem.h"

namespace l2
{

    namespace gameobjects
    {

        class Armor : public EquippableItem
        {
        private:
            Armor() = delete;
            Armor(const Armor & right) = delete;
        protected:
            Armor(const std::string & name, const TertiaryStatistics & stats) : EquippableItem(name, stats) {}
        };

    }

}