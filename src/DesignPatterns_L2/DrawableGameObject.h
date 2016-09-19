#pragma once

#include "GameObject.h"
#include "IDrawable.h"
#include "InputHandler.h"

namespace l2r = l2::rendering;

namespace l2
{

	namespace gameobjects
	{

		class DrawableGameObject : public IGameObject, public l2r::IDrawable
		{
		private:
			DrawableGameObject() = delete;
		public:
			DrawableGameObject(const DrawableGameObject & right);
			DrawableGameObject(const IDrawable & drawable, const IGameObject & gameobject);
		};

	}

}