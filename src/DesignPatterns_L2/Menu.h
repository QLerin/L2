#pragma once

#include "ColorizedDrawable.h"
#include "Colorizer.h"
#include "MenuItem.h"
#include "ArrayStorage.h"
#include <list>

namespace l2s = l2::sys;
namespace l2r = l2::rendering;

namespace l2
{
    namespace rendering
    {
        class ConsoleWindow;
    }
    namespace sys
    {
        class MenuLoader;
    }
}

namespace l2
{

	namespace gameobjects
	{

		class Menu
		{
            friend l2::sys::MenuLoader;
		private:
            Menu() = delete;
			Menu(const Menu & right) = delete;
		protected:
            std::shared_ptr<l2r::ConsoleWindow> parentWindow_;

			l2r::ColorizedDrawable menu_;
			l2r::Colorizer::COLOR_ATTRIBUTES menuBoxColor_;
            l2r::Colorizer::COLOR_ATTRIBUTES selectedItemColor_;

            l2s::ArrayStorage<MenuItem> menuItems_;
            uint64_t selectedItem_;

            bool isInitialized_;

			void NextSelection();
			void PreviousSelection();
		public:
			Menu(std::shared_ptr<l2r::ConsoleWindow> parentWindow, const std::string & path);

            const bool IsInitialized() const { return isInitialized_; }

            void Draw();
		};

	}

}