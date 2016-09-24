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
        protected:
            const bool LoadResource(const std::string & path);
        public:
            StartMenu(std::shared_ptr<l2r::ConsoleWindow> parentWindow) : Menu(parentWindow, RESPATH_START_MENU)
            {
            }

        };

    }

}