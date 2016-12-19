#include "Memento.h"
namespace l2
{

	namespace gameobjects
	{
		Memento::Memento(Player * p)
		{
			acc_ = p->getAcc();
			state_ = p->getState();
			stats_ = p->getCharacterStatistics();
		}

	}

}
