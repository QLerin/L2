#pragma once

#include <thread>
#include "Singleton.h"
#include "Sender.h"
#include "Inputs.h"
#include "MenuActionMessage.h"

namespace l2
{

	namespace sys
	{

		class InputManager : public Singleton<InputManager>
		{
		private:
			InputManager(const InputManager & right) = delete;
			std::thread inputThread_;

			Sender<Message> * inputSender_;

			bool isRunning_;
			void PollInput();

            MenuActionMessage * const CreateActionMessage(const Inputs::KeyCode input);
		public:
            InputManager() : isRunning_(false), inputSender_(nullptr) {}
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