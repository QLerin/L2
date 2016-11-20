#pragma once

#include "InputManager.h"
#include "MenuActionMessage.h"
#include "GameManager.h"
#include "Register.h"

class Executor
{
private:
    l2::sys::Register<l2::sys::Message> reg_;
    std::shared_ptr<l2::rendering::ConsoleWindow> window_;
public:
    Executor() : window_(new l2::rendering::ConsoleWindow(true))
    {
        
    }

    void Run()
    {
        LOG_INFO("Application starting...");
        std::shared_ptr<l2::sys::GameManager> temp = l2::sys::GameManager::GetInstance();
        temp->SetMainWindow(window_);

        temp->ExecuteDrawProcedure();
        temp->ExecuteDrawProcedure();

        std::shared_ptr<l2::sys::InputManager> inputs = l2::sys::InputManager::GetInstance();
        reg_.RegisterReceiver(l2::sys::MenuActionMessage::MENU_ACTION_MESSAGE, temp.get());
        inputs->StartPolling(reg_);

        while (!temp->ShouldAppExit())
        {
            Sleep(50);
        }

        LOG_INFO("Application exiting...");
        inputs->StopPolling();
    
        reg_.UnregisterReceiver(temp.get());
    }
};