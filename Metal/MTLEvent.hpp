//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLEvent.hpp
//
// Copyright 2020-2025 Apple Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

// ReSharper disable CppInconsistentNaming
#pragma once

#include <cstdint>
#include <dispatch/dispatch.h>
#include "../Foundation/Foundation.hpp"
#include "MTLDefines.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"

#include <functional>

namespace MTL
{
    class Device;
    class SharedEvent;
    class SharedEventHandle;
    class SharedEventListener;

    using SharedEventNotificationBlock    = void (^)(SharedEvent* pEvent, std::uint64_t value);
    using SharedEventNotificationFunction = std::function<void(SharedEvent* pEvent, std::uint64_t value)>;

    /// @see https://developer.apple.com/documentation/metal/mtlevent?language=objc
    class Event : public NS::Referencing<Event>
    {
    public:
        [[nodiscard]] Device* device() const;

        [[nodiscard]] NS::String* label() const;
        void                      setLabel(const NS::String* label) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlsharedeventlistener?language=objc
    class SharedEventListener : public NS::Referencing<SharedEventListener>
    {
    public:
        [[nodiscard]] static SharedEventListener* alloc();

        [[nodiscard]] dispatch_queue_t dispatchQueue() const;

        [[nodiscard]] SharedEventListener* init();
        [[nodiscard]] SharedEventListener* init(dispatch_queue_t dispatchQueue) const;

        [[nodiscard]] static SharedEventListener* sharedListener();
    };

    /// @see https://developer.apple.com/documentation/metal/mtlsharedevent?language=objc
    class SharedEvent : public NS::Referencing<SharedEvent, Event>
    {
    public:
        [[nodiscard]] SharedEventHandle* newSharedEventHandle() const;

        void notifyListener(const SharedEventListener* listener, uint64_t value, SharedEventNotificationBlock block);
        void notifyListener(const SharedEventListener*             listener,
                            uint64_t                               value,
                            const SharedEventNotificationFunction& function);

        void                   setSignaledValue(uint64_t signaledValue) const;
        [[nodiscard]] uint64_t signaledValue() const;
        [[nodiscard]] bool     waitUntilSignaledValue(uint64_t value, uint64_t milliseconds) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlsharedeventhandle?language=objc
    class SharedEventHandle : public NS::SecureCoding<SharedEventHandle>
    {
    public:
        [[nodiscard]] static SharedEventHandle* alloc();

        [[nodiscard]] SharedEventHandle* init();

        [[nodiscard]] NS::String* label() const;
    };

} // namespace MTL
_MTL_INLINE MTL::Device* MTL::Event::device() const { return sendMessage<Device*>(this, _MTL_PRIVATE_SEL(device)); }

_MTL_INLINE NS::String* MTL::Event::label() const { return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label)); }

_MTL_INLINE void MTL::Event::setLabel(const NS::String* label) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLabel_), label);
}

_MTL_INLINE MTL::SharedEventListener* MTL::SharedEventListener::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<SharedEventListener>(_MTL_PRIVATE_CLS(MTLSharedEventListener));
}

_MTL_INLINE dispatch_queue_t MTL::SharedEventListener::dispatchQueue() const
{
    return sendMessage<dispatch_queue_t>(this, _MTL_PRIVATE_SEL(dispatchQueue));
}

_MTL_INLINE MTL::SharedEventListener* MTL::SharedEventListener::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<SharedEventListener>();
}

// ReSharper disable once CppParameterMayBeConst
_MTL_INLINE MTL::SharedEventListener* MTL::SharedEventListener::init(dispatch_queue_t dispatchQueue) const
{
    return sendMessage<SharedEventListener*>(this, _MTL_PRIVATE_SEL(initWithDispatchQueue_), dispatchQueue);
}

_MTL_INLINE MTL::SharedEventListener* MTL::SharedEventListener::sharedListener()
{
    return sendMessage<SharedEventListener*>(_MTL_PRIVATE_CLS(MTLSharedEventListener),
                                             _MTL_PRIVATE_SEL(sharedListener));
}

_MTL_INLINE MTL::SharedEventHandle* MTL::SharedEvent::newSharedEventHandle() const
{
    return sendMessage<SharedEventHandle*>(this, _MTL_PRIVATE_SEL(newSharedEventHandle));
}

_MTL_INLINE void MTL::SharedEvent::notifyListener(const SharedEventListener*         listener,
                                                  uint64_t                           value,
                                                  const SharedEventNotificationBlock block)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(notifyListener_atValue_block_), listener, value, block);
}

_MTL_INLINE void MTL::SharedEvent::notifyListener(const SharedEventListener*             listener,
                                                  uint64_t                               value,
                                                  const SharedEventNotificationFunction& function)
{
    __block SharedEventNotificationFunction callback = function;
    notifyListener(listener, value, ^void(SharedEvent* pEvent, std::uint64_t innerValue) {
      callback(pEvent, innerValue);
    });
}

_MTL_INLINE void MTL::SharedEvent::setSignaledValue(const uint64_t signaledValue) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSignaledValue_), signaledValue);
}

_MTL_INLINE uint64_t MTL::SharedEvent::signaledValue() const
{
    return sendMessage<uint64_t>(this, _MTL_PRIVATE_SEL(signaledValue));
}

_MTL_INLINE bool MTL::SharedEvent::waitUntilSignaledValue(const uint64_t value, const uint64_t milliseconds) const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(waitUntilSignaledValue_timeoutMS_), value, milliseconds);
}

_MTL_INLINE MTL::SharedEventHandle* MTL::SharedEventHandle::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<SharedEventHandle>(_MTL_PRIVATE_CLS(MTLSharedEventHandle));
}

_MTL_INLINE MTL::SharedEventHandle* MTL::SharedEventHandle::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<SharedEventHandle>();
}

_MTL_INLINE NS::String* MTL::SharedEventHandle::label() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
}
