//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLArgumentEncoder.hpp
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
#include "MTLDepthStencil.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"

namespace MTL
{
    class AccelerationStructure;
    class ArgumentEncoder;
    class Buffer;
    class ComputePipelineState;
    class Device;
    class IndirectCommandBuffer;
    class IntersectionFunctionTable;
    class RenderPipelineState;
    class SamplerState;
    class Texture;
    class VisibleFunctionTable;

    static constexpr NS::UInteger AttributeStrideStatic = NS::UIntegerMax;

    /// @see https://developer.apple.com/documentation/metal/mtlargumentencoder?language=objc
    class ArgumentEncoder : public NS::Referencing<ArgumentEncoder>
    {
    public:
        [[nodiscard]] NS::UInteger alignment() const;

        [[nodiscard]] void* constantData(NS::UInteger index) const;

        [[nodiscard]] Device* device() const;

        [[nodiscard]] NS::UInteger encodedLength() const;

        [[nodiscard]] NS::String* label() const;

        [[nodiscard]] ArgumentEncoder* newArgumentEncoder(NS::UInteger index) const;

        void setAccelerationStructure(const AccelerationStructure* accelerationStructure, NS::UInteger index) const;

        void setArgumentBuffer(const Buffer* argumentBuffer, NS::UInteger offset) const;
        void setArgumentBuffer(const Buffer* argumentBuffer, NS::UInteger startOffset, NS::UInteger arrayElement) const;

        void setBuffer(const Buffer* buffer, NS::UInteger offset, NS::UInteger index) const;
        void setBuffers(const Buffer* const buffers[], const NS::UInteger offsets[], NS::Range range) const;

        void setComputePipelineState(const ComputePipelineState* pipeline, NS::UInteger index) const;
        void setComputePipelineStates(const ComputePipelineState* const pipelines[], NS::Range range) const;

        void setDepthStencilState(const DepthStencilState* depthStencilState, NS::UInteger index) const;
        void setDepthStencilStates(const DepthStencilState* const depthStencilStates[], NS::Range range) const;

        void setIndirectCommandBuffer(const IndirectCommandBuffer* indirectCommandBuffer, NS::UInteger index) const;
        void setIndirectCommandBuffers(const IndirectCommandBuffer* const buffers[], NS::Range range) const;

        void setIntersectionFunctionTable(const IntersectionFunctionTable* intersectionFunctionTable,
                                          NS::UInteger                     index) const;
        void setIntersectionFunctionTables(const IntersectionFunctionTable* const intersectionFunctionTables[],
                                           NS::Range                              range) const;

        void setLabel(const NS::String* label) const;

        void setRenderPipelineState(const RenderPipelineState* pipeline, NS::UInteger index) const;
        void setRenderPipelineStates(const RenderPipelineState* const pipelines[], NS::Range range) const;

        void setSamplerState(const SamplerState* sampler, NS::UInteger index) const;
        void setSamplerStates(const SamplerState* const samplers[], NS::Range range) const;

        void setTexture(const Texture* texture, NS::UInteger index) const;
        void setTextures(const Texture* const textures[], NS::Range range) const;

        void setVisibleFunctionTable(const VisibleFunctionTable* visibleFunctionTable, NS::UInteger index) const;
        void setVisibleFunctionTables(const VisibleFunctionTable* const visibleFunctionTables[], NS::Range range) const;
    };

} // namespace MTL

_MTL_INLINE NS::UInteger MTL::ArgumentEncoder::alignment() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(alignment));
}

_MTL_INLINE void* MTL::ArgumentEncoder::constantData(const NS::UInteger index) const
{
    return sendMessage<void*>(this, _MTL_PRIVATE_SEL(constantDataAtIndex_), index);
}

_MTL_INLINE MTL::Device* MTL::ArgumentEncoder::device() const
{
    return sendMessage<Device*>(this, _MTL_PRIVATE_SEL(device));
}

_MTL_INLINE NS::UInteger MTL::ArgumentEncoder::encodedLength() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(encodedLength));
}

_MTL_INLINE NS::String* MTL::ArgumentEncoder::label() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
}

_MTL_INLINE MTL::ArgumentEncoder* MTL::ArgumentEncoder::newArgumentEncoder(const NS::UInteger index) const
{
    return sendMessage<ArgumentEncoder*>(this, _MTL_PRIVATE_SEL(newArgumentEncoderForBufferAtIndex_), index);
}

_MTL_INLINE void MTL::ArgumentEncoder::setAccelerationStructure(const AccelerationStructure* accelerationStructure,
                                                                const NS::UInteger           index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setAccelerationStructure_atIndex_), accelerationStructure, index);
}

_MTL_INLINE void MTL::ArgumentEncoder::setArgumentBuffer(const Buffer* argumentBuffer, const NS::UInteger offset) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setArgumentBuffer_offset_), argumentBuffer, offset);
}

_MTL_INLINE void MTL::ArgumentEncoder::setArgumentBuffer(const Buffer*      argumentBuffer,
                                                         const NS::UInteger startOffset,
                                                         const NS::UInteger arrayElement) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setArgumentBuffer_startOffset_arrayElement_), argumentBuffer, startOffset, arrayElement);
}

_MTL_INLINE void MTL::ArgumentEncoder::setBuffer(const Buffer*      buffer,
                                                 const NS::UInteger offset,
                                                 const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBuffer_offset_atIndex_), buffer, offset, index);
}

_MTL_INLINE void MTL::ArgumentEncoder::setBuffers(const Buffer* const buffers[],
                                                  const NS::UInteger  offsets[],
                                                  const NS::Range     range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBuffers_offsets_withRange_), buffers, offsets, range);
}

_MTL_INLINE void MTL::ArgumentEncoder::setComputePipelineState(const ComputePipelineState* pipeline,
                                                               const NS::UInteger          index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setComputePipelineState_atIndex_), pipeline, index);
}

_MTL_INLINE void MTL::ArgumentEncoder::setComputePipelineStates(const ComputePipelineState* const pipelines[],
                                                                const NS::Range                   range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setComputePipelineStates_withRange_), pipelines, range);
}

_MTL_INLINE void MTL::ArgumentEncoder::setDepthStencilState(const DepthStencilState* depthStencilState,
                                                            const NS::UInteger       index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDepthStencilState_atIndex_), depthStencilState, index);
}

_MTL_INLINE void MTL::ArgumentEncoder::setDepthStencilStates(const DepthStencilState* const depthStencilStates[],
                                                             const NS::Range                range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDepthStencilStates_withRange_), depthStencilStates, range);
}

_MTL_INLINE void MTL::ArgumentEncoder::setIndirectCommandBuffer(const IndirectCommandBuffer* indirectCommandBuffer,
                                                                const NS::UInteger           index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setIndirectCommandBuffer_atIndex_), indirectCommandBuffer, index);
}

_MTL_INLINE void MTL::ArgumentEncoder::setIndirectCommandBuffers(const IndirectCommandBuffer* const buffers[],
                                                                 const NS::Range                    range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setIndirectCommandBuffers_withRange_), buffers, range);
}

_MTL_INLINE void MTL::ArgumentEncoder::setIntersectionFunctionTable(
    const IntersectionFunctionTable* intersectionFunctionTable, const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setIntersectionFunctionTable_atIndex_), intersectionFunctionTable, index);
}

_MTL_INLINE void MTL::ArgumentEncoder::setIntersectionFunctionTables(
    const IntersectionFunctionTable* const intersectionFunctionTables[], const NS::Range range) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setIntersectionFunctionTables_withRange_), intersectionFunctionTables, range);
}

_MTL_INLINE void MTL::ArgumentEncoder::setLabel(const NS::String* label) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLabel_), label);
}

_MTL_INLINE void MTL::ArgumentEncoder::setRenderPipelineState(const RenderPipelineState* pipeline,
                                                              const NS::UInteger         index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRenderPipelineState_atIndex_), pipeline, index);
}

_MTL_INLINE void MTL::ArgumentEncoder::setRenderPipelineStates(const RenderPipelineState* const pipelines[],
                                                               const NS::Range                  range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRenderPipelineStates_withRange_), pipelines, range);
}

_MTL_INLINE void MTL::ArgumentEncoder::setSamplerState(const SamplerState* sampler, const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSamplerState_atIndex_), sampler, index);
}

_MTL_INLINE void MTL::ArgumentEncoder::setSamplerStates(const SamplerState* const samplers[],
                                                        const NS::Range           range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSamplerStates_withRange_), samplers, range);
}

_MTL_INLINE void MTL::ArgumentEncoder::setTexture(const Texture* texture, const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTexture_atIndex_), texture, index);
}

_MTL_INLINE void MTL::ArgumentEncoder::setTextures(const Texture* const textures[], const NS::Range range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTextures_withRange_), textures, range);
}

_MTL_INLINE void MTL::ArgumentEncoder::setVisibleFunctionTable(const VisibleFunctionTable* visibleFunctionTable,
                                                               const NS::UInteger          index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVisibleFunctionTable_atIndex_), visibleFunctionTable, index);
}

_MTL_INLINE void MTL::ArgumentEncoder::setVisibleFunctionTables(
    const VisibleFunctionTable* const visibleFunctionTables[], const NS::Range range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVisibleFunctionTables_withRange_), visibleFunctionTables, range);
}
