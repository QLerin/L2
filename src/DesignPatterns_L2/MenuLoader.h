#pragma once

#include <string>
#include "Colorizer.h"

namespace l2
{
    namespace gameobjects
    {
        class Menu;
    }
}

namespace l2g = l2::gameobjects;

namespace l2
{

    namespace sys
    {

        class MenuLoader
        {
            static const l2::rendering::Colorizer::Color GetColorFromChar(const char id);
        public:
            const bool LoadL2Menu(l2g::Menu * const menu, const std::string & path);
        };

    }

}