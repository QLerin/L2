#pragma once

#include "SUICallbackComponent.h"
#include "ColorizedDrawable.h"
#include "MenuLoader.h"

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

		class MenuItem : public SUICallbackComponent
		{
		private:
            MenuItem() = delete;
            MenuItem(const MenuItem & right) = delete;
		public:
            MenuItem(std::shared_ptr<l2::rendering::ConsoleWindow> parentWindow, const std::string & path) : SUICallbackComponent() { sys::MenuLoader().LoadL2MenuItem(this, path); SetParentWindow(parentWindow); }

            virtual void Draw() { drawable_.Draw(); }
		};

	}

}