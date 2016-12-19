#pragma once
#include "PlayerState.h"

namespace l2
{

	namespace gameobjects
	{
		class InjuredAttackState : public PlayerState
		{
		public:
			InjuredAttackState(Player * p) : PlayerState(p) {}
			PlayerState * clone() override;
			void PlayerAttack(Enemy * enemy) override;
			void ChangePlayerHealth(double diff) override;

		};

	}

}
