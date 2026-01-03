//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLComputeCommandEncoder.hpp
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
#include "../Foundation/Foundation.hpp"
#include "MTLCommandBuffer.hpp"
#include "MTLCommandEncoder.hpp"
#include "MTLDefines.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"
#include "MTLTypes.hpp"

namespace MTL
{
    class AccelerationStructure;
    class Buffer;
    class ComputePipelineState;
    class CounterSampleBuffer;
    class Fence;
    class Heap;
    class IndirectCommandBuffer;
    class IntersectionFunctionTable;
    class Resource;
    class SamplerState;
    class Texture;
    class VisibleFunctionTable;

    /// @see https://developer.apple.com/documentation/metal/mtldispatchtype?language=objc
    struct DispatchThreadgroupsIndirectArguments
    {
        uint32_t threadgroupsPerGrid[3];
    } _MTL_PACKED;

    /// @see https://developer.apple.com/documentation/metal/mtldispatchthreadsindirectarguments?language=objc
    struct DispatchThreadsIndirectArguments
    {
        uint32_t threadsPerGrid[3];
        uint32_t threadsPerThreadgroup[3];
    } _MTL_PACKED;

    /// @see https://developer.apple.com/documentation/metal/mtlstageinregionindirectarguments?language=objc
    struct StageInRegionIndirectArguments
    {
        uint32_t stageInOrigin[3];
        uint32_t stageInSize[3];
    } _MTL_PACKED;

    /// @see https://developer.apple.com/documentation/metal/mtlcomputecommandencoder?language=objc
    class ComputeCommandEncoder : public NS::Referencing<ComputeCommandEncoder, CommandEncoder>
    {
    public:
        void dispatchThreadgroups(const Size& threadgroupsPerGrid, const Size& threadsPerThreadgroup) const;
        void dispatchThreadgroups(const Buffer* indirectBuffer,
                                  NS::UInteger  indirectBufferOffset,
                                  const Size&   threadsPerThreadgroup) const;

        void dispatchThreads(const Size& threadsPerGrid, const Size& threadsPerThreadgroup) const;

        [[nodiscard]] DispatchType dispatchType() const;

        void executeCommandsInBuffer(const IndirectCommandBuffer* indirectCommandBuffer,
                                     NS::Range                    executionRange) const;
        void executeCommandsInBuffer(const IndirectCommandBuffer* indirectCommandbuffer,
                                     const Buffer*                indirectRangeBuffer,
                                     NS::UInteger                 indirectBufferOffset) const;

        void memoryBarrier(BarrierScope scope) const;
        void memoryBarrier(const Resource* const resources[], NS::UInteger count) const;

        void sampleCountersInBuffer(const CounterSampleBuffer* sampleBuffer,
                                    NS::UInteger               sampleIndex,
                                    bool                       barrier) const;

        void setAccelerationStructure(const AccelerationStructure* accelerationStructure,
                                      NS::UInteger                 bufferIndex) const;

        void setBuffer(const Buffer* buffer, NS::UInteger offset, NS::UInteger index) const;
        void setBuffer(const Buffer* buffer, NS::UInteger offset, NS::UInteger stride, NS::UInteger index) const;
        void setBufferOffset(NS::UInteger offset, NS::UInteger index) const;
        void setBufferOffset(NS::UInteger offset, NS::UInteger stride, NS::UInteger index) const;

        void setBuffers(const Buffer* const buffers[], const NS::UInteger offsets[], NS::Range range) const;
        void setBuffers(const Buffer* const buffers[],
                        const NS::UInteger* offsets,
                        const NS::UInteger* strides,
                        NS::Range           range) const;

        void setBytes(const void* bytes, NS::UInteger length, NS::UInteger index) const;
        void setBytes(const void* bytes, NS::UInteger length, NS::UInteger stride, NS::UInteger index) const;

        void setComputePipelineState(const ComputePipelineState* state) const;

        void setImageblockWidth(NS::UInteger width, NS::UInteger height) const;

        void setIntersectionFunctionTable(const IntersectionFunctionTable* intersectionFunctionTable,
                                          NS::UInteger                     bufferIndex) const;
        void setIntersectionFunctionTables(const IntersectionFunctionTable* const intersectionFunctionTables[],
                                           NS::Range                              range) const;

        void setSamplerState(const SamplerState* sampler, NS::UInteger index) const;
        void setSamplerState(const SamplerState* sampler,
                             float               lodMinClamp,
                             float               lodMaxClamp,
                             NS::UInteger        index) const;
        void setSamplerStates(const SamplerState* const samplers[], NS::Range range) const;
        void setSamplerStates(const SamplerState* const samplers[],
                              const float               lodMinClamps[],
                              const float               lodMaxClamps[],
                              NS::Range                 range) const;

        void setStageInRegion(const Region& region) const;
        void setStageInRegion(const Buffer* indirectBuffer, NS::UInteger indirectBufferOffset) const;

        void setTexture(const Texture* texture, NS::UInteger index) const;
        void setTextures(const Texture* const textures[], NS::Range range) const;

        void setThreadgroupMemoryLength(NS::UInteger length, NS::UInteger index) const;

        void setVisibleFunctionTable(const VisibleFunctionTable* visibleFunctionTable, NS::UInteger bufferIndex) const;
        void setVisibleFunctionTables(const VisibleFunctionTable* const visibleFunctionTables[], NS::Range range) const;

        void updateFence(const Fence* fence) const;

        void useHeap(const Heap* heap) const;
        void useHeaps(const Heap* const heaps[], NS::UInteger count) const;

        void useResource(const Resource* resource, ResourceUsage usage) const;
        void useResources(const Resource* const resources[], NS::UInteger count, ResourceUsage usage) const;

        void waitForFence(const Fence* fence) const;
    };

} // namespace MTL

_MTL_INLINE void MTL::ComputeCommandEncoder::dispatchThreadgroups(const Size& threadgroupsPerGrid,
                                                                  const Size& threadsPerThreadgroup) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(dispatchThreadgroups_threadsPerThreadgroup_),
                      threadgroupsPerGrid,
                      threadsPerThreadgroup);
}

_MTL_INLINE void MTL::ComputeCommandEncoder::dispatchThreadgroups(const Buffer*      indirectBuffer,
                                                                  const NS::UInteger indirectBufferOffset,
                                                                  const Size&        threadsPerThreadgroup) const
{
    sendMessage<void>(
        this,
        _MTL_PRIVATE_SEL(dispatchThreadgroupsWithIndirectBuffer_indirectBufferOffset_threadsPerThreadgroup_),
        indirectBuffer,
        indirectBufferOffset,
        threadsPerThreadgroup);
}

_MTL_INLINE void MTL::ComputeCommandEncoder::dispatchThreads(const Size& threadsPerGrid,
                                                             const Size& threadsPerThreadgroup) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(dispatchThreads_threadsPerThreadgroup_), threadsPerGrid, threadsPerThreadgroup);
}

_MTL_INLINE MTL::DispatchType MTL::ComputeCommandEncoder::dispatchType() const
{
    return sendMessage<DispatchType>(this, _MTL_PRIVATE_SEL(dispatchType));
}

_MTL_INLINE void MTL::ComputeCommandEncoder::executeCommandsInBuffer(const IndirectCommandBuffer* indirectCommandBuffer,
                                                                     const NS::Range              executionRange) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(executeCommandsInBuffer_withRange_), indirectCommandBuffer, executionRange);
}

_MTL_INLINE void MTL::ComputeCommandEncoder::executeCommandsInBuffer(const IndirectCommandBuffer* indirectCommandbuffer,
                                                                     const Buffer*                indirectRangeBuffer,
                                                                     const NS::UInteger indirectBufferOffset) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(executeCommandsInBuffer_indirectBuffer_indirectBufferOffset_),
                      indirectCommandbuffer,
                      indirectRangeBuffer,
                      indirectBufferOffset);
}

_MTL_INLINE void MTL::ComputeCommandEncoder::memoryBarrier(const BarrierScope scope) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(memoryBarrierWithScope_), scope);
}

_MTL_INLINE void MTL::ComputeCommandEncoder::memoryBarrier(const Resource* const resources[],
                                                           const NS::UInteger    count) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(memoryBarrierWithResources_count_), resources, count);
}

_MTL_INLINE void MTL::ComputeCommandEncoder::sampleCountersInBuffer(const CounterSampleBuffer* sampleBuffer,
                                                                    const NS::UInteger         sampleIndex,
                                                                    const bool                 barrier) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(sampleCountersInBuffer_atSampleIndex_withBarrier_), sampleBuffer, sampleIndex, barrier);
}

_MTL_INLINE void MTL::ComputeCommandEncoder::setAccelerationStructure(
    const AccelerationStructure* accelerationStructure, const NS::UInteger bufferIndex) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setAccelerationStructure_atBufferIndex_), accelerationStructure, bufferIndex);
}

_MTL_INLINE void MTL::ComputeCommandEncoder::setBuffer(const Buffer*      buffer,
                                                       const NS::UInteger offset,
                                                       const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBuffer_offset_atIndex_), buffer, offset, index);
}

_MTL_INLINE void MTL::ComputeCommandEncoder::setBuffer(const Buffer*      buffer,
                                                       const NS::UInteger offset,
                                                       const NS::UInteger stride,
                                                       const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBuffer_offset_attributeStride_atIndex_), buffer, offset, stride, index);
}

_MTL_INLINE void MTL::ComputeCommandEncoder::setBufferOffset(const NS::UInteger offset, const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBufferOffset_atIndex_), offset, index);
}

_MTL_INLINE void MTL::ComputeCommandEncoder::setBufferOffset(const NS::UInteger offset,
                                                             const NS::UInteger stride,
                                                             const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBufferOffset_attributeStride_atIndex_), offset, stride, index);
}

_MTL_INLINE void MTL::ComputeCommandEncoder::setBuffers(const Buffer* const buffers[],
                                                        const NS::UInteger  offsets[],
                                                        const NS::Range     range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBuffers_offsets_withRange_), buffers, offsets, range);
}

_MTL_INLINE void MTL::ComputeCommandEncoder::setBuffers(const Buffer* const buffers[],
                                                        const NS::UInteger* offsets,
                                                        const NS::UInteger* strides,
                                                        const NS::Range     range) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setBuffers_offsets_attributeStrides_withRange_), buffers, offsets, strides, range);
}

_MTL_INLINE void MTL::ComputeCommandEncoder::setBytes(const void*        bytes,
                                                      const NS::UInteger length,
                                                      const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBytes_length_atIndex_), bytes, length, index);
}

_MTL_INLINE void MTL::ComputeCommandEncoder::setBytes(const void*        bytes,
                                                      const NS::UInteger length,
                                                      const NS::UInteger stride,
                                                      const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBytes_length_attributeStride_atIndex_), bytes, length, stride, index);
}

_MTL_INLINE void MTL::ComputeCommandEncoder::setComputePipelineState(const ComputePipelineState* state) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setComputePipelineState_), state);
}

_MTL_INLINE void MTL::ComputeCommandEncoder::setImageblockWidth(const NS::UInteger width,
                                                                const NS::UInteger height) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setImageblockWidth_height_), width, height);
}

_MTL_INLINE void MTL::ComputeCommandEncoder::setIntersectionFunctionTable(
    const IntersectionFunctionTable* intersectionFunctionTable, const NS::UInteger bufferIndex) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setIntersectionFunctionTable_atBufferIndex_), intersectionFunctionTable, bufferIndex);
}

_MTL_INLINE void MTL::ComputeCommandEncoder::setIntersectionFunctionTables(
    const IntersectionFunctionTable* const intersectionFunctionTables[], const NS::Range range) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setIntersectionFunctionTables_withBufferRange_), intersectionFunctionTables, range);
}

_MTL_INLINE void MTL::ComputeCommandEncoder::setSamplerState(const SamplerState* sampler,
                                                             const NS::UInteger  index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSamplerState_atIndex_), sampler, index);
}

_MTL_INLINE void MTL::ComputeCommandEncoder::setSamplerState(const SamplerState* sampler,
                                                             const float         lodMinClamp,
                                                             const float         lodMaxClamp,
                                                             const NS::UInteger  index) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(setSamplerState_lodMinClamp_lodMaxClamp_atIndex_),
                      sampler,
                      lodMinClamp,
                      lodMaxClamp,
                      index);
}

_MTL_INLINE void MTL::ComputeCommandEncoder::setSamplerStates(const SamplerState* const samplers[],
                                                              const NS::Range           range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSamplerStates_withRange_), samplers, range);
}

_MTL_INLINE void MTL::ComputeCommandEncoder::setSamplerStates(const SamplerState* const samplers[],
                                                              const float               lodMinClamps[],
                                                              const float               lodMaxClamps[],
                                                              const NS::Range           range) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(setSamplerStates_lodMinClamps_lodMaxClamps_withRange_),
                      samplers,
                      lodMinClamps,
                      lodMaxClamps,
                      range);
}

_MTL_INLINE void MTL::ComputeCommandEncoder::setStageInRegion(const Region& region) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setStageInRegion_), region);
}

_MTL_INLINE void MTL::ComputeCommandEncoder::setStageInRegion(const Buffer*      indirectBuffer,
                                                              const NS::UInteger indirectBufferOffset) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(setStageInRegionWithIndirectBuffer_indirectBufferOffset_),
                      indirectBuffer,
                      indirectBufferOffset);
}

_MTL_INLINE void MTL::ComputeCommandEncoder::setTexture(const Texture* texture, const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTexture_atIndex_), texture, index);
}

_MTL_INLINE void MTL::ComputeCommandEncoder::setTextures(const Texture* const textures[], const NS::Range range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTextures_withRange_), textures, range);
}

_MTL_INLINE void MTL::ComputeCommandEncoder::setThreadgroupMemoryLength(const NS::UInteger length,
                                                                        const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setThreadgroupMemoryLength_atIndex_), length, index);
}

_MTL_INLINE void MTL::ComputeCommandEncoder::setVisibleFunctionTable(const VisibleFunctionTable* visibleFunctionTable,
                                                                     const NS::UInteger          bufferIndex) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setVisibleFunctionTable_atBufferIndex_), visibleFunctionTable, bufferIndex);
}

_MTL_INLINE void MTL::ComputeCommandEncoder::setVisibleFunctionTables(
    const VisibleFunctionTable* const visibleFunctionTables[], const NS::Range range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVisibleFunctionTables_withBufferRange_), visibleFunctionTables, range);
}

_MTL_INLINE void MTL::ComputeCommandEncoder::updateFence(const Fence* fence) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(updateFence_), fence);
}

_MTL_INLINE void MTL::ComputeCommandEncoder::useHeap(const Heap* heap) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(useHeap_), heap);
}

_MTL_INLINE void MTL::ComputeCommandEncoder::useHeaps(const Heap* const heaps[], const NS::UInteger count) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(useHeaps_count_), heaps, count);
}

_MTL_INLINE void MTL::ComputeCommandEncoder::useResource(const Resource* resource, const ResourceUsage usage) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(useResource_usage_), resource, usage);
}

_MTL_INLINE void MTL::ComputeCommandEncoder::useResources(const Resource* const resources[],
                                                          const NS::UInteger    count,
                                                          const ResourceUsage   usage) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(useResources_count_usage_), resources, count, usage);
}

_MTL_INLINE void MTL::ComputeCommandEncoder::waitForFence(const Fence* fence) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(waitForFence_), fence);
}
