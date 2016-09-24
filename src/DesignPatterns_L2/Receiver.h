#pragma once

#include <Windows.h>
#include <mutex>
#include <thread>
#include <memory>
#include <queue>
#include "Register.h"

namespace l2
{

	namespace sys
	{

		template <typename T>
		class Receiver
		{
			friend Register<T>;
		private:
			Register<T> * register_;
            uint64_t messageType_;
		protected:
			Receiver() : register_(nullptr), messageType_(UNDEFINED_MESSAGE) { }
			Receiver(const Receiver & right) = delete;
		public:
			virtual ~Receiver();
            virtual void HandleMessage(const std::shared_ptr<T> & message) = 0;
		};

		template <typename T>
		Receiver<T>::~Receiver()
		{
			if(register_)
				register_->UnregisterReceiver(this);
		}

	}

}