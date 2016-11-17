#include "Menu.h"
#include "ConsoleWindow.h"
#include "MenuLoader.h"
#include <assert.h>

using namespace std;
using namespace l2::sys;
using namespace l2::rendering;
using namespace l2::gameobjects;

Menu::Menu(const std::string & path) : PUIComponent()
{
    MenuLoader().LoadL2Menu(this, path);
}

UIComponent::MenuActionReturn Menu::Next()
{
    if (ValidationHook())
        TransitionRight();

    return NoAction;
}

UIComponent::MenuActionReturn Menu::Previous()
{
    if (ValidationHook())
        TransitionLeft();

    return NoAction;
}

UIComponent::MenuActionReturn Menu::Use()
{
#pragma message ("Enum should be filled with error information")

    if (!ValidationHook())
        return NoAction;

    if (!parent_) // If USE is called on a menu with no parent, do nothing, else - transition forward
        return NoAction;

    return RequestFwdTransition;
}

UIComponent::MenuActionReturn Menu::Exit()
{
#pragma message ("Enum should be filled with error information")
    if (!ValidationHook())
        return NoAction;

    if (!parent_) // If USE is called on a menu with no parent, do nothing, else - transition forward
        return NoAction;

    return RequestBwdTransition;
}

void Menu::Draw()
{
    if (!ValidationHook())
        return;
    //parentWindow_->SetColor(menu_.GetDrawableColor());
    drawable_.Draw();
    for (uint16_t i = 0; i < children_.GetStorageSize(); ++i)
    {
        if (!children_[i])
        {
            LOG_WARNING("A CHILD IN MENU " + componentName_ + " is inactive yet still in list!");
            continue;
        }
        if (i == selectedIndex_)
        {
            ColorizedDrawable temp = children_[i]->GetDrawable();
            temp.SetColor(selectionColor_.foregroundColor, selectionColor_.backgroundColor);
            children_[i]->SetDrawable(temp);
            //window_->SetColor(selectionColor_);
        }
        else
        {
            ColorizedDrawable temp = children_[i]->GetDrawable();
            temp.SetColor(drawable_.GetDrawableColor().foregroundColor, drawable_.GetDrawableColor().backgroundColor);
            children_[i]->SetDrawable(temp);
            //window_->SetColor(Colorizer::COLOR_ATTRIBUTES(drawable_.GetDrawableColor()));
        }

        children_[i]->Draw();
    }
}