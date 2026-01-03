//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Foundation/NSLock.hpp
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

#include "NSDate.hpp"
#include "NSDefines.hpp"
#include "NSObject.hpp"
#include "NSPrivate.hpp"

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

namespace NS
{

    template<typename, class _Base = Object> // NOLINT(*-reserved-identifier)
    class Locking : public _Base
    {
    public:
        void lock();
        void unlock();
    };

    class Condition : public Locking<Condition>
    {
    public:
        static Condition* alloc();

        Condition* init();

        void wait() const;
        bool waitUntilDate(Date* pLimit) const;
        void signal() const;
        void broadcast() const;
    };

} // namespace NS

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

// NOLINTNEXTLINE(*-reserved-identifier)
template<typename _Class, class _Base /* = NS::Object */>
_NS_INLINE void NS::Locking<_Class, _Base>::lock()
{
    Object::sendMessage<void>(this, _NS_PRIVATE_SEL(lock));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

// NOLINTNEXTLINE(*-reserved-identifier)
template<typename _Class, class _Base /* = NS::Object */>
_NS_INLINE void NS::Locking<_Class, _Base>::unlock()
{
    Object::sendMessage<void>(this, _NS_PRIVATE_SEL(unlock));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Condition* NS::Condition::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<Condition>(_NS_PRIVATE_CLS(NSCondition));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Condition* NS::Condition::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<Condition>();
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE void NS::Condition::wait() const { sendMessage<void>(this, _NS_PRIVATE_SEL(wait)); }

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE bool NS::Condition::waitUntilDate(Date* pLimit) const
{
    return sendMessage<bool>(this, _NS_PRIVATE_SEL(waitUntilDate_), pLimit);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE void NS::Condition::signal() const { sendMessage<void>(this, _NS_PRIVATE_SEL(signal)); }

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE void NS::Condition::broadcast() const { sendMessage<void>(this, _NS_PRIVATE_SEL(broadcast)); }

//-------------------------------------------------------------------------------------------------------------------------------------------------------------
