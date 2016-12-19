#include "FirstAttackState.h"
#include <random>
#include "Logger.h"
#include "RegularAttackState.h"
#include "InjuredAttackState.h"

namespace l2
{

	namespace gameobjects
	{

#pragma warning (push)
#pragma warning (disable : 4244)
		PlayerState * FirstAttackState::clone(){
			return new FirstAttackState(player_);
		}

		void FirstAttackState::PlayerAttack(Enemy * enemy)
		{
			if (player_->isAlive()) {
				std::random_device rd;
				std::mt19937 eng(rd());
				std::uniform_int_distribution<> distr(0, 100);
				double chance = distr(eng);


				if (fabs(player_->getAcc()*1.1 - chance) > 0)
				{
					LOG_INFO("Player attacked in FirstAttack state");
					enemy->changeHP(-20 * 1.2); 
					if (enemy->isEnemyAlive()) {
						player_->setState(new RegularAttackState(player_)); //RegularAttack

					}
					else
					{
						LOG_INFO("Player killed enemy");
					}
				}
			}
		}

		void FirstAttackState::ChangePlayerHealth(double diff)
		{
			if (player_->isAlive()) {
				int healK = 1;
				int health = player_->getCharacterStatistics()->GetLife().GetHealth();
				int mHealth = player_->getCharacterStatistics()->GetLife().GetMaxHealth();


				if (diff > 0)
				{
					LOG_INFO("Player healed in FAS");
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
					LOG_INFO("Player damaged in FAS");
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
