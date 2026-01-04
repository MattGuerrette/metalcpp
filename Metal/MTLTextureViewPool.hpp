//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLTextureViewPool.hpp
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
#include "MTLResourceViewPool.hpp"
#include "MTLTypes.hpp"

namespace MTL
{
    class Buffer;
    class Texture;
    class TextureDescriptor;
    class TextureViewDescriptor;

    /// @see https://developer.apple.com/documentation/metal/mtltextureviewpool?language=objc
    class TextureViewPool : public NS::Referencing<TextureViewPool, ResourceViewPool>
    {
    public:
        [[nodiscard]] ResourceID setTextureView(const Texture* texture, NS::UInteger index) const;
        [[nodiscard]] ResourceID setTextureView(const Texture*               texture,
                                                const TextureViewDescriptor* descriptor,
                                                NS::UInteger                 index) const;
        [[nodiscard]] ResourceID setTextureViewFromBuffer(const Buffer*            buffer,
                                                          const TextureDescriptor* descriptor,
                                                          NS::UInteger             offset,
                                                          NS::UInteger             bytesPerRow,
                                                          NS::UInteger             index) const;
    };

} // namespace MTL
_MTL_INLINE MTL::ResourceID MTL::TextureViewPool::setTextureView(const Texture* texture, const NS::UInteger index) const
{
    return sendMessage<ResourceID>(this, _MTL_PRIVATE_SEL(setTextureView_atIndex_), texture, index);
}

_MTL_INLINE MTL::ResourceID MTL::TextureViewPool::setTextureView(const Texture*               texture,
                                                                 const TextureViewDescriptor* descriptor,
                                                                 const NS::UInteger           index) const
{
    return sendMessage<ResourceID>(
        this, _MTL_PRIVATE_SEL(setTextureView_descriptor_atIndex_), texture, descriptor, index);
}

_MTL_INLINE MTL::ResourceID MTL::TextureViewPool::setTextureViewFromBuffer(const Buffer*            buffer,
                                                                           const TextureDescriptor* descriptor,
                                                                           const NS::UInteger       offset,
                                                                           const NS::UInteger       bytesPerRow,
                                                                           const NS::UInteger       index) const
{
    return sendMessage<ResourceID>(this,
                                   _MTL_PRIVATE_SEL(setTextureViewFromBuffer_descriptor_offset_bytesPerRow_atIndex_),
                                   buffer,
                                   descriptor,
                                   offset,
                                   bytesPerRow,
                                   index);
}
