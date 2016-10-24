#pragma once

#include "UsableFactory.h"
#include "GlitteringGem.h"
#include "SmallPotion.h"
#include "WaterEnchantment.h"

namespace l2
{

    namespace gameobjects
    {

        class CommonFactory : public UsableFactory
        {
        public:
            virtual Gem * CreateGem() = 0;
            virtual Potion * CreatePotion() = 0;
            virtual Enchantment * CreateEnchantment() = 0;
        };

    }

}