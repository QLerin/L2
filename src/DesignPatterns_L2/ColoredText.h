#pragma once

#include "ProgressBar.h"
#include "Colorizer.h"

namespace l2
{

	namespace gameobjects
	{

		class ColoredText : public UnselectabeSUIComponent
		{
		public:
			const bool LoadFromFile(const std::string & path);

			void SetColor(const l2::rendering::Colorizer::Color color);

			virtual const bool UseMenuColorScheme() const { return false; }
		};

	}

}