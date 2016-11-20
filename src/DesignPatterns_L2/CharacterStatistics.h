#pragma once

#include "LifeStatistics.h"
#include "TertiaryStatistics.h"
#include <stdint.h>

namespace l2
{

	namespace gameobjects
	{

		class CharacterStatistics
		{
		protected:
            LifeStatistics life_;
            TertiaryStatistics tertiary_;
		public:
            CharacterStatistics() : life_(0, 0), tertiary_(0, 0, 0) { }
			CharacterStatistics(const CharacterStatistics & right) : life_(right.life_), tertiary_(right.tertiary_)
			{
			}
			CharacterStatistics(const LifeStatistics & life, const TertiaryStatistics & tertiary) :
                                      life_(life),                 tertiary_(tertiary)
			{
			}

            void ApplyTertiary(const TertiaryStatistics & itemStats) { tertiary_ += itemStats; life_.CalculateAndSetMaxima(tertiary_); }
            void ApplyLife(const LifeStatistics & itemStats) { life_ += itemStats; }

            void RemoveTertiary(const TertiaryStatistics & itemStats) { tertiary_ -= itemStats; }
            void RemoveLife(const LifeStatistics & itemStats) { life_ -= itemStats; }

            void SpendEnergy(const int64_t energy) { energy; }
            void SpendLife(const int64_t life) { life; }

            LifeStatistics & GetLife() { return life_; }
            const TertiaryStatistics & GetTertiary() const { return tertiary_; }
        };

	}

}