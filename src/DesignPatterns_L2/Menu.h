#pragma once

#include "ColorizedDrawable.h"
#include "Colorizer.h"
#include "MenuItem.h"
#include "ArrayStorage.h"
#include <list>
#include "MenuInputHandler.h"

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
            l2s::MenuInputHandler * inHandler_;

			l2r::ColorizedDrawable menu_;
			l2r::Colorizer::COLOR_ATTRIBUTES menuBoxColor_;
            l2r::Colorizer::COLOR_ATTRIBUTES selectedItemColor_;

            l2s::ArrayStorage<MenuItem> menuItems_;
            uint64_t selectedItem_;

            bool isInitialized_;
		public:
			Menu(std::shared_ptr<l2r::ConsoleWindow> parentWindow, const std::string & path);

            const bool IsInitialized() const { return isInitialized_; }

            /// Denotes wether any action should be taken after command execution
            enum MenuActionReturn
            {
                //Take no action upon command execution
                NoAction = 0,
                //Should transition forward to next menu in the transition list
                RequestFwdTransition,
                //Should transition backward to previous menu in the transition list
                RequestBwdTransition
            };

            MenuActionReturn NextSelection();
            MenuActionReturn PreviousSelection();
            virtual const MenuActionReturn RequestExitVerification() { return NoAction; }
            virtual MenuActionReturn ActivateSelected() { }

            virtual void Draw();
		};

	}

}