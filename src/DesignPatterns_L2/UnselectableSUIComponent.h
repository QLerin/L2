#pragma once

#include "SUIComponent.h"

namespace l2
{

	namespace gameobjects
	{

		class UnselectabeSUIComponent : public SUIComponent
		{
		public:
			MenuActionReturn Use() { return NoAction; }
			MenuActionReturn Next() { return NoAction; }
			MenuActionReturn Previous() { return NoAction; }
			MenuActionReturn Exit() { return NoAction; }

			virtual void Draw() { drawable_.Draw(); }

			const bool CanBeSelected() const { return false; }
		};

	}

}