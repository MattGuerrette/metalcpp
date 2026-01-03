//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLDepthStencil.hpp
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

#include <cstdint>
#include "../Foundation/Foundation.hpp"
#include "MTLDefines.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"
#include "MTLTypes.hpp"

namespace MTL
{
    class DepthStencilDescriptor;
    class Device;
    class StencilDescriptor;
    _MTL_ENUM(NS::UInteger, CompareFunction){
        CompareFunctionNever = 0,        CompareFunctionLess = 1,    CompareFunctionEqual = 2,
        CompareFunctionLessEqual = 3,    CompareFunctionGreater = 4, CompareFunctionNotEqual = 5,
        CompareFunctionGreaterEqual = 6, CompareFunctionAlways = 7,
    };

    _MTL_ENUM(NS::UInteger, StencilOperation){
        StencilOperationKeep = 0,           StencilOperationZero = 1,           StencilOperationReplace = 2,
        StencilOperationIncrementClamp = 3, StencilOperationDecrementClamp = 4, StencilOperationInvert = 5,
        StencilOperationIncrementWrap = 6,  StencilOperationDecrementWrap = 7,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlstencildescriptor?language=objc
    class StencilDescriptor : public NS::Copying<StencilDescriptor>
    {
    public:
        [[nodiscard]] static StencilDescriptor* alloc();

        [[nodiscard]] StencilOperation depthFailureOperation() const;

        [[nodiscard]] StencilOperation depthStencilPassOperation() const;

        [[nodiscard]] StencilDescriptor* init();

        [[nodiscard]] uint32_t readMask() const;

        void setDepthFailureOperation(StencilOperation depthFailureOperation) const;

        void setDepthStencilPassOperation(StencilOperation depthStencilPassOperation) const;

        void setReadMask(uint32_t readMask) const;

        void setStencilCompareFunction(CompareFunction stencilCompareFunction) const;

        void setStencilFailureOperation(StencilOperation stencilFailureOperation) const;

        void setWriteMask(uint32_t writeMask) const;

        [[nodiscard]] CompareFunction stencilCompareFunction() const;

        [[nodiscard]] StencilOperation stencilFailureOperation() const;

        [[nodiscard]] uint32_t writeMask() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtldepthstencildescriptor?language=objc
    class DepthStencilDescriptor : public NS::Copying<DepthStencilDescriptor>
    {
    public:
        [[nodiscard]] static DepthStencilDescriptor* alloc();

        [[nodiscard]] StencilDescriptor* backFaceStencil() const;

        [[nodiscard]] CompareFunction depthCompareFunction() const;

        [[deprecated("please use isDepthWriteEnabled instead")]] [[nodiscard]] bool depthWriteEnabled() const;

        [[nodiscard]] StencilDescriptor* frontFaceStencil() const;

        [[nodiscard]] DepthStencilDescriptor* init();

        [[nodiscard]] bool isDepthWriteEnabled() const;

        [[nodiscard]] NS::String* label() const;

        void setBackFaceStencil(const StencilDescriptor* backFaceStencil) const;

        void setDepthCompareFunction(CompareFunction depthCompareFunction) const;

        void setDepthWriteEnabled(bool depthWriteEnabled) const;

        void setFrontFaceStencil(const StencilDescriptor* frontFaceStencil) const;

        void setLabel(const NS::String* label) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtldepthstencilstate?language=objc
    class DepthStencilState : public NS::Referencing<DepthStencilState>
    {
    public:
        [[nodiscard]] Device* device() const;

        [[nodiscard]] ResourceID gpuResourceID() const;

        [[nodiscard]] NS::String* label() const;
    };

} // namespace MTL
_MTL_INLINE MTL::StencilDescriptor* MTL::StencilDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<StencilDescriptor>(_MTL_PRIVATE_CLS(MTLStencilDescriptor));
}

_MTL_INLINE MTL::StencilOperation MTL::StencilDescriptor::depthFailureOperation() const
{
    return sendMessage<StencilOperation>(this, _MTL_PRIVATE_SEL(depthFailureOperation));
}

_MTL_INLINE MTL::StencilOperation MTL::StencilDescriptor::depthStencilPassOperation() const
{
    return sendMessage<StencilOperation>(this, _MTL_PRIVATE_SEL(depthStencilPassOperation));
}

_MTL_INLINE MTL::StencilDescriptor* MTL::StencilDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<StencilDescriptor>();
}

_MTL_INLINE uint32_t MTL::StencilDescriptor::readMask() const
{
    return sendMessage<uint32_t>(this, _MTL_PRIVATE_SEL(readMask));
}

_MTL_INLINE void MTL::StencilDescriptor::setDepthFailureOperation(const StencilOperation depthFailureOperation) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDepthFailureOperation_), depthFailureOperation);
}

_MTL_INLINE void MTL::StencilDescriptor::setDepthStencilPassOperation(
    const StencilOperation depthStencilPassOperation) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDepthStencilPassOperation_), depthStencilPassOperation);
}

_MTL_INLINE void MTL::StencilDescriptor::setReadMask(const uint32_t readMask) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setReadMask_), readMask);
}

_MTL_INLINE void MTL::StencilDescriptor::setStencilCompareFunction(const CompareFunction stencilCompareFunction) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setStencilCompareFunction_), stencilCompareFunction);
}

_MTL_INLINE void MTL::StencilDescriptor::setStencilFailureOperation(
    const StencilOperation stencilFailureOperation) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setStencilFailureOperation_), stencilFailureOperation);
}

_MTL_INLINE void MTL::StencilDescriptor::setWriteMask(const uint32_t writeMask) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setWriteMask_), writeMask);
}

_MTL_INLINE MTL::CompareFunction MTL::StencilDescriptor::stencilCompareFunction() const
{
    return sendMessage<CompareFunction>(this, _MTL_PRIVATE_SEL(stencilCompareFunction));
}

_MTL_INLINE MTL::StencilOperation MTL::StencilDescriptor::stencilFailureOperation() const
{
    return sendMessage<StencilOperation>(this, _MTL_PRIVATE_SEL(stencilFailureOperation));
}

_MTL_INLINE uint32_t MTL::StencilDescriptor::writeMask() const
{
    return sendMessage<uint32_t>(this, _MTL_PRIVATE_SEL(writeMask));
}

_MTL_INLINE MTL::DepthStencilDescriptor* MTL::DepthStencilDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<DepthStencilDescriptor>(_MTL_PRIVATE_CLS(MTLDepthStencilDescriptor));
}

_MTL_INLINE MTL::StencilDescriptor* MTL::DepthStencilDescriptor::backFaceStencil() const
{
    return sendMessage<StencilDescriptor*>(this, _MTL_PRIVATE_SEL(backFaceStencil));
}

_MTL_INLINE MTL::CompareFunction MTL::DepthStencilDescriptor::depthCompareFunction() const
{
    return sendMessage<CompareFunction>(this, _MTL_PRIVATE_SEL(depthCompareFunction));
}

_MTL_INLINE bool MTL::DepthStencilDescriptor::depthWriteEnabled() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isDepthWriteEnabled));
}

_MTL_INLINE MTL::StencilDescriptor* MTL::DepthStencilDescriptor::frontFaceStencil() const
{
    return sendMessage<StencilDescriptor*>(this, _MTL_PRIVATE_SEL(frontFaceStencil));
}

_MTL_INLINE MTL::DepthStencilDescriptor* MTL::DepthStencilDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<DepthStencilDescriptor>();
}

_MTL_INLINE bool MTL::DepthStencilDescriptor::isDepthWriteEnabled() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isDepthWriteEnabled));
}

_MTL_INLINE NS::String* MTL::DepthStencilDescriptor::label() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
}

_MTL_INLINE void MTL::DepthStencilDescriptor::setBackFaceStencil(const StencilDescriptor* backFaceStencil) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBackFaceStencil_), backFaceStencil);
}

_MTL_INLINE void MTL::DepthStencilDescriptor::setDepthCompareFunction(const CompareFunction depthCompareFunction) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDepthCompareFunction_), depthCompareFunction);
}

_MTL_INLINE void MTL::DepthStencilDescriptor::setDepthWriteEnabled(const bool depthWriteEnabled) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDepthWriteEnabled_), depthWriteEnabled);
}

_MTL_INLINE void MTL::DepthStencilDescriptor::setFrontFaceStencil(const StencilDescriptor* frontFaceStencil) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFrontFaceStencil_), frontFaceStencil);
}

_MTL_INLINE void MTL::DepthStencilDescriptor::setLabel(const NS::String* label) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLabel_), label);
}

_MTL_INLINE MTL::Device* MTL::DepthStencilState::device() const
{
    return sendMessage<Device*>(this, _MTL_PRIVATE_SEL(device));
}

_MTL_INLINE MTL::ResourceID MTL::DepthStencilState::gpuResourceID() const
{
    return sendMessage<ResourceID>(this, _MTL_PRIVATE_SEL(gpuResourceID));
}

_MTL_INLINE NS::String* MTL::DepthStencilState::label() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
}
