#include "GameManager.h"

using namespace std;
using namespace l2::rendering;
using namespace l2::sys;

static const uint16_t DEFAULT_FRAME_WIDTH = 150;
static const uint16_t DEFAULT_FRAME_HEIGHT = 75;
static const std::string SCENE_CONTENTS_PATH_DEBUG = "Contents.dat";
static const std::string SCENE_CONTENTS_PATH_RELEASE = "/res/Contents.dat";

GameManager::GameManager() : mainFrame_(DEFAULT_FRAME_WIDTH, DEFAULT_FRAME_HEIGHT)
{
#ifdef _DEBUG
	Initialize(SCENE_CONTENTS_PATH_DEBUG);
#else
	Initialize(SCENE_CONTENTS_PATH_RELEASE);
#endif
}

bool GameManager::Initialize(const string & contentsPath)
{
	contentsPath.c_str();
#pragma message ("TODO: [GameManager.cpp] : load scene data from a text file")
	return false;
}

void GameManager::RunMainLoop()
{
	
}