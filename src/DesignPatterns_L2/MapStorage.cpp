#include "stdafx.h"
#include "MapStorage.h"

using namespace std;
using namespace LT::Resources;

template <typename tID>
shared_ptr<IResource> MapStorage<tID>::GetResource(const tID & identifier)
{
	lock_guard<mutex> lock(containerMutex_);
	return container_[identifier];
}

template <typename tID>
void MapStorage<tID>::RemoveResource(const tID & identifier)
{
	lock_guard<mutex> lock(containerMutex_);
	container_.erase(identifier);
}

template <typename tID>
void MapStorage<tID>::AddResource(const shared_ptr<IResource> & resource, const tID & identifier)
{
	lock_guard<mutex> lock(containerMutex_);
	if (!container_[identifier])
	{
		container_[identifier] = resource;
		return true;
	}

	return false;
}

template <typename tID>
void MapStorage<tID>::FindAndDo(const tID & identifier, void(*pFunction)(shared_ptr<IResource> & resource))
{
	shared_ptr<IResource> resourcePointer(nullptr);
	{
		lock_guard<mutex> lock(containerMutex_);
		resourcePointer = container_[identifier];
	}
	if (resourcePointer)
		pFunction(resourcePointer);
}