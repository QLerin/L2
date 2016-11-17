#pragma once

#include "ConsoleWindow.h"
#include "Frame.h"
#include "IDrawable.h"
#include "GameObject.h"
#include "Singleton.h"
#include <memory>
#include <list>

#include "StartMenu.h"

namespace l2
{

	namespace sys
	{

		class GameManager : public Singleton<GameManager>, public MenuInputHandler
		{
            friend class Singleton<GameManager>;
			friend class std::shared_ptr<GameManager>;
        private:
            bool shouldExit_;
		protected:
            GameManager();
			GameManager(const GameManager & right) = delete;

            std::shared_ptr<l2::rendering::ConsoleWindow> mainWindow_;

            gameobjects::StartMenu sm;

			/// Initializes game manager from contents file
			///
			/// \param contentsPath		Location of the data file
			///
			/// \retval true			Successfully initialized
			/// \retval false			File doesn't exists, no permission to open \ check log
			///
			/// \note					Defaults for debug and release configurations defined in impl file
			bool Initialize(const std::string & contentsPath);

		public:

            void SetMainWindow(std::shared_ptr<rendering::ConsoleWindow> pWindow) { mainWindow_ = pWindow; sm.SetParentWindow(pWindow); }

            void HandleMessage(const std::shared_ptr<Message> & message);

            const bool ShouldAppExit() { return shouldExit_; }

            void ExecuteDrawProcedure()
            {
                sm.Draw();

                mainWindow_->SwapBuffers();
            }
		};

	}

}