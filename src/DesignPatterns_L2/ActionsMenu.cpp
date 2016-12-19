#include "ActionsMenu.h"
#include "EnemyFactory.h"

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
	if (player_->isAlive()) {
		shared_ptr < Player> cpy = player_;
		shared_ptr < Enemy> cpy2 = enemy_;
		player_->saveStateToMemento(*caretaker_);
		LOG_INFO(".............................");
		LOG_INFO(".............................");
		player_->Attack(cpy2.get());
		LOG_INFO("............................." + std::to_string(player_->getCharacterStatistics()->GetLife().GetHealth()));
		if (enemy_->isEnemyAlive() == false)
		{
			LOG_INFO("<<<<<<<<<<<<<<<<<<<<<<<< ENEMY DIED >>>>>>>>>>>>>>>>>>>>>");
			enemy_ = fac_.CreateRandomEnemy();
			enemy_->SetConsoleWindow(GetParentWindow());
		}
		else {
			enemy_->Attack(cpy.get());
			LOG_INFO("............................." + std::to_string(enemy_->getEnemyHealth()));
		}

		LOG_INFO(".............................");
		LOG_INFO(".............................");
	}
	else
		return RequestBwdTransition;
	
	return UIComponent::NoAction;
}

UIComponent::MenuActionReturn ActionsMenu::SkipTurnCallback()
{
	if (player_->isAlive()) {
		player_->saveStateToMemento(*caretaker_);
		shared_ptr < Player> cpy = player_;
		luck_ += 10; //Increasing chance to rewind time
		LOG_INFO("<<<<<<<<<<<<<<<<<<<<<<<< BEFORE ATTACK >>>>>>>>>>>>>>>>>>>>>");
		LOG_INFO("............................." + std::to_string(player_->getCharacterStatistics()->GetLife().GetHealth()));
		enemy_->Attack(cpy.get());
		LOG_INFO("<<<<<<<<<<<<<<<<<<<<<<<< ENEMY ATTACKS, PLAYERS INCREASES REWIND CHANCE >>>>>>>>>>>>>>>>>>>>>");
		LOG_INFO("............................." + std::to_string(player_->getCharacterStatistics()->GetLife().GetHealth()));
	}
	//Enemy attacks player
	return UIComponent::NoAction;
}

UIComponent::MenuActionReturn ActionsMenu::RewindCallback()
{
	if (player_->isAlive()) {
		shared_ptr < Player> cpy = player_;
		std::random_device rd;
		std::mt19937 eng(rd());
		std::uniform_int_distribution<> distr(0, 100);
		double chance = distr(eng);
		if (luck_ > chance)
		{
			LOG_INFO("<<<<<<<<<<<<<<<<<<<<<<<< BEFORE REWIND >>>>>>>>>>>>>>>>>>>>>");
			LOG_INFO("............................." + std::to_string(player_->getCharacterStatistics()->GetLife().GetHealth()));
			player_->restoreStateFromMemento(*caretaker_);
			LOG_INFO("<<<<<<<<<<<<<<<<<<<<<<<< TIME REWINDED >>>>>>>>>>>>>>>>>>>>>");
			LOG_INFO("............................." + std::to_string(player_->getCharacterStatistics()->GetLife().GetHealth()));
			luck_ -= 20;
			player_->saveStateToMemento(*caretaker_);
		} else
		{
			LOG_INFO("<<<<<<<<<<<<<<<<<<<<<<<< BEFORE ATTACK AFTER FAILED REWIND>>>>>>>>>>>>>>>>>>>>>");
			LOG_INFO("............................." + std::to_string(player_->getCharacterStatistics()->GetLife().GetHealth()));
			enemy_->Attack(cpy.get());
			LOG_INFO("<<<<<<<<<<<<<<<<<<<<<<<< ENEMY ATTACKS >>>>>>>>>>>>>>>>>>>>>");
			LOG_INFO("............................." + std::to_string(player_->getCharacterStatistics()->GetLife().GetHealth()));
			luck_ += 15;
		}
	}
	
	return UIComponent::NoAction;
}

void ActionsMenu::SetEnemy(shared_ptr<Enemy> enemy) 
{
	enemy_ = enemy;
	if (enemy_)
		enemy_->SetConsoleWindow(GetParentWindow()); 
}


void ActionsMenu::SetPlayer(shared_ptr<Player> player) 
{ 
	player_ = player; 
	if (player_)
		player_->SetConsoleWindow(GetParentWindow());
}

void ActionsMenu::SetParentWindow(const shared_ptr<ConsoleWindow> & window)
{
	__super::SetParentWindow(window);
	if (enemy_)
		enemy_->SetConsoleWindow(window);
	if (player_)
		player_->SetConsoleWindow(window);
}

void ActionsMenu::Draw()
{
	__super::Draw();
	if (enemy_)
		enemy_->Draw();
	if (player_)
		player_->Draw();
}

const string ActionsMenu::RESPATH_ACTIONS_MENU = "ActionsMenu.txt";