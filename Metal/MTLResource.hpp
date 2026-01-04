//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLResource.hpp
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

#include <mach/mach.h>
#include "../Foundation/Foundation.hpp"
#include "MTLAllocation.hpp"
#include "MTLDefines.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"

namespace MTL
{
    class Device;
    class Heap;

    /// @see https://developer.apple.com/documentation/metal/mtlpurgeablestate?language=objc
    _MTL_ENUM(NS::UInteger, PurgeableState){
        PurgeableStateKeepCurrent = 1,
        PurgeableStateNonVolatile = 2,
        PurgeableStateVolatile    = 3,
        PurgeableStateEmpty       = 4,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlcpucachemode?language=objc
    _MTL_ENUM(NS::UInteger, CPUCacheMode){
        CPUCacheModeDefaultCache  = 0,
        CPUCacheModeWriteCombined = 1,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlstoragemode?language=objc
    _MTL_ENUM(NS::UInteger, StorageMode){
        StorageModeShared     = 0,
        StorageModeManaged    = 1,
        StorageModePrivate    = 2,
        StorageModeMemoryless = 3,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlhazardtrackingmode?language=objc
    _MTL_ENUM(NS::UInteger, HazardTrackingMode){
        HazardTrackingModeDefault   = 0,
        HazardTrackingModeUntracked = 1,
        HazardTrackingModeTracked   = 2,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlsparsepagesize?language=objc
    _MTL_ENUM(NS::Integer, SparsePageSize){
        SparsePageSize16  = 101,
        SparsePageSize64  = 102,
        SparsePageSize256 = 103,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlbuffersparsetier?language=objc
    _MTL_ENUM(NS::Integer, BufferSparseTier){
        BufferSparseTierNone = 0,
        BufferSparseTier1    = 1,
    };

    /// @see https://developer.apple.com/documentation/metal/mtltexturesparsetier?language=objc
    _MTL_ENUM(NS::Integer, TextureSparseTier){
        TextureSparseTierNone = 0,
        TextureSparseTier1    = 1,
        TextureSparseTier2    = 2,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlresourceoptions?language=objc
    _MTL_OPTIONS(NS::UInteger, ResourceOptions){
        ResourceCPUCacheModeDefaultCache        = 0,
        ResourceCPUCacheModeWriteCombined       = 1,
        ResourceStorageModeShared               = 0,
        ResourceStorageModeManaged              = 1 << 4,
        ResourceStorageModePrivate              = 1 << 5,
        ResourceStorageModeMemoryless           = 1 << 5,
        ResourceHazardTrackingModeDefault       = 0,
        ResourceHazardTrackingModeUntracked     = 1 << 8,
        ResourceHazardTrackingModeTracked       = 1 << 9,
        ResourceOptionCPUCacheModeDefault       = 0,
        ResourceOptionCPUCacheModeWriteCombined = 1,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlresource?language=objc
    class Resource : public NS::Referencing<Resource, Allocation>
    {
    public:
        [[nodiscard]] NS::UInteger allocatedSize() const;

        [[nodiscard]] CPUCacheMode cpuCacheMode() const;

        [[nodiscard]] Device* device() const;

        [[nodiscard]] HazardTrackingMode hazardTrackingMode() const;

        [[nodiscard]] Heap*        heap() const;
        [[nodiscard]] NS::UInteger heapOffset() const;

        [[nodiscard]] bool isAliasable() const;

        [[nodiscard]] NS::String* label() const;

        void makeAliasable() const;

        [[nodiscard]] ResourceOptions resourceOptions() const;

        void setLabel(const NS::String* label) const;

        [[nodiscard]] kern_return_t setOwner(task_id_token_t task_id_token) const;

        [[nodiscard]] PurgeableState setPurgeableState(PurgeableState state) const;

        [[nodiscard]] StorageMode storageMode() const;
    };

} // namespace MTL
_MTL_INLINE NS::UInteger MTL::Resource::allocatedSize() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(allocatedSize));
}

_MTL_INLINE MTL::CPUCacheMode MTL::Resource::cpuCacheMode() const
{
    return sendMessage<CPUCacheMode>(this, _MTL_PRIVATE_SEL(cpuCacheMode));
}

_MTL_INLINE MTL::Device* MTL::Resource::device() const { return sendMessage<Device*>(this, _MTL_PRIVATE_SEL(device)); }

_MTL_INLINE MTL::HazardTrackingMode MTL::Resource::hazardTrackingMode() const
{
    return sendMessage<HazardTrackingMode>(this, _MTL_PRIVATE_SEL(hazardTrackingMode));
}

_MTL_INLINE MTL::Heap* MTL::Resource::heap() const { return sendMessage<Heap*>(this, _MTL_PRIVATE_SEL(heap)); }

_MTL_INLINE NS::UInteger MTL::Resource::heapOffset() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(heapOffset));
}

_MTL_INLINE bool MTL::Resource::isAliasable() const { return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isAliasable)); }

_MTL_INLINE NS::String* MTL::Resource::label() const { return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label)); }

_MTL_INLINE void MTL::Resource::makeAliasable() const { sendMessage<void>(this, _MTL_PRIVATE_SEL(makeAliasable)); }

_MTL_INLINE MTL::ResourceOptions MTL::Resource::resourceOptions() const
{
    return sendMessage<ResourceOptions>(this, _MTL_PRIVATE_SEL(resourceOptions));
}

_MTL_INLINE void MTL::Resource::setLabel(const NS::String* label) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLabel_), label);
}

_MTL_INLINE kern_return_t MTL::Resource::setOwner(const task_id_token_t task_id_token) const
{
    return sendMessage<kern_return_t>(this, _MTL_PRIVATE_SEL(setOwnerWithIdentity_), task_id_token);
}

_MTL_INLINE MTL::PurgeableState MTL::Resource::setPurgeableState(const PurgeableState state) const
{
    return sendMessage<PurgeableState>(this, _MTL_PRIVATE_SEL(setPurgeableState_), state);
}

_MTL_INLINE MTL::StorageMode MTL::Resource::storageMode() const
{
    return sendMessage<StorageMode>(this, _MTL_PRIVATE_SEL(storageMode));
}
