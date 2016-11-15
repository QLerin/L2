#include "PUIComponent.h"

using namespace l2::gameobjects;
using namespace l2::sys;

void PUIComponent::AddChild(UIComponent * component)
{
    if (!component)
        return;
    children_.AddResource(component, 0);
}

void PUIComponent::RemoveChild(UIComponent * component)
{
    if (!component)
        return;

    std::lock_guard<std::recursive_mutex> lock(children_.GetContainerLock());

    for (uint16_t i = 0; i < children_.GetStorageSize(); ++i)
    {
        if (children_[i] == component)
        {
            children_.RemoveResource(i);
            return;
        }
    }
}