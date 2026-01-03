//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Foundation/NSArray.hpp
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

#include "NSEnumerator.hpp"
#include "NSObject.hpp"
#include "NSTypes.hpp"

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

namespace NS
{
    class Array : public Copying<Array>
    {
    public:
        static Array* array();
        static Array* array(const Object* pObject);
        static Array* array(const Object* const* pObjects, UInteger count);

        static Array* alloc();

        Array* init();
        Array* init(const Object* const* pObjects, UInteger count) const;
        Array* init(const class Coder* pCoder) const;

        template<class _Object = Object> // NOLINT(*-reserved-identifier)
        _Object* object(UInteger index) const;

        [[nodiscard]] UInteger            count() const;
        [[nodiscard]] Enumerator<Object>* objectEnumerator() const;
    };
} // namespace NS

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Array* NS::Array::array()
{
    return sendMessage<Array*>(_NS_PRIVATE_CLS(NSArray), _NS_PRIVATE_SEL(array));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Array* NS::Array::array(const Object* pObject)
{
    return sendMessage<Array*>(_NS_PRIVATE_CLS(NSArray), _NS_PRIVATE_SEL(arrayWithObject_), pObject);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Array* NS::Array::array(const Object* const* pObjects, const UInteger count)
{
    return sendMessage<Array*>(_NS_PRIVATE_CLS(NSArray), _NS_PRIVATE_SEL(arrayWithObjects_count_), pObjects, count);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

// ReSharper disable once CppRedundantQualifier
_NS_INLINE NS::Array* NS::Array::alloc() { return Object::alloc<Array>(_NS_PRIVATE_CLS(NSArray)); }

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

// ReSharper disable once CppRedundantQualifier
_NS_INLINE NS::Array* NS::Array::init() { return Object::init<Array>(); }

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Array* NS::Array::init(const Object* const* pObjects, const UInteger count) const
{
    return sendMessage<Array*>(this, _NS_PRIVATE_SEL(initWithObjects_count_), pObjects, count);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Array* NS::Array::init(const Coder* pCoder) const
{
    return sendMessage<Array*>(this, _NS_PRIVATE_SEL(initWithCoder_), pCoder);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::UInteger NS::Array::count() const { return sendMessage<UInteger>(this, _NS_PRIVATE_SEL(count)); }

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

template<typename _Object> // NOLINT(*-reserved-identifier)
_NS_INLINE _Object* NS::Array::object(const UInteger index) const
{
    return Object::sendMessage<_Object*>(this, _NS_PRIVATE_SEL(objectAtIndex_), index);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Enumerator<NS::Object>* NS::Array::objectEnumerator() const
{
    return sendMessage<Enumerator<Object>*>(this, _NS_PRIVATE_SEL(objectEnumerator));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------
