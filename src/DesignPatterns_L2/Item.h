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
            Item() = delete;
            Item(const Item & right) = default;
            Item(const std::string & name) : IGameObject(name), parentCharacter_(nullptr) { }
			std::shared_ptr<Character> parentCharacter_;
		public:

			virtual void ActivateEffect() = 0;
			virtual void DeactivateEffect() = 0;
		};

	}

}