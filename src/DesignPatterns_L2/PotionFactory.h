#pragma once

#include "SmallPotion.h"
#include "MediumPotion.h"
#include "LargePotion.h"

namespace l2
{

    namespace gameobjects
    {

        class PotionFactory
        {
            Potion * CreateSmallPotion() { return new SmallPotion(); }
            Potion * CreateMediumPotion() { return new MediumPotion(); }
            Potion * CreateLargePotion() { return new LargePotion(); }
        };

    }

}