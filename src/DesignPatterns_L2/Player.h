#pragma once

#include "Character.h"
#include "PlayerState.h"
//#include "FirstAttackState.h"

#pragma warning (push)
#pragma warning (disable : 4100 4150) // Unused parameters (fleshing out how a character operates)
namespace l2r = l2::rendering;

namespace l2
{

    namespace gameobjects
    {
		class PlayerState;
		class FirstAttackState;
        class Player : public Character
        {
			double acc_ = 90;
			PlayerState * state_;
        public:
			Player(const std::string & name);
				

			void setAcc(double acc) { acc_ = acc;  }
			void setState(PlayerState * state) { delete state_; state_ = state; }
			double getAcc() { return acc_;  }
			PlayerState* getState() { return state_;  }

			
			//void Attack(Enemy * target); 
			void ChangeHealth(const uint64_t damage);

			void TakeDamage(const uint64_t damage){}
			void Attack(Character * target);
			void ChangeHealth(const LifeStatistics & stats) {}
			
        };

    }

}
#pragma warning (pop)