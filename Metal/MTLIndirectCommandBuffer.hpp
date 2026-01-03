//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLIndirectCommandBuffer.hpp
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
#include "MTLDefines.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"
#include "MTLResource.hpp"
#include "MTLTypes.hpp"

namespace MTL
{
    class IndirectCommandBufferDescriptor;
    class IndirectComputeCommand;
    class IndirectRenderCommand;

    /// @see https://developer.apple.com/documentation/metal/mtlindirectcommandtype?language=objc
    _MTL_OPTIONS(NS::UInteger, IndirectCommandType){
        IndirectCommandTypeDraw                      = 1,
        IndirectCommandTypeDrawIndexed               = 1 << 1,
        IndirectCommandTypeDrawPatches               = 1 << 2,
        IndirectCommandTypeDrawIndexedPatches        = 1 << 3,
        IndirectCommandTypeConcurrentDispatch        = 1 << 5,
        IndirectCommandTypeConcurrentDispatchThreads = 1 << 6,
        IndirectCommandTypeDrawMeshThreadgroups      = 1 << 7,
        IndirectCommandTypeDrawMeshThreads           = 1 << 8,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlindirectcommandbufferexecutionrange?language=objc
    struct IndirectCommandBufferExecutionRange
    {
        uint32_t location;
        uint32_t length;
    } _MTL_PACKED;

    /// @see https://developer.apple.com/documentation/metal/mtlindirectcommandbufferdescriptor?language=objc
    class IndirectCommandBufferDescriptor : public NS::Copying<IndirectCommandBufferDescriptor>
    {
    public:
        [[nodiscard]] static IndirectCommandBufferDescriptor* alloc();

        [[nodiscard]] IndirectCommandType commandTypes() const;

        [[nodiscard]] bool inheritBuffers() const;

        [[nodiscard]] bool inheritCullMode() const;

        [[nodiscard]] bool inheritDepthBias() const;

        [[nodiscard]] bool inheritDepthClipMode() const;

        [[nodiscard]] bool inheritDepthStencilState() const;

        [[nodiscard]] bool inheritFrontFacingWinding() const;

        [[nodiscard]] bool inheritPipelineState() const;

        [[nodiscard]] bool inheritTriangleFillMode() const;

        [[nodiscard]] IndirectCommandBufferDescriptor* init();

        [[nodiscard]] NS::UInteger maxFragmentBufferBindCount() const;

        [[nodiscard]] NS::UInteger maxKernelBufferBindCount() const;

        [[nodiscard]] NS::UInteger maxKernelThreadgroupMemoryBindCount() const;

        [[nodiscard]] NS::UInteger maxMeshBufferBindCount() const;

        [[nodiscard]] NS::UInteger maxObjectBufferBindCount() const;

        [[nodiscard]] NS::UInteger maxObjectThreadgroupMemoryBindCount() const;

        [[nodiscard]] NS::UInteger maxVertexBufferBindCount() const;

        void setCommandTypes(IndirectCommandType commandTypes) const;

        void setInheritBuffers(bool inheritBuffers) const;

        void setInheritCullMode(bool inheritCullMode) const;

        void setInheritDepthBias(bool inheritDepthBias) const;

        void setInheritDepthClipMode(bool inheritDepthClipMode) const;

        void setInheritDepthStencilState(bool inheritDepthStencilState) const;

        void setInheritFrontFacingWinding(bool inheritFrontFacingWinding) const;

        void setInheritPipelineState(bool inheritPipelineState) const;

        void setInheritTriangleFillMode(bool inheritTriangleFillMode) const;

        void setMaxFragmentBufferBindCount(NS::UInteger maxFragmentBufferBindCount) const;

        void setMaxKernelBufferBindCount(NS::UInteger maxKernelBufferBindCount) const;

        void setMaxKernelThreadgroupMemoryBindCount(NS::UInteger maxKernelThreadgroupMemoryBindCount) const;

        void setMaxMeshBufferBindCount(NS::UInteger maxMeshBufferBindCount) const;

        void setMaxObjectBufferBindCount(NS::UInteger maxObjectBufferBindCount) const;

        void setMaxObjectThreadgroupMemoryBindCount(NS::UInteger maxObjectThreadgroupMemoryBindCount) const;

        void setMaxVertexBufferBindCount(NS::UInteger maxVertexBufferBindCount) const;

        void setSupportColorAttachmentMapping(bool supportColorAttachmentMapping) const;

        void setSupportDynamicAttributeStride(bool supportDynamicAttributeStride) const;

        void setSupportRayTracing(bool supportRayTracing) const;

        [[nodiscard]] bool supportColorAttachmentMapping() const;

        [[nodiscard]] bool supportDynamicAttributeStride() const;

        [[nodiscard]] bool supportRayTracing() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlindirectcommandbuffer?language=objc
    class IndirectCommandBuffer : public NS::Referencing<IndirectCommandBuffer, Resource>
    {
    public:
        [[nodiscard]] ResourceID gpuResourceID() const;

        [[nodiscard]] IndirectComputeCommand* indirectComputeCommand(NS::UInteger commandIndex) const;

        [[nodiscard]] IndirectRenderCommand* indirectRenderCommand(NS::UInteger commandIndex) const;

        void reset(NS::Range range) const;

        [[nodiscard]] NS::UInteger size() const;
    };

} // namespace MTL

_MTL_INLINE MTL::IndirectCommandBufferDescriptor* MTL::IndirectCommandBufferDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<IndirectCommandBufferDescriptor>(_MTL_PRIVATE_CLS(MTLIndirectCommandBufferDescriptor));
}

_MTL_INLINE MTL::IndirectCommandType MTL::IndirectCommandBufferDescriptor::commandTypes() const
{
    return sendMessage<IndirectCommandType>(this, _MTL_PRIVATE_SEL(commandTypes));
}

_MTL_INLINE bool MTL::IndirectCommandBufferDescriptor::inheritBuffers() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(inheritBuffers));
}

_MTL_INLINE bool MTL::IndirectCommandBufferDescriptor::inheritCullMode() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(inheritCullMode));
}

_MTL_INLINE bool MTL::IndirectCommandBufferDescriptor::inheritDepthBias() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(inheritDepthBias));
}

_MTL_INLINE bool MTL::IndirectCommandBufferDescriptor::inheritDepthClipMode() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(inheritDepthClipMode));
}

_MTL_INLINE bool MTL::IndirectCommandBufferDescriptor::inheritDepthStencilState() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(inheritDepthStencilState));
}

_MTL_INLINE bool MTL::IndirectCommandBufferDescriptor::inheritFrontFacingWinding() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(inheritFrontFacingWinding));
}

_MTL_INLINE bool MTL::IndirectCommandBufferDescriptor::inheritPipelineState() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(inheritPipelineState));
}

_MTL_INLINE bool MTL::IndirectCommandBufferDescriptor::inheritTriangleFillMode() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(inheritTriangleFillMode));
}

_MTL_INLINE MTL::IndirectCommandBufferDescriptor* MTL::IndirectCommandBufferDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<IndirectCommandBufferDescriptor>();
}

_MTL_INLINE NS::UInteger MTL::IndirectCommandBufferDescriptor::maxFragmentBufferBindCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxFragmentBufferBindCount));
}

_MTL_INLINE NS::UInteger MTL::IndirectCommandBufferDescriptor::maxKernelBufferBindCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxKernelBufferBindCount));
}

_MTL_INLINE NS::UInteger MTL::IndirectCommandBufferDescriptor::maxKernelThreadgroupMemoryBindCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxKernelThreadgroupMemoryBindCount));
}

_MTL_INLINE NS::UInteger MTL::IndirectCommandBufferDescriptor::maxMeshBufferBindCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxMeshBufferBindCount));
}

_MTL_INLINE NS::UInteger MTL::IndirectCommandBufferDescriptor::maxObjectBufferBindCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxObjectBufferBindCount));
}

_MTL_INLINE NS::UInteger MTL::IndirectCommandBufferDescriptor::maxObjectThreadgroupMemoryBindCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxObjectThreadgroupMemoryBindCount));
}

_MTL_INLINE NS::UInteger MTL::IndirectCommandBufferDescriptor::maxVertexBufferBindCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxVertexBufferBindCount));
}

_MTL_INLINE void MTL::IndirectCommandBufferDescriptor::setCommandTypes(const IndirectCommandType commandTypes) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setCommandTypes_), commandTypes);
}

_MTL_INLINE void MTL::IndirectCommandBufferDescriptor::setInheritBuffers(const bool inheritBuffers) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setInheritBuffers_), inheritBuffers);
}

_MTL_INLINE void MTL::IndirectCommandBufferDescriptor::setInheritCullMode(const bool inheritCullMode) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setInheritCullMode_), inheritCullMode);
}

_MTL_INLINE void MTL::IndirectCommandBufferDescriptor::setInheritDepthBias(const bool inheritDepthBias) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setInheritDepthBias_), inheritDepthBias);
}

_MTL_INLINE void MTL::IndirectCommandBufferDescriptor::setInheritDepthClipMode(const bool inheritDepthClipMode) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setInheritDepthClipMode_), inheritDepthClipMode);
}

_MTL_INLINE void MTL::IndirectCommandBufferDescriptor::setInheritDepthStencilState(
    const bool inheritDepthStencilState) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setInheritDepthStencilState_), inheritDepthStencilState);
}

_MTL_INLINE void MTL::IndirectCommandBufferDescriptor::setInheritFrontFacingWinding(
    const bool inheritFrontFacingWinding) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setInheritFrontFacingWinding_), inheritFrontFacingWinding);
}

_MTL_INLINE void MTL::IndirectCommandBufferDescriptor::setInheritPipelineState(const bool inheritPipelineState) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setInheritPipelineState_), inheritPipelineState);
}

_MTL_INLINE void MTL::IndirectCommandBufferDescriptor::setInheritTriangleFillMode(
    const bool inheritTriangleFillMode) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setInheritTriangleFillMode_), inheritTriangleFillMode);
}

_MTL_INLINE void MTL::IndirectCommandBufferDescriptor::setMaxFragmentBufferBindCount(
    const NS::UInteger maxFragmentBufferBindCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxFragmentBufferBindCount_), maxFragmentBufferBindCount);
}

_MTL_INLINE void MTL::IndirectCommandBufferDescriptor::setMaxKernelBufferBindCount(
    const NS::UInteger maxKernelBufferBindCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxKernelBufferBindCount_), maxKernelBufferBindCount);
}

_MTL_INLINE void MTL::IndirectCommandBufferDescriptor::setMaxKernelThreadgroupMemoryBindCount(
    const NS::UInteger maxKernelThreadgroupMemoryBindCount) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setMaxKernelThreadgroupMemoryBindCount_), maxKernelThreadgroupMemoryBindCount);
}

_MTL_INLINE void MTL::IndirectCommandBufferDescriptor::setMaxMeshBufferBindCount(
    const NS::UInteger maxMeshBufferBindCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxMeshBufferBindCount_), maxMeshBufferBindCount);
}

_MTL_INLINE void MTL::IndirectCommandBufferDescriptor::setMaxObjectBufferBindCount(
    const NS::UInteger maxObjectBufferBindCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxObjectBufferBindCount_), maxObjectBufferBindCount);
}

_MTL_INLINE void MTL::IndirectCommandBufferDescriptor::setMaxObjectThreadgroupMemoryBindCount(
    const NS::UInteger maxObjectThreadgroupMemoryBindCount) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setMaxObjectThreadgroupMemoryBindCount_), maxObjectThreadgroupMemoryBindCount);
}

_MTL_INLINE void MTL::IndirectCommandBufferDescriptor::setMaxVertexBufferBindCount(
    const NS::UInteger maxVertexBufferBindCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxVertexBufferBindCount_), maxVertexBufferBindCount);
}

_MTL_INLINE void MTL::IndirectCommandBufferDescriptor::setSupportColorAttachmentMapping(
    const bool supportColorAttachmentMapping) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSupportColorAttachmentMapping_), supportColorAttachmentMapping);
}

_MTL_INLINE void MTL::IndirectCommandBufferDescriptor::setSupportDynamicAttributeStride(
    const bool supportDynamicAttributeStride) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSupportDynamicAttributeStride_), supportDynamicAttributeStride);
}

_MTL_INLINE void MTL::IndirectCommandBufferDescriptor::setSupportRayTracing(const bool supportRayTracing) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSupportRayTracing_), supportRayTracing);
}

_MTL_INLINE bool MTL::IndirectCommandBufferDescriptor::supportColorAttachmentMapping() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supportColorAttachmentMapping));
}

_MTL_INLINE bool MTL::IndirectCommandBufferDescriptor::supportDynamicAttributeStride() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supportDynamicAttributeStride));
}

_MTL_INLINE bool MTL::IndirectCommandBufferDescriptor::supportRayTracing() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supportRayTracing));
}

_MTL_INLINE MTL::ResourceID MTL::IndirectCommandBuffer::gpuResourceID() const
{
    return sendMessage<ResourceID>(this, _MTL_PRIVATE_SEL(gpuResourceID));
}

_MTL_INLINE MTL::IndirectComputeCommand* MTL::IndirectCommandBuffer::indirectComputeCommand(
    const NS::UInteger commandIndex) const
{
    return sendMessage<IndirectComputeCommand*>(this, _MTL_PRIVATE_SEL(indirectComputeCommandAtIndex_), commandIndex);
}

_MTL_INLINE MTL::IndirectRenderCommand* MTL::IndirectCommandBuffer::indirectRenderCommand(
    const NS::UInteger commandIndex) const
{
    return sendMessage<IndirectRenderCommand*>(this, _MTL_PRIVATE_SEL(indirectRenderCommandAtIndex_), commandIndex);
}

_MTL_INLINE void MTL::IndirectCommandBuffer::reset(const NS::Range range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(resetWithRange_), range);
}

_MTL_INLINE NS::UInteger MTL::IndirectCommandBuffer::size() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(size));
}
