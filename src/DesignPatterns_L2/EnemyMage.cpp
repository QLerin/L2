#include "EnemyMage.h"

void l2::gameobjects::EnemyMage::Attack(l2::gameobjects::Character & target)
{
	target.TakeDamage(15);
	LOG_INFO("Enemy mage attacks");
}
void  l2::gameobjects::EnemyMage::TakeDamage(const uint64_t damage)
{
	LOG_INFO("Enemy mage got hit");
}
void  l2::gameobjects::EnemyMage::Die()
{
	LOG_INFO("Enemy mage dies");
}
