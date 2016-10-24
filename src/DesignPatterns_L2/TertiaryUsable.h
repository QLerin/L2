#pragma once

#include "UsableItem.h"
#include "TertiaryStatistics.h"

namespace l2
{

    namespace gameobjects
    {

        class TertiaryUsable : public UsableItem
        {
        private:
            TertiaryUsable() = delete;
        protected:
            const TertiaryStatistics statistics_;

            TertiaryUsable(const TertiaryUsable & other) = default;
            TertiaryUsable(const std::string & name, const TertiaryStatistics & stats) : UsableItem(name), statistics_(stats) {}
        public:
            const TertiaryStatistics & GetUsableStatistics() { return statistics_; }

            virtual void UseItem(CharacterStatistics & stats)
            {
                stats.ApplyTertiary(statistics_);
            }
        };

    }

}