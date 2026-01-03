//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLCaptureManager.hpp
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
    class CaptureDescriptor;
    class CaptureManager;
    class CaptureScope;
    class CommandQueue;
    class Device;
} // namespace MTL

namespace MTL4
{
    class CommandQueue;
}

namespace MTL
{
    _MTL_ENUM(NS::Integer, CaptureError){
        CaptureErrorNotSupported      = 1,
        CaptureErrorAlreadyCapturing  = 2,
        CaptureErrorInvalidDescriptor = 3,
    };

    _MTL_ENUM(NS::Integer, CaptureDestination){
        CaptureDestinationDeveloperTools   = 1,
        CaptureDestinationGPUTraceDocument = 2,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlcapturedescriptor?language=objc
    class CaptureDescriptor : public NS::Copying<CaptureDescriptor>
    {
    public:
        [[nodiscard]] static CaptureDescriptor* alloc();

        [[nodiscard]] Object* captureObject() const;

        [[nodiscard]] CaptureDestination destination() const;

        [[nodiscard]] CaptureDescriptor* init();

        [[nodiscard]] NS::URL* outputURL() const;

        void setCaptureObject(Object* captureObject) const;

        void setDestination(CaptureDestination destination) const;

        void setOutputURL(const NS::URL* outputURL) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlcapturemanager?language=objc
    class CaptureManager : public NS::Referencing<CaptureManager>
    {
    public:
        [[nodiscard]] static CaptureManager* alloc();

        [[nodiscard]] CaptureScope* defaultCaptureScope() const;

        [[nodiscard]] CaptureManager* init();

        [[nodiscard]] bool isCapturing() const;

        [[nodiscard]] CaptureScope* newCaptureScope(const Device* device) const;
        [[nodiscard]] CaptureScope* newCaptureScope(const CommandQueue* commandQueue) const;
        [[nodiscard]] CaptureScope* newCaptureScope(const MTL4::CommandQueue* commandQueue) const;

        void setDefaultCaptureScope(const CaptureScope* defaultCaptureScope) const;

        [[nodiscard]] static CaptureManager* sharedCaptureManager();

        [[nodiscard]] bool startCapture(const CaptureDescriptor* descriptor, NS::Error** error) const;
        void               startCapture(const Device* device) const;
        void               startCapture(const CommandQueue* commandQueue) const;
        void               startCapture(const CaptureScope* captureScope) const;

        void stopCapture() const;

        [[nodiscard]] bool supportsDestination(CaptureDestination destination) const;
    };

} // namespace MTL
_MTL_INLINE MTL::CaptureDescriptor* MTL::CaptureDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<CaptureDescriptor>(_MTL_PRIVATE_CLS(MTLCaptureDescriptor));
}

_MTL_INLINE NS::Object* MTL::CaptureDescriptor::captureObject() const
{
    return sendMessage<Object*>(this, _MTL_PRIVATE_SEL(captureObject));
}

_MTL_INLINE MTL::CaptureDestination MTL::CaptureDescriptor::destination() const
{
    return sendMessage<CaptureDestination>(this, _MTL_PRIVATE_SEL(destination));
}

_MTL_INLINE MTL::CaptureDescriptor* MTL::CaptureDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<CaptureDescriptor>();
}

_MTL_INLINE NS::URL* MTL::CaptureDescriptor::outputURL() const
{
    return sendMessage<NS::URL*>(this, _MTL_PRIVATE_SEL(outputURL));
}

_MTL_INLINE void MTL::CaptureDescriptor::setCaptureObject(Object* captureObject) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setCaptureObject_), captureObject);
}

_MTL_INLINE void MTL::CaptureDescriptor::setDestination(const CaptureDestination destination) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDestination_), destination);
}

_MTL_INLINE void MTL::CaptureDescriptor::setOutputURL(const NS::URL* outputURL) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setOutputURL_), outputURL);
}

_MTL_INLINE MTL::CaptureManager* MTL::CaptureManager::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<CaptureManager>(_MTL_PRIVATE_CLS(MTLCaptureManager));
}

_MTL_INLINE MTL::CaptureScope* MTL::CaptureManager::defaultCaptureScope() const
{
    return sendMessage<CaptureScope*>(this, _MTL_PRIVATE_SEL(defaultCaptureScope));
}

_MTL_INLINE MTL::CaptureManager* MTL::CaptureManager::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<CaptureManager>();
}

_MTL_INLINE bool MTL::CaptureManager::isCapturing() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isCapturing));
}

_MTL_INLINE MTL::CaptureScope* MTL::CaptureManager::newCaptureScope(const Device* device) const
{
    return sendMessage<CaptureScope*>(this, _MTL_PRIVATE_SEL(newCaptureScopeWithDevice_), device);
}

_MTL_INLINE MTL::CaptureScope* MTL::CaptureManager::newCaptureScope(const CommandQueue* commandQueue) const
{
    return sendMessage<CaptureScope*>(this, _MTL_PRIVATE_SEL(newCaptureScopeWithCommandQueue_), commandQueue);
}

_MTL_INLINE MTL::CaptureScope* MTL::CaptureManager::newCaptureScope(const MTL4::CommandQueue* commandQueue) const
{
    return sendMessage<CaptureScope*>(this, _MTL_PRIVATE_SEL(newCaptureScopeWithMTL4CommandQueue_), commandQueue);
}

_MTL_INLINE void MTL::CaptureManager::setDefaultCaptureScope(const CaptureScope* defaultCaptureScope) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDefaultCaptureScope_), defaultCaptureScope);
}

_MTL_INLINE MTL::CaptureManager* MTL::CaptureManager::sharedCaptureManager()
{
    return sendMessage<CaptureManager*>(_MTL_PRIVATE_CLS(MTLCaptureManager), _MTL_PRIVATE_SEL(sharedCaptureManager));
}

_MTL_INLINE bool MTL::CaptureManager::startCapture(const CaptureDescriptor* descriptor, NS::Error** error) const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(startCaptureWithDescriptor_error_), descriptor, error);
}

_MTL_INLINE void MTL::CaptureManager::startCapture(const Device* device) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(startCaptureWithDevice_), device);
}

_MTL_INLINE void MTL::CaptureManager::startCapture(const CommandQueue* commandQueue) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(startCaptureWithCommandQueue_), commandQueue);
}

_MTL_INLINE void MTL::CaptureManager::startCapture(const CaptureScope* captureScope) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(startCaptureWithScope_), captureScope);
}

_MTL_INLINE void MTL::CaptureManager::stopCapture() const { sendMessage<void>(this, _MTL_PRIVATE_SEL(stopCapture)); }

_MTL_INLINE bool MTL::CaptureManager::supportsDestination(const CaptureDestination destination) const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supportsDestination_), destination);
}
