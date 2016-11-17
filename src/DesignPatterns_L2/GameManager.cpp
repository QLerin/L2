#include "GameManager.h"

using namespace std;
using namespace l2::rendering;
using namespace l2::sys;

static const uint16_t DEFAULT_FRAME_WIDTH = 150;
static const uint16_t DEFAULT_FRAME_HEIGHT = 75;
static const std::string SCENE_CONTENTS_PATH_DEBUG = "Contents.dat";
static const std::string SCENE_CONTENTS_PATH_RELEASE = "/res/Contents.dat";

GameManager::GameManager() : mainWindow_(new ConsoleWindow(true)), sm(mainWindow_)
{
//#ifdef _DEBUG
//	Initialize(SCENE_CONTENTS_PATH_DEBUG);
//#else
//	Initialize(SCENE_CONTENTS_PATH_RELEASE);
//#endif
}

bool GameManager::Initialize(const string & contentsPath)
{
	contentsPath.c_str();
#pragma message ("TODO: [GameManager.cpp] : load scene data from a text file")
	return true;
}

void GameManager::HandleMessage(const std::shared_ptr<Message> & message)
{
    if (!message || !ValidateMessage(message))
        return;
    shared_ptr<MenuActionMessage> messageCopy = static_pointer_cast<MenuActionMessage, Message>(message);
    messageCopy->GetMenuAction()->SetMenu(&sm);
    messageCopy->GetMenuAction()->ExecuteAction();

    ExecuteDrawProcedure();
}