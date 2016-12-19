#pragma once

#include "Character.h"

namespace l2g = l2::gameobjects;

namespace l2
{

	namespace sys
	{

		class CharacterLoader
		{
		public:
			const bool LoadL2CharacterImage(l2g::Character * character, const std::string & path);
		};

	}

}