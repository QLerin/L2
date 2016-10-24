#pragma once

#include "LifeUsable.h"
#include <string>

namespace l2
{

    namespace gameobjects
    {

        class Potion : public LifeUsable
        {
        private:
            Potion() = delete;
        protected:
            Potion(const Potion & other) : LifeUsable(other.objectName_, other.statistics_) { }
            Potion(const std::string & name, const LifeStatistics & stats) : LifeUsable(name, stats) { }
        };

    }

}