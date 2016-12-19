#include "EnemySwordsman.h"

using namespace std;

#pragma warning (push)
#pragma warning (disable : 4100) 
void l2::gameobjects::EnemySwordsman::Attack(l2::gameobjects::Character * target)
{
	if (alive_) {
		eat->AttackPlayer(target, this);
	}
}
void  l2::gameobjects::EnemySwordsman::TakeDamage(double damage)
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
		LOG_INFO("Enemy swordsman got hit");
		if ((health_ + damage) > 0)
		{
			health_ += damage;
		}
		else
		{
			LOG_INFO("Enemy swordsman dies");
			alive_ = false;
		}
	}
	checkState();
}
void  l2::gameobjects::EnemySwordsman::Die()
{
	alive_ = false;
	LOG_INFO("Enemy swordsman dies");
}
#pragma warning (pop)

const string l2::gameobjects::EnemySwordsman::RESPATH_SWORDSMAN = "EnemySwordsman.txt";