#include "Caretaker.h"
namespace l2
{

	namespace gameobjects
	{
		Caretaker::Caretaker(std::shared_ptr<Player> p)
		{
			lastTurn_ = Memento(p);
			beforeLastTurn_ = Memento(p);
			beforeBeforeLastTurn_ = Memento(p);
		}

	}

}
