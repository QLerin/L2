#pragma once

#include "TertiaryStatistics.h"
#include <stdint.h>

namespace l2
{

    namespace gameobjects
    {
#pragma warning (push)
#pragma warning (disable : 4244)
        class LifeStatistics 
        {
        private:
            static const int64_t HEALTH_MULTIPLIER = 20;
            static const int64_t ENERGY_MULTIPLIER = 10;
        protected:
            int64_t health_;
            int64_t energy_;

            int64_t maxHealth_;
            int64_t maxEnergy_;
        public:
            LifeStatistics() : health_(0), energy_(0) {}
            LifeStatistics(const int64_t maxHealth, const int64_t maxEnergy) :
                           maxHealth_(maxHealth)  , maxEnergy_(maxEnergy)
            {
                SetHealthToMax();
                SetEnergyToMax();
            }

            const int64_t GetHealth() const { return health_; }
            void SetHealth(const int64_t health) { health_ = health; } 

			void ChangeHealth(int64_t diff) { health_ += diff;  }
			int GetMaxHealth() { return maxHealth_; }

            const uint64_t GetEnergy() const { return energy_; }
            void SetEnergy(const uint64_t energy) { energy_ = energy; }

            void SetHealthToMax() { health_ = maxHealth_; }
            void SetEnergyToMax() { energy_ = maxEnergy_; }

            virtual void CalculateAndSetMaxima(const TertiaryStatistics & other)
            {
                maxHealth_ = other.GetStrength() * HEALTH_MULTIPLIER;
                maxEnergy_ = (other.GetAgility() + other.GetIntellect() / 2) * ENERGY_MULTIPLIER;
            }

            void operator += (const LifeStatistics & other)
            {
                health_ += other.health_;
                energy_ += other.energy_;
            }

            void operator -= (const LifeStatistics & other)
            {
                health_ -= other.health_;
                energy_ -= other.energy_;
            }
        };

    }
#pragma warning (pop)

}