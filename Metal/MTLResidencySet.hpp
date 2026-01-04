//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLResidencySet.hpp
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

#include <cstdint>
#include "../Foundation/Foundation.hpp"
#include "MTLDefines.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"

namespace MTL
{
    class Allocation;
    class Device;
    class ResidencySetDescriptor;

    /// @see https://developer.apple.com/documentation/metal/mtlresidencysetdescriptor?language=objc
    class ResidencySetDescriptor : public NS::Copying<ResidencySetDescriptor>
    {
    public:
        [[nodiscard]] static ResidencySetDescriptor* alloc();

        [[nodiscard]] ResidencySetDescriptor* init();
        [[nodiscard]] NS::UInteger            initialCapacity() const;

        [[nodiscard]] NS::String* label() const;

        void setInitialCapacity(NS::UInteger initialCapacity) const;

        void setLabel(const NS::String* label) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlresidencyset?language=objc
    class ResidencySet : public NS::Referencing<ResidencySet>
    {
    public:
        void addAllocation(const Allocation* allocation) const;
        void addAllocations(const Allocation* const allocations[], NS::UInteger count) const;

        [[nodiscard]] NS::Array* allAllocations() const;

        [[nodiscard]] uint64_t allocatedSize() const;

        [[nodiscard]] NS::UInteger allocationCount() const;

        void commit() const;

        [[nodiscard]] bool containsAllocation(const Allocation* anAllocation) const;

        [[nodiscard]] Device* device() const;

        void endResidency() const;

        [[nodiscard]] NS::String* label() const;

        void removeAllAllocations() const;

        void removeAllocation(const Allocation* allocation) const;
        void removeAllocations(const Allocation* const allocations[], NS::UInteger count) const;

        void requestResidency() const;
    };

} // namespace MTL

_MTL_INLINE MTL::ResidencySetDescriptor* MTL::ResidencySetDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<ResidencySetDescriptor>(_MTL_PRIVATE_CLS(MTLResidencySetDescriptor));
}

_MTL_INLINE MTL::ResidencySetDescriptor* MTL::ResidencySetDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<ResidencySetDescriptor>();
}

_MTL_INLINE NS::UInteger MTL::ResidencySetDescriptor::initialCapacity() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(initialCapacity));
}

_MTL_INLINE NS::String* MTL::ResidencySetDescriptor::label() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
}

_MTL_INLINE void MTL::ResidencySetDescriptor::setInitialCapacity(const NS::UInteger initialCapacity) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setInitialCapacity_), initialCapacity);
}

_MTL_INLINE void MTL::ResidencySetDescriptor::setLabel(const NS::String* label) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLabel_), label);
}

_MTL_INLINE void MTL::ResidencySet::addAllocation(const Allocation* allocation) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(addAllocation_), allocation);
}

_MTL_INLINE void MTL::ResidencySet::addAllocations(const Allocation* const allocations[],
                                                   const NS::UInteger      count) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(addAllocations_count_), allocations, count);
}

_MTL_INLINE NS::Array* MTL::ResidencySet::allAllocations() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(allAllocations));
}

_MTL_INLINE uint64_t MTL::ResidencySet::allocatedSize() const
{
    return sendMessage<uint64_t>(this, _MTL_PRIVATE_SEL(allocatedSize));
}

_MTL_INLINE NS::UInteger MTL::ResidencySet::allocationCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(allocationCount));
}

_MTL_INLINE void MTL::ResidencySet::commit() const { sendMessage<void>(this, _MTL_PRIVATE_SEL(commit)); }

_MTL_INLINE bool MTL::ResidencySet::containsAllocation(const Allocation* anAllocation) const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(containsAllocation_), anAllocation);
}

_MTL_INLINE MTL::Device* MTL::ResidencySet::device() const
{
    return sendMessage<Device*>(this, _MTL_PRIVATE_SEL(device));
}

_MTL_INLINE void MTL::ResidencySet::endResidency() const { sendMessage<void>(this, _MTL_PRIVATE_SEL(endResidency)); }

_MTL_INLINE NS::String* MTL::ResidencySet::label() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
}

_MTL_INLINE void MTL::ResidencySet::removeAllAllocations() const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(removeAllAllocations));
}

_MTL_INLINE void MTL::ResidencySet::removeAllocation(const Allocation* allocation) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(removeAllocation_), allocation);
}

_MTL_INLINE void MTL::ResidencySet::removeAllocations(const Allocation* const allocations[],
                                                      const NS::UInteger      count) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(removeAllocations_count_), allocations, count);
}

_MTL_INLINE void MTL::ResidencySet::requestResidency() const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(requestResidency));
}
