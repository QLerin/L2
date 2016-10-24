#pragma once

#include "Potion.h"

namespace l2
{

    namespace gameobjects
    {

        class LargePotion : public Potion
        {
        public:
            static const std::string LARGE_POTION_NAME;
            LargePotion() : Potion(LARGE_POTION_NAME, LifeStatistics(200, 40)) {}
        };

        const std::string LargePotion::LARGE_POTION_NAME = "Large potion";

    }

}