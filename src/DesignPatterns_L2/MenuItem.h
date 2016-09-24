#pragma once

#include "ColorizedDrawable.h"

namespace l2
{
    namespace rendering
    {
        class ConsoleWindow;
    }
}

namespace l2
{

	namespace gameobjects
	{

		class MenuItem
		{
		private:
            ColorizedDrawable item_;
		public:
            MenuItem() = delete;
            MenuItem(const MenuItem & right) = delete;
            MenuItem(std::shared_ptr<l2::rendering::ConsoleWindow> parentWindow) : item_(parentWindow) { }

            void Draw() { item_.Draw(); }
		};

	}

}