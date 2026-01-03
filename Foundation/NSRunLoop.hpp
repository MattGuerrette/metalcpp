//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Foundation/NSRunLoop.hpp
//
// Copyright 2020-2023 Apple Inc.
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

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

namespace NS
{
    using RunLoopMode = const String*;

    _NS_CONST(RunLoopMode, RunLoopCommonModes);
    _NS_CONST(RunLoopMode, DefaultRunLoopMode);
    //_NS_CONST(RunLoopMode, EventTrackingRunLoopMode);
    //_NS_CONST(RunLoopMode, ModalPanelRunLoopMode);


    class RunLoop : public Referencing<RunLoop>
    {
    public:
        static RunLoop* currentRunLoop();
        static RunLoop* mainRunLoop();

        bool run(RunLoopMode mode, Date* date) const;
    };
} // namespace NS

_NS_PRIVATE_DEF_CONST(NS::RunLoopMode, RunLoopCommonModes);
_NS_PRIVATE_DEF_CONST(NS::RunLoopMode, DefaultRunLoopMode);
//_NS_PRIVATE_DEF_CONST(NS::RunLoopMode, EventTrackingRunLoopMode);
//_NS_PRIVATE_DEF_CONST(NS::RunLoopMode, ModalPanelRunLoopMode);

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::RunLoop* NS::RunLoop::currentRunLoop()
{
    return sendMessage<RunLoop*>(_NS_PRIVATE_CLS(NSRunLoop), _NS_PRIVATE_SEL(currentRunLoop));
}

_NS_INLINE NS::RunLoop* NS::RunLoop::mainRunLoop()
{
    return sendMessage<RunLoop*>(_NS_PRIVATE_CLS(NSRunLoop), _NS_PRIVATE_SEL(mainRunLoop));
}

_NS_INLINE bool NS::RunLoop::run(const RunLoopMode mode, Date* date) const
{
    return sendMessage<bool>(this, _NS_PRIVATE_SEL(runMode_beforeDate_), mode, date);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------
