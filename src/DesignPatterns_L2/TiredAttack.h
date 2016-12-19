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
		class TiredAttack : public EnemyAttackPattern
		{
		public:
			void AttackPlayer(Character * player, Enemy * attacker) override
			{
				std::random_device rd;
				std::mt19937 eng(rd());
				std::uniform_int_distribution<> distr(0, 100);
				double chance = distr(eng);
				if (attacker->getEnemyAcc()*0.3 > chance)
				{
					double damage = attacker->getEnemyDamage() * 0.7;
					player->TakeDamage(-damage);
					LOG_INFO("Enemy attacks with tired state, dealt " + std::to_string(damage));
				} else
				{
					LOG_INFO("Tired attack missed");
				}

			}
		};
	}
}
#pragma warning (pop)

