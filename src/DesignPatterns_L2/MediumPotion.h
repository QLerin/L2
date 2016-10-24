#pragma once

#include "Potion.h"

namespace l2
{

    namespace gameobjects
    {

        class MediumPotion : public Potion
        {
        public:
            static const std::string MEDIUM_POTION_NAME;
            MediumPotion() : Potion(MEDIUM_POTION_NAME, LifeStatistics(200, 40)) {}
        };

        const std::string MediumPotion::MEDIUM_POTION_NAME = "Medium potion";

    }

}