#include "CharacterStatistics.h"

using namespace l2::gameobjects;

void CharacterStatistics::ApplyStatistics(const Statistics & itemStats)
{
	strength_  += itemStats.GetStrength();
	agility_   += itemStats.GetAgility();
	intellect_ += itemStats.GetIntellect();
}

void CharacterStatistics::RemoveStatistics(const Statistics & itemStats)
{
	strength_  -= itemStats.GetStrength();
	agility_   -= itemStats.GetAgility();
	intellect_ -= itemStats.GetIntellect();
}