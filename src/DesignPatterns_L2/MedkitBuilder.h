#pragma once
#include "Medkit.h"

namespace l2
{

	namespace common
	{
		class MedkitBuilder
		{
		public:
			MedkitBuilder() = default;
			virtual void setHP() = 0;
			virtual void setSP() = 0;
			virtual gameobjects::Medkit getMedkit() = 0;
			virtual void setModel() = 0;

		};
	}
}

