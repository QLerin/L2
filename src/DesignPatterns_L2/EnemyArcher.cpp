#include "EnemyArcher.h"



void l2::gameobjects::EnemyArcher::Attack(l2::gameobjects::Character & target)
{
	target.TakeDamage(10);
	LOG_INFO("Enemy archer attacks");
}
void  l2::gameobjects::EnemyArcher::TakeDamage(const uint64_t damage)
{
	LOG_INFO("Enemy archer got hit");
}
void  l2::gameobjects::EnemyArcher::Die()
{
	LOG_INFO("Enemy archer dies");
}