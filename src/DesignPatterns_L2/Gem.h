#pragma once

#include "TertiaryUsable.h"

namespace l2
{

    namespace gameobjects
    {

        class Gem : public TertiaryUsable
        {
        private:
            Gem() = delete;
        protected:
            Gem(const Gem & right) : TertiaryUsable(right.objectName_, right.statistics_) { }
            Gem(const std::string name, const TertiaryStatistics & stats) : TertiaryUsable(name, stats) { }
        };

    }

}