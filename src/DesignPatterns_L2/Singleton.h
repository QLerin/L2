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
			Singleton(const Singleton<T> & right) = delete;

			static std::shared_ptr<T> instance_;
		public:
			static std::shared_ptr<T> GetInstance();
		};

		template <typename T>
		std::shared_ptr<T> Singleton<T>::instance_(nullptr);

		template <typename T>
		std::shared_ptr<T> Singleton<T>::GetInstance()
		{
			if (!instance_)
				instance_ = std::shared_ptr<T>(new T);
			return instance_;
		}

	}

}