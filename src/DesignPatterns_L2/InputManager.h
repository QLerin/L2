#pragma once

#include <thread>
#include "Singleton.h"
#include "Sender.h"
#include "Message.h"

namespace l2
{

	namespace sys
	{

		class InputManager : public Singleton<InputManager>
		{
		private:
			InputManager() : isRunning_(false) { }
			InputManager(const InputManager & right) = delete;
			std::thread inputThread_;

			Sender<Message> inputSender_;

			bool isRunning_;
			void PollInput();
		public:
			enum ConsoleInput
			{
				KEY_UP,
				KEY_DOWN,
				KEY_LEFT,
				KEY_RIGHT,
				KEY_Q,
				KEY_W,
				KEY_R,
				KEY_T,
				KEY_ESC
			};

			void StartPolling();
			void StopPolling();
		};

	}

}