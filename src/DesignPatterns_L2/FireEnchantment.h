#pragma once

#include "Enchantment.h"

namespace l2
{

    namespace gameobjects
    {

        class FireEnchantment : public Enchantment
        {
        public:
            FireEnchantment() : Enchantment("Fire enchantment", TertiaryStatistics(25, 25, 25)) { }
            FireEnchantment(const FireEnchantment & right) : Enchantment(right.objectName_, right.statistics_) { }
        };

    }

}