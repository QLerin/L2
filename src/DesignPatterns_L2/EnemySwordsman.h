#pragma once

#include "Enemy.h"
#include "Logger.h"
#include "NormalAttack.h"
#include "EnragedAttack.h"
#include "FuriousAttack.h"
#include "TiredAttack.h"

namespace l2r = l2::rendering;

namespace l2
{

    namespace gameobjects
    {
		static const std::string DEFAULT_SWORDSMAN_NAME = "Swordsman";
        class EnemySwordsman : public Enemy
        {
        public:
			EnemySwordsman() : Enemy(DEFAULT_SWORDSMAN_NAME)
			{
				LOG_INFO("Enemy swordsman created");
				damage_ = 6;
				health_ = 100;
				maxHealth_ = health_;
				acc_ = 90;
				eat = new NormalAttack();
			}
			void checkState() override
			{
				double hL = health_ / maxHealth_ * 100;
				if (hL > 90)
				{
					state_ = 'n';
					eat = new NormalAttack();
				} else
				{
					if(hL > 50)
					{
						state_ = 'e';
						eat = new EnragedAttack();
					}
					else
					{
						if(hL > 25)
						{
							state_ = 'f';
							eat = new FuriousAttack();
						}
						else
						{
							if(hL > 0)
							{
								state_ = 't';
								eat = new TiredAttack();
							}
							else
							{
								state_ = 'd';
								alive_ = false;
							}
						}
					}

				}
			}

			void Attack(Character * target) override;
			void TakeDamage(const uint64_t damage) override;
			void Die();
        };

    }

}