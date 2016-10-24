#pragma once

#include "Enemy.h"
#include "Logger.h"

namespace l2r = l2::rendering;

namespace l2
{

    namespace gameobjects
    {
        static const std::string DEFAULT_ARCHER_NAME = "Archer";
        class EnemyArcher : public Enemy
        {
			int arrowAmount;
        public:
			EnemyArcher() : Enemy(DEFAULT_ARCHER_NAME)
			{
				LOG_INFO("Enemy mage created");
				arrowAmount = 10;
			}

			void Attack(Character & target) override;
			void TakeDamage(const uint64_t damage) override;
			void Die();
        };

    }

}