//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLVisibleFunctionTable.hpp
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
#include "MTLResource.hpp"
#include "MTLTypes.hpp"

namespace MTL
{
    class FunctionHandle;
    class VisibleFunctionTableDescriptor;

    /// @see https://developer.apple.com/documentation/metal/mtlvisiblefunctiontabledescriptor?language=objc
    class VisibleFunctionTableDescriptor : public NS::Copying<VisibleFunctionTableDescriptor>
    {
    public:
        [[nodiscard]] static VisibleFunctionTableDescriptor* alloc();

        [[nodiscard]] NS::UInteger functionCount() const;

        [[nodiscard]] VisibleFunctionTableDescriptor* init();

        void setFunctionCount(NS::UInteger functionCount) const;

        [[nodiscard]] static VisibleFunctionTableDescriptor* visibleFunctionTableDescriptor();
    };

    /// @see https://developer.apple.com/documentation/metal/mtlvisiblefunctiontable?language=objc
    class VisibleFunctionTable : public NS::Referencing<VisibleFunctionTable, Resource>
    {
    public:
        [[nodiscard]] ResourceID gpuResourceID() const;

        void setFunction(const FunctionHandle* function, NS::UInteger index) const;
        void setFunctions(const FunctionHandle* const functions[], NS::Range range) const;
    };

} // namespace MTL
_MTL_INLINE MTL::VisibleFunctionTableDescriptor* MTL::VisibleFunctionTableDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<VisibleFunctionTableDescriptor>(_MTL_PRIVATE_CLS(MTLVisibleFunctionTableDescriptor));
}

_MTL_INLINE NS::UInteger MTL::VisibleFunctionTableDescriptor::functionCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(functionCount));
}

_MTL_INLINE MTL::VisibleFunctionTableDescriptor* MTL::VisibleFunctionTableDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<VisibleFunctionTableDescriptor>();
}

_MTL_INLINE void MTL::VisibleFunctionTableDescriptor::setFunctionCount(const NS::UInteger functionCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFunctionCount_), functionCount);
}

_MTL_INLINE MTL::VisibleFunctionTableDescriptor* MTL::VisibleFunctionTableDescriptor::visibleFunctionTableDescriptor()
{
    return sendMessage<VisibleFunctionTableDescriptor*>(_MTL_PRIVATE_CLS(MTLVisibleFunctionTableDescriptor),
                                                        _MTL_PRIVATE_SEL(visibleFunctionTableDescriptor));
}

_MTL_INLINE MTL::ResourceID MTL::VisibleFunctionTable::gpuResourceID() const
{
    return sendMessage<ResourceID>(this, _MTL_PRIVATE_SEL(gpuResourceID));
}

_MTL_INLINE void MTL::VisibleFunctionTable::setFunction(const FunctionHandle* function, const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFunction_atIndex_), function, index);
}

_MTL_INLINE void MTL::VisibleFunctionTable::setFunctions(const FunctionHandle* const functions[],
                                                         const NS::Range             range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFunctions_withRange_), functions, range);
}
