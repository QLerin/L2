#pragma once

#include "UsableFactory.h"
#include "ShiningGem.h"
#include "MediumPotion.h"
#include "FireEnchantment.h"

namespace l2
{

    namespace gameobjects
    {

        class UsableFactory
        {
        public:
            virtual Gem * CreateGem() { return new ShiningGem(); }
            virtual Potion * CreatePotion() { return new MediumPotion(); }
            virtual Enchantment * CreateEnchantment() { return new FireEnchantment(); }
        };

    }

}