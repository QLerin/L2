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
			InputManager(const InputManager & right) = delete;
			std::thread inputThread_;

			Sender<Message> inputSender_;

			bool isRunning_;
			void PollInput();
		public:
            InputManager() : isRunning_(false) {}
			enum ConsoleInput
			{
				KEY_UP,
				KEY_DOWN,
				KEY_LEFT,
				KEY_RIGHT,
				KEY_Q,
				KEY_W,
				KEY_E,
				KEY_R,
                KEY_I,
				KEY_ESC,
                KEY_ENTER
			};

			void StartPolling(Register<Message> & reg);
			void StopPolling();
		};

	}

}