#pragma once

#include "Enemy.h"
#include "Logger.h"

namespace l2r = l2::rendering;

namespace l2
{

    namespace gameobjects
    {
		static const std::string DEFAULT_MAGE_NAME = "Mage";
        class EnemyMage : public Enemy
        {
			int powerfulCasts;
        public:
			EnemyMage() : Enemy(DEFAULT_MAGE_NAME)
			{
				LOG_INFO("Enemy mage created");
				powerfulCasts = 10;
			}

			void Attack(Character & target) override;
			void TakeDamage(const uint64_t damage) override;
			void Die();

        };

    }

}