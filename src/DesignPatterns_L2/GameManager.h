#pragma once

#include "Frame.h"
#include "IDrawable.h"
#include "GameObject.h"
#include "Singleton.h"
#include <memory>
#include <list>

namespace l2
{

	namespace sys
	{

		class GameManager : public Singleton<GameManager>
		{
			friend class std::shared_ptr<GameManager>;
		private:
			GameManager();
			GameManager(const GameManager & right) = delete;

			/// The main console window frame (single buffered)
			l2::rendering::Frame mainFrame_;

			/// Holds all objects to be drawn on screen
			std::list<l2::rendering::IDrawable> screenObjects_;

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

			/// Starts runnning the main loop until an interrupt is requested
			void RunMainLoop();
		};

	}

}