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
            static const uint64_t HEALTH_MULTIPLIER = 20;
            static const uint64_t ENERGY_MULTIPLIER = 10;
        protected:
			double health_;
			double energy_;

			double maxHealth_;
			double maxEnergy_;
        public:
            LifeStatistics() : health_(0), energy_(0) {}
            LifeStatistics(const double maxHealth, const double maxEnergy) :
                           maxHealth_(maxHealth)  , maxEnergy_(maxEnergy)
            {
                SetHealthToMax();
                SetEnergyToMax();
            }

            const double GetHealth() const { return health_; }
            void SetHealth(const double health) { health_ = health; }

			void ChangeHealth(double diff) { health_ += diff;  }
			int GetMaxHealth() { return maxHealth_; }

            const double GetEnergy() const { return energy_; }
            void SetEnergy(const double energy) { energy_ = energy; }

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