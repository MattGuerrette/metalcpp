//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLDynamicLibrary.hpp
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
    class Device;
    _MTL_ENUM(NS::UInteger, DynamicLibraryError){
        DynamicLibraryErrorNone                  = 0,
        DynamicLibraryErrorInvalidFile           = 1,
        DynamicLibraryErrorCompilationFailure    = 2,
        DynamicLibraryErrorUnresolvedInstallName = 3,
        DynamicLibraryErrorDependencyLoadFailure = 4,
        DynamicLibraryErrorUnsupported           = 5,
    };

    /// @see https://developer.apple.com/documentation/metal/mtldynamiclibrary?language=objc
    class DynamicLibrary : public NS::Referencing<DynamicLibrary>
    {
    public:
        [[nodiscard]] Device* device() const;

        [[nodiscard]] NS::String* installName() const;

        [[nodiscard]] NS::String* label() const;

        [[nodiscard]] bool serializeToURL(const NS::URL* url, NS::Error** error) const;

        void setLabel(const NS::String* label) const;
    };

} // namespace MTL
_MTL_INLINE MTL::Device* MTL::DynamicLibrary::device() const
{
    return sendMessage<Device*>(this, _MTL_PRIVATE_SEL(device));
}

_MTL_INLINE NS::String* MTL::DynamicLibrary::installName() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(installName));
}

_MTL_INLINE NS::String* MTL::DynamicLibrary::label() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
}

_MTL_INLINE bool MTL::DynamicLibrary::serializeToURL(const NS::URL* url, NS::Error** error) const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(serializeToURL_error_), url, error);
}

_MTL_INLINE void MTL::DynamicLibrary::setLabel(const NS::String* label) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLabel_), label);
}
