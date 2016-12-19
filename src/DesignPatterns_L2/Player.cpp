#include "Player.h"
#include "PlayerState.h"
#include "FirstAttackState.h"
#include "Logger.h"
#include "Caretaker.h"
#include "CharacterLoader.h"
#include "Colorizer.h"

namespace l2
{

	namespace gameobjects
	{
#pragma warning (push)
#pragma warning (disable : 4244)

		Player::Player(const std::string & name): Character(name) {
			l2::sys::CharacterLoader().LoadL2CharacterImage(this, RESPATH_PLAYER);
			uint16_t x(0), y(0), w(0), h(0);
			uint16_t statX(0), statY(0);
			getStaticPosition(statX, statY);

			healthbar_.GetDrawable().GetDrawableSpace(x, y, w, h);
			l2r::ColorizedDrawable temp = healthbar_.GetDrawable();
			temp.SetDrawableSpace(statX, statY - h - 1, w, h);
			healthbar_.SetDrawable(temp);
			healthbar_.SetColor(rendering::Colorizer::Color::Green);
			state_ = new FirstAttackState(this);
			stats_ = std::make_shared<CharacterStatistics>(LifeStatistics(100, 100), TertiaryStatistics(10, 10, 10));
		}

		void Player::Attack(Character * target) {
			state_->PlayerAttack(static_cast <Enemy*>(target));
		}

		void Player::ChangeHealth(double diff) {
			state_->ChangePlayerHealth(diff);
			healthbar_.DecrementBar((uint16_t)abs((int)diff));
			if(stats_->GetLife().GetHealth() < 0.1)
			{
				alive = false;
			}
		}

		void Player::saveStateToMemento(Caretaker & c)
		{
			c.add(Memento(acc_, state_, stats_));
		}

		void Player::restoreStateFromMemento(Caretaker & c)
		{
			Memento temp = c.getMemento();
			state_ = temp.getState();
			stats_ = temp.getStats();
			acc_ = temp.getAcc();
			healthbar_.SetProgressAt(stats_->GetLife().GetHealth());
		}

		const std::string Player::RESPATH_PLAYER = "PlayerImage.txt";

	}
#pragma warning (pop)
}
