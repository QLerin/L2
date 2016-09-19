#include "InputManager.h"
#include "GameManager.h"
#include <conio.h>

using namespace std;
using namespace l2::sys;

void InputManager::PollInput()
{
	isRunning_ = true;

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
	isRunning_ = false;
}