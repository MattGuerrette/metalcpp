//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLRasterizationRate.hpp
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
#include "MTLDevice.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"
#include "MTLTypes.hpp"

namespace MTL
{
    class Buffer;
    class Device;
    class RasterizationRateLayerArray;
    class RasterizationRateLayerDescriptor;
    class RasterizationRateMapDescriptor;
    class RasterizationRateSampleArray;

    /// @see https://developer.apple.com/documentation/metal/mtlrasterizationratesamplearray?language=objc
    class RasterizationRateSampleArray : public NS::Referencing<RasterizationRateSampleArray>
    {
    public:
        [[nodiscard]] static RasterizationRateSampleArray* alloc();

        [[nodiscard]] RasterizationRateSampleArray* init();

        [[nodiscard]] NS::Number* object(NS::UInteger index) const;
        void                      setObject(const NS::Number* value, NS::UInteger index) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlrasterizationratelayerdescriptor?language=objc
    class RasterizationRateLayerDescriptor : public NS::Copying<RasterizationRateLayerDescriptor>
    {
    public:
        [[nodiscard]] static RasterizationRateLayerDescriptor* alloc();

        [[nodiscard]] RasterizationRateSampleArray* horizontal() const;
        [[nodiscard]] float*                        horizontalSampleStorage() const;

        [[nodiscard]] RasterizationRateLayerDescriptor* init();
        [[nodiscard]] RasterizationRateLayerDescriptor* init(const Size& sampleCount) const;
        [[nodiscard]] RasterizationRateLayerDescriptor* init(const Size&  sampleCount,
                                                             const float* horizontal,
                                                             const float* vertical) const;

        [[nodiscard]] Size maxSampleCount() const;
        [[nodiscard]] Size sampleCount() const;
        void               setSampleCount(const Size& sampleCount) const;

        [[nodiscard]] RasterizationRateSampleArray* vertical() const;
        [[nodiscard]] float*                        verticalSampleStorage() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlrasterizationratelayerarray?language=objc
    class RasterizationRateLayerArray : public NS::Referencing<RasterizationRateLayerArray>
    {
    public:
        [[nodiscard]] static RasterizationRateLayerArray* alloc();

        [[nodiscard]] RasterizationRateLayerArray* init();

        [[nodiscard]] RasterizationRateLayerDescriptor* object(NS::UInteger layerIndex) const;
        void setObject(const RasterizationRateLayerDescriptor* layer, NS::UInteger layerIndex) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlrasterizationratemapdescriptor?language=objc
    class RasterizationRateMapDescriptor : public NS::Copying<RasterizationRateMapDescriptor>
    {
    public:
        [[nodiscard]] static RasterizationRateMapDescriptor* alloc();

        [[nodiscard]] RasterizationRateMapDescriptor* init();

        [[nodiscard]] NS::String* label() const;

        [[nodiscard]] RasterizationRateLayerDescriptor* layer(NS::UInteger layerIndex) const;
        [[nodiscard]] NS::UInteger                      layerCount() const;

        [[nodiscard]] RasterizationRateLayerArray* layers() const;

        [[nodiscard]] static RasterizationRateMapDescriptor* rasterizationRateMapDescriptor(const Size& screenSize);
        [[nodiscard]] static RasterizationRateMapDescriptor* rasterizationRateMapDescriptor(
            const Size& screenSize, const RasterizationRateLayerDescriptor* layer);
        [[nodiscard]] static RasterizationRateMapDescriptor* rasterizationRateMapDescriptor(
            const Size& screenSize, NS::UInteger layerCount, const RasterizationRateLayerDescriptor* const* layers);

        [[nodiscard]] Size screenSize() const;

        void setLabel(const NS::String* label) const;

        void setLayer(const RasterizationRateLayerDescriptor* layer, NS::UInteger layerIndex) const;

        void setScreenSize(const Size& screenSize) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlrasterizationratemap?language=objc
    class RasterizationRateMap : public NS::Referencing<RasterizationRateMap>
    {
    public:
        void copyParameterDataToBuffer(const Buffer* buffer, NS::UInteger offset) const;

        [[nodiscard]] Device* device() const;

        [[nodiscard]] NS::String* label() const;

        [[nodiscard]] NS::UInteger layerCount() const;

        [[nodiscard]] Coordinate2D mapPhysicalToScreenCoordinates(Coordinate2D physicalCoordinates,
                                                                  NS::UInteger layerIndex) const;

        [[nodiscard]] Coordinate2D mapScreenToPhysicalCoordinates(Coordinate2D screenCoordinates,
                                                                  NS::UInteger layerIndex) const;

        [[nodiscard]] SizeAndAlign parameterBufferSizeAndAlign() const;

        [[nodiscard]] Size physicalGranularity() const;

        [[nodiscard]] Size physicalSize(NS::UInteger layerIndex) const;

        [[nodiscard]] Size screenSize() const;
    };

} // namespace MTL
_MTL_INLINE MTL::RasterizationRateSampleArray* MTL::RasterizationRateSampleArray::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<RasterizationRateSampleArray>(_MTL_PRIVATE_CLS(MTLRasterizationRateSampleArray));
}

_MTL_INLINE MTL::RasterizationRateSampleArray* MTL::RasterizationRateSampleArray::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<RasterizationRateSampleArray>();
}

_MTL_INLINE NS::Number* MTL::RasterizationRateSampleArray::object(const NS::UInteger index) const
{
    return sendMessage<NS::Number*>(this, _MTL_PRIVATE_SEL(objectAtIndexedSubscript_), index);
}

_MTL_INLINE void MTL::RasterizationRateSampleArray::setObject(const NS::Number* value, const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setObject_atIndexedSubscript_), value, index);
}

_MTL_INLINE MTL::RasterizationRateLayerDescriptor* MTL::RasterizationRateLayerDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<RasterizationRateLayerDescriptor>(_MTL_PRIVATE_CLS(MTLRasterizationRateLayerDescriptor));
}

_MTL_INLINE MTL::RasterizationRateSampleArray* MTL::RasterizationRateLayerDescriptor::horizontal() const
{
    return sendMessage<RasterizationRateSampleArray*>(this, _MTL_PRIVATE_SEL(horizontal));
}

_MTL_INLINE float* MTL::RasterizationRateLayerDescriptor::horizontalSampleStorage() const
{
    return sendMessage<float*>(this, _MTL_PRIVATE_SEL(horizontalSampleStorage));
}

_MTL_INLINE MTL::RasterizationRateLayerDescriptor* MTL::RasterizationRateLayerDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<RasterizationRateLayerDescriptor>();
}

_MTL_INLINE MTL::RasterizationRateLayerDescriptor* MTL::RasterizationRateLayerDescriptor::init(
    const Size& sampleCount) const
{
    return sendMessage<RasterizationRateLayerDescriptor*>(this, _MTL_PRIVATE_SEL(initWithSampleCount_), sampleCount);
}

_MTL_INLINE MTL::RasterizationRateLayerDescriptor* MTL::RasterizationRateLayerDescriptor::init(
    const Size& sampleCount, const float* horizontal, const float* vertical) const
{
    return sendMessage<RasterizationRateLayerDescriptor*>(
        this, _MTL_PRIVATE_SEL(initWithSampleCount_horizontal_vertical_), sampleCount, horizontal, vertical);
}

_MTL_INLINE MTL::Size MTL::RasterizationRateLayerDescriptor::maxSampleCount() const
{
    return sendMessage<Size>(this, _MTL_PRIVATE_SEL(maxSampleCount));
}

_MTL_INLINE MTL::Size MTL::RasterizationRateLayerDescriptor::sampleCount() const
{
    return sendMessage<Size>(this, _MTL_PRIVATE_SEL(sampleCount));
}

_MTL_INLINE void MTL::RasterizationRateLayerDescriptor::setSampleCount(const Size& sampleCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSampleCount_), sampleCount);
}

_MTL_INLINE MTL::RasterizationRateSampleArray* MTL::RasterizationRateLayerDescriptor::vertical() const
{
    return sendMessage<RasterizationRateSampleArray*>(this, _MTL_PRIVATE_SEL(vertical));
}

_MTL_INLINE float* MTL::RasterizationRateLayerDescriptor::verticalSampleStorage() const
{
    return sendMessage<float*>(this, _MTL_PRIVATE_SEL(verticalSampleStorage));
}

_MTL_INLINE MTL::RasterizationRateLayerArray* MTL::RasterizationRateLayerArray::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<RasterizationRateLayerArray>(_MTL_PRIVATE_CLS(MTLRasterizationRateLayerArray));
}

_MTL_INLINE MTL::RasterizationRateLayerArray* MTL::RasterizationRateLayerArray::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<RasterizationRateLayerArray>();
}

_MTL_INLINE MTL::RasterizationRateLayerDescriptor* MTL::RasterizationRateLayerArray::object(
    const NS::UInteger layerIndex) const
{
    return sendMessage<RasterizationRateLayerDescriptor*>(
        this, _MTL_PRIVATE_SEL(objectAtIndexedSubscript_), layerIndex);
}

_MTL_INLINE void MTL::RasterizationRateLayerArray::setObject(const RasterizationRateLayerDescriptor* layer,
                                                             const NS::UInteger                      layerIndex) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setObject_atIndexedSubscript_), layer, layerIndex);
}

_MTL_INLINE MTL::RasterizationRateMapDescriptor* MTL::RasterizationRateMapDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<RasterizationRateMapDescriptor>(_MTL_PRIVATE_CLS(MTLRasterizationRateMapDescriptor));
}

_MTL_INLINE MTL::RasterizationRateMapDescriptor* MTL::RasterizationRateMapDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<RasterizationRateMapDescriptor>();
}

_MTL_INLINE NS::String* MTL::RasterizationRateMapDescriptor::label() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
}

_MTL_INLINE MTL::RasterizationRateLayerDescriptor* MTL::RasterizationRateMapDescriptor::layer(
    const NS::UInteger layerIndex) const
{
    return sendMessage<RasterizationRateLayerDescriptor*>(this, _MTL_PRIVATE_SEL(layerAtIndex_), layerIndex);
}

_MTL_INLINE NS::UInteger MTL::RasterizationRateMapDescriptor::layerCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(layerCount));
}

_MTL_INLINE MTL::RasterizationRateLayerArray* MTL::RasterizationRateMapDescriptor::layers() const
{
    return sendMessage<RasterizationRateLayerArray*>(this, _MTL_PRIVATE_SEL(layers));
}

_MTL_INLINE MTL::RasterizationRateMapDescriptor* MTL::RasterizationRateMapDescriptor::rasterizationRateMapDescriptor(
    const Size& screenSize)
{
    return sendMessage<RasterizationRateMapDescriptor*>(_MTL_PRIVATE_CLS(MTLRasterizationRateMapDescriptor),
                                                        _MTL_PRIVATE_SEL(rasterizationRateMapDescriptorWithScreenSize_),
                                                        screenSize);
}

_MTL_INLINE MTL::RasterizationRateMapDescriptor* MTL::RasterizationRateMapDescriptor::rasterizationRateMapDescriptor(
    const Size& screenSize, const RasterizationRateLayerDescriptor* layer)
{
    return sendMessage<RasterizationRateMapDescriptor*>(
        _MTL_PRIVATE_CLS(MTLRasterizationRateMapDescriptor),
        _MTL_PRIVATE_SEL(rasterizationRateMapDescriptorWithScreenSize_layer_),
        screenSize,
        layer);
}

_MTL_INLINE MTL::RasterizationRateMapDescriptor* MTL::RasterizationRateMapDescriptor::rasterizationRateMapDescriptor(
    const Size& screenSize, const NS::UInteger layerCount, const RasterizationRateLayerDescriptor* const* layers)
{
    return sendMessage<RasterizationRateMapDescriptor*>(
        _MTL_PRIVATE_CLS(MTLRasterizationRateMapDescriptor),
        _MTL_PRIVATE_SEL(rasterizationRateMapDescriptorWithScreenSize_layerCount_layers_),
        screenSize,
        layerCount,
        layers);
}

_MTL_INLINE MTL::Size MTL::RasterizationRateMapDescriptor::screenSize() const
{
    return sendMessage<Size>(this, _MTL_PRIVATE_SEL(screenSize));
}

_MTL_INLINE void MTL::RasterizationRateMapDescriptor::setLabel(const NS::String* label) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLabel_), label);
}

_MTL_INLINE void MTL::RasterizationRateMapDescriptor::setLayer(const RasterizationRateLayerDescriptor* layer,
                                                               const NS::UInteger                      layerIndex) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLayer_atIndex_), layer, layerIndex);
}

_MTL_INLINE void MTL::RasterizationRateMapDescriptor::setScreenSize(const Size& screenSize) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setScreenSize_), screenSize);
}

_MTL_INLINE void MTL::RasterizationRateMap::copyParameterDataToBuffer(const Buffer*      buffer,
                                                                      const NS::UInteger offset) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(copyParameterDataToBuffer_offset_), buffer, offset);
}

_MTL_INLINE MTL::Device* MTL::RasterizationRateMap::device() const
{
    return sendMessage<Device*>(this, _MTL_PRIVATE_SEL(device));
}

_MTL_INLINE NS::String* MTL::RasterizationRateMap::label() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
}

_MTL_INLINE NS::UInteger MTL::RasterizationRateMap::layerCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(layerCount));
}

_MTL_INLINE MTL::Coordinate2D MTL::RasterizationRateMap::mapPhysicalToScreenCoordinates(
    const Coordinate2D physicalCoordinates, const NS::UInteger layerIndex) const
{
    return sendMessage<Coordinate2D>(
        this, _MTL_PRIVATE_SEL(mapPhysicalToScreenCoordinates_forLayer_), physicalCoordinates, layerIndex);
}

_MTL_INLINE MTL::Coordinate2D MTL::RasterizationRateMap::mapScreenToPhysicalCoordinates(
    const Coordinate2D screenCoordinates, const NS::UInteger layerIndex) const
{
    return sendMessage<Coordinate2D>(
        this, _MTL_PRIVATE_SEL(mapScreenToPhysicalCoordinates_forLayer_), screenCoordinates, layerIndex);
}

_MTL_INLINE MTL::SizeAndAlign MTL::RasterizationRateMap::parameterBufferSizeAndAlign() const
{
    return sendMessage<SizeAndAlign>(this, _MTL_PRIVATE_SEL(parameterBufferSizeAndAlign));
}

_MTL_INLINE MTL::Size MTL::RasterizationRateMap::physicalGranularity() const
{
    return sendMessage<Size>(this, _MTL_PRIVATE_SEL(physicalGranularity));
}

_MTL_INLINE MTL::Size MTL::RasterizationRateMap::physicalSize(const NS::UInteger layerIndex) const
{
    return sendMessage<Size>(this, _MTL_PRIVATE_SEL(physicalSizeForLayer_), layerIndex);
}

_MTL_INLINE MTL::Size MTL::RasterizationRateMap::screenSize() const
{
    return sendMessage<Size>(this, _MTL_PRIVATE_SEL(screenSize));
}
