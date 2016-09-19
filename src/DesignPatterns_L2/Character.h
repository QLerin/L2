#pragma once

#include "ControlledGameObject.h"
#include "CharacterStatistics.h"

namespace l2
{

	namespace gameobjects
	{

		class Character : public ControlledGameObject
		{
		protected:
			CharacterStatistics stats_;
		public:

		};

	}

}