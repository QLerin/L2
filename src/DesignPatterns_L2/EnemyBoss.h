#pragma once

#pragma once

#include "Character.h"
#include "EnemyAttackPattern.h"
#include "Logger.h"

namespace l2r = l2::rendering;

namespace l2
{
	#pragma warning (push)
	#pragma warning (disable : 4244)
	namespace gameobjects
	{
		class EnemyAttackPattern;
		class EnemyBoss : public Character
		{
		protected:
			
			double damage_ = 9;
			double health_ = 150;
			double maxHealth_ = 150;
			bool alive_ = true;
		public:
			EnemyBoss(const std::string & name) : Character(name) { }
			void Die()
			{
				alive_ = false;
			}
			void setEnemyDamage(double dmg) { damage_ = dmg; }
			void setEnemyHealth(double health) { health_ = health; }
			void setEnemyMaxHealth(double maxHealth) { maxHealth_ = maxHealth; }

			double getEnemyDamage() { return damage_; }
			double getEnemyHealth() { return health_; }
			double getEnemyMaxHealth() { return maxHealth_; }

			bool isEnemyAlive() { return alive_; }

			void Attack(Character * target) override {
				
				target->TakeDamage((-damage_/3));
				LOG_INFO("Boss attack " + std::to_string(damage_ / 3));
			}

			void Attack2(Character * target){

				target->TakeDamage(-damage_ / 5);
				LOG_INFO("Boss attack " + std::to_string(damage_ / 5));
			}

			void TakeDamage(double damage) override {
				changeHP(damage);
			}

			void changeHP(double diff)
			{
				if (diff > 0)
				{
					if ((health_ + diff) < maxHealth_)
					{
						health_ += diff;
					}
					else
					{
						health_ = maxHealth_;
					}
				}
				if (diff < 0)
				{
					if ((health_ + diff) > 0)
					{
						health_ += diff;
					}
					else
					{
						health_ = 0;
						alive_ = false;
					}
				}
			}

			virtual void getStaticPosition(uint16_t & x, uint16_t & y)
			{
				x = 200;
				y = 30;
			}
		};

	}

}

#pragma warning (pop)

