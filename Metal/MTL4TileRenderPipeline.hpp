//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTL4TileRenderPipeline.hpp
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
#include "MTL4PipelineState.hpp"
#include "MTLDefines.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"
#include "MTLTypes.hpp"

namespace MTL4
{
    class FunctionDescriptor;
    class StaticLinkingDescriptor;
    class TileRenderPipelineDescriptor;
} // namespace MTL4

namespace MTL
{
    class TileRenderPipelineColorAttachmentDescriptorArray;
}

namespace MTL4
{
    /// @see https://developer.apple.com/documentation/metal/mtl4tilerenderpipelinedescriptor
    class TileRenderPipelineDescriptor : public NS::Copying<TileRenderPipelineDescriptor, PipelineDescriptor>
    {
    public:
        [[nodiscard]] static TileRenderPipelineDescriptor* alloc();

        [[nodiscard]] MTL::TileRenderPipelineColorAttachmentDescriptorArray* colorAttachments() const;

        [[nodiscard]] TileRenderPipelineDescriptor* init();

        [[nodiscard]] NS::UInteger maxTotalThreadsPerThreadgroup() const;

        [[nodiscard]] NS::UInteger rasterSampleCount() const;

        [[nodiscard]] MTL::Size requiredThreadsPerThreadgroup() const;

        [[nodiscard]] StaticLinkingDescriptor* staticLinkingDescriptor() const;

        [[nodiscard]] bool supportBinaryLinking() const;

        [[nodiscard]] bool threadgroupSizeMatchesTileSize() const;

        [[nodiscard]] FunctionDescriptor* tileFunctionDescriptor() const;

        void reset() const;

        void setMaxTotalThreadsPerThreadgroup(NS::UInteger maxTotalThreadsPerThreadgroup) const;

        void setRasterSampleCount(NS::UInteger rasterSampleCount) const;

        void setRequiredThreadsPerThreadgroup(const MTL::Size& requiredThreadsPerThreadgroup) const;

        void setStaticLinkingDescriptor(const StaticLinkingDescriptor* staticLinkingDescriptor) const;

        void setSupportBinaryLinking(bool supportBinaryLinking) const;

        void setThreadgroupSizeMatchesTileSize(bool threadgroupSizeMatchesTileSize) const;

        void setTileFunctionDescriptor(const FunctionDescriptor* tileFunctionDescriptor) const;
    };

} // namespace MTL4
_MTL_INLINE MTL4::TileRenderPipelineDescriptor* MTL4::TileRenderPipelineDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<TileRenderPipelineDescriptor>(_MTL_PRIVATE_CLS(MTL4TileRenderPipelineDescriptor));
}

_MTL_INLINE MTL::TileRenderPipelineColorAttachmentDescriptorArray*
            MTL4::TileRenderPipelineDescriptor::colorAttachments() const
{
    return sendMessage<MTL::TileRenderPipelineColorAttachmentDescriptorArray*>(this,
                                                                               _MTL_PRIVATE_SEL(colorAttachments));
}

_MTL_INLINE MTL4::TileRenderPipelineDescriptor* MTL4::TileRenderPipelineDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<TileRenderPipelineDescriptor>();
}

_MTL_INLINE NS::UInteger MTL4::TileRenderPipelineDescriptor::maxTotalThreadsPerThreadgroup() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxTotalThreadsPerThreadgroup));
}

_MTL_INLINE NS::UInteger MTL4::TileRenderPipelineDescriptor::rasterSampleCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(rasterSampleCount));
}

_MTL_INLINE MTL::Size MTL4::TileRenderPipelineDescriptor::requiredThreadsPerThreadgroup() const
{
    return sendMessage<MTL::Size>(this, _MTL_PRIVATE_SEL(requiredThreadsPerThreadgroup));
}

_MTL_INLINE void MTL4::TileRenderPipelineDescriptor::reset() const { sendMessage<void>(this, _MTL_PRIVATE_SEL(reset)); }

_MTL_INLINE void MTL4::TileRenderPipelineDescriptor::setMaxTotalThreadsPerThreadgroup(
    const NS::UInteger maxTotalThreadsPerThreadgroup) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxTotalThreadsPerThreadgroup_), maxTotalThreadsPerThreadgroup);
}

_MTL_INLINE void MTL4::TileRenderPipelineDescriptor::setRasterSampleCount(const NS::UInteger rasterSampleCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRasterSampleCount_), rasterSampleCount);
}

_MTL_INLINE void MTL4::TileRenderPipelineDescriptor::setRequiredThreadsPerThreadgroup(
    const MTL::Size& requiredThreadsPerThreadgroup) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRequiredThreadsPerThreadgroup_), requiredThreadsPerThreadgroup);
}

_MTL_INLINE void MTL4::TileRenderPipelineDescriptor::setStaticLinkingDescriptor(
    const StaticLinkingDescriptor* staticLinkingDescriptor) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setStaticLinkingDescriptor_), staticLinkingDescriptor);
}

_MTL_INLINE void MTL4::TileRenderPipelineDescriptor::setSupportBinaryLinking(const bool supportBinaryLinking) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSupportBinaryLinking_), supportBinaryLinking);
}

_MTL_INLINE void MTL4::TileRenderPipelineDescriptor::setThreadgroupSizeMatchesTileSize(
    const bool threadgroupSizeMatchesTileSize) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setThreadgroupSizeMatchesTileSize_), threadgroupSizeMatchesTileSize);
}

_MTL_INLINE void MTL4::TileRenderPipelineDescriptor::setTileFunctionDescriptor(
    const FunctionDescriptor* tileFunctionDescriptor) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTileFunctionDescriptor_), tileFunctionDescriptor);
}

_MTL_INLINE MTL4::StaticLinkingDescriptor* MTL4::TileRenderPipelineDescriptor::staticLinkingDescriptor() const
{
    return sendMessage<StaticLinkingDescriptor*>(this, _MTL_PRIVATE_SEL(staticLinkingDescriptor));
}

_MTL_INLINE bool MTL4::TileRenderPipelineDescriptor::supportBinaryLinking() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supportBinaryLinking));
}

_MTL_INLINE bool MTL4::TileRenderPipelineDescriptor::threadgroupSizeMatchesTileSize() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(threadgroupSizeMatchesTileSize));
}

_MTL_INLINE MTL4::FunctionDescriptor* MTL4::TileRenderPipelineDescriptor::tileFunctionDescriptor() const
{
    return sendMessage<FunctionDescriptor*>(this, _MTL_PRIVATE_SEL(tileFunctionDescriptor));
}
