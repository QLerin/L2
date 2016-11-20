#pragma once
#include "PlayerState.h"

	namespace l2
	{
		namespace gameobjects
		{

			class RegularAttackState: public PlayerState
			{
				int times = 0;
			public:
				RegularAttackState(Player * p) : PlayerState(p) {}
				void PlayerAttack(Enemy * enemy) override;
				void ChangePlayerHealth(double diff) override;

			};

		}

	}
