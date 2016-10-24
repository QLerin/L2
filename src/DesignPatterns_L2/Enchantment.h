#pragma once

#include "UsableItem.h"

namespace l2
{

    namespace gameobjects
    {

        class Enchantment : public UsableItem
        {
        private:
            static const std::string ENCHANTMENT_NAME;
        public:
            Enchantment() : UsableItem(ENCHANTMENT_NAME) {}
            virtual std::shared_ptr<CharacterStatistics> ActivateEffect()
            {

                return nullptr;
            }
        };

        const std::string Enchantment::ENCHANTMENT_NAME = "Enchantment";

    }

}