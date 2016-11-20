#pragma once

#include "Character.h"
#include "EnemyAttackPattern.h"

namespace l2r = l2::rendering;

namespace l2
{

    namespace gameobjects
    {
		class EnemyAttackPattern;
        class Enemy : public Character
        {
        protected:
			EnemyAttackPattern * eat;
            Enemy(const std::string & name) : Character(name) { }
			double damage_ = 1;
			double health_ = 1;
			double maxHealth_ = 1;
			double acc_ = 1;
			char state_ = 'n';
			bool alive_ = true;
        public:
			virtual void Die() {}
			void setEnemyDamage(double dmg){damage_ = dmg;}
			void setEnemyHealth(double health) {health_ = health;}
			void setEnemyMaxHealth(double maxHealth) { maxHealth_ = maxHealth; }
			void setEnemAcc(double acc) { acc_ = acc; }
			void setState(char state) { state_ = state; }
			double getEnemyDamage() { return damage_; }
			double getEnemyHealth() { return health_; }
			double getEnemyMaxHealth() { return maxHealth_; }
			double getEnemyAcc() { return acc_; }
			char getState() { return state_;  }
			bool isEnemyAlive() { return alive_; }
			virtual void checkState() {}

			void changeHP(double diff)
			{
				if(diff > 0)
				{
					if((health_ + diff) < maxHealth_)
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
        };

    }

}