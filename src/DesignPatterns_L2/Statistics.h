#pragma once

#include <stdint.h>

namespace l2
{

	namespace gameobjects
	{

		/// Class to handle characters statistics
		///
		/// Statistics influence damage and survivability
		class Statistics
		{
		protected:
			// ctor indices for tertiary
			static const uint16_t STR_INDEX = 0;
			static const uint16_t AGI_INDEX = 1;
			static const uint16_t INT_INDEX = 2;

			uint64_t strength_;
			uint64_t agility_;
			uint64_t intellect_;
		public:
			Statistics() : strength_(0), agility_(0), intellect_(0) { }

			Statistics(const Statistics & right) : strength_(right.strength_), agility_(right.agility_),
												   intellect_(right.intellect_)
			{
			}

			Statistics(const int64_t tertiary[3]) : strength_(tertiary[STR_INDEX]),
													agility_(tertiary[AGI_INDEX]),
													intellect_(tertiary[INT_INDEX])
			{
			}

			const uint64_t GetStrength() const { return strength_; }
			void SetStrength(const uint64_t strength) { strength_ = strength; }

			const uint64_t GetAgility() const { return agility_; }
			void SetAgility(const uint64_t agility) { agility_ = agility; }

			const uint64_t GetIntellect() const { return intellect_; }
			void SetIntellect(const uint64_t intellect) { intellect_ = intellect; }
		};

	}

}