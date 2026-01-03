//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLRenderPass.hpp
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

namespace MTL
{
    class Buffer;
    class CounterSampleBuffer;
    class RasterizationRateMap;
    class RenderPassAttachmentDescriptor;
    class RenderPassColorAttachmentDescriptor;
    class RenderPassColorAttachmentDescriptorArray;
    class RenderPassDepthAttachmentDescriptor;
    class RenderPassDescriptor;
    class RenderPassSampleBufferAttachmentDescriptor;
    class RenderPassSampleBufferAttachmentDescriptorArray;
    class RenderPassStencilAttachmentDescriptor;
    struct SamplePosition;
    class Texture;

    /// @see https://developer.apple.com/documentation/metal/mtlloadaction?language=objc
    _MTL_ENUM(NS::UInteger, LoadAction){
        LoadActionDontCare = 0,
        LoadActionLoad     = 1,
        LoadActionClear    = 2,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlstoreaction?language=objc
    _MTL_ENUM(NS::UInteger, StoreAction){
        StoreActionDontCare                   = 0,
        StoreActionStore                      = 1,
        StoreActionMultisampleResolve         = 2,
        StoreActionStoreAndMultisampleResolve = 3,
        StoreActionUnknown                    = 4,
        StoreActionCustomSampleDepthStore     = 5,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlvisibilityresulttype?language=objc
    _MTL_ENUM(NS::Integer, VisibilityResultType){
        VisibilityResultTypeReset      = 0,
        VisibilityResultTypeAccumulate = 1,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlmultisampledepthresolvefilter?language=objc
    _MTL_ENUM(NS::UInteger, MultisampleDepthResolveFilter){
        MultisampleDepthResolveFilterSample0 = 0,
        MultisampleDepthResolveFilterMin     = 1,
        MultisampleDepthResolveFilterMax     = 2,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlmultisamplestencilresolvefilter?language=objc
    _MTL_ENUM(NS::UInteger, MultisampleStencilResolveFilter){
        MultisampleStencilResolveFilterSample0             = 0,
        MultisampleStencilResolveFilterDepthResolvedSample = 1,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlstoreactionoptions?language=objc
    _MTL_OPTIONS(NS::UInteger, StoreActionOptions){
        StoreActionOptionNone                  = 0,
        StoreActionOptionCustomSamplePositions = 1,
        StoreActionOptionValidMask             = 1,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlclearcolor?language=objc
    struct ClearColor
    {
        ClearColor() = default;

        ClearColor(double red, double green, double blue, double alpha);

        static ClearColor Make(double red, double green, double blue, double alpha);

        double red;
        double green;
        double blue;
        double alpha;
    } _MTL_PACKED;

    /// @see https://developer.apple.com/documentation/metal/mtlrenderpassattachmentdescriptor?language=objc
    class RenderPassAttachmentDescriptor : public NS::Copying<RenderPassAttachmentDescriptor>
    {
    public:
        [[nodiscard]] static RenderPassAttachmentDescriptor* alloc();

        [[nodiscard]] NS::UInteger depthPlane() const;

        [[nodiscard]] RenderPassAttachmentDescriptor* init();

        [[nodiscard]] NS::UInteger level() const;

        [[nodiscard]] LoadAction loadAction() const;

        [[nodiscard]] NS::UInteger resolveDepthPlane() const;

        [[nodiscard]] NS::UInteger resolveLevel() const;

        [[nodiscard]] NS::UInteger resolveSlice() const;

        [[nodiscard]] Texture* resolveTexture() const;

        void setDepthPlane(NS::UInteger depthPlane) const;

        void setLevel(NS::UInteger level) const;

        void setLoadAction(LoadAction loadAction) const;

        void setResolveDepthPlane(NS::UInteger resolveDepthPlane) const;

        void setResolveLevel(NS::UInteger resolveLevel) const;

        void setResolveSlice(NS::UInteger resolveSlice) const;

        void setResolveTexture(const Texture* resolveTexture) const;

        void setSlice(NS::UInteger slice) const;

        void setStoreAction(StoreAction storeAction) const;
        void setStoreActionOptions(StoreActionOptions storeActionOptions) const;

        void setTexture(const Texture* texture) const;

        [[nodiscard]] NS::UInteger slice() const;

        [[nodiscard]] StoreAction        storeAction() const;
        [[nodiscard]] StoreActionOptions storeActionOptions() const;

        [[nodiscard]] Texture* texture() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlrenderpasscolorattachmentdescriptor?language=objc
    class RenderPassColorAttachmentDescriptor
        : public NS::Copying<RenderPassColorAttachmentDescriptor, RenderPassAttachmentDescriptor>
    {
    public:
        [[nodiscard]] static RenderPassColorAttachmentDescriptor* alloc();

        [[nodiscard]] ClearColor clearColor() const;

        [[nodiscard]] RenderPassColorAttachmentDescriptor* init();

        void setClearColor(const ClearColor& clearColor) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlrenderpassdepthattachmentdescriptor?language=objc
    class RenderPassDepthAttachmentDescriptor
        : public NS::Copying<RenderPassDepthAttachmentDescriptor, RenderPassAttachmentDescriptor>
    {
    public:
        [[nodiscard]] static RenderPassDepthAttachmentDescriptor* alloc();

        [[nodiscard]] double clearDepth() const;

        [[nodiscard]] MultisampleDepthResolveFilter depthResolveFilter() const;

        [[nodiscard]] RenderPassDepthAttachmentDescriptor* init();

        void setClearDepth(double clearDepth) const;

        void setDepthResolveFilter(MultisampleDepthResolveFilter depthResolveFilter) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlrenderpassstencilattachmentdescriptor?language=objc
    class RenderPassStencilAttachmentDescriptor
        : public NS::Copying<RenderPassStencilAttachmentDescriptor, RenderPassAttachmentDescriptor>
    {
    public:
        [[nodiscard]] static RenderPassStencilAttachmentDescriptor* alloc();

        [[nodiscard]] uint32_t clearStencil() const;

        [[nodiscard]] RenderPassStencilAttachmentDescriptor* init();

        void setClearStencil(uint32_t clearStencil) const;

        void setStencilResolveFilter(MultisampleStencilResolveFilter stencilResolveFilter) const;
        [[nodiscard]] MultisampleStencilResolveFilter stencilResolveFilter() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlrenderpasscolorattachmentdescriptorarray?language=objc
    class RenderPassColorAttachmentDescriptorArray : public NS::Referencing<RenderPassColorAttachmentDescriptorArray>
    {
    public:
        [[nodiscard]] static RenderPassColorAttachmentDescriptorArray* alloc();

        [[nodiscard]] RenderPassColorAttachmentDescriptorArray* init();

        [[nodiscard]] RenderPassColorAttachmentDescriptor* object(NS::UInteger attachmentIndex) const;
        void setObject(const RenderPassColorAttachmentDescriptor* attachment, NS::UInteger attachmentIndex) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlrenderpasssamplebufferattachmentdescriptor?language=objc
    class RenderPassSampleBufferAttachmentDescriptor : public NS::Copying<RenderPassSampleBufferAttachmentDescriptor>
    {
    public:
        [[nodiscard]] static RenderPassSampleBufferAttachmentDescriptor* alloc();

        [[nodiscard]] NS::UInteger endOfFragmentSampleIndex() const;

        [[nodiscard]] NS::UInteger endOfVertexSampleIndex() const;

        [[nodiscard]] RenderPassSampleBufferAttachmentDescriptor* init();

        [[nodiscard]] CounterSampleBuffer* sampleBuffer() const;

        void setEndOfFragmentSampleIndex(NS::UInteger endOfFragmentSampleIndex) const;

        void setEndOfVertexSampleIndex(NS::UInteger endOfVertexSampleIndex) const;

        void setSampleBuffer(const CounterSampleBuffer* sampleBuffer) const;

        void setStartOfFragmentSampleIndex(NS::UInteger startOfFragmentSampleIndex) const;

        void setStartOfVertexSampleIndex(NS::UInteger startOfVertexSampleIndex) const;

        [[nodiscard]] NS::UInteger startOfFragmentSampleIndex() const;

        [[nodiscard]] NS::UInteger startOfVertexSampleIndex() const;
    };

    /// @see
    /// https://developer.apple.com/documentation/metal/mtlrenderpasssamplebufferattachmentdescriptorarray?language=objc
    class RenderPassSampleBufferAttachmentDescriptorArray
        : public NS::Referencing<RenderPassSampleBufferAttachmentDescriptorArray>
    {
    public:
        [[nodiscard]] static RenderPassSampleBufferAttachmentDescriptorArray* alloc();

        [[nodiscard]] RenderPassSampleBufferAttachmentDescriptorArray* init();

        [[nodiscard]] RenderPassSampleBufferAttachmentDescriptor* object(NS::UInteger attachmentIndex) const;
        void setObject(const RenderPassSampleBufferAttachmentDescriptor* attachment,
                       NS::UInteger                                      attachmentIndex) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlrenderpassdescriptor?language=objc
    class RenderPassDescriptor : public NS::Copying<RenderPassDescriptor>
    {
    public:
        [[nodiscard]] static RenderPassDescriptor* alloc();

        [[nodiscard]] RenderPassColorAttachmentDescriptorArray* colorAttachments() const;

        [[nodiscard]] NS::UInteger defaultRasterSampleCount() const;

        [[nodiscard]] RenderPassDepthAttachmentDescriptor* depthAttachment() const;

        [[nodiscard]] NS::UInteger getSamplePositions(SamplePosition* positions, NS::UInteger count) const;

        [[nodiscard]] NS::UInteger imageblockSampleLength() const;

        [[nodiscard]] RenderPassDescriptor* init();

        [[nodiscard]] RasterizationRateMap* rasterizationRateMap() const;

        [[nodiscard]] static RenderPassDescriptor* renderPassDescriptor();

        [[nodiscard]] NS::UInteger renderTargetArrayLength() const;

        [[nodiscard]] NS::UInteger renderTargetHeight() const;

        [[nodiscard]] NS::UInteger renderTargetWidth() const;

        [[nodiscard]] RenderPassSampleBufferAttachmentDescriptorArray* sampleBufferAttachments() const;

        void setDefaultRasterSampleCount(NS::UInteger defaultRasterSampleCount) const;

        void setDepthAttachment(const RenderPassDepthAttachmentDescriptor* depthAttachment) const;

        void setImageblockSampleLength(NS::UInteger imageblockSampleLength) const;

        void setRasterizationRateMap(const RasterizationRateMap* rasterizationRateMap) const;

        void setRenderTargetArrayLength(NS::UInteger renderTargetArrayLength) const;

        void setRenderTargetHeight(NS::UInteger renderTargetHeight) const;

        void setRenderTargetWidth(NS::UInteger renderTargetWidth) const;

        void setSamplePositions(const SamplePosition* positions, NS::UInteger count) const;

        void setStencilAttachment(const RenderPassStencilAttachmentDescriptor* stencilAttachment) const;

        void setSupportColorAttachmentMapping(bool supportColorAttachmentMapping) const;

        void setThreadgroupMemoryLength(NS::UInteger threadgroupMemoryLength) const;

        void setTileHeight(NS::UInteger tileHeight) const;

        void setTileWidth(NS::UInteger tileWidth) const;

        void setVisibilityResultBuffer(const Buffer* visibilityResultBuffer) const;

        void setVisibilityResultType(VisibilityResultType visibilityResultType) const;

        [[nodiscard]] RenderPassStencilAttachmentDescriptor* stencilAttachment() const;

        [[nodiscard]] bool supportColorAttachmentMapping() const;

        [[nodiscard]] NS::UInteger threadgroupMemoryLength() const;

        [[nodiscard]] NS::UInteger tileHeight() const;

        [[nodiscard]] NS::UInteger tileWidth() const;

        [[nodiscard]] Buffer* visibilityResultBuffer() const;

        [[nodiscard]] VisibilityResultType visibilityResultType() const;
    };

} // namespace MTL
_MTL_INLINE MTL::ClearColor::ClearColor(const double red, const double green, const double blue, const double alpha)
    : red(red), green(green), blue(blue), alpha(alpha)
{
}

_MTL_INLINE MTL::ClearColor MTL::ClearColor::Make(const double red,
                                                  const double green,
                                                  const double blue,
                                                  const double alpha)
{
    return { red, green, blue, alpha };
}

_MTL_INLINE MTL::RenderPassAttachmentDescriptor* MTL::RenderPassAttachmentDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<RenderPassAttachmentDescriptor>(_MTL_PRIVATE_CLS(MTLRenderPassAttachmentDescriptor));
}

_MTL_INLINE NS::UInteger MTL::RenderPassAttachmentDescriptor::depthPlane() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(depthPlane));
}

_MTL_INLINE MTL::RenderPassAttachmentDescriptor* MTL::RenderPassAttachmentDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<RenderPassAttachmentDescriptor>();
}

_MTL_INLINE NS::UInteger MTL::RenderPassAttachmentDescriptor::level() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(level));
}

_MTL_INLINE MTL::LoadAction MTL::RenderPassAttachmentDescriptor::loadAction() const
{
    return sendMessage<LoadAction>(this, _MTL_PRIVATE_SEL(loadAction));
}

_MTL_INLINE NS::UInteger MTL::RenderPassAttachmentDescriptor::resolveDepthPlane() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(resolveDepthPlane));
}

_MTL_INLINE NS::UInteger MTL::RenderPassAttachmentDescriptor::resolveLevel() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(resolveLevel));
}

_MTL_INLINE NS::UInteger MTL::RenderPassAttachmentDescriptor::resolveSlice() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(resolveSlice));
}

_MTL_INLINE MTL::Texture* MTL::RenderPassAttachmentDescriptor::resolveTexture() const
{
    return sendMessage<Texture*>(this, _MTL_PRIVATE_SEL(resolveTexture));
}

_MTL_INLINE void MTL::RenderPassAttachmentDescriptor::setDepthPlane(const NS::UInteger depthPlane) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDepthPlane_), depthPlane);
}

_MTL_INLINE void MTL::RenderPassAttachmentDescriptor::setLevel(const NS::UInteger level) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLevel_), level);
}

_MTL_INLINE void MTL::RenderPassAttachmentDescriptor::setLoadAction(const LoadAction loadAction) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLoadAction_), loadAction);
}

_MTL_INLINE void MTL::RenderPassAttachmentDescriptor::setResolveDepthPlane(const NS::UInteger resolveDepthPlane) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setResolveDepthPlane_), resolveDepthPlane);
}

_MTL_INLINE void MTL::RenderPassAttachmentDescriptor::setResolveLevel(const NS::UInteger resolveLevel) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setResolveLevel_), resolveLevel);
}

_MTL_INLINE void MTL::RenderPassAttachmentDescriptor::setResolveSlice(const NS::UInteger resolveSlice) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setResolveSlice_), resolveSlice);
}

_MTL_INLINE void MTL::RenderPassAttachmentDescriptor::setResolveTexture(const Texture* resolveTexture) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setResolveTexture_), resolveTexture);
}

_MTL_INLINE void MTL::RenderPassAttachmentDescriptor::setSlice(const NS::UInteger slice) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSlice_), slice);
}

_MTL_INLINE void MTL::RenderPassAttachmentDescriptor::setStoreAction(const StoreAction storeAction) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setStoreAction_), storeAction);
}

_MTL_INLINE void MTL::RenderPassAttachmentDescriptor::setStoreActionOptions(
    const StoreActionOptions storeActionOptions) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setStoreActionOptions_), storeActionOptions);
}

_MTL_INLINE void MTL::RenderPassAttachmentDescriptor::setTexture(const Texture* texture) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTexture_), texture);
}

_MTL_INLINE NS::UInteger MTL::RenderPassAttachmentDescriptor::slice() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(slice));
}

_MTL_INLINE MTL::StoreAction MTL::RenderPassAttachmentDescriptor::storeAction() const
{
    return sendMessage<StoreAction>(this, _MTL_PRIVATE_SEL(storeAction));
}

_MTL_INLINE MTL::StoreActionOptions MTL::RenderPassAttachmentDescriptor::storeActionOptions() const
{
    return sendMessage<StoreActionOptions>(this, _MTL_PRIVATE_SEL(storeActionOptions));
}

_MTL_INLINE MTL::Texture* MTL::RenderPassAttachmentDescriptor::texture() const
{
    return sendMessage<Texture*>(this, _MTL_PRIVATE_SEL(texture));
}

_MTL_INLINE MTL::RenderPassColorAttachmentDescriptor* MTL::RenderPassColorAttachmentDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<RenderPassColorAttachmentDescriptor>(
        _MTL_PRIVATE_CLS(MTLRenderPassColorAttachmentDescriptor));
}

_MTL_INLINE MTL::ClearColor MTL::RenderPassColorAttachmentDescriptor::clearColor() const
{
    return sendMessage<ClearColor>(this, _MTL_PRIVATE_SEL(clearColor));
}

_MTL_INLINE MTL::RenderPassColorAttachmentDescriptor* MTL::RenderPassColorAttachmentDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<RenderPassColorAttachmentDescriptor>();
}

_MTL_INLINE void MTL::RenderPassColorAttachmentDescriptor::setClearColor(const ClearColor& clearColor) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setClearColor_), clearColor);
}

_MTL_INLINE MTL::RenderPassDepthAttachmentDescriptor* MTL::RenderPassDepthAttachmentDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<RenderPassDepthAttachmentDescriptor>(
        _MTL_PRIVATE_CLS(MTLRenderPassDepthAttachmentDescriptor));
}

_MTL_INLINE double MTL::RenderPassDepthAttachmentDescriptor::clearDepth() const
{
    return sendMessage<double>(this, _MTL_PRIVATE_SEL(clearDepth));
}

_MTL_INLINE MTL::MultisampleDepthResolveFilter MTL::RenderPassDepthAttachmentDescriptor::depthResolveFilter() const
{
    return sendMessage<MultisampleDepthResolveFilter>(this, _MTL_PRIVATE_SEL(depthResolveFilter));
}

_MTL_INLINE MTL::RenderPassDepthAttachmentDescriptor* MTL::RenderPassDepthAttachmentDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<RenderPassDepthAttachmentDescriptor>();
}

_MTL_INLINE void MTL::RenderPassDepthAttachmentDescriptor::setClearDepth(const double clearDepth) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setClearDepth_), clearDepth);
}

_MTL_INLINE void MTL::RenderPassDepthAttachmentDescriptor::setDepthResolveFilter(
    const MultisampleDepthResolveFilter depthResolveFilter) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDepthResolveFilter_), depthResolveFilter);
}

_MTL_INLINE MTL::RenderPassStencilAttachmentDescriptor* MTL::RenderPassStencilAttachmentDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<RenderPassStencilAttachmentDescriptor>(
        _MTL_PRIVATE_CLS(MTLRenderPassStencilAttachmentDescriptor));
}

_MTL_INLINE uint32_t MTL::RenderPassStencilAttachmentDescriptor::clearStencil() const
{
    return sendMessage<uint32_t>(this, _MTL_PRIVATE_SEL(clearStencil));
}

_MTL_INLINE MTL::RenderPassStencilAttachmentDescriptor* MTL::RenderPassStencilAttachmentDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<RenderPassStencilAttachmentDescriptor>();
}

_MTL_INLINE void MTL::RenderPassStencilAttachmentDescriptor::setClearStencil(const uint32_t clearStencil) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setClearStencil_), clearStencil);
}

_MTL_INLINE void MTL::RenderPassStencilAttachmentDescriptor::setStencilResolveFilter(
    const MultisampleStencilResolveFilter stencilResolveFilter) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setStencilResolveFilter_), stencilResolveFilter);
}

_MTL_INLINE MTL::MultisampleStencilResolveFilter MTL::RenderPassStencilAttachmentDescriptor::stencilResolveFilter()
    const
{
    return sendMessage<MultisampleStencilResolveFilter>(this, _MTL_PRIVATE_SEL(stencilResolveFilter));
}

_MTL_INLINE MTL::RenderPassColorAttachmentDescriptorArray* MTL::RenderPassColorAttachmentDescriptorArray::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<RenderPassColorAttachmentDescriptorArray>(
        _MTL_PRIVATE_CLS(MTLRenderPassColorAttachmentDescriptorArray));
}

_MTL_INLINE MTL::RenderPassColorAttachmentDescriptorArray* MTL::RenderPassColorAttachmentDescriptorArray::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<RenderPassColorAttachmentDescriptorArray>();
}

_MTL_INLINE MTL::RenderPassColorAttachmentDescriptor* MTL::RenderPassColorAttachmentDescriptorArray::object(
    const NS::UInteger attachmentIndex) const
{
    return sendMessage<RenderPassColorAttachmentDescriptor*>(
        this, _MTL_PRIVATE_SEL(objectAtIndexedSubscript_), attachmentIndex);
}

_MTL_INLINE void MTL::RenderPassColorAttachmentDescriptorArray::setObject(
    const RenderPassColorAttachmentDescriptor* attachment, const NS::UInteger attachmentIndex) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setObject_atIndexedSubscript_), attachment, attachmentIndex);
}

_MTL_INLINE MTL::RenderPassSampleBufferAttachmentDescriptor* MTL::RenderPassSampleBufferAttachmentDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<RenderPassSampleBufferAttachmentDescriptor>(
        _MTL_PRIVATE_CLS(MTLRenderPassSampleBufferAttachmentDescriptor));
}

_MTL_INLINE NS::UInteger MTL::RenderPassSampleBufferAttachmentDescriptor::endOfFragmentSampleIndex() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(endOfFragmentSampleIndex));
}

_MTL_INLINE NS::UInteger MTL::RenderPassSampleBufferAttachmentDescriptor::endOfVertexSampleIndex() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(endOfVertexSampleIndex));
}

_MTL_INLINE MTL::RenderPassSampleBufferAttachmentDescriptor* MTL::RenderPassSampleBufferAttachmentDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<RenderPassSampleBufferAttachmentDescriptor>();
}

_MTL_INLINE MTL::CounterSampleBuffer* MTL::RenderPassSampleBufferAttachmentDescriptor::sampleBuffer() const
{
    return sendMessage<CounterSampleBuffer*>(this, _MTL_PRIVATE_SEL(sampleBuffer));
}

_MTL_INLINE void MTL::RenderPassSampleBufferAttachmentDescriptor::setEndOfFragmentSampleIndex(
    const NS::UInteger endOfFragmentSampleIndex) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setEndOfFragmentSampleIndex_), endOfFragmentSampleIndex);
}

_MTL_INLINE void MTL::RenderPassSampleBufferAttachmentDescriptor::setEndOfVertexSampleIndex(
    const NS::UInteger endOfVertexSampleIndex) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setEndOfVertexSampleIndex_), endOfVertexSampleIndex);
}

_MTL_INLINE void MTL::RenderPassSampleBufferAttachmentDescriptor::setSampleBuffer(
    const CounterSampleBuffer* sampleBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSampleBuffer_), sampleBuffer);
}

_MTL_INLINE void MTL::RenderPassSampleBufferAttachmentDescriptor::setStartOfFragmentSampleIndex(
    const NS::UInteger startOfFragmentSampleIndex) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setStartOfFragmentSampleIndex_), startOfFragmentSampleIndex);
}

_MTL_INLINE void MTL::RenderPassSampleBufferAttachmentDescriptor::setStartOfVertexSampleIndex(
    const NS::UInteger startOfVertexSampleIndex) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setStartOfVertexSampleIndex_), startOfVertexSampleIndex);
}

_MTL_INLINE NS::UInteger MTL::RenderPassSampleBufferAttachmentDescriptor::startOfFragmentSampleIndex() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(startOfFragmentSampleIndex));
}

_MTL_INLINE NS::UInteger MTL::RenderPassSampleBufferAttachmentDescriptor::startOfVertexSampleIndex() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(startOfVertexSampleIndex));
}

_MTL_INLINE MTL::RenderPassSampleBufferAttachmentDescriptorArray*
            MTL::RenderPassSampleBufferAttachmentDescriptorArray::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<RenderPassSampleBufferAttachmentDescriptorArray>(
        _MTL_PRIVATE_CLS(MTLRenderPassSampleBufferAttachmentDescriptorArray));
}

_MTL_INLINE MTL::RenderPassSampleBufferAttachmentDescriptorArray*
            MTL::RenderPassSampleBufferAttachmentDescriptorArray::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<RenderPassSampleBufferAttachmentDescriptorArray>();
}

_MTL_INLINE MTL::RenderPassSampleBufferAttachmentDescriptor*
            MTL::RenderPassSampleBufferAttachmentDescriptorArray::object(const NS::UInteger attachmentIndex) const
{
    return sendMessage<RenderPassSampleBufferAttachmentDescriptor*>(
        this, _MTL_PRIVATE_SEL(objectAtIndexedSubscript_), attachmentIndex);
}

_MTL_INLINE void MTL::RenderPassSampleBufferAttachmentDescriptorArray::setObject(
    const RenderPassSampleBufferAttachmentDescriptor* attachment, const NS::UInteger attachmentIndex) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setObject_atIndexedSubscript_), attachment, attachmentIndex);
}

_MTL_INLINE MTL::RenderPassDescriptor* MTL::RenderPassDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<RenderPassDescriptor>(_MTL_PRIVATE_CLS(MTLRenderPassDescriptor));
}

_MTL_INLINE MTL::RenderPassColorAttachmentDescriptorArray* MTL::RenderPassDescriptor::colorAttachments() const
{
    return sendMessage<RenderPassColorAttachmentDescriptorArray*>(this, _MTL_PRIVATE_SEL(colorAttachments));
}

_MTL_INLINE NS::UInteger MTL::RenderPassDescriptor::defaultRasterSampleCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(defaultRasterSampleCount));
}

_MTL_INLINE MTL::RenderPassDepthAttachmentDescriptor* MTL::RenderPassDescriptor::depthAttachment() const
{
    return sendMessage<RenderPassDepthAttachmentDescriptor*>(this, _MTL_PRIVATE_SEL(depthAttachment));
}

_MTL_INLINE NS::UInteger MTL::RenderPassDescriptor::getSamplePositions(SamplePosition*    positions,
                                                                       const NS::UInteger count) const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(getSamplePositions_count_), positions, count);
}

_MTL_INLINE NS::UInteger MTL::RenderPassDescriptor::imageblockSampleLength() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(imageblockSampleLength));
}

_MTL_INLINE MTL::RenderPassDescriptor* MTL::RenderPassDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<RenderPassDescriptor>();
}

_MTL_INLINE MTL::RasterizationRateMap* MTL::RenderPassDescriptor::rasterizationRateMap() const
{
    return sendMessage<RasterizationRateMap*>(this, _MTL_PRIVATE_SEL(rasterizationRateMap));
}

_MTL_INLINE MTL::RenderPassDescriptor* MTL::RenderPassDescriptor::renderPassDescriptor()
{
    return sendMessage<RenderPassDescriptor*>(_MTL_PRIVATE_CLS(MTLRenderPassDescriptor),
                                              _MTL_PRIVATE_SEL(renderPassDescriptor));
}

_MTL_INLINE NS::UInteger MTL::RenderPassDescriptor::renderTargetArrayLength() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(renderTargetArrayLength));
}

_MTL_INLINE NS::UInteger MTL::RenderPassDescriptor::renderTargetHeight() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(renderTargetHeight));
}

_MTL_INLINE NS::UInteger MTL::RenderPassDescriptor::renderTargetWidth() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(renderTargetWidth));
}

_MTL_INLINE MTL::RenderPassSampleBufferAttachmentDescriptorArray* MTL::RenderPassDescriptor::sampleBufferAttachments()
    const
{
    return sendMessage<RenderPassSampleBufferAttachmentDescriptorArray*>(this,
                                                                         _MTL_PRIVATE_SEL(sampleBufferAttachments));
}

_MTL_INLINE void MTL::RenderPassDescriptor::setDefaultRasterSampleCount(
    const NS::UInteger defaultRasterSampleCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDefaultRasterSampleCount_), defaultRasterSampleCount);
}

_MTL_INLINE void MTL::RenderPassDescriptor::setDepthAttachment(
    const RenderPassDepthAttachmentDescriptor* depthAttachment) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDepthAttachment_), depthAttachment);
}

_MTL_INLINE void MTL::RenderPassDescriptor::setImageblockSampleLength(const NS::UInteger imageblockSampleLength) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setImageblockSampleLength_), imageblockSampleLength);
}

_MTL_INLINE void MTL::RenderPassDescriptor::setRasterizationRateMap(
    const RasterizationRateMap* rasterizationRateMap) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRasterizationRateMap_), rasterizationRateMap);
}

_MTL_INLINE void MTL::RenderPassDescriptor::setRenderTargetArrayLength(const NS::UInteger renderTargetArrayLength) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRenderTargetArrayLength_), renderTargetArrayLength);
}

_MTL_INLINE void MTL::RenderPassDescriptor::setRenderTargetHeight(const NS::UInteger renderTargetHeight) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRenderTargetHeight_), renderTargetHeight);
}

_MTL_INLINE void MTL::RenderPassDescriptor::setRenderTargetWidth(const NS::UInteger renderTargetWidth) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRenderTargetWidth_), renderTargetWidth);
}

_MTL_INLINE void MTL::RenderPassDescriptor::setSamplePositions(const SamplePosition* positions,
                                                               const NS::UInteger    count) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSamplePositions_count_), positions, count);
}

_MTL_INLINE void MTL::RenderPassDescriptor::setStencilAttachment(
    const RenderPassStencilAttachmentDescriptor* stencilAttachment) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setStencilAttachment_), stencilAttachment);
}

_MTL_INLINE void MTL::RenderPassDescriptor::setSupportColorAttachmentMapping(
    const bool supportColorAttachmentMapping) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSupportColorAttachmentMapping_), supportColorAttachmentMapping);
}

_MTL_INLINE void MTL::RenderPassDescriptor::setThreadgroupMemoryLength(const NS::UInteger threadgroupMemoryLength) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setThreadgroupMemoryLength_), threadgroupMemoryLength);
}

_MTL_INLINE void MTL::RenderPassDescriptor::setTileHeight(const NS::UInteger tileHeight) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTileHeight_), tileHeight);
}

_MTL_INLINE void MTL::RenderPassDescriptor::setTileWidth(const NS::UInteger tileWidth) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTileWidth_), tileWidth);
}

_MTL_INLINE void MTL::RenderPassDescriptor::setVisibilityResultBuffer(const Buffer* visibilityResultBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVisibilityResultBuffer_), visibilityResultBuffer);
}

_MTL_INLINE void MTL::RenderPassDescriptor::setVisibilityResultType(
    const VisibilityResultType visibilityResultType) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVisibilityResultType_), visibilityResultType);
}

_MTL_INLINE MTL::RenderPassStencilAttachmentDescriptor* MTL::RenderPassDescriptor::stencilAttachment() const
{
    return sendMessage<RenderPassStencilAttachmentDescriptor*>(this, _MTL_PRIVATE_SEL(stencilAttachment));
}

_MTL_INLINE bool MTL::RenderPassDescriptor::supportColorAttachmentMapping() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supportColorAttachmentMapping));
}

_MTL_INLINE NS::UInteger MTL::RenderPassDescriptor::threadgroupMemoryLength() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(threadgroupMemoryLength));
}

_MTL_INLINE NS::UInteger MTL::RenderPassDescriptor::tileHeight() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(tileHeight));
}

_MTL_INLINE NS::UInteger MTL::RenderPassDescriptor::tileWidth() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(tileWidth));
}

_MTL_INLINE MTL::Buffer* MTL::RenderPassDescriptor::visibilityResultBuffer() const
{
    return sendMessage<Buffer*>(this, _MTL_PRIVATE_SEL(visibilityResultBuffer));
}

_MTL_INLINE MTL::VisibilityResultType MTL::RenderPassDescriptor::visibilityResultType() const
{
    return sendMessage<VisibilityResultType>(this, _MTL_PRIVATE_SEL(visibilityResultType));
}
