#pragma once

#include <string>
#include "Colorizer.h"
#include <fstream>

namespace l2
{
    namespace gameobjects
    {
        class Menu;
        class MenuItem;
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
        private:
            static const l2r::Colorizer::Color GetColorFromChar(const char id);

            const bool LoadL2MenuItem(l2g::MenuItem * const menu, std::ifstream & istream);
        public:
            const bool LoadL2Menu(l2g::Menu * const menu, const std::string & path);
        };

    }

}