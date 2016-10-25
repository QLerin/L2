#pragma once

#include "Gem.h"

namespace l2
{

    namespace gameobjects
    {

        class RadiantGem : public Gem
        {
        public:
            RadiantGem() : Gem("Radiant gem", TertiaryStatistics(10, 10, 10)) {}
            RadiantGem(const RadiantGem & right) : Gem(right.objectName_, right.statistics_) {}
        };

    }

}