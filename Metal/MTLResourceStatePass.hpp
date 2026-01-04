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

#include "../Foundation/Foundation.hpp"
#include "MTLDefines.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"

namespace MTL
{
    class CounterSampleBuffer;
    class ResourceStatePassDescriptor;
    class ResourceStatePassSampleBufferAttachmentDescriptor;
    class ResourceStatePassSampleBufferAttachmentDescriptorArray;

    /// @see
    /// https://developer.apple.com/documentation/metal/mtlresourcestatepasssamplebufferattachmentdescriptor?language=objc
    class ResourceStatePassSampleBufferAttachmentDescriptor
        : public NS::Copying<ResourceStatePassSampleBufferAttachmentDescriptor>
    {
    public:
        [[nodiscard]] static ResourceStatePassSampleBufferAttachmentDescriptor* alloc();

        [[nodiscard]] NS::UInteger endOfEncoderSampleIndex() const;

        [[nodiscard]] ResourceStatePassSampleBufferAttachmentDescriptor* init();

        [[nodiscard]] CounterSampleBuffer* sampleBuffer() const;

        void setEndOfEncoderSampleIndex(NS::UInteger endOfEncoderSampleIndex) const;

        void setSampleBuffer(const CounterSampleBuffer* sampleBuffer) const;

        void                       setStartOfEncoderSampleIndex(NS::UInteger startOfEncoderSampleIndex) const;
        [[nodiscard]] NS::UInteger startOfEncoderSampleIndex() const;
    };

    /// @see
    /// https://developer.apple.com/documentation/metal/mtlresourcestatepasssamplebufferattachmentdescriptorarray?language=objc
    class ResourceStatePassSampleBufferAttachmentDescriptorArray
        : public NS::Referencing<ResourceStatePassSampleBufferAttachmentDescriptorArray>
    {
    public:
        [[nodiscard]] static ResourceStatePassSampleBufferAttachmentDescriptorArray* alloc();

        [[nodiscard]] ResourceStatePassSampleBufferAttachmentDescriptorArray* init();

        [[nodiscard]] ResourceStatePassSampleBufferAttachmentDescriptor* object(NS::UInteger attachmentIndex) const;
        void setObject(const ResourceStatePassSampleBufferAttachmentDescriptor* attachment,
                       NS::UInteger                                             attachmentIndex) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlresourcestatepassdescriptor?language=objc
    class ResourceStatePassDescriptor : public NS::Copying<ResourceStatePassDescriptor>
    {
    public:
        [[nodiscard]] static ResourceStatePassDescriptor* alloc();

        [[nodiscard]] ResourceStatePassDescriptor* init();

        [[nodiscard]] static ResourceStatePassDescriptor* resourceStatePassDescriptor();

        [[nodiscard]] ResourceStatePassSampleBufferAttachmentDescriptorArray* sampleBufferAttachments() const;
    };

} // namespace MTL
_MTL_INLINE MTL::ResourceStatePassSampleBufferAttachmentDescriptor*
            MTL::ResourceStatePassSampleBufferAttachmentDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<ResourceStatePassSampleBufferAttachmentDescriptor>(
        _MTL_PRIVATE_CLS(MTLResourceStatePassSampleBufferAttachmentDescriptor));
}

_MTL_INLINE NS::UInteger MTL::ResourceStatePassSampleBufferAttachmentDescriptor::endOfEncoderSampleIndex() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(endOfEncoderSampleIndex));
}

_MTL_INLINE MTL::ResourceStatePassSampleBufferAttachmentDescriptor*
            MTL::ResourceStatePassSampleBufferAttachmentDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<ResourceStatePassSampleBufferAttachmentDescriptor>();
}

_MTL_INLINE MTL::CounterSampleBuffer* MTL::ResourceStatePassSampleBufferAttachmentDescriptor::sampleBuffer() const
{
    return sendMessage<CounterSampleBuffer*>(this, _MTL_PRIVATE_SEL(sampleBuffer));
}

_MTL_INLINE void MTL::ResourceStatePassSampleBufferAttachmentDescriptor::setEndOfEncoderSampleIndex(
    const NS::UInteger endOfEncoderSampleIndex) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setEndOfEncoderSampleIndex_), endOfEncoderSampleIndex);
}

_MTL_INLINE void MTL::ResourceStatePassSampleBufferAttachmentDescriptor::setSampleBuffer(
    const CounterSampleBuffer* sampleBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSampleBuffer_), sampleBuffer);
}

_MTL_INLINE void MTL::ResourceStatePassSampleBufferAttachmentDescriptor::setStartOfEncoderSampleIndex(
    const NS::UInteger startOfEncoderSampleIndex) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setStartOfEncoderSampleIndex_), startOfEncoderSampleIndex);
}

_MTL_INLINE NS::UInteger MTL::ResourceStatePassSampleBufferAttachmentDescriptor::startOfEncoderSampleIndex() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(startOfEncoderSampleIndex));
}

_MTL_INLINE MTL::ResourceStatePassSampleBufferAttachmentDescriptorArray*
            MTL::ResourceStatePassSampleBufferAttachmentDescriptorArray::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<ResourceStatePassSampleBufferAttachmentDescriptorArray>(
        _MTL_PRIVATE_CLS(MTLResourceStatePassSampleBufferAttachmentDescriptorArray));
}

_MTL_INLINE MTL::ResourceStatePassSampleBufferAttachmentDescriptorArray*
            MTL::ResourceStatePassSampleBufferAttachmentDescriptorArray::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<ResourceStatePassSampleBufferAttachmentDescriptorArray>();
}

_MTL_INLINE MTL::ResourceStatePassSampleBufferAttachmentDescriptor*
MTL::ResourceStatePassSampleBufferAttachmentDescriptorArray::object(const NS::UInteger attachmentIndex) const
{
    return sendMessage<ResourceStatePassSampleBufferAttachmentDescriptor*>(
        this, _MTL_PRIVATE_SEL(objectAtIndexedSubscript_), attachmentIndex);
}

_MTL_INLINE void MTL::ResourceStatePassSampleBufferAttachmentDescriptorArray::setObject(
    const ResourceStatePassSampleBufferAttachmentDescriptor* attachment, const NS::UInteger attachmentIndex) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setObject_atIndexedSubscript_), attachment, attachmentIndex);
}

_MTL_INLINE MTL::ResourceStatePassDescriptor* MTL::ResourceStatePassDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<ResourceStatePassDescriptor>(_MTL_PRIVATE_CLS(MTLResourceStatePassDescriptor));
}

_MTL_INLINE MTL::ResourceStatePassDescriptor* MTL::ResourceStatePassDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<ResourceStatePassDescriptor>();
}

_MTL_INLINE MTL::ResourceStatePassDescriptor* MTL::ResourceStatePassDescriptor::resourceStatePassDescriptor()
{
    return sendMessage<ResourceStatePassDescriptor*>(_MTL_PRIVATE_CLS(MTLResourceStatePassDescriptor),
                                                     _MTL_PRIVATE_SEL(resourceStatePassDescriptor));
}

_MTL_INLINE MTL::ResourceStatePassSampleBufferAttachmentDescriptorArray*
            MTL::ResourceStatePassDescriptor::sampleBufferAttachments() const
{
    return sendMessage<ResourceStatePassSampleBufferAttachmentDescriptorArray*>(
        this, _MTL_PRIVATE_SEL(sampleBufferAttachments));
}
