//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLBuffer.hpp
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
#include "MTLGPUAddress.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"
#include "MTLResource.hpp"

namespace MTL
{
    class Buffer;
    class Device;
    class Tensor;
    class TensorDescriptor;
    class Texture;
    class TextureDescriptor;

    /// @see https://developer.apple.com/documentation/metal/mtlbuffer?language=objc
    class Buffer : public NS::Referencing<Buffer, Resource>
    {
    public:
        [[nodiscard]] void* contents() const;

        [[nodiscard]] GPUAddress gpuAddress() const;

        [[nodiscard]] NS::UInteger length() const;

        [[nodiscard]] Buffer* newRemoteBufferViewForDevice(const Device* device) const;

        [[nodiscard]] Tensor* newTensor(const TensorDescriptor* descriptor,
                                        NS::UInteger            offset,
                                        NS::Error**             error) const;

        [[nodiscard]] Texture* newTexture(const TextureDescriptor* descriptor,
                                          NS::UInteger             offset,
                                          NS::UInteger             bytesPerRow) const;

        [[nodiscard]] Buffer* remoteStorageBuffer() const;

        [[nodiscard]] BufferSparseTier sparseBufferTier() const;

        void removeAllDebugMarkers() const;

        void didModifyRange(NS::Range range) const;

        void addDebugMarker(const NS::String* marker, NS::Range range) const;
    };

} // namespace MTL
_MTL_INLINE void MTL::Buffer::addDebugMarker(const NS::String* marker, const NS::Range range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(addDebugMarker_range_), marker, range);
}

_MTL_INLINE void* MTL::Buffer::contents() const { return sendMessage<void*>(this, _MTL_PRIVATE_SEL(contents)); }

_MTL_INLINE void MTL::Buffer::didModifyRange(const NS::Range range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(didModifyRange_), range);
}

_MTL_INLINE MTL::GPUAddress MTL::Buffer::gpuAddress() const
{
    return sendMessage<GPUAddress>(this, _MTL_PRIVATE_SEL(gpuAddress));
}

_MTL_INLINE NS::UInteger MTL::Buffer::length() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(length));
}

_MTL_INLINE MTL::Buffer* MTL::Buffer::newRemoteBufferViewForDevice(const Device* device) const
{
    return sendMessage<Buffer*>(this, _MTL_PRIVATE_SEL(newRemoteBufferViewForDevice_), device);
}

_MTL_INLINE MTL::Tensor* MTL::Buffer::newTensor(const TensorDescriptor* descriptor,
                                                const NS::UInteger      offset,
                                                NS::Error**             error) const
{
    return sendMessage<Tensor*>(
        this, _MTL_PRIVATE_SEL(newTensorWithDescriptor_offset_error_), descriptor, offset, error);
}

_MTL_INLINE MTL::Texture* MTL::Buffer::newTexture(const TextureDescriptor* descriptor,
                                                  const NS::UInteger       offset,
                                                  const NS::UInteger       bytesPerRow) const
{
    return sendMessage<Texture*>(
        this, _MTL_PRIVATE_SEL(newTextureWithDescriptor_offset_bytesPerRow_), descriptor, offset, bytesPerRow);
}

_MTL_INLINE MTL::Buffer* MTL::Buffer::remoteStorageBuffer() const
{
    return sendMessage<Buffer*>(this, _MTL_PRIVATE_SEL(remoteStorageBuffer));
}

_MTL_INLINE void MTL::Buffer::removeAllDebugMarkers() const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(removeAllDebugMarkers));
}

_MTL_INLINE MTL::BufferSparseTier MTL::Buffer::sparseBufferTier() const
{
    return sendMessage<BufferSparseTier>(this, _MTL_PRIVATE_SEL(sparseBufferTier));
}
