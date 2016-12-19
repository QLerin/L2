#pragma once

#include "Menu.h"
#include "Player.h"
#include "Enemy.h"

namespace l2
{

    namespace gameobjects
    {

        class ActionsMenu : public Menu
        {
        private:
			ActionsMenu() = delete;
			ActionsMenu(const ActionsMenu & right) = delete;

			std::shared_ptr<Enemy> enemy_;
			std::shared_ptr<Player> player_;

			static const std::string RESPATH_ACTIONS_MENU;

			/// Callback for when player wants to open inventory
			MenuActionReturn OpenInventoryCallback();

			/// Callback for when player wants to attack
			MenuActionReturn AttackCallback();

			/// Callback for when player wants to skip turn
			MenuActionReturn SkipTurnCallback();

			/// Callback for when player wants to "rewind time"
			MenuActionReturn RewindCallback();
        public:
			ActionsMenu(const std::shared_ptr<l2r::ConsoleWindow> & parentWindow);

			void SetEnemy(std::shared_ptr<Enemy> enemy) { enemy_ = enemy; }

			void SetPlayer(std::shared_ptr<Player> player) { player_ = player; }
        };

    }

}