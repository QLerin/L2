#pragma once
#include "PlayerState.h"

namespace l2
{

	namespace gameobjects
	{
		class FirstAttackState : public PlayerState
		{
		public:
			FirstAttackState(Player * p) : PlayerState(p) {}
			void PlayerAttack(Enemy * enemy) override;
			void ChangePlayerHealth(double diff) override;

		};

	}

}
