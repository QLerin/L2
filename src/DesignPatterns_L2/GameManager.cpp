#include "GameManager.h"

#include "ActionsMenu.h"

using namespace std;
using namespace l2::rendering;
using namespace l2::sys;
using namespace l2::gameobjects;

static const uint16_t DEFAULT_FRAME_WIDTH = 150;
static const uint16_t DEFAULT_FRAME_HEIGHT = 75;
static const std::string SCENE_CONTENTS_PATH_DEBUG = "Contents.dat";
static const std::string SCENE_CONTENTS_PATH_RELEASE = "/res/Contents.dat";

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
        if (nextComponent == nullptr && activeMenu_ == transitions_.GetFrontElement())
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
	smTransitions.backward = sm;
	smTransitions.forward = nullptr;
    ///Inventory menu
    
    ///Stats menu
    
    ///----------------------------------------+

    activeMenu_ = activeMenus_.front();
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

    for (auto a : activeMenus_)
        if (a)
            a->Draw();
    mainWindow_->SwapBuffers();
}