#pragma once

#include <string>
#include "Colorizer.h"
#include <fstream>

namespace l2
{
    namespace gameobjects
    {
        class Menu;
        class SUIComponent;
    }
}

namespace l2g = l2::gameobjects;
namespace l2r = l2::rendering;

namespace l2
{

    namespace sys
    {

        class MenuLoader
        {
        public:
            const bool LoadL2Menu(l2g::Menu * const menu, const std::string & path);
            const bool LoadL2MenuItem(l2g::SUIComponent * const menu, const std::string & path);
        };

    }

}