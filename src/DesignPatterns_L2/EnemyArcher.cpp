#include "EnemyArcher.h"


#pragma warning (push)
#pragma warning (disable : 4100) // Lino funkcijos (save me from this hell)
void l2::gameobjects::EnemyArcher::Attack(l2::gameobjects::Character * target)
{
	eat->AttackPlayer(target, this);
}
void  l2::gameobjects::EnemyArcher::TakeDamage(const uint64_t damage)
{
	LOG_INFO("Enemy archer got hit");
}
void  l2::gameobjects::EnemyArcher::Die()
{
	LOG_INFO("Enemy archer dies");
}
#pragma warning (pop)