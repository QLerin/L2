#pragma once

#include "ProgressBar.h"
#include "Colorizer.h"

namespace l2
{

	namespace gameobjects
	{

		class ColoredProgressBar : public ProgressBar
		{
		public:
			void SetColor(const l2::rendering::Colorizer::Color color);

			virtual const bool UseMenuColorScheme() const { return false; }
		};

	}

}