#pragma once

#include "ResourceStorage.h"
#include <unordered_map>
#include <mutex>

namespace l2
{
	namespace sys
	{

		/// Container for large data sets
		template <typename K, typename T>
		class MapStorage : public IResourceStorage<K, T>
		{
		private:
			std::unordered_map<K, T *> container_;

            void PerformCleanup();
		protected:
			virtual T * const GetResource(const K & identifier);
		public:
			MapStorage() = default;
			MapStorage(const MapStorage & right);
            ~MapStorage();

			void AddResource(T * const resource, const K & identifier);
			void RemoveResource(const K & identifier);
			const uint64_t GetStorageSize() const { return container_.size(); }

		};

        template <typename K, typename T>
        void MapStorage<K, T>::PerformCleanup()
        {
        }

		template <typename K, typename T>
		MapStorage<K, T>::MapStorage(const MapStorage<K, T> & right) : container_(right.container_)
		{
		}

        template <typename K, typename T>
        MapStorage<K, T>::~MapStorage()
        {
            if (shouldPerformCleanup_)
                PerformCleanup();
        }

		template <typename K, typename T>
		T * const MapStorage<K, T>::GetResource(const K & identifier)
		{
			std::lock_guard<std::recursive_mutex> lock(containerLock_);
			return container_[identifier];
		}

		template <typename K, typename T>
		void MapStorage<K, T>::RemoveResource(const K & identifier)
		{
			std::lock_guard<std::recursive_mutex> lock(containerLock_);
			container_.erase(identifier);
		}

		template <typename K, typename T>
		void MapStorage<K, T>::AddResource(T * const resource, const K & identifier)
		{
			std::lock_guard<std::recursive_mutex> lock(containerLock_);
			if (!container_[identifier])
				container_[identifier] = resource;
		}

	}
}