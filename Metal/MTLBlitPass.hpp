//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLBlitPass.hpp
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
    class BlitPassDescriptor;
    class BlitPassSampleBufferAttachmentDescriptor;
    class BlitPassSampleBufferAttachmentDescriptorArray;
    class CounterSampleBuffer;

    /// @see https://developer.apple.com/documentation/metal/mtlblitpasssamplebufferattachmentdescriptor?language=objc
    class BlitPassSampleBufferAttachmentDescriptor : public NS::Copying<BlitPassSampleBufferAttachmentDescriptor>
    {
    public:
        [[nodiscard]] static BlitPassSampleBufferAttachmentDescriptor* alloc();

        [[nodiscard]] NS::UInteger endOfEncoderSampleIndex() const;

        [[nodiscard]] BlitPassSampleBufferAttachmentDescriptor* init();

        [[nodiscard]] CounterSampleBuffer* sampleBuffer() const;

        [[nodiscard]] NS::UInteger startOfEncoderSampleIndex() const;

        void setEndOfEncoderSampleIndex(NS::UInteger endOfEncoderSampleIndex) const;

        void setSampleBuffer(const CounterSampleBuffer* sampleBuffer) const;

        void setStartOfEncoderSampleIndex(NS::UInteger startOfEncoderSampleIndex) const;
    };

    /// @see
    /// https://developer.apple.com/documentation/metal/mtlblitpasssamplebufferattachmentdescriptorarray?language=objc
    class BlitPassSampleBufferAttachmentDescriptorArray
        : public NS::Referencing<BlitPassSampleBufferAttachmentDescriptorArray>
    {
    public:
        [[nodiscard]] static BlitPassSampleBufferAttachmentDescriptorArray* alloc();

        [[nodiscard]] BlitPassSampleBufferAttachmentDescriptorArray* init();

        [[nodiscard]] BlitPassSampleBufferAttachmentDescriptor* object(NS::UInteger attachmentIndex) const;

        void setObject(const BlitPassSampleBufferAttachmentDescriptor* attachment, NS::UInteger attachmentIndex) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlblitpassdescriptor?language=objc
    class BlitPassDescriptor : public NS::Copying<BlitPassDescriptor>
    {
    public:
        [[nodiscard]] static BlitPassDescriptor* alloc();

        [[nodiscard]] static BlitPassDescriptor* blitPassDescriptor();

        [[nodiscard]] BlitPassDescriptor* init();

        [[nodiscard]] BlitPassSampleBufferAttachmentDescriptorArray* sampleBufferAttachments() const;
    };

} // namespace MTL
_MTL_INLINE MTL::BlitPassSampleBufferAttachmentDescriptor* MTL::BlitPassSampleBufferAttachmentDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<BlitPassSampleBufferAttachmentDescriptor>(
        _MTL_PRIVATE_CLS(MTLBlitPassSampleBufferAttachmentDescriptor));
}

_MTL_INLINE NS::UInteger MTL::BlitPassSampleBufferAttachmentDescriptor::endOfEncoderSampleIndex() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(endOfEncoderSampleIndex));
}

_MTL_INLINE MTL::BlitPassSampleBufferAttachmentDescriptor* MTL::BlitPassSampleBufferAttachmentDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<BlitPassSampleBufferAttachmentDescriptor>();
}

_MTL_INLINE MTL::CounterSampleBuffer* MTL::BlitPassSampleBufferAttachmentDescriptor::sampleBuffer() const
{
    return sendMessage<CounterSampleBuffer*>(this, _MTL_PRIVATE_SEL(sampleBuffer));
}

_MTL_INLINE void MTL::BlitPassSampleBufferAttachmentDescriptor::setEndOfEncoderSampleIndex(
    const NS::UInteger endOfEncoderSampleIndex) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setEndOfEncoderSampleIndex_), endOfEncoderSampleIndex);
}

_MTL_INLINE void MTL::BlitPassSampleBufferAttachmentDescriptor::setSampleBuffer(
    const CounterSampleBuffer* sampleBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSampleBuffer_), sampleBuffer);
}

_MTL_INLINE void MTL::BlitPassSampleBufferAttachmentDescriptor::setStartOfEncoderSampleIndex(
    const NS::UInteger startOfEncoderSampleIndex) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setStartOfEncoderSampleIndex_), startOfEncoderSampleIndex);
}

_MTL_INLINE NS::UInteger MTL::BlitPassSampleBufferAttachmentDescriptor::startOfEncoderSampleIndex() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(startOfEncoderSampleIndex));
}

_MTL_INLINE MTL::BlitPassSampleBufferAttachmentDescriptorArray*
            MTL::BlitPassSampleBufferAttachmentDescriptorArray::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<BlitPassSampleBufferAttachmentDescriptorArray>(
        _MTL_PRIVATE_CLS(MTLBlitPassSampleBufferAttachmentDescriptorArray));
}

_MTL_INLINE MTL::BlitPassSampleBufferAttachmentDescriptorArray*
            MTL::BlitPassSampleBufferAttachmentDescriptorArray::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<BlitPassSampleBufferAttachmentDescriptorArray>();
}

_MTL_INLINE MTL::BlitPassSampleBufferAttachmentDescriptor* MTL::BlitPassSampleBufferAttachmentDescriptorArray::object(
    const NS::UInteger attachmentIndex) const
{
    return sendMessage<BlitPassSampleBufferAttachmentDescriptor*>(
        this, _MTL_PRIVATE_SEL(objectAtIndexedSubscript_), attachmentIndex);
}

_MTL_INLINE void MTL::BlitPassSampleBufferAttachmentDescriptorArray::setObject(
    const BlitPassSampleBufferAttachmentDescriptor* attachment, const NS::UInteger attachmentIndex) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setObject_atIndexedSubscript_), attachment, attachmentIndex);
}

_MTL_INLINE MTL::BlitPassDescriptor* MTL::BlitPassDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<BlitPassDescriptor>(_MTL_PRIVATE_CLS(MTLBlitPassDescriptor));
}

_MTL_INLINE MTL::BlitPassDescriptor* MTL::BlitPassDescriptor::blitPassDescriptor()
{
    return sendMessage<BlitPassDescriptor*>(_MTL_PRIVATE_CLS(MTLBlitPassDescriptor),
                                            _MTL_PRIVATE_SEL(blitPassDescriptor));
}

_MTL_INLINE MTL::BlitPassDescriptor* MTL::BlitPassDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<BlitPassDescriptor>();
}

_MTL_INLINE MTL::BlitPassSampleBufferAttachmentDescriptorArray* MTL::BlitPassDescriptor::sampleBufferAttachments() const
{
    return sendMessage<BlitPassSampleBufferAttachmentDescriptorArray*>(this, _MTL_PRIVATE_SEL(sampleBufferAttachments));
}
