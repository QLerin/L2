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
#pragma warning (push)
#pragma warning (disable : 4100) // Unused parameters (fleshing out how a character operates)
			void Attack(Character * target) {}
			void TakeDamage(const uint64_t damage) {}
			void ChangeHealth(LifeStatistics stats) {}
        };
#pragma warning (pop)
    }

}