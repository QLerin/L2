#pragma once

#include "ColorizedDrawable.h"
#include "Colorizer.h"
#include "MenuItem.h"
#include "ArrayStorage.h"
#include <list>
#include "MenuInputHandler.h"
#include "PUIComponent.h"

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

		class Menu : public PUIComponent
		{
            friend l2::sys::MenuLoader;
		private:
            Menu() = delete;
			Menu(const Menu & right) = delete;
		protected:

            l2r::Colorizer::COLOR_ATTRIBUTES selectionColor_;

            virtual const bool ValidationHook() const { return (window_ != nullptr); }

		public:
			Menu(const std::string & path);


            /// For menu on use
            ///
            /// When used with no parent simply draws the menu box + menu items
            /// When parent != nullptr - set as current active menu and use it for transitions
            virtual MenuActionReturn Use();

            /// Select next item in menu
            virtual MenuActionReturn Next();

            /// Select previous item in menu
            virtual MenuActionReturn Previous();

            /// Exit the menu if a parent exists (current menu is transitioned to parent)
            virtual MenuActionReturn Exit();

            void Draw();
		};

	}

}