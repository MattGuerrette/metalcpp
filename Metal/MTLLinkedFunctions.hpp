//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLLinkedFunctions.hpp
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

namespace MTL
{
    /// @see https://developer.apple.com/documentation/metal/mtllinkedfunctions?language=objc
    class LinkedFunctions : public NS::Copying<LinkedFunctions>
    {
    public:
        [[nodiscard]] static LinkedFunctions* alloc();

        [[nodiscard]] NS::Array* binaryFunctions() const;
        [[nodiscard]] NS::Array* functions() const;

        [[nodiscard]] NS::Dictionary* groups() const;

        [[nodiscard]] LinkedFunctions* init();

        [[nodiscard]] static LinkedFunctions* linkedFunctions();

        [[nodiscard]] NS::Array* privateFunctions() const;

        void setBinaryFunctions(const NS::Array* binaryFunctions) const;

        void setFunctions(const NS::Array* functions) const;

        void setGroups(const NS::Dictionary* groups) const;

        void setPrivateFunctions(const NS::Array* privateFunctions) const;
    };

} // namespace MTL
_MTL_INLINE MTL::LinkedFunctions* MTL::LinkedFunctions::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<LinkedFunctions>(_MTL_PRIVATE_CLS(MTLLinkedFunctions));
}

_MTL_INLINE NS::Array* MTL::LinkedFunctions::binaryFunctions() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(binaryFunctions));
}

_MTL_INLINE NS::Array* MTL::LinkedFunctions::functions() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(functions));
}

_MTL_INLINE NS::Dictionary* MTL::LinkedFunctions::groups() const
{
    return sendMessage<NS::Dictionary*>(this, _MTL_PRIVATE_SEL(groups));
}

_MTL_INLINE MTL::LinkedFunctions* MTL::LinkedFunctions::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<LinkedFunctions>();
}

_MTL_INLINE MTL::LinkedFunctions* MTL::LinkedFunctions::linkedFunctions()
{
    return sendMessage<LinkedFunctions*>(_MTL_PRIVATE_CLS(MTLLinkedFunctions), _MTL_PRIVATE_SEL(linkedFunctions));
}

_MTL_INLINE NS::Array* MTL::LinkedFunctions::privateFunctions() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(privateFunctions));
}

_MTL_INLINE void MTL::LinkedFunctions::setBinaryFunctions(const NS::Array* binaryFunctions) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBinaryFunctions_), binaryFunctions);
}

_MTL_INLINE void MTL::LinkedFunctions::setFunctions(const NS::Array* functions) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFunctions_), functions);
}

_MTL_INLINE void MTL::LinkedFunctions::setGroups(const NS::Dictionary* groups) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setGroups_), groups);
}

_MTL_INLINE void MTL::LinkedFunctions::setPrivateFunctions(const NS::Array* privateFunctions) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setPrivateFunctions_), privateFunctions);
}
