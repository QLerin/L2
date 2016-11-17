#include "UIComponent.h"

using namespace std;
using namespace l2::rendering;
using namespace l2::gameobjects;

void UIComponent::SetOffsetX(const uint16_t offset)
{
    uint16_t oldOffset = xOffset_;

    uint16_t x, y, w, h;
    drawable_.GetDrawableSpace(x, y, w, h);
    x -= oldOffset;
    xOffset_ = offset;
    x += offset;

    drawable_.SetDrawableSpace(x, y, w, h);
}

void UIComponent::SetOffsetY(const uint16_t offset)
{
    uint16_t oldOffset = xOffset_;

    uint16_t x, y, w, h;
    drawable_.GetDrawableSpace(x, y, w, h);
    y -= oldOffset;
    yOffset_ = offset;
    y += offset;

    drawable_.SetDrawableSpace(x, y, w, h);
}

void UIComponent::SetOffsets(const uint16_t xOffset, const uint16_t yOffset)
{
    uint16_t oldOffsetX = xOffset_;
    uint16_t oldOffsetY = yOffset_;

    uint16_t x, y, w, h;
    drawable_.GetDrawableSpace(x, y, w, h);
    y -= oldOffsetY;
    x -= oldOffsetX;

    yOffset_ = yOffset;
    xOffset_ = xOffset;
    y += yOffset;
    x += xOffset;
    
    drawable_.SetDrawableSpace(x, y, w, h);
}

void UIComponent::SetParentWindow(const shared_ptr<ConsoleWindow> & window)
{
    window_ = window; 
    drawable_.SetParentWindow(window);
}

const bool UIComponent::Validate(const bool checkParent) const
{
    return (ValidationHook() && ((parent_ != nullptr || checkParent)));
}