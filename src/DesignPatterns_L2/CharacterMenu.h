#pragma once

#include "Menu.h"

namespace l2
{

    namespace gameobjects
    {

		// PUSH HEALTH BAR, ENERGY BAR AND OTHER ICONS HERE
        class CharacterMenu : public Menu
        {
        private:
			CharacterMenu() = delete;
			CharacterMenu(const CharacterMenu & right) = delete;

			static const std::string RESPATH_CHARACTER_MENU;
        public:
			CharacterMenu(std::shared_ptr<l2r::ConsoleWindow> parentWindow);

			void UpdateTick();
        };

    }

}