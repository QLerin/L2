#include "SUIComponent.h"

using namespace std;
using namespace l2::sys;
using namespace l2::gameobjects;
using namespace l2::rendering;

void SUIComponent::AddChild(UIComponent * component)
{
    if (!component)
    {
        LOG_WARNING("Attempting to add null component to " + componentName_);
        return;
    }

    if (child_)
        LOG_WARNING("Replacing children in " + componentName_);

    child_ = component;
}

#pragma warning (push)
#pragma warning (disable : 4100) // Argument is there in case child should be removed by address
void SUIComponent::RemoveChild(UIComponent * component)
{
    child_ = nullptr;
}
#pragma warning (pop)

const bool SUIComponent::Validate(const bool checkParent) const
{
    return (__super::Validate(checkParent) && (child_ != nullptr || !checkParent));
}

UIComponent * SUIComponent::GetActiveComponent()
{ 
    if (child_)
        return child_->GetActiveComponent();
    else
        return this;
}

void SUIComponent::SetParentWindow(const shared_ptr<ConsoleWindow> & window)
{
    __super::SetParentWindow(window);
    if (child_)
        child_->SetParentWindow(window);
}

UIComponent::MenuActionReturn SUIComponent::Next()
{ 
    return UIComponent::NoAction;
}

UIComponent::MenuActionReturn SUIComponent::Previous()
{ 
    return UIComponent::NoAction; 
}

UIComponent::MenuActionReturn SUIComponent::Exit()
{ 
    if (parent_)
        return parent_->Exit();
    return NoAction; 
}

SUIComponent::~SUIComponent()
{
    delete child_;
}