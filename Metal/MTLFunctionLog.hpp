//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLFunctionLog.hpp
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
    class Function;
    class FunctionLogDebugLocation;

    /// @see https://developer.apple.com/documentation/metal/mtlfunctionlogtype?language=objc
    _MTL_ENUM(NS::UInteger, FunctionLogType){
        FunctionLogTypeValidation = 0,
    };

    /// @see https://developer.apple.com/documentation/metal/mtllogcontainer?language=objc
    class LogContainer : public NS::Referencing<LogContainer, NS::FastEnumeration>
    {
    };

    /// @see https://developer.apple.com/documentation/metal/mtlfunctionlogdebuglocation?language=objc
    class FunctionLogDebugLocation : public NS::Referencing<FunctionLogDebugLocation>
    {
    public:
        [[nodiscard]] NS::URL* URL() const;

        [[nodiscard]] NS::UInteger column() const;

        [[nodiscard]] NS::String* functionName() const;

        [[nodiscard]] NS::UInteger line() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlfunctionlog?language=objc
    class FunctionLog : public NS::Referencing<FunctionLog>
    {
    public:
        [[nodiscard]] FunctionLogDebugLocation* debugLocation() const;

        [[nodiscard]] NS::String* encoderLabel() const;

        [[nodiscard]] Function* function() const;

        [[nodiscard]] FunctionLogType type() const;
    };

} // namespace MTL
_MTL_INLINE NS::URL* MTL::FunctionLogDebugLocation::URL() const
{
    return sendMessage<NS::URL*>(this, _MTL_PRIVATE_SEL(URL));
}

_MTL_INLINE NS::UInteger MTL::FunctionLogDebugLocation::column() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(column));
}

_MTL_INLINE NS::String* MTL::FunctionLogDebugLocation::functionName() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(functionName));
}

_MTL_INLINE NS::UInteger MTL::FunctionLogDebugLocation::line() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(line));
}

_MTL_INLINE MTL::FunctionLogDebugLocation* MTL::FunctionLog::debugLocation() const
{
    return sendMessage<FunctionLogDebugLocation*>(this, _MTL_PRIVATE_SEL(debugLocation));
}

_MTL_INLINE NS::String* MTL::FunctionLog::encoderLabel() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(encoderLabel));
}

_MTL_INLINE MTL::Function* MTL::FunctionLog::function() const
{
    return sendMessage<Function*>(this, _MTL_PRIVATE_SEL(function));
}

_MTL_INLINE MTL::FunctionLogType MTL::FunctionLog::type() const
{
    return sendMessage<FunctionLogType>(this, _MTL_PRIVATE_SEL(type));
}
