//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Foundation/NSURL.hpp
//
// Copyright 2020-2024 Apple Inc.
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

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#include "NSDefines.hpp"
#include "NSObject.hpp"
#include "NSPrivate.hpp"

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

namespace NS
{
    class URL : public Copying<URL>
    {
    public:
        [[nodiscard]] static URL* fileURLWithPath(const String* pPath);

        [[nodiscard]] static URL* alloc();
        [[nodiscard]] URL*        init();
        [[nodiscard]] URL*        init(const String* pString) const;
        [[nodiscard]] URL*        initFileURLWithPath(const String* pPath) const;

        [[nodiscard]] const char* fileSystemRepresentation() const;
    };
} // namespace NS

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::URL* NS::URL::fileURLWithPath(const String* pPath)
{
    return sendMessage<URL*>(_NS_PRIVATE_CLS(NSURL), _NS_PRIVATE_SEL(fileURLWithPath_), pPath);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::URL* NS::URL::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return Object::alloc<URL>(_NS_PRIVATE_CLS(NSURL));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::URL* NS::URL::init()
{
    // ReSharper disable once CppRedundantQualifier
    return Object::init<URL>();
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::URL* NS::URL::init(const String* pString) const
{
    return sendMessage<URL*>(this, _NS_PRIVATE_SEL(initWithString_), pString);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::URL* NS::URL::initFileURLWithPath(const String* pPath) const
{
    return sendMessage<URL*>(this, _NS_PRIVATE_SEL(initFileURLWithPath_), pPath);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE const char* NS::URL::fileSystemRepresentation() const
{
    return sendMessage<const char*>(this, _NS_PRIVATE_SEL(fileSystemRepresentation));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------
