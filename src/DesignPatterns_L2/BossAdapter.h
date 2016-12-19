#pragma once
#include "Enemy.h"
#include "EnemyBoss.h"

namespace l2
{
	namespace gameobjects
	{
		class BossAdapter : public Enemy
		{
			EnemyBoss *boss;
			int arrowAmount;

		public:
			BossAdapter(EnemyBoss *b) : Enemy("BossAdapter")
			{
				boss = b;
			}

			void setBoss(EnemyBoss *b) {
				boss = b;
			}

			void checkState() override {}


			void Attack(Character * target) override {
				boss->Attack(target);
				boss->Attack2(target);
			}
			void TakeDamage(double damage)
			{
				boss->changeHP(damage);
			}

			void changeHP(double diff) override
			{
				boss->changeHP(diff);
			}
			void Die()
			{
				boss->Die();
			}

			bool isNull() override {
				if (boss != nullptr)
				{
					return false;
				}
				return true;
				
			}

			void setEnemyDamage(double dmg) override { boss->setEnemyDamage(dmg); }
			void setEnemyHealth(double health) override { boss->setEnemyHealth(health); }
			void setEnemyMaxHealth(double maxHealth) override { boss->setEnemyMaxHealth(maxHealth); }

			double getEnemyDamage() override { return boss->getEnemyDamage(); }
			double getEnemyHealth() override { return boss->getEnemyHealth(); }
			double getEnemyMaxHealth() override { return boss->getEnemyMaxHealth(); }

			bool isEnemyAlive() override { return boss->isEnemyAlive(); }

		};

	}
}
