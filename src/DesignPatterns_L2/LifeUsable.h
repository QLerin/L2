#pragma once

#include "UsableItem.h"
#include "LifeStatistics.h"

namespace l2
{

    namespace gameobjects
    {

        class LifeUsable : public UsableItem
        {
        private:
            LifeUsable() = delete;
        protected:
            const LifeStatistics statistics_;

            LifeUsable(const LifeUsable & other) = default;
            LifeUsable(const std::string & name, const LifeStatistics & stats) : UsableItem(name), statistics_(stats) {}
        public:
            const LifeStatistics & GetUsableStatistics() { return statistics_; }

            virtual void UseItem(CharacterStatistics & stats)
            {
                __super::UseItem(stats);
                stats.ApplyLife(statistics_);
            }
        };

    }

}