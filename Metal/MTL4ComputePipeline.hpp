//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTL4ComputePipeline.hpp
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
#include "MTLPrivate.hpp"
#include "MTLTypes.hpp"

namespace MTL4
{
    class ComputePipelineDescriptor;
    class FunctionDescriptor;
    class StaticLinkingDescriptor;

    /// @see https://developer.apple.com/documentation/metal/mtl4computepipelinedescriptor
    class ComputePipelineDescriptor : public NS::Copying<ComputePipelineDescriptor, PipelineDescriptor>
    {
    public:
        [[nodiscard]] static ComputePipelineDescriptor* alloc();

        [[nodiscard]] FunctionDescriptor* computeFunctionDescriptor() const;

        [[nodiscard]] ComputePipelineDescriptor* init();

        [[nodiscard]] NS::UInteger maxTotalThreadsPerThreadgroup() const;

        [[nodiscard]] MTL::Size requiredThreadsPerThreadgroup() const;

        [[nodiscard]] StaticLinkingDescriptor* staticLinkingDescriptor() const;

        [[nodiscard]] bool supportBinaryLinking() const;

        [[nodiscard]] IndirectCommandBufferSupportState supportIndirectCommandBuffers() const;

        [[nodiscard]] bool threadGroupSizeIsMultipleOfThreadExecutionWidth() const;

        void reset() const;

        void setComputeFunctionDescriptor(const FunctionDescriptor* computeFunctionDescriptor) const;

        void setMaxTotalThreadsPerThreadgroup(NS::UInteger maxTotalThreadsPerThreadgroup) const;

        void setRequiredThreadsPerThreadgroup(const MTL::Size& requiredThreadsPerThreadgroup) const;

        void setStaticLinkingDescriptor(const StaticLinkingDescriptor* staticLinkingDescriptor) const;

        void setSupportBinaryLinking(bool supportBinaryLinking) const;

        void setSupportIndirectCommandBuffers(IndirectCommandBufferSupportState supportIndirectCommandBuffers) const;

        void setThreadGroupSizeIsMultipleOfThreadExecutionWidth(
            bool threadGroupSizeIsMultipleOfThreadExecutionWidth) const;
    };

} // namespace MTL4
_MTL_INLINE MTL4::ComputePipelineDescriptor* MTL4::ComputePipelineDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<ComputePipelineDescriptor>(_MTL_PRIVATE_CLS(MTL4ComputePipelineDescriptor));
}

_MTL_INLINE MTL4::FunctionDescriptor* MTL4::ComputePipelineDescriptor::computeFunctionDescriptor() const
{
    return sendMessage<FunctionDescriptor*>(this, _MTL_PRIVATE_SEL(computeFunctionDescriptor));
}

_MTL_INLINE MTL4::ComputePipelineDescriptor* MTL4::ComputePipelineDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<ComputePipelineDescriptor>();
}

_MTL_INLINE NS::UInteger MTL4::ComputePipelineDescriptor::maxTotalThreadsPerThreadgroup() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxTotalThreadsPerThreadgroup));
}

_MTL_INLINE MTL::Size MTL4::ComputePipelineDescriptor::requiredThreadsPerThreadgroup() const
{
    return sendMessage<MTL::Size>(this, _MTL_PRIVATE_SEL(requiredThreadsPerThreadgroup));
}

_MTL_INLINE void MTL4::ComputePipelineDescriptor::reset() const { sendMessage<void>(this, _MTL_PRIVATE_SEL(reset)); }

_MTL_INLINE void MTL4::ComputePipelineDescriptor::setComputeFunctionDescriptor(
    const FunctionDescriptor* computeFunctionDescriptor) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setComputeFunctionDescriptor_), computeFunctionDescriptor);
}

_MTL_INLINE void MTL4::ComputePipelineDescriptor::setMaxTotalThreadsPerThreadgroup(
    const NS::UInteger maxTotalThreadsPerThreadgroup) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxTotalThreadsPerThreadgroup_), maxTotalThreadsPerThreadgroup);
}

_MTL_INLINE void MTL4::ComputePipelineDescriptor::setRequiredThreadsPerThreadgroup(
    const MTL::Size& requiredThreadsPerThreadgroup) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRequiredThreadsPerThreadgroup_), requiredThreadsPerThreadgroup);
}

_MTL_INLINE void MTL4::ComputePipelineDescriptor::setStaticLinkingDescriptor(
    const StaticLinkingDescriptor* staticLinkingDescriptor) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setStaticLinkingDescriptor_), staticLinkingDescriptor);
}

_MTL_INLINE void MTL4::ComputePipelineDescriptor::setSupportBinaryLinking(const bool supportBinaryLinking) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSupportBinaryLinking_), supportBinaryLinking);
}

_MTL_INLINE void MTL4::ComputePipelineDescriptor::setSupportIndirectCommandBuffers(
    const IndirectCommandBufferSupportState supportIndirectCommandBuffers) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSupportIndirectCommandBuffers_), supportIndirectCommandBuffers);
}

_MTL_INLINE void MTL4::ComputePipelineDescriptor::setThreadGroupSizeIsMultipleOfThreadExecutionWidth(
    const bool threadGroupSizeIsMultipleOfThreadExecutionWidth) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(setThreadGroupSizeIsMultipleOfThreadExecutionWidth_),
                      threadGroupSizeIsMultipleOfThreadExecutionWidth);
}

_MTL_INLINE MTL4::StaticLinkingDescriptor* MTL4::ComputePipelineDescriptor::staticLinkingDescriptor() const
{
    return sendMessage<StaticLinkingDescriptor*>(this, _MTL_PRIVATE_SEL(staticLinkingDescriptor));
}

_MTL_INLINE bool MTL4::ComputePipelineDescriptor::supportBinaryLinking() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supportBinaryLinking));
}

_MTL_INLINE MTL4::IndirectCommandBufferSupportState MTL4::ComputePipelineDescriptor::supportIndirectCommandBuffers()
    const
{
    return sendMessage<IndirectCommandBufferSupportState>(this, _MTL_PRIVATE_SEL(supportIndirectCommandBuffers));
}

_MTL_INLINE bool MTL4::ComputePipelineDescriptor::threadGroupSizeIsMultipleOfThreadExecutionWidth() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(threadGroupSizeIsMultipleOfThreadExecutionWidth));
}
