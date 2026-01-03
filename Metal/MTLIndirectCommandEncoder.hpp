//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLIndirectCommandEncoder.hpp
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
#include "MTLArgument.hpp"
#include "MTLDefines.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"
#include "MTLRenderCommandEncoder.hpp"
#include "MTLTypes.hpp"

namespace MTL
{
    class Buffer;
    class ComputePipelineState;
    class RenderPipelineState;

    /// @see https://developer.apple.com/documentation/metal/mtlindirectrendercommand?language=objc
    class IndirectRenderCommand : public NS::Referencing<IndirectRenderCommand>
    {
    public:
        void clearBarrier() const;

        void drawIndexedPatches(NS::UInteger  numberOfPatchControlPoints,
                                NS::UInteger  patchStart,
                                NS::UInteger  patchCount,
                                const Buffer* patchIndexBuffer,
                                NS::UInteger  patchIndexBufferOffset,
                                const Buffer* controlPointIndexBuffer,
                                NS::UInteger  controlPointIndexBufferOffset,
                                NS::UInteger  instanceCount,
                                NS::UInteger  baseInstance,
                                const Buffer* buffer,
                                NS::UInteger  offset,
                                NS::UInteger  instanceStride) const;

        void drawIndexedPrimitives(PrimitiveType primitiveType,
                                   NS::UInteger  indexCount,
                                   IndexType     indexType,
                                   const Buffer* indexBuffer,
                                   NS::UInteger  indexBufferOffset,
                                   NS::UInteger  instanceCount,
                                   NS::Integer   baseVertex,
                                   NS::UInteger  baseInstance) const;

        void drawMeshThreadgroups(const Size& threadgroupsPerGrid,
                                  const Size& threadsPerObjectThreadgroup,
                                  const Size& threadsPerMeshThreadgroup) const;

        void drawMeshThreads(const Size& threadsPerGrid,
                             const Size& threadsPerObjectThreadgroup,
                             const Size& threadsPerMeshThreadgroup) const;

        void drawPatches(NS::UInteger  numberOfPatchControlPoints,
                         NS::UInteger  patchStart,
                         NS::UInteger  patchCount,
                         const Buffer* patchIndexBuffer,
                         NS::UInteger  patchIndexBufferOffset,
                         NS::UInteger  instanceCount,
                         NS::UInteger  baseInstance,
                         const Buffer* buffer,
                         NS::UInteger  offset,
                         NS::UInteger  instanceStride) const;

        void drawPrimitives(PrimitiveType primitiveType,
                            NS::UInteger  vertexStart,
                            NS::UInteger  vertexCount,
                            NS::UInteger  instanceCount,
                            NS::UInteger  baseInstance) const;

        void reset() const;

        void setBarrier() const;

        void setCullMode(CullMode cullMode) const;

        void setDepthBias(float depthBias, float slopeScale, float clamp) const;

        void setDepthClipMode(DepthClipMode depthClipMode) const;

        void setDepthStencilState(const DepthStencilState* depthStencilState) const;

        void setFragmentBuffer(const Buffer* buffer, NS::UInteger offset, NS::UInteger index) const;

        void setFrontFacingWinding(Winding frontFacingWinding) const;

        void setMeshBuffer(const Buffer* buffer, NS::UInteger offset, NS::UInteger index) const;

        void setObjectBuffer(const Buffer* buffer, NS::UInteger offset, NS::UInteger index) const;

        void setObjectThreadgroupMemoryLength(NS::UInteger length, NS::UInteger index) const;

        void setRenderPipelineState(const RenderPipelineState* pipelineState) const;

        void setTriangleFillMode(TriangleFillMode fillMode) const;

        void setVertexBuffer(const Buffer* buffer, NS::UInteger offset, NS::UInteger index) const;
        void setVertexBuffer(const Buffer* buffer, NS::UInteger offset, NS::UInteger stride, NS::UInteger index) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlindirectcomputecommand?language=objc
    class IndirectComputeCommand : public NS::Referencing<IndirectComputeCommand>
    {
    public:
        void clearBarrier() const;

        void concurrentDispatchThreadgroups(const Size& threadgroupsPerGrid, const Size& threadsPerThreadgroup) const;

        void concurrentDispatchThreads(const Size& threadsPerGrid, const Size& threadsPerThreadgroup) const;

        void reset() const;

        void setBarrier() const;

        void setComputePipelineState(const ComputePipelineState* pipelineState) const;

        void setImageblockWidth(NS::UInteger width, NS::UInteger height) const;

        void setKernelBuffer(const Buffer* buffer, NS::UInteger offset, NS::UInteger index) const;
        void setKernelBuffer(const Buffer* buffer, NS::UInteger offset, NS::UInteger stride, NS::UInteger index) const;

        void setStageInRegion(const Region& region) const;

        void setThreadgroupMemoryLength(NS::UInteger length, NS::UInteger index) const;
    };

} // namespace MTL
_MTL_INLINE void MTL::IndirectRenderCommand::clearBarrier() const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(clearBarrier));
}

_MTL_INLINE void MTL::IndirectRenderCommand::drawIndexedPatches(const NS::UInteger numberOfPatchControlPoints,
                                                                const NS::UInteger patchStart,
                                                                const NS::UInteger patchCount,
                                                                const Buffer*      patchIndexBuffer,
                                                                const NS::UInteger patchIndexBufferOffset,
                                                                const Buffer*      controlPointIndexBuffer,
                                                                const NS::UInteger controlPointIndexBufferOffset,
                                                                const NS::UInteger instanceCount,
                                                                const NS::UInteger baseInstance,
                                                                const Buffer*      buffer,
                                                                const NS::UInteger offset,
                                                                const NS::UInteger instanceStride) const
{
    sendMessage<void>(
        this,
        _MTL_PRIVATE_SEL(
            drawIndexedPatches_patchStart_patchCount_patchIndexBuffer_patchIndexBufferOffset_controlPointIndexBuffer_controlPointIndexBufferOffset_instanceCount_baseInstance_tessellationFactorBuffer_tessellationFactorBufferOffset_tessellationFactorBufferInstanceStride_),
        numberOfPatchControlPoints,
        patchStart,
        patchCount,
        patchIndexBuffer,
        patchIndexBufferOffset,
        controlPointIndexBuffer,
        controlPointIndexBufferOffset,
        instanceCount,
        baseInstance,
        buffer,
        offset,
        instanceStride);
}

_MTL_INLINE void MTL::IndirectRenderCommand::drawIndexedPrimitives(const PrimitiveType primitiveType,
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

_MTL_INLINE void MTL::IndirectRenderCommand::drawMeshThreadgroups(const Size& threadgroupsPerGrid,
                                                                  const Size& threadsPerObjectThreadgroup,
                                                                  const Size& threadsPerMeshThreadgroup) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(drawMeshThreadgroups_threadsPerObjectThreadgroup_threadsPerMeshThreadgroup_),
                      threadgroupsPerGrid,
                      threadsPerObjectThreadgroup,
                      threadsPerMeshThreadgroup);
}

_MTL_INLINE void MTL::IndirectRenderCommand::drawMeshThreads(const Size& threadsPerGrid,
                                                             const Size& threadsPerObjectThreadgroup,
                                                             const Size& threadsPerMeshThreadgroup) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(drawMeshThreads_threadsPerObjectThreadgroup_threadsPerMeshThreadgroup_),
                      threadsPerGrid,
                      threadsPerObjectThreadgroup,
                      threadsPerMeshThreadgroup);
}

_MTL_INLINE void MTL::IndirectRenderCommand::drawPatches(const NS::UInteger numberOfPatchControlPoints,
                                                         const NS::UInteger patchStart,
                                                         const NS::UInteger patchCount,
                                                         const Buffer*      patchIndexBuffer,
                                                         const NS::UInteger patchIndexBufferOffset,
                                                         const NS::UInteger instanceCount,
                                                         const NS::UInteger baseInstance,
                                                         const Buffer*      buffer,
                                                         const NS::UInteger offset,
                                                         const NS::UInteger instanceStride) const
{
    sendMessage<void>(
        this,
        _MTL_PRIVATE_SEL(
            drawPatches_patchStart_patchCount_patchIndexBuffer_patchIndexBufferOffset_instanceCount_baseInstance_tessellationFactorBuffer_tessellationFactorBufferOffset_tessellationFactorBufferInstanceStride_),
        numberOfPatchControlPoints,
        patchStart,
        patchCount,
        patchIndexBuffer,
        patchIndexBufferOffset,
        instanceCount,
        baseInstance,
        buffer,
        offset,
        instanceStride);
}

_MTL_INLINE void MTL::IndirectRenderCommand::drawPrimitives(const PrimitiveType primitiveType,
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

_MTL_INLINE void MTL::IndirectRenderCommand::reset() const { sendMessage<void>(this, _MTL_PRIVATE_SEL(reset)); }

_MTL_INLINE void MTL::IndirectRenderCommand::setBarrier() const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBarrier));
}

_MTL_INLINE void MTL::IndirectRenderCommand::setCullMode(const CullMode cullMode) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setCullMode_), cullMode);
}

_MTL_INLINE void MTL::IndirectRenderCommand::setDepthBias(const float depthBias,
                                                          const float slopeScale,
                                                          const float clamp) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDepthBias_slopeScale_clamp_), depthBias, slopeScale, clamp);
}

_MTL_INLINE void MTL::IndirectRenderCommand::setDepthClipMode(const DepthClipMode depthClipMode) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDepthClipMode_), depthClipMode);
}

_MTL_INLINE void MTL::IndirectRenderCommand::setDepthStencilState(const DepthStencilState* depthStencilState) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDepthStencilState_), depthStencilState);
}

_MTL_INLINE void MTL::IndirectRenderCommand::setFragmentBuffer(const Buffer*      buffer,
                                                               const NS::UInteger offset,
                                                               const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFragmentBuffer_offset_atIndex_), buffer, offset, index);
}

_MTL_INLINE void MTL::IndirectRenderCommand::setFrontFacingWinding(const Winding frontFacingWinding) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFrontFacingWinding_), frontFacingWinding);
}

_MTL_INLINE void MTL::IndirectRenderCommand::setMeshBuffer(const Buffer*      buffer,
                                                           const NS::UInteger offset,
                                                           const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMeshBuffer_offset_atIndex_), buffer, offset, index);
}

_MTL_INLINE void MTL::IndirectRenderCommand::setObjectBuffer(const Buffer*      buffer,
                                                             const NS::UInteger offset,
                                                             const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setObjectBuffer_offset_atIndex_), buffer, offset, index);
}

_MTL_INLINE void MTL::IndirectRenderCommand::setObjectThreadgroupMemoryLength(const NS::UInteger length,
                                                                              const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setObjectThreadgroupMemoryLength_atIndex_), length, index);
}

_MTL_INLINE void MTL::IndirectRenderCommand::setRenderPipelineState(const RenderPipelineState* pipelineState) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRenderPipelineState_), pipelineState);
}

_MTL_INLINE void MTL::IndirectRenderCommand::setTriangleFillMode(const TriangleFillMode fillMode) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTriangleFillMode_), fillMode);
}

_MTL_INLINE void MTL::IndirectRenderCommand::setVertexBuffer(const Buffer*      buffer,
                                                             const NS::UInteger offset,
                                                             const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVertexBuffer_offset_atIndex_), buffer, offset, index);
}

_MTL_INLINE void MTL::IndirectRenderCommand::setVertexBuffer(const Buffer*      buffer,
                                                             const NS::UInteger offset,
                                                             const NS::UInteger stride,
                                                             const NS::UInteger index) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setVertexBuffer_offset_attributeStride_atIndex_), buffer, offset, stride, index);
}

_MTL_INLINE void MTL::IndirectComputeCommand::clearBarrier() const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(clearBarrier));
}

_MTL_INLINE void MTL::IndirectComputeCommand::concurrentDispatchThreadgroups(const Size& threadgroupsPerGrid,
                                                                             const Size& threadsPerThreadgroup) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(concurrentDispatchThreadgroups_threadsPerThreadgroup_),
                      threadgroupsPerGrid,
                      threadsPerThreadgroup);
}

_MTL_INLINE void MTL::IndirectComputeCommand::concurrentDispatchThreads(const Size& threadsPerGrid,
                                                                        const Size& threadsPerThreadgroup) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(concurrentDispatchThreads_threadsPerThreadgroup_),
                      threadsPerGrid,
                      threadsPerThreadgroup);
}

_MTL_INLINE void MTL::IndirectComputeCommand::reset() const { sendMessage<void>(this, _MTL_PRIVATE_SEL(reset)); }

_MTL_INLINE void MTL::IndirectComputeCommand::setBarrier() const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBarrier));
}

_MTL_INLINE void MTL::IndirectComputeCommand::setComputePipelineState(const ComputePipelineState* pipelineState) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setComputePipelineState_), pipelineState);
}

_MTL_INLINE void MTL::IndirectComputeCommand::setImageblockWidth(const NS::UInteger width,
                                                                 const NS::UInteger height) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setImageblockWidth_height_), width, height);
}

_MTL_INLINE void MTL::IndirectComputeCommand::setKernelBuffer(const Buffer*      buffer,
                                                              const NS::UInteger offset,
                                                              const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setKernelBuffer_offset_atIndex_), buffer, offset, index);
}

_MTL_INLINE void MTL::IndirectComputeCommand::setKernelBuffer(const Buffer*      buffer,
                                                              const NS::UInteger offset,
                                                              const NS::UInteger stride,
                                                              const NS::UInteger index) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setKernelBuffer_offset_attributeStride_atIndex_), buffer, offset, stride, index);
}

_MTL_INLINE void MTL::IndirectComputeCommand::setStageInRegion(const Region& region) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setStageInRegion_), region);
}

_MTL_INLINE void MTL::IndirectComputeCommand::setThreadgroupMemoryLength(const NS::UInteger length,
                                                                         const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setThreadgroupMemoryLength_atIndex_), length, index);
}
