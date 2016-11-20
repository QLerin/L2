#include "Player.h"
#include "PlayerState.h"
#include "FirstAttackState.h"

namespace l2
{

	namespace gameobjects
	{
#pragma warning (push)
#pragma warning (disable : 4244)

		Player::Player(const std::string & name): Character(name) {
			state_ = new FirstAttackState(this);
		}

		void Player::Attack(Character * target) {
			state_->PlayerAttack(static_cast <Enemy*>(target));
		}

		void Player::ChangeHealth(const uint64_t diff) {
			state_->ChangePlayerHealth(diff);
		}
	}
#pragma warning (pop)
}
