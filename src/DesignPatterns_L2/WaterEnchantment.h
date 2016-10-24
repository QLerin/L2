#pragma once

#include "Enchantment.h"

namespace l2
{

    namespace gameobjects
    {

        class WaterEnchantment : public Enchantment
        {
        public:
            WaterEnchantment() : Enchantment("Water enchantment", TertiaryStatistics(10, 10, 10)) {}
            WaterEnchantment(const WaterEnchantment & right) : Enchantment(right.objectName_, right.statistics_) {}
        };

    }

}