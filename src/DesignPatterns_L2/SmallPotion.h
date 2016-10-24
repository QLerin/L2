#pragma once

#include "Potion.h"

namespace l2
{

    namespace gameobjects
    {

        class SmallPotion : public Potion
        {
        public:
            static const std::string SMALL_POTION_NAME;
            SmallPotion() : Potion(SMALL_POTION_NAME, LifeStatistics(50, 10)) { }
        };

        const std::string SmallPotion::SMALL_POTION_NAME = "Small potion";

    }

}