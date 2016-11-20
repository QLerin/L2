#pragma once

#include "Menu.h"

namespace l2
{

    namespace gameobjects
    {

        class StartMenu : public Menu
        {
        private:
            StartMenu() = delete;
            StartMenu(const StartMenu & right) = delete;

            static const std::string RESPATH_START_MENU;

            MenuActionReturn PlayCallback();
            MenuActionReturn ExitCallback();

        public:
            StartMenu(std::shared_ptr<l2r::ConsoleWindow> parentWindow);

        };

    }

}