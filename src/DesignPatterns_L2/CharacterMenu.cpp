#include "CharacterMenu.h"
#include "ConsoleWindow.h"

using namespace std;
using namespace l2::rendering;
using namespace l2::gameobjects;

CharacterMenu::CharacterMenu(shared_ptr<ConsoleWindow> parentWindow) : Menu(RESPATH_CHARACTER_MENU)
{
	SetParentWindow(parentWindow);
}

const string CharacterMenu::RESPATH_CHARACTER_MENU = "CharacterMenu.txt";