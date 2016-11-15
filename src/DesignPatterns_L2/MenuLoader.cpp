#include "MenuLoader.h"
#include "Menu.h"
#include <fstream>

using namespace std;
using namespace l2::sys;
using namespace l2::gameobjects;
using namespace l2::rendering;

const Colorizer::Color MenuLoader::GetColorFromChar(const char id)
{
    switch (id)
    {
    case 'W': //White
        return Colorizer::White;
    case 'O': //Black (O for Onyx)
        return Colorizer::Black;
    case 'R': //Red
        return Colorizer::Red;
    case 'G': //Green
        return Colorizer::Green;
    case 'B': //Blue
        return Colorizer::Blue;
    case 'Y': //Yellow
        return Colorizer::Yellow;
    case 'P': //Purple
        return Colorizer::Purple;
    case 'M': //Brown (M for Maroon)
        return Colorizer::Brown;
    }
    return Colorizer::White;
}

const bool MenuLoader::LoadL2Menu(l2g::Menu * const menu, const std::string & path)
{
    ifstream in(path.c_str());
    if (!in.is_open())
        return false;


    uint16_t x(0), y(0), w(0), h(0);
    char corner(' '), ulBorder(' '), lrBorder(' ');
    std::string outBuffer;

    std::string header("");
    while (in.good())
    {
        in >> header;


        if (header == "CN")
        {
            char foreground, background;
            in >> foreground >> background;
            menu->menu_.SetColor(GetColorFromChar(foreground), GetColorFromChar(background));
        }
        else if (header == "CSEL")
        {
            char foreground, background;
            in >> foreground >> background;

#define dual_retrieve(fg, bg) MenuLoader::GetColorFromChar(fg), MenuLoader::GetColorFromChar(bg)
            //menu->selectedItemColor_ = Colorizer::COLOR_ATTRIBUTES(GetColorFromChar(foreground), GetColorFromChar(background));
            menu->menu_.SetColor(dual_retrieve(foreground, background));
        }
        else if (header == "CORNER")
            in >> corner; //corner ASCII
        else if (header == "UL_BORDER")
            in >> ulBorder; // upper and lower border ASCII
        else if (header == "LR_BORDER")
            in >> lrBorder; // left and right border ASCII
        else if (header == "MX")
            // Menu position x
            in >> x;
        else if (header == "MY")
            // Menu position y
            in >> y;
        else if (header == "MW")
            // The width will also count as the button maximum width
            in >> w;
        else if (header == "MH")
            // Height of the menu
            in >> h;
        else
        {
            // Adding additional menu items
        }

    }

    //Setting the border char in corners
    outBuffer.resize(w * h, ' ');
    outBuffer[0] = corner; outBuffer[w - 1] = corner;
    outBuffer[(h-1) * w] = corner; outBuffer[h*w - 1] = corner;

    //Setting the upper and lower border
    for (uint16_t i = 1; i < w-1; ++i)
    {
        outBuffer[i] = ulBorder;
        outBuffer[(h - 1) * w + i] = ulBorder;
    }

    //Setting the left and right border
    for (uint16_t i = 1; i < h - 1; ++i)
    {
        outBuffer[w * i] = lrBorder;
        outBuffer[w * i + w - 1] = lrBorder;
    }

    menu->menu_.SetDrawableData(outBuffer);
    menu->menu_.SetDrawableSpace(x, y, w, h);

    return true;
}

const bool MenuLoader::LoadL2MenuItem(l2g::MenuItem * const menu, std::ifstream & istream)
{
    if (!istream.is_open())
        return false;


}