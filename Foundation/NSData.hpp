//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Foundation/NSData.hpp
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

#include "NSObject.hpp"
#include "NSTypes.hpp"

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

namespace NS
{
    class Data : public Copying<Data>
    {
    public:
        [[nodiscard]] static Data* data(String* path);
        [[nodiscard]] static Data* data(URL* url);
        [[nodiscard]] static Data* data(const void* bytes, UInteger length);

        [[nodiscard]] const void* bytes() const;
        [[nodiscard]] void*       mutableBytes() const;
        [[nodiscard]] UInteger    length() const;
    };
} // namespace NS

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Data* NS::Data::data(URL* url)
{
    return sendMessage<Data*>(_NS_PRIVATE_CLS(NSData), _NS_PRIVATE_SEL(dataWithContentsOfURL_), url);
}

_NS_INLINE NS::Data* NS::Data::data(String* path)
{
    return sendMessage<Data*>(_NS_PRIVATE_CLS(NSData), _NS_PRIVATE_SEL(dataWithContentsOfFile_), path);
}

_NS_INLINE NS::Data* NS::Data::data(const void* bytes, const UInteger length)
{
    return sendMessage<Data*>(_NS_PRIVATE_CLS(NSData), _NS_PRIVATE_SEL(dataWithBytes_length_), bytes, length);
}

_NS_INLINE void* NS::Data::mutableBytes() const { return sendMessage<void*>(this, _NS_PRIVATE_SEL(mutableBytes)); }

_NS_INLINE const void* NS::Data::bytes() const { return sendMessage<const void*>(this, _NS_PRIVATE_SEL(bytes)); }

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::UInteger NS::Data::length() const { return sendMessage<UInteger>(this, _NS_PRIVATE_SEL(length)); }

//-------------------------------------------------------------------------------------------------------------------------------------------------------------
