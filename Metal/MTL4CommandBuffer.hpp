//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTL4CommandBuffer.hpp
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
#include "MTL4RenderCommandEncoder.hpp"
#include "MTLAccelerationStructureTypes.hpp"
#include "MTLDefines.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"

namespace MTL4
{
    class CommandAllocator;
    class CommandBufferOptions;
    class ComputeCommandEncoder;
    class CounterHeap;
    class MachineLearningCommandEncoder;
    class RenderCommandEncoder;
    class RenderPassDescriptor;
} // namespace MTL4

namespace MTL
{
    class Device;
    class Fence;
    class LogState;
    class ResidencySet;
} // namespace MTL

namespace MTL4
{
    class CommandBufferOptions : public NS::Copying<CommandBufferOptions>
    {
    public:
        [[nodiscard]] static CommandBufferOptions* alloc();

        [[nodiscard]] CommandBufferOptions* init();

        [[nodiscard]] MTL::LogState* logState() const;

        void setLogState(const MTL::LogState* logState) const;
    };
    class CommandBuffer : public NS::Referencing<CommandBuffer>
    {
    public:
        void beginCommandBuffer(const CommandAllocator* allocator) const;
        void beginCommandBuffer(const CommandAllocator* allocator, const CommandBufferOptions* options) const;

        [[nodiscard]] ComputeCommandEncoder* computeCommandEncoder() const;

        [[nodiscard]] MTL::Device* device() const;

        void endCommandBuffer() const;

        [[nodiscard]] NS::String* label() const;

        [[nodiscard]] MachineLearningCommandEncoder* machineLearningCommandEncoder() const;

        void popDebugGroup() const;

        void pushDebugGroup(const NS::String* string) const;

        [[nodiscard]] RenderCommandEncoder* renderCommandEncoder(const RenderPassDescriptor* descriptor) const;
        [[nodiscard]] RenderCommandEncoder* renderCommandEncoder(const RenderPassDescriptor* descriptor,
                                                                 RenderEncoderOptions        options) const;

        void resolveCounterHeap(const CounterHeap* counterHeap,
                                NS::Range          range,
                                BufferRange        bufferRange,
                                const MTL::Fence*  fenceToWait,
                                const MTL::Fence*  fenceToUpdate) const;

        void setLabel(const NS::String* label) const;

        void useResidencySet(const MTL::ResidencySet* residencySet) const;
        void useResidencySets(const MTL::ResidencySet* const residencySets[], NS::UInteger count) const;

        void writeTimestampIntoHeap(const CounterHeap* counterHeap, NS::UInteger index) const;
    };

} // namespace MTL4
_MTL_INLINE MTL4::CommandBufferOptions* MTL4::CommandBufferOptions::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<CommandBufferOptions>(_MTL_PRIVATE_CLS(MTL4CommandBufferOptions));
}

_MTL_INLINE MTL4::CommandBufferOptions* MTL4::CommandBufferOptions::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<CommandBufferOptions>();
}

_MTL_INLINE MTL::LogState* MTL4::CommandBufferOptions::logState() const
{
    return sendMessage<MTL::LogState*>(this, _MTL_PRIVATE_SEL(logState));
}

_MTL_INLINE void MTL4::CommandBufferOptions::setLogState(const MTL::LogState* logState) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLogState_), logState);
}

_MTL_INLINE void MTL4::CommandBuffer::beginCommandBuffer(const CommandAllocator* allocator) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(beginCommandBufferWithAllocator_), allocator);
}

_MTL_INLINE void MTL4::CommandBuffer::beginCommandBuffer(const CommandAllocator*     allocator,
                                                         const CommandBufferOptions* options) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(beginCommandBufferWithAllocator_options_), allocator, options);
}

_MTL_INLINE MTL4::ComputeCommandEncoder* MTL4::CommandBuffer::computeCommandEncoder() const
{
    return sendMessage<ComputeCommandEncoder*>(this, _MTL_PRIVATE_SEL(computeCommandEncoder));
}

_MTL_INLINE MTL::Device* MTL4::CommandBuffer::device() const
{
    return sendMessage<MTL::Device*>(this, _MTL_PRIVATE_SEL(device));
}

_MTL_INLINE void MTL4::CommandBuffer::endCommandBuffer() const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(endCommandBuffer));
}

_MTL_INLINE NS::String* MTL4::CommandBuffer::label() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
}

_MTL_INLINE MTL4::MachineLearningCommandEncoder* MTL4::CommandBuffer::machineLearningCommandEncoder() const
{
    return sendMessage<MachineLearningCommandEncoder*>(this, _MTL_PRIVATE_SEL(machineLearningCommandEncoder));
}

_MTL_INLINE void MTL4::CommandBuffer::popDebugGroup() const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(popDebugGroup));
}

_MTL_INLINE void MTL4::CommandBuffer::pushDebugGroup(const NS::String* string) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(pushDebugGroup_), string);
}

_MTL_INLINE MTL4::RenderCommandEncoder* MTL4::CommandBuffer::renderCommandEncoder(
    const RenderPassDescriptor* descriptor) const
{
    return sendMessage<RenderCommandEncoder*>(this, _MTL_PRIVATE_SEL(renderCommandEncoderWithDescriptor_), descriptor);
}

_MTL_INLINE MTL4::RenderCommandEncoder* MTL4::CommandBuffer::renderCommandEncoder(
    const RenderPassDescriptor* descriptor, const RenderEncoderOptions options) const
{
    return sendMessage<RenderCommandEncoder*>(
        this, _MTL_PRIVATE_SEL(renderCommandEncoderWithDescriptor_options_), descriptor, options);
}

_MTL_INLINE void MTL4::CommandBuffer::resolveCounterHeap(const CounterHeap* counterHeap,
                                                         const NS::Range    range,
                                                         const BufferRange  bufferRange,
                                                         const MTL::Fence*  fenceToWait,
                                                         const MTL::Fence*  fenceToUpdate) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(resolveCounterHeap_withRange_intoBuffer_waitFence_updateFence_),
                      counterHeap,
                      range,
                      bufferRange,
                      fenceToWait,
                      fenceToUpdate);
}

_MTL_INLINE void MTL4::CommandBuffer::setLabel(const NS::String* label) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLabel_), label);
}

_MTL_INLINE void MTL4::CommandBuffer::useResidencySet(const MTL::ResidencySet* residencySet) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(useResidencySet_), residencySet);
}

_MTL_INLINE void MTL4::CommandBuffer::useResidencySets(const MTL::ResidencySet* const residencySets[],
                                                       const NS::UInteger             count) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(useResidencySets_count_), residencySets, count);
}

_MTL_INLINE void MTL4::CommandBuffer::writeTimestampIntoHeap(const CounterHeap* counterHeap,
                                                             const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(writeTimestampIntoHeap_atIndex_), counterHeap, index);
}
