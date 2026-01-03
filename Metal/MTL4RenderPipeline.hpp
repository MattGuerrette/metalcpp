//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTL4RenderPipeline.hpp
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
#include "MTLPixelFormat.hpp"
#include "MTLPrivate.hpp"
#include "MTLRenderPipeline.hpp"

namespace MTL4
{
    class FunctionDescriptor;
    class RenderPipelineBinaryFunctionsDescriptor;
    class RenderPipelineColorAttachmentDescriptor;
    class RenderPipelineColorAttachmentDescriptorArray;
    class RenderPipelineDescriptor;
    class StaticLinkingDescriptor;
} // namespace MTL4

namespace MTL
{
    class VertexDescriptor;
}

namespace MTL4
{
    _MTL_ENUM(NS::Integer, LogicalToPhysicalColorAttachmentMappingState){
        LogicalToPhysicalColorAttachmentMappingStateIdentity  = 0,
        LogicalToPhysicalColorAttachmentMappingStateInherited = 1,
    };

    /// @see https://developer.apple.com/documentation/metal/mtl4renderpipelinecolorattachmentdescriptor
    class RenderPipelineColorAttachmentDescriptor : public NS::Copying<RenderPipelineColorAttachmentDescriptor>
    {
    public:
        [[nodiscard]] static RenderPipelineColorAttachmentDescriptor* alloc();

        [[nodiscard]] MTL::BlendOperation alphaBlendOperation() const;

        [[nodiscard]] BlendState blendingState() const;

        [[nodiscard]] MTL::BlendFactor destinationAlphaBlendFactor() const;

        [[nodiscard]] MTL::BlendFactor destinationRGBBlendFactor() const;

        [[nodiscard]] RenderPipelineColorAttachmentDescriptor* init();

        [[nodiscard]] MTL::PixelFormat pixelFormat() const;

        [[nodiscard]] MTL::BlendOperation rgbBlendOperation() const;

        [[nodiscard]] MTL::BlendFactor sourceAlphaBlendFactor() const;

        [[nodiscard]] MTL::BlendFactor sourceRGBBlendFactor() const;

        [[nodiscard]] MTL::ColorWriteMask writeMask() const;

        void reset() const;

        void setAlphaBlendOperation(MTL::BlendOperation alphaBlendOperation) const;

        void setBlendingState(BlendState blendingState) const;

        void setDestinationAlphaBlendFactor(MTL::BlendFactor destinationAlphaBlendFactor) const;

        void setDestinationRGBBlendFactor(MTL::BlendFactor destinationRGBBlendFactor) const;

        void setPixelFormat(MTL::PixelFormat pixelFormat) const;

        void setRgbBlendOperation(MTL::BlendOperation rgbBlendOperation) const;

        void setSourceAlphaBlendFactor(MTL::BlendFactor sourceAlphaBlendFactor) const;

        void setSourceRGBBlendFactor(MTL::BlendFactor sourceRGBBlendFactor) const;

        void setWriteMask(MTL::ColorWriteMask writeMask) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtl4renderpipelinecolorattachmentdescriptorarray
    class RenderPipelineColorAttachmentDescriptorArray
        : public NS::Copying<RenderPipelineColorAttachmentDescriptorArray>
    {
    public:
        [[nodiscard]] static RenderPipelineColorAttachmentDescriptorArray* alloc();

        [[nodiscard]] RenderPipelineColorAttachmentDescriptorArray* init();

        [[nodiscard]] RenderPipelineColorAttachmentDescriptor* object(NS::UInteger attachmentIndex) const;

        void reset() const;

        void setObject(const RenderPipelineColorAttachmentDescriptor* attachment, NS::UInteger attachmentIndex) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtl4renderpipelinebinaryfunctionsdescriptor
    class RenderPipelineBinaryFunctionsDescriptor : public NS::Copying<RenderPipelineBinaryFunctionsDescriptor>
    {
    public:
        [[nodiscard]] static RenderPipelineBinaryFunctionsDescriptor* alloc();

        [[nodiscard]] NS::Array* fragmentAdditionalBinaryFunctions() const;

        [[nodiscard]] RenderPipelineBinaryFunctionsDescriptor* init();

        [[nodiscard]] NS::Array* meshAdditionalBinaryFunctions() const;

        [[nodiscard]] NS::Array* objectAdditionalBinaryFunctions() const;

        [[nodiscard]] NS::Array* tileAdditionalBinaryFunctions() const;

        [[nodiscard]] NS::Array* vertexAdditionalBinaryFunctions() const;

        void reset() const;

        void setFragmentAdditionalBinaryFunctions(const NS::Array* fragmentAdditionalBinaryFunctions) const;

        void setMeshAdditionalBinaryFunctions(const NS::Array* meshAdditionalBinaryFunctions) const;

        void setObjectAdditionalBinaryFunctions(const NS::Array* objectAdditionalBinaryFunctions) const;

        void setTileAdditionalBinaryFunctions(const NS::Array* tileAdditionalBinaryFunctions) const;

        void setVertexAdditionalBinaryFunctions(const NS::Array* vertexAdditionalBinaryFunctions) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtl4renderpipelinedescriptor
    class RenderPipelineDescriptor : public NS::Copying<RenderPipelineDescriptor, PipelineDescriptor>
    {
    public:
        [[nodiscard]] static RenderPipelineDescriptor* alloc();

        [[nodiscard]] AlphaToCoverageState alphaToCoverageState() const;

        [[nodiscard]] AlphaToOneState alphaToOneState() const;

        [[nodiscard]] LogicalToPhysicalColorAttachmentMappingState colorAttachmentMappingState() const;

        [[nodiscard]] RenderPipelineColorAttachmentDescriptorArray* colorAttachments() const;

        [[nodiscard]] FunctionDescriptor* fragmentFunctionDescriptor() const;

        [[nodiscard]] StaticLinkingDescriptor* fragmentStaticLinkingDescriptor() const;

        [[nodiscard]] RenderPipelineDescriptor* init();

        [[nodiscard]] MTL::PrimitiveTopologyClass inputPrimitiveTopology() const;

        [[nodiscard]] bool isRasterizationEnabled() const;

        [[nodiscard]] NS::UInteger maxVertexAmplificationCount() const;

        [[nodiscard]] NS::UInteger rasterSampleCount() const;

        [[deprecated("please use isRasterizationEnabled instead")]] [[nodiscard]] bool rasterizationEnabled() const;

        [[nodiscard]] bool supportFragmentBinaryLinking() const;

        [[nodiscard]] IndirectCommandBufferSupportState supportIndirectCommandBuffers() const;

        [[nodiscard]] bool supportVertexBinaryLinking() const;

        [[nodiscard]] MTL::VertexDescriptor* vertexDescriptor() const;

        [[nodiscard]] FunctionDescriptor* vertexFunctionDescriptor() const;

        [[nodiscard]] StaticLinkingDescriptor* vertexStaticLinkingDescriptor() const;

        void reset() const;

        void setAlphaToCoverageState(AlphaToCoverageState alphaToCoverageState) const;

        void setAlphaToOneState(AlphaToOneState alphaToOneState) const;

        void setColorAttachmentMappingState(
            LogicalToPhysicalColorAttachmentMappingState colorAttachmentMappingState) const;

        void setFragmentFunctionDescriptor(const FunctionDescriptor* fragmentFunctionDescriptor) const;

        void setFragmentStaticLinkingDescriptor(const StaticLinkingDescriptor* fragmentStaticLinkingDescriptor) const;

        void setInputPrimitiveTopology(MTL::PrimitiveTopologyClass inputPrimitiveTopology) const;

        void setMaxVertexAmplificationCount(NS::UInteger maxVertexAmplificationCount) const;

        void setRasterSampleCount(NS::UInteger rasterSampleCount) const;

        void setRasterizationEnabled(bool rasterizationEnabled) const;

        void setSupportFragmentBinaryLinking(bool supportFragmentBinaryLinking) const;

        void setSupportIndirectCommandBuffers(IndirectCommandBufferSupportState supportIndirectCommandBuffers) const;

        void setSupportVertexBinaryLinking(bool supportVertexBinaryLinking) const;

        void setVertexDescriptor(const MTL::VertexDescriptor* vertexDescriptor) const;

        void setVertexFunctionDescriptor(const FunctionDescriptor* vertexFunctionDescriptor) const;

        void setVertexStaticLinkingDescriptor(const StaticLinkingDescriptor* vertexStaticLinkingDescriptor) const;
    };

} // namespace MTL4
_MTL_INLINE MTL4::RenderPipelineColorAttachmentDescriptor* MTL4::RenderPipelineColorAttachmentDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<RenderPipelineColorAttachmentDescriptor>(
        _MTL_PRIVATE_CLS(MTL4RenderPipelineColorAttachmentDescriptor));
}

_MTL_INLINE MTL::BlendOperation MTL4::RenderPipelineColorAttachmentDescriptor::alphaBlendOperation() const
{
    return sendMessage<MTL::BlendOperation>(this, _MTL_PRIVATE_SEL(alphaBlendOperation));
}

_MTL_INLINE MTL4::BlendState MTL4::RenderPipelineColorAttachmentDescriptor::blendingState() const
{
    return sendMessage<BlendState>(this, _MTL_PRIVATE_SEL(blendingState));
}

_MTL_INLINE MTL::BlendFactor MTL4::RenderPipelineColorAttachmentDescriptor::destinationAlphaBlendFactor() const
{
    return sendMessage<MTL::BlendFactor>(this, _MTL_PRIVATE_SEL(destinationAlphaBlendFactor));
}

_MTL_INLINE MTL::BlendFactor MTL4::RenderPipelineColorAttachmentDescriptor::destinationRGBBlendFactor() const
{
    return sendMessage<MTL::BlendFactor>(this, _MTL_PRIVATE_SEL(destinationRGBBlendFactor));
}

_MTL_INLINE MTL4::RenderPipelineColorAttachmentDescriptor* MTL4::RenderPipelineColorAttachmentDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<RenderPipelineColorAttachmentDescriptor>();
}

_MTL_INLINE MTL::PixelFormat MTL4::RenderPipelineColorAttachmentDescriptor::pixelFormat() const
{
    return sendMessage<MTL::PixelFormat>(this, _MTL_PRIVATE_SEL(pixelFormat));
}

_MTL_INLINE void MTL4::RenderPipelineColorAttachmentDescriptor::reset() const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(reset));
}

_MTL_INLINE MTL::BlendOperation MTL4::RenderPipelineColorAttachmentDescriptor::rgbBlendOperation() const
{
    return sendMessage<MTL::BlendOperation>(this, _MTL_PRIVATE_SEL(rgbBlendOperation));
}

_MTL_INLINE void MTL4::RenderPipelineColorAttachmentDescriptor::setAlphaBlendOperation(
    const MTL::BlendOperation alphaBlendOperation) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setAlphaBlendOperation_), alphaBlendOperation);
}

_MTL_INLINE void MTL4::RenderPipelineColorAttachmentDescriptor::setBlendingState(const BlendState blendingState) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBlendingState_), blendingState);
}

_MTL_INLINE void MTL4::RenderPipelineColorAttachmentDescriptor::setDestinationAlphaBlendFactor(
    const MTL::BlendFactor destinationAlphaBlendFactor) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDestinationAlphaBlendFactor_), destinationAlphaBlendFactor);
}

_MTL_INLINE void MTL4::RenderPipelineColorAttachmentDescriptor::setDestinationRGBBlendFactor(
    const MTL::BlendFactor destinationRGBBlendFactor) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDestinationRGBBlendFactor_), destinationRGBBlendFactor);
}

_MTL_INLINE void MTL4::RenderPipelineColorAttachmentDescriptor::setPixelFormat(const MTL::PixelFormat pixelFormat) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setPixelFormat_), pixelFormat);
}

_MTL_INLINE void MTL4::RenderPipelineColorAttachmentDescriptor::setRgbBlendOperation(
    const MTL::BlendOperation rgbBlendOperation) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRgbBlendOperation_), rgbBlendOperation);
}

_MTL_INLINE void MTL4::RenderPipelineColorAttachmentDescriptor::setSourceAlphaBlendFactor(
    const MTL::BlendFactor sourceAlphaBlendFactor) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSourceAlphaBlendFactor_), sourceAlphaBlendFactor);
}

_MTL_INLINE void MTL4::RenderPipelineColorAttachmentDescriptor::setSourceRGBBlendFactor(
    const MTL::BlendFactor sourceRGBBlendFactor) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSourceRGBBlendFactor_), sourceRGBBlendFactor);
}

_MTL_INLINE void MTL4::RenderPipelineColorAttachmentDescriptor::setWriteMask(const MTL::ColorWriteMask writeMask) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setWriteMask_), writeMask);
}

_MTL_INLINE MTL::BlendFactor MTL4::RenderPipelineColorAttachmentDescriptor::sourceAlphaBlendFactor() const
{
    return sendMessage<MTL::BlendFactor>(this, _MTL_PRIVATE_SEL(sourceAlphaBlendFactor));
}

_MTL_INLINE MTL::BlendFactor MTL4::RenderPipelineColorAttachmentDescriptor::sourceRGBBlendFactor() const
{
    return sendMessage<MTL::BlendFactor>(this, _MTL_PRIVATE_SEL(sourceRGBBlendFactor));
}

_MTL_INLINE MTL::ColorWriteMask MTL4::RenderPipelineColorAttachmentDescriptor::writeMask() const
{
    return sendMessage<MTL::ColorWriteMask>(this, _MTL_PRIVATE_SEL(writeMask));
}

_MTL_INLINE MTL4::RenderPipelineColorAttachmentDescriptorArray*
            MTL4::RenderPipelineColorAttachmentDescriptorArray::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<RenderPipelineColorAttachmentDescriptorArray>(
        _MTL_PRIVATE_CLS(MTL4RenderPipelineColorAttachmentDescriptorArray));
}

_MTL_INLINE MTL4::RenderPipelineColorAttachmentDescriptorArray*
            MTL4::RenderPipelineColorAttachmentDescriptorArray::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<RenderPipelineColorAttachmentDescriptorArray>();
}

_MTL_INLINE MTL4::RenderPipelineColorAttachmentDescriptor* MTL4::RenderPipelineColorAttachmentDescriptorArray::object(
    const NS::UInteger attachmentIndex) const
{
    return sendMessage<RenderPipelineColorAttachmentDescriptor*>(
        this, _MTL_PRIVATE_SEL(objectAtIndexedSubscript_), attachmentIndex);
}

_MTL_INLINE void MTL4::RenderPipelineColorAttachmentDescriptorArray::reset() const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(reset));
}

_MTL_INLINE void MTL4::RenderPipelineColorAttachmentDescriptorArray::setObject(
    const RenderPipelineColorAttachmentDescriptor* attachment, const NS::UInteger attachmentIndex) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setObject_atIndexedSubscript_), attachment, attachmentIndex);
}

_MTL_INLINE MTL4::RenderPipelineBinaryFunctionsDescriptor* MTL4::RenderPipelineBinaryFunctionsDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<RenderPipelineBinaryFunctionsDescriptor>(
        _MTL_PRIVATE_CLS(MTL4RenderPipelineBinaryFunctionsDescriptor));
}

_MTL_INLINE NS::Array* MTL4::RenderPipelineBinaryFunctionsDescriptor::fragmentAdditionalBinaryFunctions() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(fragmentAdditionalBinaryFunctions));
}

_MTL_INLINE MTL4::RenderPipelineBinaryFunctionsDescriptor* MTL4::RenderPipelineBinaryFunctionsDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<RenderPipelineBinaryFunctionsDescriptor>();
}

_MTL_INLINE NS::Array* MTL4::RenderPipelineBinaryFunctionsDescriptor::meshAdditionalBinaryFunctions() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(meshAdditionalBinaryFunctions));
}

_MTL_INLINE NS::Array* MTL4::RenderPipelineBinaryFunctionsDescriptor::objectAdditionalBinaryFunctions() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(objectAdditionalBinaryFunctions));
}

_MTL_INLINE void MTL4::RenderPipelineBinaryFunctionsDescriptor::reset() const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(reset));
}

_MTL_INLINE void MTL4::RenderPipelineBinaryFunctionsDescriptor::setFragmentAdditionalBinaryFunctions(
    const NS::Array* fragmentAdditionalBinaryFunctions) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFragmentAdditionalBinaryFunctions_), fragmentAdditionalBinaryFunctions);
}

_MTL_INLINE void MTL4::RenderPipelineBinaryFunctionsDescriptor::setMeshAdditionalBinaryFunctions(
    const NS::Array* meshAdditionalBinaryFunctions) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMeshAdditionalBinaryFunctions_), meshAdditionalBinaryFunctions);
}

_MTL_INLINE void MTL4::RenderPipelineBinaryFunctionsDescriptor::setObjectAdditionalBinaryFunctions(
    const NS::Array* objectAdditionalBinaryFunctions) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setObjectAdditionalBinaryFunctions_), objectAdditionalBinaryFunctions);
}

_MTL_INLINE void MTL4::RenderPipelineBinaryFunctionsDescriptor::setTileAdditionalBinaryFunctions(
    const NS::Array* tileAdditionalBinaryFunctions) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTileAdditionalBinaryFunctions_), tileAdditionalBinaryFunctions);
}

_MTL_INLINE void MTL4::RenderPipelineBinaryFunctionsDescriptor::setVertexAdditionalBinaryFunctions(
    const NS::Array* vertexAdditionalBinaryFunctions) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVertexAdditionalBinaryFunctions_), vertexAdditionalBinaryFunctions);
}

_MTL_INLINE NS::Array* MTL4::RenderPipelineBinaryFunctionsDescriptor::tileAdditionalBinaryFunctions() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(tileAdditionalBinaryFunctions));
}

_MTL_INLINE NS::Array* MTL4::RenderPipelineBinaryFunctionsDescriptor::vertexAdditionalBinaryFunctions() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(vertexAdditionalBinaryFunctions));
}

_MTL_INLINE MTL4::RenderPipelineDescriptor* MTL4::RenderPipelineDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<RenderPipelineDescriptor>(_MTL_PRIVATE_CLS(MTL4RenderPipelineDescriptor));
}

_MTL_INLINE MTL4::AlphaToCoverageState MTL4::RenderPipelineDescriptor::alphaToCoverageState() const
{
    return sendMessage<AlphaToCoverageState>(this, _MTL_PRIVATE_SEL(alphaToCoverageState));
}

_MTL_INLINE MTL4::AlphaToOneState MTL4::RenderPipelineDescriptor::alphaToOneState() const
{
    return sendMessage<AlphaToOneState>(this, _MTL_PRIVATE_SEL(alphaToOneState));
}

_MTL_INLINE MTL4::LogicalToPhysicalColorAttachmentMappingState
            MTL4::RenderPipelineDescriptor::colorAttachmentMappingState() const
{
    return sendMessage<LogicalToPhysicalColorAttachmentMappingState>(this,
                                                                     _MTL_PRIVATE_SEL(colorAttachmentMappingState));
}

_MTL_INLINE MTL4::RenderPipelineColorAttachmentDescriptorArray* MTL4::RenderPipelineDescriptor::colorAttachments() const
{
    return sendMessage<RenderPipelineColorAttachmentDescriptorArray*>(this, _MTL_PRIVATE_SEL(colorAttachments));
}

_MTL_INLINE MTL4::FunctionDescriptor* MTL4::RenderPipelineDescriptor::fragmentFunctionDescriptor() const
{
    return sendMessage<FunctionDescriptor*>(this, _MTL_PRIVATE_SEL(fragmentFunctionDescriptor));
}

_MTL_INLINE MTL4::StaticLinkingDescriptor* MTL4::RenderPipelineDescriptor::fragmentStaticLinkingDescriptor() const
{
    return sendMessage<StaticLinkingDescriptor*>(this, _MTL_PRIVATE_SEL(fragmentStaticLinkingDescriptor));
}

_MTL_INLINE MTL4::RenderPipelineDescriptor* MTL4::RenderPipelineDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<RenderPipelineDescriptor>();
}

_MTL_INLINE MTL::PrimitiveTopologyClass MTL4::RenderPipelineDescriptor::inputPrimitiveTopology() const
{
    return sendMessage<MTL::PrimitiveTopologyClass>(this, _MTL_PRIVATE_SEL(inputPrimitiveTopology));
}

_MTL_INLINE bool MTL4::RenderPipelineDescriptor::isRasterizationEnabled() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isRasterizationEnabled));
}

_MTL_INLINE NS::UInteger MTL4::RenderPipelineDescriptor::maxVertexAmplificationCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxVertexAmplificationCount));
}

_MTL_INLINE NS::UInteger MTL4::RenderPipelineDescriptor::rasterSampleCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(rasterSampleCount));
}

_MTL_INLINE bool MTL4::RenderPipelineDescriptor::rasterizationEnabled() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isRasterizationEnabled));
}

_MTL_INLINE void MTL4::RenderPipelineDescriptor::reset() const { sendMessage<void>(this, _MTL_PRIVATE_SEL(reset)); }

_MTL_INLINE void MTL4::RenderPipelineDescriptor::setAlphaToCoverageState(
    const AlphaToCoverageState alphaToCoverageState) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setAlphaToCoverageState_), alphaToCoverageState);
}

_MTL_INLINE void MTL4::RenderPipelineDescriptor::setAlphaToOneState(const AlphaToOneState alphaToOneState) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setAlphaToOneState_), alphaToOneState);
}

_MTL_INLINE void MTL4::RenderPipelineDescriptor::setColorAttachmentMappingState(
    const LogicalToPhysicalColorAttachmentMappingState colorAttachmentMappingState) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setColorAttachmentMappingState_), colorAttachmentMappingState);
}

_MTL_INLINE void MTL4::RenderPipelineDescriptor::setFragmentFunctionDescriptor(
    const FunctionDescriptor* fragmentFunctionDescriptor) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFragmentFunctionDescriptor_), fragmentFunctionDescriptor);
}

_MTL_INLINE void MTL4::RenderPipelineDescriptor::setFragmentStaticLinkingDescriptor(
    const StaticLinkingDescriptor* fragmentStaticLinkingDescriptor) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFragmentStaticLinkingDescriptor_), fragmentStaticLinkingDescriptor);
}

_MTL_INLINE void MTL4::RenderPipelineDescriptor::setInputPrimitiveTopology(
    const MTL::PrimitiveTopologyClass inputPrimitiveTopology) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setInputPrimitiveTopology_), inputPrimitiveTopology);
}

_MTL_INLINE void MTL4::RenderPipelineDescriptor::setMaxVertexAmplificationCount(
    const NS::UInteger maxVertexAmplificationCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxVertexAmplificationCount_), maxVertexAmplificationCount);
}

_MTL_INLINE void MTL4::RenderPipelineDescriptor::setRasterSampleCount(const NS::UInteger rasterSampleCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRasterSampleCount_), rasterSampleCount);
}

_MTL_INLINE void MTL4::RenderPipelineDescriptor::setRasterizationEnabled(const bool rasterizationEnabled) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRasterizationEnabled_), rasterizationEnabled);
}

_MTL_INLINE void MTL4::RenderPipelineDescriptor::setSupportFragmentBinaryLinking(
    const bool supportFragmentBinaryLinking) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSupportFragmentBinaryLinking_), supportFragmentBinaryLinking);
}

_MTL_INLINE void MTL4::RenderPipelineDescriptor::setSupportIndirectCommandBuffers(
    const IndirectCommandBufferSupportState supportIndirectCommandBuffers) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSupportIndirectCommandBuffers_), supportIndirectCommandBuffers);
}

_MTL_INLINE void MTL4::RenderPipelineDescriptor::setSupportVertexBinaryLinking(
    const bool supportVertexBinaryLinking) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSupportVertexBinaryLinking_), supportVertexBinaryLinking);
}

_MTL_INLINE void MTL4::RenderPipelineDescriptor::setVertexDescriptor(
    const MTL::VertexDescriptor* vertexDescriptor) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVertexDescriptor_), vertexDescriptor);
}

_MTL_INLINE void MTL4::RenderPipelineDescriptor::setVertexFunctionDescriptor(
    const FunctionDescriptor* vertexFunctionDescriptor) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVertexFunctionDescriptor_), vertexFunctionDescriptor);
}

_MTL_INLINE void MTL4::RenderPipelineDescriptor::setVertexStaticLinkingDescriptor(
    const StaticLinkingDescriptor* vertexStaticLinkingDescriptor) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVertexStaticLinkingDescriptor_), vertexStaticLinkingDescriptor);
}

_MTL_INLINE bool MTL4::RenderPipelineDescriptor::supportFragmentBinaryLinking() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supportFragmentBinaryLinking));
}

_MTL_INLINE MTL4::IndirectCommandBufferSupportState MTL4::RenderPipelineDescriptor::supportIndirectCommandBuffers()
    const
{
    return sendMessage<IndirectCommandBufferSupportState>(this, _MTL_PRIVATE_SEL(supportIndirectCommandBuffers));
}

_MTL_INLINE bool MTL4::RenderPipelineDescriptor::supportVertexBinaryLinking() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supportVertexBinaryLinking));
}

_MTL_INLINE MTL::VertexDescriptor* MTL4::RenderPipelineDescriptor::vertexDescriptor() const
{
    return sendMessage<MTL::VertexDescriptor*>(this, _MTL_PRIVATE_SEL(vertexDescriptor));
}

_MTL_INLINE MTL4::FunctionDescriptor* MTL4::RenderPipelineDescriptor::vertexFunctionDescriptor() const
{
    return sendMessage<FunctionDescriptor*>(this, _MTL_PRIVATE_SEL(vertexFunctionDescriptor));
}

_MTL_INLINE MTL4::StaticLinkingDescriptor* MTL4::RenderPipelineDescriptor::vertexStaticLinkingDescriptor() const
{
    return sendMessage<StaticLinkingDescriptor*>(this, _MTL_PRIVATE_SEL(vertexStaticLinkingDescriptor));
}
