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
        private:
            Item() = delete;
        protected:
            Item(const Item & right) : IGameObject(right.objectName_), destroyOnUse_(right.destroyOnUse_), isEquippable_(right.isEquippable_) { }
            Item(const std::string & name, const bool destroyOnUse, const bool isEquippable) : IGameObject(name), destroyOnUse_(destroyOnUse), isEquippable_(isEquippable) { }

            const bool destroyOnUse_;
            const bool isEquippable_;
        public:
            const bool IsEquippable() { return isEquippable_; }
            const bool ShouldDestryOnUse() { return destroyOnUse_; }
		};

	}

}