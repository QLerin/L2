#include "TransitionTable.h"

using namespace std;
using namespace l2::sys;

TransitionTable::TransitionTable()
{
}

uicmp * const TransitionTable::Retrieve(const uicmp::MenuActionReturn code, const uicmp * const component)
{
    auto iter = itemTransition_.begin();
    for (iter; iter != itemTransition_.end(); ++iter)
    {
        if (iter->first == component)
        {
            switch (code)
            {
            case uicmp::RequestFwdTransition:
                return iter->second.forward;
            case uicmp::RequestBwdTransition:
                return iter->second.backward;
            }
            return nullptr;
        }
    }

    return nullptr;
}

void TransitionTable::Assign(uicmp * component, const TRANSITION transitions)
{
    if (!component)
        return;

    itemTransition_.push_back(pair<uicmp *, TRANSITION>(component, transitions));
}

void TransitionTable::Remove(const uicmp * const component)
{
    if (!component)
        return;

    auto iter = itemTransition_.begin();
    for (iter; iter != itemTransition_.end(); ++iter)
        if (iter->first == component)
            itemTransition_.erase(iter);
}

void TransitionTable::ClearTable()
{
#pragma warning (push)
#pragma warning (disable : 4239) //Swap triggering warning
    itemTransition_.swap(vector<pair<uicmp *, TRANSITION>>());
#pragma warning (pop)
}

const uicmp * const TransitionTable::GetFrontElement() const
{
    if (itemTransition_.size() > 0)
        return itemTransition_[0].first;
    return nullptr;
}