#pragma once

#include "ClothArmor.h"
#include "LeatherArmor.h"
#include "PlateArmor.h"

namespace l2
{

    namespace gameobjects
    {

        class ArmorFactory
        {
        public:
            virtual Armor * CreateClothArmor() { return new ClothArmor(); }
            virtual Armor * CreateLeatherArmor() { return new LeatherArmor(); }
            virtual Armor * CreatePlateArmor() { return new PlateArmor(); }
        };

    }

}