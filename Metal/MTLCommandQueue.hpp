//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLCommandQueue.hpp
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
    class CommandBuffer;
    class CommandBufferDescriptor;
    class CommandQueueDescriptor;
    class Device;
    class LogState;
    class ResidencySet;

    /// @see https://developer.apple.com/documentation/metal/mtlcommandqueue?language=objc
    class CommandQueue : public NS::Referencing<CommandQueue>
    {
    public:
        void addResidencySet(const ResidencySet* residencySet) const;
        void addResidencySets(const ResidencySet* const residencySets[], NS::UInteger count) const;

        [[nodiscard]] CommandBuffer* commandBuffer() const;
        [[nodiscard]] CommandBuffer* commandBuffer(const CommandBufferDescriptor* descriptor) const;
        [[nodiscard]] CommandBuffer* commandBufferWithUnretainedReferences() const;

        [[nodiscard]] Device* device() const;

        void insertDebugCaptureBoundary() const;

        [[nodiscard]] NS::String* label() const;

        void removeResidencySet(const ResidencySet* residencySet) const;
        void removeResidencySets(const ResidencySet* const residencySets[], NS::UInteger count) const;

        void setLabel(const NS::String* label) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlcommandqueuedescriptor?language=objc
    class CommandQueueDescriptor : public NS::Copying<CommandQueueDescriptor>
    {
    public:
        [[nodiscard]] static CommandQueueDescriptor* alloc();

        [[nodiscard]] CommandQueueDescriptor* init();

        [[nodiscard]] LogState* logState() const;

        [[nodiscard]] NS::UInteger maxCommandBufferCount() const;

        void setLogState(const LogState* logState) const;

        void setMaxCommandBufferCount(NS::UInteger maxCommandBufferCount) const;
    };

} // namespace MTL
_MTL_INLINE void MTL::CommandQueue::addResidencySet(const ResidencySet* residencySet) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(addResidencySet_), residencySet);
}

_MTL_INLINE void MTL::CommandQueue::addResidencySets(const ResidencySet* const residencySets[],
                                                     const NS::UInteger        count) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(addResidencySets_count_), residencySets, count);
}

_MTL_INLINE MTL::CommandBuffer* MTL::CommandQueue::commandBuffer() const
{
    return sendMessage<CommandBuffer*>(this, _MTL_PRIVATE_SEL(commandBuffer));
}

_MTL_INLINE MTL::CommandBuffer* MTL::CommandQueue::commandBuffer(const CommandBufferDescriptor* descriptor) const
{
    return sendMessage<CommandBuffer*>(this, _MTL_PRIVATE_SEL(commandBufferWithDescriptor_), descriptor);
}

_MTL_INLINE MTL::CommandBuffer* MTL::CommandQueue::commandBufferWithUnretainedReferences() const
{
    return sendMessage<CommandBuffer*>(this, _MTL_PRIVATE_SEL(commandBufferWithUnretainedReferences));
}

_MTL_INLINE MTL::Device* MTL::CommandQueue::device() const
{
    return sendMessage<Device*>(this, _MTL_PRIVATE_SEL(device));
}

_MTL_INLINE void MTL::CommandQueue::insertDebugCaptureBoundary() const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(insertDebugCaptureBoundary));
}

_MTL_INLINE NS::String* MTL::CommandQueue::label() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
}

_MTL_INLINE void MTL::CommandQueue::removeResidencySet(const ResidencySet* residencySet) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(removeResidencySet_), residencySet);
}

_MTL_INLINE void MTL::CommandQueue::removeResidencySets(const ResidencySet* const residencySets[],
                                                        const NS::UInteger        count) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(removeResidencySets_count_), residencySets, count);
}

_MTL_INLINE void MTL::CommandQueue::setLabel(const NS::String* label) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLabel_), label);
}

_MTL_INLINE MTL::CommandQueueDescriptor* MTL::CommandQueueDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<CommandQueueDescriptor>(_MTL_PRIVATE_CLS(MTLCommandQueueDescriptor));
}

_MTL_INLINE MTL::CommandQueueDescriptor* MTL::CommandQueueDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<CommandQueueDescriptor>();
}

_MTL_INLINE MTL::LogState* MTL::CommandQueueDescriptor::logState() const
{
    return sendMessage<LogState*>(this, _MTL_PRIVATE_SEL(logState));
}

_MTL_INLINE NS::UInteger MTL::CommandQueueDescriptor::maxCommandBufferCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxCommandBufferCount));
}

_MTL_INLINE void MTL::CommandQueueDescriptor::setLogState(const LogState* logState) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLogState_), logState);
}

_MTL_INLINE void MTL::CommandQueueDescriptor::setMaxCommandBufferCount(const NS::UInteger maxCommandBufferCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxCommandBufferCount_), maxCommandBufferCount);
}
