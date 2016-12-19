#include "ColoredProgressBar.h"

using namespace std;
using namespace l2::gameobjects;
using namespace l2::rendering;

void ColoredProgressBar::SetColor(const Colorizer::Color color)
{
	drawable_.SetColor(color, Colorizer::Color::Black);
}
