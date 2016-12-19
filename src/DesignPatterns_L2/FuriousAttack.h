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
		class FuriousAttack : public EnemyAttackPattern
		{
		public:
			void AttackPlayer(Character * player, Enemy * attacker) override
			{
				std::random_device rd;
				std::mt19937 eng(rd());
				std::uniform_int_distribution<> distr(0, 100);
				double chance = distr(eng);
				if (attacker->getEnemyAcc()*0.5 > chance)
				{
					double damage = attacker->getEnemyDamage() * 1.3;
					player->TakeDamage(-damage);
					LOG_INFO("Enemy attacks with furious state, dealt " + std::to_string(damage));
				}
				else
				{
					LOG_INFO("Furious atack missed");
				}

			}
		};
	}
}



#pragma warning (pop)