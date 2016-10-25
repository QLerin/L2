#pragma once

#include "Armor.h"

namespace l2
{

    namespace gameobjects
    {

        class PlateArmor : public Armor
        {
        public:
            PlateArmor() : Armor("Bow", TertiaryStatistics(0, 10, 0)) {}
        };

    }

}