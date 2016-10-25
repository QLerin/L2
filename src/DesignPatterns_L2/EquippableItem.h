#pragma once

#include "Item.h"
#include "Logger.h"

namespace l2
{

    namespace gameobjects
    {

        class EquippableItem : public Item
        {
        private:
            EquippableItem() = delete;
        protected:
            const TertiaryStatistics statistics_;

            EquippableItem(const EquippableItem & other) = default;
            EquippableItem(const std::string & name, const TertiaryStatistics & stats) : Item(name, true, false), statistics_(stats){}
        public:
            virtual void EquipItem(CharacterStatistics & stats) { LOG_INFO((objectName_ + " was equipped.").c_str()); stats.ApplyTertiary(statistics_); }
            virtual void UnequipItem(CharacterStatistics & stats) { LOG_INFO((objectName_ + " was unequipped.").c_str()); stats.RemoveTertiary(statistics_); }
        };

    }

}