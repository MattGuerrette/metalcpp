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

        void setAlphaBlendOperation(BlendOperation alphaBlendOperation) const;

        void setBlendingEnabled(bool blendingEnabled) const;

        void setDestinationAlphaBlendFactor(BlendFactor destinationAlphaBlendFactor) const;

        void setDestinationRGBBlendFactor(BlendFactor destinationRGBBlendFactor) const;

        void setPixelFormat(PixelFormat pixelFormat) const;

        void setRgbBlendOperation(BlendOperation rgbBlendOperation) const;

        void setSourceAlphaBlendFactor(BlendFactor sourceAlphaBlendFactor) const;

        void setSourceRGBBlendFactor(BlendFactor sourceRGBBlendFactor) const;

        void setWriteMask(ColorWriteMask writeMask) const;

        [[nodiscard]] BlendFactor sourceAlphaBlendFactor() const;

        [[nodiscard]] BlendFactor sourceRGBBlendFactor() const;

        [[nodiscard]] ColorWriteMask writeMask() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtllogicaltophysicalcolorattachmentmap?language=objc
    class LogicalToPhysicalColorAttachmentMap : public NS::Copying<LogicalToPhysicalColorAttachmentMap>
    {
    public:
        [[nodiscard]] static LogicalToPhysicalColorAttachmentMap* alloc();

        [[nodiscard]] NS::UInteger getPhysicalIndex(NS::UInteger logicalIndex) const;

        [[nodiscard]] LogicalToPhysicalColorAttachmentMap* init();

        void reset() const;

        void setPhysicalIndex(NS::UInteger physicalIndex, NS::UInteger logicalIndex) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlrenderpipelinereflection?language=objc
    class RenderPipelineReflection : public NS::Referencing<RenderPipelineReflection>
    {
    public:
        [[nodiscard]] static RenderPipelineReflection* alloc();

        [[nodiscard]] NS::Array* fragmentArguments() const;

        [[nodiscard]] NS::Array* fragmentBindings() const;

        [[nodiscard]] RenderPipelineReflection* init();

        [[nodiscard]] NS::Array* meshBindings() const;

        [[nodiscard]] NS::Array* objectBindings() const;

        [[nodiscard]] NS::Array* tileArguments() const;

        [[nodiscard]] NS::Array* tileBindings() const;

        [[nodiscard]] NS::Array* vertexArguments() const;

        [[nodiscard]] NS::Array* vertexBindings() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlrenderpipelinedescriptor?language=objc
    class RenderPipelineDescriptor : public NS::Copying<RenderPipelineDescriptor>
    {
    public:
        [[nodiscard]] static RenderPipelineDescriptor* alloc();

        [[deprecated("please use isAlphaToCoverageEnabled instead")]] [[nodiscard]] bool alphaToCoverageEnabled() const;

        [[deprecated("please use isAlphaToOneEnabled instead")]] [[nodiscard]] bool alphaToOneEnabled() const;

        [[nodiscard]] NS::Array* binaryArchives() const;

        [[nodiscard]] RenderPipelineColorAttachmentDescriptorArray* colorAttachments() const;

        [[nodiscard]] PixelFormat depthAttachmentPixelFormat() const;

        [[nodiscard]] PipelineBufferDescriptorArray* fragmentBuffers() const;

        [[nodiscard]] Function* fragmentFunction() const;

        [[nodiscard]] LinkedFunctions* fragmentLinkedFunctions() const;

        [[nodiscard]] NS::Array* fragmentPreloadedLibraries() const;

        [[nodiscard]] RenderPipelineDescriptor* init();

        [[nodiscard]] PrimitiveTopologyClass inputPrimitiveTopology() const;

        [[nodiscard]] bool isAlphaToCoverageEnabled() const;

        [[nodiscard]] bool isAlphaToOneEnabled() const;

        [[nodiscard]] bool isRasterizationEnabled() const;

        [[nodiscard]] bool isTessellationFactorScaleEnabled() const;

        [[nodiscard]] NS::String* label() const;

        [[nodiscard]] NS::UInteger maxFragmentCallStackDepth() const;

        [[nodiscard]] NS::UInteger maxTessellationFactor() const;

        [[nodiscard]] NS::UInteger maxVertexAmplificationCount() const;

        [[nodiscard]] NS::UInteger maxVertexCallStackDepth() const;

        [[nodiscard]] NS::UInteger rasterSampleCount() const;

        [[deprecated("please use isRasterizationEnabled instead")]] [[nodiscard]] bool rasterizationEnabled() const;

        void reset() const;

        [[nodiscard]] NS::UInteger sampleCount() const;

        void setAlphaToCoverageEnabled(bool alphaToCoverageEnabled) const;

        void setAlphaToOneEnabled(bool alphaToOneEnabled) const;

        void setBinaryArchives(const NS::Array* binaryArchives) const;

        void setDepthAttachmentPixelFormat(PixelFormat depthAttachmentPixelFormat) const;

        void setFragmentFunction(const Function* fragmentFunction) const;

        void setFragmentLinkedFunctions(const LinkedFunctions* fragmentLinkedFunctions) const;

        void setFragmentPreloadedLibraries(const NS::Array* fragmentPreloadedLibraries) const;

        void setInputPrimitiveTopology(PrimitiveTopologyClass inputPrimitiveTopology) const;

        void setLabel(const NS::String* label) const;

        void setMaxFragmentCallStackDepth(NS::UInteger maxFragmentCallStackDepth) const;

        void setMaxTessellationFactor(NS::UInteger maxTessellationFactor) const;

        void setMaxVertexAmplificationCount(NS::UInteger maxVertexAmplificationCount) const;

        void setMaxVertexCallStackDepth(NS::UInteger maxVertexCallStackDepth) const;

        void setRasterSampleCount(NS::UInteger rasterSampleCount) const;

        void setRasterizationEnabled(bool rasterizationEnabled) const;

        void setSampleCount(NS::UInteger sampleCount) const;

        void setShaderValidation(ShaderValidation shaderValidation) const;

        void setStencilAttachmentPixelFormat(PixelFormat stencilAttachmentPixelFormat) const;

        void setSupportAddingFragmentBinaryFunctions(bool supportAddingFragmentBinaryFunctions) const;

        void setSupportAddingVertexBinaryFunctions(bool supportAddingVertexBinaryFunctions) const;

        void setSupportIndirectCommandBuffers(bool supportIndirectCommandBuffers) const;

        void setTessellationControlPointIndexType(
            TessellationControlPointIndexType tessellationControlPointIndexType) const;

        void setTessellationFactorFormat(TessellationFactorFormat tessellationFactorFormat) const;

        void setTessellationFactorScaleEnabled(bool tessellationFactorScaleEnabled) const;

        void setTessellationFactorStepFunction(TessellationFactorStepFunction tessellationFactorStepFunction) const;

        void setTessellationOutputWindingOrder(Winding tessellationOutputWindingOrder) const;

        void setTessellationPartitionMode(TessellationPartitionMode tessellationPartitionMode) const;

        void setVertexDescriptor(const VertexDescriptor* vertexDescriptor) const;

        void setVertexFunction(const Function* vertexFunction) const;

        void setVertexLinkedFunctions(const LinkedFunctions* vertexLinkedFunctions) const;

        void setVertexPreloadedLibraries(const NS::Array* vertexPreloadedLibraries) const;

        [[nodiscard]] ShaderValidation shaderValidation() const;

        [[nodiscard]] PixelFormat stencilAttachmentPixelFormat() const;

        [[nodiscard]] bool supportAddingFragmentBinaryFunctions() const;

        [[nodiscard]] bool supportAddingVertexBinaryFunctions() const;

        [[nodiscard]] bool supportIndirectCommandBuffers() const;

        [[nodiscard]] TessellationControlPointIndexType tessellationControlPointIndexType() const;

        [[nodiscard]] TessellationFactorFormat tessellationFactorFormat() const;

        [[deprecated("please use isTessellationFactorScaleEnabled instead")]] [[nodiscard]] bool
        tessellationFactorScaleEnabled() const;

        [[nodiscard]] TessellationFactorStepFunction tessellationFactorStepFunction() const;

        [[nodiscard]] Winding tessellationOutputWindingOrder() const;

        [[nodiscard]] TessellationPartitionMode tessellationPartitionMode() const;

        [[nodiscard]] PipelineBufferDescriptorArray* vertexBuffers() const;

        [[nodiscard]] VertexDescriptor* vertexDescriptor() const;

        [[nodiscard]] Function* vertexFunction() const;

        [[nodiscard]] LinkedFunctions* vertexLinkedFunctions() const;

        [[nodiscard]] NS::Array* vertexPreloadedLibraries() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlrenderpipelinefunctionsdescriptor?language=objc
    class RenderPipelineFunctionsDescriptor : public NS::Copying<RenderPipelineFunctionsDescriptor>
    {
    public:
        [[nodiscard]] static RenderPipelineFunctionsDescriptor* alloc();

        [[nodiscard]] NS::Array* fragmentAdditionalBinaryFunctions() const;

        [[nodiscard]] RenderPipelineFunctionsDescriptor* init();

        void setFragmentAdditionalBinaryFunctions(const NS::Array* fragmentAdditionalBinaryFunctions) const;

        void setTileAdditionalBinaryFunctions(const NS::Array* tileAdditionalBinaryFunctions) const;

        void setVertexAdditionalBinaryFunctions(const NS::Array* vertexAdditionalBinaryFunctions) const;

        [[nodiscard]] NS::Array* tileAdditionalBinaryFunctions() const;

        [[nodiscard]] NS::Array* vertexAdditionalBinaryFunctions() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlrenderpipelinestate?language=objc
    class RenderPipelineState : public NS::Referencing<RenderPipelineState, Allocation>
    {
    public:
        [[nodiscard]] Device* device() const;

        [[nodiscard]] FunctionHandle* functionHandle(const NS::String* name, RenderStages stage) const;
        [[nodiscard]] FunctionHandle* functionHandle(const MTL4::BinaryFunction* function, RenderStages stage) const;
        [[nodiscard]] FunctionHandle* functionHandle(const Function* function, RenderStages stage) const;

        [[nodiscard]] ResourceID gpuResourceID() const;

        [[nodiscard]] NS::UInteger imageblockMemoryLength(const Size& imageblockDimensions) const;

        [[nodiscard]] NS::UInteger imageblockSampleLength() const;

        [[nodiscard]] NS::String* label() const;

        [[nodiscard]] NS::UInteger maxTotalThreadgroupsPerMeshGrid() const;

        [[nodiscard]] NS::UInteger maxTotalThreadsPerMeshThreadgroup() const;

        [[nodiscard]] NS::UInteger maxTotalThreadsPerObjectThreadgroup() const;

        [[nodiscard]] NS::UInteger maxTotalThreadsPerThreadgroup() const;

        [[nodiscard]] NS::UInteger meshThreadExecutionWidth() const;

        [[nodiscard]] IntersectionFunctionTable* newIntersectionFunctionTable(
            const IntersectionFunctionTableDescriptor* descriptor, RenderStages stage) const;

        [[nodiscard]] MTL4::PipelineDescriptor* newRenderPipelineDescriptor() const;

        [[nodiscard]] RenderPipelineState* newRenderPipelineState(
            const MTL4::RenderPipelineBinaryFunctionsDescriptor* binaryFunctionsDescriptor, NS::Error** error) const;
        [[nodiscard]] RenderPipelineState* newRenderPipelineState(
            const RenderPipelineFunctionsDescriptor* additionalBinaryFunctions, NS::Error** error) const;

        [[nodiscard]] VisibleFunctionTable* newVisibleFunctionTable(const VisibleFunctionTableDescriptor* descriptor,
                                                                    RenderStages                          stage) const;

        [[nodiscard]] NS::UInteger objectThreadExecutionWidth() const;

        [[nodiscard]] RenderPipelineReflection* reflection() const;

        [[nodiscard]] Size requiredThreadsPerMeshThreadgroup() const;

        [[nodiscard]] Size requiredThreadsPerObjectThreadgroup() const;

        [[nodiscard]] Size requiredThreadsPerTileThreadgroup() const;

        [[nodiscard]] ShaderValidation shaderValidation() const;

        [[nodiscard]] bool supportIndirectCommandBuffers() const;

        [[nodiscard]] bool threadgroupSizeMatchesTileSize() const;
    };

    /// @see
    /// https://developer.apple.com/documentation/metal/mtlrenderpipelinecolorattachmentdescriptorarray?language=objc
    class RenderPipelineColorAttachmentDescriptorArray
        : public NS::Referencing<RenderPipelineColorAttachmentDescriptorArray>
    {
    public:
        [[nodiscard]] static RenderPipelineColorAttachmentDescriptorArray* alloc();

        [[nodiscard]] RenderPipelineColorAttachmentDescriptorArray* init();

        [[nodiscard]] RenderPipelineColorAttachmentDescriptor* object(NS::UInteger attachmentIndex) const;
        void setObject(const RenderPipelineColorAttachmentDescriptor* attachment, NS::UInteger attachmentIndex) const;
    };

    /// @see
    /// https://developer.apple.com/documentation/metal/mtltilerenderpipelinecolorattachmentdescriptor?language=objc
    class TileRenderPipelineColorAttachmentDescriptor : public NS::Copying<TileRenderPipelineColorAttachmentDescriptor>
    {
    public:
        [[nodiscard]] static TileRenderPipelineColorAttachmentDescriptor* alloc();

        [[nodiscard]] TileRenderPipelineColorAttachmentDescriptor* init();

        [[nodiscard]] PixelFormat pixelFormat() const;
        void                      setPixelFormat(PixelFormat pixelFormat) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtltilerenderpipelinecolorattachmentdescriptorarray
    class TileRenderPipelineColorAttachmentDescriptorArray
        : public NS::Referencing<TileRenderPipelineColorAttachmentDescriptorArray>
    {
    public:
        [[nodiscard]] static TileRenderPipelineColorAttachmentDescriptorArray* alloc();

        [[nodiscard]] TileRenderPipelineColorAttachmentDescriptorArray* init();

        [[nodiscard]] TileRenderPipelineColorAttachmentDescriptor* object(NS::UInteger attachmentIndex) const;
        void setObject(const TileRenderPipelineColorAttachmentDescriptor* attachment,
                       NS::UInteger                                       attachmentIndex) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtltilerenderpipelinedescriptor?language=objc
    class TileRenderPipelineDescriptor : public NS::Copying<TileRenderPipelineDescriptor>
    {
    public:
        [[nodiscard]] static TileRenderPipelineDescriptor* alloc();

        [[nodiscard]] NS::Array* binaryArchives() const;

        [[nodiscard]] TileRenderPipelineColorAttachmentDescriptorArray* colorAttachments() const;

        [[nodiscard]] TileRenderPipelineDescriptor* init();

        [[nodiscard]] NS::String* label() const;

        [[nodiscard]] LinkedFunctions* linkedFunctions() const;

        [[nodiscard]] NS::UInteger maxCallStackDepth() const;

        [[nodiscard]] NS::UInteger maxTotalThreadsPerThreadgroup() const;

        [[nodiscard]] NS::Array* preloadedLibraries() const;

        [[nodiscard]] NS::UInteger rasterSampleCount() const;

        [[nodiscard]] Size requiredThreadsPerThreadgroup() const;

        void reset() const;

        void setBinaryArchives(const NS::Array* binaryArchives) const;

        void setLabel(const NS::String* label) const;

        void setLinkedFunctions(const LinkedFunctions* linkedFunctions) const;

        void setMaxCallStackDepth(NS::UInteger maxCallStackDepth) const;

        void setMaxTotalThreadsPerThreadgroup(NS::UInteger maxTotalThreadsPerThreadgroup) const;

        void setPreloadedLibraries(const NS::Array* preloadedLibraries) const;

        void setRasterSampleCount(NS::UInteger rasterSampleCount) const;

        void setRequiredThreadsPerThreadgroup(const Size& requiredThreadsPerThreadgroup) const;

        void setShaderValidation(ShaderValidation shaderValidation) const;

        void setSupportAddingBinaryFunctions(bool supportAddingBinaryFunctions) const;

        void setThreadgroupSizeMatchesTileSize(bool threadgroupSizeMatchesTileSize) const;

        void setTileFunction(const Function* tileFunction) const;

        [[nodiscard]] ShaderValidation shaderValidation() const;

        [[nodiscard]] bool supportAddingBinaryFunctions() const;

        [[nodiscard]] bool threadgroupSizeMatchesTileSize() const;

        [[nodiscard]] PipelineBufferDescriptorArray* tileBuffers() const;

        [[nodiscard]] Function* tileFunction() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlmeshrenderpipelinedescriptor?language=objc
    class MeshRenderPipelineDescriptor : public NS::Copying<MeshRenderPipelineDescriptor>
    {
    public:
        [[nodiscard]] static MeshRenderPipelineDescriptor* alloc();

        [[deprecated("please use isAlphaToCoverageEnabled instead")]] [[nodiscard]] bool alphaToCoverageEnabled() const;

        [[deprecated("please use isAlphaToOneEnabled instead")]] [[nodiscard]] bool alphaToOneEnabled() const;

        [[nodiscard]] NS::Array* binaryArchives() const;

        [[nodiscard]] RenderPipelineColorAttachmentDescriptorArray* colorAttachments() const;

        [[nodiscard]] PixelFormat depthAttachmentPixelFormat() const;

        [[nodiscard]] PipelineBufferDescriptorArray* fragmentBuffers() const;

        [[nodiscard]] Function* fragmentFunction() const;

        [[nodiscard]] LinkedFunctions* fragmentLinkedFunctions() const;

        [[nodiscard]] MeshRenderPipelineDescriptor* init();

        [[nodiscard]] bool isAlphaToCoverageEnabled() const;

        [[nodiscard]] bool isAlphaToOneEnabled() const;

        [[nodiscard]] bool isRasterizationEnabled() const;

        [[nodiscard]] NS::String* label() const;

        [[nodiscard]] NS::UInteger maxTotalThreadgroupsPerMeshGrid() const;

        [[nodiscard]] NS::UInteger maxTotalThreadsPerMeshThreadgroup() const;

        [[nodiscard]] NS::UInteger maxTotalThreadsPerObjectThreadgroup() const;

        [[nodiscard]] NS::UInteger maxVertexAmplificationCount() const;

        [[nodiscard]] PipelineBufferDescriptorArray* meshBuffers() const;

        [[nodiscard]] Function* meshFunction() const;

        [[nodiscard]] LinkedFunctions* meshLinkedFunctions() const;

        [[nodiscard]] bool meshThreadgroupSizeIsMultipleOfThreadExecutionWidth() const;

        [[nodiscard]] PipelineBufferDescriptorArray* objectBuffers() const;

        [[nodiscard]] Function* objectFunction() const;

        [[nodiscard]] LinkedFunctions* objectLinkedFunctions() const;

        [[nodiscard]] bool objectThreadgroupSizeIsMultipleOfThreadExecutionWidth() const;

        [[nodiscard]] NS::UInteger payloadMemoryLength() const;

        [[nodiscard]] NS::UInteger rasterSampleCount() const;

        [[deprecated("please use isRasterizationEnabled instead")]] [[nodiscard]] bool rasterizationEnabled() const;

        [[nodiscard]] Size requiredThreadsPerMeshThreadgroup() const;

        [[nodiscard]] Size requiredThreadsPerObjectThreadgroup() const;

        void reset() const;

        void setAlphaToCoverageEnabled(bool alphaToCoverageEnabled) const;

        void setAlphaToOneEnabled(bool alphaToOneEnabled) const;

        void setBinaryArchives(const NS::Array* binaryArchives) const;

        void setDepthAttachmentPixelFormat(PixelFormat depthAttachmentPixelFormat) const;

        void setFragmentFunction(const Function* fragmentFunction) const;

        void setFragmentLinkedFunctions(const LinkedFunctions* fragmentLinkedFunctions) const;

        void setLabel(const NS::String* label) const;

        void setMaxTotalThreadgroupsPerMeshGrid(NS::UInteger maxTotalThreadgroupsPerMeshGrid) const;

        void setMaxTotalThreadsPerMeshThreadgroup(NS::UInteger maxTotalThreadsPerMeshThreadgroup) const;

        void setMaxTotalThreadsPerObjectThreadgroup(NS::UInteger maxTotalThreadsPerObjectThreadgroup) const;

        void setMaxVertexAmplificationCount(NS::UInteger maxVertexAmplificationCount) const;

        void setMeshFunction(const Function* meshFunction) const;

        void setMeshLinkedFunctions(const LinkedFunctions* meshLinkedFunctions) const;

        void setMeshThreadgroupSizeIsMultipleOfThreadExecutionWidth(
            bool meshThreadgroupSizeIsMultipleOfThreadExecutionWidth) const;

        void setObjectFunction(const Function* objectFunction) const;

        void setObjectLinkedFunctions(const LinkedFunctions* objectLinkedFunctions) const;

        void setObjectThreadgroupSizeIsMultipleOfThreadExecutionWidth(
            bool objectThreadgroupSizeIsMultipleOfThreadExecutionWidth) const;

        void setPayloadMemoryLength(NS::UInteger payloadMemoryLength) const;

        void setRasterSampleCount(NS::UInteger rasterSampleCount) const;

        void setRasterizationEnabled(bool rasterizationEnabled) const;

        void setRequiredThreadsPerMeshThreadgroup(const Size& requiredThreadsPerMeshThreadgroup) const;

        void setRequiredThreadsPerObjectThreadgroup(const Size& requiredThreadsPerObjectThreadgroup) const;

        void setShaderValidation(ShaderValidation shaderValidation) const;

        void setStencilAttachmentPixelFormat(PixelFormat stencilAttachmentPixelFormat) const;

        void setSupportIndirectCommandBuffers(bool supportIndirectCommandBuffers) const;

        [[nodiscard]] ShaderValidation shaderValidation() const;

        [[nodiscard]] PixelFormat stencilAttachmentPixelFormat() const;

        [[nodiscard]] bool supportIndirectCommandBuffers() const;
    };

} // namespace MTL
_MTL_INLINE MTL::RenderPipelineColorAttachmentDescriptor* MTL::RenderPipelineColorAttachmentDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<RenderPipelineColorAttachmentDescriptor>(
        _MTL_PRIVATE_CLS(MTLRenderPipelineColorAttachmentDescriptor));
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
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<RenderPipelineColorAttachmentDescriptor>();
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
    const BlendOperation alphaBlendOperation) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setAlphaBlendOperation_), alphaBlendOperation);
}

_MTL_INLINE void MTL::RenderPipelineColorAttachmentDescriptor::setBlendingEnabled(const bool blendingEnabled) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBlendingEnabled_), blendingEnabled);
}

_MTL_INLINE void MTL::RenderPipelineColorAttachmentDescriptor::setDestinationAlphaBlendFactor(
    const BlendFactor destinationAlphaBlendFactor) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDestinationAlphaBlendFactor_), destinationAlphaBlendFactor);
}

_MTL_INLINE void MTL::RenderPipelineColorAttachmentDescriptor::setDestinationRGBBlendFactor(
    const BlendFactor destinationRGBBlendFactor) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDestinationRGBBlendFactor_), destinationRGBBlendFactor);
}

_MTL_INLINE void MTL::RenderPipelineColorAttachmentDescriptor::setPixelFormat(const PixelFormat pixelFormat) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setPixelFormat_), pixelFormat);
}

_MTL_INLINE void MTL::RenderPipelineColorAttachmentDescriptor::setRgbBlendOperation(
    const BlendOperation rgbBlendOperation) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRgbBlendOperation_), rgbBlendOperation);
}

_MTL_INLINE void MTL::RenderPipelineColorAttachmentDescriptor::setSourceAlphaBlendFactor(
    const BlendFactor sourceAlphaBlendFactor) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSourceAlphaBlendFactor_), sourceAlphaBlendFactor);
}

_MTL_INLINE void MTL::RenderPipelineColorAttachmentDescriptor::setSourceRGBBlendFactor(
    const BlendFactor sourceRGBBlendFactor) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSourceRGBBlendFactor_), sourceRGBBlendFactor);
}

_MTL_INLINE void MTL::RenderPipelineColorAttachmentDescriptor::setWriteMask(const ColorWriteMask writeMask) const
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
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<LogicalToPhysicalColorAttachmentMap>(
        _MTL_PRIVATE_CLS(MTLLogicalToPhysicalColorAttachmentMap));
}

_MTL_INLINE NS::UInteger MTL::LogicalToPhysicalColorAttachmentMap::getPhysicalIndex(
    const NS::UInteger logicalIndex) const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(getPhysicalIndexForLogicalIndex_), logicalIndex);
}

_MTL_INLINE MTL::LogicalToPhysicalColorAttachmentMap* MTL::LogicalToPhysicalColorAttachmentMap::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<LogicalToPhysicalColorAttachmentMap>();
}

_MTL_INLINE void MTL::LogicalToPhysicalColorAttachmentMap::reset() const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(reset));
}

_MTL_INLINE void MTL::LogicalToPhysicalColorAttachmentMap::setPhysicalIndex(const NS::UInteger physicalIndex,
                                                                            const NS::UInteger logicalIndex) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setPhysicalIndex_forLogicalIndex_), physicalIndex, logicalIndex);
}

_MTL_INLINE MTL::RenderPipelineReflection* MTL::RenderPipelineReflection::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<RenderPipelineReflection>(_MTL_PRIVATE_CLS(MTLRenderPipelineReflection));
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
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<RenderPipelineReflection>();
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
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<RenderPipelineDescriptor>(_MTL_PRIVATE_CLS(MTLRenderPipelineDescriptor));
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
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<RenderPipelineDescriptor>();
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

_MTL_INLINE void MTL::RenderPipelineDescriptor::reset() const { sendMessage<void>(this, _MTL_PRIVATE_SEL(reset)); }

_MTL_INLINE NS::UInteger MTL::RenderPipelineDescriptor::sampleCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(sampleCount));
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setAlphaToCoverageEnabled(const bool alphaToCoverageEnabled) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setAlphaToCoverageEnabled_), alphaToCoverageEnabled);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setAlphaToOneEnabled(const bool alphaToOneEnabled) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setAlphaToOneEnabled_), alphaToOneEnabled);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setBinaryArchives(const NS::Array* binaryArchives) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBinaryArchives_), binaryArchives);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setDepthAttachmentPixelFormat(
    const PixelFormat depthAttachmentPixelFormat) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDepthAttachmentPixelFormat_), depthAttachmentPixelFormat);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setFragmentFunction(const Function* fragmentFunction) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFragmentFunction_), fragmentFunction);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setFragmentLinkedFunctions(
    const LinkedFunctions* fragmentLinkedFunctions) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFragmentLinkedFunctions_), fragmentLinkedFunctions);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setFragmentPreloadedLibraries(
    const NS::Array* fragmentPreloadedLibraries) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFragmentPreloadedLibraries_), fragmentPreloadedLibraries);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setInputPrimitiveTopology(
    const PrimitiveTopologyClass inputPrimitiveTopology) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setInputPrimitiveTopology_), inputPrimitiveTopology);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setLabel(const NS::String* label) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLabel_), label);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setMaxFragmentCallStackDepth(
    const NS::UInteger maxFragmentCallStackDepth) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxFragmentCallStackDepth_), maxFragmentCallStackDepth);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setMaxTessellationFactor(const NS::UInteger maxTessellationFactor) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxTessellationFactor_), maxTessellationFactor);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setMaxVertexAmplificationCount(
    const NS::UInteger maxVertexAmplificationCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxVertexAmplificationCount_), maxVertexAmplificationCount);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setMaxVertexCallStackDepth(
    const NS::UInteger maxVertexCallStackDepth) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxVertexCallStackDepth_), maxVertexCallStackDepth);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setRasterSampleCount(const NS::UInteger rasterSampleCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRasterSampleCount_), rasterSampleCount);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setRasterizationEnabled(const bool rasterizationEnabled) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRasterizationEnabled_), rasterizationEnabled);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setSampleCount(const NS::UInteger sampleCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSampleCount_), sampleCount);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setShaderValidation(const ShaderValidation shaderValidation) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setShaderValidation_), shaderValidation);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setStencilAttachmentPixelFormat(
    const PixelFormat stencilAttachmentPixelFormat) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setStencilAttachmentPixelFormat_), stencilAttachmentPixelFormat);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setSupportAddingFragmentBinaryFunctions(
    const bool supportAddingFragmentBinaryFunctions) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setSupportAddingFragmentBinaryFunctions_), supportAddingFragmentBinaryFunctions);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setSupportAddingVertexBinaryFunctions(
    const bool supportAddingVertexBinaryFunctions) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setSupportAddingVertexBinaryFunctions_), supportAddingVertexBinaryFunctions);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setSupportIndirectCommandBuffers(
    const bool supportIndirectCommandBuffers) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSupportIndirectCommandBuffers_), supportIndirectCommandBuffers);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setTessellationControlPointIndexType(
    const TessellationControlPointIndexType tessellationControlPointIndexType) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTessellationControlPointIndexType_), tessellationControlPointIndexType);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setTessellationFactorFormat(
    const TessellationFactorFormat tessellationFactorFormat) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTessellationFactorFormat_), tessellationFactorFormat);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setTessellationFactorScaleEnabled(
    const bool tessellationFactorScaleEnabled) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTessellationFactorScaleEnabled_), tessellationFactorScaleEnabled);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setTessellationFactorStepFunction(
    const TessellationFactorStepFunction tessellationFactorStepFunction) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTessellationFactorStepFunction_), tessellationFactorStepFunction);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setTessellationOutputWindingOrder(
    const Winding tessellationOutputWindingOrder) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTessellationOutputWindingOrder_), tessellationOutputWindingOrder);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setTessellationPartitionMode(
    const TessellationPartitionMode tessellationPartitionMode) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTessellationPartitionMode_), tessellationPartitionMode);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setVertexDescriptor(const VertexDescriptor* vertexDescriptor) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVertexDescriptor_), vertexDescriptor);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setVertexFunction(const Function* vertexFunction) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVertexFunction_), vertexFunction);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setVertexLinkedFunctions(
    const LinkedFunctions* vertexLinkedFunctions) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVertexLinkedFunctions_), vertexLinkedFunctions);
}

_MTL_INLINE void MTL::RenderPipelineDescriptor::setVertexPreloadedLibraries(
    const NS::Array* vertexPreloadedLibraries) const
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
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<RenderPipelineFunctionsDescriptor>(_MTL_PRIVATE_CLS(MTLRenderPipelineFunctionsDescriptor));
}

_MTL_INLINE NS::Array* MTL::RenderPipelineFunctionsDescriptor::fragmentAdditionalBinaryFunctions() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(fragmentAdditionalBinaryFunctions));
}

_MTL_INLINE MTL::RenderPipelineFunctionsDescriptor* MTL::RenderPipelineFunctionsDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<RenderPipelineFunctionsDescriptor>();
}

_MTL_INLINE void MTL::RenderPipelineFunctionsDescriptor::setFragmentAdditionalBinaryFunctions(
    const NS::Array* fragmentAdditionalBinaryFunctions) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFragmentAdditionalBinaryFunctions_), fragmentAdditionalBinaryFunctions);
}

_MTL_INLINE void MTL::RenderPipelineFunctionsDescriptor::setTileAdditionalBinaryFunctions(
    const NS::Array* tileAdditionalBinaryFunctions) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTileAdditionalBinaryFunctions_), tileAdditionalBinaryFunctions);
}

_MTL_INLINE void MTL::RenderPipelineFunctionsDescriptor::setVertexAdditionalBinaryFunctions(
    const NS::Array* vertexAdditionalBinaryFunctions) const
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

_MTL_INLINE MTL::FunctionHandle* MTL::RenderPipelineState::functionHandle(const NS::String*  name,
                                                                          const RenderStages stage) const
{
    return sendMessage<FunctionHandle*>(this, _MTL_PRIVATE_SEL(functionHandleWithName_stage_), name, stage);
}

_MTL_INLINE MTL::FunctionHandle* MTL::RenderPipelineState::functionHandle(const MTL4::BinaryFunction* function,
                                                                          const RenderStages          stage) const
{
    return sendMessage<FunctionHandle*>(
        this, _MTL_PRIVATE_SEL(functionHandleWithBinaryFunction_stage_), function, stage);
}

_MTL_INLINE MTL::FunctionHandle* MTL::RenderPipelineState::functionHandle(const Function*    function,
                                                                          const RenderStages stage) const
{
    return sendMessage<FunctionHandle*>(this, _MTL_PRIVATE_SEL(functionHandleWithFunction_stage_), function, stage);
}

_MTL_INLINE MTL::ResourceID MTL::RenderPipelineState::gpuResourceID() const
{
    return sendMessage<ResourceID>(this, _MTL_PRIVATE_SEL(gpuResourceID));
}

_MTL_INLINE NS::UInteger MTL::RenderPipelineState::imageblockMemoryLength(const Size& imageblockDimensions) const
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
    const IntersectionFunctionTableDescriptor* descriptor, const RenderStages stage) const
{
    return sendMessage<IntersectionFunctionTable*>(
        this, _MTL_PRIVATE_SEL(newIntersectionFunctionTableWithDescriptor_stage_), descriptor, stage);
}

_MTL_INLINE MTL4::PipelineDescriptor* MTL::RenderPipelineState::newRenderPipelineDescriptor() const
{
    return sendMessage<MTL4::PipelineDescriptor*>(this, _MTL_PRIVATE_SEL(newRenderPipelineDescriptorForSpecialization));
}

_MTL_INLINE MTL::RenderPipelineState* MTL::RenderPipelineState::newRenderPipelineState(
    const MTL4::RenderPipelineBinaryFunctionsDescriptor* binaryFunctionsDescriptor, NS::Error** error) const
{
    return sendMessage<RenderPipelineState*>(
        this, _MTL_PRIVATE_SEL(newRenderPipelineStateWithBinaryFunctions_error_), binaryFunctionsDescriptor, error);
}

_MTL_INLINE MTL::RenderPipelineState* MTL::RenderPipelineState::newRenderPipelineState(
    const RenderPipelineFunctionsDescriptor* additionalBinaryFunctions, NS::Error** error) const
{
    return sendMessage<RenderPipelineState*>(
        this,
        _MTL_PRIVATE_SEL(newRenderPipelineStateWithAdditionalBinaryFunctions_error_),
        additionalBinaryFunctions,
        error);
}

_MTL_INLINE MTL::VisibleFunctionTable* MTL::RenderPipelineState::newVisibleFunctionTable(
    const VisibleFunctionTableDescriptor* descriptor, const RenderStages stage) const
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
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<RenderPipelineColorAttachmentDescriptorArray>(
        _MTL_PRIVATE_CLS(MTLRenderPipelineColorAttachmentDescriptorArray));
}

_MTL_INLINE MTL::RenderPipelineColorAttachmentDescriptorArray* MTL::RenderPipelineColorAttachmentDescriptorArray::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<RenderPipelineColorAttachmentDescriptorArray>();
}

_MTL_INLINE MTL::RenderPipelineColorAttachmentDescriptor* MTL::RenderPipelineColorAttachmentDescriptorArray::object(
    const NS::UInteger attachmentIndex) const
{
    return sendMessage<RenderPipelineColorAttachmentDescriptor*>(
        this, _MTL_PRIVATE_SEL(objectAtIndexedSubscript_), attachmentIndex);
}

_MTL_INLINE void MTL::RenderPipelineColorAttachmentDescriptorArray::setObject(
    const RenderPipelineColorAttachmentDescriptor* attachment, const NS::UInteger attachmentIndex) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setObject_atIndexedSubscript_), attachment, attachmentIndex);
}

_MTL_INLINE MTL::TileRenderPipelineColorAttachmentDescriptor* MTL::TileRenderPipelineColorAttachmentDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<TileRenderPipelineColorAttachmentDescriptor>(
        _MTL_PRIVATE_CLS(MTLTileRenderPipelineColorAttachmentDescriptor));
}

_MTL_INLINE MTL::TileRenderPipelineColorAttachmentDescriptor* MTL::TileRenderPipelineColorAttachmentDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<TileRenderPipelineColorAttachmentDescriptor>();
}

_MTL_INLINE MTL::PixelFormat MTL::TileRenderPipelineColorAttachmentDescriptor::pixelFormat() const
{
    return sendMessage<PixelFormat>(this, _MTL_PRIVATE_SEL(pixelFormat));
}

_MTL_INLINE void MTL::TileRenderPipelineColorAttachmentDescriptor::setPixelFormat(const PixelFormat pixelFormat) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setPixelFormat_), pixelFormat);
}

_MTL_INLINE MTL::TileRenderPipelineColorAttachmentDescriptorArray*
            MTL::TileRenderPipelineColorAttachmentDescriptorArray::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<TileRenderPipelineColorAttachmentDescriptorArray>(
        _MTL_PRIVATE_CLS(MTLTileRenderPipelineColorAttachmentDescriptorArray));
}

_MTL_INLINE MTL::TileRenderPipelineColorAttachmentDescriptorArray*
            MTL::TileRenderPipelineColorAttachmentDescriptorArray::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<TileRenderPipelineColorAttachmentDescriptorArray>();
}

_MTL_INLINE MTL::TileRenderPipelineColorAttachmentDescriptor*
            MTL::TileRenderPipelineColorAttachmentDescriptorArray::object(const NS::UInteger attachmentIndex) const
{
    return sendMessage<TileRenderPipelineColorAttachmentDescriptor*>(
        this, _MTL_PRIVATE_SEL(objectAtIndexedSubscript_), attachmentIndex);
}

_MTL_INLINE void MTL::TileRenderPipelineColorAttachmentDescriptorArray::setObject(
    const TileRenderPipelineColorAttachmentDescriptor* attachment, const NS::UInteger attachmentIndex) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setObject_atIndexedSubscript_), attachment, attachmentIndex);
}

_MTL_INLINE MTL::TileRenderPipelineDescriptor* MTL::TileRenderPipelineDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<TileRenderPipelineDescriptor>(_MTL_PRIVATE_CLS(MTLTileRenderPipelineDescriptor));
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
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<TileRenderPipelineDescriptor>();
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

_MTL_INLINE void MTL::TileRenderPipelineDescriptor::reset() const { sendMessage<void>(this, _MTL_PRIVATE_SEL(reset)); }

_MTL_INLINE void MTL::TileRenderPipelineDescriptor::setBinaryArchives(const NS::Array* binaryArchives) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBinaryArchives_), binaryArchives);
}

_MTL_INLINE void MTL::TileRenderPipelineDescriptor::setLabel(const NS::String* label) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLabel_), label);
}

_MTL_INLINE void MTL::TileRenderPipelineDescriptor::setLinkedFunctions(const LinkedFunctions* linkedFunctions) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLinkedFunctions_), linkedFunctions);
}

_MTL_INLINE void MTL::TileRenderPipelineDescriptor::setMaxCallStackDepth(const NS::UInteger maxCallStackDepth) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxCallStackDepth_), maxCallStackDepth);
}

_MTL_INLINE void MTL::TileRenderPipelineDescriptor::setMaxTotalThreadsPerThreadgroup(
    const NS::UInteger maxTotalThreadsPerThreadgroup) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxTotalThreadsPerThreadgroup_), maxTotalThreadsPerThreadgroup);
}

_MTL_INLINE void MTL::TileRenderPipelineDescriptor::setPreloadedLibraries(const NS::Array* preloadedLibraries) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setPreloadedLibraries_), preloadedLibraries);
}

_MTL_INLINE void MTL::TileRenderPipelineDescriptor::setRasterSampleCount(const NS::UInteger rasterSampleCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRasterSampleCount_), rasterSampleCount);
}

_MTL_INLINE void MTL::TileRenderPipelineDescriptor::setRequiredThreadsPerThreadgroup(
    const Size& requiredThreadsPerThreadgroup) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRequiredThreadsPerThreadgroup_), requiredThreadsPerThreadgroup);
}

_MTL_INLINE void MTL::TileRenderPipelineDescriptor::setShaderValidation(const ShaderValidation shaderValidation) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setShaderValidation_), shaderValidation);
}

_MTL_INLINE void MTL::TileRenderPipelineDescriptor::setSupportAddingBinaryFunctions(
    const bool supportAddingBinaryFunctions) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSupportAddingBinaryFunctions_), supportAddingBinaryFunctions);
}

_MTL_INLINE void MTL::TileRenderPipelineDescriptor::setThreadgroupSizeMatchesTileSize(
    const bool threadgroupSizeMatchesTileSize) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setThreadgroupSizeMatchesTileSize_), threadgroupSizeMatchesTileSize);
}

_MTL_INLINE void MTL::TileRenderPipelineDescriptor::setTileFunction(const Function* tileFunction) const
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
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<MeshRenderPipelineDescriptor>(_MTL_PRIVATE_CLS(MTLMeshRenderPipelineDescriptor));
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
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<MeshRenderPipelineDescriptor>();
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

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::reset() const { sendMessage<void>(this, _MTL_PRIVATE_SEL(reset)); }

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setAlphaToCoverageEnabled(const bool alphaToCoverageEnabled) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setAlphaToCoverageEnabled_), alphaToCoverageEnabled);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setAlphaToOneEnabled(const bool alphaToOneEnabled) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setAlphaToOneEnabled_), alphaToOneEnabled);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setBinaryArchives(const NS::Array* binaryArchives) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBinaryArchives_), binaryArchives);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setDepthAttachmentPixelFormat(
    const PixelFormat depthAttachmentPixelFormat) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDepthAttachmentPixelFormat_), depthAttachmentPixelFormat);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setFragmentFunction(const Function* fragmentFunction) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFragmentFunction_), fragmentFunction);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setFragmentLinkedFunctions(
    const LinkedFunctions* fragmentLinkedFunctions) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFragmentLinkedFunctions_), fragmentLinkedFunctions);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setLabel(const NS::String* label) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLabel_), label);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setMaxTotalThreadgroupsPerMeshGrid(
    const NS::UInteger maxTotalThreadgroupsPerMeshGrid) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxTotalThreadgroupsPerMeshGrid_), maxTotalThreadgroupsPerMeshGrid);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setMaxTotalThreadsPerMeshThreadgroup(
    const NS::UInteger maxTotalThreadsPerMeshThreadgroup) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxTotalThreadsPerMeshThreadgroup_), maxTotalThreadsPerMeshThreadgroup);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setMaxTotalThreadsPerObjectThreadgroup(
    const NS::UInteger maxTotalThreadsPerObjectThreadgroup) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setMaxTotalThreadsPerObjectThreadgroup_), maxTotalThreadsPerObjectThreadgroup);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setMaxVertexAmplificationCount(
    const NS::UInteger maxVertexAmplificationCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxVertexAmplificationCount_), maxVertexAmplificationCount);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setMeshFunction(const Function* meshFunction) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMeshFunction_), meshFunction);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setMeshLinkedFunctions(
    const LinkedFunctions* meshLinkedFunctions) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMeshLinkedFunctions_), meshLinkedFunctions);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setMeshThreadgroupSizeIsMultipleOfThreadExecutionWidth(
    const bool meshThreadgroupSizeIsMultipleOfThreadExecutionWidth) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(setMeshThreadgroupSizeIsMultipleOfThreadExecutionWidth_),
                      meshThreadgroupSizeIsMultipleOfThreadExecutionWidth);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setObjectFunction(const Function* objectFunction) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setObjectFunction_), objectFunction);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setObjectLinkedFunctions(
    const LinkedFunctions* objectLinkedFunctions) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setObjectLinkedFunctions_), objectLinkedFunctions);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setObjectThreadgroupSizeIsMultipleOfThreadExecutionWidth(
    const bool objectThreadgroupSizeIsMultipleOfThreadExecutionWidth) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(setObjectThreadgroupSizeIsMultipleOfThreadExecutionWidth_),
                      objectThreadgroupSizeIsMultipleOfThreadExecutionWidth);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setPayloadMemoryLength(const NS::UInteger payloadMemoryLength) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setPayloadMemoryLength_), payloadMemoryLength);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setRasterSampleCount(const NS::UInteger rasterSampleCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRasterSampleCount_), rasterSampleCount);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setRasterizationEnabled(const bool rasterizationEnabled) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRasterizationEnabled_), rasterizationEnabled);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setRequiredThreadsPerMeshThreadgroup(
    const Size& requiredThreadsPerMeshThreadgroup) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRequiredThreadsPerMeshThreadgroup_), requiredThreadsPerMeshThreadgroup);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setRequiredThreadsPerObjectThreadgroup(
    const Size& requiredThreadsPerObjectThreadgroup) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setRequiredThreadsPerObjectThreadgroup_), requiredThreadsPerObjectThreadgroup);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setShaderValidation(const ShaderValidation shaderValidation) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setShaderValidation_), shaderValidation);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setStencilAttachmentPixelFormat(
    const PixelFormat stencilAttachmentPixelFormat) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setStencilAttachmentPixelFormat_), stencilAttachmentPixelFormat);
}

_MTL_INLINE void MTL::MeshRenderPipelineDescriptor::setSupportIndirectCommandBuffers(
    const bool supportIndirectCommandBuffers) const
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
