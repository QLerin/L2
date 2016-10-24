#pragma once

#include "EnemyFactory.h"
#include "EnemyArcher.h"

namespace l2
{

    namespace gameobjects
    {

        class EnemyArcherFactory : public EnemyFactory
        {
            virtual std::shared_ptr<EnemyNPC> CreateEnemy() { return std::dynamic_pointer_cast<EnemyNPC, EnemyArcher>(std::make_shared<EnemyArcher>(new EnemyArcher)); }
        };

    }

}