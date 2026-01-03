//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLResourceStatePass.hpp
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
#include "MTLArgument.hpp"
#include "MTLCommandEncoder.hpp"
#include "MTLDefines.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"
#include "MTLRenderPass.hpp"
#include "MTLTypes.hpp"

namespace MTL
{
    class AccelerationStructure;
    class Buffer;
    class CounterSampleBuffer;
    class DepthStencilState;
    class Fence;
    class Heap;
    class IndirectCommandBuffer;
    class IntersectionFunctionTable;
    class LogicalToPhysicalColorAttachmentMap;
    class RenderPipelineState;
    class Resource;
    class SamplerState;
    struct ScissorRect;
    class Texture;
    struct VertexAmplificationViewMapping;
    struct Viewport;
    class VisibleFunctionTable;

    /// @see https://developer.apple.com/documentation/metal/mtlprimitivetype?language=objc
    _MTL_ENUM(NS::UInteger, PrimitiveType){
        PrimitiveTypePoint = 0,    PrimitiveTypeLine = 1,          PrimitiveTypeLineStrip = 2,
        PrimitiveTypeTriangle = 3, PrimitiveTypeTriangleStrip = 4,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlvisibilityresultmode?language=objc
    _MTL_ENUM(NS::UInteger, VisibilityResultMode){
        VisibilityResultModeDisabled = 0,
        VisibilityResultModeBoolean  = 1,
        VisibilityResultModeCounting = 2,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlcullmode?language=objc
    _MTL_ENUM(NS::UInteger, CullMode){
        CullModeNone  = 0,
        CullModeFront = 1,
        CullModeBack  = 2,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlwinding?language=objc
    _MTL_ENUM(NS::UInteger, Winding){
        WindingClockwise        = 0,
        WindingCounterClockwise = 1,
    };

    /// @see https://developer.apple.com/documentation/metal/mtldepthclipmode?language=objc
    _MTL_ENUM(NS::UInteger, DepthClipMode){
        DepthClipModeClip  = 0,
        DepthClipModeClamp = 1,
    };

    /// @see https://developer.apple.com/documentation/metal/mtltrianglefillmode?language=objc
    _MTL_ENUM(NS::UInteger, TriangleFillMode){
        TriangleFillModeFill  = 0,
        TriangleFillModeLines = 1,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlrenderstages?language=objc
    _MTL_OPTIONS(NS::UInteger, RenderStages){
        RenderStageVertex = 1,      RenderStageFragment = 1 << 1, RenderStageTile = 1 << 2,
        RenderStageObject = 1 << 3, RenderStageMesh = 1 << 4,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlscissorrect?language=objc
    struct ScissorRect
    {
        NS::UInteger x;
        NS::UInteger y;
        NS::UInteger width;
        NS::UInteger height;
    } _MTL_PACKED;

    /// @see https://developer.apple.com/documentation/metal/mtlviewport?language=objc
    struct Viewport
    {
        double originX;
        double originY;
        double width;
        double height;
        double znear;
        double zfar;
    } _MTL_PACKED;

    /// @see https://developer.apple.com/documentation/metal/mtldrawprimitivesindirectarguments?language=objc
    struct DrawPrimitivesIndirectArguments
    {
        uint32_t vertexCount;
        uint32_t instanceCount;
        uint32_t vertexStart;
        uint32_t baseInstance;
    } _MTL_PACKED;

    /// @see https://developer.apple.com/documentation/metal/mtldrawindexedprimitivesindirectarguments?language=objc
    struct DrawIndexedPrimitivesIndirectArguments
    {
        uint32_t indexCount;
        uint32_t instanceCount;
        uint32_t indexStart;
        int32_t  baseVertex;
        uint32_t baseInstance;
    } _MTL_PACKED;

    /// @see https://developer.apple.com/documentation/metal/mtlvertexamplificationviewmapping?language=objc
    struct VertexAmplificationViewMapping
    {
        uint32_t viewportArrayIndexOffset;
        uint32_t renderTargetArrayIndexOffset;
    } _MTL_PACKED;

    /// @see https://developer.apple.com/documentation/metal/mtldrawpatchindirectarguments?language=objc
    struct DrawPatchIndirectArguments
    {
        uint32_t patchCount;
        uint32_t instanceCount;
        uint32_t patchStart;
        uint32_t baseInstance;
    } _MTL_PACKED;

    /// @see https://developer.apple.com/documentation/metal/mtlquadtessellationfactorshalf?language=objc
    struct QuadTessellationFactorsHalf
    {
        uint16_t edgeTessellationFactor[4];
        uint16_t insideTessellationFactor[2];
    } _MTL_PACKED;

    /// @see https://developer.apple.com/documentation/metal/mtltriangletessellationfactorshalf?language=objc
    struct TriangleTessellationFactorsHalf
    {
        uint16_t edgeTessellationFactor[3];
        uint16_t insideTessellationFactor;
    } _MTL_PACKED;

    /// @see https://developer.apple.com/documentation/metal/mtlrendercommandencoder?language=objc
    class RenderCommandEncoder : public NS::Referencing<RenderCommandEncoder, CommandEncoder>
    {
    public:
        void dispatchThreadsPerTile(const Size& threadsPerTile) const;

        void drawIndexedPatches(NS::UInteger  numberOfPatchControlPoints,
                                NS::UInteger  patchStart,
                                NS::UInteger  patchCount,
                                const Buffer* patchIndexBuffer,
                                NS::UInteger  patchIndexBufferOffset,
                                const Buffer* controlPointIndexBuffer,
                                NS::UInteger  controlPointIndexBufferOffset,
                                NS::UInteger  instanceCount,
                                NS::UInteger  baseInstance) const;
        void drawIndexedPatches(NS::UInteger  numberOfPatchControlPoints,
                                const Buffer* patchIndexBuffer,
                                NS::UInteger  patchIndexBufferOffset,
                                const Buffer* controlPointIndexBuffer,
                                NS::UInteger  controlPointIndexBufferOffset,
                                const Buffer* indirectBuffer,
                                NS::UInteger  indirectBufferOffset) const;

        void drawIndexedPrimitives(PrimitiveType primitiveType,
                                   NS::UInteger  indexCount,
                                   IndexType     indexType,
                                   const Buffer* indexBuffer,
                                   NS::UInteger  indexBufferOffset,
                                   NS::UInteger  instanceCount) const;
        void drawIndexedPrimitives(PrimitiveType primitiveType,
                                   NS::UInteger  indexCount,
                                   IndexType     indexType,
                                   const Buffer* indexBuffer,
                                   NS::UInteger  indexBufferOffset) const;
        void drawIndexedPrimitives(PrimitiveType primitiveType,
                                   NS::UInteger  indexCount,
                                   IndexType     indexType,
                                   const Buffer* indexBuffer,
                                   NS::UInteger  indexBufferOffset,
                                   NS::UInteger  instanceCount,
                                   NS::Integer   baseVertex,
                                   NS::UInteger  baseInstance) const;
        void drawIndexedPrimitives(PrimitiveType primitiveType,
                                   IndexType     indexType,
                                   const Buffer* indexBuffer,
                                   NS::UInteger  indexBufferOffset,
                                   const Buffer* indirectBuffer,
                                   NS::UInteger  indirectBufferOffset) const;

        void drawMeshThreadgroups(const Size& threadgroupsPerGrid,
                                  const Size& threadsPerObjectThreadgroup,
                                  const Size& threadsPerMeshThreadgroup) const;
        void drawMeshThreadgroups(const Buffer* indirectBuffer,
                                  NS::UInteger  indirectBufferOffset,
                                  const Size&   threadsPerObjectThreadgroup,
                                  const Size&   threadsPerMeshThreadgroup) const;

        void drawMeshThreads(const Size& threadsPerGrid,
                             const Size& threadsPerObjectThreadgroup,
                             const Size& threadsPerMeshThreadgroup) const;

        void drawPatches(NS::UInteger  numberOfPatchControlPoints,
                         NS::UInteger  patchStart,
                         NS::UInteger  patchCount,
                         const Buffer* patchIndexBuffer,
                         NS::UInteger  patchIndexBufferOffset,
                         NS::UInteger  instanceCount,
                         NS::UInteger  baseInstance) const;
        void drawPatches(NS::UInteger  numberOfPatchControlPoints,
                         const Buffer* patchIndexBuffer,
                         NS::UInteger  patchIndexBufferOffset,
                         const Buffer* indirectBuffer,
                         NS::UInteger  indirectBufferOffset) const;

        void drawPrimitives(PrimitiveType primitiveType,
                            NS::UInteger  vertexStart,
                            NS::UInteger  vertexCount,
                            NS::UInteger  instanceCount) const;
        void drawPrimitives(PrimitiveType primitiveType, NS::UInteger vertexStart, NS::UInteger vertexCount) const;
        void drawPrimitives(PrimitiveType primitiveType,
                            NS::UInteger  vertexStart,
                            NS::UInteger  vertexCount,
                            NS::UInteger  instanceCount,
                            NS::UInteger  baseInstance) const;
        void drawPrimitives(PrimitiveType primitiveType,
                            const Buffer* indirectBuffer,
                            NS::UInteger  indirectBufferOffset) const;

        void executeCommandsInBuffer(const IndirectCommandBuffer* indirectCommandBuffer,
                                     NS::Range                    executionRange) const;
        void executeCommandsInBuffer(const IndirectCommandBuffer* indirectCommandbuffer,
                                     const Buffer*                indirectRangeBuffer,
                                     NS::UInteger                 indirectBufferOffset) const;

        void memoryBarrier(BarrierScope scope, RenderStages after, RenderStages before) const;
        void memoryBarrier(const Resource* const resources[],
                           NS::UInteger          count,
                           RenderStages          after,
                           RenderStages          before) const;

        void sampleCountersInBuffer(const CounterSampleBuffer* sampleBuffer,
                                    NS::UInteger               sampleIndex,
                                    bool                       barrier) const;

        void setBlendColor(float red, float green, float blue, float alpha) const;

        void setColorAttachmentMap(const LogicalToPhysicalColorAttachmentMap* mapping) const;

        void setColorStoreAction(StoreAction storeAction, NS::UInteger colorAttachmentIndex) const;
        void setColorStoreActionOptions(StoreActionOptions storeActionOptions, NS::UInteger colorAttachmentIndex) const;

        void setCullMode(CullMode cullMode) const;

        void setDepthBias(float depthBias, float slopeScale, float clamp) const;

        void setDepthClipMode(DepthClipMode depthClipMode) const;

        void setDepthStencilState(const DepthStencilState* depthStencilState) const;

        void setDepthStoreAction(StoreAction storeAction) const;
        void setDepthStoreActionOptions(StoreActionOptions storeActionOptions) const;

        void setDepthTestBounds(float minBound, float maxBound) const;

        void setFragmentAccelerationStructure(const AccelerationStructure* accelerationStructure,
                                              NS::UInteger                 bufferIndex) const;

        void setFragmentBuffer(const Buffer* buffer, NS::UInteger offset, NS::UInteger index) const;
        void setFragmentBufferOffset(NS::UInteger offset, NS::UInteger index) const;

        void setFragmentBuffers(const Buffer* const buffers[], const NS::UInteger offsets[], NS::Range range) const;

        void setFragmentBytes(const void* bytes, NS::UInteger length, NS::UInteger index) const;

        void setFragmentIntersectionFunctionTable(const IntersectionFunctionTable* intersectionFunctionTable,
                                                  NS::UInteger                     bufferIndex) const;
        void setFragmentIntersectionFunctionTables(const IntersectionFunctionTable* const intersectionFunctionTables[],
                                                   NS::Range                              range) const;

        void setFragmentSamplerState(const SamplerState* sampler, NS::UInteger index) const;
        void setFragmentSamplerState(const SamplerState* sampler,
                                     float               lodMinClamp,
                                     float               lodMaxClamp,
                                     NS::UInteger        index) const;
        void setFragmentSamplerStates(const SamplerState* const samplers[], NS::Range range) const;
        void setFragmentSamplerStates(const SamplerState* const samplers[],
                                      const float               lodMinClamps[],
                                      const float               lodMaxClamps[],
                                      NS::Range                 range) const;

        void setFragmentTexture(const Texture* texture, NS::UInteger index) const;
        void setFragmentTextures(const Texture* const textures[], NS::Range range) const;

        void setFragmentVisibleFunctionTable(const VisibleFunctionTable* functionTable, NS::UInteger bufferIndex) const;
        void setFragmentVisibleFunctionTables(const VisibleFunctionTable* const functionTables[],
                                              NS::Range                         range) const;

        void setFrontFacingWinding(Winding frontFacingWinding) const;

        void setMeshBuffer(const Buffer* buffer, NS::UInteger offset, NS::UInteger index) const;
        void setMeshBufferOffset(NS::UInteger offset, NS::UInteger index) const;

        void setMeshBuffers(const Buffer* const buffers[], const NS::UInteger* offsets, NS::Range range) const;

        void setMeshBytes(const void* bytes, NS::UInteger length, NS::UInteger index) const;

        void setMeshSamplerState(const SamplerState* sampler, NS::UInteger index) const;
        void setMeshSamplerState(const SamplerState* sampler,
                                 float               lodMinClamp,
                                 float               lodMaxClamp,
                                 NS::UInteger        index) const;
        void setMeshSamplerStates(const SamplerState* const samplers[], NS::Range range) const;
        void setMeshSamplerStates(const SamplerState* const samplers[],
                                  const float*              lodMinClamps,
                                  const float*              lodMaxClamps,
                                  NS::Range                 range) const;

        void setMeshTexture(const Texture* texture, NS::UInteger index) const;
        void setMeshTextures(const Texture* const textures[], NS::Range range) const;

        void setObjectBuffer(const Buffer* buffer, NS::UInteger offset, NS::UInteger index) const;
        void setObjectBufferOffset(NS::UInteger offset, NS::UInteger index) const;

        void setObjectBuffers(const Buffer* const buffers[], const NS::UInteger* offsets, NS::Range range) const;

        void setObjectBytes(const void* bytes, NS::UInteger length, NS::UInteger index) const;

        void setObjectSamplerState(const SamplerState* sampler, NS::UInteger index) const;
        void setObjectSamplerState(const SamplerState* sampler,
                                   float               lodMinClamp,
                                   float               lodMaxClamp,
                                   NS::UInteger        index) const;
        void setObjectSamplerStates(const SamplerState* const samplers[], NS::Range range) const;
        void setObjectSamplerStates(const SamplerState* const samplers[],
                                    const float*              lodMinClamps,
                                    const float*              lodMaxClamps,
                                    NS::Range                 range) const;

        void setObjectTexture(const Texture* texture, NS::UInteger index) const;
        void setObjectTextures(const Texture* const textures[], NS::Range range) const;

        void setObjectThreadgroupMemoryLength(NS::UInteger length, NS::UInteger index) const;

        void setRenderPipelineState(const RenderPipelineState* pipelineState) const;

        void setScissorRect(const ScissorRect& rect) const;
        void setScissorRects(const ScissorRect* scissorRects, NS::UInteger count) const;

        void setStencilReferenceValue(uint32_t referenceValue) const;
        void setStencilReferenceValues(uint32_t frontReferenceValue, uint32_t backReferenceValue) const;

        void setStencilStoreAction(StoreAction storeAction) const;
        void setStencilStoreActionOptions(StoreActionOptions storeActionOptions) const;

        void setTessellationFactorBuffer(const Buffer* buffer, NS::UInteger offset, NS::UInteger instanceStride) const;

        void setTessellationFactorScale(float scale) const;

        void setThreadgroupMemoryLength(NS::UInteger length, NS::UInteger offset, NS::UInteger index) const;

        void setTileAccelerationStructure(const AccelerationStructure* accelerationStructure,
                                          NS::UInteger                 bufferIndex) const;

        void setTileBuffer(const Buffer* buffer, NS::UInteger offset, NS::UInteger index) const;
        void setTileBufferOffset(NS::UInteger offset, NS::UInteger index) const;

        void setTileBuffers(const Buffer* const buffers[], const NS::UInteger* offsets, NS::Range range) const;

        void setTileBytes(const void* bytes, NS::UInteger length, NS::UInteger index) const;

        void setTileIntersectionFunctionTable(const IntersectionFunctionTable* intersectionFunctionTable,
                                              NS::UInteger                     bufferIndex) const;
        void setTileIntersectionFunctionTables(const IntersectionFunctionTable* const intersectionFunctionTables[],
                                               NS::Range                              range) const;

        void setTileSamplerState(const SamplerState* sampler, NS::UInteger index) const;
        void setTileSamplerState(const SamplerState* sampler,
                                 float               lodMinClamp,
                                 float               lodMaxClamp,
                                 NS::UInteger        index) const;
        void setTileSamplerStates(const SamplerState* const samplers[], NS::Range range) const;
        void setTileSamplerStates(const SamplerState* const samplers[],
                                  const float               lodMinClamps[],
                                  const float               lodMaxClamps[],
                                  NS::Range                 range) const;

        void setTileTexture(const Texture* texture, NS::UInteger index) const;
        void setTileTextures(const Texture* const textures[], NS::Range range) const;

        void setTileVisibleFunctionTable(const VisibleFunctionTable* functionTable, NS::UInteger bufferIndex) const;
        void setTileVisibleFunctionTables(const VisibleFunctionTable* const functionTables[], NS::Range range) const;

        void setTriangleFillMode(TriangleFillMode fillMode) const;

        void setVertexAccelerationStructure(const AccelerationStructure* accelerationStructure,
                                            NS::UInteger                 bufferIndex) const;

        void setVertexAmplificationCount(NS::UInteger count, const VertexAmplificationViewMapping* viewMappings) const;

        void setVertexBuffer(const Buffer* buffer, NS::UInteger offset, NS::UInteger index) const;
        void setVertexBuffer(const Buffer* buffer, NS::UInteger offset, NS::UInteger stride, NS::UInteger index) const;
        void setVertexBufferOffset(NS::UInteger offset, NS::UInteger index) const;
        void setVertexBufferOffset(NS::UInteger offset, NS::UInteger stride, NS::UInteger index) const;

        void setVertexBuffers(const Buffer* const buffers[], const NS::UInteger offsets[], NS::Range range) const;
        void setVertexBuffers(const Buffer* const buffers[],
                              const NS::UInteger* offsets,
                              const NS::UInteger* strides,
                              NS::Range           range) const;

        void setVertexBytes(const void* bytes, NS::UInteger length, NS::UInteger index) const;
        void setVertexBytes(const void* bytes, NS::UInteger length, NS::UInteger stride, NS::UInteger index) const;

        void setVertexIntersectionFunctionTable(const IntersectionFunctionTable* intersectionFunctionTable,
                                                NS::UInteger                     bufferIndex) const;
        void setVertexIntersectionFunctionTables(const IntersectionFunctionTable* const intersectionFunctionTables[],
                                                 NS::Range                              range) const;

        void setVertexSamplerState(const SamplerState* sampler, NS::UInteger index) const;
        void setVertexSamplerState(const SamplerState* sampler,
                                   float               lodMinClamp,
                                   float               lodMaxClamp,
                                   NS::UInteger        index) const;
        void setVertexSamplerStates(const SamplerState* const samplers[], NS::Range range) const;
        void setVertexSamplerStates(const SamplerState* const samplers[],
                                    const float               lodMinClamps[],
                                    const float               lodMaxClamps[],
                                    NS::Range                 range) const;

        void setVertexTexture(const Texture* texture, NS::UInteger index) const;
        void setVertexTextures(const Texture* const textures[], NS::Range range) const;

        void setVertexVisibleFunctionTable(const VisibleFunctionTable* functionTable, NS::UInteger bufferIndex) const;
        void setVertexVisibleFunctionTables(const VisibleFunctionTable* const functionTables[], NS::Range range) const;

        void setViewport(const Viewport& viewport) const;
        void setViewports(const Viewport* viewports, NS::UInteger count) const;

        void setVisibilityResultMode(VisibilityResultMode mode, NS::UInteger offset) const;

        void textureBarrier() const;

        [[nodiscard]] NS::UInteger tileHeight() const;

        [[nodiscard]] NS::UInteger tileWidth() const;

        void updateFence(const Fence* fence, RenderStages stages) const;

        void useHeap(const Heap* heap) const;
        void useHeap(const Heap* heap, RenderStages stages) const;
        void useHeaps(const Heap* const heaps[], NS::UInteger count) const;
        void useHeaps(const Heap* const heaps[], NS::UInteger count, RenderStages stages) const;

        void useResource(const Resource* resource, ResourceUsage usage) const;
        void useResource(const Resource* resource, ResourceUsage usage, RenderStages stages) const;
        void useResources(const Resource* const resources[], NS::UInteger count, ResourceUsage usage) const;
        void useResources(const Resource* const resources[],
                          NS::UInteger          count,
                          ResourceUsage         usage,
                          RenderStages          stages) const;

        void waitForFence(const Fence* fence, RenderStages stages) const;
    };

} // namespace MTL

_MTL_INLINE void MTL::RenderCommandEncoder::dispatchThreadsPerTile(const Size& threadsPerTile) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(dispatchThreadsPerTile_), threadsPerTile);
}

_MTL_INLINE void MTL::RenderCommandEncoder::drawIndexedPatches(const NS::UInteger numberOfPatchControlPoints,
                                                               const NS::UInteger patchStart,
                                                               const NS::UInteger patchCount,
                                                               const Buffer*      patchIndexBuffer,
                                                               const NS::UInteger patchIndexBufferOffset,
                                                               const Buffer*      controlPointIndexBuffer,
                                                               const NS::UInteger controlPointIndexBufferOffset,
                                                               const NS::UInteger instanceCount,
                                                               const NS::UInteger baseInstance) const
{
    sendMessage<void>(
        this,
        _MTL_PRIVATE_SEL(
            drawIndexedPatches_patchStart_patchCount_patchIndexBuffer_patchIndexBufferOffset_controlPointIndexBuffer_controlPointIndexBufferOffset_instanceCount_baseInstance_),
        numberOfPatchControlPoints,
        patchStart,
        patchCount,
        patchIndexBuffer,
        patchIndexBufferOffset,
        controlPointIndexBuffer,
        controlPointIndexBufferOffset,
        instanceCount,
        baseInstance);
}

_MTL_INLINE void MTL::RenderCommandEncoder::drawIndexedPatches(const NS::UInteger numberOfPatchControlPoints,
                                                               const Buffer*      patchIndexBuffer,
                                                               const NS::UInteger patchIndexBufferOffset,
                                                               const Buffer*      controlPointIndexBuffer,
                                                               const NS::UInteger controlPointIndexBufferOffset,
                                                               const Buffer*      indirectBuffer,
                                                               const NS::UInteger indirectBufferOffset) const
{
    sendMessage<void>(
        this,
        _MTL_PRIVATE_SEL(
            drawIndexedPatches_patchIndexBuffer_patchIndexBufferOffset_controlPointIndexBuffer_controlPointIndexBufferOffset_indirectBuffer_indirectBufferOffset_),
        numberOfPatchControlPoints,
        patchIndexBuffer,
        patchIndexBufferOffset,
        controlPointIndexBuffer,
        controlPointIndexBufferOffset,
        indirectBuffer,
        indirectBufferOffset);
}

_MTL_INLINE void MTL::RenderCommandEncoder::drawIndexedPrimitives(const PrimitiveType primitiveType,
                                                                  const NS::UInteger  indexCount,
                                                                  const IndexType     indexType,
                                                                  const Buffer*       indexBuffer,
                                                                  const NS::UInteger  indexBufferOffset,
                                                                  const NS::UInteger  instanceCount) const
{
    sendMessage<void>(
        this,
        _MTL_PRIVATE_SEL(drawIndexedPrimitives_indexCount_indexType_indexBuffer_indexBufferOffset_instanceCount_),
        primitiveType,
        indexCount,
        indexType,
        indexBuffer,
        indexBufferOffset,
        instanceCount);
}

_MTL_INLINE void MTL::RenderCommandEncoder::drawIndexedPrimitives(const PrimitiveType primitiveType,
                                                                  const NS::UInteger  indexCount,
                                                                  const IndexType     indexType,
                                                                  const Buffer*       indexBuffer,
                                                                  const NS::UInteger  indexBufferOffset) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(drawIndexedPrimitives_indexCount_indexType_indexBuffer_indexBufferOffset_),
                      primitiveType,
                      indexCount,
                      indexType,
                      indexBuffer,
                      indexBufferOffset);
}

_MTL_INLINE void MTL::RenderCommandEncoder::drawIndexedPrimitives(const PrimitiveType primitiveType,
                                                                  const NS::UInteger  indexCount,
                                                                  const IndexType     indexType,
                                                                  const Buffer*       indexBuffer,
                                                                  const NS::UInteger  indexBufferOffset,
                                                                  const NS::UInteger  instanceCount,
                                                                  const NS::Integer   baseVertex,
                                                                  const NS::UInteger  baseInstance) const
{
    sendMessage<void>(
        this,
        _MTL_PRIVATE_SEL(
            drawIndexedPrimitives_indexCount_indexType_indexBuffer_indexBufferOffset_instanceCount_baseVertex_baseInstance_),
        primitiveType,
        indexCount,
        indexType,
        indexBuffer,
        indexBufferOffset,
        instanceCount,
        baseVertex,
        baseInstance);
}

_MTL_INLINE void MTL::RenderCommandEncoder::drawIndexedPrimitives(const PrimitiveType primitiveType,
                                                                  const IndexType     indexType,
                                                                  const Buffer*       indexBuffer,
                                                                  const NS::UInteger  indexBufferOffset,
                                                                  const Buffer*       indirectBuffer,
                                                                  const NS::UInteger  indirectBufferOffset) const
{
    sendMessage<void>(
        this,
        _MTL_PRIVATE_SEL(
            drawIndexedPrimitives_indexType_indexBuffer_indexBufferOffset_indirectBuffer_indirectBufferOffset_),
        primitiveType,
        indexType,
        indexBuffer,
        indexBufferOffset,
        indirectBuffer,
        indirectBufferOffset);
}

_MTL_INLINE void MTL::RenderCommandEncoder::drawMeshThreadgroups(const Size& threadgroupsPerGrid,
                                                                 const Size& threadsPerObjectThreadgroup,
                                                                 const Size& threadsPerMeshThreadgroup) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(drawMeshThreadgroups_threadsPerObjectThreadgroup_threadsPerMeshThreadgroup_),
                      threadgroupsPerGrid,
                      threadsPerObjectThreadgroup,
                      threadsPerMeshThreadgroup);
}

_MTL_INLINE void MTL::RenderCommandEncoder::drawMeshThreadgroups(const Buffer*      indirectBuffer,
                                                                 const NS::UInteger indirectBufferOffset,
                                                                 const Size&        threadsPerObjectThreadgroup,
                                                                 const Size&        threadsPerMeshThreadgroup) const
{
    sendMessage<void>(
        this,
        _MTL_PRIVATE_SEL(
            drawMeshThreadgroupsWithIndirectBuffer_indirectBufferOffset_threadsPerObjectThreadgroup_threadsPerMeshThreadgroup_),
        indirectBuffer,
        indirectBufferOffset,
        threadsPerObjectThreadgroup,
        threadsPerMeshThreadgroup);
}

_MTL_INLINE void MTL::RenderCommandEncoder::drawMeshThreads(const Size& threadsPerGrid,
                                                            const Size& threadsPerObjectThreadgroup,
                                                            const Size& threadsPerMeshThreadgroup) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(drawMeshThreads_threadsPerObjectThreadgroup_threadsPerMeshThreadgroup_),
                      threadsPerGrid,
                      threadsPerObjectThreadgroup,
                      threadsPerMeshThreadgroup);
}

_MTL_INLINE void MTL::RenderCommandEncoder::drawPatches(const NS::UInteger numberOfPatchControlPoints,
                                                        const NS::UInteger patchStart,
                                                        const NS::UInteger patchCount,
                                                        const Buffer*      patchIndexBuffer,
                                                        const NS::UInteger patchIndexBufferOffset,
                                                        const NS::UInteger instanceCount,
                                                        const NS::UInteger baseInstance) const
{
    sendMessage<void>(
        this,
        _MTL_PRIVATE_SEL(
            drawPatches_patchStart_patchCount_patchIndexBuffer_patchIndexBufferOffset_instanceCount_baseInstance_),
        numberOfPatchControlPoints,
        patchStart,
        patchCount,
        patchIndexBuffer,
        patchIndexBufferOffset,
        instanceCount,
        baseInstance);
}

_MTL_INLINE void MTL::RenderCommandEncoder::drawPatches(const NS::UInteger numberOfPatchControlPoints,
                                                        const Buffer*      patchIndexBuffer,
                                                        const NS::UInteger patchIndexBufferOffset,
                                                        const Buffer*      indirectBuffer,
                                                        const NS::UInteger indirectBufferOffset) const
{
    sendMessage<void>(
        this,
        _MTL_PRIVATE_SEL(drawPatches_patchIndexBuffer_patchIndexBufferOffset_indirectBuffer_indirectBufferOffset_),
        numberOfPatchControlPoints,
        patchIndexBuffer,
        patchIndexBufferOffset,
        indirectBuffer,
        indirectBufferOffset);
}

_MTL_INLINE void MTL::RenderCommandEncoder::drawPrimitives(const PrimitiveType primitiveType,
                                                           const NS::UInteger  vertexStart,
                                                           const NS::UInteger  vertexCount,
                                                           const NS::UInteger  instanceCount) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(drawPrimitives_vertexStart_vertexCount_instanceCount_),
                      primitiveType,
                      vertexStart,
                      vertexCount,
                      instanceCount);
}

_MTL_INLINE void MTL::RenderCommandEncoder::drawPrimitives(const PrimitiveType primitiveType,
                                                           const NS::UInteger  vertexStart,
                                                           const NS::UInteger  vertexCount) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(drawPrimitives_vertexStart_vertexCount_), primitiveType, vertexStart, vertexCount);
}

_MTL_INLINE void MTL::RenderCommandEncoder::drawPrimitives(const PrimitiveType primitiveType,
                                                           const NS::UInteger  vertexStart,
                                                           const NS::UInteger  vertexCount,
                                                           const NS::UInteger  instanceCount,
                                                           const NS::UInteger  baseInstance) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(drawPrimitives_vertexStart_vertexCount_instanceCount_baseInstance_),
                      primitiveType,
                      vertexStart,
                      vertexCount,
                      instanceCount,
                      baseInstance);
}

_MTL_INLINE void MTL::RenderCommandEncoder::drawPrimitives(const PrimitiveType primitiveType,
                                                           const Buffer*       indirectBuffer,
                                                           const NS::UInteger  indirectBufferOffset) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(drawPrimitives_indirectBuffer_indirectBufferOffset_),
                      primitiveType,
                      indirectBuffer,
                      indirectBufferOffset);
}

_MTL_INLINE void MTL::RenderCommandEncoder::executeCommandsInBuffer(const IndirectCommandBuffer* indirectCommandBuffer,
                                                                    const NS::Range              executionRange) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(executeCommandsInBuffer_withRange_), indirectCommandBuffer, executionRange);
}

_MTL_INLINE void MTL::RenderCommandEncoder::executeCommandsInBuffer(const IndirectCommandBuffer* indirectCommandbuffer,
                                                                    const Buffer*                indirectRangeBuffer,
                                                                    const NS::UInteger indirectBufferOffset) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(executeCommandsInBuffer_indirectBuffer_indirectBufferOffset_),
                      indirectCommandbuffer,
                      indirectRangeBuffer,
                      indirectBufferOffset);
}

_MTL_INLINE void MTL::RenderCommandEncoder::memoryBarrier(const BarrierScope scope,
                                                          const RenderStages after,
                                                          const RenderStages before) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(memoryBarrierWithScope_afterStages_beforeStages_), scope, after, before);
}

_MTL_INLINE void MTL::RenderCommandEncoder::memoryBarrier(const Resource* const resources[],
                                                          const NS::UInteger    count,
                                                          const RenderStages    after,
                                                          const RenderStages    before) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(memoryBarrierWithResources_count_afterStages_beforeStages_),
                      resources,
                      count,
                      after,
                      before);
}

_MTL_INLINE void MTL::RenderCommandEncoder::sampleCountersInBuffer(const CounterSampleBuffer* sampleBuffer,
                                                                   const NS::UInteger         sampleIndex,
                                                                   const bool                 barrier) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(sampleCountersInBuffer_atSampleIndex_withBarrier_), sampleBuffer, sampleIndex, barrier);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setBlendColor(const float red,
                                                          const float green,
                                                          const float blue,
                                                          const float alpha) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBlendColorRed_green_blue_alpha_), red, green, blue, alpha);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setColorAttachmentMap(
    const LogicalToPhysicalColorAttachmentMap* mapping) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setColorAttachmentMap_), mapping);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setColorStoreAction(const StoreAction  storeAction,
                                                                const NS::UInteger colorAttachmentIndex) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setColorStoreAction_atIndex_), storeAction, colorAttachmentIndex);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setColorStoreActionOptions(const StoreActionOptions storeActionOptions,
                                                                       const NS::UInteger colorAttachmentIndex) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setColorStoreActionOptions_atIndex_), storeActionOptions, colorAttachmentIndex);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setCullMode(const CullMode cullMode) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setCullMode_), cullMode);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setDepthBias(const float depthBias,
                                                         const float slopeScale,
                                                         const float clamp) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDepthBias_slopeScale_clamp_), depthBias, slopeScale, clamp);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setDepthClipMode(const DepthClipMode depthClipMode) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDepthClipMode_), depthClipMode);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setDepthStencilState(const DepthStencilState* depthStencilState) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDepthStencilState_), depthStencilState);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setDepthStoreAction(const StoreAction storeAction) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDepthStoreAction_), storeAction);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setDepthStoreActionOptions(
    const StoreActionOptions storeActionOptions) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDepthStoreActionOptions_), storeActionOptions);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setDepthTestBounds(const float minBound, const float maxBound) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDepthTestMinBound_maxBound_), minBound, maxBound);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setFragmentAccelerationStructure(
    const AccelerationStructure* accelerationStructure, const NS::UInteger bufferIndex) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setFragmentAccelerationStructure_atBufferIndex_), accelerationStructure, bufferIndex);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setFragmentBuffer(const Buffer*      buffer,
                                                              const NS::UInteger offset,
                                                              const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFragmentBuffer_offset_atIndex_), buffer, offset, index);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setFragmentBufferOffset(const NS::UInteger offset,
                                                                    const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFragmentBufferOffset_atIndex_), offset, index);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setFragmentBuffers(const Buffer* const buffers[],
                                                               const NS::UInteger  offsets[],
                                                               const NS::Range     range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFragmentBuffers_offsets_withRange_), buffers, offsets, range);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setFragmentBytes(const void*        bytes,
                                                             const NS::UInteger length,
                                                             const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFragmentBytes_length_atIndex_), bytes, length, index);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setFragmentIntersectionFunctionTable(
    const IntersectionFunctionTable* intersectionFunctionTable, const NS::UInteger bufferIndex) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(setFragmentIntersectionFunctionTable_atBufferIndex_),
                      intersectionFunctionTable,
                      bufferIndex);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setFragmentIntersectionFunctionTables(
    const IntersectionFunctionTable* const intersectionFunctionTables[], const NS::Range range) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(setFragmentIntersectionFunctionTables_withBufferRange_),
                      intersectionFunctionTables,
                      range);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setFragmentSamplerState(const SamplerState* sampler,
                                                                    const NS::UInteger  index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFragmentSamplerState_atIndex_), sampler, index);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setFragmentSamplerState(const SamplerState* sampler,
                                                                    const float         lodMinClamp,
                                                                    const float         lodMaxClamp,
                                                                    const NS::UInteger  index) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(setFragmentSamplerState_lodMinClamp_lodMaxClamp_atIndex_),
                      sampler,
                      lodMinClamp,
                      lodMaxClamp,
                      index);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setFragmentSamplerStates(const SamplerState* const samplers[],
                                                                     const NS::Range           range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFragmentSamplerStates_withRange_), samplers, range);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setFragmentSamplerStates(const SamplerState* const samplers[],
                                                                     const float               lodMinClamps[],
                                                                     const float               lodMaxClamps[],
                                                                     const NS::Range           range) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(setFragmentSamplerStates_lodMinClamps_lodMaxClamps_withRange_),
                      samplers,
                      lodMinClamps,
                      lodMaxClamps,
                      range);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setFragmentTexture(const Texture* texture, const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFragmentTexture_atIndex_), texture, index);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setFragmentTextures(const Texture* const textures[],
                                                                const NS::Range      range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFragmentTextures_withRange_), textures, range);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setFragmentVisibleFunctionTable(const VisibleFunctionTable* functionTable,
                                                                            const NS::UInteger bufferIndex) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setFragmentVisibleFunctionTable_atBufferIndex_), functionTable, bufferIndex);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setFragmentVisibleFunctionTables(
    const VisibleFunctionTable* const functionTables[], const NS::Range range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFragmentVisibleFunctionTables_withBufferRange_), functionTables, range);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setFrontFacingWinding(const Winding frontFacingWinding) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFrontFacingWinding_), frontFacingWinding);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setMeshBuffer(const Buffer*      buffer,
                                                          const NS::UInteger offset,
                                                          const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMeshBuffer_offset_atIndex_), buffer, offset, index);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setMeshBufferOffset(const NS::UInteger offset,
                                                                const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMeshBufferOffset_atIndex_), offset, index);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setMeshBuffers(const Buffer* const buffers[],
                                                           const NS::UInteger* offsets,
                                                           const NS::Range     range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMeshBuffers_offsets_withRange_), buffers, offsets, range);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setMeshBytes(const void*        bytes,
                                                         const NS::UInteger length,
                                                         const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMeshBytes_length_atIndex_), bytes, length, index);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setMeshSamplerState(const SamplerState* sampler,
                                                                const NS::UInteger  index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMeshSamplerState_atIndex_), sampler, index);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setMeshSamplerState(const SamplerState* sampler,
                                                                const float         lodMinClamp,
                                                                const float         lodMaxClamp,
                                                                const NS::UInteger  index) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(setMeshSamplerState_lodMinClamp_lodMaxClamp_atIndex_),
                      sampler,
                      lodMinClamp,
                      lodMaxClamp,
                      index);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setMeshSamplerStates(const SamplerState* const samplers[],
                                                                 const NS::Range           range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMeshSamplerStates_withRange_), samplers, range);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setMeshSamplerStates(const SamplerState* const samplers[],
                                                                 const float*              lodMinClamps,
                                                                 const float*              lodMaxClamps,
                                                                 const NS::Range           range) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(setMeshSamplerStates_lodMinClamps_lodMaxClamps_withRange_),
                      samplers,
                      lodMinClamps,
                      lodMaxClamps,
                      range);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setMeshTexture(const Texture* texture, const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMeshTexture_atIndex_), texture, index);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setMeshTextures(const Texture* const textures[],
                                                            const NS::Range      range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMeshTextures_withRange_), textures, range);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setObjectBuffer(const Buffer*      buffer,
                                                            const NS::UInteger offset,
                                                            const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setObjectBuffer_offset_atIndex_), buffer, offset, index);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setObjectBufferOffset(const NS::UInteger offset,
                                                                  const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setObjectBufferOffset_atIndex_), offset, index);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setObjectBuffers(const Buffer* const buffers[],
                                                             const NS::UInteger* offsets,
                                                             const NS::Range     range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setObjectBuffers_offsets_withRange_), buffers, offsets, range);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setObjectBytes(const void*        bytes,
                                                           const NS::UInteger length,
                                                           const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setObjectBytes_length_atIndex_), bytes, length, index);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setObjectSamplerState(const SamplerState* sampler,
                                                                  const NS::UInteger  index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setObjectSamplerState_atIndex_), sampler, index);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setObjectSamplerState(const SamplerState* sampler,
                                                                  const float         lodMinClamp,
                                                                  const float         lodMaxClamp,
                                                                  const NS::UInteger  index) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(setObjectSamplerState_lodMinClamp_lodMaxClamp_atIndex_),
                      sampler,
                      lodMinClamp,
                      lodMaxClamp,
                      index);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setObjectSamplerStates(const SamplerState* const samplers[],
                                                                   const NS::Range           range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setObjectSamplerStates_withRange_), samplers, range);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setObjectSamplerStates(const SamplerState* const samplers[],
                                                                   const float*              lodMinClamps,
                                                                   const float*              lodMaxClamps,
                                                                   const NS::Range           range) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(setObjectSamplerStates_lodMinClamps_lodMaxClamps_withRange_),
                      samplers,
                      lodMinClamps,
                      lodMaxClamps,
                      range);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setObjectTexture(const Texture* texture, const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setObjectTexture_atIndex_), texture, index);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setObjectTextures(const Texture* const textures[],
                                                              const NS::Range      range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setObjectTextures_withRange_), textures, range);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setObjectThreadgroupMemoryLength(const NS::UInteger length,
                                                                             const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setObjectThreadgroupMemoryLength_atIndex_), length, index);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setRenderPipelineState(const RenderPipelineState* pipelineState) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRenderPipelineState_), pipelineState);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setScissorRect(const ScissorRect& rect) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setScissorRect_), rect);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setScissorRects(const ScissorRect* scissorRects,
                                                            const NS::UInteger count) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setScissorRects_count_), scissorRects, count);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setStencilReferenceValue(const uint32_t referenceValue) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setStencilReferenceValue_), referenceValue);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setStencilReferenceValues(const uint32_t frontReferenceValue,
                                                                      const uint32_t backReferenceValue) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(setStencilFrontReferenceValue_backReferenceValue_),
                      frontReferenceValue,
                      backReferenceValue);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setStencilStoreAction(const StoreAction storeAction) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setStencilStoreAction_), storeAction);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setStencilStoreActionOptions(
    const StoreActionOptions storeActionOptions) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setStencilStoreActionOptions_), storeActionOptions);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setTessellationFactorBuffer(const Buffer*      buffer,
                                                                        const NS::UInteger offset,
                                                                        const NS::UInteger instanceStride) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setTessellationFactorBuffer_offset_instanceStride_), buffer, offset, instanceStride);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setTessellationFactorScale(const float scale) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTessellationFactorScale_), scale);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setThreadgroupMemoryLength(const NS::UInteger length,
                                                                       const NS::UInteger offset,
                                                                       const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setThreadgroupMemoryLength_offset_atIndex_), length, offset, index);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setTileAccelerationStructure(
    const AccelerationStructure* accelerationStructure, const NS::UInteger bufferIndex) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setTileAccelerationStructure_atBufferIndex_), accelerationStructure, bufferIndex);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setTileBuffer(const Buffer*      buffer,
                                                          const NS::UInteger offset,
                                                          const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTileBuffer_offset_atIndex_), buffer, offset, index);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setTileBufferOffset(const NS::UInteger offset,
                                                                const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTileBufferOffset_atIndex_), offset, index);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setTileBuffers(const Buffer* const buffers[],
                                                           const NS::UInteger* offsets,
                                                           const NS::Range     range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTileBuffers_offsets_withRange_), buffers, offsets, range);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setTileBytes(const void*        bytes,
                                                         const NS::UInteger length,
                                                         const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTileBytes_length_atIndex_), bytes, length, index);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setTileIntersectionFunctionTable(
    const IntersectionFunctionTable* intersectionFunctionTable, const NS::UInteger bufferIndex) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(setTileIntersectionFunctionTable_atBufferIndex_),
                      intersectionFunctionTable,
                      bufferIndex);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setTileIntersectionFunctionTables(
    const IntersectionFunctionTable* const intersectionFunctionTables[], const NS::Range range) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setTileIntersectionFunctionTables_withBufferRange_), intersectionFunctionTables, range);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setTileSamplerState(const SamplerState* sampler,
                                                                const NS::UInteger  index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTileSamplerState_atIndex_), sampler, index);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setTileSamplerState(const SamplerState* sampler,
                                                                const float         lodMinClamp,
                                                                const float         lodMaxClamp,
                                                                const NS::UInteger  index) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(setTileSamplerState_lodMinClamp_lodMaxClamp_atIndex_),
                      sampler,
                      lodMinClamp,
                      lodMaxClamp,
                      index);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setTileSamplerStates(const SamplerState* const samplers[],
                                                                 const NS::Range           range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTileSamplerStates_withRange_), samplers, range);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setTileSamplerStates(const SamplerState* const samplers[],
                                                                 const float               lodMinClamps[],
                                                                 const float               lodMaxClamps[],
                                                                 const NS::Range           range) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(setTileSamplerStates_lodMinClamps_lodMaxClamps_withRange_),
                      samplers,
                      lodMinClamps,
                      lodMaxClamps,
                      range);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setTileTexture(const Texture* texture, const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTileTexture_atIndex_), texture, index);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setTileTextures(const Texture* const textures[],
                                                            const NS::Range      range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTileTextures_withRange_), textures, range);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setTileVisibleFunctionTable(const VisibleFunctionTable* functionTable,
                                                                        const NS::UInteger          bufferIndex) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTileVisibleFunctionTable_atBufferIndex_), functionTable, bufferIndex);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setTileVisibleFunctionTables(
    const VisibleFunctionTable* const functionTables[], const NS::Range range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTileVisibleFunctionTables_withBufferRange_), functionTables, range);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setTriangleFillMode(const TriangleFillMode fillMode) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTriangleFillMode_), fillMode);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setVertexAccelerationStructure(
    const AccelerationStructure* accelerationStructure, const NS::UInteger bufferIndex) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setVertexAccelerationStructure_atBufferIndex_), accelerationStructure, bufferIndex);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setVertexAmplificationCount(
    const NS::UInteger count, const VertexAmplificationViewMapping* viewMappings) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVertexAmplificationCount_viewMappings_), count, viewMappings);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setVertexBuffer(const Buffer*      buffer,
                                                            const NS::UInteger offset,
                                                            const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVertexBuffer_offset_atIndex_), buffer, offset, index);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setVertexBuffer(const Buffer*      buffer,
                                                            const NS::UInteger offset,
                                                            const NS::UInteger stride,
                                                            const NS::UInteger index) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setVertexBuffer_offset_attributeStride_atIndex_), buffer, offset, stride, index);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setVertexBufferOffset(const NS::UInteger offset,
                                                                  const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVertexBufferOffset_atIndex_), offset, index);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setVertexBufferOffset(const NS::UInteger offset,
                                                                  const NS::UInteger stride,
                                                                  const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVertexBufferOffset_attributeStride_atIndex_), offset, stride, index);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setVertexBuffers(const Buffer* const buffers[],
                                                             const NS::UInteger  offsets[],
                                                             const NS::Range     range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVertexBuffers_offsets_withRange_), buffers, offsets, range);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setVertexBuffers(const Buffer* const buffers[],
                                                             const NS::UInteger* offsets,
                                                             const NS::UInteger* strides,
                                                             const NS::Range     range) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setVertexBuffers_offsets_attributeStrides_withRange_), buffers, offsets, strides, range);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setVertexBytes(const void*        bytes,
                                                           const NS::UInteger length,
                                                           const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVertexBytes_length_atIndex_), bytes, length, index);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setVertexBytes(const void*        bytes,
                                                           const NS::UInteger length,
                                                           const NS::UInteger stride,
                                                           const NS::UInteger index) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setVertexBytes_length_attributeStride_atIndex_), bytes, length, stride, index);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setVertexIntersectionFunctionTable(
    const IntersectionFunctionTable* intersectionFunctionTable, const NS::UInteger bufferIndex) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(setVertexIntersectionFunctionTable_atBufferIndex_),
                      intersectionFunctionTable,
                      bufferIndex);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setVertexIntersectionFunctionTables(
    const IntersectionFunctionTable* const intersectionFunctionTables[], const NS::Range range) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(setVertexIntersectionFunctionTables_withBufferRange_),
                      intersectionFunctionTables,
                      range);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setVertexSamplerState(const SamplerState* sampler,
                                                                  const NS::UInteger  index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVertexSamplerState_atIndex_), sampler, index);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setVertexSamplerState(const SamplerState* sampler,
                                                                  const float         lodMinClamp,
                                                                  const float         lodMaxClamp,
                                                                  const NS::UInteger  index) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(setVertexSamplerState_lodMinClamp_lodMaxClamp_atIndex_),
                      sampler,
                      lodMinClamp,
                      lodMaxClamp,
                      index);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setVertexSamplerStates(const SamplerState* const samplers[],
                                                                   const NS::Range           range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVertexSamplerStates_withRange_), samplers, range);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setVertexSamplerStates(const SamplerState* const samplers[],
                                                                   const float               lodMinClamps[],
                                                                   const float               lodMaxClamps[],
                                                                   const NS::Range           range) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(setVertexSamplerStates_lodMinClamps_lodMaxClamps_withRange_),
                      samplers,
                      lodMinClamps,
                      lodMaxClamps,
                      range);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setVertexTexture(const Texture* texture, const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVertexTexture_atIndex_), texture, index);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setVertexTextures(const Texture* const textures[],
                                                              const NS::Range      range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVertexTextures_withRange_), textures, range);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setVertexVisibleFunctionTable(const VisibleFunctionTable* functionTable,
                                                                          const NS::UInteger          bufferIndex) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVertexVisibleFunctionTable_atBufferIndex_), functionTable, bufferIndex);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setVertexVisibleFunctionTables(
    const VisibleFunctionTable* const functionTables[], const NS::Range range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVertexVisibleFunctionTables_withBufferRange_), functionTables, range);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setViewport(const Viewport& viewport) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setViewport_), viewport);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setViewports(const Viewport* viewports, const NS::UInteger count) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setViewports_count_), viewports, count);
}

_MTL_INLINE void MTL::RenderCommandEncoder::setVisibilityResultMode(const VisibilityResultMode mode,
                                                                    const NS::UInteger         offset) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVisibilityResultMode_offset_), mode, offset);
}

_MTL_INLINE void MTL::RenderCommandEncoder::textureBarrier() const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(textureBarrier));
}

_MTL_INLINE NS::UInteger MTL::RenderCommandEncoder::tileHeight() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(tileHeight));
}

_MTL_INLINE NS::UInteger MTL::RenderCommandEncoder::tileWidth() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(tileWidth));
}

_MTL_INLINE void MTL::RenderCommandEncoder::updateFence(const Fence* fence, const RenderStages stages) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(updateFence_afterStages_), fence, stages);
}

_MTL_INLINE void MTL::RenderCommandEncoder::useHeap(const Heap* heap) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(useHeap_), heap);
}

_MTL_INLINE void MTL::RenderCommandEncoder::useHeap(const Heap* heap, const RenderStages stages) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(useHeap_stages_), heap, stages);
}

_MTL_INLINE void MTL::RenderCommandEncoder::useHeaps(const Heap* const heaps[], const NS::UInteger count) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(useHeaps_count_), heaps, count);
}

_MTL_INLINE void MTL::RenderCommandEncoder::useHeaps(const Heap* const  heaps[],
                                                     const NS::UInteger count,
                                                     const RenderStages stages) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(useHeaps_count_stages_), heaps, count, stages);
}

_MTL_INLINE void MTL::RenderCommandEncoder::useResource(const Resource* resource, const ResourceUsage usage) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(useResource_usage_), resource, usage);
}

_MTL_INLINE void MTL::RenderCommandEncoder::useResource(const Resource*     resource,
                                                        const ResourceUsage usage,
                                                        const RenderStages  stages) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(useResource_usage_stages_), resource, usage, stages);
}

_MTL_INLINE void MTL::RenderCommandEncoder::useResources(const Resource* const resources[],
                                                         const NS::UInteger    count,
                                                         const ResourceUsage   usage) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(useResources_count_usage_), resources, count, usage);
}

_MTL_INLINE void MTL::RenderCommandEncoder::useResources(const Resource* const resources[],
                                                         const NS::UInteger    count,
                                                         const ResourceUsage   usage,
                                                         const RenderStages    stages) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(useResources_count_usage_stages_), resources, count, usage, stages);
}

_MTL_INLINE void MTL::RenderCommandEncoder::waitForFence(const Fence* fence, const RenderStages stages) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(waitForFence_beforeStages_), fence, stages);
}
