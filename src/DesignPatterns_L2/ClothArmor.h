#pragma once

#include "Armor.h"

namespace l2
{

    namespace gameobjects
    {

        class ClothArmor : public Armor
        {
        public:
            ClothArmor() : Armor("Bow", TertiaryStatistics(0, 10, 0)) {}
        };

    }

}