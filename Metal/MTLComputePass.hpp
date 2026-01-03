//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLComputePass.hpp
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
#include "MTLCommandBuffer.hpp"
#include "MTLDefines.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"

namespace MTL
{
    class ComputePassDescriptor;
    class ComputePassSampleBufferAttachmentDescriptor;
    class ComputePassSampleBufferAttachmentDescriptorArray;
    class CounterSampleBuffer;

    /// @see
    /// https://developer.apple.com/documentation/metal/mtlcomputepasssamplebufferattachmentdescriptor?language=objc
    class ComputePassSampleBufferAttachmentDescriptor : public NS::Copying<ComputePassSampleBufferAttachmentDescriptor>
    {
    public:
        [[nodiscard]] static ComputePassSampleBufferAttachmentDescriptor* alloc();

        [[nodiscard]] NS::UInteger endOfEncoderSampleIndex() const;

        [[nodiscard]] ComputePassSampleBufferAttachmentDescriptor* init();

        [[nodiscard]] CounterSampleBuffer* sampleBuffer() const;

        void setEndOfEncoderSampleIndex(NS::UInteger endOfEncoderSampleIndex) const;

        void setSampleBuffer(const CounterSampleBuffer* sampleBuffer) const;

        void                       setStartOfEncoderSampleIndex(NS::UInteger startOfEncoderSampleIndex) const;
        [[nodiscard]] NS::UInteger startOfEncoderSampleIndex() const;
    };

    /// @see
    /// https://developer.apple.com/documentation/metal/mtlcomputepasssamplebufferattachmentdescriptorarray?language=objc
    class ComputePassSampleBufferAttachmentDescriptorArray
        : public NS::Referencing<ComputePassSampleBufferAttachmentDescriptorArray>
    {
    public:
        [[nodiscard]] static ComputePassSampleBufferAttachmentDescriptorArray* alloc();

        [[nodiscard]] ComputePassSampleBufferAttachmentDescriptorArray* init();

        [[nodiscard]] ComputePassSampleBufferAttachmentDescriptor* object(NS::UInteger attachmentIndex) const;
        void setObject(const ComputePassSampleBufferAttachmentDescriptor* attachment,
                       NS::UInteger                                       attachmentIndex) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlcomputepassdescriptor?language=objc
    class ComputePassDescriptor : public NS::Copying<ComputePassDescriptor>
    {
    public:
        [[nodiscard]] static ComputePassDescriptor* alloc();

        [[nodiscard]] static ComputePassDescriptor* computePassDescriptor();

        [[nodiscard]] DispatchType dispatchType() const;

        [[nodiscard]] ComputePassDescriptor* init();

        [[nodiscard]] ComputePassSampleBufferAttachmentDescriptorArray* sampleBufferAttachments() const;

        void setDispatchType(DispatchType dispatchType) const;
    };

} // namespace MTL
_MTL_INLINE MTL::ComputePassSampleBufferAttachmentDescriptor* MTL::ComputePassSampleBufferAttachmentDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<ComputePassSampleBufferAttachmentDescriptor>(
        _MTL_PRIVATE_CLS(MTLComputePassSampleBufferAttachmentDescriptor));
}

_MTL_INLINE NS::UInteger MTL::ComputePassSampleBufferAttachmentDescriptor::endOfEncoderSampleIndex() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(endOfEncoderSampleIndex));
}

_MTL_INLINE MTL::ComputePassSampleBufferAttachmentDescriptor* MTL::ComputePassSampleBufferAttachmentDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<ComputePassSampleBufferAttachmentDescriptor>();
}

_MTL_INLINE MTL::CounterSampleBuffer* MTL::ComputePassSampleBufferAttachmentDescriptor::sampleBuffer() const
{
    return sendMessage<CounterSampleBuffer*>(this, _MTL_PRIVATE_SEL(sampleBuffer));
}

_MTL_INLINE void MTL::ComputePassSampleBufferAttachmentDescriptor::setEndOfEncoderSampleIndex(
    const NS::UInteger endOfEncoderSampleIndex) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setEndOfEncoderSampleIndex_), endOfEncoderSampleIndex);
}

_MTL_INLINE void MTL::ComputePassSampleBufferAttachmentDescriptor::setSampleBuffer(
    const CounterSampleBuffer* sampleBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSampleBuffer_), sampleBuffer);
}

_MTL_INLINE void MTL::ComputePassSampleBufferAttachmentDescriptor::setStartOfEncoderSampleIndex(
    const NS::UInteger startOfEncoderSampleIndex) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setStartOfEncoderSampleIndex_), startOfEncoderSampleIndex);
}

_MTL_INLINE NS::UInteger MTL::ComputePassSampleBufferAttachmentDescriptor::startOfEncoderSampleIndex() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(startOfEncoderSampleIndex));
}

_MTL_INLINE MTL::ComputePassSampleBufferAttachmentDescriptorArray*
            MTL::ComputePassSampleBufferAttachmentDescriptorArray::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<ComputePassSampleBufferAttachmentDescriptorArray>(
        _MTL_PRIVATE_CLS(MTLComputePassSampleBufferAttachmentDescriptorArray));
}

_MTL_INLINE MTL::ComputePassSampleBufferAttachmentDescriptorArray*
            MTL::ComputePassSampleBufferAttachmentDescriptorArray::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<ComputePassSampleBufferAttachmentDescriptorArray>();
}

_MTL_INLINE MTL::ComputePassSampleBufferAttachmentDescriptor*
            MTL::ComputePassSampleBufferAttachmentDescriptorArray::object(const NS::UInteger attachmentIndex) const
{
    return sendMessage<ComputePassSampleBufferAttachmentDescriptor*>(
        this, _MTL_PRIVATE_SEL(objectAtIndexedSubscript_), attachmentIndex);
}

_MTL_INLINE void MTL::ComputePassSampleBufferAttachmentDescriptorArray::setObject(
    const ComputePassSampleBufferAttachmentDescriptor* attachment, const NS::UInteger attachmentIndex) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setObject_atIndexedSubscript_), attachment, attachmentIndex);
}

_MTL_INLINE MTL::ComputePassDescriptor* MTL::ComputePassDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<ComputePassDescriptor>(_MTL_PRIVATE_CLS(MTLComputePassDescriptor));
}

_MTL_INLINE MTL::ComputePassDescriptor* MTL::ComputePassDescriptor::computePassDescriptor()
{
    return sendMessage<ComputePassDescriptor*>(_MTL_PRIVATE_CLS(MTLComputePassDescriptor),
                                               _MTL_PRIVATE_SEL(computePassDescriptor));
}

_MTL_INLINE MTL::DispatchType MTL::ComputePassDescriptor::dispatchType() const
{
    return sendMessage<DispatchType>(this, _MTL_PRIVATE_SEL(dispatchType));
}

_MTL_INLINE MTL::ComputePassDescriptor* MTL::ComputePassDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<ComputePassDescriptor>();
}

_MTL_INLINE MTL::ComputePassSampleBufferAttachmentDescriptorArray* MTL::ComputePassDescriptor::sampleBufferAttachments()
    const
{
    return sendMessage<ComputePassSampleBufferAttachmentDescriptorArray*>(this,
                                                                          _MTL_PRIVATE_SEL(sampleBufferAttachments));
}

_MTL_INLINE void MTL::ComputePassDescriptor::setDispatchType(const DispatchType dispatchType) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDispatchType_), dispatchType);
}
