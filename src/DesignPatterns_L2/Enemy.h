#pragma once

#include "Character.h"

namespace l2r = l2::rendering;

namespace l2
{

    namespace gameobjects
    {

        class Enemy : public Character
        {
        protected:
            Enemy(const std::string & name) : Character(name) { }
        public:
			virtual void Die() {}
        };

    }

}