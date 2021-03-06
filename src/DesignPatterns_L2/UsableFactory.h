#pragma once

#include "Gem.h"
#include "Potion.h"
#include "Enchantment.h"

namespace l2
{

    namespace gameobjects
    {

        class UsableFactory
        {
        public:
            virtual Gem * CreateGem() = 0;
            virtual Potion * CreatePotion() = 0;
            virtual Enchantment * CreateEnchantment() = 0;
        };

    }

}