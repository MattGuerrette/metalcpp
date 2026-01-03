//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTL4ComputeCommandEncoder.hpp
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
#include "MTL4CommandEncoder.hpp"
#include "MTL4Counters.hpp"
#include "MTLAccelerationStructure.hpp"
#include "MTLAccelerationStructureTypes.hpp"
#include "MTLBlitCommandEncoder.hpp"
#include "MTLCommandEncoder.hpp"
#include "MTLDefines.hpp"
#include "MTLGPUAddress.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"
#include "MTLTypes.hpp"

namespace MTL4
{
    class AccelerationStructureDescriptor;
    class ArgumentTable;
    class CounterHeap;
} // namespace MTL4

namespace MTL
{
    class AccelerationStructure;
    class Buffer;
    class ComputePipelineState;
    class IndirectCommandBuffer;
    class Tensor;
    class TensorExtents;
    class Texture;
} // namespace MTL

namespace MTL4
{
    /// @see https://developer.apple.com/documentation/metal/mtl4computecommandencoder
    class ComputeCommandEncoder : public NS::Referencing<ComputeCommandEncoder, CommandEncoder>
    {
    public:
        void buildAccelerationStructure(const MTL::AccelerationStructure*      accelerationStructure,
                                        const AccelerationStructureDescriptor* descriptor,
                                        BufferRange                            scratchBuffer) const;

        void copyAccelerationStructure(const MTL::AccelerationStructure* sourceAccelerationStructure,
                                       const MTL::AccelerationStructure* destinationAccelerationStructure) const;

        void copyAndCompactAccelerationStructure(
            const MTL::AccelerationStructure* sourceAccelerationStructure,
            const MTL::AccelerationStructure* destinationAccelerationStructure) const;

        void copyFromBuffer(const MTL::Buffer* sourceBuffer,
                            NS::UInteger       sourceOffset,
                            const MTL::Buffer* destinationBuffer,
                            NS::UInteger       destinationOffset,
                            NS::UInteger       size) const;
        void copyFromBuffer(const MTL::Buffer*  sourceBuffer,
                            NS::UInteger        sourceOffset,
                            NS::UInteger        sourceBytesPerRow,
                            NS::UInteger        sourceBytesPerImage,
                            const MTL::Size&    sourceSize,
                            const MTL::Texture* destinationTexture,
                            NS::UInteger        destinationSlice,
                            NS::UInteger        destinationLevel,
                            const MTL::Origin&  destinationOrigin) const;
        void copyFromBuffer(const MTL::Buffer*  sourceBuffer,
                            NS::UInteger        sourceOffset,
                            NS::UInteger        sourceBytesPerRow,
                            NS::UInteger        sourceBytesPerImage,
                            const MTL::Size&    sourceSize,
                            const MTL::Texture* destinationTexture,
                            NS::UInteger        destinationSlice,
                            NS::UInteger        destinationLevel,
                            const MTL::Origin&  destinationOrigin,
                            MTL::BlitOption     options) const;

        void copyFromTensor(const MTL::Tensor*        sourceTensor,
                            const MTL::TensorExtents* sourceOrigin,
                            const MTL::TensorExtents* sourceDimensions,
                            const MTL::Tensor*        destinationTensor,
                            const MTL::TensorExtents* destinationOrigin,
                            const MTL::TensorExtents* destinationDimensions) const;

        void copyFromTexture(const MTL::Texture* sourceTexture, const MTL::Texture* destinationTexture) const;
        void copyFromTexture(const MTL::Texture* sourceTexture,
                             NS::UInteger        sourceSlice,
                             NS::UInteger        sourceLevel,
                             const MTL::Texture* destinationTexture,
                             NS::UInteger        destinationSlice,
                             NS::UInteger        destinationLevel,
                             NS::UInteger        sliceCount,
                             NS::UInteger        levelCount) const;
        void copyFromTexture(const MTL::Texture* sourceTexture,
                             NS::UInteger        sourceSlice,
                             NS::UInteger        sourceLevel,
                             const MTL::Origin&  sourceOrigin,
                             const MTL::Size&    sourceSize,
                             const MTL::Texture* destinationTexture,
                             NS::UInteger        destinationSlice,
                             NS::UInteger        destinationLevel,
                             const MTL::Origin&  destinationOrigin) const;
        void copyFromTexture(const MTL::Texture* sourceTexture,
                             NS::UInteger        sourceSlice,
                             NS::UInteger        sourceLevel,
                             const MTL::Origin&  sourceOrigin,
                             const MTL::Size&    sourceSize,
                             const MTL::Buffer*  destinationBuffer,
                             NS::UInteger        destinationOffset,
                             NS::UInteger        destinationBytesPerRow,
                             NS::UInteger        destinationBytesPerImage) const;
        void copyFromTexture(const MTL::Texture* sourceTexture,
                             NS::UInteger        sourceSlice,
                             NS::UInteger        sourceLevel,
                             const MTL::Origin&  sourceOrigin,
                             const MTL::Size&    sourceSize,
                             const MTL::Buffer*  destinationBuffer,
                             NS::UInteger        destinationOffset,
                             NS::UInteger        destinationBytesPerRow,
                             NS::UInteger        destinationBytesPerImage,
                             MTL::BlitOption     options) const;

        void copyIndirectCommandBuffer(const MTL::IndirectCommandBuffer* source,
                                       NS::Range                         sourceRange,
                                       const MTL::IndirectCommandBuffer* destination,
                                       NS::UInteger                      destinationIndex) const;

        void dispatchThreadgroups(const MTL::Size& threadgroupsPerGrid, const MTL::Size& threadsPerThreadgroup) const;
        void dispatchThreadgroups(MTL::GPUAddress indirectBuffer, const MTL::Size& threadsPerThreadgroup) const;

        void dispatchThreads(const MTL::Size& threadsPerGrid, const MTL::Size& threadsPerThreadgroup) const;
        void dispatchThreads(MTL::GPUAddress indirectBuffer) const;

        void executeCommandsInBuffer(const MTL::IndirectCommandBuffer* indirectCommandBuffer,
                                     NS::Range                         executionRange) const;
        void executeCommandsInBuffer(const MTL::IndirectCommandBuffer* indirectCommandbuffer,
                                     MTL::GPUAddress                   indirectRangeBuffer) const;

        void fillBuffer(const MTL::Buffer* buffer, NS::Range range, uint8_t value) const;

        void generateMipmaps(const MTL::Texture* texture) const;

        void optimizeContentsForCPUAccess(const MTL::Texture* texture) const;
        void optimizeContentsForCPUAccess(const MTL::Texture* texture, NS::UInteger slice, NS::UInteger level) const;

        void optimizeContentsForGPUAccess(const MTL::Texture* texture) const;
        void optimizeContentsForGPUAccess(const MTL::Texture* texture, NS::UInteger slice, NS::UInteger level) const;

        void optimizeIndirectCommandBuffer(const MTL::IndirectCommandBuffer* indirectCommandBuffer,
                                           NS::Range                         range) const;

        void refitAccelerationStructure(const MTL::AccelerationStructure*      sourceAccelerationStructure,
                                        const AccelerationStructureDescriptor* descriptor,
                                        const MTL::AccelerationStructure*      destinationAccelerationStructure,
                                        BufferRange                            scratchBuffer) const;
        void refitAccelerationStructure(const MTL::AccelerationStructure*      sourceAccelerationStructure,
                                        const AccelerationStructureDescriptor* descriptor,
                                        const MTL::AccelerationStructure*      destinationAccelerationStructure,
                                        BufferRange                            scratchBuffer,
                                        MTL::AccelerationStructureRefitOptions options) const;

        void resetCommandsInBuffer(const MTL::IndirectCommandBuffer* buffer, NS::Range range) const;

        void setArgumentTable(const ArgumentTable* argumentTable) const;

        void setComputePipelineState(const MTL::ComputePipelineState* state) const;

        void setImageblockWidth(NS::UInteger width, NS::UInteger height) const;

        void setThreadgroupMemoryLength(NS::UInteger length, NS::UInteger index) const;

        [[nodiscard]] MTL::Stages stages() const;

        void writeCompactedAccelerationStructureSize(const MTL::AccelerationStructure* accelerationStructure,
                                                     BufferRange                       buffer) const;

        void writeTimestamp(TimestampGranularity granularity, const CounterHeap* counterHeap, NS::UInteger index) const;
    };

} // namespace MTL4
_MTL_INLINE void MTL4::ComputeCommandEncoder::buildAccelerationStructure(
    const MTL::AccelerationStructure*      accelerationStructure,
    const AccelerationStructureDescriptor* descriptor,
    const BufferRange                      scratchBuffer) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(buildAccelerationStructure_descriptor_scratchBuffer_),
                      accelerationStructure,
                      descriptor,
                      scratchBuffer);
}

_MTL_INLINE void MTL4::ComputeCommandEncoder::copyAccelerationStructure(
    const MTL::AccelerationStructure* sourceAccelerationStructure,
    const MTL::AccelerationStructure* destinationAccelerationStructure) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(copyAccelerationStructure_toAccelerationStructure_),
                      sourceAccelerationStructure,
                      destinationAccelerationStructure);
}

_MTL_INLINE void MTL4::ComputeCommandEncoder::copyAndCompactAccelerationStructure(
    const MTL::AccelerationStructure* sourceAccelerationStructure,
    const MTL::AccelerationStructure* destinationAccelerationStructure) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(copyAndCompactAccelerationStructure_toAccelerationStructure_),
                      sourceAccelerationStructure,
                      destinationAccelerationStructure);
}

_MTL_INLINE void MTL4::ComputeCommandEncoder::copyFromBuffer(const MTL::Buffer* sourceBuffer,
                                                             const NS::UInteger sourceOffset,
                                                             const MTL::Buffer* destinationBuffer,
                                                             const NS::UInteger destinationOffset,
                                                             const NS::UInteger size) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(copyFromBuffer_sourceOffset_toBuffer_destinationOffset_size_),
                      sourceBuffer,
                      sourceOffset,
                      destinationBuffer,
                      destinationOffset,
                      size);
}

_MTL_INLINE void MTL4::ComputeCommandEncoder::copyFromBuffer(const MTL::Buffer*  sourceBuffer,
                                                             const NS::UInteger  sourceOffset,
                                                             const NS::UInteger  sourceBytesPerRow,
                                                             const NS::UInteger  sourceBytesPerImage,
                                                             const MTL::Size&    sourceSize,
                                                             const MTL::Texture* destinationTexture,
                                                             const NS::UInteger  destinationSlice,
                                                             const NS::UInteger  destinationLevel,
                                                             const MTL::Origin&  destinationOrigin) const
{
    sendMessage<void>(
        this,
        _MTL_PRIVATE_SEL(
            copyFromBuffer_sourceOffset_sourceBytesPerRow_sourceBytesPerImage_sourceSize_toTexture_destinationSlice_destinationLevel_destinationOrigin_),
        sourceBuffer,
        sourceOffset,
        sourceBytesPerRow,
        sourceBytesPerImage,
        sourceSize,
        destinationTexture,
        destinationSlice,
        destinationLevel,
        destinationOrigin);
}

_MTL_INLINE void MTL4::ComputeCommandEncoder::copyFromBuffer(const MTL::Buffer*    sourceBuffer,
                                                             const NS::UInteger    sourceOffset,
                                                             const NS::UInteger    sourceBytesPerRow,
                                                             const NS::UInteger    sourceBytesPerImage,
                                                             const MTL::Size&      sourceSize,
                                                             const MTL::Texture*   destinationTexture,
                                                             const NS::UInteger    destinationSlice,
                                                             const NS::UInteger    destinationLevel,
                                                             const MTL::Origin&    destinationOrigin,
                                                             const MTL::BlitOption options) const
{
    sendMessage<void>(
        this,
        _MTL_PRIVATE_SEL(
            copyFromBuffer_sourceOffset_sourceBytesPerRow_sourceBytesPerImage_sourceSize_toTexture_destinationSlice_destinationLevel_destinationOrigin_options_),
        sourceBuffer,
        sourceOffset,
        sourceBytesPerRow,
        sourceBytesPerImage,
        sourceSize,
        destinationTexture,
        destinationSlice,
        destinationLevel,
        destinationOrigin,
        options);
}

_MTL_INLINE void MTL4::ComputeCommandEncoder::copyFromTensor(const MTL::Tensor*        sourceTensor,
                                                             const MTL::TensorExtents* sourceOrigin,
                                                             const MTL::TensorExtents* sourceDimensions,
                                                             const MTL::Tensor*        destinationTensor,
                                                             const MTL::TensorExtents* destinationOrigin,
                                                             const MTL::TensorExtents* destinationDimensions) const
{
    sendMessage<void>(
        this,
        _MTL_PRIVATE_SEL(
            copyFromTensor_sourceOrigin_sourceDimensions_toTensor_destinationOrigin_destinationDimensions_),
        sourceTensor,
        sourceOrigin,
        sourceDimensions,
        destinationTensor,
        destinationOrigin,
        destinationDimensions);
}

_MTL_INLINE void MTL4::ComputeCommandEncoder::copyFromTexture(const MTL::Texture* sourceTexture,
                                                              const MTL::Texture* destinationTexture) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(copyFromTexture_toTexture_), sourceTexture, destinationTexture);
}

_MTL_INLINE void MTL4::ComputeCommandEncoder::copyFromTexture(const MTL::Texture* sourceTexture,
                                                              const NS::UInteger  sourceSlice,
                                                              const NS::UInteger  sourceLevel,
                                                              const MTL::Texture* destinationTexture,
                                                              const NS::UInteger  destinationSlice,
                                                              const NS::UInteger  destinationLevel,
                                                              const NS::UInteger  sliceCount,
                                                              const NS::UInteger  levelCount) const
{
    sendMessage<void>(
        this,
        _MTL_PRIVATE_SEL(
            copyFromTexture_sourceSlice_sourceLevel_toTexture_destinationSlice_destinationLevel_sliceCount_levelCount_),
        sourceTexture,
        sourceSlice,
        sourceLevel,
        destinationTexture,
        destinationSlice,
        destinationLevel,
        sliceCount,
        levelCount);
}

_MTL_INLINE void MTL4::ComputeCommandEncoder::copyFromTexture(const MTL::Texture* sourceTexture,
                                                              const NS::UInteger  sourceSlice,
                                                              const NS::UInteger  sourceLevel,
                                                              const MTL::Origin&  sourceOrigin,
                                                              const MTL::Size&    sourceSize,
                                                              const MTL::Texture* destinationTexture,
                                                              const NS::UInteger  destinationSlice,
                                                              const NS::UInteger  destinationLevel,
                                                              const MTL::Origin&  destinationOrigin) const
{
    sendMessage<void>(
        this,
        _MTL_PRIVATE_SEL(
            copyFromTexture_sourceSlice_sourceLevel_sourceOrigin_sourceSize_toTexture_destinationSlice_destinationLevel_destinationOrigin_),
        sourceTexture,
        sourceSlice,
        sourceLevel,
        sourceOrigin,
        sourceSize,
        destinationTexture,
        destinationSlice,
        destinationLevel,
        destinationOrigin);
}

_MTL_INLINE void MTL4::ComputeCommandEncoder::copyFromTexture(const MTL::Texture* sourceTexture,
                                                              const NS::UInteger  sourceSlice,
                                                              const NS::UInteger  sourceLevel,
                                                              const MTL::Origin&  sourceOrigin,
                                                              const MTL::Size&    sourceSize,
                                                              const MTL::Buffer*  destinationBuffer,
                                                              const NS::UInteger  destinationOffset,
                                                              const NS::UInteger  destinationBytesPerRow,
                                                              const NS::UInteger  destinationBytesPerImage) const
{
    sendMessage<void>(
        this,
        _MTL_PRIVATE_SEL(
            copyFromTexture_sourceSlice_sourceLevel_sourceOrigin_sourceSize_toBuffer_destinationOffset_destinationBytesPerRow_destinationBytesPerImage_),
        sourceTexture,
        sourceSlice,
        sourceLevel,
        sourceOrigin,
        sourceSize,
        destinationBuffer,
        destinationOffset,
        destinationBytesPerRow,
        destinationBytesPerImage);
}

_MTL_INLINE void MTL4::ComputeCommandEncoder::copyFromTexture(const MTL::Texture*   sourceTexture,
                                                              const NS::UInteger    sourceSlice,
                                                              const NS::UInteger    sourceLevel,
                                                              const MTL::Origin&    sourceOrigin,
                                                              const MTL::Size&      sourceSize,
                                                              const MTL::Buffer*    destinationBuffer,
                                                              const NS::UInteger    destinationOffset,
                                                              const NS::UInteger    destinationBytesPerRow,
                                                              const NS::UInteger    destinationBytesPerImage,
                                                              const MTL::BlitOption options) const
{
    sendMessage<void>(
        this,
        _MTL_PRIVATE_SEL(
            copyFromTexture_sourceSlice_sourceLevel_sourceOrigin_sourceSize_toBuffer_destinationOffset_destinationBytesPerRow_destinationBytesPerImage_options_),
        sourceTexture,
        sourceSlice,
        sourceLevel,
        sourceOrigin,
        sourceSize,
        destinationBuffer,
        destinationOffset,
        destinationBytesPerRow,
        destinationBytesPerImage,
        options);
}

_MTL_INLINE void MTL4::ComputeCommandEncoder::copyIndirectCommandBuffer(const MTL::IndirectCommandBuffer* source,
                                                                        const NS::Range                   sourceRange,
                                                                        const MTL::IndirectCommandBuffer* destination,
                                                                        const NS::UInteger destinationIndex) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(copyIndirectCommandBuffer_sourceRange_destination_destinationIndex_),
                      source,
                      sourceRange,
                      destination,
                      destinationIndex);
}

_MTL_INLINE void MTL4::ComputeCommandEncoder::dispatchThreadgroups(const MTL::Size& threadgroupsPerGrid,
                                                                   const MTL::Size& threadsPerThreadgroup) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(dispatchThreadgroups_threadsPerThreadgroup_),
                      threadgroupsPerGrid,
                      threadsPerThreadgroup);
}

_MTL_INLINE void MTL4::ComputeCommandEncoder::dispatchThreadgroups(const MTL::GPUAddress indirectBuffer,
                                                                   const MTL::Size&      threadsPerThreadgroup) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(dispatchThreadgroupsWithIndirectBuffer_threadsPerThreadgroup_),
                      indirectBuffer,
                      threadsPerThreadgroup);
}

_MTL_INLINE void MTL4::ComputeCommandEncoder::dispatchThreads(const MTL::Size& threadsPerGrid,
                                                              const MTL::Size& threadsPerThreadgroup) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(dispatchThreads_threadsPerThreadgroup_), threadsPerGrid, threadsPerThreadgroup);
}

_MTL_INLINE void MTL4::ComputeCommandEncoder::dispatchThreads(const MTL::GPUAddress indirectBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(dispatchThreadsWithIndirectBuffer_), indirectBuffer);
}

_MTL_INLINE void MTL4::ComputeCommandEncoder::executeCommandsInBuffer(
    const MTL::IndirectCommandBuffer* indirectCommandBuffer, const NS::Range executionRange) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(executeCommandsInBuffer_withRange_), indirectCommandBuffer, executionRange);
}

_MTL_INLINE void MTL4::ComputeCommandEncoder::executeCommandsInBuffer(
    const MTL::IndirectCommandBuffer* indirectCommandbuffer, const MTL::GPUAddress indirectRangeBuffer) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(executeCommandsInBuffer_indirectBuffer_), indirectCommandbuffer, indirectRangeBuffer);
}

_MTL_INLINE void MTL4::ComputeCommandEncoder::fillBuffer(const MTL::Buffer* buffer,
                                                         const NS::Range    range,
                                                         const uint8_t      value) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(fillBuffer_range_value_), buffer, range, value);
}

_MTL_INLINE void MTL4::ComputeCommandEncoder::generateMipmaps(const MTL::Texture* texture) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(generateMipmapsForTexture_), texture);
}

_MTL_INLINE void MTL4::ComputeCommandEncoder::optimizeContentsForCPUAccess(const MTL::Texture* texture) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(optimizeContentsForCPUAccess_), texture);
}

_MTL_INLINE void MTL4::ComputeCommandEncoder::optimizeContentsForCPUAccess(const MTL::Texture* texture,
                                                                           const NS::UInteger  slice,
                                                                           const NS::UInteger  level) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(optimizeContentsForCPUAccess_slice_level_), texture, slice, level);
}

_MTL_INLINE void MTL4::ComputeCommandEncoder::optimizeContentsForGPUAccess(const MTL::Texture* texture) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(optimizeContentsForGPUAccess_), texture);
}

_MTL_INLINE void MTL4::ComputeCommandEncoder::optimizeContentsForGPUAccess(const MTL::Texture* texture,
                                                                           const NS::UInteger  slice,
                                                                           const NS::UInteger  level) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(optimizeContentsForGPUAccess_slice_level_), texture, slice, level);
}

_MTL_INLINE void MTL4::ComputeCommandEncoder::optimizeIndirectCommandBuffer(
    const MTL::IndirectCommandBuffer* indirectCommandBuffer, const NS::Range range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(optimizeIndirectCommandBuffer_withRange_), indirectCommandBuffer, range);
}

_MTL_INLINE void MTL4::ComputeCommandEncoder::refitAccelerationStructure(
    const MTL::AccelerationStructure*      sourceAccelerationStructure,
    const AccelerationStructureDescriptor* descriptor,
    const MTL::AccelerationStructure*      destinationAccelerationStructure,
    const BufferRange                      scratchBuffer) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(refitAccelerationStructure_descriptor_destination_scratchBuffer_),
                      sourceAccelerationStructure,
                      descriptor,
                      destinationAccelerationStructure,
                      scratchBuffer);
}

_MTL_INLINE void MTL4::ComputeCommandEncoder::refitAccelerationStructure(
    const MTL::AccelerationStructure*            sourceAccelerationStructure,
    const AccelerationStructureDescriptor*       descriptor,
    const MTL::AccelerationStructure*            destinationAccelerationStructure,
    const BufferRange                            scratchBuffer,
    const MTL::AccelerationStructureRefitOptions options) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(refitAccelerationStructure_descriptor_destination_scratchBuffer_options_),
                      sourceAccelerationStructure,
                      descriptor,
                      destinationAccelerationStructure,
                      scratchBuffer,
                      options);
}

_MTL_INLINE void MTL4::ComputeCommandEncoder::resetCommandsInBuffer(const MTL::IndirectCommandBuffer* buffer,
                                                                    const NS::Range                   range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(resetCommandsInBuffer_withRange_), buffer, range);
}

_MTL_INLINE void MTL4::ComputeCommandEncoder::setArgumentTable(const ArgumentTable* argumentTable) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setArgumentTable_), argumentTable);
}

_MTL_INLINE void MTL4::ComputeCommandEncoder::setComputePipelineState(const MTL::ComputePipelineState* state) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setComputePipelineState_), state);
}

_MTL_INLINE void MTL4::ComputeCommandEncoder::setImageblockWidth(const NS::UInteger width,
                                                                 const NS::UInteger height) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setImageblockWidth_height_), width, height);
}

_MTL_INLINE void MTL4::ComputeCommandEncoder::setThreadgroupMemoryLength(const NS::UInteger length,
                                                                         const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setThreadgroupMemoryLength_atIndex_), length, index);
}

_MTL_INLINE MTL::Stages MTL4::ComputeCommandEncoder::stages() const
{
    return sendMessage<MTL::Stages>(this, _MTL_PRIVATE_SEL(stages));
}

_MTL_INLINE void MTL4::ComputeCommandEncoder::writeCompactedAccelerationStructureSize(
    const MTL::AccelerationStructure* accelerationStructure, const BufferRange buffer) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(writeCompactedAccelerationStructureSize_toBuffer_), accelerationStructure, buffer);
}

_MTL_INLINE void MTL4::ComputeCommandEncoder::writeTimestamp(const TimestampGranularity granularity,
                                                             const CounterHeap*         counterHeap,
                                                             const NS::UInteger         index) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(writeTimestampWithGranularity_intoHeap_atIndex_), granularity, counterHeap, index);
}
