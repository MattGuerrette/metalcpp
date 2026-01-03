//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLLogState.hpp
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
    class LogStateDescriptor;

    /// @see https://developer.apple.com/documentation/metal/mtlloglevel?language=objc
    _MTL_ENUM(NS::Integer, LogLevel){
        LogLevelUndefined = 0, LogLevelDebug = 1, LogLevelInfo = 2,
        LogLevelNotice = 3,    LogLevelError = 4, LogLevelFault = 5,
    };

    /// @see https://developer.apple.com/documentation/metal/mtllogstateerror?language=objc
    _MTL_ENUM(NS::UInteger, LogStateError){
        LogStateErrorInvalidSize = 1,
        LogStateErrorInvalid     = 2,
    };

    using LogHandlerFunction =
        std::function<void(NS::String* subsystem, NS::String* category, LogLevel logLevel, NS::String* message)>;

    _MTL_CONST(NS::ErrorDomain, LogStateErrorDomain);

    /// @see https://developer.apple.com/documentation/metal/mtllogstate?language=objc
    class LogState : public NS::Referencing<LogState>
    {
    public:
        void addLogHandler(void (^block)(NS::String*, NS::String*, LogLevel, NS::String*));
        void addLogHandler(const LogHandlerFunction& handler);
    };

    /// @see https://developer.apple.com/documentation/metal/mtllogstatedescriptor?language=objc
    class LogStateDescriptor : public NS::Copying<LogStateDescriptor>
    {
    public:
        [[nodiscard]] static LogStateDescriptor* alloc();

        [[nodiscard]] NS::Integer bufferSize() const;

        [[nodiscard]] LogStateDescriptor* init();

        [[nodiscard]] LogLevel level() const;

        void setBufferSize(NS::Integer bufferSize) const;

        void setLevel(LogLevel level) const;
    };

} // namespace MTL
_MTL_PRIVATE_DEF_CONST(NS::ErrorDomain, LogStateErrorDomain);
_MTL_INLINE void MTL::LogState::addLogHandler(void (^block)(NS::String*, NS::String*, LogLevel, NS::String*))
{
    Object::sendMessage<void>(this, _MTL_PRIVATE_SEL(addLogHandler_), block);
}

_MTL_INLINE void MTL::LogState::addLogHandler(const LogHandlerFunction& handler)
{
    __block LogHandlerFunction function = handler;
    addLogHandler(^void(NS::String* subsystem, NS::String* category, LogLevel logLevel, NS::String* message) {
      function(subsystem, category, logLevel, message);
    });
}

_MTL_INLINE MTL::LogStateDescriptor* MTL::LogStateDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<LogStateDescriptor>(_MTL_PRIVATE_CLS(MTLLogStateDescriptor));
}

_MTL_INLINE NS::Integer MTL::LogStateDescriptor::bufferSize() const
{
    return sendMessage<NS::Integer>(this, _MTL_PRIVATE_SEL(bufferSize));
}

_MTL_INLINE MTL::LogStateDescriptor* MTL::LogStateDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<LogStateDescriptor>();
}

_MTL_INLINE MTL::LogLevel MTL::LogStateDescriptor::level() const
{
    return sendMessage<LogLevel>(this, _MTL_PRIVATE_SEL(level));
}

_MTL_INLINE void MTL::LogStateDescriptor::setBufferSize(const NS::Integer bufferSize) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBufferSize_), bufferSize);
}

_MTL_INLINE void MTL::LogStateDescriptor::setLevel(const LogLevel level) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLevel_), level);
}
