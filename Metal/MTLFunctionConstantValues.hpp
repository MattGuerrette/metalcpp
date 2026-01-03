//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLFunctionConstantValues.hpp
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
#include "MTLDataType.hpp"
#include "MTLDefines.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"

namespace MTL
{
    class FunctionConstantValues;

    /// @see https://developer.apple.com/documentation/metal/mtlfunctionconstantvalues?language=objc
    class FunctionConstantValues : public NS::Copying<FunctionConstantValues>
    {
    public:
        [[nodiscard]] static FunctionConstantValues* alloc();

        [[nodiscard]] FunctionConstantValues* init();

        void reset() const;

        void setConstantValue(const void* value, DataType type, NS::UInteger index) const;
        void setConstantValue(const void* value, DataType type, const NS::String* name) const;
        void setConstantValues(const void* values, DataType type, NS::Range range) const;
    };

} // namespace MTL
_MTL_INLINE MTL::FunctionConstantValues* MTL::FunctionConstantValues::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<FunctionConstantValues>(_MTL_PRIVATE_CLS(MTLFunctionConstantValues));
}

_MTL_INLINE MTL::FunctionConstantValues* MTL::FunctionConstantValues::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<FunctionConstantValues>();
}

_MTL_INLINE void MTL::FunctionConstantValues::reset() const { sendMessage<void>(this, _MTL_PRIVATE_SEL(reset)); }

_MTL_INLINE void MTL::FunctionConstantValues::setConstantValue(const void*        value,
                                                               const DataType     type,
                                                               const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setConstantValue_type_atIndex_), value, type, index);
}

_MTL_INLINE void MTL::FunctionConstantValues::setConstantValue(const void*       value,
                                                               const DataType    type,
                                                               const NS::String* name) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setConstantValue_type_withName_), value, type, name);
}

_MTL_INLINE void MTL::FunctionConstantValues::setConstantValues(const void*     values,
                                                                const DataType  type,
                                                                const NS::Range range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setConstantValues_type_withRange_), values, type, range);
}
