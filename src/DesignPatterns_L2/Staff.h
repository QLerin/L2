#pragma once

#include "Weapon.h"

namespace l2
{

    namespace gameobjects
    {

        class Staff : public Weapon
        {
        public:
            Staff() : Weapon("Staff", TertiaryStatistics(0, 0, 10)) { }
            Staff(const Staff & right) : Weapon(right.objectName_, right.statistics_) { }
        };

    }

}