//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTL4BinaryFunctionDescriptor.hpp
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

namespace MTL4
{
    class BinaryFunctionDescriptor;
    class FunctionDescriptor;

    _MTL_OPTIONS(NS::UInteger, BinaryFunctionOptions){
        BinaryFunctionOptionNone                = 0,
        BinaryFunctionOptionPipelineIndependent = 1 << 1,
    };

    class BinaryFunctionDescriptor : public NS::Copying<BinaryFunctionDescriptor>
    {
    public:
        [[nodiscard]] static BinaryFunctionDescriptor* alloc();

        [[nodiscard]] FunctionDescriptor* functionDescriptor() const;

        [[nodiscard]] BinaryFunctionDescriptor* init();

        [[nodiscard]] NS::String* name() const;

        [[nodiscard]] BinaryFunctionOptions options() const;

        void setFunctionDescriptor(const FunctionDescriptor* functionDescriptor) const;

        void setName(const NS::String* name) const;

        void setOptions(BinaryFunctionOptions options) const;
    };

} // namespace MTL4
_MTL_INLINE MTL4::BinaryFunctionDescriptor* MTL4::BinaryFunctionDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<BinaryFunctionDescriptor>(_MTL_PRIVATE_CLS(MTL4BinaryFunctionDescriptor));
}

_MTL_INLINE MTL4::FunctionDescriptor* MTL4::BinaryFunctionDescriptor::functionDescriptor() const
{
    return sendMessage<FunctionDescriptor*>(this, _MTL_PRIVATE_SEL(functionDescriptor));
}

_MTL_INLINE MTL4::BinaryFunctionDescriptor* MTL4::BinaryFunctionDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<BinaryFunctionDescriptor>();
}

_MTL_INLINE NS::String* MTL4::BinaryFunctionDescriptor::name() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(name));
}

_MTL_INLINE MTL4::BinaryFunctionOptions MTL4::BinaryFunctionDescriptor::options() const
{
    return sendMessage<BinaryFunctionOptions>(this, _MTL_PRIVATE_SEL(options));
}

_MTL_INLINE void MTL4::BinaryFunctionDescriptor::setFunctionDescriptor(
    const FunctionDescriptor* functionDescriptor) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFunctionDescriptor_), functionDescriptor);
}

_MTL_INLINE void MTL4::BinaryFunctionDescriptor::setName(const NS::String* name) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setName_), name);
}

_MTL_INLINE void MTL4::BinaryFunctionDescriptor::setOptions(const BinaryFunctionOptions options) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setOptions_), options);
}
