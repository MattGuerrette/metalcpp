//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLAccelerationStructureCommandEncoder.hpp
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
#include "MTLAccelerationStructure.hpp"
#include "MTLCommandEncoder.hpp"
#include "MTLDataType.hpp"
#include "MTLDefines.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"

namespace MTL
{
    class AccelerationStructure;
    class AccelerationStructureDescriptor;
    class AccelerationStructurePassDescriptor;
    class AccelerationStructurePassSampleBufferAttachmentDescriptor;
    class AccelerationStructurePassSampleBufferAttachmentDescriptorArray;
    class Buffer;
    class CounterSampleBuffer;
    class Fence;
    class Heap;
    class Resource;

    /// @see https://developer.apple.com/documentation/metal/mtlaccelerationstructurecommandencoder
    class AccelerationStructureCommandEncoder
        : public NS::Referencing<AccelerationStructureCommandEncoder, CommandEncoder>
    {
    public:
        void buildAccelerationStructure(const AccelerationStructure*           accelerationStructure,
                                        const AccelerationStructureDescriptor* descriptor,
                                        const Buffer*                          scratchBuffer,
                                        NS::UInteger                           scratchBufferOffset) const;

        void copyAccelerationStructure(const AccelerationStructure* sourceAccelerationStructure,
                                       const AccelerationStructure* destinationAccelerationStructure) const;

        void copyAndCompactAccelerationStructure(const AccelerationStructure* sourceAccelerationStructure,
                                                 const AccelerationStructure* destinationAccelerationStructure) const;

        void refitAccelerationStructure(const AccelerationStructure*           sourceAccelerationStructure,
                                        const AccelerationStructureDescriptor* descriptor,
                                        const AccelerationStructure*           destinationAccelerationStructure,
                                        const Buffer*                          scratchBuffer,
                                        NS::UInteger                           scratchBufferOffset) const;
        void refitAccelerationStructure(const AccelerationStructure*           sourceAccelerationStructure,
                                        const AccelerationStructureDescriptor* descriptor,
                                        const AccelerationStructure*           destinationAccelerationStructure,
                                        const Buffer*                          scratchBuffer,
                                        NS::UInteger                           scratchBufferOffset,
                                        AccelerationStructureRefitOptions      options) const;

        void sampleCountersInBuffer(const CounterSampleBuffer* sampleBuffer,
                                    NS::UInteger               sampleIndex,
                                    bool                       barrier) const;

        void updateFence(const Fence* fence) const;

        void useHeap(const Heap* heap) const;
        void useHeaps(const Heap* const heaps[], NS::UInteger count) const;

        void useResource(const Resource* resource, ResourceUsage usage) const;
        void useResources(const Resource* const resources[], NS::UInteger count, ResourceUsage usage) const;

        void waitForFence(const Fence* fence) const;

        void writeCompactedAccelerationStructureSize(const AccelerationStructure* accelerationStructure,
                                                     const Buffer*                buffer,
                                                     NS::UInteger                 offset) const;
        void writeCompactedAccelerationStructureSize(const AccelerationStructure* accelerationStructure,
                                                     const Buffer*                buffer,
                                                     NS::UInteger                 offset,
                                                     DataType                     sizeDataType) const;
    };

    /// @see
    /// https://developer.apple.com/documentation/metal/mtlaccelerationstructurepasssamplebufferattachmentdescriptor
    class AccelerationStructurePassSampleBufferAttachmentDescriptor
        : public NS::Copying<AccelerationStructurePassSampleBufferAttachmentDescriptor>
    {
    public:
        [[nodiscard]] static AccelerationStructurePassSampleBufferAttachmentDescriptor* alloc();

        [[nodiscard]] NS::UInteger endOfEncoderSampleIndex() const;

        [[nodiscard]] AccelerationStructurePassSampleBufferAttachmentDescriptor* init();

        [[nodiscard]] CounterSampleBuffer* sampleBuffer() const;

        [[nodiscard]] NS::UInteger startOfEncoderSampleIndex() const;

        void setEndOfEncoderSampleIndex(NS::UInteger endOfEncoderSampleIndex) const;

        void setSampleBuffer(const CounterSampleBuffer* sampleBuffer) const;

        void setStartOfEncoderSampleIndex(NS::UInteger startOfEncoderSampleIndex) const;
    };

    /// @see
    /// https://developer.apple.com/documentation/metal/mtlaccelerationstructurepasssamplebufferattachmentdescriptorarray
    class AccelerationStructurePassSampleBufferAttachmentDescriptorArray
        : public NS::Referencing<AccelerationStructurePassSampleBufferAttachmentDescriptorArray>
    {
    public:
        [[nodiscard]] static AccelerationStructurePassSampleBufferAttachmentDescriptorArray* alloc();

        [[nodiscard]] AccelerationStructurePassSampleBufferAttachmentDescriptorArray* init();

        [[nodiscard]] AccelerationStructurePassSampleBufferAttachmentDescriptor* object(
            NS::UInteger attachmentIndex) const;

        void setObject(const AccelerationStructurePassSampleBufferAttachmentDescriptor* attachment,
                       NS::UInteger                                                     attachmentIndex) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlaccelerationstructurepassdescriptor
    class AccelerationStructurePassDescriptor : public NS::Copying<AccelerationStructurePassDescriptor>
    {
    public:
        [[nodiscard]] static AccelerationStructurePassDescriptor* accelerationStructurePassDescriptor();

        [[nodiscard]] static AccelerationStructurePassDescriptor* alloc();

        [[nodiscard]] AccelerationStructurePassDescriptor* init();

        [[nodiscard]] AccelerationStructurePassSampleBufferAttachmentDescriptorArray* sampleBufferAttachments() const;
    };

} // namespace MTL
_MTL_INLINE void MTL::AccelerationStructureCommandEncoder::buildAccelerationStructure(
    const AccelerationStructure*           accelerationStructure,
    const AccelerationStructureDescriptor* descriptor,
    const Buffer*                          scratchBuffer,
    const NS::UInteger                     scratchBufferOffset) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(buildAccelerationStructure_descriptor_scratchBuffer_scratchBufferOffset_),
                      accelerationStructure,
                      descriptor,
                      scratchBuffer,
                      scratchBufferOffset);
}

_MTL_INLINE void MTL::AccelerationStructureCommandEncoder::copyAccelerationStructure(
    const AccelerationStructure* sourceAccelerationStructure,
    const AccelerationStructure* destinationAccelerationStructure) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(copyAccelerationStructure_toAccelerationStructure_),
                      sourceAccelerationStructure,
                      destinationAccelerationStructure);
}

_MTL_INLINE void MTL::AccelerationStructureCommandEncoder::copyAndCompactAccelerationStructure(
    const AccelerationStructure* sourceAccelerationStructure,
    const AccelerationStructure* destinationAccelerationStructure) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(copyAndCompactAccelerationStructure_toAccelerationStructure_),
                      sourceAccelerationStructure,
                      destinationAccelerationStructure);
}

_MTL_INLINE void MTL::AccelerationStructureCommandEncoder::refitAccelerationStructure(
    const AccelerationStructure*           sourceAccelerationStructure,
    const AccelerationStructureDescriptor* descriptor,
    const AccelerationStructure*           destinationAccelerationStructure,
    const Buffer*                          scratchBuffer,
    const NS::UInteger                     scratchBufferOffset) const
{
    sendMessage<void>(
        this,
        _MTL_PRIVATE_SEL(refitAccelerationStructure_descriptor_destination_scratchBuffer_scratchBufferOffset_),
        sourceAccelerationStructure,
        descriptor,
        destinationAccelerationStructure,
        scratchBuffer,
        scratchBufferOffset);
}

_MTL_INLINE void MTL::AccelerationStructureCommandEncoder::refitAccelerationStructure(
    const AccelerationStructure*            sourceAccelerationStructure,
    const AccelerationStructureDescriptor*  descriptor,
    const AccelerationStructure*            destinationAccelerationStructure,
    const Buffer*                           scratchBuffer,
    const NS::UInteger                      scratchBufferOffset,
    const AccelerationStructureRefitOptions options) const
{
    sendMessage<void>(
        this,
        _MTL_PRIVATE_SEL(refitAccelerationStructure_descriptor_destination_scratchBuffer_scratchBufferOffset_options_),
        sourceAccelerationStructure,
        descriptor,
        destinationAccelerationStructure,
        scratchBuffer,
        scratchBufferOffset,
        options);
}

_MTL_INLINE void MTL::AccelerationStructureCommandEncoder::sampleCountersInBuffer(
    const CounterSampleBuffer* sampleBuffer, const NS::UInteger sampleIndex, const bool barrier) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(sampleCountersInBuffer_atSampleIndex_withBarrier_), sampleBuffer, sampleIndex, barrier);
}

_MTL_INLINE void MTL::AccelerationStructureCommandEncoder::updateFence(const Fence* fence) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(updateFence_), fence);
}

_MTL_INLINE void MTL::AccelerationStructureCommandEncoder::useHeap(const Heap* heap) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(useHeap_), heap);
}

_MTL_INLINE void MTL::AccelerationStructureCommandEncoder::useHeaps(const Heap* const  heaps[],
                                                                    const NS::UInteger count) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(useHeaps_count_), heaps, count);
}

_MTL_INLINE void MTL::AccelerationStructureCommandEncoder::useResource(const Resource*     resource,
                                                                       const ResourceUsage usage) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(useResource_usage_), resource, usage);
}

_MTL_INLINE void MTL::AccelerationStructureCommandEncoder::useResources(const Resource* const resources[],
                                                                        const NS::UInteger    count,
                                                                        const ResourceUsage   usage) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(useResources_count_usage_), resources, count, usage);
}

_MTL_INLINE void MTL::AccelerationStructureCommandEncoder::waitForFence(const Fence* fence) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(waitForFence_), fence);
}

_MTL_INLINE void MTL::AccelerationStructureCommandEncoder::writeCompactedAccelerationStructureSize(
    const AccelerationStructure* accelerationStructure, const Buffer* buffer, const NS::UInteger offset) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(writeCompactedAccelerationStructureSize_toBuffer_offset_),
                      accelerationStructure,
                      buffer,
                      offset);
}

_MTL_INLINE void MTL::AccelerationStructureCommandEncoder::writeCompactedAccelerationStructureSize(
    const AccelerationStructure* accelerationStructure,
    const Buffer*                buffer,
    const NS::UInteger           offset,
    const DataType               sizeDataType) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(writeCompactedAccelerationStructureSize_toBuffer_offset_sizeDataType_),
                      accelerationStructure,
                      buffer,
                      offset,
                      sizeDataType);
}

_MTL_INLINE MTL::AccelerationStructurePassSampleBufferAttachmentDescriptor*
            MTL::AccelerationStructurePassSampleBufferAttachmentDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<AccelerationStructurePassSampleBufferAttachmentDescriptor>(
        _MTL_PRIVATE_CLS(MTLAccelerationStructurePassSampleBufferAttachmentDescriptor));
}

_MTL_INLINE NS::UInteger MTL::AccelerationStructurePassSampleBufferAttachmentDescriptor::endOfEncoderSampleIndex() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(endOfEncoderSampleIndex));
}

_MTL_INLINE MTL::AccelerationStructurePassSampleBufferAttachmentDescriptor*
            MTL::AccelerationStructurePassSampleBufferAttachmentDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<AccelerationStructurePassSampleBufferAttachmentDescriptor>();
}

_MTL_INLINE MTL::CounterSampleBuffer* MTL::AccelerationStructurePassSampleBufferAttachmentDescriptor::sampleBuffer()
    const
{
    return sendMessage<CounterSampleBuffer*>(this, _MTL_PRIVATE_SEL(sampleBuffer));
}

_MTL_INLINE void MTL::AccelerationStructurePassSampleBufferAttachmentDescriptor::setEndOfEncoderSampleIndex(
    const NS::UInteger endOfEncoderSampleIndex) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setEndOfEncoderSampleIndex_), endOfEncoderSampleIndex);
}

_MTL_INLINE void MTL::AccelerationStructurePassSampleBufferAttachmentDescriptor::setSampleBuffer(
    const CounterSampleBuffer* sampleBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSampleBuffer_), sampleBuffer);
}

_MTL_INLINE void MTL::AccelerationStructurePassSampleBufferAttachmentDescriptor::setStartOfEncoderSampleIndex(
    const NS::UInteger startOfEncoderSampleIndex) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setStartOfEncoderSampleIndex_), startOfEncoderSampleIndex);
}

_MTL_INLINE NS::UInteger MTL::AccelerationStructurePassSampleBufferAttachmentDescriptor::startOfEncoderSampleIndex()
    const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(startOfEncoderSampleIndex));
}

_MTL_INLINE MTL::AccelerationStructurePassSampleBufferAttachmentDescriptorArray*
            MTL::AccelerationStructurePassSampleBufferAttachmentDescriptorArray::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<AccelerationStructurePassSampleBufferAttachmentDescriptorArray>(
        _MTL_PRIVATE_CLS(MTLAccelerationStructurePassSampleBufferAttachmentDescriptorArray));
}

_MTL_INLINE MTL::AccelerationStructurePassSampleBufferAttachmentDescriptorArray*
            MTL::AccelerationStructurePassSampleBufferAttachmentDescriptorArray::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<AccelerationStructurePassSampleBufferAttachmentDescriptorArray>();
}

_MTL_INLINE MTL::AccelerationStructurePassSampleBufferAttachmentDescriptor*
MTL::AccelerationStructurePassSampleBufferAttachmentDescriptorArray::object(const NS::UInteger attachmentIndex) const
{
    return sendMessage<AccelerationStructurePassSampleBufferAttachmentDescriptor*>(
        this, _MTL_PRIVATE_SEL(objectAtIndexedSubscript_), attachmentIndex);
}

_MTL_INLINE void MTL::AccelerationStructurePassSampleBufferAttachmentDescriptorArray::setObject(
    const AccelerationStructurePassSampleBufferAttachmentDescriptor* attachment,
    const NS::UInteger                                               attachmentIndex) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setObject_atIndexedSubscript_), attachment, attachmentIndex);
}

_MTL_INLINE MTL::AccelerationStructurePassDescriptor*
            MTL::AccelerationStructurePassDescriptor::accelerationStructurePassDescriptor()
{
    return sendMessage<AccelerationStructurePassDescriptor*>(_MTL_PRIVATE_CLS(MTLAccelerationStructurePassDescriptor),
                                                             _MTL_PRIVATE_SEL(accelerationStructurePassDescriptor));
}

_MTL_INLINE MTL::AccelerationStructurePassDescriptor* MTL::AccelerationStructurePassDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<AccelerationStructurePassDescriptor>(
        _MTL_PRIVATE_CLS(MTLAccelerationStructurePassDescriptor));
}

_MTL_INLINE MTL::AccelerationStructurePassDescriptor* MTL::AccelerationStructurePassDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<AccelerationStructurePassDescriptor>();
}

_MTL_INLINE MTL::AccelerationStructurePassSampleBufferAttachmentDescriptorArray*
            MTL::AccelerationStructurePassDescriptor::sampleBufferAttachments() const
{
    return sendMessage<AccelerationStructurePassSampleBufferAttachmentDescriptorArray*>(
        this, _MTL_PRIVATE_SEL(sampleBufferAttachments));
}
