#pragma once
#include "EnemyAttackPattern.h"
#include <iostream>
#include <random>
#include "Logger.h"

#pragma warning (push)
#pragma warning (disable : 4244)
namespace l2
{

	namespace gameobjects
	{
		class NormalAttack : public EnemyAttackPattern
		{
		public:
			void AttackPlayer(Character * player, Enemy * attacker) override
			{
				std::random_device rd; 
				std::mt19937 eng(rd()); 
				std::uniform_int_distribution<> distr(0, 100); 
				double chance = distr(eng);
				if (fabs(attacker->getEnemyAcc()*1.2 - chance ))
				{
					double damage = attacker->getEnemyDamage() * 1;
					player->TakeDamage(-damage);
					LOG_INFO("Enemy attacks with normal state, dealt " + std::to_string(damage));
				}
				else
				{
					LOG_INFO("Normal attack missed");
				}
				
			}
		};
	}
}

#pragma warning (pop)

