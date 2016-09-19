#pragma once

#include "Statistics.h"
#include <stdint.h>

namespace l2
{

	namespace gameobjects
	{

		class CharacterStatistics : public Statistics
		{
		protected:
			// ctor indices for life
			static const uint16_t HEALTH_INDEX = 0;
			static const uint16_t ENERGY_INDEX = 1;

			int64_t health_;
			int64_t energy_;

			/// Calculates health and energy from tertiary stats (Statistics class fields)
			virtual void CalculateLifePoints() = 0;

		public:
			CharacterStatistics() : Statistics(), health_(0), energy_(0) { }
			CharacterStatistics(const CharacterStatistics & right) : Statistics((int64_t *)( right.strength_, right.agility_,
																	 right.intellect_ )),
																	 health_(right.health_), energy_(right.energy_)
			{
			}
			CharacterStatistics(const int64_t life[2], const int64_t tertiary[3]) : Statistics(tertiary),
																					health_(life[HEALTH_INDEX]),
																					energy_(life[ENERGY_INDEX])
			{
			}

			const int64_t GetHealth() { return health_; }
			void SetHealth(const int64_t health) { health_ = health; }

			const uint64_t GetEnergy() { return energy_; }
			void SetEnergy(const uint64_t energy) { energy_ = energy; }

			void ApplyStatistics(const Statistics & itemStats);
			void RemoveStatistics(const Statistics & itemStats);
		};

	}

}