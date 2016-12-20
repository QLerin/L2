#include "GameOverMenu.h"

using namespace std;
using namespace l2::rendering;
using namespace l2::gameobjects;

GameOverMenu::GameOverMenu(shared_ptr<l2r::ConsoleWindow> parentWindow) : Menu(RESPATH_GAMEOVER_MENU)
{

}

const string GameOverMenu::RESPATH_GAMEOVER_MENU = "GameOverMenu.txt";

