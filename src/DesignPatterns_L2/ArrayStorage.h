#pragma once

#include "ResourceStorage.h"
#include <vector>

namespace l2
{
	namespace sys
	{
		
		template < typename T>
		class ArrayStorage : public IResourceStorage<uint32_t, T>
		{
		private:
			static const uint32_t RESOURCE_LIMIT = 0xFFFFFFFF;
			std::vector<T *> container_;

            void PerformCleanup();
        protected:
			virtual T * const GetResource(const uint32_t & identifier);
		public:
            ArrayStorage() : IResourceStorage<uint32_t, T>() {}
			ArrayStorage(const ArrayStorage & right);
            ~ArrayStorage();

			void AddResource(T * const resource, const uint32_t & identifier);
			void RemoveResource(const uint32_t & identifier);
			const uint64_t GetStorageSize() const { return container_.size(); }
		};

        template <typename T>
        void ArrayStorage<T>::PerformCleanup()
        {
        }

		template <typename T>
		ArrayStorage<T>::ArrayStorage(const ArrayStorage & original) : container_(original.container_)
		{
		}

        template <typename T>
        ArrayStorage<T>::~ArrayStorage()
        {
            if (shouldPerformCleanup_)
                PerformCleanup();
        }

		template <typename T>
		T * const ArrayStorage<T>::GetResource(const uint32_t & identifier)
		{
			{
				std::lock_guard<std::recursive_mutex> lock(containerLock_);
				if (container_[identifier])
					return container_[identifier];
			}
			return nullptr;
		}

		template <typename T>
		void ArrayStorage<T>::RemoveResource(const uint32_t & identifier)
		{
			if (identifier >= RESOURCE_LIMIT)
				return;
			std::lock_guard<std::recursive_mutex> lock(containerLock_);
			container_.erase(container_.begin() + identifier);
		}


		template <typename T>
		void ArrayStorage<T>::AddResource(T * const resource, const uint32_t & identifier)
		{
			std::lock_guard<std::recursive_mutex> lock(containerLock_);
			if (identifier && (identifier + container_.begin()) != container_.end())
				container_.insert(container_.begin() + identifier, resource);
			else
				container_.push_back(resource);
		}

	}
}