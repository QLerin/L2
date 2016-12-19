#include "EnemyMage.h"

#pragma warning (push)
#pragma warning (disable : 4100) // NEVER AGAIIIIIIIN
void l2::gameobjects::EnemyMage::Attack(l2::gameobjects::Character * target)
{
	if (alive_) {
		eat->AttackPlayer(target, this);
	}
}
void  l2::gameobjects::EnemyMage::TakeDamage(double damage)
{
	if (damage > 0)
	{

		if (health_ + damage < maxHealth_)
		{
			health_ += damage;
		}
		else
		{
			health_ = maxHealth_;
		}
	}
	if (damage < 0)
	{
		LOG_INFO("Enemy mage got hit");
		if ((health_ + damage) > 0)
		{
			health_ += damage;
		}
		else
		{
			LOG_INFO("Enemy mage dies");
			alive_ = false;
		}
	}
	checkState();
}
void  l2::gameobjects::EnemyMage::Die()
{
	LOG_INFO("Enemy mage dies");
	alive_ = false;
}
#pragma warning (pop)
