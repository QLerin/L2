#pragma once

#include "Enemy.h"
#include "Logger.h"
#include "NormalAttack.h"
#include "EnragedAttack.h"
#include "FuriousAttack.h"
#include "TiredAttack.h"
#include "CharacterLoader.h"

namespace l2r = l2::rendering;

namespace l2
{
	namespace gameobjects
	{
        static const std::string DEFAULT_ARCHER_NAME = "Archer";
        class EnemyArcher : public Enemy
        {
		private:
			int arrowAmount;
			static const std::string RESPATH_ARCHER;
        public:
			EnemyArcher() : Enemy(DEFAULT_ARCHER_NAME)
			{
				sys::CharacterLoader().LoadL2CharacterImage(this, RESPATH_ARCHER);
				LOG_INFO("Enemy mage created");
				arrowAmount = 10;
				damage_ = 8;
				health_ = 70;
				maxHealth_ = health_;
				acc_ = 50;
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
					if (hL > 50)
					{
						state_ = 'e';
						eat = new EnragedAttack();
					}
					else
					{
						if (hL > 25)
						{
							state_ = 'f';
							eat = new FuriousAttack();
						}
						else
						{
							if (hL > 0)
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
			void TakeDamage(double damage) override;
			void Die();
			bool isNull() override {
				return false;
			}
        };

    }

}