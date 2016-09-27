#include "MenuInputHandler.h"

void l2::sys::MenuInputHandler::HandleInput(const InputManager::ConsoleInput inputEvent)
{
    switch (inputEvent)
    {
    case InputManager::KEY_UP:
        OnKeyUp();
        break;
    case InputManager::KEY_DOWN:
        OnKeyDown();
        break;
    case InputManager::KEY_LEFT:
        OnKeyLeft();
        break;
    case InputManager::KEY_RIGHT:
        OnKeyRight();
        break;
    case InputManager::KEY_ENTER:
        OnKeyEnter();
        break;
    case InputManager::KEY_ESC:
        OnKeyEsc();
        break;
    }
}
