//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTL4ArgumentTable.hpp
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
#include "MTLGPUAddress.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"
#include "MTLTypes.hpp"

namespace MTL
{
    class Device;
}

namespace MTL4
{
    class ArgumentTableDescriptor : public NS::Copying<ArgumentTableDescriptor>
    {
    public:
        [[nodiscard]] static ArgumentTableDescriptor* alloc();

        [[nodiscard]] ArgumentTableDescriptor* init();
        [[nodiscard]] bool                     initializeBindings() const;

        [[nodiscard]] NS::String* label() const;

        [[nodiscard]] NS::UInteger maxBufferBindCount() const;

        [[nodiscard]] NS::UInteger maxSamplerStateBindCount() const;

        [[nodiscard]] NS::UInteger maxTextureBindCount() const;

        [[nodiscard]] bool supportAttributeStrides() const;

        void setInitializeBindings(bool initializeBindings) const;

        void setLabel(const NS::String* label) const;

        void setMaxBufferBindCount(NS::UInteger maxBufferBindCount) const;

        void setMaxSamplerStateBindCount(NS::UInteger maxSamplerStateBindCount) const;

        void setMaxTextureBindCount(NS::UInteger maxTextureBindCount) const;

        void setSupportAttributeStrides(bool supportAttributeStrides) const;
    };
    class ArgumentTable : public NS::Referencing<ArgumentTable>
    {
    public:
        [[nodiscard]] MTL::Device* device() const;

        [[nodiscard]] NS::String* label() const;

        void setAddress(MTL::GPUAddress gpuAddress, NS::UInteger bindingIndex) const;
        void setAddress(MTL::GPUAddress gpuAddress, NS::UInteger stride, NS::UInteger bindingIndex) const;

        void setResource(MTL::ResourceID resourceID, NS::UInteger bindingIndex) const;

        void setSamplerState(MTL::ResourceID resourceID, NS::UInteger bindingIndex) const;

        void setTexture(MTL::ResourceID resourceID, NS::UInteger bindingIndex) const;
    };

} // namespace MTL4
_MTL_INLINE MTL4::ArgumentTableDescriptor* MTL4::ArgumentTableDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<ArgumentTableDescriptor>(_MTL_PRIVATE_CLS(MTL4ArgumentTableDescriptor));
}

_MTL_INLINE MTL4::ArgumentTableDescriptor* MTL4::ArgumentTableDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<ArgumentTableDescriptor>();
}

_MTL_INLINE bool MTL4::ArgumentTableDescriptor::initializeBindings() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(initializeBindings));
}

_MTL_INLINE NS::String* MTL4::ArgumentTableDescriptor::label() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
}

_MTL_INLINE NS::UInteger MTL4::ArgumentTableDescriptor::maxBufferBindCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxBufferBindCount));
}

_MTL_INLINE NS::UInteger MTL4::ArgumentTableDescriptor::maxSamplerStateBindCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxSamplerStateBindCount));
}

_MTL_INLINE NS::UInteger MTL4::ArgumentTableDescriptor::maxTextureBindCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxTextureBindCount));
}

_MTL_INLINE void MTL4::ArgumentTableDescriptor::setInitializeBindings(const bool initializeBindings) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setInitializeBindings_), initializeBindings);
}

_MTL_INLINE void MTL4::ArgumentTableDescriptor::setLabel(const NS::String* label) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLabel_), label);
}

_MTL_INLINE void MTL4::ArgumentTableDescriptor::setMaxBufferBindCount(const NS::UInteger maxBufferBindCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxBufferBindCount_), maxBufferBindCount);
}

_MTL_INLINE void MTL4::ArgumentTableDescriptor::setMaxSamplerStateBindCount(
    const NS::UInteger maxSamplerStateBindCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxSamplerStateBindCount_), maxSamplerStateBindCount);
}

_MTL_INLINE void MTL4::ArgumentTableDescriptor::setMaxTextureBindCount(const NS::UInteger maxTextureBindCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxTextureBindCount_), maxTextureBindCount);
}

_MTL_INLINE void MTL4::ArgumentTableDescriptor::setSupportAttributeStrides(const bool supportAttributeStrides) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSupportAttributeStrides_), supportAttributeStrides);
}

_MTL_INLINE bool MTL4::ArgumentTableDescriptor::supportAttributeStrides() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supportAttributeStrides));
}

_MTL_INLINE MTL::Device* MTL4::ArgumentTable::device() const
{
    return sendMessage<MTL::Device*>(this, _MTL_PRIVATE_SEL(device));
}

_MTL_INLINE NS::String* MTL4::ArgumentTable::label() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
}

_MTL_INLINE void MTL4::ArgumentTable::setAddress(const MTL::GPUAddress gpuAddress,
                                                 const NS::UInteger    bindingIndex) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setAddress_atIndex_), gpuAddress, bindingIndex);
}

_MTL_INLINE void MTL4::ArgumentTable::setAddress(const MTL::GPUAddress gpuAddress,
                                                 const NS::UInteger    stride,
                                                 const NS::UInteger    bindingIndex) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setAddress_attributeStride_atIndex_), gpuAddress, stride, bindingIndex);
}

_MTL_INLINE void MTL4::ArgumentTable::setResource(const MTL::ResourceID resourceID,
                                                  const NS::UInteger    bindingIndex) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setResource_atBufferIndex_), resourceID, bindingIndex);
}

_MTL_INLINE void MTL4::ArgumentTable::setSamplerState(const MTL::ResourceID resourceID,
                                                      const NS::UInteger    bindingIndex) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSamplerState_atIndex_), resourceID, bindingIndex);
}

_MTL_INLINE void MTL4::ArgumentTable::setTexture(const MTL::ResourceID resourceID,
                                                 const NS::UInteger    bindingIndex) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTexture_atIndex_), resourceID, bindingIndex);
}
