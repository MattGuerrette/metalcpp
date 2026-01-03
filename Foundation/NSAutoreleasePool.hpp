//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Foundation/NSAutoreleasePool.hpp
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
    class AutoreleasePool : public Object
    {
    public:
        static AutoreleasePool* alloc();
        AutoreleasePool*        init();

        void drain() const;

        void addObject(Object* pObject) const;

        static void showPools();
    };
} // namespace NS

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::AutoreleasePool* NS::AutoreleasePool::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<AutoreleasePool>(_NS_PRIVATE_CLS(NSAutoreleasePool));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

// ReSharper disable once CppRedundantQualifier
_NS_INLINE NS::AutoreleasePool* NS::AutoreleasePool::init() { return NS::Object::init<AutoreleasePool>(); }

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE void NS::AutoreleasePool::drain() const { sendMessage<void>(this, _NS_PRIVATE_SEL(drain)); }

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE void NS::AutoreleasePool::addObject(Object* pObject) const
{
    sendMessage<void>(this, _NS_PRIVATE_SEL(addObject_), pObject);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE void NS::AutoreleasePool::showPools()
{
    sendMessage<void>(_NS_PRIVATE_CLS(NSAutoreleasePool), _NS_PRIVATE_SEL(showPools));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------
