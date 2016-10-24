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
            Item(const Item & right) : IGameObject(right.objectName_), destroyOnUse_(right.destroyOnUse_) { }
            Item(const std::string & name, const bool destroyOnUse) : IGameObject(name), destroyOnUse_(destroyOnUse) { }

            const bool destroyOnUse_;
		};

	}

}