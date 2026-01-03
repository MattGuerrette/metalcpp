//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Foundation/NSSet.hpp
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

/*****Immutable Set*******/

namespace NS
{
    class Set : public Copying<Set>
    {
    public:
        [[nodiscard]] UInteger            count() const;
        [[nodiscard]] Enumerator<Object>* objectEnumerator() const;

        static Set* alloc();

        Set* init();
        Set* init(const Object* const* pObjects, UInteger count) const;
        Set* init(const Coder* pCoder) const;
    };
} // namespace NS

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::UInteger NS::Set::count() const { return sendMessage<UInteger>(this, _NS_PRIVATE_SEL(count)); }

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Enumerator<NS::Object>* NS::Set::objectEnumerator() const
{
    return sendMessage<Enumerator<Object>*>(this, _NS_PRIVATE_SEL(objectEnumerator));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Set* NS::Set::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<Set>(_NS_PRIVATE_CLS(NSSet));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Set* NS::Set::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<Set>();
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Set* NS::Set::init(const Object* const* pObjects, const UInteger count) const
{
    return sendMessage<Set*>(this, _NS_PRIVATE_SEL(initWithObjects_count_), pObjects, count);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Set* NS::Set::init(const Coder* pCoder) const
{
    return sendMessage<Set*>(this, _NS_PRIVATE_SEL(initWithCoder_), pCoder);
}
