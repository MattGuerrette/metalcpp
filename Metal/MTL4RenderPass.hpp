//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTL4RenderPass.hpp
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
#include "MTLRenderPass.hpp"

namespace MTL4
{
    class RenderPassDescriptor;
}

namespace MTL
{
    class Buffer;
    class RasterizationRateMap;
    class RenderPassColorAttachmentDescriptorArray;
    class RenderPassDepthAttachmentDescriptor;
    class RenderPassStencilAttachmentDescriptor;
    struct SamplePosition;
} // namespace MTL

namespace MTL4
{
    /// @see https://developer.apple.com/documentation/metal/mtl4renderpassdescriptor
    class RenderPassDescriptor : public NS::Copying<RenderPassDescriptor>
    {
    public:
        [[nodiscard]] static RenderPassDescriptor* alloc();

        [[nodiscard]] MTL::RenderPassColorAttachmentDescriptorArray* colorAttachments() const;

        [[nodiscard]] NS::UInteger defaultRasterSampleCount() const;

        [[nodiscard]] MTL::RenderPassDepthAttachmentDescriptor* depthAttachment() const;

        [[nodiscard]] NS::UInteger getSamplePositions(MTL::SamplePosition* positions, NS::UInteger count) const;

        [[nodiscard]] NS::UInteger imageblockSampleLength() const;

        [[nodiscard]] RenderPassDescriptor* init();

        [[nodiscard]] MTL::RasterizationRateMap* rasterizationRateMap() const;

        [[nodiscard]] NS::UInteger renderTargetArrayLength() const;

        [[nodiscard]] NS::UInteger renderTargetHeight() const;

        [[nodiscard]] NS::UInteger renderTargetWidth() const;

        [[nodiscard]] MTL::RenderPassStencilAttachmentDescriptor* stencilAttachment() const;

        [[nodiscard]] bool supportColorAttachmentMapping() const;

        [[nodiscard]] NS::UInteger threadgroupMemoryLength() const;

        [[nodiscard]] NS::UInteger tileHeight() const;

        [[nodiscard]] NS::UInteger tileWidth() const;

        [[nodiscard]] MTL::Buffer* visibilityResultBuffer() const;

        [[nodiscard]] MTL::VisibilityResultType visibilityResultType() const;

        void setDefaultRasterSampleCount(NS::UInteger defaultRasterSampleCount) const;

        void setDepthAttachment(const MTL::RenderPassDepthAttachmentDescriptor* depthAttachment) const;

        void setImageblockSampleLength(NS::UInteger imageblockSampleLength) const;

        void setRasterizationRateMap(const MTL::RasterizationRateMap* rasterizationRateMap) const;

        void setRenderTargetArrayLength(NS::UInteger renderTargetArrayLength) const;

        void setRenderTargetHeight(NS::UInteger renderTargetHeight) const;

        void setRenderTargetWidth(NS::UInteger renderTargetWidth) const;

        void setSamplePositions(const MTL::SamplePosition* positions, NS::UInteger count) const;

        void setStencilAttachment(const MTL::RenderPassStencilAttachmentDescriptor* stencilAttachment) const;

        void setSupportColorAttachmentMapping(bool supportColorAttachmentMapping) const;

        void setThreadgroupMemoryLength(NS::UInteger threadgroupMemoryLength) const;

        void setTileHeight(NS::UInteger tileHeight) const;

        void setTileWidth(NS::UInteger tileWidth) const;

        void setVisibilityResultBuffer(const MTL::Buffer* visibilityResultBuffer) const;

        void setVisibilityResultType(MTL::VisibilityResultType visibilityResultType) const;
    };

} // namespace MTL4
_MTL_INLINE MTL4::RenderPassDescriptor* MTL4::RenderPassDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<RenderPassDescriptor>(_MTL_PRIVATE_CLS(MTL4RenderPassDescriptor));
}

_MTL_INLINE MTL::RenderPassColorAttachmentDescriptorArray* MTL4::RenderPassDescriptor::colorAttachments() const
{
    return sendMessage<MTL::RenderPassColorAttachmentDescriptorArray*>(this, _MTL_PRIVATE_SEL(colorAttachments));
}

_MTL_INLINE NS::UInteger MTL4::RenderPassDescriptor::defaultRasterSampleCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(defaultRasterSampleCount));
}

_MTL_INLINE MTL::RenderPassDepthAttachmentDescriptor* MTL4::RenderPassDescriptor::depthAttachment() const
{
    return sendMessage<MTL::RenderPassDepthAttachmentDescriptor*>(this, _MTL_PRIVATE_SEL(depthAttachment));
}

_MTL_INLINE NS::UInteger MTL4::RenderPassDescriptor::getSamplePositions(MTL::SamplePosition* positions,
                                                                        const NS::UInteger   count) const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(getSamplePositions_count_), positions, count);
}

_MTL_INLINE NS::UInteger MTL4::RenderPassDescriptor::imageblockSampleLength() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(imageblockSampleLength));
}

_MTL_INLINE MTL4::RenderPassDescriptor* MTL4::RenderPassDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<RenderPassDescriptor>();
}

_MTL_INLINE MTL::RasterizationRateMap* MTL4::RenderPassDescriptor::rasterizationRateMap() const
{
    return sendMessage<MTL::RasterizationRateMap*>(this, _MTL_PRIVATE_SEL(rasterizationRateMap));
}

_MTL_INLINE NS::UInteger MTL4::RenderPassDescriptor::renderTargetArrayLength() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(renderTargetArrayLength));
}

_MTL_INLINE NS::UInteger MTL4::RenderPassDescriptor::renderTargetHeight() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(renderTargetHeight));
}

_MTL_INLINE NS::UInteger MTL4::RenderPassDescriptor::renderTargetWidth() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(renderTargetWidth));
}

_MTL_INLINE void MTL4::RenderPassDescriptor::setDefaultRasterSampleCount(
    const NS::UInteger defaultRasterSampleCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDefaultRasterSampleCount_), defaultRasterSampleCount);
}

_MTL_INLINE void MTL4::RenderPassDescriptor::setDepthAttachment(
    const MTL::RenderPassDepthAttachmentDescriptor* depthAttachment) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDepthAttachment_), depthAttachment);
}

_MTL_INLINE void MTL4::RenderPassDescriptor::setImageblockSampleLength(const NS::UInteger imageblockSampleLength) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setImageblockSampleLength_), imageblockSampleLength);
}

_MTL_INLINE void MTL4::RenderPassDescriptor::setRasterizationRateMap(
    const MTL::RasterizationRateMap* rasterizationRateMap) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRasterizationRateMap_), rasterizationRateMap);
}

_MTL_INLINE void MTL4::RenderPassDescriptor::setRenderTargetArrayLength(
    const NS::UInteger renderTargetArrayLength) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRenderTargetArrayLength_), renderTargetArrayLength);
}

_MTL_INLINE void MTL4::RenderPassDescriptor::setRenderTargetHeight(const NS::UInteger renderTargetHeight) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRenderTargetHeight_), renderTargetHeight);
}

_MTL_INLINE void MTL4::RenderPassDescriptor::setRenderTargetWidth(const NS::UInteger renderTargetWidth) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRenderTargetWidth_), renderTargetWidth);
}

_MTL_INLINE void MTL4::RenderPassDescriptor::setSamplePositions(const MTL::SamplePosition* positions,
                                                                const NS::UInteger         count) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSamplePositions_count_), positions, count);
}

_MTL_INLINE void MTL4::RenderPassDescriptor::setStencilAttachment(
    const MTL::RenderPassStencilAttachmentDescriptor* stencilAttachment) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setStencilAttachment_), stencilAttachment);
}

_MTL_INLINE void MTL4::RenderPassDescriptor::setSupportColorAttachmentMapping(
    const bool supportColorAttachmentMapping) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSupportColorAttachmentMapping_), supportColorAttachmentMapping);
}

_MTL_INLINE void MTL4::RenderPassDescriptor::setThreadgroupMemoryLength(
    const NS::UInteger threadgroupMemoryLength) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setThreadgroupMemoryLength_), threadgroupMemoryLength);
}

_MTL_INLINE void MTL4::RenderPassDescriptor::setTileHeight(const NS::UInteger tileHeight) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTileHeight_), tileHeight);
}

_MTL_INLINE void MTL4::RenderPassDescriptor::setTileWidth(const NS::UInteger tileWidth) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTileWidth_), tileWidth);
}

_MTL_INLINE void MTL4::RenderPassDescriptor::setVisibilityResultBuffer(const MTL::Buffer* visibilityResultBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVisibilityResultBuffer_), visibilityResultBuffer);
}

_MTL_INLINE void MTL4::RenderPassDescriptor::setVisibilityResultType(
    const MTL::VisibilityResultType visibilityResultType) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVisibilityResultType_), visibilityResultType);
}

_MTL_INLINE MTL::RenderPassStencilAttachmentDescriptor* MTL4::RenderPassDescriptor::stencilAttachment() const
{
    return sendMessage<MTL::RenderPassStencilAttachmentDescriptor*>(this, _MTL_PRIVATE_SEL(stencilAttachment));
}

_MTL_INLINE bool MTL4::RenderPassDescriptor::supportColorAttachmentMapping() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supportColorAttachmentMapping));
}

_MTL_INLINE NS::UInteger MTL4::RenderPassDescriptor::threadgroupMemoryLength() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(threadgroupMemoryLength));
}

_MTL_INLINE NS::UInteger MTL4::RenderPassDescriptor::tileHeight() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(tileHeight));
}

_MTL_INLINE NS::UInteger MTL4::RenderPassDescriptor::tileWidth() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(tileWidth));
}

_MTL_INLINE MTL::Buffer* MTL4::RenderPassDescriptor::visibilityResultBuffer() const
{
    return sendMessage<MTL::Buffer*>(this, _MTL_PRIVATE_SEL(visibilityResultBuffer));
}

_MTL_INLINE MTL::VisibilityResultType MTL4::RenderPassDescriptor::visibilityResultType() const
{
    return sendMessage<MTL::VisibilityResultType>(this, _MTL_PRIVATE_SEL(visibilityResultType));
}
