#pragma once
#include "Enemy.h"
#include "Logger.h"

#pragma warning (push)
#pragma warning (disable : 4100)
namespace l2r = l2::rendering;

namespace l2
{
	namespace gameobjects
	{
		class NullEnemy : public Enemy
		{

		public:
			NullEnemy() : Enemy("null")
			{
				LOG_INFO("Null enemy created.");

			}

			void Attack(Character * target) override {}
			void TakeDamage(double damage) override {}
			bool isNull() override{
				return true;
			}
		};

	}

}

#pragma warning (pop)

