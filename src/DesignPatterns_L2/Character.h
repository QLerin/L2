#pragma once

#include "CharacterStatistics.h"
#include "ColorizedDrawable.h"
#include "GameObject.h"
#include <memory>

namespace l2r = l2::rendering;

namespace l2
{

	namespace gameobjects
	{

		class Character : public IGameObject
		{
		protected:
			std::shared_ptr<CharacterStatistics> stats_;
            l2r::ColorizedDrawable model_;
		public:
            Character(const std::string & name) : IGameObject(name), model_(nullptr) { }

            virtual void Attack(Character * target) = 0;
            virtual void TakeDamage(const uint64_t damage) = 0;

			std::shared_ptr<CharacterStatistics> getCharacterStatistics()
			{
				return stats_;
			}
		};

	}

}