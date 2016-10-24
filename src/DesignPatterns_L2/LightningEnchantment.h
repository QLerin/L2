#pragma once

#include "Enchantment.h"

namespace l2
{

    namespace gameobjects
    {

        class LightningEnchantment : public Enchantment
        {
        public:
            LightningEnchantment() : Enchantment("Lightning enchantment", TertiaryStatistics(50, 50, 50)) {}
            LightningEnchantment(const LightningEnchantment & right) : Enchantment(right.objectName_, right.statistics_) {}
        };

    }

}