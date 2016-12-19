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
	        std::shared_ptr<Enemy> CreateRandomEnemy();
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

		inline std::shared_ptr<Enemy> EnemyFactory::CreateRandomEnemy()
		{
			#pragma warning (push)
			#pragma warning (disable : 4244)
			srand(time(NULL));

			int randNum = (rand() % 3) + 1;
			switch (randNum)
			{
			case 1:
				return std::shared_ptr<Enemy>(new EnemyMage(), std::default_delete<EnemyMage>());
			case 2:
				return  std::shared_ptr<Enemy>(new EnemySwordsman(), std::default_delete<EnemySwordsman>());
			case 3:
				return std::shared_ptr<Enemy>(new EnemyArcher(), std::default_delete<EnemyArcher>());
			default:
				return std::shared_ptr<Enemy>(new NullEnemy(), std::default_delete<NullEnemy>());
			}

			

			#pragma warning (pop)
		}
    }

}
