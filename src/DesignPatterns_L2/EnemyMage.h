#pragma once

#include "EnemyNPC.h"

namespace l2r = l2::rendering;

namespace l2
{

    namespace gameobjects
    {

        class EnemyMage : public EnemyNPC
        {
        protected:

        public:
            virtual void Attack(Character & target) { }
            virtual void TakeDamage(const uint64_t damage) {}
        };

    }

}