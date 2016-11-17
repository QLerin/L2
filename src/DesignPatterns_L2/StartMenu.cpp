#include "StartMenu.h"
#include "MenuLoader.h"
#include <fstream>

using namespace std;
using namespace l2::rendering;
using namespace l2::gameobjects;

const std::string StartMenu::RESPATH_START_MENU = "MenuTest.txt";

StartMenu::StartMenu(std::shared_ptr<l2r::ConsoleWindow> parentWindow) : Menu(RESPATH_START_MENU)
{

    uint16_t tX, tY, tW, tH;
    drawable_.GetDrawableSpace(tX, tY, tW, tH);

    // Play button
    MenuItem * playButton = new MenuItem(parentWindow, "PlayButton.txt");
    playButton->SetComponentName("Play");
    playButton->SetComponentCallback(std::bind<MenuActionReturn>(&StartMenu::PlayCallback, this));

    ColorizedDrawable cpy(playButton->GetDrawable());
    cpy.SetColor(drawable_.GetDrawableColor().foregroundColor, drawable_.GetDrawableColor().backgroundColor);
    playButton->SetDrawable(cpy);

    playButton->SetOffsets(tX + tW / 4, tY + 1);

    AddChild(playButton);

    playButton->GetDrawable().GetDrawableSpace(tX, tY, tW, tH);
    // Exit button

    MenuItem * exitButton = new MenuItem(parentWindow, "ExitButton.txt");
    exitButton->SetComponentName("Exit");
    exitButton->SetComponentCallback(std::bind<MenuActionReturn>(&StartMenu::ExitCallback, this));
    AddChild(exitButton);

    cpy = exitButton->GetDrawable();
    cpy.SetColor(drawable_.GetDrawableColor().foregroundColor, drawable_.GetDrawableColor().backgroundColor);
    exitButton->SetDrawable(cpy);

    exitButton->SetOffsets(tX, tY + tH + 1);

    SetParentWindow(parentWindow);
}

UIComponent::MenuActionReturn StartMenu::PlayCallback()
{
    return RequestBwdTransition;
}

UIComponent::MenuActionReturn StartMenu::ExitCallback()
{
    return RequestBwdTransition;
}