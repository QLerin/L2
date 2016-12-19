#include "EnemyArcher.h"


#pragma warning (push)
#pragma warning (disable : 4100) // Lino funkcijos (save me from this hell)
void l2::gameobjects::EnemyArcher::Attack(l2::gameobjects::Character * target)
{
	if (alive_) {
		eat->AttackPlayer(target, this);
	}
}
void  l2::gameobjects::EnemyArcher::TakeDamage(double damage)
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
		LOG_INFO("Enemy archer got hit");
		if ((health_ + damage) > 0)
		{
			health_ += damage;
		}
		else
		{
			LOG_INFO("Enemy archer dies");
			alive_ = false;
		}
	}
	checkState();
	
	
}
void  l2::gameobjects::EnemyArcher::Die()
{
	LOG_INFO("Enemy archer dies");
	alive_ = false;
}
#pragma warning (pop)