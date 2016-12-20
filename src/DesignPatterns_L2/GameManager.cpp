#include "GameManager.h"

#include "ActionsMenu.h"
#include "CharacterMenu.h"
#include "EnemyFactory.h"
#include "Caretaker.h"
#include "GameOverMenu.h"

using namespace std;
using namespace l2::rendering;
using namespace l2::sys;
using namespace l2::gameobjects;

static const uint16_t DEFAULT_FRAME_WIDTH            = 150;
static const uint16_t DEFAULT_FRAME_HEIGHT           = 75;
static const std::string SCENE_CONTENTS_PATH_DEBUG   = "Contents.dat";
static const std::string SCENE_CONTENTS_PATH_RELEASE = "/res/Contents.dat";

static const uint16_t NUM_SINGLEDRAW_MENUS = 2;

GameManager::GameManager() : mainWindow_(nullptr), shouldExit_(false), activeMenu_(nullptr)
{
    SetupTransitionTable();
}

GameManager::~GameManager()
{
    for (auto a : activeMenus_)
        delete a;
}

bool GameManager::Initialize(const string & contentsPath)
{
	contentsPath.c_str();
#pragma message ("TODO: [GameManager.cpp] : load scene data from a text file")
	return true;
}

void GameManager::HandleMessage(const shared_ptr<Message> & message)
{
    if (!message || !ValidateMessage(message))
        return;
    shared_ptr<MenuActionMessage> messageCopy = static_pointer_cast<MenuActionMessage, Message>(message);
    messageCopy->GetMenuAction()->SetMenu(activeMenu_);
    UIComponent::MenuActionReturn rc = messageCopy->GetMenuAction()->ExecuteAction();
    if (rc == UIComponent::RequestFwdTransition || rc == UIComponent::RequestBwdTransition)
    {
        uicmp * nextComponent = transitions_.Retrieve(rc, activeMenu_);
        if (nextComponent == nullptr /*&& activeMenu_ == transitions_.GetFrontElement()*/)
        {
            shouldExit_ = true;
            return;
        }
        activeMenu_ = nextComponent;
    }
    else if (rc == UIComponent::NoAction)
        LOG_WARNING("Returning no action. Be wary: menus might contain structural error!");
    ExecuteDrawProcedure();

}

void GameManager::SetupTransitionTable()
{
    /// INITIALIZE MENUS HERE ----------------+
    StartMenu * sm = new StartMenu(mainWindow_);
    activeMenus_.push_back(sm);
	GameOverMenu * gom = new GameOverMenu(mainWindow_);
	activeMenus_.push_back(gom);
	CharacterMenu * cm = new CharacterMenu(mainWindow_);
	activeMenus_.push_back(cm);
	ActionsMenu * am = new ActionsMenu(mainWindow_);
	activeMenus_.push_back(am);
    ///---------------------------------------+

    /// SETUP THE TRANSITION TABLE -----------+

    ///Start menu
    TransitionTable::TRANSITION smTransitions;
    smTransitions.forward = am;
    smTransitions.backward = nullptr;
    transitions_.Assign(sm, smTransitions);
    ///Actions menu
	TransitionTable::TRANSITION amTransitions;
	amTransitions.backward = gom;
	amTransitions.forward = nullptr;
	transitions_.Assign(am, amTransitions);
	///Character menu
	TransitionTable::TRANSITION cmTransitions;
	cmTransitions.backward = nullptr;
	cmTransitions.forward = nullptr;
	transitions_.Assign(cm, cmTransitions);
    ///Game over menu
	TransitionTable::TRANSITION gomTransitions;
	gomTransitions.backward = nullptr;
	gomTransitions.forward = nullptr;
	transitions_.Assign(gom, gomTransitions);

    ///Stats menu
    
    ///----------------------------------------+

	drawableMenuOffset_ = NUM_SINGLEDRAW_MENUS;

    activeMenu_ = activeMenus_.front();

	LOG_INFO("Starting logger...");
	EnemyFactory fac;

	shared_ptr<Player>player = make_shared<Player>("Player");
	shared_ptr<Enemy> ene = fac.CreateRandomEnemy();
	shared_ptr<Caretaker>caretaker = make_shared<Caretaker>(player);

	am->SetEnemy(ene);
	am->SetPlayer(player);
	am->SetCaretaker(caretaker);

}


void GameManager::SetMainWindow(shared_ptr<ConsoleWindow> pWindow)
{
    mainWindow_ = pWindow;
    for( auto a : activeMenus_ )
        if(a)
            a->SetParentWindow(pWindow);
}

void GameManager::ExecuteDrawProcedure()
{
    mainWindow_->ClearActiveBuffer();

	auto iter = activeMenus_.begin();
	for (auto i = 0; i < drawableMenuOffset_; ++i)
		iter++;
	for (iter; iter != activeMenus_.end(); ++iter)
        if ((*iter))
            (*iter)->Draw();
	if (activeMenu_)
		activeMenu_->Draw();
    mainWindow_->SwapBuffers();
}