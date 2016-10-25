#pragma once

#include "Bow.h"
#include "Sword.h"
#include "Staff.h"

namespace l2
{

    namespace gameobjects
    {

        class WeaponFactory
        {
        public:
            virtual Weapon * CreateSword() { return new Sword(); }
            virtual Weapon * CreateStaff() { return new Staff(); }
            virtual Weapon * CreateBow() { return new Bow(); }
        };

    }

}