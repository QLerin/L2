#include "InputManager.h"
#include "GameManager.h"
#include "Logger.h"
#include <conio.h>
#include "Inputs.h"

#include "MenuNextAction.h"
#include "MenuPreviousAction.h"
#include "MenuUseAction.h"
#include "MenuExitAction.h"

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
        Inputs::KeyCode code;
		unsigned char ioChar = static_cast<unsigned char>(_getch());
        if (ioChar == 0xE0 || ioChar == 0) //Arrow key was pressed
            code = Inputs::GetArrowCode(static_cast<unsigned char>(_getch()));
        else
            code = Inputs::GetKeyCode(ioChar);

        shared_ptr<Message> msg(CreateActionMessage(code));
        if (!msg)
        {
            LOG_WARNING("Invalid keycode read (unable to generate message)");
            continue;
        }
        inputSender_->BroadcastMessage(msg);
	}
}

MenuActionMessage * const InputManager::CreateActionMessage(const Inputs::KeyCode input)
{
    switch (input)
    {
    case Inputs::KeyCode_UpArrow:
    case Inputs::KeyCode_RightArrow:
        return new MenuActionMessage(shared_ptr<go::MenuNextAction>(new go::MenuNextAction()));
    case Inputs::KeyCode_DownArrow:
    case Inputs::KeyCode_LeftArrow:
        return new MenuActionMessage(shared_ptr<go::MenuPreviousAction>(new go::MenuPreviousAction()));
    case Inputs::KeyCode_Enter:
        return new MenuActionMessage(shared_ptr<go::MenuUseAction>(new go::MenuUseAction()));
    case Inputs::KeyCode_Esc:
        return new MenuActionMessage(shared_ptr<go::MenuExitAction>(new go::MenuExitAction()));
    }

    return nullptr;
}

void InputManager::StartPolling(Register<Message> & reg)
{
    reg.RegisterSender(MenuActionMessage::MENU_ACTION_MESSAGE, (inputSender_ = new Sender<Message>()));
	inputThread_ = thread(bind(&InputManager::PollInput, this));
}

void InputManager::StopPolling()
{
    LOG_INFO("Stopping poll operations");
	isRunning_ = false;
    inputThread_.join();
    LOG_INFO("Polling operation stopped");
    delete inputSender_;
    inputSender_ = nullptr;
}