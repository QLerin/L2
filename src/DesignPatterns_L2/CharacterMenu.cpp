#include "CharacterMenu.h"
#include "ConsoleWindow.h"
#include "ProgressBar.h"

using namespace std;
using namespace l2::rendering;
using namespace l2::gameobjects;

CharacterMenu::CharacterMenu(shared_ptr<ConsoleWindow> parentWindow) : Menu(RESPATH_CHARACTER_MENU)
{
	AddChild(new ProgressBar());

	SetParentWindow(parentWindow);
}

const string CharacterMenu::RESPATH_CHARACTER_MENU = "CharacterMenu.txt";