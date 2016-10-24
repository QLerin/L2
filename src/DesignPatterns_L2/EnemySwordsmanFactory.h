#pragma once

#include "EnemyFactory.h"
#include "EnemySwordsman.h"

namespace l2
{

    namespace gameobjects
    {

        class EnemySwordsmanFactory : public EnemyFactory
        {
            virtual std::shared_ptr<EnemyNPC> CreateEnemy();
        };

    }

}