//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLTexture.hpp
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

#include <IOSurface/IOSurfaceRef.h>
#include "../Foundation/Foundation.hpp"
#include "MTLDefines.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPixelFormat.hpp"
#include "MTLPrivate.hpp"
#include "MTLResource.hpp"
#include "MTLTypes.hpp"

namespace MTL
{
    class Buffer;
    class Device;
    class Resource;
    class SharedTextureHandle;
    class Texture;
    class TextureDescriptor;
    class TextureViewDescriptor;
} // namespace MTL

namespace MTL
{
    /// @see https://developer.apple.com/documentation/metal/mtltexturetype?language=objc
    _MTL_ENUM(NS::UInteger, TextureType){
        TextureType1D                 = 0,
        TextureType1DArray            = 1,
        TextureType2D                 = 2,
        TextureType2DArray            = 3,
        TextureType2DMultisample      = 4,
        TextureTypeCube               = 5,
        TextureTypeCubeArray          = 6,
        TextureType3D                 = 7,
        TextureType2DMultisampleArray = 8,
        TextureTypeTextureBuffer      = 9,
    };

    /// @see https://developer.apple.com/documentation/metal/mtltextureswizzle?language=objc
    _MTL_ENUM(uint8_t, TextureSwizzle){
        TextureSwizzleZero = 0,  TextureSwizzleOne = 1,  TextureSwizzleRed = 2,
        TextureSwizzleGreen = 3, TextureSwizzleBlue = 4, TextureSwizzleAlpha = 5,
    };

    /// @see https://developer.apple.com/documentation/metal/mtltexturecompressiontype?language=objc
    _MTL_ENUM(NS::Integer, TextureCompressionType){
        TextureCompressionTypeLossless = 0,
        TextureCompressionTypeLossy    = 1,
    };

    /// @see https://developer.apple.com/documentation/metal/mtltextureusage?language=objc
    _MTL_OPTIONS(NS::UInteger, TextureUsage){
        TextureUsageUnknown = 0,           TextureUsageShaderRead = 1,           TextureUsageShaderWrite = 1 << 1,
        TextureUsageRenderTarget = 1 << 2, TextureUsagePixelFormatView = 1 << 4, TextureUsageShaderAtomic = 1 << 5,
    };

    /// @see https://developer.apple.com/documentation/metal/mtltextureswizzlechannels?language=objc
    struct TextureSwizzleChannels
    {
        TextureSwizzleChannels(TextureSwizzle r, TextureSwizzle g, TextureSwizzle b, TextureSwizzle a);

        TextureSwizzleChannels();

        [[nodiscard]] static TextureSwizzleChannels Default();

        [[nodiscard]] static TextureSwizzleChannels Make(TextureSwizzle r,
                                                         TextureSwizzle g,
                                                         TextureSwizzle b,
                                                         TextureSwizzle a);

        TextureSwizzle red;
        TextureSwizzle green;
        TextureSwizzle blue;
        TextureSwizzle alpha;
    } _MTL_PACKED;

    /// @see https://developer.apple.com/documentation/metal/mtlsharedtexturehandle?language=objc
    class SharedTextureHandle : public NS::SecureCoding<SharedTextureHandle>
    {
    public:
        [[nodiscard]] static SharedTextureHandle* alloc();

        [[nodiscard]] Device* device() const;

        [[nodiscard]] SharedTextureHandle* init();

        [[nodiscard]] NS::String* label() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtltexturedescriptor?language=objc
    class TextureDescriptor : public NS::Copying<TextureDescriptor>
    {
    public:
        [[nodiscard]] static TextureDescriptor* alloc();

        [[nodiscard]] bool allowGPUOptimizedContents() const;

        [[nodiscard]] NS::UInteger arrayLength() const;

        [[nodiscard]] TextureCompressionType compressionType() const;

        [[nodiscard]] CPUCacheMode cpuCacheMode() const;

        [[nodiscard]] NS::UInteger depth() const;

        [[nodiscard]] HazardTrackingMode hazardTrackingMode() const;

        [[nodiscard]] NS::UInteger height() const;

        [[nodiscard]] TextureDescriptor* init();

        [[nodiscard]] NS::UInteger mipmapLevelCount() const;

        [[nodiscard]] PixelFormat pixelFormat() const;

        [[nodiscard]] SparsePageSize placementSparsePageSize() const;

        [[nodiscard]] ResourceOptions resourceOptions() const;

        [[nodiscard]] NS::UInteger sampleCount() const;

        void setAllowGPUOptimizedContents(bool allowGPUOptimizedContents) const;

        void setArrayLength(NS::UInteger arrayLength) const;

        void setCompressionType(TextureCompressionType compressionType) const;

        void setCpuCacheMode(CPUCacheMode cpuCacheMode) const;

        void setDepth(NS::UInteger depth) const;

        void setHazardTrackingMode(HazardTrackingMode hazardTrackingMode) const;

        void setHeight(NS::UInteger height) const;

        void setMipmapLevelCount(NS::UInteger mipmapLevelCount) const;

        void setPixelFormat(PixelFormat pixelFormat) const;

        void setPlacementSparsePageSize(SparsePageSize placementSparsePageSize) const;

        void setResourceOptions(ResourceOptions resourceOptions) const;

        void setSampleCount(NS::UInteger sampleCount) const;

        void setStorageMode(StorageMode storageMode) const;

        void setSwizzle(TextureSwizzleChannels swizzle) const;

        void setTextureType(TextureType textureType) const;

        void setUsage(TextureUsage usage) const;

        void setWidth(NS::UInteger width) const;

        [[nodiscard]] StorageMode storageMode() const;

        [[nodiscard]] TextureSwizzleChannels swizzle() const;

        [[nodiscard]] static TextureDescriptor* texture2DDescriptor(PixelFormat  pixelFormat,
                                                                    NS::UInteger width,
                                                                    NS::UInteger height,
                                                                    bool         mipmapped);

        [[nodiscard]] static TextureDescriptor* textureBufferDescriptor(PixelFormat     pixelFormat,
                                                                        NS::UInteger    width,
                                                                        ResourceOptions resourceOptions,
                                                                        TextureUsage    usage);

        [[nodiscard]] static TextureDescriptor* textureCubeDescriptor(PixelFormat  pixelFormat,
                                                                      NS::UInteger size,
                                                                      bool         mipmapped);

        [[nodiscard]] TextureType textureType() const;

        [[nodiscard]] TextureUsage usage() const;

        [[nodiscard]] NS::UInteger width() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtltextureviewdescriptor?language=objc
    class TextureViewDescriptor : public NS::Copying<TextureViewDescriptor>
    {
    public:
        [[nodiscard]] static TextureViewDescriptor* alloc();

        [[nodiscard]] TextureViewDescriptor* init();

        [[nodiscard]] NS::Range levelRange() const;

        [[nodiscard]] PixelFormat pixelFormat() const;

        void setLevelRange(NS::Range levelRange) const;

        void setPixelFormat(PixelFormat pixelFormat) const;

        void setSliceRange(NS::Range sliceRange) const;

        void setSwizzle(TextureSwizzleChannels swizzle) const;

        void setTextureType(TextureType textureType) const;

        [[nodiscard]] NS::Range sliceRange() const;

        [[nodiscard]] TextureSwizzleChannels swizzle() const;

        [[nodiscard]] TextureType textureType() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtltexture?language=objc
    class Texture : public NS::Referencing<Texture, Resource>
    {
    public:
        [[nodiscard]] bool allowGPUOptimizedContents() const;

        [[nodiscard]] NS::UInteger arrayLength() const;

        [[nodiscard]] Buffer*      buffer() const;
        [[nodiscard]] NS::UInteger bufferBytesPerRow() const;

        [[nodiscard]] NS::UInteger bufferOffset() const;

        [[nodiscard]] TextureCompressionType compressionType() const;

        [[nodiscard]] NS::UInteger depth() const;

        [[nodiscard]] NS::UInteger firstMipmapInTail() const;

        [[deprecated("please use isFramebufferOnly instead")]] [[nodiscard]] bool framebufferOnly() const;

        void getBytes(void*        pixelBytes,
                      NS::UInteger bytesPerRow,
                      NS::UInteger bytesPerImage,
                      const Region& region,
                      NS::UInteger level,
                      NS::UInteger slice) const;
        void getBytes(void* pixelBytes, NS::UInteger bytesPerRow, const Region& region, NS::UInteger level) const;

        [[nodiscard]] ResourceID gpuResourceID() const;

        [[nodiscard]] NS::UInteger height() const;

        [[nodiscard]] IOSurfaceRef iosurface() const;
        [[nodiscard]] NS::UInteger iosurfacePlane() const;

        [[nodiscard]] bool isFramebufferOnly() const;

        [[nodiscard]] bool isShareable() const;

        [[nodiscard]] bool isSparse() const;

        [[nodiscard]] NS::UInteger mipmapLevelCount() const;

        [[nodiscard]] Texture* newRemoteTextureViewForDevice(const Device* device) const;

        [[nodiscard]] SharedTextureHandle* newSharedTextureHandle() const;

        [[nodiscard]] Texture* newTextureView(PixelFormat pixelFormat) const;
        [[nodiscard]] Texture* newTextureView(PixelFormat pixelFormat,
                                              TextureType textureType,
                                              NS::Range   levelRange,
                                              NS::Range   sliceRange) const;
        [[nodiscard]] Texture* newTextureView(const TextureViewDescriptor* descriptor) const;
        [[nodiscard]] Texture* newTextureView(PixelFormat            pixelFormat,
                                              TextureType            textureType,
                                              NS::Range              levelRange,
                                              NS::Range              sliceRange,
                                              TextureSwizzleChannels swizzle) const;

        [[nodiscard]] NS::UInteger parentRelativeLevel() const;

        [[nodiscard]] NS::UInteger parentRelativeSlice() const;

        [[nodiscard]] Texture* parentTexture() const;

        [[nodiscard]] PixelFormat pixelFormat() const;

        [[nodiscard]] Texture* remoteStorageTexture() const;

        void replaceRegion(const Region& region,
                           NS::UInteger level,
                           NS::UInteger slice,
                           const void*  pixelBytes,
                           NS::UInteger bytesPerRow,
                           NS::UInteger bytesPerImage) const;
        void replaceRegion(const Region& region, NS::UInteger level, const void* pixelBytes, NS::UInteger bytesPerRow) const;

        [[nodiscard]] Resource* rootResource() const;

        [[nodiscard]] NS::UInteger sampleCount() const;

        [[deprecated("please use isShareable instead")]] [[nodiscard]] bool shareable() const;

        [[nodiscard]] TextureSparseTier sparseTextureTier() const;

        [[nodiscard]] TextureSwizzleChannels swizzle() const;

        [[nodiscard]] NS::UInteger tailSizeInBytes() const;

        [[nodiscard]] TextureType textureType() const;

        [[nodiscard]] TextureUsage usage() const;

        [[nodiscard]] NS::UInteger width() const;
    };

} // namespace MTL
_MTL_INLINE MTL::TextureSwizzleChannels::TextureSwizzleChannels(const TextureSwizzle r,
                                                                const TextureSwizzle g,
                                                                const TextureSwizzle b,
                                                                const TextureSwizzle a)
    : red(r), green(g), blue(b), alpha(a)
{
}

_MTL_INLINE MTL::TextureSwizzleChannels::TextureSwizzleChannels()
    : red(TextureSwizzleRed), green(TextureSwizzleGreen), blue(TextureSwizzleBlue), alpha(TextureSwizzleAlpha)
{
}

_MTL_INLINE MTL::TextureSwizzleChannels MTL::TextureSwizzleChannels::Default() { return {}; }

_MTL_INLINE MTL::TextureSwizzleChannels MTL::TextureSwizzleChannels::Make(const TextureSwizzle r,
                                                                          const TextureSwizzle g,
                                                                          const TextureSwizzle b,
                                                                          const TextureSwizzle a)
{
    return { r, g, b, a };
}

_MTL_INLINE MTL::SharedTextureHandle* MTL::SharedTextureHandle::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<SharedTextureHandle>(_MTL_PRIVATE_CLS(MTLSharedTextureHandle));
}

_MTL_INLINE MTL::Device* MTL::SharedTextureHandle::device() const
{
    return sendMessage<Device*>(this, _MTL_PRIVATE_SEL(device));
}

_MTL_INLINE MTL::SharedTextureHandle* MTL::SharedTextureHandle::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<SharedTextureHandle>();
}

_MTL_INLINE NS::String* MTL::SharedTextureHandle::label() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
}

_MTL_INLINE MTL::TextureDescriptor* MTL::TextureDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<TextureDescriptor>(_MTL_PRIVATE_CLS(MTLTextureDescriptor));
}

_MTL_INLINE bool MTL::TextureDescriptor::allowGPUOptimizedContents() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(allowGPUOptimizedContents));
}

_MTL_INLINE NS::UInteger MTL::TextureDescriptor::arrayLength() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(arrayLength));
}

_MTL_INLINE MTL::TextureCompressionType MTL::TextureDescriptor::compressionType() const
{
    return sendMessage<TextureCompressionType>(this, _MTL_PRIVATE_SEL(compressionType));
}

_MTL_INLINE MTL::CPUCacheMode MTL::TextureDescriptor::cpuCacheMode() const
{
    return sendMessage<CPUCacheMode>(this, _MTL_PRIVATE_SEL(cpuCacheMode));
}

_MTL_INLINE NS::UInteger MTL::TextureDescriptor::depth() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(depth));
}

_MTL_INLINE MTL::HazardTrackingMode MTL::TextureDescriptor::hazardTrackingMode() const
{
    return sendMessage<HazardTrackingMode>(this, _MTL_PRIVATE_SEL(hazardTrackingMode));
}

_MTL_INLINE NS::UInteger MTL::TextureDescriptor::height() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(height));
}

_MTL_INLINE MTL::TextureDescriptor* MTL::TextureDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<TextureDescriptor>();
}

_MTL_INLINE NS::UInteger MTL::TextureDescriptor::mipmapLevelCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(mipmapLevelCount));
}

_MTL_INLINE MTL::PixelFormat MTL::TextureDescriptor::pixelFormat() const
{
    return sendMessage<PixelFormat>(this, _MTL_PRIVATE_SEL(pixelFormat));
}

_MTL_INLINE MTL::SparsePageSize MTL::TextureDescriptor::placementSparsePageSize() const
{
    return sendMessage<SparsePageSize>(this, _MTL_PRIVATE_SEL(placementSparsePageSize));
}

_MTL_INLINE MTL::ResourceOptions MTL::TextureDescriptor::resourceOptions() const
{
    return sendMessage<ResourceOptions>(this, _MTL_PRIVATE_SEL(resourceOptions));
}

_MTL_INLINE NS::UInteger MTL::TextureDescriptor::sampleCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(sampleCount));
}

_MTL_INLINE void MTL::TextureDescriptor::setAllowGPUOptimizedContents(const bool allowGPUOptimizedContents) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setAllowGPUOptimizedContents_), allowGPUOptimizedContents);
}

_MTL_INLINE void MTL::TextureDescriptor::setArrayLength(const NS::UInteger arrayLength) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setArrayLength_), arrayLength);
}

_MTL_INLINE void MTL::TextureDescriptor::setCompressionType(const TextureCompressionType compressionType) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setCompressionType_), compressionType);
}

_MTL_INLINE void MTL::TextureDescriptor::setCpuCacheMode(const CPUCacheMode cpuCacheMode) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setCpuCacheMode_), cpuCacheMode);
}

_MTL_INLINE void MTL::TextureDescriptor::setDepth(const NS::UInteger depth) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDepth_), depth);
}

_MTL_INLINE void MTL::TextureDescriptor::setHazardTrackingMode(const HazardTrackingMode hazardTrackingMode) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setHazardTrackingMode_), hazardTrackingMode);
}

_MTL_INLINE void MTL::TextureDescriptor::setHeight(const NS::UInteger height) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setHeight_), height);
}

_MTL_INLINE void MTL::TextureDescriptor::setMipmapLevelCount(const NS::UInteger mipmapLevelCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMipmapLevelCount_), mipmapLevelCount);
}

_MTL_INLINE void MTL::TextureDescriptor::setPixelFormat(const PixelFormat pixelFormat) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setPixelFormat_), pixelFormat);
}

_MTL_INLINE void MTL::TextureDescriptor::setPlacementSparsePageSize(const SparsePageSize placementSparsePageSize) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setPlacementSparsePageSize_), placementSparsePageSize);
}

_MTL_INLINE void MTL::TextureDescriptor::setResourceOptions(const ResourceOptions resourceOptions) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setResourceOptions_), resourceOptions);
}

_MTL_INLINE void MTL::TextureDescriptor::setSampleCount(const NS::UInteger sampleCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSampleCount_), sampleCount);
}

_MTL_INLINE void MTL::TextureDescriptor::setStorageMode(const StorageMode storageMode) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setStorageMode_), storageMode);
}

_MTL_INLINE void MTL::TextureDescriptor::setSwizzle(const TextureSwizzleChannels swizzle) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSwizzle_), swizzle);
}

_MTL_INLINE void MTL::TextureDescriptor::setTextureType(const TextureType textureType) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTextureType_), textureType);
}

_MTL_INLINE void MTL::TextureDescriptor::setUsage(const TextureUsage usage) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setUsage_), usage);
}

_MTL_INLINE void MTL::TextureDescriptor::setWidth(const NS::UInteger width) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setWidth_), width);
}

_MTL_INLINE MTL::StorageMode MTL::TextureDescriptor::storageMode() const
{
    return sendMessage<StorageMode>(this, _MTL_PRIVATE_SEL(storageMode));
}

_MTL_INLINE MTL::TextureSwizzleChannels MTL::TextureDescriptor::swizzle() const
{
    return sendMessage<TextureSwizzleChannels>(this, _MTL_PRIVATE_SEL(swizzle));
}

_MTL_INLINE MTL::TextureDescriptor* MTL::TextureDescriptor::texture2DDescriptor(const PixelFormat  pixelFormat,
                                                                                const NS::UInteger width,
                                                                                const NS::UInteger height,
                                                                                const bool         mipmapped)
{
    return sendMessage<TextureDescriptor*>(_MTL_PRIVATE_CLS(MTLTextureDescriptor),
                                           _MTL_PRIVATE_SEL(texture2DDescriptorWithPixelFormat_width_height_mipmapped_),
                                           pixelFormat,
                                           width,
                                           height,
                                           mipmapped);
}

_MTL_INLINE MTL::TextureDescriptor* MTL::TextureDescriptor::textureBufferDescriptor(
    const PixelFormat     pixelFormat,
    const NS::UInteger    width,
    const ResourceOptions resourceOptions,
    const TextureUsage    usage)
{
    return sendMessage<TextureDescriptor*>(
        _MTL_PRIVATE_CLS(MTLTextureDescriptor),
        _MTL_PRIVATE_SEL(textureBufferDescriptorWithPixelFormat_width_resourceOptions_usage_),
        pixelFormat,
        width,
        resourceOptions,
        usage);
}

_MTL_INLINE MTL::TextureDescriptor* MTL::TextureDescriptor::textureCubeDescriptor(const PixelFormat  pixelFormat,
                                                                                  const NS::UInteger size,
                                                                                  const bool         mipmapped)
{
    return sendMessage<TextureDescriptor*>(_MTL_PRIVATE_CLS(MTLTextureDescriptor),
                                           _MTL_PRIVATE_SEL(textureCubeDescriptorWithPixelFormat_size_mipmapped_),
                                           pixelFormat,
                                           size,
                                           mipmapped);
}

_MTL_INLINE MTL::TextureType MTL::TextureDescriptor::textureType() const
{
    return sendMessage<TextureType>(this, _MTL_PRIVATE_SEL(textureType));
}

_MTL_INLINE MTL::TextureUsage MTL::TextureDescriptor::usage() const
{
    return sendMessage<TextureUsage>(this, _MTL_PRIVATE_SEL(usage));
}

_MTL_INLINE NS::UInteger MTL::TextureDescriptor::width() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(width));
}

_MTL_INLINE MTL::TextureViewDescriptor* MTL::TextureViewDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<TextureViewDescriptor>(_MTL_PRIVATE_CLS(MTLTextureViewDescriptor));
}

_MTL_INLINE MTL::TextureViewDescriptor* MTL::TextureViewDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<TextureViewDescriptor>();
}

_MTL_INLINE NS::Range MTL::TextureViewDescriptor::levelRange() const
{
    return sendMessage<NS::Range>(this, _MTL_PRIVATE_SEL(levelRange));
}

_MTL_INLINE MTL::PixelFormat MTL::TextureViewDescriptor::pixelFormat() const
{
    return sendMessage<PixelFormat>(this, _MTL_PRIVATE_SEL(pixelFormat));
}

_MTL_INLINE void MTL::TextureViewDescriptor::setLevelRange(const NS::Range levelRange) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLevelRange_), levelRange);
}

_MTL_INLINE void MTL::TextureViewDescriptor::setPixelFormat(const PixelFormat pixelFormat) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setPixelFormat_), pixelFormat);
}

_MTL_INLINE void MTL::TextureViewDescriptor::setSliceRange(const NS::Range sliceRange) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSliceRange_), sliceRange);
}

_MTL_INLINE void MTL::TextureViewDescriptor::setSwizzle(const TextureSwizzleChannels swizzle) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSwizzle_), swizzle);
}

_MTL_INLINE void MTL::TextureViewDescriptor::setTextureType(const TextureType textureType) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTextureType_), textureType);
}

_MTL_INLINE NS::Range MTL::TextureViewDescriptor::sliceRange() const
{
    return sendMessage<NS::Range>(this, _MTL_PRIVATE_SEL(sliceRange));
}

_MTL_INLINE MTL::TextureSwizzleChannels MTL::TextureViewDescriptor::swizzle() const
{
    return sendMessage<TextureSwizzleChannels>(this, _MTL_PRIVATE_SEL(swizzle));
}

_MTL_INLINE MTL::TextureType MTL::TextureViewDescriptor::textureType() const
{
    return sendMessage<TextureType>(this, _MTL_PRIVATE_SEL(textureType));
}

_MTL_INLINE bool MTL::Texture::allowGPUOptimizedContents() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(allowGPUOptimizedContents));
}

_MTL_INLINE NS::UInteger MTL::Texture::arrayLength() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(arrayLength));
}

_MTL_INLINE MTL::Buffer* MTL::Texture::buffer() const { return sendMessage<Buffer*>(this, _MTL_PRIVATE_SEL(buffer)); }

_MTL_INLINE NS::UInteger MTL::Texture::bufferBytesPerRow() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(bufferBytesPerRow));
}

_MTL_INLINE NS::UInteger MTL::Texture::bufferOffset() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(bufferOffset));
}

_MTL_INLINE MTL::TextureCompressionType MTL::Texture::compressionType() const
{
    return sendMessage<TextureCompressionType>(this, _MTL_PRIVATE_SEL(compressionType));
}

_MTL_INLINE NS::UInteger MTL::Texture::depth() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(depth));
}

_MTL_INLINE NS::UInteger MTL::Texture::firstMipmapInTail() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(firstMipmapInTail));
}

_MTL_INLINE bool MTL::Texture::framebufferOnly() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isFramebufferOnly));
}

_MTL_INLINE void MTL::Texture::getBytes(void*              pixelBytes,
                                        const NS::UInteger bytesPerRow,
                                        const NS::UInteger bytesPerImage,
                                        const Region&      region,
                                        const NS::UInteger level,
                                        const NS::UInteger slice) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(getBytes_bytesPerRow_bytesPerImage_fromRegion_mipmapLevel_slice_),
                      pixelBytes,
                      bytesPerRow,
                      bytesPerImage,
                      region,
                      level,
                      slice);
}

_MTL_INLINE void MTL::Texture::getBytes(void*              pixelBytes,
                                        const NS::UInteger bytesPerRow,
                                        const Region&      region,
                                        const NS::UInteger level) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(getBytes_bytesPerRow_fromRegion_mipmapLevel_), pixelBytes, bytesPerRow, region, level);
}

_MTL_INLINE MTL::ResourceID MTL::Texture::gpuResourceID() const
{
    return sendMessage<ResourceID>(this, _MTL_PRIVATE_SEL(gpuResourceID));
}

_MTL_INLINE NS::UInteger MTL::Texture::height() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(height));
}

_MTL_INLINE IOSurfaceRef MTL::Texture::iosurface() const
{
    return sendMessage<IOSurfaceRef>(this, _MTL_PRIVATE_SEL(iosurface));
}

_MTL_INLINE NS::UInteger MTL::Texture::iosurfacePlane() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(iosurfacePlane));
}

_MTL_INLINE bool MTL::Texture::isFramebufferOnly() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isFramebufferOnly));
}

_MTL_INLINE bool MTL::Texture::isShareable() const { return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isShareable)); }

_MTL_INLINE bool MTL::Texture::isSparse() const { return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isSparse)); }

_MTL_INLINE NS::UInteger MTL::Texture::mipmapLevelCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(mipmapLevelCount));
}

_MTL_INLINE MTL::Texture* MTL::Texture::newRemoteTextureViewForDevice(const Device* device) const
{
    return sendMessage<Texture*>(this, _MTL_PRIVATE_SEL(newRemoteTextureViewForDevice_), device);
}

_MTL_INLINE MTL::SharedTextureHandle* MTL::Texture::newSharedTextureHandle() const
{
    return sendMessage<SharedTextureHandle*>(this, _MTL_PRIVATE_SEL(newSharedTextureHandle));
}

_MTL_INLINE MTL::Texture* MTL::Texture::newTextureView(const PixelFormat pixelFormat) const
{
    return sendMessage<Texture*>(this, _MTL_PRIVATE_SEL(newTextureViewWithPixelFormat_), pixelFormat);
}

_MTL_INLINE MTL::Texture* MTL::Texture::newTextureView(const PixelFormat pixelFormat,
                                                       const TextureType textureType,
                                                       const NS::Range   levelRange,
                                                       const NS::Range   sliceRange) const
{
    return sendMessage<Texture*>(this,
                                 _MTL_PRIVATE_SEL(newTextureViewWithPixelFormat_textureType_levels_slices_),
                                 pixelFormat,
                                 textureType,
                                 levelRange,
                                 sliceRange);
}

_MTL_INLINE MTL::Texture* MTL::Texture::newTextureView(const TextureViewDescriptor* descriptor) const
{
    return sendMessage<Texture*>(this, _MTL_PRIVATE_SEL(newTextureViewWithDescriptor_), descriptor);
}

_MTL_INLINE MTL::Texture* MTL::Texture::newTextureView(const PixelFormat            pixelFormat,
                                                       const TextureType            textureType,
                                                       const NS::Range              levelRange,
                                                       const NS::Range              sliceRange,
                                                       const TextureSwizzleChannels swizzle) const
{
    return sendMessage<Texture*>(this,
                                 _MTL_PRIVATE_SEL(newTextureViewWithPixelFormat_textureType_levels_slices_swizzle_),
                                 pixelFormat,
                                 textureType,
                                 levelRange,
                                 sliceRange,
                                 swizzle);
}

_MTL_INLINE NS::UInteger MTL::Texture::parentRelativeLevel() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(parentRelativeLevel));
}

_MTL_INLINE NS::UInteger MTL::Texture::parentRelativeSlice() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(parentRelativeSlice));
}

_MTL_INLINE MTL::Texture* MTL::Texture::parentTexture() const
{
    return sendMessage<Texture*>(this, _MTL_PRIVATE_SEL(parentTexture));
}

_MTL_INLINE MTL::PixelFormat MTL::Texture::pixelFormat() const
{
    return sendMessage<PixelFormat>(this, _MTL_PRIVATE_SEL(pixelFormat));
}

_MTL_INLINE MTL::Texture* MTL::Texture::remoteStorageTexture() const
{
    return sendMessage<Texture*>(this, _MTL_PRIVATE_SEL(remoteStorageTexture));
}

_MTL_INLINE void MTL::Texture::replaceRegion(const Region&      region,
                                             const NS::UInteger level,
                                             const NS::UInteger slice,
                                             const void*        pixelBytes,
                                             const NS::UInteger bytesPerRow,
                                             const NS::UInteger bytesPerImage) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(replaceRegion_mipmapLevel_slice_withBytes_bytesPerRow_bytesPerImage_),
                      region,
                      level,
                      slice,
                      pixelBytes,
                      bytesPerRow,
                      bytesPerImage);
}

_MTL_INLINE void MTL::Texture::replaceRegion(const Region&      region,
                                             const NS::UInteger level,
                                             const void*        pixelBytes,
                                             const NS::UInteger bytesPerRow) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(replaceRegion_mipmapLevel_withBytes_bytesPerRow_),
                      region,
                      level,
                      pixelBytes,
                      bytesPerRow);
}

_MTL_INLINE MTL::Resource* MTL::Texture::rootResource() const
{
    return sendMessage<Resource*>(this, _MTL_PRIVATE_SEL(rootResource));
}

_MTL_INLINE NS::UInteger MTL::Texture::sampleCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(sampleCount));
}

_MTL_INLINE bool MTL::Texture::shareable() const { return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isShareable)); }

_MTL_INLINE MTL::TextureSparseTier MTL::Texture::sparseTextureTier() const
{
    return sendMessage<TextureSparseTier>(this, _MTL_PRIVATE_SEL(sparseTextureTier));
}

_MTL_INLINE MTL::TextureSwizzleChannels MTL::Texture::swizzle() const
{
    return sendMessage<TextureSwizzleChannels>(this, _MTL_PRIVATE_SEL(swizzle));
}

_MTL_INLINE NS::UInteger MTL::Texture::tailSizeInBytes() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(tailSizeInBytes));
}

_MTL_INLINE MTL::TextureType MTL::Texture::textureType() const
{
    return sendMessage<TextureType>(this, _MTL_PRIVATE_SEL(textureType));
}

_MTL_INLINE MTL::TextureUsage MTL::Texture::usage() const
{
    return sendMessage<TextureUsage>(this, _MTL_PRIVATE_SEL(usage));
}

_MTL_INLINE NS::UInteger MTL::Texture::width() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(width));
}
