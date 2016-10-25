#pragma once

#include "Weapon.h"

namespace l2
{

    namespace gameobjects
    {

        class Sword : public Weapon
        {
        public:
            Sword() : Weapon("Sword", TertiaryStatistics(10, 0, 0)) {}
            Sword(const Sword & right) : Weapon(right.objectName_, right.statistics_) {}
        };

    }

}