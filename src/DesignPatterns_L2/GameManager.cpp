#include "GameManager.h"

using namespace std;
using namespace l2::rendering;
using namespace l2::sys;
using namespace l2::gameobjects;

static const uint16_t DEFAULT_FRAME_WIDTH = 150;
static const uint16_t DEFAULT_FRAME_HEIGHT = 75;
static const std::string SCENE_CONTENTS_PATH_DEBUG = "Contents.dat";
static const std::string SCENE_CONTENTS_PATH_RELEASE = "/res/Contents.dat";

GameManager::GameManager() : mainWindow_(new ConsoleWindow(true)), shouldExit_(false), activeMenu_(nullptr)
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
    if (rc != UIComponent::NoAction)
    {
        uicmp * nextComponent = transitions_.Retrieve(rc, activeMenu_);
        if (nextComponent == nullptr && activeMenu_ == transitions_.GetFrontElement())
        {
            shouldExit_ = true;
            return;
        }
        activeMenu_ = nextComponent;
    }
    ExecuteDrawProcedure();

}

void GameManager::SetupTransitionTable()
{
    /// INITIALIZE MENUS HERE ----------------+
    StartMenu * sm = new StartMenu(mainWindow_);
    activeMenus_.push_back(sm);



    ///---------------------------------------+

    /// SETUP THE TRANSITION TABLE -----------+

    ///Start menu
    TransitionTable::TRANSITION smTransitions;
    smTransitions.forward = nullptr;
    smTransitions.backward = nullptr;

    transitions_.Assign(sm, smTransitions);
    ///Actions menu

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
    for (auto a : activeMenus_)
        if (a)
            a->Draw();
    mainWindow_->SwapBuffers();
}