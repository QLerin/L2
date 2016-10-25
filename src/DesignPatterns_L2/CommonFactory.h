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
            virtual Gem * CreateGem() { return new GlitteringGem(); }
            virtual Potion * CreatePotion() { return new SmallPotion(); }
            virtual Enchantment * CreateEnchantment() { return new WaterEnchantment(); }
        };

    }

}