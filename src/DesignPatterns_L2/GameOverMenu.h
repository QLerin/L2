#pragma once

#include "Menu.h"

namespace l2
{

	namespace gameobjects
	{

		class GameOverMenu : public Menu
		{
		private:
			GameOverMenu() = delete;
			GameOverMenu(const GameOverMenu & right) = delete;

			static const std::string RESPATH_GAMEOVER_MENU;

			MenuActionReturn PlayCallback();
			MenuActionReturn ExitCallback();
		public:
			GameOverMenu(std::shared_ptr<l2r::ConsoleWindow> parentWindow);

		};

	}

}