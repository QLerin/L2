#include "Menu.h"
#include "ConsoleWindow.h"
#include "MenuLoader.h"

using namespace std;
using namespace l2::sys;
using namespace l2::rendering;
using namespace l2::gameobjects;

Menu::Menu(std::shared_ptr<l2r::ConsoleWindow> parentWindow, const std::string & path) : parentWindow_(parentWindow), menu_(parentWindow), selectedItem_(0)
{
    isInitialized_ = MenuLoader().LoadL2Menu(this, path);
}

void Menu::NextSelection()
{
    if (isInitialized_)
    {
        if (++selectedItem_ >= menuItems_.GetStorageSize())
            selectedItem_ = 0;
    }
}

void Menu::PreviousSelection()
{
    if (isInitialized_)
    {
        if (--selectedItem_ >= menuItems_.GetStorageSize())
            selectedItem_ = menuItems_.GetStorageSize() - 1;
    }
}

void Menu::Draw()
{
    if (!isInitialized_)
        return;
    //parentWindow_->SetColor(menuBoxColor_);
    menu_.Draw();
    for (uint16_t i = 0; i < menuItems_.GetStorageSize(); ++i)
    {
        if (i == selectedItem_)
            parentWindow_->SetColor(selectedItemColor_);
        else
            parentWindow_->SetColor(Colorizer::COLOR_ATTRIBUTES(Colorizer::White, menuBoxColor_.backgroundColor));

        menuItems_[i]->Draw();
    }
}