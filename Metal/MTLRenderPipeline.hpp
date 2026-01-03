//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLRenderPipeline.hpp
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
#include "MTLAllocation.hpp"
#include "MTLDefines.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPipeline.hpp"
#include "MTLPixelFormat.hpp"
#include "MTLPrivate.hpp"
#include "MTLRenderCommandEncoder.hpp"
#include "MTLTypes.hpp"

namespace MTL
{
    class Device;
    class Function;
    class FunctionHandle;
    class IntersectionFunctionTable;
    class IntersectionFunctionTableDescriptor;
    class LinkedFunctions;
    class LogicalToPhysicalColorAttachmentMap;
    class MeshRenderPipelineDescriptor;
    class PipelineBufferDescriptorArray;
    class RenderPipelineColorAttachmentDescriptor;
    class RenderPipelineColorAttachmentDescriptorArray;
    class RenderPipelineDescriptor;
    class RenderPipelineFunctionsDescriptor;
    class RenderPipelineReflection;
    class RenderPipelineState;
    class TileRenderPipelineColorAttachmentDescriptor;
    class TileRenderPipelineColorAttachmentDescriptorArray;
    class TileRenderPipelineDescriptor;
    class VertexDescriptor;
    class VisibleFunctionTable;
    class VisibleFunctionTableDescriptor;

} // namespace MTL
namespace MTL4
{
    class BinaryFunction;
    class PipelineDescriptor;
    class RenderPipelineBinaryFunctionsDescriptor;

} // namespace MTL4
namespace MTL
{
    /// @see https://developer.apple.com/documentation/metal/mtlblendfactor?language=objc
    _MTL_ENUM(NS::UInteger, BlendFactor){
        BlendFactorZero                     = 0,
        BlendFactorOne                      = 1,
        BlendFactorSourceColor              = 2,
        BlendFactorOneMinusSourceColor      = 3,
        BlendFactorSourceAlpha              = 4,
        BlendFactorOneMinusSourceAlpha      = 5,
        BlendFactorDestinationColor         = 6,
        BlendFactorOneMinusDestinationColor = 7,
        BlendFactorDestinationAlpha         = 8,
        BlendFactorOneMinusDestinationAlpha = 9,
        BlendFactorSourceAlphaSaturated     = 10,
        BlendFactorBlendColor               = 11,
        BlendFactorOneMinusBlendColor       = 12,
        BlendFactorBlendAlpha               = 13,
        BlendFactorOneMinusBlendAlpha       = 14,
        BlendFactorSource1Color             = 15,
        BlendFactorOneMinusSource1Color     = 16,
        BlendFactorSource1Alpha             = 17,
        BlendFactorOneMinusSource1Alpha     = 18,
        BlendFactorUnspecialized            = 19,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlblendoperation?language=objc
    _MTL_ENUM(NS::UInteger, BlendOperation){
        BlendOperationAdd = 0, BlendOperationSubtract = 1, BlendOperationReverseSubtract = 2,
        BlendOperationMin = 3, BlendOperationMax = 4,      BlendOperationUnspecialized = 5,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlprimitivetopologyclass?language=objc
    _MTL_ENUM(NS::UInteger, PrimitiveTopologyClass){
        PrimitiveTopologyClassUnspecified = 0,
        PrimitiveTopologyClassPoint       = 1,
        PrimitiveTopologyClassLine        = 2,
        PrimitiveTopologyClassTriangle    = 3,
    };

    /// @see https://developer.apple.com/documentation/metal/mtltessellationpartitionmode?language=objc
    _MTL_ENUM(NS::UInteger, TessellationPartitionMode){
        TessellationPartitionModePow2           = 0,
        TessellationPartitionModeInteger        = 1,
        TessellationPartitionModeFractionalOdd  = 2,
        TessellationPartitionModeFractionalEven = 3,
    };

    /// @see https://developer.apple.com/documentation/metal/mtltessellationfactorstepfunction?language=objc
    _MTL_ENUM(NS::UInteger, TessellationFactorStepFunction){
        TessellationFactorStepFunctionConstant               = 0,
        TessellationFactorStepFunctionPerPatch               = 1,
        TessellationFactorStepFunctionPerInstance            = 2,
        TessellationFactorStepFunctionPerPatchAndPerInstance = 3,
    };

    /// @see https://developer.apple.com/documentation/metal/mtltessellationfactorformat?language=objc
    _MTL_ENUM(NS::UInteger, TessellationFactorFormat){
        TessellationFactorFormatHalf = 0,
    };

    /// @see https://developer.apple.com/documentation/metal/mtltessellationcontrolpointindextype?language=objc
    _MTL_ENUM(NS::UInteger, TessellationControlPointIndexType){
        TessellationControlPointIndexTypeNone   = 0,
        TessellationControlPointIndexTypeUInt16 = 1,
        TessellationControlPointIndexTypeUInt32 = 2,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlcolorwritemask?language=objc
    _MTL_OPTIONS(NS::UInteger, ColorWriteMask){
        ColorWriteMaskNone          = 0,
        ColorWriteMaskRed           = 1 << 3,
        ColorWriteMaskGreen         = 1 << 2,
        ColorWriteMaskBlue          = 1 << 1,
        ColorWriteMaskAlpha         = 1,
        ColorWriteMaskAll           = 15,
        ColorWriteMaskUnspecialized = 1 << 4,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlrenderpipelinecolorattachmentdescriptor?language=objc
    class RenderPipelineColorAttachmentDescriptor : public NS::Copying<RenderPipelineColorAttachmentDescriptor>
    {
    public:
        [[nodiscard]] static RenderPipelineColorAttachmentDescriptor* alloc();

        [[nodiscard]] BlendOperation alphaBlendOperation() const;

        [[deprecated("please use isBlendingEnabled instead")]] [[nodiscard]] bool blendingEnabled() const;

        [[nodiscard]] BlendFactor destinationAlphaBlendFactor() const;

        [[nodiscard]] BlendFactor destinationRGBBlendFactor() const;

        [[nodiscard]] RenderPipelineColorAttachmentDescriptor* init();

        [[nodiscard]] bool isBlendingEnabled() const;

        [[nodiscard]] PixelFormat pixelFormat() const;

        [[nodiscard]] BlendOperation rgbBlendOperation() const;

        void setAlphaBlendOperation(BlendOperation alphaBlendOperation);

        void setBlendingEnabled(bool blendingEnabled);

        void setDestinationAlphaBlendFactor(BlendFactor destinationAlphaBlendFactor);

        void setDestinationRGBBlendFactor(BlendFactor destinationRGBBlendFactor);

        void setPixelFormat(PixelFormat pixelFormat);

        void setRgbBlendOperation(BlendOperation rgbBlendOperation);

        void setSourceAlphaBlendFactor(BlendFactor sourceAlphaBlendFactor);

        void setSourceRGBBlendFactor(BlendFactor sourceRGBBlendFactor);

        void setWriteMask(ColorWriteMask writeMask);

        [[nodiscard]] BlendFactor sourceAlphaBlendFactor() const;

        [[nodiscard]] BlendFactor sourceRGBBlendFactor() const;

        [[nodiscard]] ColorWriteMask writeMask() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtllogicaltophysicalcolorattachmentmap?language=objc
    class LogicalToPhysicalColorAttachmentMap : public NS::Copying<LogicalToPhysicalColorAttachmentMap>
    {
    public:
        static LogicalToPhysicalColorAttachmentMap* alloc();

        NS::UInteger getPhysicalIndex(NS::UInteger logicalIndex);

        LogicalToPhysicalColorAttachmentMap* init();

        void reset();

        void setPhysicalIndex(NS::UInteger physicalIndex, NS::UInteger logicalIndex);
    };

    class RenderPipelineReflection : public NS::Referencing<RenderPipelineReflection>
    {
    public:
        static RenderPipelineReflection* alloc();

        NS::Array* fragmentArguments() const;

        NS::Array* fragmentBindings() const;

        RenderPipelineReflection* init();

        NS::Array* meshBindings() const;

        NS::Array* objectBindings() const;

        NS::Array* tileArguments() const;

        NS::Array* tileBindings() const;

        NS::Array* vertexArguments() const;

        NS::Array* vertexBindings() const;
    };
    class RenderPipelineDescriptor : public NS::Copying<RenderPipelineDescriptor>
    {
    public:
        static RenderPipelineDescriptor* alloc();

        [[deprecated("please use isAlphaToCoverageEnabled instead")]]
        bool alphaToCoverageEnabled() const;

        [[deprecated("please use isAlphaToOneEnabled instead")]]
        bool alphaToOneEnabled() const;

        NS::Array* binaryArchives() const;

        RenderPipelineColorAttachmentDescriptorArray* colorAttachments() const;

        PixelFormat depthAttachmentPixelFormat() const;

        PipelineBufferDescriptorArray* fragmentBuffers() const;

        Function* fragmentFunction() const;

        LinkedFunctions* fragmentLinkedFunctions() const;

        NS::Array* fragmentPreloadedLibraries() const;

        RenderPipelineDescriptor* init();

        PrimitiveTopologyClass inputPrimitiveTopology() const;

        bool isAlphaToCoverageEnabled() const;

        bool isAlphaToOneEnabled() const;

        bool isRasterizationEnabled() const;

        bool isTessellationFactorScaleEnabled() const;

        NS::String* label() const;

        NS::UInteger maxFragmentCallStackDepth() const;

        NS::UInteger maxTessellationFactor() const;

        NS::UInteger maxVertexAmplificationCount() const;

        NS::UInteger maxVertexCallStackDepth() const;

        NS::UInteger rasterSampleCount() const;

        [[deprecated("please use isRasterizationEnabled instead")]]
        bool rasterizationEnabled() const;

        void reset();

        NS::UInteger sampleCount() const;

        void setAlphaToCoverageEnabled(bool alphaToCoverageEnabled);

        void setAlphaToOneEnabled(bool alphaToOneEnabled);

        void setBinaryArchives(const NS::Array* binaryArchives);

        void setDepthAttachmentPixelFormat(PixelFormat depthAttachmentPixelFormat);

        void setFragmentFunction(const Function* fragmentFunction);

        void setFragmentLinkedFunctions(const LinkedFunctions* fragmentLinkedFunctions);

        void setFragmentPreloadedLibraries(const NS::Array* fragmentPreloadedLibraries);

        void setInputPrimitiveTopology(PrimitiveTopologyClass inputPrimitiveTopology);

        void setLabel(const NS::String* label);

        void setMaxFragmentCallStackDepth(NS::UInteger maxFragmentCallStackDepth);

        void setMaxTessellationFactor(NS::UInteger maxTessellationFactor);

        void setMaxVertexAmplificationCount(NS::UInteger maxVertexAmplificationCount);

        void setMaxVertexCallStackDepth(NS::UInteger maxVertexCallStackDepth);

        void setRasterSampleCount(NS::UInteger rasterSampleCount);

        void setRasterizationEnabled(bool rasterizationEnabled);

        void setSampleCount(NS::UInteger sampleCount);

        void setShaderValidation(ShaderValidation shaderValidation);

        void setStencilAttachmentPixelFormat(PixelFormat stencilAttachmentPixelFormat);

        void setSupportAddingFragmentBinaryFunctions(bool supportAddingFragmentBinaryFunctions);

        void setSupportAddingVertexBinaryFunctions(bool supportAddingVertexBinaryFunctions);

        void setSupportIndirectCommandBuffers(bool supportIndirectCommandBuffers);

        void setTessellationControlPointIndexType(TessellationControlPointIndexType tessellationControlPointIndexType);

        void setTessellationFactorFormat(TessellationFactorFormat tessellationFactorFormat);

        void setTessellationFactorScaleEnabled(bool tessellationFactorScaleEnabled);

        void setTessellationFactorStepFunction(TessellationFactorStepFunction tessellationFactorStepFunction);

        void setTessellationOutputWindingOrder(Winding tessellationOutputWindingOrder);

        void setTessellationPartitionMode(TessellationPartitionMode tessellationPartitionMode);

        void setVertexDescriptor(const VertexDescriptor* vertexDescriptor);

        void setVertexFunction(const Function* vertexFunction);

        void setVertexLinkedFunctions(const LinkedFunctions* vertexLinkedFunctions);

        void setVertexPreloadedLibraries(const NS::Array* vertexPreloadedLibraries);

        ShaderValidation shaderValidation() const;

        PixelFormat stencilAttachmentPixelFormat() const;

        bool supportAddingFragmentBinaryFunctions() const;

        bool supportAddingVertexBinaryFunctions() const;

        bool supportIndirectCommandBuffers() const;

        TessellationControlPointIndexType tessellationControlPointIndexType() const;

        TessellationFactorFormat tessellationFactorFormat() const;

        [[deprecated("please use isTessellationFactorScaleEnabled instead")]]
        bool tessellationFactorScaleEnabled() const;

        TessellationFactorStepFunction tessellationFactorStepFunction() const;

        Winding tessellationOutputWindingOrder() const;

        TessellationPartitionMode tessellationPartitionMode() const;

        PipelineBufferDescriptorArray* vertexBuffers() const;

        VertexDescriptor* vertexDescriptor() const;

        Function* vertexFunction() const;

        LinkedFunctions* vertexLinkedFunctions() const;

        NS::Array* vertexPreloadedLibraries() const;
    };
    class RenderPipelineFunctionsDescriptor : public NS::Copying<RenderPipelineFunctionsDescriptor>
    {
    public:
        static RenderPipelineFunctionsDescriptor* alloc();

        NS::Array* fragmentAdditionalBinaryFunctions() const;

        RenderPipelineFunctionsDescriptor* init();

        void setFragmentAdditionalBinaryFunctions(const NS::Array* fragmentAdditionalBinaryFunctions);

        void setTileAdditionalBinaryFunctions(const NS::Array* tileAdditionalBinaryFunctions);

        void setVertexAdditionalBinaryFunctions(const NS::Array* vertexAdditionalBinaryFunctions);

        NS::Array* tileAdditionalBinaryFunctions() const;

        NS::Array* vertexAdditionalBinaryFunctions() const;
    };
    class RenderPipelineState : public NS::Referencing<RenderPipelineState, Allocation>
    {
    public:
        Device* device() const;

        FunctionHandle* functionHandle(const NS::String* name, RenderStages stage);
        FunctionHandle* functionHandle(const MTL4::BinaryFunction* function, RenderStages stage);
        FunctionHandle* functionHandle(const Function* function, RenderStages stage);

        ResourceID gpuResourceID() const;

        NS::UInteger imageblockMemoryLength(Size imageblockDimensions);

        NS::UInteger imageblockSampleLength() const;

        NS::String* label() const;

        NS::UInteger maxTotalThreadgroupsPerMeshGrid() const;

        NS::UInteger maxTotalThreadsPerMeshThreadgroup() const;

        NS::UInteger maxTotalThreadsPerObjectThreadgroup() const;

        NS::UInteger maxTotalThreadsPerThreadgroup() const;

        NS::UInteger meshThreadExecutionWidth() const;

        IntersectionFunctionTable* newIntersectionFunctionTable(const IntersectionFunctionTableDescriptor* descriptor,
                                                                RenderStages                               stage);

        MTL4::PipelineDescriptor* newRenderPipelineDescriptor();

        RenderPipelineState* newRenderPipelineState(
            const MTL4::RenderPipelineBinaryFunctionsDescriptor* binaryFunctionsDescriptor, NS::Error** error);
        RenderPipelineState* newRenderPipelineState(const RenderPipelineFunctionsDescriptor* additionalBinaryFunctions,
                                                    NS::Error**                              error);

        VisibleFunctionTable* newVisibleFunctionTable(const VisibleFunctionTableDescriptor* descriptor,
                                                      RenderStages                          stage);

        NS::UInteger objectThreadExecutionWidth() const;

        RenderPipelineReflection* reflection() const;

        Size requiredThreadsPerMeshThreadgroup() const;

        Size requiredThreadsPerObjectThreadgroup() const;

        Size requiredThreadsPerTileThreadgroup() const;

        ShaderValidation shaderValidation() const;

        bool supportIndirectCommandBuffers() const;

        bool threadgroupSizeMatchesTileSize() const;
    };
    class RenderPipelineColorAttachmentDescriptorArray
        : public NS::Referencing<RenderPipelineColorAttachmentDescriptorArray>
    {
    public:
        static RenderPipelineColorAttachmentDescriptorArray* alloc();

        RenderPipelineColorAttachmentDescriptorArray* init();

        RenderPipelineColorAttachmentDescriptor* object(NS::UInteger attachmentIndex);
        void setObject(const RenderPipelineColorAttachmentDescriptor* attachment, NS::UInteger attachmentIndex);
    };
    class TileRenderPipelineColorAttachmentDescriptor : public NS::Copying<TileRenderPipelineColorAttachmentDescriptor>
    {
    public:
        static TileRenderPipelineColorAttachmentDescriptor* alloc();

        TileRenderPipelineColorAttachmentDescriptor* init();

        PixelFormat pixelFormat() const;
        void        setPixelFormat(PixelFormat pixelFormat);
    };
    class TileRenderPipelineColorAttachmentDescriptorArray
        : public NS::Referencing<TileRenderPipelineColorAttachmentDescriptorArray>
    {
    public:
        static TileRenderPipelineColorAttachmentDescriptorArray* alloc();

        TileRenderPipelineColorAttachmentDescriptorArray* init();

        TileRenderPipelineColorAttachmentDescriptor* object(NS::UInteger attachmentIndex);
        void setObject(const TileRenderPipelineColorAttachmentDescriptor* attachment, NS::UInteger attachmentIndex);
    };
    class TileRenderPipelineDescriptor : public NS::Copying<TileRenderPipelineDescriptor>
    {
    public:
        static TileRenderPipelineDescriptor* alloc();

        NS::Array* binaryArchives() const;

        TileRenderPipelineColorAttachmentDescriptorArray* colorAttachments() const;

        TileRenderPipelineDescriptor* init();

        NS::String* label() const;

        LinkedFunctions* linkedFunctions() const;

        NS::UInteger maxCallStackDepth() const;

        NS::UInteger maxTotalThreadsPerThreadgroup() const;

        NS::Array* preloadedLibraries() const;

        NS::UInteger rasterSampleCount() const;

        Size requiredThreadsPerThreadgroup() const;

        void reset();

        void setBinaryArchives(const NS::Array* binaryArchives);

        void setLabel(const NS::String* label);

        void setLinkedFunctions(const LinkedFunctions* linkedFunctions);

        void setMaxCallStackDepth(NS::UInteger maxCallStackDepth);

        void setMaxTotalThreadsPerThreadgroup(NS::UInteger maxTotalThreadsPerThreadgroup);

        void setPreloadedLibraries(const NS::Array* preloadedLibraries);

        void setRasterSampleCount(NS::UInteger rasterSampleCount);

        void setRequiredThreadsPerThreadgroup(Size requiredThreadsPerThreadgroup);

        void setShaderValidation(ShaderValidation shaderValidation);

        void setSupportAddingBinaryFunctions(bool supportAddingBinaryFunctions);

        void setThreadgroupSizeMatchesTileSize(bool threadgroupSizeMatchesTileSize);

        void setTileFunction(const Function* tileFunction);

        ShaderValidation shaderValidation() const;

        bool supportAddingBinaryFunctions() const;

        bool threadgroupSizeMatchesTileSize() const;

        PipelineBufferDescriptorArray* tileBuffers() const;

        Function* tileFunction() const;
    };
    class MeshRenderPipelineDescriptor : public NS::Copying<MeshRenderPipelineDescriptor>
    {
    public:
        static MeshRenderPipelineDescriptor* alloc();

        [[deprecated("please use isAlphaToCoverageEnabled instead")]]
        bool alphaToCoverageEnabled() const;

        [[deprecated("please use isAlphaToOneEnabled instead")]]
        bool alphaToOneEnabled() const;

        NS::Array* binaryArchives() const;

        RenderPipelineColorAttachmentDescriptorArray* colorAttachments() const;

        PixelFormat depthAttachmentPixelFormat() const;

        PipelineBufferDescriptorArray* fragmentBuffers() const;

        Function* fragmentFunction() const;

        LinkedFunctions* fragmentLinkedFunctions() const;

        MeshRenderPipelineDescriptor* init();

        bool isAlphaToCoverageEnabled() const;

        bool isAlphaToOneEnabled() const;

        bool isRasterizationEnabled() const;

        NS::String* label() const;

        NS::UInteger maxTotalThreadgroupsPerMeshGrid() const;

        NS::UInteger maxTotalThreadsPerMeshThreadgroup() const;

        NS::UInteger maxTotalThreadsPerObjectThreadgroup() const;

        NS::UInteger maxVertexAmplificationCount() const;

        PipelineBufferDescriptorArray* meshBuffers() const;

        Function* meshFunction() const;

        LinkedFunctions* meshLinkedFunctions() const;

        bool meshThreadgroupSizeIsMultipleOfThreadExecutionWidth() const;

        PipelineBufferDescriptorArray* objectBuffers() const;

        Function* objectFunction() const;

        LinkedFunctions* objectLinkedFunctions() const;

        bool objectThreadgroupSizeIsMultipleOfThreadExecutionWidth() const;

        NS::UInteger payloadMemoryLength() const;

        NS::UInteger rasterSampleCount() const;

        [[deprecated("please use isRasterizationEnabled instead")]]
        bool rasterizationEnabled() const;

        Size requiredThreadsPerMeshThreadgroup() const;

        Size requiredThreadsPerObjectThreadgroup() const;

        void reset();

        void setAlphaToCoverageEnabled(bool alphaToCoverageEnabled);

        void setAlphaToOneEnabled(bool alphaToOneEnabled);

        void setBinaryArchives(const NS::Array* binaryArchives);

        void setDepthAttachmentPixelFormat(PixelFormat depthAttachmentPixelFormat);

        void setFragmentFunction(const Function* fragmentFunction);

        void setFragmentLinkedFunctions(const LinkedFunctions* fragmentLinkedFunctions);

        void setLabel(const NS::String* label);

        void setMaxTotalThreadgroupsPerMeshGrid(NS::UInteger maxTotalThreadgroupsPerMeshGrid);

        void setMaxTotalThreadsPerMeshThreadgroup(NS::UInteger maxTotalThreadsPerMeshThreadgroup);

        void setMaxTotalThreadsPerObjectThreadgroup(NS::UInteger maxTotalThreadsPerObjectThreadgroup);

        void setMaxVertexAmplificationCount(NS::UInteger maxVertexAmplificationCount);

        void setMeshFunction(const Function* meshFunction);

        void setMeshLinkedFunctions(const LinkedFunctions* meshLinkedFunctions);

        void setMeshThreadgroupSizeIsMultipleOfThreadExecutionWidth(
            bool meshThreadgroupSizeIsMultipleOfThreadExecutionWidth);

        void setObjectFunction(const Function* objectFunction);

        void setObjectLinkedFunctions(const LinkedFunctions* objectLinkedFunctions);

        void setObjectThreadgroupSizeIsMultipleOfThreadExecutionWidth(
            bool objectThreadgroupSizeIsMultipleOfThreadExecutionWidth);

        void setPayloadMemoryLength(NS::UInteger payloadMemoryLength);

        void setRasterSampleCount(NS::UInteger rasterSampleCount);

        void setRasterizationEnabled(bool rasterizationEnabled);

        void setRequiredThreadsPerMeshThreadgroup(Size requiredThreadsPerMeshThreadgroup);

        void setRequiredThreadsPerObjectThreadgroup(Size requiredThreadsPerObjectThreadgroup);

        void setShaderValidation(ShaderValidation shaderValidation);

        void setStencilAttachmentPixelFormat(PixelFormat stencilAttachmentPixelFormat);

        void setSupportIndirectCommandBuffers(bool supportIndirectCommandBuffers);

        ShaderValidation shaderValidation() const;

        PixelFormat stencilAttachmentPixelFormat() const;

        bool supportIndirectCommandBuffers() const;
    };

} // namespace MTL
_MTL_INLINE MTL::RenderPipelineColorAttachmentDescriptor* MTL::RenderPipelineColorAttachmentDescriptor::alloc()
{
    return alloc<RenderPipelineColorAttachmentDescriptor>(_MTL_PRIVATE_CLS(MTLRenderPipelineColorAttachmentDescriptor));
}

_MTL_INLINE MTL::BlendOperation MTL::RenderPipelineColorAttachmentDescriptor::alphaBlendOperation() const
{
    return sendMessage<BlendOperation>(this, _MTL_PRIVATE_SEL(alphaBlendOperation));
}

_MTL_INLINE bool MTL::RenderPipelineColorAttachmentDescriptor::blendingEnabled() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isBlendingEnabled));
}

_MTL_INLINE MTL::BlendFactor MTL::RenderPipelineColorAttachmentDescriptor::destinationAlphaBlendFactor() const
{
    return sendMessage<BlendFactor>(this, _MTL_PRIVATE_SEL(destinationAlphaBlendFactor));
}

_MTL_INLINE MTL::BlendFactor MTL::RenderPipelineColorAttachmentDescriptor::destinationRGBBlendFactor() const
{
    return sendMessage<BlendFactor>(this, _MTL_PRIVATE_SEL(destinationRGBBlendFactor));
}

_MTL_INLINE MTL::RenderPipelineColorAttachmentDescriptor* MTL::RenderPipelineColorAttachmentDescriptor::init()
{
    return init<RenderPipelineColorAttachmentDescriptor>();
}

_MTL_INLINE bool MTL::RenderPipelineColorAttachmentDescriptor::isBlendingEnabled() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isBlendingEnabled));
}

_MTL_INLINE MTL::PixelFormat MTL::RenderPipelineColorAttachmentDescriptor::pixelFormat() const
{
    return sendMessage<PixelFormat>(this, _MTL_PRIVATE_SEL(pixelFormat));
}

_MTL_INLINE MTL::BlendOperation MTL::RenderPipelineColorAttachmentDescriptor::rgbBlendOperation() const
{
    return sendMessage<BlendOperation>(this, _MTL_PRIVATE_SEL(rgbBlendOperation));
}

_MTL_INLINE void MTL::RenderPipelineColorAttachmentDescriptor::setAlphaBlendOperation(
    BlendOperation alphaBlendOperation)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setAlphaBlendOperation_), alphaBlendOperation);
}

_MTL_INLINE void MTL::RenderPipelineColorAttachmentDescriptor::setBlendingEnabled(bool blendingEnabled)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBlendingEnabled_), blendingEnabled);
}

_MTL_INLINE void MTL::RenderPipelineColorAttachmentDescriptor::setDestinationAlphaBlendFactor(
    BlendFactor destinationAlphaBlendFactor)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDestinationAlphaBlendFactor_), destinationAlphaBlendFactor);
}

_MTL_INLINE void MTL::RenderPipelineColorAttachmentDescriptor::setDestinationRGBBlendFactor(
    BlendFactor destinationRGBBlendFactor)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDestinationRGBBlendFactor_), destinationRGBBlendFactor);
}

_MTL_INLINE void MTL::RenderPipelineColorAttachmentDescriptor::setPixelFormat(PixelFormat pixelFormat)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setPixelFormat_), pixelFormat);
}

_MTL_INLINE void MTL::RenderPipelineColorAttachmentDescriptor::setRgbBlendOperation(BlendOperation rgbBlendOperation)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRgbBlendOperation_), rgbBlendOperation);
}

_MTL_INLINE void MTL::RenderPipelineColorAttachmentDescriptor::setSourceAlphaBlendFactor(
    BlendFactor sourceAlphaBlendFactor)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSourceAlphaBlendFactor_), sourceAlphaBlendFactor);
}

_MTL_INLINE void MTL::RenderPipelineColorAttachmentDescriptor::setSourceRGBBlendFactor(BlendFactor sourceRGBBlendFactor)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSourceRGBBlendFactor_), sourceRGBBlendFactor);
}

_MTL_INLINE void MTL::RenderPipelineColorAttachmentDescriptor::setWriteMask(ColorWriteMask writeMask)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setWriteMask_), writeMask);
}

_MTL_INLINE MTL::BlendFactor MTL::RenderPipelineColorAttachmentDescriptor::sourceAlphaBlendFactor() const
{
    return sendMessage<BlendFactor>(this, _MTL_PRIVATE_SEL(sourceAlphaBlendFactor));
}

_MTL_INLINE MTL::BlendFactor MTL::RenderPipelineColorAttachmentDescriptor::sourceRGBBlendFactor() const
{
    return sendMessage<BlendFactor>(this, _MTL_PRIVATE_SEL(sourceRGBBlendFactor));
}

_MTL_INLINE MTL::ColorWriteMask MTL::RenderPipelineColorAttachmentDescriptor::writeMask() const
{
    return sendMessage<ColorWriteMask>(this, _MTL_PRIVATE_SEL(writeMask));
}

_MTL_INLINE MTL::LogicalToPhysicalColorAttachmentMap* MTL::LogicalToPhysicalColorAttachmentMap::alloc()
{
    return alloc<LogicalToPhysicalColorAttachmentMap>(_MTL_PRIVATE_CLS(MTLLogicalToPhysicalColorAttachmentMap));
}

_MTL_INLINE NS::UInteger MTL::LogicalToPhysicalColorAttachmentMap::getPhysicalIndex(NS::UInteger logicalIndex)
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(getPhysicalIndexForLogicalIndex_), logicalIndex);
}

_MTL_INLINE MTL::LogicalToPhysicalColorAttachmentMap* MTL::LogicalToPhysicalColorAttachmentMap::init()
{
    return init<LogicalToPhysicalColorAttachmentMap>();
}

_MTL_INLINE void MTL::LogicalToPhysicalColorAttachmentMap::reset() { sendMessage<void>(this, _MTL_PRIVATE_SEL(reset)); }

_MTL_INLINE void MTL::LogicalToPhysicalColorAttachmentMap::setPhysicalIndex(NS::UInteger physicalIndex,
                                                                            NS::UInteger logicalIndex)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setPhysicalIndex_forLogicalIndex_), physicalIndex, logicalIndex);
}

_MTL_INLINE MTL::RenderPipelineReflection* MTL::RenderPipelineReflection::alloc()
{
    return alloc<RenderPipelineReflection>(_MTL_PRIVATE_CLS(MTLRenderPipelineReflection));
}

_MTL_INLINE NS::Array* MTL::RenderPipelineReflection::fragmentArguments() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(fragmentArguments));
}

_MTL_INLINE NS::Array* MTL::RenderPipelineReflection::fragmentBindings() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(fragmentBindings));
}

_MTL_INLINE MTL::RenderPipelineReflection* MTL::RenderPipelineReflection::init()
{
    return init<RenderPipelineReflection>();
}

_MTL_INLINE NS::Array* MTL::RenderPipelineReflection::meshBindings() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(meshBindings));
}

_MTL_INLINE NS::Array* MTL::RenderPipelineReflection::objectBindings() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(objectBindings));
}

_MTL_INLINE NS::Array* MTL::RenderPipelineReflection::tileArguments() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(tileArguments));
}

_MTL_INLINE NS::Array* MTL::RenderPipelineReflection::tileBindings() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(tileBindings));
}

_MTL_INLINE NS::Array* MTL::RenderPipelineReflection::vertexArguments() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(vertexArguments));
}

_MTL_INLINE NS::Array* MTL::RenderPipelineReflection::vertexBindings() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(vertexBindings));
}

_MTL_INLINE MTL::RenderPipelineDescriptor* MTL::RenderPipelineDescriptor::alloc()
{
    return alloc<RenderPipelineDescriptor>(_MTL_PRIVATE_CLS(MTLRenderPipelineDescriptor));
}

_MTL_INLINE bool MTL::RenderPipelineDescriptor::alphaToCoverageEnabled() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isAlphaToCoverageEnabled));
}

_MTL_INLINE bool MTL::RenderPipelineDescriptor::alphaToOneEnabled() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isAlphaToOneEnabled));
}

_MTL_INLINE NS::Array* MTL::RenderPipelineDescriptor::binaryArchives() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(binaryArchives));
}

_MTL_INLINE MTL::RenderPipelineColorAttachmentDescriptorArray* MTL::RenderPipelineDescriptor::colorAttachments() const
{
    return sendMessage<RenderPipelineColorAttachmentDescriptorArray*>(this, _MTL_PRIVATE_SEL(colorAttachments));
}

_MTL_INLINE MTL::PixelFormat MTL::RenderPipelineDescriptor::depthAttachmentPixelFormat() const
{
    return sendMessage<PixelFormat>(this, _MTL_PRIVATE_SEL(depthAttachmentPixelFormat));
}

_MTL_INLINE MTL::PipelineBufferDescriptorArray* MTL::RenderPipelineDescriptor::fragmentBuffers() const
{
    return sendMessage<PipelineBufferDescriptorArray*>(this, _MTL_PRIVATE_SEL(fragmentBuffers));
}

_MTL_INLINE MTL::Function* MTL::RenderPipelineDescriptor::fragmentFunction() const
{
    return sendMessage<Function*>(this, _MTL_PRIVATE_SEL(fragmentFunction));
}

_MTL_INLINE MTL::LinkedFunctions* MTL::RenderPipelineDescriptor::fragmentLinkedFunctions() const
{
    return sendMessage<LinkedFunctions*>(this, _MTL_PRIVATE_SEL(fragmentLinkedFunctions));
}

_MTL_INLINE NS::Array* MTL::RenderPipelineDescriptor::fragmentPreloadedLibraries() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(fragmentPreloadedLibraries));
}

_MTL_INLINE MTL::RenderPipelineDescriptor* MTL::RenderPipelineDescriptor::init()
{
    return init<RenderPipelineDescriptor>();
}

_MTL_INLINE MTL::PrimitiveTopologyClass MTL::RenderPipelineDescriptor::inputPrimitiveTopology() const
{
    return sendMessage<PrimitiveTopologyClass>(this, _MTL_PRIVATE_SEL(inputPrimitiveTopology));
}

_MTL_INLINE bool MTL::RenderPipelineDescriptor::isAlphaToCoverageEnabled() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isAlphaToCoverageEnabled));
}

_MTL_INLINE bool MTL::RenderPipelineDescriptor::isAlphaToOneEnabled() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isAlphaToOneEnabled));
}

_MTL_INLINE bool MTL::RenderPipelineDescriptor::isRasterizationEnabled() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isRasterizationEnabled));
}

_MTL_INLINE bool MTL::RenderPipelineDescriptor::isTessellationFactorScaleEnabled() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isTessellationFactorScaleEnabled));
}

_MTL_INLINE NS::String* MTL::RenderPipelineDescriptor::label() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
}

_MTL_INLINE NS::UInteger MTL::RenderPipelineDescriptor::maxFragmentCallStackDepth() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxFragmentCallStackDepth));
}

_MTL_INLINE NS::UInteger MTL::RenderPipelineDescriptor::maxTessellationFactor() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxTessellationFactor));
}

_MTL_INLINE NS::UInteger MTL::RenderPipelineDescriptor::maxVertexAmplificationCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxVertexAmplificationCount));
}

_MTL_INLINE NS::UInteger MTL::RenderPipelineDescriptor::maxVertexCallStackDepth() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxVertexCallStackDepth));
}

_MTL_INLINE NS::UInteger MTL::RenderPipelineDescriptor::rasterSampleCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(rasterSampleCount));
}

_MTL_INLINE bool MTL::RenderPipelineDescriptor::rasterizationEnabled() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isRasterizationEnabled));
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::reset() { sendMessage<void>(this, _MTL_PRIVATE_SEL(reset)); }

_MTL_INLINE NS::UInteger MTL::RenderPipelineDescriptor::sampleCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(sampleCount));
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setAlphaToCoverageEnabled(bool alphaToCoverageEnabled)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setAlphaToCoverageEnabled_), alphaToCoverageEnabled);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setAlphaToOneEnabled(bool alphaToOneEnabled)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setAlphaToOneEnabled_), alphaToOneEnabled);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setBinaryArchives(const NS::Array* binaryArchives)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBinaryArchives_), binaryArchives);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setDepthAttachmentPixelFormat(PixelFormat depthAttachmentPixelFormat)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDepthAttachmentPixelFormat_), depthAttachmentPixelFormat);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setFragmentFunction(const Function* fragmentFunction)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFragmentFunction_), fragmentFunction);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setFragmentLinkedFunctions(
    const LinkedFunctions* fragmentLinkedFunctions)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFragmentLinkedFunctions_), fragmentLinkedFunctions);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setFragmentPreloadedLibraries(
    const NS::Array* fragmentPreloadedLibraries)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFragmentPreloadedLibraries_), fragmentPreloadedLibraries);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setInputPrimitiveTopology(PrimitiveTopologyClass inputPrimitiveTopology)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setInputPrimitiveTopology_), inputPrimitiveTopology);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setLabel(const NS::String* label)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLabel_), label);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setMaxFragmentCallStackDepth(NS::UInteger maxFragmentCallStackDepth)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxFragmentCallStackDepth_), maxFragmentCallStackDepth);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setMaxTessellationFactor(NS::UInteger maxTessellationFactor)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxTessellationFactor_), maxTessellationFactor);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setMaxVertexAmplificationCount(NS::UInteger maxVertexAmplificationCount)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxVertexAmplificationCount_), maxVertexAmplificationCount);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setMaxVertexCallStackDepth(NS::UInteger maxVertexCallStackDepth)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxVertexCallStackDepth_), maxVertexCallStackDepth);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setRasterSampleCount(NS::UInteger rasterSampleCount)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRasterSampleCount_), rasterSampleCount);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setRasterizationEnabled(bool rasterizationEnabled)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRasterizationEnabled_), rasterizationEnabled);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setSampleCount(NS::UInteger sampleCount)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSampleCount_), sampleCount);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setShaderValidation(ShaderValidation shaderValidation)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setShaderValidation_), shaderValidation);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setStencilAttachmentPixelFormat(
    PixelFormat stencilAttachmentPixelFormat)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setStencilAttachmentPixelFormat_), stencilAttachmentPixelFormat);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setSupportAddingFragmentBinaryFunctions(
    bool supportAddingFragmentBinaryFunctions)
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setSupportAddingFragmentBinaryFunctions_), supportAddingFragmentBinaryFunctions);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setSupportAddingVertexBinaryFunctions(
    bool supportAddingVertexBinaryFunctions)
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setSupportAddingVertexBinaryFunctions_), supportAddingVertexBinaryFunctions);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setSupportIndirectCommandBuffers(bool supportIndirectCommandBuffers)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSupportIndirectCommandBuffers_), supportIndirectCommandBuffers);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setTessellationControlPointIndexType(
    TessellationControlPointIndexType tessellationControlPointIndexType)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTessellationControlPointIndexType_), tessellationControlPointIndexType);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setTessellationFactorFormat(
    TessellationFactorFormat tessellationFactorFormat)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTessellationFactorFormat_), tessellationFactorFormat);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setTessellationFactorScaleEnabled(bool tessellationFactorScaleEnabled)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTessellationFactorScaleEnabled_), tessellationFactorScaleEnabled);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setTessellationFactorStepFunction(
    TessellationFactorStepFunction tessellationFactorStepFunction)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTessellationFactorStepFunction_), tessellationFactorStepFunction);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setTessellationOutputWindingOrder(
    Winding tessellationOutputWindingOrder)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTessellationOutputWindingOrder_), tessellationOutputWindingOrder);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setTessellationPartitionMode(
    TessellationPartitionMode tessellationPartitionMode)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTessellationPartitionMode_), tessellationPartitionMode);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setVertexDescriptor(const VertexDescriptor* vertexDescriptor)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVertexDescriptor_), vertexDescriptor);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setVertexFunction(const Function* vertexFunction)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVertexFunction_), vertexFunction);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setVertexLinkedFunctions(const LinkedFunctions* vertexLinkedFunctions)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVertexLinkedFunctions_), vertexLinkedFunctions);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setVertexPreloadedLibraries(const NS::Array* vertexPreloadedLibraries)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVertexPreloadedLibraries_), vertexPreloadedLibraries);
}

_MTL_INLINE MTL::ShaderValidation MTL::RenderPipelineDescriptor::shaderValidation() const
{
    return sendMessage<ShaderValidation>(this, _MTL_PRIVATE_SEL(shaderValidation));
}

_MTL_INLINE MTL::PixelFormat MTL::RenderPipelineDescriptor::stencilAttachmentPixelFormat() const
{
    return sendMessage<PixelFormat>(this, _MTL_PRIVATE_SEL(stencilAttachmentPixelFormat));
}

_MTL_INLINE bool MTL::RenderPipelineDescriptor::supportAddingFragmentBinaryFunctions() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supportAddingFragmentBinaryFunctions));
}

_MTL_INLINE bool MTL::RenderPipelineDescriptor::supportAddingVertexBinaryFunctions() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supportAddingVertexBinaryFunctions));
}

_MTL_INLINE bool MTL::RenderPipelineDescriptor::supportIndirectCommandBuffers() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supportIndirectCommandBuffers));
}

_MTL_INLINE MTL::TessellationControlPointIndexType MTL::RenderPipelineDescriptor::tessellationControlPointIndexType()
    const
{
    return sendMessage<TessellationControlPointIndexType>(this, _MTL_PRIVATE_SEL(tessellationControlPointIndexType));
}

_MTL_INLINE MTL::TessellationFactorFormat MTL::RenderPipelineDescriptor::tessellationFactorFormat() const
{
    return sendMessage<TessellationFactorFormat>(this, _MTL_PRIVATE_SEL(tessellationFactorFormat));
}

_MTL_INLINE bool MTL::RenderPipelineDescriptor::tessellationFactorScaleEnabled() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isTessellationFactorScaleEnabled));
}

_MTL_INLINE MTL::TessellationFactorStepFunction MTL::RenderPipelineDescriptor::tessellationFactorStepFunction() const
{
    return sendMessage<TessellationFactorStepFunction>(this, _MTL_PRIVATE_SEL(tessellationFactorStepFunction));
}

_MTL_INLINE MTL::Winding MTL::RenderPipelineDescriptor::tessellationOutputWindingOrder() const
{
    return sendMessage<Winding>(this, _MTL_PRIVATE_SEL(tessellationOutputWindingOrder));
}

_MTL_INLINE MTL::TessellationPartitionMode MTL::RenderPipelineDescriptor::tessellationPartitionMode() const
{
    return sendMessage<TessellationPartitionMode>(this, _MTL_PRIVATE_SEL(tessellationPartitionMode));
}

_MTL_INLINE MTL::PipelineBufferDescriptorArray* MTL::RenderPipelineDescriptor::vertexBuffers() const
{
    return sendMessage<PipelineBufferDescriptorArray*>(this, _MTL_PRIVATE_SEL(vertexBuffers));
}

_MTL_INLINE MTL::VertexDescriptor* MTL::RenderPipelineDescriptor::vertexDescriptor() const
{
    return sendMessage<VertexDescriptor*>(this, _MTL_PRIVATE_SEL(vertexDescriptor));
}

_MTL_INLINE MTL::Function* MTL::RenderPipelineDescriptor::vertexFunction() const
{
    return sendMessage<Function*>(this, _MTL_PRIVATE_SEL(vertexFunction));
}

_MTL_INLINE MTL::LinkedFunctions* MTL::RenderPipelineDescriptor::vertexLinkedFunctions() const
{
    return sendMessage<LinkedFunctions*>(this, _MTL_PRIVATE_SEL(vertexLinkedFunctions));
}

_MTL_INLINE NS::Array* MTL::RenderPipelineDescriptor::vertexPreloadedLibraries() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(vertexPreloadedLibraries));
}

_MTL_INLINE MTL::RenderPipelineFunctionsDescriptor* MTL::RenderPipelineFunctionsDescriptor::alloc()
{
    return alloc<RenderPipelineFunctionsDescriptor>(_MTL_PRIVATE_CLS(MTLRenderPipelineFunctionsDescriptor));
}

_MTL_INLINE NS::Array* MTL::RenderPipelineFunctionsDescriptor::fragmentAdditionalBinaryFunctions() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(fragmentAdditionalBinaryFunctions));
}

_MTL_INLINE MTL::RenderPipelineFunctionsDescriptor* MTL::RenderPipelineFunctionsDescriptor::init()
{
    return init<RenderPipelineFunctionsDescriptor>();
}

_MTL_INLINE void MTL::RenderPipelineFunctionsDescriptor::setFragmentAdditionalBinaryFunctions(
    const NS::Array* fragmentAdditionalBinaryFunctions)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFragmentAdditionalBinaryFunctions_), fragmentAdditionalBinaryFunctions);
}

_MTL_INLINE void MTL::RenderPipelineFunctionsDescriptor::setTileAdditionalBinaryFunctions(
    const NS::Array* tileAdditionalBinaryFunctions)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTileAdditionalBinaryFunctions_), tileAdditionalBinaryFunctions);
}

_MTL_INLINE void MTL::RenderPipelineFunctionsDescriptor::setVertexAdditionalBinaryFunctions(
    const NS::Array* vertexAdditionalBinaryFunctions)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVertexAdditionalBinaryFunctions_), vertexAdditionalBinaryFunctions);
}

_MTL_INLINE NS::Array* MTL::RenderPipelineFunctionsDescriptor::tileAdditionalBinaryFunctions() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(tileAdditionalBinaryFunctions));
}

_MTL_INLINE NS::Array* MTL::RenderPipelineFunctionsDescriptor::vertexAdditionalBinaryFunctions() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(vertexAdditionalBinaryFunctions));
}

_MTL_INLINE MTL::Device* MTL::RenderPipelineState::device() const
{
    return sendMessage<Device*>(this, _MTL_PRIVATE_SEL(device));
}

_MTL_INLINE MTL::FunctionHandle* MTL::RenderPipelineState::functionHandle(const NS::String* name, RenderStages stage)
{
    return sendMessage<FunctionHandle*>(this, _MTL_PRIVATE_SEL(functionHandleWithName_stage_), name, stage);
}

_MTL_INLINE MTL::FunctionHandle* MTL::RenderPipelineState::functionHandle(const MTL4::BinaryFunction* function,
                                                                          RenderStages                stage)
{
    return sendMessage<FunctionHandle*>(
        this, _MTL_PRIVATE_SEL(functionHandleWithBinaryFunction_stage_), function, stage);
}

_MTL_INLINE MTL::FunctionHandle* MTL::RenderPipelineState::functionHandle(const Function* function, RenderStages stage)
{
    return sendMessage<FunctionHandle*>(this, _MTL_PRIVATE_SEL(functionHandleWithFunction_stage_), function, stage);
}

_MTL_INLINE MTL::ResourceID MTL::RenderPipelineState::gpuResourceID() const
{
    return sendMessage<ResourceID>(this, _MTL_PRIVATE_SEL(gpuResourceID));
}

_MTL_INLINE NS::UInteger MTL::RenderPipelineState::imageblockMemoryLength(Size imageblockDimensions)
{
    return sendMessage<NS::UInteger>(
        this, _MTL_PRIVATE_SEL(imageblockMemoryLengthForDimensions_), imageblockDimensions);
}

_MTL_INLINE NS::UInteger MTL::RenderPipelineState::imageblockSampleLength() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(imageblockSampleLength));
}

_MTL_INLINE NS::String* MTL::RenderPipelineState::label() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
}

_MTL_INLINE NS::UInteger MTL::RenderPipelineState::maxTotalThreadgroupsPerMeshGrid() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxTotalThreadgroupsPerMeshGrid));
}

_MTL_INLINE NS::UInteger MTL::RenderPipelineState::maxTotalThreadsPerMeshThreadgroup() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxTotalThreadsPerMeshThreadgroup));
}

_MTL_INLINE NS::UInteger MTL::RenderPipelineState::maxTotalThreadsPerObjectThreadgroup() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxTotalThreadsPerObjectThreadgroup));
}

_MTL_INLINE NS::UInteger MTL::RenderPipelineState::maxTotalThreadsPerThreadgroup() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxTotalThreadsPerThreadgroup));
}

_MTL_INLINE NS::UInteger MTL::RenderPipelineState::meshThreadExecutionWidth() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(meshThreadExecutionWidth));
}

_MTL_INLINE MTL::IntersectionFunctionTable* MTL::RenderPipelineState::newIntersectionFunctionTable(
    const IntersectionFunctionTableDescriptor* descriptor, RenderStages stage)
{
    return sendMessage<IntersectionFunctionTable*>(
        this, _MTL_PRIVATE_SEL(newIntersectionFunctionTableWithDescriptor_stage_), descriptor, stage);
}

_MTL_INLINE MTL4::PipelineDescriptor* MTL::RenderPipelineState::newRenderPipelineDescriptor()
{
    return sendMessage<MTL4::PipelineDescriptor*>(this, _MTL_PRIVATE_SEL(newRenderPipelineDescriptorForSpecialization));
}

_MTL_INLINE MTL::RenderPipelineState* MTL::RenderPipelineState::newRenderPipelineState(
    const MTL4::RenderPipelineBinaryFunctionsDescriptor* binaryFunctionsDescriptor, NS::Error** error)
{
    return sendMessage<RenderPipelineState*>(
        this, _MTL_PRIVATE_SEL(newRenderPipelineStateWithBinaryFunctions_error_), binaryFunctionsDescriptor, error);
}

_MTL_INLINE MTL::RenderPipelineState* MTL::RenderPipelineState::newRenderPipelineState(
    const RenderPipelineFunctionsDescriptor* additionalBinaryFunctions, NS::Error** error)
{
    return sendMessage<RenderPipelineState*>(
        this,
        _MTL_PRIVATE_SEL(newRenderPipelineStateWithAdditionalBinaryFunctions_error_),
        additionalBinaryFunctions,
        error);
}

_MTL_INLINE MTL::VisibleFunctionTable* MTL::RenderPipelineState::newVisibleFunctionTable(
    const VisibleFunctionTableDescriptor* descriptor, RenderStages stage)
{
    return sendMessage<VisibleFunctionTable*>(
        this, _MTL_PRIVATE_SEL(newVisibleFunctionTableWithDescriptor_stage_), descriptor, stage);
}

_MTL_INLINE NS::UInteger MTL::RenderPipelineState::objectThreadExecutionWidth() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(objectThreadExecutionWidth));
}

_MTL_INLINE MTL::RenderPipelineReflection* MTL::RenderPipelineState::reflection() const
{
    return sendMessage<RenderPipelineReflection*>(this, _MTL_PRIVATE_SEL(reflection));
}

_MTL_INLINE MTL::Size MTL::RenderPipelineState::requiredThreadsPerMeshThreadgroup() const
{
    return sendMessage<Size>(this, _MTL_PRIVATE_SEL(requiredThreadsPerMeshThreadgroup));
}

_MTL_INLINE MTL::Size MTL::RenderPipelineState::requiredThreadsPerObjectThreadgroup() const
{
    return sendMessage<Size>(this, _MTL_PRIVATE_SEL(requiredThreadsPerObjectThreadgroup));
}

_MTL_INLINE MTL::Size MTL::RenderPipelineState::requiredThreadsPerTileThreadgroup() const
{
    return sendMessage<Size>(this, _MTL_PRIVATE_SEL(requiredThreadsPerTileThreadgroup));
}

_MTL_INLINE MTL::ShaderValidation MTL::RenderPipelineState::shaderValidation() const
{
    return sendMessage<ShaderValidation>(this, _MTL_PRIVATE_SEL(shaderValidation));
}

_MTL_INLINE bool MTL::RenderPipelineState::supportIndirectCommandBuffers() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supportIndirectCommandBuffers));
}

_MTL_INLINE bool MTL::RenderPipelineState::threadgroupSizeMatchesTileSize() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(threadgroupSizeMatchesTileSize));
}

_MTL_INLINE MTL::RenderPipelineColorAttachmentDescriptorArray*
            MTL::RenderPipelineColorAttachmentDescriptorArray::alloc()
{
    return alloc<RenderPipelineColorAttachmentDescriptorArray>(
        _MTL_PRIVATE_CLS(MTLRenderPipelineColorAttachmentDescriptorArray));
}

_MTL_INLINE MTL::RenderPipelineColorAttachmentDescriptorArray* MTL::RenderPipelineColorAttachmentDescriptorArray::init()
{
    return init<RenderPipelineColorAttachmentDescriptorArray>();
}

_MTL_INLINE MTL::RenderPipelineColorAttachmentDescriptor* MTL::RenderPipelineColorAttachmentDescriptorArray::object(
    NS::UInteger attachmentIndex)
{
    return sendMessage<RenderPipelineColorAttachmentDescriptor*>(
        this, _MTL_PRIVATE_SEL(objectAtIndexedSubscript_), attachmentIndex);
}

_MTL_INLINE void MTL::RenderPipelineColorAttachmentDescriptorArray::setObject(
    const RenderPipelineColorAttachmentDescriptor* attachment, NS::UInteger attachmentIndex)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setObject_atIndexedSubscript_), attachment, attachmentIndex);
}

_MTL_INLINE MTL::TileRenderPipelineColorAttachmentDescriptor* MTL::TileRenderPipelineColorAttachmentDescriptor::alloc()
{
    return alloc<TileRenderPipelineColorAttachmentDescriptor>(
        _MTL_PRIVATE_CLS(MTLTileRenderPipelineColorAttachmentDescriptor));
}

_MTL_INLINE MTL::TileRenderPipelineColorAttachmentDescriptor* MTL::TileRenderPipelineColorAttachmentDescriptor::init()
{
    return init<TileRenderPipelineColorAttachmentDescriptor>();
}

_MTL_INLINE MTL::PixelFormat MTL::TileRenderPipelineColorAttachmentDescriptor::pixelFormat() const
{
    return sendMessage<PixelFormat>(this, _MTL_PRIVATE_SEL(pixelFormat));
}

_MTL_INLINE void MTL::TileRenderPipelineColorAttachmentDescriptor::setPixelFormat(PixelFormat pixelFormat)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setPixelFormat_), pixelFormat);
}

_MTL_INLINE MTL::TileRenderPipelineColorAttachmentDescriptorArray*
            MTL::TileRenderPipelineColorAttachmentDescriptorArray::alloc()
{
    return alloc<TileRenderPipelineColorAttachmentDescriptorArray>(
        _MTL_PRIVATE_CLS(MTLTileRenderPipelineColorAttachmentDescriptorArray));
}

_MTL_INLINE MTL::TileRenderPipelineColorAttachmentDescriptorArray*
            MTL::TileRenderPipelineColorAttachmentDescriptorArray::init()
{
    return init<TileRenderPipelineColorAttachmentDescriptorArray>();
}

_MTL_INLINE MTL::TileRenderPipelineColorAttachmentDescriptor*
            MTL::TileRenderPipelineColorAttachmentDescriptorArray::object(NS::UInteger attachmentIndex)
{
    return sendMessage<TileRenderPipelineColorAttachmentDescriptor*>(
        this, _MTL_PRIVATE_SEL(objectAtIndexedSubscript_), attachmentIndex);
}

_MTL_INLINE void MTL::TileRenderPipelineColorAttachmentDescriptorArray::setObject(
    const TileRenderPipelineColorAttachmentDescriptor* attachment, NS::UInteger attachmentIndex)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setObject_atIndexedSubscript_), attachment, attachmentIndex);
}

_MTL_INLINE MTL::TileRenderPipelineDescriptor* MTL::TileRenderPipelineDescriptor::alloc()
{
    return alloc<TileRenderPipelineDescriptor>(_MTL_PRIVATE_CLS(MTLTileRenderPipelineDescriptor));
}

_MTL_INLINE NS::Array* MTL::TileRenderPipelineDescriptor::binaryArchives() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(binaryArchives));
}

_MTL_INLINE MTL::TileRenderPipelineColorAttachmentDescriptorArray* MTL::TileRenderPipelineDescriptor::colorAttachments()
    const
{
    return sendMessage<TileRenderPipelineColorAttachmentDescriptorArray*>(this, _MTL_PRIVATE_SEL(colorAttachments));
}

_MTL_INLINE MTL::TileRenderPipelineDescriptor* MTL::TileRenderPipelineDescriptor::init()
{
    return init<TileRenderPipelineDescriptor>();
}

_MTL_INLINE NS::String* MTL::TileRenderPipelineDescriptor::label() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
}

_MTL_INLINE MTL::LinkedFunctions* MTL::TileRenderPipelineDescriptor::linkedFunctions() const
{
    return sendMessage<LinkedFunctions*>(this, _MTL_PRIVATE_SEL(linkedFunctions));
}

_MTL_INLINE NS::UInteger MTL::TileRenderPipelineDescriptor::maxCallStackDepth() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxCallStackDepth));
}

_MTL_INLINE NS::UInteger MTL::TileRenderPipelineDescriptor::maxTotalThreadsPerThreadgroup() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxTotalThreadsPerThreadgroup));
}

_MTL_INLINE NS::Array* MTL::TileRenderPipelineDescriptor::preloadedLibraries() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(preloadedLibraries));
}

_MTL_INLINE NS::UInteger MTL::TileRenderPipelineDescriptor::rasterSampleCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(rasterSampleCount));
}

_MTL_INLINE MTL::Size MTL::TileRenderPipelineDescriptor::requiredThreadsPerThreadgroup() const
{
    return sendMessage<Size>(this, _MTL_PRIVATE_SEL(requiredThreadsPerThreadgroup));
}

_MTL_INLINE void MTL::TileRenderPipelineDescriptor::reset() { sendMessage<void>(this, _MTL_PRIVATE_SEL(reset)); }

_MTL_INLINE void MTL::TileRenderPipelineDescriptor::setBinaryArchives(const NS::Array* binaryArchives)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBinaryArchives_), binaryArchives);
}

_MTL_INLINE void MTL::TileRenderPipelineDescriptor::setLabel(const NS::String* label)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLabel_), label);
}

_MTL_INLINE void MTL::TileRenderPipelineDescriptor::setLinkedFunctions(const LinkedFunctions* linkedFunctions)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLinkedFunctions_), linkedFunctions);
}

_MTL_INLINE void MTL::TileRenderPipelineDescriptor::setMaxCallStackDepth(NS::UInteger maxCallStackDepth)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxCallStackDepth_), maxCallStackDepth);
}

_MTL_INLINE void MTL::TileRenderPipelineDescriptor::setMaxTotalThreadsPerThreadgroup(
    NS::UInteger maxTotalThreadsPerThreadgroup)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxTotalThreadsPerThreadgroup_), maxTotalThreadsPerThreadgroup);
}

_MTL_INLINE void MTL::TileRenderPipelineDescriptor::setPreloadedLibraries(const NS::Array* preloadedLibraries)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setPreloadedLibraries_), preloadedLibraries);
}

_MTL_INLINE void MTL::TileRenderPipelineDescriptor::setRasterSampleCount(NS::UInteger rasterSampleCount)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRasterSampleCount_), rasterSampleCount);
}

_MTL_INLINE void MTL::TileRenderPipelineDescriptor::setRequiredThreadsPerThreadgroup(Size requiredThreadsPerThreadgroup)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRequiredThreadsPerThreadgroup_), requiredThreadsPerThreadgroup);
}

_MTL_INLINE void MTL::TileRenderPipelineDescriptor::setShaderValidation(ShaderValidation shaderValidation)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setShaderValidation_), shaderValidation);
}

_MTL_INLINE void MTL::TileRenderPipelineDescriptor::setSupportAddingBinaryFunctions(bool supportAddingBinaryFunctions)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSupportAddingBinaryFunctions_), supportAddingBinaryFunctions);
}

_MTL_INLINE void MTL::TileRenderPipelineDescriptor::setThreadgroupSizeMatchesTileSize(
    bool threadgroupSizeMatchesTileSize)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setThreadgroupSizeMatchesTileSize_), threadgroupSizeMatchesTileSize);
}

_MTL_INLINE void MTL::TileRenderPipelineDescriptor::setTileFunction(const Function* tileFunction)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTileFunction_), tileFunction);
}

_MTL_INLINE MTL::ShaderValidation MTL::TileRenderPipelineDescriptor::shaderValidation() const
{
    return sendMessage<ShaderValidation>(this, _MTL_PRIVATE_SEL(shaderValidation));
}

_MTL_INLINE bool MTL::TileRenderPipelineDescriptor::supportAddingBinaryFunctions() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supportAddingBinaryFunctions));
}

_MTL_INLINE bool MTL::TileRenderPipelineDescriptor::threadgroupSizeMatchesTileSize() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(threadgroupSizeMatchesTileSize));
}

_MTL_INLINE MTL::PipelineBufferDescriptorArray* MTL::TileRenderPipelineDescriptor::tileBuffers() const
{
    return sendMessage<PipelineBufferDescriptorArray*>(this, _MTL_PRIVATE_SEL(tileBuffers));
}

_MTL_INLINE MTL::Function* MTL::TileRenderPipelineDescriptor::tileFunction() const
{
    return sendMessage<Function*>(this, _MTL_PRIVATE_SEL(tileFunction));
}

_MTL_INLINE MTL::MeshRenderPipelineDescriptor* MTL::MeshRenderPipelineDescriptor::alloc()
{
    return alloc<MeshRenderPipelineDescriptor>(_MTL_PRIVATE_CLS(MTLMeshRenderPipelineDescriptor));
}

_MTL_INLINE bool MTL::MeshRenderPipelineDescriptor::alphaToCoverageEnabled() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isAlphaToCoverageEnabled));
}

_MTL_INLINE bool MTL::MeshRenderPipelineDescriptor::alphaToOneEnabled() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isAlphaToOneEnabled));
}

_MTL_INLINE NS::Array* MTL::MeshRenderPipelineDescriptor::binaryArchives() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(binaryArchives));
}

_MTL_INLINE MTL::RenderPipelineColorAttachmentDescriptorArray* MTL::MeshRenderPipelineDescriptor::colorAttachments()
    const
{
    return sendMessage<RenderPipelineColorAttachmentDescriptorArray*>(this, _MTL_PRIVATE_SEL(colorAttachments));
}

_MTL_INLINE MTL::PixelFormat MTL::MeshRenderPipelineDescriptor::depthAttachmentPixelFormat() const
{
    return sendMessage<PixelFormat>(this, _MTL_PRIVATE_SEL(depthAttachmentPixelFormat));
}

_MTL_INLINE MTL::PipelineBufferDescriptorArray* MTL::MeshRenderPipelineDescriptor::fragmentBuffers() const
{
    return sendMessage<PipelineBufferDescriptorArray*>(this, _MTL_PRIVATE_SEL(fragmentBuffers));
}

_MTL_INLINE MTL::Function* MTL::MeshRenderPipelineDescriptor::fragmentFunction() const
{
    return sendMessage<Function*>(this, _MTL_PRIVATE_SEL(fragmentFunction));
}

_MTL_INLINE MTL::LinkedFunctions* MTL::MeshRenderPipelineDescriptor::fragmentLinkedFunctions() const
{
    return sendMessage<LinkedFunctions*>(this, _MTL_PRIVATE_SEL(fragmentLinkedFunctions));
}

_MTL_INLINE MTL::MeshRenderPipelineDescriptor* MTL::MeshRenderPipelineDescriptor::init()
{
    return init<MeshRenderPipelineDescriptor>();
}

_MTL_INLINE bool MTL::MeshRenderPipelineDescriptor::isAlphaToCoverageEnabled() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isAlphaToCoverageEnabled));
}

_MTL_INLINE bool MTL::MeshRenderPipelineDescriptor::isAlphaToOneEnabled() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isAlphaToOneEnabled));
}

_MTL_INLINE bool MTL::MeshRenderPipelineDescriptor::isRasterizationEnabled() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isRasterizationEnabled));
}

_MTL_INLINE NS::String* MTL::MeshRenderPipelineDescriptor::label() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
}

_MTL_INLINE NS::UInteger MTL::MeshRenderPipelineDescriptor::maxTotalThreadgroupsPerMeshGrid() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxTotalThreadgroupsPerMeshGrid));
}

_MTL_INLINE NS::UInteger MTL::MeshRenderPipelineDescriptor::maxTotalThreadsPerMeshThreadgroup() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxTotalThreadsPerMeshThreadgroup));
}

_MTL_INLINE NS::UInteger MTL::MeshRenderPipelineDescriptor::maxTotalThreadsPerObjectThreadgroup() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxTotalThreadsPerObjectThreadgroup));
}

_MTL_INLINE NS::UInteger MTL::MeshRenderPipelineDescriptor::maxVertexAmplificationCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxVertexAmplificationCount));
}

_MTL_INLINE MTL::PipelineBufferDescriptorArray* MTL::MeshRenderPipelineDescriptor::meshBuffers() const
{
    return sendMessage<PipelineBufferDescriptorArray*>(this, _MTL_PRIVATE_SEL(meshBuffers));
}

_MTL_INLINE MTL::Function* MTL::MeshRenderPipelineDescriptor::meshFunction() const
{
    return sendMessage<Function*>(this, _MTL_PRIVATE_SEL(meshFunction));
}

_MTL_INLINE MTL::LinkedFunctions* MTL::MeshRenderPipelineDescriptor::meshLinkedFunctions() const
{
    return sendMessage<LinkedFunctions*>(this, _MTL_PRIVATE_SEL(meshLinkedFunctions));
}

_MTL_INLINE bool MTL::MeshRenderPipelineDescriptor::meshThreadgroupSizeIsMultipleOfThreadExecutionWidth() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(meshThreadgroupSizeIsMultipleOfThreadExecutionWidth));
}

_MTL_INLINE MTL::PipelineBufferDescriptorArray* MTL::MeshRenderPipelineDescriptor::objectBuffers() const
{
    return sendMessage<PipelineBufferDescriptorArray*>(this, _MTL_PRIVATE_SEL(objectBuffers));
}

_MTL_INLINE MTL::Function* MTL::MeshRenderPipelineDescriptor::objectFunction() const
{
    return sendMessage<Function*>(this, _MTL_PRIVATE_SEL(objectFunction));
}

_MTL_INLINE MTL::LinkedFunctions* MTL::MeshRenderPipelineDescriptor::objectLinkedFunctions() const
{
    return sendMessage<LinkedFunctions*>(this, _MTL_PRIVATE_SEL(objectLinkedFunctions));
}

_MTL_INLINE bool MTL::MeshRenderPipelineDescriptor::objectThreadgroupSizeIsMultipleOfThreadExecutionWidth() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(objectThreadgroupSizeIsMultipleOfThreadExecutionWidth));
}

_MTL_INLINE NS::UInteger MTL::MeshRenderPipelineDescriptor::payloadMemoryLength() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(payloadMemoryLength));
}

_MTL_INLINE NS::UInteger MTL::MeshRenderPipelineDescriptor::rasterSampleCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(rasterSampleCount));
}

_MTL_INLINE bool MTL::MeshRenderPipelineDescriptor::rasterizationEnabled() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isRasterizationEnabled));
}

_MTL_INLINE MTL::Size MTL::MeshRenderPipelineDescriptor::requiredThreadsPerMeshThreadgroup() const
{
    return sendMessage<Size>(this, _MTL_PRIVATE_SEL(requiredThreadsPerMeshThreadgroup));
}

_MTL_INLINE MTL::Size MTL::MeshRenderPipelineDescriptor::requiredThreadsPerObjectThreadgroup() const
{
    return sendMessage<Size>(this, _MTL_PRIVATE_SEL(requiredThreadsPerObjectThreadgroup));
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::reset() { sendMessage<void>(this, _MTL_PRIVATE_SEL(reset)); }

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setAlphaToCoverageEnabled(bool alphaToCoverageEnabled)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setAlphaToCoverageEnabled_), alphaToCoverageEnabled);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setAlphaToOneEnabled(bool alphaToOneEnabled)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setAlphaToOneEnabled_), alphaToOneEnabled);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setBinaryArchives(const NS::Array* binaryArchives)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBinaryArchives_), binaryArchives);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setDepthAttachmentPixelFormat(
    PixelFormat depthAttachmentPixelFormat)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDepthAttachmentPixelFormat_), depthAttachmentPixelFormat);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setFragmentFunction(const Function* fragmentFunction)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFragmentFunction_), fragmentFunction);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setFragmentLinkedFunctions(
    const LinkedFunctions* fragmentLinkedFunctions)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFragmentLinkedFunctions_), fragmentLinkedFunctions);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setLabel(const NS::String* label)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLabel_), label);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setMaxTotalThreadgroupsPerMeshGrid(
    NS::UInteger maxTotalThreadgroupsPerMeshGrid)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxTotalThreadgroupsPerMeshGrid_), maxTotalThreadgroupsPerMeshGrid);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setMaxTotalThreadsPerMeshThreadgroup(
    NS::UInteger maxTotalThreadsPerMeshThreadgroup)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxTotalThreadsPerMeshThreadgroup_), maxTotalThreadsPerMeshThreadgroup);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setMaxTotalThreadsPerObjectThreadgroup(
    NS::UInteger maxTotalThreadsPerObjectThreadgroup)
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setMaxTotalThreadsPerObjectThreadgroup_), maxTotalThreadsPerObjectThreadgroup);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setMaxVertexAmplificationCount(
    NS::UInteger maxVertexAmplificationCount)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxVertexAmplificationCount_), maxVertexAmplificationCount);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setMeshFunction(const Function* meshFunction)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMeshFunction_), meshFunction);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setMeshLinkedFunctions(const LinkedFunctions* meshLinkedFunctions)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMeshLinkedFunctions_), meshLinkedFunctions);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setMeshThreadgroupSizeIsMultipleOfThreadExecutionWidth(
    bool meshThreadgroupSizeIsMultipleOfThreadExecutionWidth)
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(setMeshThreadgroupSizeIsMultipleOfThreadExecutionWidth_),
                      meshThreadgroupSizeIsMultipleOfThreadExecutionWidth);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setObjectFunction(const Function* objectFunction)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setObjectFunction_), objectFunction);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setObjectLinkedFunctions(
    const LinkedFunctions* objectLinkedFunctions)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setObjectLinkedFunctions_), objectLinkedFunctions);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setObjectThreadgroupSizeIsMultipleOfThreadExecutionWidth(
    bool objectThreadgroupSizeIsMultipleOfThreadExecutionWidth)
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(setObjectThreadgroupSizeIsMultipleOfThreadExecutionWidth_),
                      objectThreadgroupSizeIsMultipleOfThreadExecutionWidth);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setPayloadMemoryLength(NS::UInteger payloadMemoryLength)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setPayloadMemoryLength_), payloadMemoryLength);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setRasterSampleCount(NS::UInteger rasterSampleCount)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRasterSampleCount_), rasterSampleCount);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setRasterizationEnabled(bool rasterizationEnabled)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRasterizationEnabled_), rasterizationEnabled);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setRequiredThreadsPerMeshThreadgroup(
    Size requiredThreadsPerMeshThreadgroup)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRequiredThreadsPerMeshThreadgroup_), requiredThreadsPerMeshThreadgroup);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setRequiredThreadsPerObjectThreadgroup(
    Size requiredThreadsPerObjectThreadgroup)
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setRequiredThreadsPerObjectThreadgroup_), requiredThreadsPerObjectThreadgroup);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setShaderValidation(ShaderValidation shaderValidation)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setShaderValidation_), shaderValidation);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setStencilAttachmentPixelFormat(
    PixelFormat stencilAttachmentPixelFormat)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setStencilAttachmentPixelFormat_), stencilAttachmentPixelFormat);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setSupportIndirectCommandBuffers(bool supportIndirectCommandBuffers)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSupportIndirectCommandBuffers_), supportIndirectCommandBuffers);
}

_MTL_INLINE MTL::ShaderValidation MTL::MeshRenderPipelineDescriptor::shaderValidation() const
{
    return sendMessage<ShaderValidation>(this, _MTL_PRIVATE_SEL(shaderValidation));
}

_MTL_INLINE MTL::PixelFormat MTL::MeshRenderPipelineDescriptor::stencilAttachmentPixelFormat() const
{
    return sendMessage<PixelFormat>(this, _MTL_PRIVATE_SEL(stencilAttachmentPixelFormat));
}

_MTL_INLINE bool MTL::MeshRenderPipelineDescriptor::supportIndirectCommandBuffers() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supportIndirectCommandBuffers));
}
