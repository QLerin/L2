#include "Medkit.h"
#include "Score.h"
#include "Logger.h"



void l2::gameobjects::Medkit::Use(l2::gameobjects::Player player)
{
	player.ChangeHealth(LifeStatistics(healSize, 0));
	common::Score::getInstance().changePoints(0 - scorePenalty);
	LOG_INFO("Medkit used, healed for " + std::to_string(healSize) );
}

