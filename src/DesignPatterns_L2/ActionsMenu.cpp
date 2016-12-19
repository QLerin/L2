#include "ActionsMenu.h"

using namespace std;
using namespace l2::gameobjects;
using namespace l2::rendering;

static const uint16_t    BUTTON_COUNT		 = 4;

static const std::string COMPONENT_ATTACK    = "Attack";
static const std::string COMPONENT_SKIP      = "SkipTurn";
static const std::string COMPONENT_REWIND    = "Rewind";
static const std::string COMPONENT_INVENTORY = "Inventory";

static const std::string RESOURCE_ATTACK	    = "AttackButton.txt";
static const std::string RESOURCE_SKIP          = "SkipButton.txt";
static const std::string RESOURCE_REWIND        = "RewindButton.txt";
static const std::string RESOURCE_INVENTORY     = "InventoryButton.txt";

static const uint16_t BUTTON_SPACING			= 1;

#define ATTACK_BUTTON							  0
#define SKIP_BUTTON								  1
#define REWIND_BUTTON							  2
#define INVENTORY_BUTTON						  3

ActionsMenu::ActionsMenu(const std::shared_ptr<l2r::ConsoleWindow>& parentWindow) : Menu(RESPATH_ACTIONS_MENU)
{
	uint16_t tX, tY, tW, tH;
	drawable_.GetDrawableSpace(tX, tY, tW, tH);
	tY += BUTTON_SPACING;

	const string componentNames[BUTTON_COUNT] = { COMPONENT_ATTACK, COMPONENT_SKIP, COMPONENT_REWIND, COMPONENT_INVENTORY };
	const string resourceNames[BUTTON_COUNT] = { RESOURCE_ATTACK, RESOURCE_SKIP, RESOURCE_REWIND, RESOURCE_INVENTORY };
	vector<MenuItem *> buttons;

	for (auto i = 0; i < BUTTON_COUNT; ++i)
	{
		buttons.push_back(new MenuItem(parentWindow, resourceNames[i]));
		buttons[i]->SetComponentName("Attack");
		ColorizedDrawable cpy(buttons[i]->GetDrawable());
		cpy.SetColor(drawable_.GetDrawableColor().foregroundColor, drawable_.GetDrawableColor().backgroundColor);
		buttons[i]->SetDrawable(cpy);
		buttons[i]->SetOffsets(tX + (i > 0 ? tW : 0) + 1, tY);
		AddChild(buttons[i]);
		buttons[i]->GetDrawable().GetDrawableSpace(tX, tY, tW, tH);
	}

	// 0 index = attack button
	buttons[ATTACK_BUTTON]->SetComponentCallback(std::bind<MenuActionReturn>(&ActionsMenu::AttackCallback, this));
	// 1 index = skip button
	buttons[SKIP_BUTTON]->SetComponentCallback(std::bind<MenuActionReturn>(&ActionsMenu::SkipTurnCallback, this));
	// 2 index = rewind button
	buttons[REWIND_BUTTON]->SetComponentCallback(std::bind<MenuActionReturn>(&ActionsMenu::RewindCallback, this));
	// 3 index = inventory button
	buttons[INVENTORY_BUTTON]->SetComponentCallback(std::bind<MenuActionReturn>(&ActionsMenu::OpenInventoryCallback , this));

	SetParentWindow(parentWindow);
}

UIComponent::MenuActionReturn ActionsMenu::OpenInventoryCallback()
{
	return MenuActionReturn();
}

UIComponent::MenuActionReturn ActionsMenu::AttackCallback()
{
	//Player attacks enemy, enemy retaliates
	return MenuActionReturn();
}

UIComponent::MenuActionReturn ActionsMenu::SkipTurnCallback()
{
	//Enemy attacks player
	return MenuActionReturn();
}

UIComponent::MenuActionReturn ActionsMenu::RewindCallback()
{
	//Guy rewinds time
	return MenuActionReturn();
}

const string ActionsMenu::RESPATH_ACTIONS_MENU = "ActionsMenu.txt";