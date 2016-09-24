#pragma once

#include "ColorizedDrawable.h"
#include "Colorizer.h"
#include "MenuItem.h"
#include <list>

namespace l2s = l2::sys;
namespace l2r = l2::rendering;

namespace l2
{

	namespace gameobjects
	{

		class ConsoleWindow;

		class Menu
		{
		private:
			Menu(const Menu & right) = delete;
		protected:
			l2r::ColorizedDrawable menu_;
			l2r::Colorizer::COLOR_ATTRIBUTES menuBoxColor_;

			std::list<MenuItem> menuItems_;
			std::list<MenuItem>::iterator currentMenuItem_;

			void NextSelection();
			void PreviousSelection();
		public:
			Menu();
			Menu(std::shared_ptr<ConsoleWindow> parentWindow);
		};

	}

}