#include "Memento.h"
namespace l2
{

	namespace gameobjects
	{
		Memento::Memento(double acc, PlayerState* state, std::shared_ptr<CharacterStatistics> stats)
		{
			acc_ = acc;
			state_ = state->clone();
			stats_ = std::make_shared<CharacterStatistics>(*(stats));
		}

		Memento::Memento(std::shared_ptr<Player> p)
		{
			acc_ = p->getAcc();
			state_ = p->getState()->clone();
			stats_ = std::make_shared<CharacterStatistics>(*(p->getCharacterStatistics()));
		}

	}

}
