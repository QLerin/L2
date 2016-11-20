#include "EnemySwordsman.h"

#pragma warning (push)
#pragma warning (disable : 4100) // I'm on the highway to hell
void l2::gameobjects::EnemySwordsman::Attack(l2::gameobjects::Character & target)
{
	target.TakeDamage(15);
	LOG_INFO("Enemy swordsman hits");
}
void  l2::gameobjects::EnemySwordsman::TakeDamage(const uint64_t damage)
{
	LOG_INFO("Enemy swordsman got hit");
}
void  l2::gameobjects::EnemySwordsman::Die()
{
	LOG_INFO("Enemy swordsman dies");
}
#pragma warning (pop)
