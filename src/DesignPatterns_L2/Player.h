#pragma once

#include "Character.h"

namespace l2r = l2::rendering;

namespace l2
{

    namespace gameobjects
    {

        class Player : public Character
        {
        public:
	        explicit Player(const std::string& name)
		        : Character(name)
	        {
	        }

			void Attack(Character & target) {}
			void TakeDamage(const uint64_t damage) {}
			void ChangeHealth(LifeStatistics stats) {}
        };

    }

}