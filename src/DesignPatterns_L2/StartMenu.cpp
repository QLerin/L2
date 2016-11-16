#include "StartMenu.h"
#include "MenuLoader.h"
#include <fstream>

using namespace std;
using namespace l2::rendering;
using namespace l2::gameobjects;

const std::string StartMenu::RESPATH_START_MENU = "MenuTest.txt";

StartMenu::StartMenu(std::shared_ptr<l2r::ConsoleWindow> parentWindow) : Menu(RESPATH_START_MENU)
{
    MenuItem * playButton = new MenuItem(parentWindow, "PlayButton.txt");
    playButton->SetComponentName("Play");
    playButton->SetComponentCallback(std::bind<MenuActionReturn>(&StartMenu::PlayCallback, this));

    ColorizedDrawable cpy(playButton->GetDrawable());
    cpy.SetColor(drawable_.GetDrawableColor().foregroundColor, drawable_.GetDrawableColor().backgroundColor);
    playButton->SetDrawable(cpy);

    AddChild(playButton);

    SetParentWindow(parentWindow);
    //MenuItem * exitButton = new MenuItem(parentWindow);
    //exitButton->SetComponentName("Exit");
    //exitButton->SetComponentCallback(std::bind<MenuActionReturn>(&StartMenu::ExitCallback, this));
    //AddChild(exitButton);
}

UIComponent::MenuActionReturn StartMenu::PlayCallback()
{
    return RequestFwdTransition;
}

UIComponent::MenuActionReturn StartMenu::ExitCallback()
{

    return RequestBwdTransition;
}