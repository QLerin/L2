#pragma once

#include <memory>
#include <list>
#include "Receiver.h"

namespace l2
{

	namespace sys
	{

		template <typename T>
		class Register;

		static const uint64_t UNDEFINED_MESSAGE = 0xFFFFFFFFFFFFFFFF;

		template <class T>
		class Sender
		{
			friend Register<T>;
		private:
			uint64_t messageType_;
			Register<T> * register_;
		public:
			Sender() : messageType_(UNDEFINED_MESSAGE), register_(nullptr) { }
			Sender(const Sender & right) = delete;
			virtual ~Sender();

			void BroadcastMessage(const std::shared_ptr<T> & message);
		};

		template <typename T>
		Sender<T>::~Sender()
		{
			if (register_)
				register_->UnregisterSender(this);
		}
		
		template <typename T>
		void Sender<T>::BroadcastMessage(const std::shared_ptr<T> & message)
		{
			if (register_ && messageType_ != UNDEFINED_MESSAGE)
			{
				auto lst(register_->GetReceiverList(messageType_));
                for (uint16_t i = 0; i < lst->GetStorageSize(); ++i)
                    if ((*lst)[i])
                        (*lst)[i]->HandleMessage(message);
			}
		}

	}

}