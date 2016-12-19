#include "Player.h"
#include "PlayerState.h"
#include "FirstAttackState.h"
#include "Logger.h"
#include "Caretaker.h"

namespace l2
{

	namespace gameobjects
	{
#pragma warning (push)
#pragma warning (disable : 4244)

		Player::Player(const std::string & name): Character(name) {
			state_ = new FirstAttackState(this);
			stats_ = std::make_shared<CharacterStatistics>(LifeStatistics(100, 100), TertiaryStatistics(10, 10, 10));
		}

		void Player::Attack(Character * target) {
			state_->PlayerAttack(static_cast <Enemy*>(target));
		}

		void Player::ChangeHealth(double diff) {
			state_->ChangePlayerHealth(diff);
			if(stats_->GetLife().GetHealth() < 0.1)
			{
				alive = false;
			}
		}

		void Player::saveStateToMemento(Caretaker & c)
		{
			c.add(Memento(this));
		}

		void Player::restoreStateFromMemento(Caretaker & c)
		{
			Memento temp = c.getMemento();
			state_ = temp.getState();
			stats_ = temp.getStats();
			acc_ = temp.getAcc();
		}
	}
#pragma warning (pop)
}
