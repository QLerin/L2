#pragma once

#include <mutex>
#include <list>
#include <memory>
#include <utility>
#include "MapStorage.h"
#include "ArrayStorage.h"
//#include "Sender.h"
//#include "Receiver.h"

namespace l2
{

    namespace sys
    {

        /// Acts as a registration point for instances of Sender and Receiver
        ///
        /// Stores all information in an unordered_map thread-safe wrapper
        /// The unordered_map and the key share one mutex, while the receiver array shares another
        ///
        /// The idea is that you peform registration to receive/send information of a specific message type
        /// and at the end of object lifecycle, or explict unregistration, messages are no longer sent to the specific
        /// receiver
        template <typename T>
        class Sender;

        template <typename T>
        class Receiver;

        template <typename T >
        class Register
        {
        public:
            typedef ArrayStorage<Receiver<T>> receiverList_t;
            typedef std::pair <Sender<T>*, receiverList_t *> unit_t;
        private:
            MapStorage<uint64_t, unit_t> container_;
        public:
            Register() = default;
            Register(const Register & right) = delete;

            bool RegisterSender(const uint64_t messageType, Sender<T> * sender);
            bool UnregisterSender(Sender<T> * sender);

            bool RegisterReceiver(const uint64_t messageType, Receiver<T> * receiver);
            bool UnregisterReceiver(Receiver<T> * receiver);

            receiverList_t * GetReceiverList(const uint64_t messageType)
            {
                {
                    std::lock_guard<std::recursive_mutex> lock(container_.GetContainerLock());
                    if (container_[messageType] && container_[messageType]->first)
                        return container_[messageType]->second;
                }

                return nullptr;
            }

        };

        template <typename T>
        bool Register<T>::RegisterSender(const uint64_t messageType, Sender<T> * sender)
        {
            if (!container_[messageType])
            {
                container_.AddResource(new unit_t, messageType);
                *(container_[messageType]) = std::make_pair(nullptr, new receiverList_t());
            }
            else if (container_[messageType]->first == sender)
                return false;

            container_[messageType]->first = sender;
            sender->messageType_ = messageType;
            sender->register_ = this;

            return true;
        }

        template <typename T>
        bool Register<T>::UnregisterSender(Sender<T> * sender)
        {
            std::recursive_mutex & mtx(container_.GetContainerLock());
            std::lock_guard<std::recursive_mutex> lock(mtx);
            if (!sender || container_[sender->messageType_]->first != sender)
                return false;

            container_[sender->messageType_]->first = nullptr;
            sender->register_ = nullptr;
            sender->messageType_ = UNDEFINED_MESSAGE;

            return true;
        }

        template <typename T>
        bool Register<T>::RegisterReceiver(const uint64_t messageType, Receiver<T> * receiver)
        {
            if (!receiver || messageType == UNDEFINED_MESSAGE)
                return false;

            std::lock_guard<std::recursive_mutex> lock(container_.GetContainerLock());
            if (!container_[messageType])
            {
                container_.AddResource(new unit_t, messageType);
                *(container_[messageType]) = make_pair(nullptr, new receiverList_t());
            }
            
            unit_t * refNode(container_[messageType]);

            std::lock_guard<std::recursive_mutex> nodeLock(refNode->second->GetContainerLock());

            for (uint16_t i = 0; i < refNode->second->GetStorageSize(); ++i)
                if ((*refNode->second)[i] == receiver)
                    return false;

            refNode->second->AddResource(receiver, 0);
            receiver->messageType_ = messageType;
            receiver->register_ = this;

            return true;
        }

        template <typename T>
        bool Register<T>::UnregisterReceiver(Receiver<T> * receiver)
        {
            if (!receiver || receiver->messageType_ == UNDEFINED_MESSAGE)
                return false;

            unit_t * refNode(container_[receiver->messageType_]);

            bool wasRemoved(false);
            if (refNode)
            {
                std::lock_guard<std::recursive_mutex> nodeLock(refNode->second->GetContainerLock());
                for (uint16_t i = 0; i < refNode->second->GetStorageSize(); ++i)
                {
                    if ((*refNode->second)[i] == receiver)
                    {
                        refNode->second->RemoveResource(i);
                        wasRemoved = true;
                        break;
                    }
                }
            }
            return wasRemoved;
        }

    }

}