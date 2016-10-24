#pragma once

#include "Gem.h"

namespace l2
{

    namespace gameobjects
    {

        class GlitteringGem : public Gem
        {
        public:
            GlitteringGem() : Gem("Radiant gem", TertiaryStatistics(10, 10, 10)) {}
            GlitteringGem(const GlitteringGem & right) : Gem(right.objectName_, right.statistics_) {}
        };

    }

}