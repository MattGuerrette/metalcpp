//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTL4RenderCommandEncoder.hpp
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
#include "MTL4CommandEncoder.hpp"
#include "MTL4Counters.hpp"
#include "MTLArgument.hpp"
#include "MTLDefines.hpp"
#include "MTLGPUAddress.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"
#include "MTLRenderCommandEncoder.hpp"
#include "MTLRenderPass.hpp"
#include "MTLTypes.hpp"

namespace MTL4
{
    class ArgumentTable;
    class CounterHeap;
} // namespace MTL4

namespace MTL
{
    class DepthStencilState;
    class IndirectCommandBuffer;
    class LogicalToPhysicalColorAttachmentMap;
    class RenderPipelineState;
    struct ScissorRect;
    struct VertexAmplificationViewMapping;
    struct Viewport;

} // namespace MTL
namespace MTL4
{
    _MTL_OPTIONS(NS::UInteger, RenderEncoderOptions){
        RenderEncoderOptionNone       = 0,
        RenderEncoderOptionSuspending = 1,
        RenderEncoderOptionResuming   = 1 << 1,
    };

    /// @see https://developer.apple.com/documentation/metal/mtl4rendercommandencoder
    class RenderCommandEncoder : public NS::Referencing<RenderCommandEncoder, CommandEncoder>
    {
    public:
        void dispatchThreadsPerTile(const MTL::Size &threadsPerTile) const;

        void drawIndexedPrimitives(MTL::PrimitiveType primitiveType,
                                   NS::UInteger       indexCount,
                                   MTL::IndexType     indexType,
                                   MTL::GPUAddress    indexBuffer,
                                   NS::UInteger       indexBufferLength) const;
        void drawIndexedPrimitives(MTL::PrimitiveType primitiveType,
                                   NS::UInteger       indexCount,
                                   MTL::IndexType     indexType,
                                   MTL::GPUAddress    indexBuffer,
                                   NS::UInteger       indexBufferLength,
                                   NS::UInteger       instanceCount) const;
        void drawIndexedPrimitives(MTL::PrimitiveType primitiveType,
                                   NS::UInteger       indexCount,
                                   MTL::IndexType     indexType,
                                   MTL::GPUAddress    indexBuffer,
                                   NS::UInteger       indexBufferLength,
                                   NS::UInteger       instanceCount,
                                   NS::Integer        baseVertex,
                                   NS::UInteger       baseInstance) const;
        void drawIndexedPrimitives(MTL::PrimitiveType primitiveType,
                                   MTL::IndexType     indexType,
                                   MTL::GPUAddress    indexBuffer,
                                   NS::UInteger       indexBufferLength,
                                   MTL::GPUAddress    indirectBuffer) const;

        void drawMeshThreadgroups(const MTL::Size &threadgroupsPerGrid,
                                  const MTL::Size &threadsPerObjectThreadgroup,
                                  const MTL::Size &threadsPerMeshThreadgroup) const;
        void drawMeshThreadgroups(MTL::GPUAddress  indirectBuffer,
                                  const MTL::Size &threadsPerObjectThreadgroup,
                                  const MTL::Size &threadsPerMeshThreadgroup) const;

        void drawMeshThreads(const MTL::Size &threadsPerGrid,
                             const MTL::Size &threadsPerObjectThreadgroup,
                             const MTL::Size &threadsPerMeshThreadgroup) const;

        void drawPrimitives(MTL::PrimitiveType primitiveType, NS::UInteger vertexStart, NS::UInteger vertexCount) const;
        void drawPrimitives(MTL::PrimitiveType primitiveType,
                            NS::UInteger       vertexStart,
                            NS::UInteger       vertexCount,
                            NS::UInteger       instanceCount) const;
        void drawPrimitives(MTL::PrimitiveType primitiveType,
                            NS::UInteger       vertexStart,
                            NS::UInteger       vertexCount,
                            NS::UInteger       instanceCount,
                            NS::UInteger       baseInstance) const;
        void drawPrimitives(MTL::PrimitiveType primitiveType, MTL::GPUAddress indirectBuffer) const;

        void executeCommandsInBuffer(const MTL::IndirectCommandBuffer *indirectCommandBuffer,
                                     NS::Range                         executionRange) const;
        void executeCommandsInBuffer(const MTL::IndirectCommandBuffer *indirectCommandBuffer,
                                     MTL::GPUAddress                   indirectRangeBuffer) const;

        void setArgumentTable(const ArgumentTable *argumentTable, MTL::RenderStages stages) const;

        void setBlendColor(float red, float green, float blue, float alpha) const;

        void setColorAttachmentMap(const MTL::LogicalToPhysicalColorAttachmentMap *mapping) const;

        void setColorStoreAction(MTL::StoreAction storeAction, NS::UInteger colorAttachmentIndex) const;

        void setCullMode(MTL::CullMode cullMode) const;

        void setDepthBias(float depthBias, float slopeScale, float clamp) const;

        void setDepthClipMode(MTL::DepthClipMode depthClipMode) const;

        void setDepthStencilState(const MTL::DepthStencilState *depthStencilState) const;

        void setDepthStoreAction(MTL::StoreAction storeAction) const;

        void setDepthTestBounds(float minBound, float maxBound) const;

        void setFrontFacingWinding(MTL::Winding frontFacingWinding) const;

        void setObjectThreadgroupMemoryLength(NS::UInteger length, NS::UInteger index) const;

        void setRenderPipelineState(const MTL::RenderPipelineState *pipelineState) const;

        void setScissorRect(const MTL::ScissorRect &rect) const;
        void setScissorRects(const MTL::ScissorRect *scissorRects, NS::UInteger count) const;

        void setStencilReferenceValue(uint32_t referenceValue) const;
        void setStencilReferenceValues(uint32_t frontReferenceValue, uint32_t backReferenceValue) const;

        void setStencilStoreAction(MTL::StoreAction storeAction) const;

        void setThreadgroupMemoryLength(NS::UInteger length, NS::UInteger offset, NS::UInteger index) const;

        void setTriangleFillMode(MTL::TriangleFillMode fillMode) const;

        void setVertexAmplificationCount(NS::UInteger                               count,
                                         const MTL::VertexAmplificationViewMapping *viewMappings) const;

        void setViewport(const MTL::Viewport &viewport) const;
        void setViewports(const MTL::Viewport *viewports, NS::UInteger count) const;

        void setVisibilityResultMode(MTL::VisibilityResultMode mode, NS::UInteger offset) const;

        [[nodiscard]] NS::UInteger tileHeight() const;

        [[nodiscard]] NS::UInteger tileWidth() const;

        void writeTimestamp(TimestampGranularity granularity,
                            MTL::RenderStages    stage,
                            const CounterHeap   *counterHeap,
                            NS::UInteger         index) const;
    };

} // namespace MTL4
_MTL_INLINE void MTL4::RenderCommandEncoder::dispatchThreadsPerTile(const MTL::Size &threadsPerTile) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(dispatchThreadsPerTile_), threadsPerTile);
}

_MTL_INLINE void MTL4::RenderCommandEncoder::drawIndexedPrimitives(const MTL::PrimitiveType primitiveType,
                                                                   const NS::UInteger       indexCount,
                                                                   const MTL::IndexType     indexType,
                                                                   const MTL::GPUAddress    indexBuffer,
                                                                   const NS::UInteger       indexBufferLength) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(drawIndexedPrimitives_indexCount_indexType_indexBuffer_indexBufferLength_),
                      primitiveType,
                      indexCount,
                      indexType,
                      indexBuffer,
                      indexBufferLength);
}

_MTL_INLINE void MTL4::RenderCommandEncoder::drawIndexedPrimitives(const MTL::PrimitiveType primitiveType,
                                                                   const NS::UInteger       indexCount,
                                                                   const MTL::IndexType     indexType,
                                                                   const MTL::GPUAddress    indexBuffer,
                                                                   const NS::UInteger       indexBufferLength,
                                                                   const NS::UInteger       instanceCount) const
{
    sendMessage<void>(
        this,
        _MTL_PRIVATE_SEL(drawIndexedPrimitives_indexCount_indexType_indexBuffer_indexBufferLength_instanceCount_),
        primitiveType,
        indexCount,
        indexType,
        indexBuffer,
        indexBufferLength,
        instanceCount);
}

_MTL_INLINE void MTL4::RenderCommandEncoder::drawIndexedPrimitives(const MTL::PrimitiveType primitiveType,
                                                                   const NS::UInteger       indexCount,
                                                                   const MTL::IndexType     indexType,
                                                                   const MTL::GPUAddress    indexBuffer,
                                                                   const NS::UInteger       indexBufferLength,
                                                                   const NS::UInteger       instanceCount,
                                                                   const NS::Integer        baseVertex,
                                                                   const NS::UInteger       baseInstance) const
{
    sendMessage<void>(
        this,
        _MTL_PRIVATE_SEL(
            drawIndexedPrimitives_indexCount_indexType_indexBuffer_indexBufferLength_instanceCount_baseVertex_baseInstance_),
        primitiveType,
        indexCount,
        indexType,
        indexBuffer,
        indexBufferLength,
        instanceCount,
        baseVertex,
        baseInstance);
}

_MTL_INLINE void MTL4::RenderCommandEncoder::drawIndexedPrimitives(const MTL::PrimitiveType primitiveType,
                                                                   const MTL::IndexType     indexType,
                                                                   const MTL::GPUAddress    indexBuffer,
                                                                   const NS::UInteger       indexBufferLength,
                                                                   const MTL::GPUAddress    indirectBuffer) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(drawIndexedPrimitives_indexType_indexBuffer_indexBufferLength_indirectBuffer_),
                      primitiveType,
                      indexType,
                      indexBuffer,
                      indexBufferLength,
                      indirectBuffer);
}

_MTL_INLINE void MTL4::RenderCommandEncoder::drawMeshThreadgroups(const MTL::Size &threadgroupsPerGrid,
                                                                  const MTL::Size &threadsPerObjectThreadgroup,
                                                                  const MTL::Size &threadsPerMeshThreadgroup) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(drawMeshThreadgroups_threadsPerObjectThreadgroup_threadsPerMeshThreadgroup_),
                      threadgroupsPerGrid,
                      threadsPerObjectThreadgroup,
                      threadsPerMeshThreadgroup);
}

_MTL_INLINE void MTL4::RenderCommandEncoder::drawMeshThreadgroups(const MTL::GPUAddress indirectBuffer,
                                                                  const MTL::Size      &threadsPerObjectThreadgroup,
                                                                  const MTL::Size      &threadsPerMeshThreadgroup) const
{
    sendMessage<void>(
        this,
        _MTL_PRIVATE_SEL(drawMeshThreadgroupsWithIndirectBuffer_threadsPerObjectThreadgroup_threadsPerMeshThreadgroup_),
        indirectBuffer,
        threadsPerObjectThreadgroup,
        threadsPerMeshThreadgroup);
}

_MTL_INLINE void MTL4::RenderCommandEncoder::drawMeshThreads(const MTL::Size &threadsPerGrid,
                                                             const MTL::Size &threadsPerObjectThreadgroup,
                                                             const MTL::Size &threadsPerMeshThreadgroup) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(drawMeshThreads_threadsPerObjectThreadgroup_threadsPerMeshThreadgroup_),
                      threadsPerGrid,
                      threadsPerObjectThreadgroup,
                      threadsPerMeshThreadgroup);
}

_MTL_INLINE void MTL4::RenderCommandEncoder::drawPrimitives(const MTL::PrimitiveType primitiveType,
                                                            const NS::UInteger       vertexStart,
                                                            const NS::UInteger       vertexCount) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(drawPrimitives_vertexStart_vertexCount_), primitiveType, vertexStart, vertexCount);
}

_MTL_INLINE void MTL4::RenderCommandEncoder::drawPrimitives(const MTL::PrimitiveType primitiveType,
                                                            const NS::UInteger       vertexStart,
                                                            const NS::UInteger       vertexCount,
                                                            const NS::UInteger       instanceCount) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(drawPrimitives_vertexStart_vertexCount_instanceCount_),
                      primitiveType,
                      vertexStart,
                      vertexCount,
                      instanceCount);
}

_MTL_INLINE void MTL4::RenderCommandEncoder::drawPrimitives(const MTL::PrimitiveType primitiveType,
                                                            const NS::UInteger       vertexStart,
                                                            const NS::UInteger       vertexCount,
                                                            const NS::UInteger       instanceCount,
                                                            const NS::UInteger       baseInstance) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(drawPrimitives_vertexStart_vertexCount_instanceCount_baseInstance_),
                      primitiveType,
                      vertexStart,
                      vertexCount,
                      instanceCount,
                      baseInstance);
}

_MTL_INLINE void MTL4::RenderCommandEncoder::drawPrimitives(const MTL::PrimitiveType primitiveType,
                                                            const MTL::GPUAddress    indirectBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(drawPrimitives_indirectBuffer_), primitiveType, indirectBuffer);
}

_MTL_INLINE void MTL4::RenderCommandEncoder::executeCommandsInBuffer(
    const MTL::IndirectCommandBuffer *indirectCommandBuffer, const NS::Range executionRange) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(executeCommandsInBuffer_withRange_), indirectCommandBuffer, executionRange);
}

_MTL_INLINE void MTL4::RenderCommandEncoder::executeCommandsInBuffer(
    const MTL::IndirectCommandBuffer *indirectCommandBuffer, const MTL::GPUAddress indirectRangeBuffer) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(executeCommandsInBuffer_indirectBuffer_), indirectCommandBuffer, indirectRangeBuffer);
}

_MTL_INLINE void MTL4::RenderCommandEncoder::setArgumentTable(const ArgumentTable    *argumentTable,
                                                              const MTL::RenderStages stages) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setArgumentTable_atStages_), argumentTable, stages);
}

_MTL_INLINE void MTL4::RenderCommandEncoder::setBlendColor(const float red,
                                                           const float green,
                                                           const float blue,
                                                           const float alpha) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBlendColorRed_green_blue_alpha_), red, green, blue, alpha);
}

_MTL_INLINE void MTL4::RenderCommandEncoder::setColorAttachmentMap(
    const MTL::LogicalToPhysicalColorAttachmentMap *mapping) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setColorAttachmentMap_), mapping);
}

_MTL_INLINE void MTL4::RenderCommandEncoder::setColorStoreAction(const MTL::StoreAction storeAction,
                                                                 const NS::UInteger     colorAttachmentIndex) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setColorStoreAction_atIndex_), storeAction, colorAttachmentIndex);
}

_MTL_INLINE void MTL4::RenderCommandEncoder::setCullMode(const MTL::CullMode cullMode) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setCullMode_), cullMode);
}

_MTL_INLINE void MTL4::RenderCommandEncoder::setDepthBias(const float depthBias,
                                                          const float slopeScale,
                                                          const float clamp) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDepthBias_slopeScale_clamp_), depthBias, slopeScale, clamp);
}

_MTL_INLINE void MTL4::RenderCommandEncoder::setDepthClipMode(const MTL::DepthClipMode depthClipMode) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDepthClipMode_), depthClipMode);
}

_MTL_INLINE void MTL4::RenderCommandEncoder::setDepthStencilState(const MTL::DepthStencilState *depthStencilState) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDepthStencilState_), depthStencilState);
}

_MTL_INLINE void MTL4::RenderCommandEncoder::setDepthStoreAction(const MTL::StoreAction storeAction) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDepthStoreAction_), storeAction);
}

_MTL_INLINE void MTL4::RenderCommandEncoder::setDepthTestBounds(const float minBound, const float maxBound) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDepthTestMinBound_maxBound_), minBound, maxBound);
}

_MTL_INLINE void MTL4::RenderCommandEncoder::setFrontFacingWinding(const MTL::Winding frontFacingWinding) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFrontFacingWinding_), frontFacingWinding);
}

_MTL_INLINE void MTL4::RenderCommandEncoder::setObjectThreadgroupMemoryLength(const NS::UInteger length,
                                                                              const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setObjectThreadgroupMemoryLength_atIndex_), length, index);
}

_MTL_INLINE void MTL4::RenderCommandEncoder::setRenderPipelineState(const MTL::RenderPipelineState *pipelineState) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRenderPipelineState_), pipelineState);
}

_MTL_INLINE void MTL4::RenderCommandEncoder::setScissorRect(const MTL::ScissorRect &rect) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setScissorRect_), rect);
}

_MTL_INLINE void MTL4::RenderCommandEncoder::setScissorRects(const MTL::ScissorRect *scissorRects,
                                                             const NS::UInteger      count) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setScissorRects_count_), scissorRects, count);
}

_MTL_INLINE void MTL4::RenderCommandEncoder::setStencilReferenceValue(const uint32_t referenceValue) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setStencilReferenceValue_), referenceValue);
}

_MTL_INLINE void MTL4::RenderCommandEncoder::setStencilReferenceValues(const uint32_t frontReferenceValue,
                                                                       const uint32_t backReferenceValue) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(setStencilFrontReferenceValue_backReferenceValue_),
                      frontReferenceValue,
                      backReferenceValue);
}

_MTL_INLINE void MTL4::RenderCommandEncoder::setStencilStoreAction(const MTL::StoreAction storeAction) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setStencilStoreAction_), storeAction);
}

_MTL_INLINE void MTL4::RenderCommandEncoder::setThreadgroupMemoryLength(const NS::UInteger length,
                                                                        const NS::UInteger offset,
                                                                        const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setThreadgroupMemoryLength_offset_atIndex_), length, offset, index);
}

_MTL_INLINE void MTL4::RenderCommandEncoder::setTriangleFillMode(const MTL::TriangleFillMode fillMode) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTriangleFillMode_), fillMode);
}

_MTL_INLINE void MTL4::RenderCommandEncoder::setVertexAmplificationCount(
    const NS::UInteger count, const MTL::VertexAmplificationViewMapping *viewMappings) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVertexAmplificationCount_viewMappings_), count, viewMappings);
}

_MTL_INLINE void MTL4::RenderCommandEncoder::setViewport(const MTL::Viewport &viewport) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setViewport_), viewport);
}

_MTL_INLINE void MTL4::RenderCommandEncoder::setViewports(const MTL::Viewport *viewports,
                                                          const NS::UInteger   count) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setViewports_count_), viewports, count);
}

_MTL_INLINE void MTL4::RenderCommandEncoder::setVisibilityResultMode(const MTL::VisibilityResultMode mode,
                                                                     const NS::UInteger              offset) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVisibilityResultMode_offset_), mode, offset);
}

_MTL_INLINE NS::UInteger MTL4::RenderCommandEncoder::tileHeight() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(tileHeight));
}

_MTL_INLINE NS::UInteger MTL4::RenderCommandEncoder::tileWidth() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(tileWidth));
}

_MTL_INLINE void MTL4::RenderCommandEncoder::writeTimestamp(const TimestampGranularity granularity,
                                                            const MTL::RenderStages    stage,
                                                            const CounterHeap         *counterHeap,
                                                            const NS::UInteger         index) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(writeTimestampWithGranularity_afterStage_intoHeap_atIndex_),
                      granularity,
                      stage,
                      counterHeap,
                      index);
}
