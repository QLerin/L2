#pragma once

#include "Armor.h"

namespace l2
{

    namespace gameobjects
    {

        class LeatherArmor : public Armor
        {
        public:
            LeatherArmor() : Armor("Bow", TertiaryStatistics(0, 10, 0)) {}
        };

    }

}