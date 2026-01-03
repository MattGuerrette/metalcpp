//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTL4CommandAllocator.hpp
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
    class Device;
}

namespace MTL4
{
    /// @see https://developer.apple.com/documentation/metal/mtl4commandallocatordescriptor
    class CommandAllocatorDescriptor : public NS::Copying<CommandAllocatorDescriptor>
    {
    public:
        [[nodiscard]] static CommandAllocatorDescriptor* alloc();

        [[nodiscard]] CommandAllocatorDescriptor* init();

        [[nodiscard]] NS::String* label() const;

        void setLabel(const NS::String* label) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtl4commandallocator
    class CommandAllocator : public NS::Referencing<CommandAllocator>
    {
    public:
        [[nodiscard]] uint64_t allocatedSize() const;

        [[nodiscard]] MTL::Device* device() const;

        [[nodiscard]] NS::String* label() const;

        void reset() const;
    };

} // namespace MTL4

_MTL_INLINE MTL4::CommandAllocatorDescriptor* MTL4::CommandAllocatorDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<CommandAllocatorDescriptor>(_MTL_PRIVATE_CLS(MTL4CommandAllocatorDescriptor));
}

_MTL_INLINE MTL4::CommandAllocatorDescriptor* MTL4::CommandAllocatorDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<CommandAllocatorDescriptor>();
}

_MTL_INLINE NS::String* MTL4::CommandAllocatorDescriptor::label() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
}

_MTL_INLINE void MTL4::CommandAllocatorDescriptor::setLabel(const NS::String* label) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLabel_), label);
}

_MTL_INLINE uint64_t MTL4::CommandAllocator::allocatedSize() const
{
    return sendMessage<uint64_t>(this, _MTL_PRIVATE_SEL(allocatedSize));
}

_MTL_INLINE MTL::Device* MTL4::CommandAllocator::device() const
{
    return sendMessage<MTL::Device*>(this, _MTL_PRIVATE_SEL(device));
}

_MTL_INLINE NS::String* MTL4::CommandAllocator::label() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
}

_MTL_INLINE void MTL4::CommandAllocator::reset() const { sendMessage<void>(this, _MTL_PRIVATE_SEL(reset)); }
