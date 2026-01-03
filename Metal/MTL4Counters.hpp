//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTL4Counters.hpp
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

namespace MTL4
{
    class CounterHeapDescriptor;
    _MTL_ENUM(NS::Integer, CounterHeapType){
        CounterHeapTypeInvalid,
        CounterHeapTypeTimestamp,
    };

    _MTL_ENUM(NS::Integer, TimestampGranularity){
        TimestampGranularityRelaxed = 0,
        TimestampGranularityPrecise = 1,
    };

    struct TimestampHeapEntry
    {
        uint64_t timestamp;
    } _MTL_PACKED;

    /// @see https://developer.apple.com/documentation/metal/mtl4counterheapdescriptor
    class CounterHeapDescriptor : public NS::Copying<CounterHeapDescriptor>
    {
    public:
        [[nodiscard]] static CounterHeapDescriptor* alloc();

        [[nodiscard]] NS::UInteger count() const;

        [[nodiscard]] CounterHeapDescriptor* init();

        [[nodiscard]] CounterHeapType type() const;

        void setCount(NS::UInteger count) const;

        void setType(CounterHeapType type) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtl4counterheap
    class CounterHeap : public NS::Referencing<CounterHeap>
    {
    public:
        [[nodiscard]] NS::UInteger count() const;

        [[nodiscard]] NS::String* label() const;

        [[nodiscard]] NS::Data* resolveCounterRange(NS::Range range) const;

        [[nodiscard]] CounterHeapType type() const;

        void setLabel(const NS::String* label) const;

        void invalidateCounterRange(NS::Range range) const;
    };

} // namespace MTL4

_MTL_INLINE MTL4::CounterHeapDescriptor* MTL4::CounterHeapDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<CounterHeapDescriptor>(_MTL_PRIVATE_CLS(MTL4CounterHeapDescriptor));
}

_MTL_INLINE NS::UInteger MTL4::CounterHeapDescriptor::count() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(count));
}

_MTL_INLINE MTL4::CounterHeapDescriptor* MTL4::CounterHeapDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<CounterHeapDescriptor>();
}

_MTL_INLINE void MTL4::CounterHeapDescriptor::setCount(const NS::UInteger count) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setCount_), count);
}

_MTL_INLINE void MTL4::CounterHeapDescriptor::setType(const CounterHeapType type) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setType_), type);
}

_MTL_INLINE MTL4::CounterHeapType MTL4::CounterHeapDescriptor::type() const
{
    return sendMessage<CounterHeapType>(this, _MTL_PRIVATE_SEL(type));
}

_MTL_INLINE NS::UInteger MTL4::CounterHeap::count() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(count));
}

_MTL_INLINE void MTL4::CounterHeap::invalidateCounterRange(const NS::Range range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(invalidateCounterRange_), range);
}

_MTL_INLINE NS::String* MTL4::CounterHeap::label() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
}

_MTL_INLINE NS::Data* MTL4::CounterHeap::resolveCounterRange(const NS::Range range) const
{
    return sendMessage<NS::Data*>(this, _MTL_PRIVATE_SEL(resolveCounterRange_), range);
}

_MTL_INLINE void MTL4::CounterHeap::setLabel(const NS::String* label) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLabel_), label);
}

_MTL_INLINE MTL4::CounterHeapType MTL4::CounterHeap::type() const
{
    return sendMessage<CounterHeapType>(this, _MTL_PRIVATE_SEL(type));
}
