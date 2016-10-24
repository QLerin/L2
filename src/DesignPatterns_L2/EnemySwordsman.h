#pragma once

#include "Enemy.h"
#include "Logger.h"

namespace l2r = l2::rendering;

namespace l2
{

    namespace gameobjects
    {
		static const std::string DEFAULT_SWORDSMAN_NAME = "Swordsman";
        class EnemySwordsman : public Enemy
        {
        public:
			EnemySwordsman() : Enemy(DEFAULT_SWORDSMAN_NAME)
			{
				LOG_INFO("Enemy swordsman created");
			}

			void Attack(Character & target) override;
			void TakeDamage(const uint64_t damage) override;
			void Die();
        };

    }

}