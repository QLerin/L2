#pragma once

#include "Gem.h"

namespace l2
{

    namespace gameobjects
    {

        class GlitteringGem : public Gem
        {
        public:
            GlitteringGem() : Gem("Glittering gem", TertiaryStatistics(5, 5, 5)) {}
            GlitteringGem(const GlitteringGem & right) : Gem(right.objectName_, right.statistics_) {}
        };

    }

}