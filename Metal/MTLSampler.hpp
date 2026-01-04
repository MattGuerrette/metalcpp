//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLSampler.hpp
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
#include "MTLDepthStencil.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"
#include "MTLTypes.hpp"

namespace MTL
{
    class Device;
    class SamplerDescriptor;

    /// @see https://developer.apple.com/documentation/metal/mtlsamplerminmagfilter?language=objc
    _MTL_ENUM(NS::UInteger, SamplerMinMagFilter){
        SamplerMinMagFilterNearest = 0,
        SamplerMinMagFilterLinear  = 1,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlsamplermipfilter?language=objc
    _MTL_ENUM(NS::UInteger, SamplerMipFilter){
        SamplerMipFilterNotMipmapped = 0,
        SamplerMipFilterNearest      = 1,
        SamplerMipFilterLinear       = 2,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlsampleraddressmode?language=objc
    _MTL_ENUM(NS::UInteger, SamplerAddressMode){
        SamplerAddressModeClampToEdge = 0, SamplerAddressModeMirrorClampToEdge = 1,
        SamplerAddressModeRepeat = 2,      SamplerAddressModeMirrorRepeat = 3,
        SamplerAddressModeClampToZero = 4, SamplerAddressModeClampToBorderColor = 5,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlsamplerbordercolor?language=objc
    _MTL_ENUM(NS::UInteger, SamplerBorderColor){
        SamplerBorderColorTransparentBlack = 0,
        SamplerBorderColorOpaqueBlack      = 1,
        SamplerBorderColorOpaqueWhite      = 2,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlsamplerreductionmode?language=objc
    _MTL_ENUM(NS::UInteger, SamplerReductionMode){
        SamplerReductionModeWeightedAverage = 0,
        SamplerReductionModeMinimum         = 1,
        SamplerReductionModeMaximum         = 2,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlsamplerdescriptor?language=objc
    class SamplerDescriptor : public NS::Copying<SamplerDescriptor>
    {
    public:
        [[nodiscard]] static SamplerDescriptor* alloc();

        [[nodiscard]] SamplerBorderColor borderColor() const;

        [[nodiscard]] CompareFunction compareFunction() const;

        [[nodiscard]] SamplerDescriptor* init();

        [[nodiscard]] NS::String* label() const;

        [[nodiscard]] bool lodAverage() const;

        [[nodiscard]] float lodBias() const;

        [[nodiscard]] float lodMaxClamp() const;

        [[nodiscard]] float lodMinClamp() const;

        [[nodiscard]] SamplerMinMagFilter magFilter() const;

        [[nodiscard]] NS::UInteger maxAnisotropy() const;

        [[nodiscard]] SamplerMinMagFilter minFilter() const;

        [[nodiscard]] SamplerMipFilter mipFilter() const;

        [[nodiscard]] bool normalizedCoordinates() const;

        [[nodiscard]] SamplerAddressMode rAddressMode() const;

        [[nodiscard]] SamplerReductionMode reductionMode() const;

        [[nodiscard]] SamplerAddressMode sAddressMode() const;

        void setBorderColor(SamplerBorderColor borderColor) const;

        void setCompareFunction(CompareFunction compareFunction) const;

        void setLabel(const NS::String* label) const;

        void setLodAverage(bool lodAverage) const;

        void setLodBias(float lodBias) const;

        void setLodMaxClamp(float lodMaxClamp) const;

        void setLodMinClamp(float lodMinClamp) const;

        void setMagFilter(SamplerMinMagFilter magFilter) const;

        void setMaxAnisotropy(NS::UInteger maxAnisotropy) const;

        void setMinFilter(SamplerMinMagFilter minFilter) const;

        void setMipFilter(SamplerMipFilter mipFilter) const;

        void setNormalizedCoordinates(bool normalizedCoordinates) const;

        void setRAddressMode(SamplerAddressMode rAddressMode) const;

        void setReductionMode(SamplerReductionMode reductionMode) const;

        void setSAddressMode(SamplerAddressMode sAddressMode) const;

        void setSupportArgumentBuffers(bool supportArgumentBuffers) const;

        void setTAddressMode(SamplerAddressMode tAddressMode) const;

        [[nodiscard]] bool supportArgumentBuffers() const;

        [[nodiscard]] SamplerAddressMode tAddressMode() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlsamplerstate?language=objc
    class SamplerState : public NS::Referencing<SamplerState>
    {
    public:
        [[nodiscard]] Device* device() const;

        [[nodiscard]] ResourceID gpuResourceID() const;

        [[nodiscard]] NS::String* label() const;
    };

} // namespace MTL
_MTL_INLINE MTL::SamplerDescriptor* MTL::SamplerDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<SamplerDescriptor>(_MTL_PRIVATE_CLS(MTLSamplerDescriptor));
}

_MTL_INLINE MTL::SamplerBorderColor MTL::SamplerDescriptor::borderColor() const
{
    return sendMessage<SamplerBorderColor>(this, _MTL_PRIVATE_SEL(borderColor));
}

_MTL_INLINE MTL::CompareFunction MTL::SamplerDescriptor::compareFunction() const
{
    return sendMessage<CompareFunction>(this, _MTL_PRIVATE_SEL(compareFunction));
}

_MTL_INLINE MTL::SamplerDescriptor* MTL::SamplerDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<SamplerDescriptor>();
}

_MTL_INLINE NS::String* MTL::SamplerDescriptor::label() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
}

_MTL_INLINE bool MTL::SamplerDescriptor::lodAverage() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(lodAverage));
}

_MTL_INLINE float MTL::SamplerDescriptor::lodBias() const
{
    return sendMessage<float>(this, _MTL_PRIVATE_SEL(lodBias));
}

_MTL_INLINE float MTL::SamplerDescriptor::lodMaxClamp() const
{
    return sendMessage<float>(this, _MTL_PRIVATE_SEL(lodMaxClamp));
}

_MTL_INLINE float MTL::SamplerDescriptor::lodMinClamp() const
{
    return sendMessage<float>(this, _MTL_PRIVATE_SEL(lodMinClamp));
}

_MTL_INLINE MTL::SamplerMinMagFilter MTL::SamplerDescriptor::magFilter() const
{
    return sendMessage<SamplerMinMagFilter>(this, _MTL_PRIVATE_SEL(magFilter));
}

_MTL_INLINE NS::UInteger MTL::SamplerDescriptor::maxAnisotropy() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxAnisotropy));
}

_MTL_INLINE MTL::SamplerMinMagFilter MTL::SamplerDescriptor::minFilter() const
{
    return sendMessage<SamplerMinMagFilter>(this, _MTL_PRIVATE_SEL(minFilter));
}

_MTL_INLINE MTL::SamplerMipFilter MTL::SamplerDescriptor::mipFilter() const
{
    return sendMessage<SamplerMipFilter>(this, _MTL_PRIVATE_SEL(mipFilter));
}

_MTL_INLINE bool MTL::SamplerDescriptor::normalizedCoordinates() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(normalizedCoordinates));
}

_MTL_INLINE MTL::SamplerAddressMode MTL::SamplerDescriptor::rAddressMode() const
{
    return sendMessage<SamplerAddressMode>(this, _MTL_PRIVATE_SEL(rAddressMode));
}

_MTL_INLINE MTL::SamplerReductionMode MTL::SamplerDescriptor::reductionMode() const
{
    return sendMessage<SamplerReductionMode>(this, _MTL_PRIVATE_SEL(reductionMode));
}

_MTL_INLINE MTL::SamplerAddressMode MTL::SamplerDescriptor::sAddressMode() const
{
    return sendMessage<SamplerAddressMode>(this, _MTL_PRIVATE_SEL(sAddressMode));
}

_MTL_INLINE void MTL::SamplerDescriptor::setBorderColor(const SamplerBorderColor borderColor) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBorderColor_), borderColor);
}

_MTL_INLINE void MTL::SamplerDescriptor::setCompareFunction(const CompareFunction compareFunction) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setCompareFunction_), compareFunction);
}

_MTL_INLINE void MTL::SamplerDescriptor::setLabel(const NS::String* label) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLabel_), label);
}

_MTL_INLINE void MTL::SamplerDescriptor::setLodAverage(const bool lodAverage) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLodAverage_), lodAverage);
}

_MTL_INLINE void MTL::SamplerDescriptor::setLodBias(const float lodBias) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLodBias_), lodBias);
}

_MTL_INLINE void MTL::SamplerDescriptor::setLodMaxClamp(const float lodMaxClamp) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLodMaxClamp_), lodMaxClamp);
}

_MTL_INLINE void MTL::SamplerDescriptor::setLodMinClamp(const float lodMinClamp) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLodMinClamp_), lodMinClamp);
}

_MTL_INLINE void MTL::SamplerDescriptor::setMagFilter(const SamplerMinMagFilter magFilter) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMagFilter_), magFilter);
}

_MTL_INLINE void MTL::SamplerDescriptor::setMaxAnisotropy(const NS::UInteger maxAnisotropy) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxAnisotropy_), maxAnisotropy);
}

_MTL_INLINE void MTL::SamplerDescriptor::setMinFilter(const SamplerMinMagFilter minFilter) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMinFilter_), minFilter);
}

_MTL_INLINE void MTL::SamplerDescriptor::setMipFilter(const SamplerMipFilter mipFilter) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMipFilter_), mipFilter);
}

_MTL_INLINE void MTL::SamplerDescriptor::setNormalizedCoordinates(const bool normalizedCoordinates) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setNormalizedCoordinates_), normalizedCoordinates);
}

_MTL_INLINE void MTL::SamplerDescriptor::setRAddressMode(const SamplerAddressMode rAddressMode) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRAddressMode_), rAddressMode);
}

_MTL_INLINE void MTL::SamplerDescriptor::setReductionMode(const SamplerReductionMode reductionMode) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setReductionMode_), reductionMode);
}

_MTL_INLINE void MTL::SamplerDescriptor::setSAddressMode(const SamplerAddressMode sAddressMode) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSAddressMode_), sAddressMode);
}

_MTL_INLINE void MTL::SamplerDescriptor::setSupportArgumentBuffers(const bool supportArgumentBuffers) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSupportArgumentBuffers_), supportArgumentBuffers);
}

_MTL_INLINE void MTL::SamplerDescriptor::setTAddressMode(const SamplerAddressMode tAddressMode) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTAddressMode_), tAddressMode);
}

_MTL_INLINE bool MTL::SamplerDescriptor::supportArgumentBuffers() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supportArgumentBuffers));
}

_MTL_INLINE MTL::SamplerAddressMode MTL::SamplerDescriptor::tAddressMode() const
{
    return sendMessage<SamplerAddressMode>(this, _MTL_PRIVATE_SEL(tAddressMode));
}

_MTL_INLINE MTL::Device* MTL::SamplerState::device() const
{
    return sendMessage<Device*>(this, _MTL_PRIVATE_SEL(device));
}

_MTL_INLINE MTL::ResourceID MTL::SamplerState::gpuResourceID() const
{
    return sendMessage<ResourceID>(this, _MTL_PRIVATE_SEL(gpuResourceID));
}

_MTL_INLINE NS::String* MTL::SamplerState::label() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
}
