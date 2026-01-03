//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTL4Archive.hpp
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
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"

namespace MTL
{
    class ComputePipelineState;
    class RenderPipelineState;
} // namespace MTL

namespace MTL4
{
    class BinaryFunction;
    class BinaryFunctionDescriptor;
    class ComputePipelineDescriptor;
    class PipelineDescriptor;
    class PipelineStageDynamicLinkingDescriptor;
    class RenderPipelineDynamicLinkingDescriptor;

    class Archive : public NS::Referencing<Archive>
    {
    public:
        [[nodiscard]] NS::String* label() const;

        BinaryFunction* newBinaryFunction(const BinaryFunctionDescriptor* descriptor, NS::Error** error) const;

        MTL::ComputePipelineState* newComputePipelineState(const ComputePipelineDescriptor* descriptor,
                                                           NS::Error**                      error) const;
        MTL::ComputePipelineState* newComputePipelineState(
            const ComputePipelineDescriptor*             descriptor,
            const PipelineStageDynamicLinkingDescriptor* dynamicLinkingDescriptor,
            NS::Error**                                  error) const;

        MTL::RenderPipelineState* newRenderPipelineState(const PipelineDescriptor* descriptor, NS::Error** error) const;
        MTL::RenderPipelineState* newRenderPipelineState(
            const PipelineDescriptor*                     descriptor,
            const RenderPipelineDynamicLinkingDescriptor* dynamicLinkingDescriptor,
            NS::Error**                                   error) const;

        void setLabel(const NS::String* label) const;
    };

} // namespace MTL4
_MTL_INLINE NS::String* MTL4::Archive::label() const { return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label)); }

_MTL_INLINE MTL4::BinaryFunction* MTL4::Archive::newBinaryFunction(const BinaryFunctionDescriptor* descriptor,
                                                                   NS::Error**                     error) const
{
    return sendMessage<BinaryFunction*>(
        this, _MTL_PRIVATE_SEL(newBinaryFunctionWithDescriptor_error_), descriptor, error);
}

_MTL_INLINE MTL::ComputePipelineState* MTL4::Archive::newComputePipelineState(
    const ComputePipelineDescriptor* descriptor, NS::Error** error) const
{
    return sendMessage<MTL::ComputePipelineState*>(
        this, _MTL_PRIVATE_SEL(newComputePipelineStateWithDescriptor_error_), descriptor, error);
}

_MTL_INLINE MTL::ComputePipelineState* MTL4::Archive::newComputePipelineState(
    const ComputePipelineDescriptor*             descriptor,
    const PipelineStageDynamicLinkingDescriptor* dynamicLinkingDescriptor,
    NS::Error**                                  error) const
{
    return sendMessage<MTL::ComputePipelineState*>(
        this,
        _MTL_PRIVATE_SEL(newComputePipelineStateWithDescriptor_dynamicLinkingDescriptor_error_),
        descriptor,
        dynamicLinkingDescriptor,
        error);
}

_MTL_INLINE MTL::RenderPipelineState* MTL4::Archive::newRenderPipelineState(const PipelineDescriptor* descriptor,
                                                                            NS::Error**               error) const
{
    return sendMessage<MTL::RenderPipelineState*>(
        this, _MTL_PRIVATE_SEL(newRenderPipelineStateWithDescriptor_error_), descriptor, error);
}

_MTL_INLINE MTL::RenderPipelineState* MTL4::Archive::newRenderPipelineState(
    const PipelineDescriptor*                     descriptor,
    const RenderPipelineDynamicLinkingDescriptor* dynamicLinkingDescriptor,
    NS::Error**                                   error) const
{
    return sendMessage<MTL::RenderPipelineState*>(
        this,
        _MTL_PRIVATE_SEL(newRenderPipelineStateWithDescriptor_dynamicLinkingDescriptor_error_),
        descriptor,
        dynamicLinkingDescriptor,
        error);
}

_MTL_INLINE void MTL4::Archive::setLabel(const NS::String* label) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLabel_), label);
}
