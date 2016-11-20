#include "EnemyMage.h"

#pragma warning (push)
#pragma warning (disable : 4100) // NEVER AGAIIIIIIIN
void l2::gameobjects::EnemyMage::Attack(l2::gameobjects::Character * target)
{
	eat->AttackPlayer(target, this);
}
void  l2::gameobjects::EnemyMage::TakeDamage(const uint64_t damage)
{
	LOG_INFO("Enemy mage got hit");
}
void  l2::gameobjects::EnemyMage::Die()
{
	LOG_INFO("Enemy mage dies");
}
#pragma warning (pop)
