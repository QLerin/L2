#include "RegularAttackState.h"
#include <random>
#include "Logger.h"
#include "TiredAttackState.h"
#include "InjuredAttackState.h"

namespace l2
{

	namespace gameobjects
	{
#pragma warning (push)
#pragma warning (disable : 4244)
		PlayerState* RegularAttackState::clone()
		{
			return new RegularAttackState(player_);
		}

		void RegularAttackState::PlayerAttack(Enemy * enemy)
		{
			if (player_->isAlive()) {
				std::random_device rd;
				std::mt19937 eng(rd());
				std::uniform_int_distribution<> distr(0, 100);
				double chance = distr(eng);

				if (fabs(player_->getAcc() * 1 - chance) > 0)
				{
					LOG_INFO("Player attacked in RegularAttackState state");
					enemy->changeHP(-20 * 1); //-10 should be changed to damage from playerstats
					if (enemy->isEnemyAlive()) {
						if (times < 3) {
							times++;
						}
						else
						{
							times = 0;
							player_->setState(new TiredAttackState(player_)); //TiredAtack

						}
					}
					else
					{
						LOG_INFO("Player killed enemy");
					}
				}
			}
		}

		void RegularAttackState::ChangePlayerHealth(double diff)
		{
			if (player_->isAlive()) {
				int healK = 1;
				int health = player_->getCharacterStatistics()->GetLife().GetHealth();
				int mHealth = player_->getCharacterStatistics()->GetLife().GetMaxHealth();


				if (diff > 0)
				{
					LOG_INFO("Player healed in RegularAttackState");
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
					LOG_INFO("Player damaged in RegularAttackState");
					if ((health + diff) > 0)
					{
						player_->getCharacterStatistics()->GetLife().ChangeHealth(diff);
					}
					else
					{
						player_->getCharacterStatistics()->GetLife().SetHealth(0);
					}
				}

				if (100 * health / mHealth <= 25)
				{
					player_->setState(new InjuredAttackState(player_)); //InjuredAttack
					LOG_INFO("Player in injured ATM");
				}
			}
		}
	}
#pragma warning (pop)
}
