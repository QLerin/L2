#include "ColoredText.h"
#include "MenuLoader.h"

using namespace std;
using namespace l2::sys;
using namespace l2::rendering;
using namespace l2::gameobjects;

const bool l2::gameobjects::ColoredText::LoadFromFile(const std::string & path)
{
	return MenuLoader().LoadL2MenuItem(this, path);
}

void ColoredText::SetColor(const Colorizer::Color color)
{
	drawable_.SetColor(color, Colorizer::Color::Black);
}
