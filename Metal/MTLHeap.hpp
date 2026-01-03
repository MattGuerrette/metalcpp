//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLHeap.hpp
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
#include "MTLAllocation.hpp"
#include "MTLDefines.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"
#include "MTLResource.hpp"

namespace MTL
{
    class AccelerationStructure;
    class AccelerationStructureDescriptor;
    class Buffer;
    class Device;
    class HeapDescriptor;
    class Texture;
    class TextureDescriptor;

    /// @see https://developer.apple.com/documentation/metal/mtlheaptype?language=objc
    _MTL_ENUM(NS::Integer, HeapType){
        HeapTypeAutomatic = 0,
        HeapTypePlacement = 1,
        HeapTypeSparse    = 2,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlheapdescriptor?language=objc
    class HeapDescriptor : public NS::Copying<HeapDescriptor>
    {
    public:
        [[nodiscard]] static HeapDescriptor* alloc();

        [[nodiscard]] CPUCacheMode cpuCacheMode() const;

        [[nodiscard]] HazardTrackingMode hazardTrackingMode() const;

        [[nodiscard]] HeapDescriptor* init();

        [[nodiscard]] SparsePageSize maxCompatiblePlacementSparsePageSize() const;

        [[nodiscard]] ResourceOptions resourceOptions() const;

        void setCpuCacheMode(CPUCacheMode cpuCacheMode) const;

        void setHazardTrackingMode(HazardTrackingMode hazardTrackingMode) const;

        void setMaxCompatiblePlacementSparsePageSize(SparsePageSize maxCompatiblePlacementSparsePageSize) const;

        void setResourceOptions(ResourceOptions resourceOptions) const;

        void setSize(NS::UInteger size) const;

        void setSparsePageSize(SparsePageSize sparsePageSize) const;

        void setStorageMode(StorageMode storageMode) const;

        void setType(HeapType type) const;

        [[nodiscard]] NS::UInteger   size() const;
        [[nodiscard]] SparsePageSize sparsePageSize() const;

        [[nodiscard]] StorageMode storageMode() const;

        [[nodiscard]] HeapType type() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlheap?language=objc
    class Heap : public NS::Referencing<Heap, Allocation>
    {
    public:
        [[nodiscard]] CPUCacheMode cpuCacheMode() const;

        [[nodiscard]] NS::UInteger currentAllocatedSize() const;

        [[nodiscard]] Device* device() const;

        [[nodiscard]] HazardTrackingMode hazardTrackingMode() const;

        [[nodiscard]] NS::String* label() const;

        [[nodiscard]] NS::UInteger maxAvailableSize(NS::UInteger alignment) const;

        [[nodiscard]] AccelerationStructure* newAccelerationStructure(NS::UInteger size) const;
        [[nodiscard]] AccelerationStructure* newAccelerationStructure(
            const AccelerationStructureDescriptor* descriptor) const;
        [[nodiscard]] AccelerationStructure* newAccelerationStructure(NS::UInteger size, NS::UInteger offset) const;
        [[nodiscard]] AccelerationStructure* newAccelerationStructure(const AccelerationStructureDescriptor* descriptor,
                                                                      NS::UInteger offset) const;

        [[nodiscard]] Buffer* newBuffer(NS::UInteger length, ResourceOptions options) const;
        [[nodiscard]] Buffer* newBuffer(NS::UInteger length, ResourceOptions options, NS::UInteger offset) const;

        [[nodiscard]] Texture* newTexture(const TextureDescriptor* descriptor) const;
        [[nodiscard]] Texture* newTexture(const TextureDescriptor* descriptor, NS::UInteger offset) const;

        [[nodiscard]] ResourceOptions resourceOptions() const;

        void setLabel(const NS::String* label) const;

        [[nodiscard]] PurgeableState setPurgeableState(PurgeableState state) const;

        [[nodiscard]] NS::UInteger size() const;

        [[nodiscard]] StorageMode storageMode() const;

        [[nodiscard]] HeapType type() const;

        [[nodiscard]] NS::UInteger usedSize() const;
    };

} // namespace MTL
_MTL_INLINE MTL::HeapDescriptor* MTL::HeapDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<HeapDescriptor>(_MTL_PRIVATE_CLS(MTLHeapDescriptor));
}

_MTL_INLINE MTL::CPUCacheMode MTL::HeapDescriptor::cpuCacheMode() const
{
    return sendMessage<CPUCacheMode>(this, _MTL_PRIVATE_SEL(cpuCacheMode));
}

_MTL_INLINE MTL::HazardTrackingMode MTL::HeapDescriptor::hazardTrackingMode() const
{
    return sendMessage<HazardTrackingMode>(this, _MTL_PRIVATE_SEL(hazardTrackingMode));
}

_MTL_INLINE MTL::HeapDescriptor* MTL::HeapDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<HeapDescriptor>();
}

_MTL_INLINE MTL::SparsePageSize MTL::HeapDescriptor::maxCompatiblePlacementSparsePageSize() const
{
    return sendMessage<SparsePageSize>(this, _MTL_PRIVATE_SEL(maxCompatiblePlacementSparsePageSize));
}

_MTL_INLINE MTL::ResourceOptions MTL::HeapDescriptor::resourceOptions() const
{
    return sendMessage<ResourceOptions>(this, _MTL_PRIVATE_SEL(resourceOptions));
}

_MTL_INLINE void MTL::HeapDescriptor::setCpuCacheMode(const CPUCacheMode cpuCacheMode) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setCpuCacheMode_), cpuCacheMode);
}

_MTL_INLINE void MTL::HeapDescriptor::setHazardTrackingMode(const HazardTrackingMode hazardTrackingMode) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setHazardTrackingMode_), hazardTrackingMode);
}

_MTL_INLINE void MTL::HeapDescriptor::setMaxCompatiblePlacementSparsePageSize(
    const SparsePageSize maxCompatiblePlacementSparsePageSize) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setMaxCompatiblePlacementSparsePageSize_), maxCompatiblePlacementSparsePageSize);
}

_MTL_INLINE void MTL::HeapDescriptor::setResourceOptions(const ResourceOptions resourceOptions) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setResourceOptions_), resourceOptions);
}

_MTL_INLINE void MTL::HeapDescriptor::setSize(const NS::UInteger size) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSize_), size);
}

_MTL_INLINE void MTL::HeapDescriptor::setSparsePageSize(const SparsePageSize sparsePageSize) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSparsePageSize_), sparsePageSize);
}

_MTL_INLINE void MTL::HeapDescriptor::setStorageMode(const StorageMode storageMode) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setStorageMode_), storageMode);
}

_MTL_INLINE void MTL::HeapDescriptor::setType(const HeapType type) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setType_), type);
}

_MTL_INLINE NS::UInteger MTL::HeapDescriptor::size() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(size));
}

_MTL_INLINE MTL::SparsePageSize MTL::HeapDescriptor::sparsePageSize() const
{
    return sendMessage<SparsePageSize>(this, _MTL_PRIVATE_SEL(sparsePageSize));
}

_MTL_INLINE MTL::StorageMode MTL::HeapDescriptor::storageMode() const
{
    return sendMessage<StorageMode>(this, _MTL_PRIVATE_SEL(storageMode));
}

_MTL_INLINE MTL::HeapType MTL::HeapDescriptor::type() const
{
    return sendMessage<HeapType>(this, _MTL_PRIVATE_SEL(type));
}

_MTL_INLINE MTL::CPUCacheMode MTL::Heap::cpuCacheMode() const
{
    return sendMessage<CPUCacheMode>(this, _MTL_PRIVATE_SEL(cpuCacheMode));
}

_MTL_INLINE NS::UInteger MTL::Heap::currentAllocatedSize() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(currentAllocatedSize));
}

_MTL_INLINE MTL::Device* MTL::Heap::device() const { return sendMessage<Device*>(this, _MTL_PRIVATE_SEL(device)); }

_MTL_INLINE MTL::HazardTrackingMode MTL::Heap::hazardTrackingMode() const
{
    return sendMessage<HazardTrackingMode>(this, _MTL_PRIVATE_SEL(hazardTrackingMode));
}

_MTL_INLINE NS::String* MTL::Heap::label() const { return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label)); }

_MTL_INLINE NS::UInteger MTL::Heap::maxAvailableSize(const NS::UInteger alignment) const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxAvailableSizeWithAlignment_), alignment);
}

_MTL_INLINE MTL::AccelerationStructure* MTL::Heap::newAccelerationStructure(const NS::UInteger size) const
{
    return sendMessage<AccelerationStructure*>(this, _MTL_PRIVATE_SEL(newAccelerationStructureWithSize_), size);
}

_MTL_INLINE MTL::AccelerationStructure* MTL::Heap::newAccelerationStructure(
    const AccelerationStructureDescriptor* descriptor) const
{
    return sendMessage<AccelerationStructure*>(
        this, _MTL_PRIVATE_SEL(newAccelerationStructureWithDescriptor_), descriptor);
}

_MTL_INLINE MTL::AccelerationStructure* MTL::Heap::newAccelerationStructure(const NS::UInteger size,
                                                                            const NS::UInteger offset) const
{
    return sendMessage<AccelerationStructure*>(
        this, _MTL_PRIVATE_SEL(newAccelerationStructureWithSize_offset_), size, offset);
}

_MTL_INLINE MTL::AccelerationStructure* MTL::Heap::newAccelerationStructure(
    const AccelerationStructureDescriptor* descriptor, const NS::UInteger offset) const
{
    return sendMessage<AccelerationStructure*>(
        this, _MTL_PRIVATE_SEL(newAccelerationStructureWithDescriptor_offset_), descriptor, offset);
}

_MTL_INLINE MTL::Buffer* MTL::Heap::newBuffer(const NS::UInteger length, const ResourceOptions options) const
{
    return sendMessage<Buffer*>(this, _MTL_PRIVATE_SEL(newBufferWithLength_options_), length, options);
}

_MTL_INLINE MTL::Buffer* MTL::Heap::newBuffer(const NS::UInteger    length,
                                              const ResourceOptions options,
                                              const NS::UInteger    offset) const
{
    return sendMessage<Buffer*>(this, _MTL_PRIVATE_SEL(newBufferWithLength_options_offset_), length, options, offset);
}

_MTL_INLINE MTL::Texture* MTL::Heap::newTexture(const TextureDescriptor* descriptor) const
{
    return sendMessage<Texture*>(this, _MTL_PRIVATE_SEL(newTextureWithDescriptor_), descriptor);
}

_MTL_INLINE MTL::Texture* MTL::Heap::newTexture(const TextureDescriptor* descriptor, const NS::UInteger offset) const
{
    return sendMessage<Texture*>(this, _MTL_PRIVATE_SEL(newTextureWithDescriptor_offset_), descriptor, offset);
}

_MTL_INLINE MTL::ResourceOptions MTL::Heap::resourceOptions() const
{
    return sendMessage<ResourceOptions>(this, _MTL_PRIVATE_SEL(resourceOptions));
}

_MTL_INLINE void MTL::Heap::setLabel(const NS::String* label) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLabel_), label);
}

_MTL_INLINE MTL::PurgeableState MTL::Heap::setPurgeableState(const PurgeableState state) const
{
    return sendMessage<PurgeableState>(this, _MTL_PRIVATE_SEL(setPurgeableState_), state);
}

_MTL_INLINE NS::UInteger MTL::Heap::size() const { return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(size)); }

_MTL_INLINE MTL::StorageMode MTL::Heap::storageMode() const
{
    return sendMessage<StorageMode>(this, _MTL_PRIVATE_SEL(storageMode));
}

_MTL_INLINE MTL::HeapType MTL::Heap::type() const { return sendMessage<HeapType>(this, _MTL_PRIVATE_SEL(type)); }

_MTL_INLINE NS::UInteger MTL::Heap::usedSize() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(usedSize));
}
