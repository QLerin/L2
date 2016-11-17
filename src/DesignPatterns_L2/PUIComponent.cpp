#include "PUIComponent.h"

using namespace std;
using namespace l2::gameobjects;
using namespace l2::sys;
using namespace l2::rendering;

PUIComponent::~PUIComponent()
{
    for (uint16_t i = 0; i < children_.GetStorageSize(); ++i)
        if (children_[i])
            delete children_[i];
}

const bool PUIComponent::TransitionLeft()
{
    if (selectedIndex_ == 0)
        return true;
    --selectedIndex_;
    return false;
}

const bool PUIComponent::TransitionRight()
{
    if (++selectedIndex_ >= children_.GetStorageSize())
    {
#pragma warning (push)
#pragma warning (disable : 4244) //Operating on ArrayStorage with max capacity of unsigned dword
        selectedIndex_ = children_.GetStorageSize() - 1;
#pragma warning (pop)
        return true;
    }
    return false;
}

void PUIComponent::AddChild(UIComponent * component)
{
    if (!component)
        return;
    children_.AddResource(component, 0);
    component->SetParent(this);
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

const bool PUIComponent::Validate(const bool checkParent) const
{
    return (__super::Validate(checkParent) && (children_.GetStorageSize()>0 || !checkParent));
}

void PUIComponent::SetParentWindow(const shared_ptr<ConsoleWindow> & window)
{
    __super::SetParentWindow(window);
    for (uint16_t i = 0; i < children_.GetStorageSize(); ++i)
        if (children_[i])
            children_[i]->SetParentWindow(window);
}

UIComponent * PUIComponent::GetActiveComponent() { 
    if (children_.GetStorageSize() > 0 && children_[selectedIndex_] != nullptr)
        return children_[selectedIndex_];
    else 
        return this;
}

