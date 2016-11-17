#pragma once

#include <stdint.h>
#include <string>

namespace l2
{

	namespace sys
	{

		class Message
		{
        private:
            Message() = delete;
        protected:
            uint64_t messageType_;
		public:
            Message(const uint64_t messageType) : messageType_(messageType) { }
            Message(const Message & right) : messageType_(right.messageType_) { }

            const uint64_t GetMessageType() { return messageType_; }
		};

	}

}