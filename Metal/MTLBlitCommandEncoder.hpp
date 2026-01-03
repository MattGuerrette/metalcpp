//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLBlitCommandEncoder.hpp
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
#include "MTLCommandEncoder.hpp"
#include "MTLDefines.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"
#include "MTLTypes.hpp"

namespace MTL
{
    class Buffer;
    class CounterSampleBuffer;
    class Fence;
    class IndirectCommandBuffer;
    class Resource;
    class Tensor;
    class TensorExtents;
    class Texture;

    _MTL_OPTIONS(NS::UInteger, BlitOption){
        BlitOptionNone                    = 0,
        BlitOptionDepthFromDepthStencil   = 1,
        BlitOptionStencilFromDepthStencil = 1 << 1,
        BlitOptionRowLinearPVRTC          = 1 << 2,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlblitcommandencoder?language=objc
    class BlitCommandEncoder : public NS::Referencing<BlitCommandEncoder, CommandEncoder>
    {
    public:
        void copyFromBuffer(const Buffer*  sourceBuffer,
                            NS::UInteger   sourceOffset,
                            NS::UInteger   sourceBytesPerRow,
                            NS::UInteger   sourceBytesPerImage,
                            const Size&    sourceSize,
                            const Texture* destinationTexture,
                            NS::UInteger   destinationSlice,
                            NS::UInteger   destinationLevel,
                            const Origin&  destinationOrigin) const;
        void copyFromBuffer(const Buffer*  sourceBuffer,
                            NS::UInteger   sourceOffset,
                            NS::UInteger   sourceBytesPerRow,
                            NS::UInteger   sourceBytesPerImage,
                            const Size&    sourceSize,
                            const Texture* destinationTexture,
                            NS::UInteger   destinationSlice,
                            NS::UInteger   destinationLevel,
                            const Origin&  destinationOrigin,
                            BlitOption     options) const;
        void copyFromBuffer(const Buffer* sourceBuffer,
                            NS::UInteger  sourceOffset,
                            const Buffer* destinationBuffer,
                            NS::UInteger  destinationOffset,
                            NS::UInteger  size) const;

        void copyFromTensor(const Tensor*        sourceTensor,
                            const TensorExtents* sourceOrigin,
                            const TensorExtents* sourceDimensions,
                            const Tensor*        destinationTensor,
                            const TensorExtents* destinationOrigin,
                            const TensorExtents* destinationDimensions) const;

        void copyFromTexture(const Texture* sourceTexture,
                             NS::UInteger   sourceSlice,
                             NS::UInteger   sourceLevel,
                             const Origin&  sourceOrigin,
                             const Size&    sourceSize,
                             const Texture* destinationTexture,
                             NS::UInteger   destinationSlice,
                             NS::UInteger   destinationLevel,
                             const Origin&  destinationOrigin) const;
        void copyFromTexture(const Texture* sourceTexture,
                             NS::UInteger   sourceSlice,
                             NS::UInteger   sourceLevel,
                             const Origin&  sourceOrigin,
                             const Size&    sourceSize,
                             const Buffer*  destinationBuffer,
                             NS::UInteger   destinationOffset,
                             NS::UInteger   destinationBytesPerRow,
                             NS::UInteger   destinationBytesPerImage) const;
        void copyFromTexture(const Texture* sourceTexture,
                             NS::UInteger   sourceSlice,
                             NS::UInteger   sourceLevel,
                             const Origin&  sourceOrigin,
                             const Size&    sourceSize,
                             const Buffer*  destinationBuffer,
                             NS::UInteger   destinationOffset,
                             NS::UInteger   destinationBytesPerRow,
                             NS::UInteger   destinationBytesPerImage,
                             BlitOption     options) const;
        void copyFromTexture(const Texture* sourceTexture,
                             NS::UInteger   sourceSlice,
                             NS::UInteger   sourceLevel,
                             const Texture* destinationTexture,
                             NS::UInteger   destinationSlice,
                             NS::UInteger   destinationLevel,
                             NS::UInteger   sliceCount,
                             NS::UInteger   levelCount) const;
        void copyFromTexture(const Texture* sourceTexture, const Texture* destinationTexture) const;

        void copyIndirectCommandBuffer(const IndirectCommandBuffer* source,
                                       NS::Range                    sourceRange,
                                       const IndirectCommandBuffer* destination,
                                       NS::UInteger                 destinationIndex) const;

        void fillBuffer(const Buffer* buffer, NS::Range range, uint8_t value) const;

        void generateMipmaps(const Texture* texture) const;

        void getTextureAccessCounters(const Texture* texture,
                                      const Region&  region,
                                      NS::UInteger   mipLevel,
                                      NS::UInteger   slice,
                                      bool           resetCounters,
                                      const Buffer*  countersBuffer,
                                      NS::UInteger   countersBufferOffset) const;

        void optimizeContentsForCPUAccess(const Texture* texture) const;
        void optimizeContentsForCPUAccess(const Texture* texture, NS::UInteger slice, NS::UInteger level) const;

        void optimizeContentsForGPUAccess(const Texture* texture) const;
        void optimizeContentsForGPUAccess(const Texture* texture, NS::UInteger slice, NS::UInteger level) const;

        void optimizeIndirectCommandBuffer(const IndirectCommandBuffer* indirectCommandBuffer, NS::Range range) const;

        void resetCommandsInBuffer(const IndirectCommandBuffer* buffer, NS::Range range) const;

        void resetTextureAccessCounters(const Texture* texture,
                                        const Region&  region,
                                        NS::UInteger   mipLevel,
                                        NS::UInteger   slice) const;

        void resolveCounters(const CounterSampleBuffer* sampleBuffer,
                             NS::Range                  range,
                             const Buffer*              destinationBuffer,
                             NS::UInteger               destinationOffset) const;

        void sampleCountersInBuffer(const CounterSampleBuffer* sampleBuffer,
                                    NS::UInteger               sampleIndex,
                                    bool                       barrier) const;

        void synchronizeResource(const Resource* resource) const;

        void synchronizeTexture(const Texture* texture, NS::UInteger slice, NS::UInteger level) const;

        void updateFence(const Fence* fence) const;

        void waitForFence(const Fence* fence) const;
    };

} // namespace MTL
_MTL_INLINE void MTL::BlitCommandEncoder::copyFromBuffer(const Buffer*      sourceBuffer,
                                                         const NS::UInteger sourceOffset,
                                                         const NS::UInteger sourceBytesPerRow,
                                                         const NS::UInteger sourceBytesPerImage,
                                                         const Size&        sourceSize,
                                                         const Texture*     destinationTexture,
                                                         const NS::UInteger destinationSlice,
                                                         const NS::UInteger destinationLevel,
                                                         const Origin&      destinationOrigin) const
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

_MTL_INLINE void MTL::BlitCommandEncoder::copyFromBuffer(const Buffer*      sourceBuffer,
                                                         const NS::UInteger sourceOffset,
                                                         const NS::UInteger sourceBytesPerRow,
                                                         const NS::UInteger sourceBytesPerImage,
                                                         const Size&        sourceSize,
                                                         const Texture*     destinationTexture,
                                                         const NS::UInteger destinationSlice,
                                                         const NS::UInteger destinationLevel,
                                                         const Origin&      destinationOrigin,
                                                         const BlitOption   options) const
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

_MTL_INLINE void MTL::BlitCommandEncoder::copyFromBuffer(const Buffer*      sourceBuffer,
                                                         const NS::UInteger sourceOffset,
                                                         const Buffer*      destinationBuffer,
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

_MTL_INLINE void MTL::BlitCommandEncoder::copyFromTensor(const Tensor*        sourceTensor,
                                                         const TensorExtents* sourceOrigin,
                                                         const TensorExtents* sourceDimensions,
                                                         const Tensor*        destinationTensor,
                                                         const TensorExtents* destinationOrigin,
                                                         const TensorExtents* destinationDimensions) const
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

_MTL_INLINE void MTL::BlitCommandEncoder::copyFromTexture(const Texture*     sourceTexture,
                                                          const NS::UInteger sourceSlice,
                                                          const NS::UInteger sourceLevel,
                                                          const Origin&      sourceOrigin,
                                                          const Size&        sourceSize,
                                                          const Texture*     destinationTexture,
                                                          const NS::UInteger destinationSlice,
                                                          const NS::UInteger destinationLevel,
                                                          const Origin&      destinationOrigin) const
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

_MTL_INLINE void MTL::BlitCommandEncoder::copyFromTexture(const Texture*     sourceTexture,
                                                          const NS::UInteger sourceSlice,
                                                          const NS::UInteger sourceLevel,
                                                          const Origin&      sourceOrigin,
                                                          const Size&        sourceSize,
                                                          const Buffer*      destinationBuffer,
                                                          const NS::UInteger destinationOffset,
                                                          const NS::UInteger destinationBytesPerRow,
                                                          const NS::UInteger destinationBytesPerImage) const
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

_MTL_INLINE void MTL::BlitCommandEncoder::copyFromTexture(const Texture*     sourceTexture,
                                                          const NS::UInteger sourceSlice,
                                                          const NS::UInteger sourceLevel,
                                                          const Origin&      sourceOrigin,
                                                          const Size&        sourceSize,
                                                          const Buffer*      destinationBuffer,
                                                          const NS::UInteger destinationOffset,
                                                          const NS::UInteger destinationBytesPerRow,
                                                          const NS::UInteger destinationBytesPerImage,
                                                          const BlitOption   options) const
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

_MTL_INLINE void MTL::BlitCommandEncoder::copyFromTexture(const Texture*     sourceTexture,
                                                          const NS::UInteger sourceSlice,
                                                          const NS::UInteger sourceLevel,
                                                          const Texture*     destinationTexture,
                                                          const NS::UInteger destinationSlice,
                                                          const NS::UInteger destinationLevel,
                                                          const NS::UInteger sliceCount,
                                                          const NS::UInteger levelCount) const
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

_MTL_INLINE void MTL::BlitCommandEncoder::copyFromTexture(const Texture* sourceTexture,
                                                          const Texture* destinationTexture) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(copyFromTexture_toTexture_), sourceTexture, destinationTexture);
}

_MTL_INLINE void MTL::BlitCommandEncoder::copyIndirectCommandBuffer(const IndirectCommandBuffer* source,
                                                                    const NS::Range              sourceRange,
                                                                    const IndirectCommandBuffer* destination,
                                                                    const NS::UInteger           destinationIndex) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(copyIndirectCommandBuffer_sourceRange_destination_destinationIndex_),
                      source,
                      sourceRange,
                      destination,
                      destinationIndex);
}

_MTL_INLINE void MTL::BlitCommandEncoder::fillBuffer(const Buffer*   buffer,
                                                     const NS::Range range,
                                                     const uint8_t   value) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(fillBuffer_range_value_), buffer, range, value);
}

_MTL_INLINE void MTL::BlitCommandEncoder::generateMipmaps(const Texture* texture) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(generateMipmapsForTexture_), texture);
}

_MTL_INLINE void MTL::BlitCommandEncoder::getTextureAccessCounters(const Texture*     texture,
                                                                   const Region&      region,
                                                                   const NS::UInteger mipLevel,
                                                                   const NS::UInteger slice,
                                                                   const bool         resetCounters,
                                                                   const Buffer*      countersBuffer,
                                                                   const NS::UInteger countersBufferOffset) const
{
    sendMessage<void>(
        this,
        _MTL_PRIVATE_SEL(
            getTextureAccessCounters_region_mipLevel_slice_resetCounters_countersBuffer_countersBufferOffset_),
        texture,
        region,
        mipLevel,
        slice,
        resetCounters,
        countersBuffer,
        countersBufferOffset);
}

_MTL_INLINE void MTL::BlitCommandEncoder::optimizeContentsForCPUAccess(const Texture* texture) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(optimizeContentsForCPUAccess_), texture);
}

_MTL_INLINE void MTL::BlitCommandEncoder::optimizeContentsForCPUAccess(const Texture*     texture,
                                                                       const NS::UInteger slice,
                                                                       const NS::UInteger level) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(optimizeContentsForCPUAccess_slice_level_), texture, slice, level);
}

_MTL_INLINE void MTL::BlitCommandEncoder::optimizeContentsForGPUAccess(const Texture* texture) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(optimizeContentsForGPUAccess_), texture);
}

_MTL_INLINE void MTL::BlitCommandEncoder::optimizeContentsForGPUAccess(const Texture*     texture,
                                                                       const NS::UInteger slice,
                                                                       const NS::UInteger level) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(optimizeContentsForGPUAccess_slice_level_), texture, slice, level);
}

_MTL_INLINE void MTL::BlitCommandEncoder::optimizeIndirectCommandBuffer(
    const IndirectCommandBuffer* indirectCommandBuffer, const NS::Range range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(optimizeIndirectCommandBuffer_withRange_), indirectCommandBuffer, range);
}

_MTL_INLINE void MTL::BlitCommandEncoder::resetCommandsInBuffer(const IndirectCommandBuffer* buffer,
                                                                const NS::Range              range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(resetCommandsInBuffer_withRange_), buffer, range);
}

_MTL_INLINE void MTL::BlitCommandEncoder::resetTextureAccessCounters(const Texture*     texture,
                                                                     const Region&      region,
                                                                     const NS::UInteger mipLevel,
                                                                     const NS::UInteger slice) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(resetTextureAccessCounters_region_mipLevel_slice_), texture, region, mipLevel, slice);
}

_MTL_INLINE void MTL::BlitCommandEncoder::resolveCounters(const CounterSampleBuffer* sampleBuffer,
                                                          const NS::Range            range,
                                                          const Buffer*              destinationBuffer,
                                                          const NS::UInteger         destinationOffset) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(resolveCounters_inRange_destinationBuffer_destinationOffset_),
                      sampleBuffer,
                      range,
                      destinationBuffer,
                      destinationOffset);
}

_MTL_INLINE void MTL::BlitCommandEncoder::sampleCountersInBuffer(const CounterSampleBuffer* sampleBuffer,
                                                                 const NS::UInteger         sampleIndex,
                                                                 const bool                 barrier) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(sampleCountersInBuffer_atSampleIndex_withBarrier_), sampleBuffer, sampleIndex, barrier);
}

_MTL_INLINE void MTL::BlitCommandEncoder::synchronizeResource(const Resource* resource) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(synchronizeResource_), resource);
}

_MTL_INLINE void MTL::BlitCommandEncoder::synchronizeTexture(const Texture*     texture,
                                                             const NS::UInteger slice,
                                                             const NS::UInteger level) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(synchronizeTexture_slice_level_), texture, slice, level);
}

_MTL_INLINE void MTL::BlitCommandEncoder::updateFence(const Fence* fence) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(updateFence_), fence);
}

_MTL_INLINE void MTL::BlitCommandEncoder::waitForFence(const Fence* fence) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(waitForFence_), fence);
}
