#pragma once

#include "CharacterStatistics.h"
#include "ColorizedDrawable.h"
#include "GameObject.h"
#include <memory>

namespace l2r = l2::rendering;

namespace l2
{

	namespace sys
	{
		class CharacterLoader;
	}

	namespace gameobjects
	{

		class Character : public IGameObject
		{
			friend sys::CharacterLoader;
		protected:
			std::shared_ptr<CharacterStatistics> stats_;
            l2r::ColorizedDrawable model_;
		public:
            Character(const std::string & name) : IGameObject(name), model_(nullptr)
            {
				
            }

            virtual void Attack(Character * target) = 0;
            virtual void TakeDamage(double damage) = 0;

			std::shared_ptr<CharacterStatistics> getCharacterStatistics()
			{
				return stats_;
			}
		};

	}

}