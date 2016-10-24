#pragma once

#include "EnemyNPC.h"

namespace l2r = l2::rendering;

namespace l2
{

    namespace gameobjects
    {

        static const std::string DEFAULT_ARCHER_NAME = "Archer";

        class EnemyArcher : public EnemyNPC
        {
        private:
            
        protected:

        public:
            EnemyArcher() : EnemyNPC(DEFAULT_ARCHER_NAME) { }

            virtual void Attack(Character & target) { }
            virtual void TakeDamage(const uint64_t damage) { }
        };

    }

}