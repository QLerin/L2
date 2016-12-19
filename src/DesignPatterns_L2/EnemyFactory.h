#pragma once

#include "Enemy.h"
#include "EnemyMage.h"
#include "EnemyArcher.h"
#include "EnemySwordsman.h"
#include "NullEnemy.h"

namespace l2
{

    namespace gameobjects
    {

        class EnemyFactory
        {
        public:
			Enemy* CreateEnemy(std::string enemyType);
        };

	    inline Enemy* EnemyFactory::CreateEnemy(std::string enemyType)
	    {
			if (enemyType == "mage")
			{
				return new EnemyMage();
			}
			if (enemyType == "swordsman")
			{
				return new EnemySwordsman();
			}
			if (enemyType == "archer")
			{
				return new EnemyArcher();
			}
			return new NullEnemy();
	    }
    }

}
