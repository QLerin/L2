#pragma once

#include <stdint.h>
#include <string>

namespace l2
{

	namespace sys
	{

		class Message
		{
        protected:
            std::string messageString_;
		public:
            Message() : messageString_("") { }
            Message(const std::string & messageString) : messageString_(messageString) { }
            const std::string & GetMessageString() { return messageString_; }
		};

	}

}