//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTL4MeshRenderPipeline.hpp
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
#include "MTL4RenderPipeline.hpp"
#include "MTLDefines.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"
#include "MTLTypes.hpp"

namespace MTL4
{
    class FunctionDescriptor;
    class MeshRenderPipelineDescriptor;
    class RenderPipelineColorAttachmentDescriptorArray;
    class StaticLinkingDescriptor;

    /// @see https://developer.apple.com/documentation/metal/mtl4meshrenderpipelinedescriptor
    class MeshRenderPipelineDescriptor : public NS::Copying<MeshRenderPipelineDescriptor, PipelineDescriptor>
    {
    public:
        [[nodiscard]] static MeshRenderPipelineDescriptor* alloc();

        [[nodiscard]] AlphaToCoverageState alphaToCoverageState() const;

        [[nodiscard]] AlphaToOneState alphaToOneState() const;

        [[nodiscard]] LogicalToPhysicalColorAttachmentMappingState colorAttachmentMappingState() const;

        [[nodiscard]] RenderPipelineColorAttachmentDescriptorArray* colorAttachments() const;

        [[nodiscard]] FunctionDescriptor* fragmentFunctionDescriptor() const;

        [[nodiscard]] StaticLinkingDescriptor* fragmentStaticLinkingDescriptor() const;

        [[nodiscard]] MeshRenderPipelineDescriptor* init();

        [[nodiscard]] bool isRasterizationEnabled() const;

        [[nodiscard]] NS::UInteger maxTotalThreadgroupsPerMeshGrid() const;

        [[nodiscard]] NS::UInteger maxTotalThreadsPerMeshThreadgroup() const;

        [[nodiscard]] NS::UInteger maxTotalThreadsPerObjectThreadgroup() const;

        [[nodiscard]] NS::UInteger maxVertexAmplificationCount() const;

        [[nodiscard]] FunctionDescriptor* meshFunctionDescriptor() const;

        [[nodiscard]] StaticLinkingDescriptor* meshStaticLinkingDescriptor() const;

        [[nodiscard]] bool meshThreadgroupSizeIsMultipleOfThreadExecutionWidth() const;

        [[nodiscard]] FunctionDescriptor* objectFunctionDescriptor() const;

        [[nodiscard]] StaticLinkingDescriptor* objectStaticLinkingDescriptor() const;

        [[nodiscard]] bool objectThreadgroupSizeIsMultipleOfThreadExecutionWidth() const;

        [[nodiscard]] NS::UInteger payloadMemoryLength() const;

        [[nodiscard]] NS::UInteger rasterSampleCount() const;

        [[deprecated("please use isRasterizationEnabled instead")]] [[nodiscard]] bool rasterizationEnabled() const;

        [[nodiscard]] MTL::Size requiredThreadsPerMeshThreadgroup() const;

        [[nodiscard]] MTL::Size requiredThreadsPerObjectThreadgroup() const;

        [[nodiscard]] bool supportFragmentBinaryLinking() const;

        [[nodiscard]] IndirectCommandBufferSupportState supportIndirectCommandBuffers() const;

        [[nodiscard]] bool supportMeshBinaryLinking() const;

        [[nodiscard]] bool supportObjectBinaryLinking() const;

        void reset() const;

        void setAlphaToCoverageState(AlphaToCoverageState alphaToCoverageState) const;

        void setAlphaToOneState(AlphaToOneState alphaToOneState) const;

        void setColorAttachmentMappingState(
            LogicalToPhysicalColorAttachmentMappingState colorAttachmentMappingState) const;

        void setFragmentFunctionDescriptor(const FunctionDescriptor* fragmentFunctionDescriptor) const;

        void setFragmentStaticLinkingDescriptor(const StaticLinkingDescriptor* fragmentStaticLinkingDescriptor) const;

        void setMaxTotalThreadgroupsPerMeshGrid(NS::UInteger maxTotalThreadgroupsPerMeshGrid) const;

        void setMaxTotalThreadsPerMeshThreadgroup(NS::UInteger maxTotalThreadsPerMeshThreadgroup) const;

        void setMaxTotalThreadsPerObjectThreadgroup(NS::UInteger maxTotalThreadsPerObjectThreadgroup) const;

        void setMaxVertexAmplificationCount(NS::UInteger maxVertexAmplificationCount) const;

        void setMeshFunctionDescriptor(const FunctionDescriptor* meshFunctionDescriptor) const;

        void setMeshStaticLinkingDescriptor(const StaticLinkingDescriptor* meshStaticLinkingDescriptor) const;

        void setMeshThreadgroupSizeIsMultipleOfThreadExecutionWidth(
            bool meshThreadgroupSizeIsMultipleOfThreadExecutionWidth) const;

        void setObjectFunctionDescriptor(const FunctionDescriptor* objectFunctionDescriptor) const;

        void setObjectStaticLinkingDescriptor(const StaticLinkingDescriptor* objectStaticLinkingDescriptor) const;

        void setObjectThreadgroupSizeIsMultipleOfThreadExecutionWidth(
            bool objectThreadgroupSizeIsMultipleOfThreadExecutionWidth) const;

        void setPayloadMemoryLength(NS::UInteger payloadMemoryLength) const;

        void setRasterSampleCount(NS::UInteger rasterSampleCount) const;

        void setRasterizationEnabled(bool rasterizationEnabled) const;

        void setRequiredThreadsPerMeshThreadgroup(const MTL::Size& requiredThreadsPerMeshThreadgroup) const;

        void setRequiredThreadsPerObjectThreadgroup(const MTL::Size& requiredThreadsPerObjectThreadgroup) const;

        void setSupportFragmentBinaryLinking(bool supportFragmentBinaryLinking) const;

        void setSupportIndirectCommandBuffers(IndirectCommandBufferSupportState supportIndirectCommandBuffers) const;

        void setSupportMeshBinaryLinking(bool supportMeshBinaryLinking) const;

        void setSupportObjectBinaryLinking(bool supportObjectBinaryLinking) const;
    };

} // namespace MTL4
_MTL_INLINE MTL4::MeshRenderPipelineDescriptor* MTL4::MeshRenderPipelineDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<MeshRenderPipelineDescriptor>(_MTL_PRIVATE_CLS(MTL4MeshRenderPipelineDescriptor));
}

_MTL_INLINE MTL4::AlphaToCoverageState MTL4::MeshRenderPipelineDescriptor::alphaToCoverageState() const
{
    return sendMessage<AlphaToCoverageState>(this, _MTL_PRIVATE_SEL(alphaToCoverageState));
}

_MTL_INLINE MTL4::AlphaToOneState MTL4::MeshRenderPipelineDescriptor::alphaToOneState() const
{
    return sendMessage<AlphaToOneState>(this, _MTL_PRIVATE_SEL(alphaToOneState));
}

_MTL_INLINE MTL4::LogicalToPhysicalColorAttachmentMappingState
            MTL4::MeshRenderPipelineDescriptor::colorAttachmentMappingState() const
{
    return sendMessage<LogicalToPhysicalColorAttachmentMappingState>(this,
                                                                     _MTL_PRIVATE_SEL(colorAttachmentMappingState));
}

_MTL_INLINE MTL4::RenderPipelineColorAttachmentDescriptorArray* MTL4::MeshRenderPipelineDescriptor::colorAttachments()
    const
{
    return sendMessage<RenderPipelineColorAttachmentDescriptorArray*>(this, _MTL_PRIVATE_SEL(colorAttachments));
}

_MTL_INLINE MTL4::FunctionDescriptor* MTL4::MeshRenderPipelineDescriptor::fragmentFunctionDescriptor() const
{
    return sendMessage<FunctionDescriptor*>(this, _MTL_PRIVATE_SEL(fragmentFunctionDescriptor));
}

_MTL_INLINE MTL4::StaticLinkingDescriptor* MTL4::MeshRenderPipelineDescriptor::fragmentStaticLinkingDescriptor() const
{
    return sendMessage<StaticLinkingDescriptor*>(this, _MTL_PRIVATE_SEL(fragmentStaticLinkingDescriptor));
}

_MTL_INLINE MTL4::MeshRenderPipelineDescriptor* MTL4::MeshRenderPipelineDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<MeshRenderPipelineDescriptor>();
}

_MTL_INLINE bool MTL4::MeshRenderPipelineDescriptor::isRasterizationEnabled() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isRasterizationEnabled));
}

_MTL_INLINE NS::UInteger MTL4::MeshRenderPipelineDescriptor::maxTotalThreadgroupsPerMeshGrid() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxTotalThreadgroupsPerMeshGrid));
}

_MTL_INLINE NS::UInteger MTL4::MeshRenderPipelineDescriptor::maxTotalThreadsPerMeshThreadgroup() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxTotalThreadsPerMeshThreadgroup));
}

_MTL_INLINE NS::UInteger MTL4::MeshRenderPipelineDescriptor::maxTotalThreadsPerObjectThreadgroup() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxTotalThreadsPerObjectThreadgroup));
}

_MTL_INLINE NS::UInteger MTL4::MeshRenderPipelineDescriptor::maxVertexAmplificationCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxVertexAmplificationCount));
}

_MTL_INLINE MTL4::FunctionDescriptor* MTL4::MeshRenderPipelineDescriptor::meshFunctionDescriptor() const
{
    return sendMessage<FunctionDescriptor*>(this, _MTL_PRIVATE_SEL(meshFunctionDescriptor));
}

_MTL_INLINE MTL4::StaticLinkingDescriptor* MTL4::MeshRenderPipelineDescriptor::meshStaticLinkingDescriptor() const
{
    return sendMessage<StaticLinkingDescriptor*>(this, _MTL_PRIVATE_SEL(meshStaticLinkingDescriptor));
}

_MTL_INLINE bool MTL4::MeshRenderPipelineDescriptor::meshThreadgroupSizeIsMultipleOfThreadExecutionWidth() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(meshThreadgroupSizeIsMultipleOfThreadExecutionWidth));
}

_MTL_INLINE MTL4::FunctionDescriptor* MTL4::MeshRenderPipelineDescriptor::objectFunctionDescriptor() const
{
    return sendMessage<FunctionDescriptor*>(this, _MTL_PRIVATE_SEL(objectFunctionDescriptor));
}

_MTL_INLINE MTL4::StaticLinkingDescriptor* MTL4::MeshRenderPipelineDescriptor::objectStaticLinkingDescriptor() const
{
    return sendMessage<StaticLinkingDescriptor*>(this, _MTL_PRIVATE_SEL(objectStaticLinkingDescriptor));
}

_MTL_INLINE bool MTL4::MeshRenderPipelineDescriptor::objectThreadgroupSizeIsMultipleOfThreadExecutionWidth() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(objectThreadgroupSizeIsMultipleOfThreadExecutionWidth));
}

_MTL_INLINE NS::UInteger MTL4::MeshRenderPipelineDescriptor::payloadMemoryLength() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(payloadMemoryLength));
}

_MTL_INLINE NS::UInteger MTL4::MeshRenderPipelineDescriptor::rasterSampleCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(rasterSampleCount));
}

_MTL_INLINE bool MTL4::MeshRenderPipelineDescriptor::rasterizationEnabled() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isRasterizationEnabled));
}

_MTL_INLINE MTL::Size MTL4::MeshRenderPipelineDescriptor::requiredThreadsPerMeshThreadgroup() const
{
    return sendMessage<MTL::Size>(this, _MTL_PRIVATE_SEL(requiredThreadsPerMeshThreadgroup));
}

_MTL_INLINE MTL::Size MTL4::MeshRenderPipelineDescriptor::requiredThreadsPerObjectThreadgroup() const
{
    return sendMessage<MTL::Size>(this, _MTL_PRIVATE_SEL(requiredThreadsPerObjectThreadgroup));
}

_MTL_INLINE void MTL4::MeshRenderPipelineDescriptor::reset() const { sendMessage<void>(this, _MTL_PRIVATE_SEL(reset)); }

_MTL_INLINE void MTL4::MeshRenderPipelineDescriptor::setAlphaToCoverageState(
    const AlphaToCoverageState alphaToCoverageState) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setAlphaToCoverageState_), alphaToCoverageState);
}

_MTL_INLINE void MTL4::MeshRenderPipelineDescriptor::setAlphaToOneState(const AlphaToOneState alphaToOneState) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setAlphaToOneState_), alphaToOneState);
}

_MTL_INLINE void MTL4::MeshRenderPipelineDescriptor::setColorAttachmentMappingState(
    const LogicalToPhysicalColorAttachmentMappingState colorAttachmentMappingState) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setColorAttachmentMappingState_), colorAttachmentMappingState);
}

_MTL_INLINE void MTL4::MeshRenderPipelineDescriptor::setFragmentFunctionDescriptor(
    const FunctionDescriptor* fragmentFunctionDescriptor) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFragmentFunctionDescriptor_), fragmentFunctionDescriptor);
}

_MTL_INLINE void MTL4::MeshRenderPipelineDescriptor::setFragmentStaticLinkingDescriptor(
    const StaticLinkingDescriptor* fragmentStaticLinkingDescriptor) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFragmentStaticLinkingDescriptor_), fragmentStaticLinkingDescriptor);
}

_MTL_INLINE void MTL4::MeshRenderPipelineDescriptor::setMaxTotalThreadgroupsPerMeshGrid(
    const NS::UInteger maxTotalThreadgroupsPerMeshGrid) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxTotalThreadgroupsPerMeshGrid_), maxTotalThreadgroupsPerMeshGrid);
}

_MTL_INLINE void MTL4::MeshRenderPipelineDescriptor::setMaxTotalThreadsPerMeshThreadgroup(
    const NS::UInteger maxTotalThreadsPerMeshThreadgroup) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxTotalThreadsPerMeshThreadgroup_), maxTotalThreadsPerMeshThreadgroup);
}

_MTL_INLINE void MTL4::MeshRenderPipelineDescriptor::setMaxTotalThreadsPerObjectThreadgroup(
    const NS::UInteger maxTotalThreadsPerObjectThreadgroup) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setMaxTotalThreadsPerObjectThreadgroup_), maxTotalThreadsPerObjectThreadgroup);
}

_MTL_INLINE void MTL4::MeshRenderPipelineDescriptor::setMaxVertexAmplificationCount(
    const NS::UInteger maxVertexAmplificationCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxVertexAmplificationCount_), maxVertexAmplificationCount);
}

_MTL_INLINE void MTL4::MeshRenderPipelineDescriptor::setMeshFunctionDescriptor(
    const FunctionDescriptor* meshFunctionDescriptor) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMeshFunctionDescriptor_), meshFunctionDescriptor);
}

_MTL_INLINE void MTL4::MeshRenderPipelineDescriptor::setMeshStaticLinkingDescriptor(
    const StaticLinkingDescriptor* meshStaticLinkingDescriptor) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMeshStaticLinkingDescriptor_), meshStaticLinkingDescriptor);
}

_MTL_INLINE void MTL4::MeshRenderPipelineDescriptor::setMeshThreadgroupSizeIsMultipleOfThreadExecutionWidth(
    const bool meshThreadgroupSizeIsMultipleOfThreadExecutionWidth) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(setMeshThreadgroupSizeIsMultipleOfThreadExecutionWidth_),
                      meshThreadgroupSizeIsMultipleOfThreadExecutionWidth);
}

_MTL_INLINE void MTL4::MeshRenderPipelineDescriptor::setObjectFunctionDescriptor(
    const FunctionDescriptor* objectFunctionDescriptor) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setObjectFunctionDescriptor_), objectFunctionDescriptor);
}

_MTL_INLINE void MTL4::MeshRenderPipelineDescriptor::setObjectStaticLinkingDescriptor(
    const StaticLinkingDescriptor* objectStaticLinkingDescriptor) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setObjectStaticLinkingDescriptor_), objectStaticLinkingDescriptor);
}

_MTL_INLINE void MTL4::MeshRenderPipelineDescriptor::setObjectThreadgroupSizeIsMultipleOfThreadExecutionWidth(
    const bool objectThreadgroupSizeIsMultipleOfThreadExecutionWidth) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(setObjectThreadgroupSizeIsMultipleOfThreadExecutionWidth_),
                      objectThreadgroupSizeIsMultipleOfThreadExecutionWidth);
}

_MTL_INLINE void MTL4::MeshRenderPipelineDescriptor::setPayloadMemoryLength(
    const NS::UInteger payloadMemoryLength) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setPayloadMemoryLength_), payloadMemoryLength);
}

_MTL_INLINE void MTL4::MeshRenderPipelineDescriptor::setRasterSampleCount(const NS::UInteger rasterSampleCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRasterSampleCount_), rasterSampleCount);
}

_MTL_INLINE void MTL4::MeshRenderPipelineDescriptor::setRasterizationEnabled(const bool rasterizationEnabled) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRasterizationEnabled_), rasterizationEnabled);
}

_MTL_INLINE void MTL4::MeshRenderPipelineDescriptor::setRequiredThreadsPerMeshThreadgroup(
    const MTL::Size& requiredThreadsPerMeshThreadgroup) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRequiredThreadsPerMeshThreadgroup_), requiredThreadsPerMeshThreadgroup);
}

_MTL_INLINE void MTL4::MeshRenderPipelineDescriptor::setRequiredThreadsPerObjectThreadgroup(
    const MTL::Size& requiredThreadsPerObjectThreadgroup) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setRequiredThreadsPerObjectThreadgroup_), requiredThreadsPerObjectThreadgroup);
}

_MTL_INLINE void MTL4::MeshRenderPipelineDescriptor::setSupportFragmentBinaryLinking(
    const bool supportFragmentBinaryLinking) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSupportFragmentBinaryLinking_), supportFragmentBinaryLinking);
}

_MTL_INLINE void MTL4::MeshRenderPipelineDescriptor::setSupportIndirectCommandBuffers(
    const IndirectCommandBufferSupportState supportIndirectCommandBuffers) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSupportIndirectCommandBuffers_), supportIndirectCommandBuffers);
}

_MTL_INLINE void MTL4::MeshRenderPipelineDescriptor::setSupportMeshBinaryLinking(
    const bool supportMeshBinaryLinking) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSupportMeshBinaryLinking_), supportMeshBinaryLinking);
}

_MTL_INLINE void MTL4::MeshRenderPipelineDescriptor::setSupportObjectBinaryLinking(
    const bool supportObjectBinaryLinking) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSupportObjectBinaryLinking_), supportObjectBinaryLinking);
}

_MTL_INLINE bool MTL4::MeshRenderPipelineDescriptor::supportFragmentBinaryLinking() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supportFragmentBinaryLinking));
}

_MTL_INLINE MTL4::IndirectCommandBufferSupportState MTL4::MeshRenderPipelineDescriptor::supportIndirectCommandBuffers()
    const
{
    return sendMessage<IndirectCommandBufferSupportState>(this, _MTL_PRIVATE_SEL(supportIndirectCommandBuffers));
}

_MTL_INLINE bool MTL4::MeshRenderPipelineDescriptor::supportMeshBinaryLinking() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supportMeshBinaryLinking));
}

_MTL_INLINE bool MTL4::MeshRenderPipelineDescriptor::supportObjectBinaryLinking() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supportObjectBinaryLinking));
}
