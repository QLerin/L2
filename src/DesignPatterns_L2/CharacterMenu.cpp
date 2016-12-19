#include "CharacterMenu.h"
#include "ConsoleWindow.h"
#include "ColoredProgressBar.h"

using namespace std;
using namespace l2::rendering;
using namespace l2::gameobjects;

CharacterMenu::CharacterMenu(shared_ptr<ConsoleWindow> parentWindow) : Menu(RESPATH_CHARACTER_MENU)
{
	ColoredProgressBar * prog = new ColoredProgressBar();
	prog->SetColor(Colorizer::Color::Green);
	AddChild(prog);

	SetParentWindow(parentWindow);
}

const string CharacterMenu::RESPATH_CHARACTER_MENU = "CharacterMenu.txt";