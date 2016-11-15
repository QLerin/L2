#pragma once

#include "SUIComponent.h"
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

		class MenuItem : public SUIComponent
		{
		private:
            MenuItem() = delete;
            MenuItem(const MenuItem & right) = delete;
        protected:
            l2::rendering:: ColorizedDrawable item_;
		public:
            MenuItem(std::shared_ptr<l2::rendering::ConsoleWindow> parentWindow) : item_(parentWindow) { }

            void Draw() { item_.Draw(); }
		};

	}

}