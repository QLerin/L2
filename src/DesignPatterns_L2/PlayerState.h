#pragma once
#include "Player.h"
#include "Enemy.h"

namespace l2
{

	namespace gameobjects
	{

		class Player;
		class PlayerState
		{
		protected:
			Player * player_;
		public:
			PlayerState(Player * player);
			virtual PlayerState * clone() = 0;

			virtual void PlayerAttack(Enemy * enemy) = 0;
			virtual void ChangePlayerHealth(double diff) = 0;
		};

	}

}
