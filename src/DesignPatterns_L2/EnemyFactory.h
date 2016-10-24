#pragma once

#include "EnemyNPC.h"

namespace l2
{

    namespace gameobjects
    {

        class EnemyFactory
        {
            virtual std::shared_ptr<EnemyNPC> CreateEnemy() = 0;
        };

    }

}