//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLIOCommandQueue.hpp
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

#include "../Foundation/Foundation.hpp"
#include "MTLDefines.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"

namespace MTL
{
    class Buffer;
    class IOCommandBuffer;
    class IOCommandQueueDescriptor;
    class IOScratchBuffer;
    class IOScratchBufferAllocator;

    /// @see https://developer.apple.com/documentation/metal/mtliopriority?language=objc
    _MTL_ENUM(NS::Integer, IOPriority){
        IOPriorityHigh   = 0,
        IOPriorityNormal = 1,
        IOPriorityLow    = 2,
    };

    /// @see https://developer.apple.com/documentation/metal/mtliocommandqueuetype?language=objc
    _MTL_ENUM(NS::Integer, IOCommandQueueType){
        IOCommandQueueTypeConcurrent = 0,
        IOCommandQueueTypeSerial     = 1,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlioerror?language=objc
    _MTL_ENUM(NS::Integer, IOError){
        IOErrorURLInvalid = 1,
        IOErrorInternal   = 2,
    };

    _MTL_CONST(NS::ErrorDomain, IOErrorDomain);

    /// @see https://developer.apple.com/documentation/metal/mtliocommandqueue?language=objc
    class IOCommandQueue : public NS::Referencing<IOCommandQueue>
    {
    public:
        [[nodiscard]] IOCommandBuffer* commandBuffer() const;
        [[nodiscard]] IOCommandBuffer* commandBufferWithUnretainedReferences() const;

        void enqueueBarrier() const;

        [[nodiscard]] NS::String* label() const;
        void                      setLabel(const NS::String* label) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlioscratchbuffer?language=objc
    class IOScratchBuffer : public NS::Referencing<IOScratchBuffer>
    {
    public:
        [[nodiscard]] Buffer* buffer() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlioscratchbufferallocator?language=objc
    class IOScratchBufferAllocator : public NS::Referencing<IOScratchBufferAllocator>
    {
    public:
        [[nodiscard]] IOScratchBuffer* newScratchBuffer(NS::UInteger minimumSize) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtliocommandqueuedescriptor?language=objc
    class IOCommandQueueDescriptor : public NS::Copying<IOCommandQueueDescriptor>
    {
    public:
        [[nodiscard]] static IOCommandQueueDescriptor* alloc();

        [[nodiscard]] IOCommandQueueDescriptor* init();

        [[nodiscard]] NS::UInteger maxCommandBufferCount() const;

        [[nodiscard]] NS::UInteger maxCommandsInFlight() const;

        [[nodiscard]] IOPriority priority() const;

        [[nodiscard]] IOScratchBufferAllocator* scratchBufferAllocator() const;

        void setMaxCommandBufferCount(NS::UInteger maxCommandBufferCount) const;

        void setMaxCommandsInFlight(NS::UInteger maxCommandsInFlight) const;

        void setPriority(IOPriority priority) const;

        void setScratchBufferAllocator(const IOScratchBufferAllocator* scratchBufferAllocator) const;

        void                             setType(IOCommandQueueType type) const;
        [[nodiscard]] IOCommandQueueType type() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtliofilehandle?language=objc
    class IOFileHandle : public NS::Referencing<IOFileHandle>
    {
    public:
        [[nodiscard]] NS::String* label() const;
        void                      setLabel(const NS::String* label) const;
    };

} // namespace MTL
_MTL_PRIVATE_DEF_CONST(NS::ErrorDomain, IOErrorDomain);
_MTL_INLINE MTL::IOCommandBuffer* MTL::IOCommandQueue::commandBuffer() const
{
    return sendMessage<IOCommandBuffer*>(this, _MTL_PRIVATE_SEL(commandBuffer));
}

_MTL_INLINE MTL::IOCommandBuffer* MTL::IOCommandQueue::commandBufferWithUnretainedReferences() const
{
    return sendMessage<IOCommandBuffer*>(this, _MTL_PRIVATE_SEL(commandBufferWithUnretainedReferences));
}

_MTL_INLINE void MTL::IOCommandQueue::enqueueBarrier() const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(enqueueBarrier));
}

_MTL_INLINE NS::String* MTL::IOCommandQueue::label() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
}

_MTL_INLINE void MTL::IOCommandQueue::setLabel(const NS::String* label) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLabel_), label);
}

_MTL_INLINE MTL::Buffer* MTL::IOScratchBuffer::buffer() const
{
    return sendMessage<Buffer*>(this, _MTL_PRIVATE_SEL(buffer));
}

_MTL_INLINE MTL::IOScratchBuffer* MTL::IOScratchBufferAllocator::newScratchBuffer(const NS::UInteger minimumSize) const
{
    return sendMessage<IOScratchBuffer*>(this, _MTL_PRIVATE_SEL(newScratchBufferWithMinimumSize_), minimumSize);
}

_MTL_INLINE MTL::IOCommandQueueDescriptor* MTL::IOCommandQueueDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<IOCommandQueueDescriptor>(_MTL_PRIVATE_CLS(MTLIOCommandQueueDescriptor));
}

_MTL_INLINE MTL::IOCommandQueueDescriptor* MTL::IOCommandQueueDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<IOCommandQueueDescriptor>();
}

_MTL_INLINE NS::UInteger MTL::IOCommandQueueDescriptor::maxCommandBufferCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxCommandBufferCount));
}

_MTL_INLINE NS::UInteger MTL::IOCommandQueueDescriptor::maxCommandsInFlight() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxCommandsInFlight));
}

_MTL_INLINE MTL::IOPriority MTL::IOCommandQueueDescriptor::priority() const
{
    return sendMessage<IOPriority>(this, _MTL_PRIVATE_SEL(priority));
}

_MTL_INLINE MTL::IOScratchBufferAllocator* MTL::IOCommandQueueDescriptor::scratchBufferAllocator() const
{
    return sendMessage<IOScratchBufferAllocator*>(this, _MTL_PRIVATE_SEL(scratchBufferAllocator));
}

_MTL_INLINE void MTL::IOCommandQueueDescriptor::setMaxCommandBufferCount(const NS::UInteger maxCommandBufferCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxCommandBufferCount_), maxCommandBufferCount);
}

_MTL_INLINE void MTL::IOCommandQueueDescriptor::setMaxCommandsInFlight(const NS::UInteger maxCommandsInFlight) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxCommandsInFlight_), maxCommandsInFlight);
}

_MTL_INLINE void MTL::IOCommandQueueDescriptor::setPriority(const IOPriority priority) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setPriority_), priority);
}

_MTL_INLINE void MTL::IOCommandQueueDescriptor::setScratchBufferAllocator(
    const IOScratchBufferAllocator* scratchBufferAllocator) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setScratchBufferAllocator_), scratchBufferAllocator);
}

_MTL_INLINE void MTL::IOCommandQueueDescriptor::setType(const IOCommandQueueType type) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setType_), type);
}

_MTL_INLINE MTL::IOCommandQueueType MTL::IOCommandQueueDescriptor::type() const
{
    return sendMessage<IOCommandQueueType>(this, _MTL_PRIVATE_SEL(type));
}

_MTL_INLINE NS::String* MTL::IOFileHandle::label() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
}

_MTL_INLINE void MTL::IOFileHandle::setLabel(const NS::String* label) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLabel_), label);
}
