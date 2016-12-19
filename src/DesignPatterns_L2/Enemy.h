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
			virtual void setEnemyDamage(double dmg){damage_ = dmg;}
			virtual void setEnemyHealth(double health) {health_ = health;}
			virtual void setEnemyMaxHealth(double maxHealth) { maxHealth_ = maxHealth; }
			void setEnemAcc(double acc) { acc_ = acc; }
			void setState(char state) { state_ = state; }
			virtual double getEnemyDamage() { return damage_; }
			virtual double getEnemyHealth() { return health_; }
			virtual double getEnemyMaxHealth() { return maxHealth_; }
			double getEnemyAcc() { return acc_; }
			char getState() { return state_;  }
			virtual bool isEnemyAlive() { return alive_; }
			virtual bool isNull() = 0;
			virtual void checkState() {}

			virtual void getStaticPosition(uint16_t & x, uint16_t & y)
			{
				x = 200;
				y = 30;
			}

			virtual void changeHP(double diff)
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
				checkState();
			}
        };

    }

}