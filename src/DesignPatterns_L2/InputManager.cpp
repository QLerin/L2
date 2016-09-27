#include "InputManager.h"
#include "GameManager.h"
#include "Logger.h"
#include <conio.h>

using namespace std;
using namespace l2::sys;

void InputManager::PollInput()
{

	isRunning_ = true;

    LOG_INFO("Input polling thread has started");

	while (isRunning_)
	{
		if (!_kbhit())
		{
			//Uncomment later, loop is correct
			//_sleep(10);
			continue;
		}
		const unsigned ioChar = static_cast<unsigned char>(_getch());
	}
}

void InputManager::StartPolling()
{
	inputThread_ = thread(bind(&InputManager::PollInput, this));
}

void InputManager::StopPolling()
{
    LOG_INFO("Stopping poll operations");
	isRunning_ = false;
    inputThread_.join();
    LOG_INFO("Polling operation stopped");
}