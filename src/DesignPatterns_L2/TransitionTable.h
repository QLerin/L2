#pragma once

#include <utility>
#include "UIComponent.h"

namespace l2
{

    namespace sys
    {

        /// Class for handling transitions between UI components
        ///
        /// Implemented as a "sort-of" b-tree
        /// Transition table controlled dynamically (insert/remove transitions)
        class TransitionTable
        {
        private:
#define uicmp l2::gameobjects::UIComponent

            TransitionTable(const TransitionTable & right) = delete;
            TransitionTable(const TransitionTable && right) = delete;

            void operator =(const TransitionTable & right) = delete;
        public:
            struct TRANSITION
            {
                /// Transition forward
                uicmp * forward;
                /// Transition backward
                uicmp * backward;
                TRANSITION() : forward(nullptr), backward(nullptr) { ; }
                TRANSITION(const TRANSITION & right) : forward(right.forward), backward(right.backward) { }
            };
        protected:
            std::vector<std::pair<uicmp *, TRANSITION>> itemTransition_;

        public:
            TransitionTable();

            uicmp * const Retrieve(const uicmp::MenuActionReturn code,
                                   const uicmp * const component);
            
            void Assign(uicmp * const component, const TRANSITION transitions);

            void Remove(const uicmp * const component);

            void ClearTable();
            
            /// Return the front element of the transition table
            ///
            /// The first element should be considered the start node
            const uicmp * const GetFrontElement() const;
        };

    }

}