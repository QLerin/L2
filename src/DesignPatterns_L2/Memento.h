#pragma once
#include <string>
#include "PlayerState.h"
#include "Player.h"


namespace l2
{

	namespace gameobjects
	{
		class Player;
		class Memento
		{
			double acc_;
			PlayerState * state_;
			std::shared_ptr<CharacterStatistics> stats_;
		public:
			Memento(Player * p);
			Memento() = default;
			//Memento(const Memento &) = default;
			


			double getAcc()
			{
				return acc_;
			}

			PlayerState* getState() { return state_; }

			std::shared_ptr<CharacterStatistics> getStats()
			{
				return stats_;
			}

		};

	}

}
