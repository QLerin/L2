#pragma once

#include "Enemy.h"
#include "Logger.h"
#include "NormalAttack.h"
#include "TiredAttack.h"

namespace l2r = l2::rendering;

namespace l2
{

    namespace gameobjects
    {
		static const std::string DEFAULT_MAGE_NAME = "Mage";
        class EnemyMage : public Enemy
        {
			int powerfulCasts;
        public:
			EnemyMage() : Enemy(DEFAULT_MAGE_NAME)
			{
				LOG_INFO("Enemy mage created");
				powerfulCasts = 10;
				damage_ = 12;
				health_ = 40;
				maxHealth_ = health_;
				acc_ = 70;
				eat = new NormalAttack();
			}
			void checkState() override
			{
				double hL = health_ / maxHealth_ * 100;
				if (hL > 90)
				{
					state_ = 'n';
					eat = new NormalAttack();
				}
				else
				{
					if (hL > 0)
					{
						state_ = 't';
						eat = new TiredAttack();
					}
					else 
						state_ = 'd';
						alive_ = false;
				}
			}
			void Attack(Character * target) override;
		
			void TakeDamage(double damage) override;
			void Die();
			bool isNull() override {
				return false;
			}

        };

    }

}