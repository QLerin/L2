#pragma once

#include "GameObject.h"
#include "Character.h"
#include <memory>

namespace l2
{

	namespace gameobjects
	{

		class Item : public IGameObject
		{
		protected:
			std::shared_ptr<Character> parentCharacter_;
		public:
			virtual void ActivateEffect() = 0;
			virtual void DeactivateEffect() = 0;
		};

	}

}