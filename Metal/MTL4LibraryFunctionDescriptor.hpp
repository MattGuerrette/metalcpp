//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTL4LibraryFunctionDescriptor.hpp
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
    class LibraryFunctionDescriptor;
}

namespace MTL
{
    class Library;
}

namespace MTL4
{
    /// @see https://developer.apple.com/documentation/metal/mtl4libraryfunctiondescriptor
    class LibraryFunctionDescriptor : public NS::Copying<LibraryFunctionDescriptor, FunctionDescriptor>
    {
    public:
        [[nodiscard]] static LibraryFunctionDescriptor* alloc();

        [[nodiscard]] LibraryFunctionDescriptor* init();

        [[nodiscard]] MTL::Library* library() const;

        [[nodiscard]] NS::String* name() const;

        void setLibrary(const MTL::Library* library) const;

        void setName(const NS::String* name) const;
    };

} // namespace MTL4
_MTL_INLINE MTL4::LibraryFunctionDescriptor* MTL4::LibraryFunctionDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<LibraryFunctionDescriptor>(_MTL_PRIVATE_CLS(MTL4LibraryFunctionDescriptor));
}

_MTL_INLINE MTL4::LibraryFunctionDescriptor* MTL4::LibraryFunctionDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<LibraryFunctionDescriptor>();
}

_MTL_INLINE MTL::Library* MTL4::LibraryFunctionDescriptor::library() const
{
    return sendMessage<MTL::Library*>(this, _MTL_PRIVATE_SEL(library));
}

_MTL_INLINE NS::String* MTL4::LibraryFunctionDescriptor::name() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(name));
}

_MTL_INLINE void MTL4::LibraryFunctionDescriptor::setLibrary(const MTL::Library* library) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLibrary_), library);
}

_MTL_INLINE void MTL4::LibraryFunctionDescriptor::setName(const NS::String* name) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setName_), name);
}
