#pragma once

#include "Character.h"
#include "PlayerState.h"


#pragma warning (push)
#pragma warning (disable : 4100 4150) // Unused parameters (fleshing out how a character operates)
namespace l2r = l2::rendering;

namespace l2
{

    namespace gameobjects
    {
	    class Caretaker;
	    class Memento;
	    class PlayerState;
		class FirstAttackState;
        class Player : public Character
        {
			double acc_ = 90;
			PlayerState * state_;
			bool alive = true;
        public:
			Player(const std::string & name);

			void setAcc(double acc) { acc_ = acc;  }
			void setState(PlayerState * state) { delete state_; state_ = state; }
			double getAcc() { return acc_;  }

			PlayerState* getState() { return state_;  }

			bool isAlive()
			{
				return alive;
			}

			void ChangeHealth(double damage);

			void TakeDamage(double damage) override
			{
				ChangeHealth(damage);
			}
			void Attack(Character * target);
			void ChangeHealth(const LifeStatistics & stats) {}

			void saveStateToMemento(Caretaker & c);
			void restoreStateFromMemento(Caretaker & c);

			
        };

    }

}
#pragma warning (pop)