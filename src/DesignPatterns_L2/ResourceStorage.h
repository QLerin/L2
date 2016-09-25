#pragma once

#include <memory>
#include <string>
#include <mutex>
#include <assert.h>

namespace l2
{
	namespace sys
	{
		/// Resource storage, defined by type of resource and type of identifier
		///
		/// The basic idea is that you ask for a resource and then get a reference return
		/// If you want to then use the resource and it is (for example) a list that can be accessed by multiple threads
		/// You would request a reference to the container lock and lock it yourself
		///
		/// \note To avoid permalocks, use RAII mutex locking instead of the mutex methods
		template <typename K, typename T>
		class IResourceStorage
		{
		private:
			IResourceStorage(const IResourceStorage & right) = delete;
		protected:
			IResourceStorage() : shouldPerformCleanup_(false) { }
            IResourceStorage(const bool performCleanup) : shouldPerformCleanup_(performCleanup) { }

            std::recursive_mutex containerLock_;
            const bool shouldPerformCleanup_;

            virtual T * const GetResource(const K & identifier) = 0;
		public:
			T * const operator[](const K & accessor) { return GetResource(accessor); }

			virtual void AddResource(T * const resource, const K & identifier) = 0;
			virtual void RemoveResource(const K & identifier) = 0;
			virtual const uint64_t GetStorageSize() const = 0;


			std::recursive_mutex & GetContainerLock() { return containerLock_; }
		};
	}
}