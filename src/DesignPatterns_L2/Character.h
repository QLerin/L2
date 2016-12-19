#pragma once

#include "ConsoleWindow.h"
#include "CharacterStatistics.h"
#include "ColorizedDrawable.h"
#include "GameObject.h"
#include "ColoredProgressBar.h"
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

			ColoredProgressBar healthbar_;
		public:
            Character(const std::string & name) : IGameObject(name), healthbar_(), model_(nullptr)
            {

            }

			virtual void getStaticPosition(uint16_t & x, uint16_t & y) = 0;

            virtual void Attack(Character * target) = 0;
            virtual void TakeDamage(double damage) = 0;

			std::shared_ptr<CharacterStatistics> getCharacterStatistics()
			{
				return stats_;
			}

			virtual void Draw()
			{ 
				model_.Draw(); 
				healthbar_.Draw(); 
			}
			void SetConsoleWindow(std::shared_ptr<l2::rendering::ConsoleWindow> window) { model_.SetParentWindow(window); healthbar_.SetParentWindow(window); }
		};

	}

}