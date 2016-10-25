#pragma once

#include "EquippableItem.h"

namespace l2
{

    namespace gameobjects
    {

        class Weapon : public EquippableItem
        {
        private:
            Weapon() = delete;
            Weapon(const Weapon & right) = delete;
        protected:
            Weapon(const std::string & name, const TertiaryStatistics & stats) : EquippableItem(name, stats) { }
        };

    }

}