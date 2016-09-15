#pragma once

#include <memory>

namespace l2
{

	namespace sys
	{

		template <typename T> class Singleton
		{
			friend std::shared_ptr<T>;
		protected:
			Singleton() { }
			Singleton(const std::shared_ptr & right) = delete;

			static std::shared_ptr<T> instance_;
		public:
			static std::shared_ptr<T> GetInstance();
		};

	}

}