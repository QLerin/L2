#pragma once

#include "EnemyFactory.h"
#include "EnemyMage.h"

namespace l2
{

    namespace gameobjects
    {

        class EnemyMageFactory : public EnemyFactory
        {
            virtual std::shared_ptr<EnemyNPC> CreateEnemy();
        };

    }

}