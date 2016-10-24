#pragma once

#include "TertiaryUsable.h"

namespace l2
{

    namespace gameobjects
    {

        class Enchantment : public TertiaryUsable
        {
        private:
            Enchantment() = delete;
        protected:
            Enchantment(const Enchantment & other) : TertiaryUsable(other.objectName_, other.statistics_) { }
            Enchantment(const std::string & name, const TertiaryStatistics & stats) : TertiaryUsable(name, stats) { }
        };

    }

}