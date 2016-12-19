#pragma once
#include "Memento.h"

namespace l2
{

	namespace gameobjects
	{
		class Player;
		class Caretaker
		{
			Memento lastTurn_;
			Memento beforeLastTurn_;
			Memento beforeBeforeLastTurn_;
		
		public:
			Caretaker(std::shared_ptr<Player> p);


			void add(Memento mem) {
				beforeBeforeLastTurn_ = beforeLastTurn_;
				beforeLastTurn_ = lastTurn_;
				lastTurn_ = mem;
			}

			Memento getMemento()
			{
				return beforeBeforeLastTurn_;
			}

		};

	}

}
