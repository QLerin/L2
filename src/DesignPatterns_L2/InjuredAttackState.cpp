#include "InjuredAttackState.h"
#include <random>
#include "Logger.h"
#include "RegularAttackState.h"

namespace l2
{

	namespace gameobjects
	{
#pragma warning (push)
#pragma warning (disable : 4244)

		PlayerState* InjuredAttackState::clone()
		{
			return new InjuredAttackState(player_);
		}

		void InjuredAttackState::PlayerAttack(Enemy * enemy)
		{
			if (player_->isAlive()) {
				std::random_device rd;
				std::mt19937 eng(rd());
				std::uniform_int_distribution<> distr(0, 100);
				double chance = distr(eng);


				if (player_->getAcc() * 0.7 > chance)
				{
					LOG_INFO("Player attacked in InjuredAttack state");
					enemy->changeHP(-20 * 0.8); //-10 should be changed to damage from playerstats
					if (enemy->isEnemyAlive()) {

					}
					else
					{
						LOG_INFO("Player killed enemy");
					}
				}
			}
		}

		void InjuredAttackState::ChangePlayerHealth(double diff)
		{
			if (player_->isAlive()) {
				int healK = 0.8;
				int health = player_->getCharacterStatistics()->GetLife().GetHealth();
				int mHealth = player_->getCharacterStatistics()->GetLife().GetMaxHealth();


				if (diff > 0)
				{
					LOG_INFO("Player healed in InjuredAttackState");
					if (health + diff*healK < mHealth)
					{
						player_->getCharacterStatistics()->GetLife().ChangeHealth(diff * healK);
					}
					else
					{
						player_->getCharacterStatistics()->GetLife().SetHealthToMax();
					}
				}
				if (diff < 0)
				{
					LOG_INFO("Player damaged in InjuredAttackState");
					if ((health + diff) > 0)
					{
						player_->getCharacterStatistics()->GetLife().ChangeHealth(diff);
					}
					else
					{
						player_->getCharacterStatistics()->GetLife().SetHealth(0);
					}
				}

				if (100 * health / mHealth >= 25)
				{
					player_->setState(new RegularAttackState(player_)); //Regular
					LOG_INFO("Player in injured RegularAttackState");
				}
			}
		}
	}
#pragma warning (pop)
}
