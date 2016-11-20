#pragma once

#include "Character.h"

namespace l2
{

	namespace gameobjects
	{
		class Enemy;

		class EnemyAttackPattern
		{
		public:
			virtual void AttackPlayer(Character * player, Enemy * attacker) = 0;

			EnemyAttackPattern() {}

		};
	}
}

