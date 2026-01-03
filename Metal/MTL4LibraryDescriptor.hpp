//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTL4LibraryDescriptor.hpp
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
    class LibraryDescriptor;
}

namespace MTL
{
    class CompileOptions;
}

namespace MTL4
{
    /// @see https://developer.apple.com/documentation/metal/mtl4librarydescriptor
    class LibraryDescriptor : public NS::Copying<LibraryDescriptor>
    {
    public:
        [[nodiscard]] static LibraryDescriptor* alloc();

        [[nodiscard]] LibraryDescriptor* init();

        [[nodiscard]] NS::String* name() const;

        [[nodiscard]] MTL::CompileOptions* options() const;

        [[nodiscard]] NS::String* source() const;

        void setName(const NS::String* name) const;

        void setOptions(const MTL::CompileOptions* options) const;

        void setSource(const NS::String* source) const;
    };

} // namespace MTL4
_MTL_INLINE MTL4::LibraryDescriptor* MTL4::LibraryDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<LibraryDescriptor>(_MTL_PRIVATE_CLS(MTL4LibraryDescriptor));
}

_MTL_INLINE MTL4::LibraryDescriptor* MTL4::LibraryDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<LibraryDescriptor>();
}

_MTL_INLINE NS::String* MTL4::LibraryDescriptor::name() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(name));
}

_MTL_INLINE MTL::CompileOptions* MTL4::LibraryDescriptor::options() const
{
    return sendMessage<MTL::CompileOptions*>(this, _MTL_PRIVATE_SEL(options));
}

_MTL_INLINE void MTL4::LibraryDescriptor::setName(const NS::String* name) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setName_), name);
}

_MTL_INLINE void MTL4::LibraryDescriptor::setOptions(const MTL::CompileOptions* options) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setOptions_), options);
}

_MTL_INLINE void MTL4::LibraryDescriptor::setSource(const NS::String* source) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSource_), source);
}

_MTL_INLINE NS::String* MTL4::LibraryDescriptor::source() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(source));
}
