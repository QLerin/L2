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
    {
		if (children_.GetStorageSize() > 0 && children_[selectedIndex_])
        {
            MenuActionReturn rc = children_[selectedIndex_]->Next();
            if (rc == MenuActionReturn::MenuSwitch)
                return MenuNoSwitch;
        }
        if (TransitionRight())
            return MenuSwitch;
        return MenuNoSwitch;
    }

    return NoAction;
}

UIComponent::MenuActionReturn Menu::Previous()
{
    if (ValidationHook())
    {
        if (children_.GetStorageSize() > 0 && children_[selectedIndex_])
        {
            MenuActionReturn rc = children_[selectedIndex_]->Previous();
            if (rc == MenuActionReturn::MenuSwitch)
                return MenuNoSwitch;
        }
        if (TransitionLeft())
            return MenuSwitch;
        return MenuNoSwitch;
    }

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
    drawable_.Draw();
    for (uint16_t i = 0; i < children_.GetStorageSize(); ++i)
    {
        if (!children_[i])
        {
            LOG_WARNING("A CHILD IN MENU " + componentName_ + " is inactive yet still in list!");
            continue;
        }
		if (i == selectedIndex_ && children_[i]->CanBeSelected())
        {
            ColorizedDrawable temp = children_[i]->GetDrawable();
            temp.SetColor(selectionColor_.foregroundColor, selectionColor_.backgroundColor);
            children_[i]->SetDrawable(temp);
        }
        else
        {
			if (children_[i]->UseMenuColorScheme())
			{
				ColorizedDrawable temp = children_[i]->GetDrawable();
				temp.SetColor(drawable_.GetDrawableColor().foregroundColor, drawable_.GetDrawableColor().backgroundColor);
				children_[i]->SetDrawable(temp);
			}
        }

        children_[i]->Draw();
    }
}