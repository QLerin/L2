#pragma once
#include "EnemyAttackPattern.h"
#include <random>
#include "Logger.h"

#pragma warning (push)
#pragma warning (disable : 4244)
namespace l2
{

	namespace gameobjects
	{

		class EnragedAttack : public EnemyAttackPattern
		{
		public:
			void AttackPlayer(Character * player, Enemy * attacker) override
			{
				std::random_device rd;
				std::mt19937 eng(rd());
				std::uniform_int_distribution<> distr(0, 100);
				double chance = distr(eng);
				if (fabs(attacker->getEnemyAcc()*0.7 - chance))
				{
					double damage = attacker->getEnemyDamage() * 1.2;
					player->TakeDamage(-damage);
					LOG_INFO("Enemy attacks with enraged state, dealt " + std::to_string(damage));
				}
				else
				{
					LOG_INFO("Enraged attack missed");
				}

			}
		};
	}
}
#pragma warning (pop)