#pragma once

#include "IDrawable.h"
#include "Colorizer.h"

namespace l2
{

	namespace rendering
	{

		class ColorizedDrawable : public IDrawable
		{
		private:
			ColorizedDrawable() = delete;
		protected:
			/// Color information for the drawable unit
			Colorizer::COLOR_ATTRIBUTES colorInfo_;
		public:
			ColorizedDrawable(const ColorizedDrawable & right);
			ColorizedDrawable(std::shared_ptr<ConsoleWindow> parentWindow);
			void SetColor(const Colorizer::Color foregroundColor, const Colorizer::Color backgroundColor);
			virtual void Draw();
		};

	}

}