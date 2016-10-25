#pragma once

#include "Weapon.h"

namespace l2
{

    namespace gameobjects
    {

        class Bow : public Weapon
        {
        public:
            Bow() : Weapon("Bow", TertiaryStatistics(0, 10, 0)) { }
        };

    }

}