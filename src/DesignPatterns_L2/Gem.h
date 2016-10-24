#pragma once

#include "UsableItem.h"

namespace l2
{

    namespace gameobjects
    {

        class Gem : public UsableItem
        {
        private:
            static const std::string GEM_NAME;
        public:
            Gem() : UsableItem(GEM_NAME) {}
            virtual std::shared_ptr<CharacterStatistics> ActivateEffect()
            {

                return nullptr;
            }
        };

        const std::string Gem::GEM_NAME = "Gem";

    }

}