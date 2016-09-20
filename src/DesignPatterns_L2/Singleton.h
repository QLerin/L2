#pragma once

#include <mutex>
#include <memory>

namespace l2
{

	namespace sys
	{

		template <typename T> class Singleton
		{
			friend std::shared_ptr<T>;
		private:
			static std::mutex initLock_;
		protected:
			Singleton() { }
			Singleton(const Singleton<T> & right) = delete;

			static std::shared_ptr<T> instance_;
		public:
			static std::shared_ptr<T> GetInstance();
		};

		template <typename T>
		std::mutex Singleton<T>::initLock_;

		template <typename T>
		std::shared_ptr<T> Singleton<T>::instance_(nullptr);

		template <typename T>
		std::shared_ptr<T> Singleton<T>::GetInstance()
		{
			if (!instance_)
			{
				std::lock_guard<std::mutex> lock(initLock_);
				if(!instance_)
					instance_ = std::shared_ptr<T>(new T);
			}
			return instance_;
		}

	}

}