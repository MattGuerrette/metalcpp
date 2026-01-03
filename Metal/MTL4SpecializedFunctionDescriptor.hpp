//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTL4SpecializedFunctionDescriptor.hpp
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
#include "MTL4FunctionDescriptor.hpp"
#include "MTLDefines.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"

namespace MTL4
{
    class FunctionDescriptor;
    class SpecializedFunctionDescriptor;
} // namespace MTL4

namespace MTL
{
    class FunctionConstantValues;
}

namespace MTL4
{
    /// @see https://developer.apple.com/documentation/metal/mtl4specializedfunctiondescriptor
    class SpecializedFunctionDescriptor : public NS::Copying<SpecializedFunctionDescriptor, FunctionDescriptor>
    {
    public:
        [[nodiscard]] static SpecializedFunctionDescriptor* alloc();

        [[nodiscard]] MTL::FunctionConstantValues* constantValues() const;

        [[nodiscard]] FunctionDescriptor* functionDescriptor() const;

        [[nodiscard]] SpecializedFunctionDescriptor* init();

        [[nodiscard]] NS::String* specializedName() const;

        void setConstantValues(const MTL::FunctionConstantValues* constantValues) const;

        void setFunctionDescriptor(const FunctionDescriptor* functionDescriptor) const;

        void setSpecializedName(const NS::String* specializedName) const;
    };

} // namespace MTL4
_MTL_INLINE MTL4::SpecializedFunctionDescriptor* MTL4::SpecializedFunctionDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<SpecializedFunctionDescriptor>(_MTL_PRIVATE_CLS(MTL4SpecializedFunctionDescriptor));
}

_MTL_INLINE MTL::FunctionConstantValues* MTL4::SpecializedFunctionDescriptor::constantValues() const
{
    return sendMessage<MTL::FunctionConstantValues*>(this, _MTL_PRIVATE_SEL(constantValues));
}

_MTL_INLINE MTL4::FunctionDescriptor* MTL4::SpecializedFunctionDescriptor::functionDescriptor() const
{
    return sendMessage<FunctionDescriptor*>(this, _MTL_PRIVATE_SEL(functionDescriptor));
}

_MTL_INLINE MTL4::SpecializedFunctionDescriptor* MTL4::SpecializedFunctionDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<SpecializedFunctionDescriptor>();
}

_MTL_INLINE void MTL4::SpecializedFunctionDescriptor::setConstantValues(
    const MTL::FunctionConstantValues* constantValues) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setConstantValues_), constantValues);
}

_MTL_INLINE void MTL4::SpecializedFunctionDescriptor::setFunctionDescriptor(
    const FunctionDescriptor* functionDescriptor) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFunctionDescriptor_), functionDescriptor);
}

_MTL_INLINE void MTL4::SpecializedFunctionDescriptor::setSpecializedName(const NS::String* specializedName) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSpecializedName_), specializedName);
}

_MTL_INLINE NS::String* MTL4::SpecializedFunctionDescriptor::specializedName() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(specializedName));
}
