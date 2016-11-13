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
namespace l2r = l2::rendering;

namespace l2
{

    namespace sys
    {

        class MenuLoader
        {
            static const l2r::Colorizer::Color GetColorFromChar(const char id);

        //protected:
        //    std::shared_ptr<ColorizedDrawable> CreateColorizedDrawable(const l2r::Colorizer::Color color);
        public:
            const bool LoadL2Menu(l2g::Menu * const menu, const std::string & path);
        };

    }

}