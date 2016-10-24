#pragma once

#include <stdint.h>

namespace l2
{

	namespace gameobjects
	{

		/// Class to handle characters statistics
		///
		/// Statistics influence damage and survivability
		class TertiaryStatistics
		{
		private:
			uint64_t strength_;
			uint64_t agility_;
			uint64_t intellect_;
		public:
            TertiaryStatistics() : strength_(0), agility_(0), intellect_(0) { }

            TertiaryStatistics(const TertiaryStatistics & right) : strength_(right.strength_),
                                                                   agility_(right.agility_),
												                   intellect_(right.intellect_)
			{
			}

            TertiaryStatistics(const uint16_t strength,
                               const uint16_t agility,
                               const uint16_t intellect) 
                               :
                               strength_(strength),
				               agility_(agility),
				               intellect_(intellect)
			{
			}

			const uint64_t GetStrength() const { return strength_; }
			void SetStrength(const uint64_t strength) { strength_ = strength; }

			const uint64_t GetAgility() const { return agility_; }
			void SetAgility(const uint64_t agility) { agility_ = agility; }

			const uint64_t GetIntellect() const { return intellect_; }
			void SetIntellect(const uint64_t intellect) { intellect_ = intellect; }

            void operator += (const TertiaryStatistics & other)
            {
                strength_ += other.strength_;
                agility_ += other.agility_;
                intellect_ += other.intellect_;
            }

            void operator -= (const TertiaryStatistics & other)
            {
                strength_ -= other.strength_;
                agility_ -= other.agility_;
                intellect_ -= other.intellect_;
            }
		};

	}

}