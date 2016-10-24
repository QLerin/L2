#pragma once

#include "Gem.h"

namespace l2
{

    namespace gameobjects
    {

        class ShiningGem : public Gem
        {
        public:
            ShiningGem() : Gem("Glittering gem", TertiaryStatistics(15, 15, 15)) {}
            ShiningGem(const ShiningGem & right) : Gem(right.objectName_, right.statistics_) {}
        };

    }

}