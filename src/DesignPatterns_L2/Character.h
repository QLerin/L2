#pragma once

#include "CharacterStatistics.h"
#include "ColorizedDrawable.h"
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
            virtual void Attack(Character & target);
            virtual void TakeDamage(const uint64_t damage);
		};

	}

}