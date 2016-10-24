#pragma once

#include "UsableItem.h"

namespace l2
{

    namespace gameobjects
    {

        namespace l2::sys = l2s;

        const uint64_t ON_USE_MESSAGE = 0x0000000000000001;

        class Potion : public UsableItem
        {
        private:
            static const std::string POTION_NAME;
        public:
            Potion() : UsableItem(POTION_NAME) { }
            virtual std::shared_ptr<CharacterStatistics> ActivateEffect()
            {

                return nullptr;
            }
        };

        const std::string Potion::POTION_NAME = "Potion";

    }

}