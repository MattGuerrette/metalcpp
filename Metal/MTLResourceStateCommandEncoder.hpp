//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLResourceStateCommandEncoder.hpp
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
    class Fence;
    struct Region;
    class Texture;

    /// @see https://developer.apple.com/documentation/metal/mtlsparsetexturemappingmode?language=objc
    _MTL_ENUM(NS::UInteger, SparseTextureMappingMode){
        SparseTextureMappingModeMap   = 0,
        SparseTextureMappingModeUnmap = 1,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlmapindirectarguments?language=objc
    struct MapIndirectArguments
    {
        uint32_t regionOriginX;
        uint32_t regionOriginY;
        uint32_t regionOriginZ;
        uint32_t regionSizeWidth;
        uint32_t regionSizeHeight;
        uint32_t regionSizeDepth;
        uint32_t mipMapLevel;
        uint32_t sliceId;
    } _MTL_PACKED;

    /// @see https://developer.apple.com/documentation/metal/mtlresourcestatecommandencoder?language=objc
    class ResourceStateCommandEncoder : public NS::Referencing<ResourceStateCommandEncoder, CommandEncoder>
    {
    public:
        void moveTextureMappingsFromTexture(const Texture* sourceTexture,
                                            NS::UInteger   sourceSlice,
                                            NS::UInteger   sourceLevel,
                                            const Origin&  sourceOrigin,
                                            const Size&    sourceSize,
                                            const Texture* destinationTexture,
                                            NS::UInteger   destinationSlice,
                                            NS::UInteger   destinationLevel,
                                            const Origin&  destinationOrigin) const;

        void updateFence(const Fence* fence) const;

        void updateTextureMapping(const Texture*           texture,
                                  SparseTextureMappingMode mode,
                                  const Region&            region,
                                  NS::UInteger             mipLevel,
                                  NS::UInteger             slice) const;
        void updateTextureMapping(const Texture*           texture,
                                  SparseTextureMappingMode mode,
                                  const Buffer*            indirectBuffer,
                                  NS::UInteger             indirectBufferOffset) const;
        void updateTextureMappings(const Texture*           texture,
                                   SparseTextureMappingMode mode,
                                   const Region*            regions,
                                   const NS::UInteger*      mipLevels,
                                   const NS::UInteger*      slices,
                                   NS::UInteger             numRegions) const;

        void waitForFence(const Fence* fence) const;
    };

} // namespace MTL

_MTL_INLINE void MTL::ResourceStateCommandEncoder::moveTextureMappingsFromTexture(const Texture*     sourceTexture,
                                                                                  const NS::UInteger sourceSlice,
                                                                                  const NS::UInteger sourceLevel,
                                                                                  const Origin&      sourceOrigin,
                                                                                  const Size&        sourceSize,
                                                                                  const Texture*     destinationTexture,
                                                                                  const NS::UInteger destinationSlice,
                                                                                  const NS::UInteger destinationLevel,
                                                                                  const Origin& destinationOrigin) const
{
    sendMessage<void>(
        this,
        _MTL_PRIVATE_SEL(
            moveTextureMappingsFromTexture_sourceSlice_sourceLevel_sourceOrigin_sourceSize_toTexture_destinationSlice_destinationLevel_destinationOrigin_),
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

_MTL_INLINE void MTL::ResourceStateCommandEncoder::updateFence(const Fence* fence) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(updateFence_), fence);
}

_MTL_INLINE void MTL::ResourceStateCommandEncoder::updateTextureMapping(const Texture*                 texture,
                                                                        const SparseTextureMappingMode mode,
                                                                        const Region&                  region,
                                                                        const NS::UInteger             mipLevel,
                                                                        const NS::UInteger             slice) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(updateTextureMapping_mode_region_mipLevel_slice_),
                      texture,
                      mode,
                      region,
                      mipLevel,
                      slice);
}

_MTL_INLINE void MTL::ResourceStateCommandEncoder::updateTextureMapping(const Texture*                 texture,
                                                                        const SparseTextureMappingMode mode,
                                                                        const Buffer*                  indirectBuffer,
                                                                        const NS::UInteger indirectBufferOffset) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(updateTextureMapping_mode_indirectBuffer_indirectBufferOffset_),
                      texture,
                      mode,
                      indirectBuffer,
                      indirectBufferOffset);
}

_MTL_INLINE void MTL::ResourceStateCommandEncoder::updateTextureMappings(const Texture*                 texture,
                                                                         const SparseTextureMappingMode mode,
                                                                         const Region*                  regions,
                                                                         const NS::UInteger*            mipLevels,
                                                                         const NS::UInteger*            slices,
                                                                         const NS::UInteger numRegions) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(updateTextureMappings_mode_regions_mipLevels_slices_numRegions_),
                      texture,
                      mode,
                      regions,
                      mipLevels,
                      slices,
                      numRegions);
}

_MTL_INLINE void MTL::ResourceStateCommandEncoder::waitForFence(const Fence* fence) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(waitForFence_), fence);
}
