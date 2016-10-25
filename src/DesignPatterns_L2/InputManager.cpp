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
			Sleep(10);
			continue;
		}
		const char ioChar = static_cast<char>(_getch());
        inputSender_.BroadcastMessage(std::shared_ptr<Message>(new Message(string("Key with id - \" " + to_string(ioChar) + " \" was pressed."))));
	}
}

void InputManager::StartPolling(Register<Message> & reg)
{
    reg.RegisterSender(1, &inputSender_);
	inputThread_ = thread(bind(&InputManager::PollInput, this));
}

void InputManager::StopPolling()
{
    LOG_INFO("Stopping poll operations");
	isRunning_ = false;
    inputThread_.join();
    LOG_INFO("Polling operation stopped");
}