#pragma once

#include "UsableFactory.h"
#include "RadiantGem.h"
#include "LargePotion.h"
#include "LightningEnchantment.h"

namespace l2
{

    namespace gameobjects
    {

        class EpicFactory : public UsableFactory
        {
        public:
            virtual Gem * CreateGem() { return new RadiantGem(); }
            virtual Potion * CreatePotion() { return new LargePotion(); }
            virtual Enchantment * CreateEnchantment() { return new LightningEnchantment(); }
        };

    }

}