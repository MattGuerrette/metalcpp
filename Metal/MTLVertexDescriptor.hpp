//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLVertexDescriptor.hpp
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
    class VertexAttributeDescriptor;
    class VertexAttributeDescriptorArray;
    class VertexBufferLayoutDescriptor;
    class VertexBufferLayoutDescriptorArray;
    class VertexDescriptor;

    /// @see https://developer.apple.com/documentation/metal/mtlvertexformat?language=objc
    _MTL_ENUM(NS::UInteger, VertexFormat){
        VertexFormatInvalid               = 0,
        VertexFormatUChar2                = 1,
        VertexFormatUChar3                = 2,
        VertexFormatUChar4                = 3,
        VertexFormatChar2                 = 4,
        VertexFormatChar3                 = 5,
        VertexFormatChar4                 = 6,
        VertexFormatUChar2Normalized      = 7,
        VertexFormatUChar3Normalized      = 8,
        VertexFormatUChar4Normalized      = 9,
        VertexFormatChar2Normalized       = 10,
        VertexFormatChar3Normalized       = 11,
        VertexFormatChar4Normalized       = 12,
        VertexFormatUShort2               = 13,
        VertexFormatUShort3               = 14,
        VertexFormatUShort4               = 15,
        VertexFormatShort2                = 16,
        VertexFormatShort3                = 17,
        VertexFormatShort4                = 18,
        VertexFormatUShort2Normalized     = 19,
        VertexFormatUShort3Normalized     = 20,
        VertexFormatUShort4Normalized     = 21,
        VertexFormatShort2Normalized      = 22,
        VertexFormatShort3Normalized      = 23,
        VertexFormatShort4Normalized      = 24,
        VertexFormatHalf2                 = 25,
        VertexFormatHalf3                 = 26,
        VertexFormatHalf4                 = 27,
        VertexFormatFloat                 = 28,
        VertexFormatFloat2                = 29,
        VertexFormatFloat3                = 30,
        VertexFormatFloat4                = 31,
        VertexFormatInt                   = 32,
        VertexFormatInt2                  = 33,
        VertexFormatInt3                  = 34,
        VertexFormatInt4                  = 35,
        VertexFormatUInt                  = 36,
        VertexFormatUInt2                 = 37,
        VertexFormatUInt3                 = 38,
        VertexFormatUInt4                 = 39,
        VertexFormatInt1010102Normalized  = 40,
        VertexFormatUInt1010102Normalized = 41,
        VertexFormatUChar4Normalized_BGRA = 42,
        VertexFormatUChar                 = 45,
        VertexFormatChar                  = 46,
        VertexFormatUCharNormalized       = 47,
        VertexFormatCharNormalized        = 48,
        VertexFormatUShort                = 49,
        VertexFormatShort                 = 50,
        VertexFormatUShortNormalized      = 51,
        VertexFormatShortNormalized       = 52,
        VertexFormatHalf                  = 53,
        VertexFormatFloatRG11B10          = 54,
        VertexFormatFloatRGB9E5           = 55,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlvertexstepfunction?language=objc
    _MTL_ENUM(NS::UInteger, VertexStepFunction){
        VertexStepFunctionConstant             = 0,
        VertexStepFunctionPerVertex            = 1,
        VertexStepFunctionPerInstance          = 2,
        VertexStepFunctionPerPatch             = 3,
        VertexStepFunctionPerPatchControlPoint = 4,
    };

    static constexpr NS::UInteger BufferLayoutStrideDynamic = NS::UIntegerMax;

    /// @see https://developer.apple.com/documentation/metal/mtlvertexbufferlayoutdescriptor?language=objc
    class VertexBufferLayoutDescriptor : public NS::Copying<VertexBufferLayoutDescriptor>
    {
    public:
        [[nodiscard]] static VertexBufferLayoutDescriptor* alloc();

        [[nodiscard]] VertexBufferLayoutDescriptor* init();

        void setStepFunction(VertexStepFunction stepFunction) const;

        void setStepRate(NS::UInteger stepRate) const;

        void setStride(NS::UInteger stride) const;

        [[nodiscard]] VertexStepFunction stepFunction() const;

        [[nodiscard]] NS::UInteger stepRate() const;

        [[nodiscard]] NS::UInteger stride() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlvertexbufferlayoutdescriptorarray?language=objc
    class VertexBufferLayoutDescriptorArray : public NS::Referencing<VertexBufferLayoutDescriptorArray>
    {
    public:
        [[nodiscard]] static VertexBufferLayoutDescriptorArray* alloc();

        [[nodiscard]] VertexBufferLayoutDescriptorArray* init();

        [[nodiscard]] VertexBufferLayoutDescriptor* object(NS::UInteger index) const;
        void setObject(const VertexBufferLayoutDescriptor* bufferDesc, NS::UInteger index) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlvertexattributedescriptor?language=objc
    class VertexAttributeDescriptor : public NS::Copying<VertexAttributeDescriptor>
    {
    public:
        [[nodiscard]] static VertexAttributeDescriptor* alloc();

        [[nodiscard]] NS::UInteger bufferIndex() const;

        [[nodiscard]] VertexFormat format() const;

        [[nodiscard]] VertexAttributeDescriptor* init();

        [[nodiscard]] NS::UInteger offset() const;

        void setBufferIndex(NS::UInteger bufferIndex) const;

        void setFormat(VertexFormat format) const;

        void setOffset(NS::UInteger offset) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlvertexattributedescriptorarray?language=objc
    class VertexAttributeDescriptorArray : public NS::Referencing<VertexAttributeDescriptorArray>
    {
    public:
        [[nodiscard]] static VertexAttributeDescriptorArray* alloc();

        [[nodiscard]] VertexAttributeDescriptorArray* init();

        [[nodiscard]] VertexAttributeDescriptor* object(NS::UInteger index) const;
        void setObject(const VertexAttributeDescriptor* attributeDesc, NS::UInteger index) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlvertexdescriptor?language=objc
    class VertexDescriptor : public NS::Copying<VertexDescriptor>
    {
    public:
        [[nodiscard]] static VertexDescriptor* alloc();

        [[nodiscard]] VertexAttributeDescriptorArray* attributes() const;

        [[nodiscard]] VertexDescriptor* init();

        [[nodiscard]] VertexBufferLayoutDescriptorArray* layouts() const;

        void reset() const;

        [[nodiscard]] static VertexDescriptor* vertexDescriptor();
    };

} // namespace MTL

_MTL_INLINE MTL::VertexBufferLayoutDescriptor* MTL::VertexBufferLayoutDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<VertexBufferLayoutDescriptor>(_MTL_PRIVATE_CLS(MTLVertexBufferLayoutDescriptor));
}

_MTL_INLINE MTL::VertexBufferLayoutDescriptor* MTL::VertexBufferLayoutDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<VertexBufferLayoutDescriptor>();
}

_MTL_INLINE void MTL::VertexBufferLayoutDescriptor::setStepFunction(const VertexStepFunction stepFunction) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setStepFunction_), stepFunction);
}

_MTL_INLINE void MTL::VertexBufferLayoutDescriptor::setStepRate(const NS::UInteger stepRate) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setStepRate_), stepRate);
}

_MTL_INLINE void MTL::VertexBufferLayoutDescriptor::setStride(const NS::UInteger stride) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setStride_), stride);
}

_MTL_INLINE MTL::VertexStepFunction MTL::VertexBufferLayoutDescriptor::stepFunction() const
{
    return sendMessage<VertexStepFunction>(this, _MTL_PRIVATE_SEL(stepFunction));
}

_MTL_INLINE NS::UInteger MTL::VertexBufferLayoutDescriptor::stepRate() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(stepRate));
}

_MTL_INLINE NS::UInteger MTL::VertexBufferLayoutDescriptor::stride() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(stride));
}

_MTL_INLINE MTL::VertexBufferLayoutDescriptorArray* MTL::VertexBufferLayoutDescriptorArray::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<VertexBufferLayoutDescriptorArray>(_MTL_PRIVATE_CLS(MTLVertexBufferLayoutDescriptorArray));
}

_MTL_INLINE MTL::VertexBufferLayoutDescriptorArray* MTL::VertexBufferLayoutDescriptorArray::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<VertexBufferLayoutDescriptorArray>();
}

_MTL_INLINE MTL::VertexBufferLayoutDescriptor* MTL::VertexBufferLayoutDescriptorArray::object(
    const NS::UInteger index) const
{
    return sendMessage<VertexBufferLayoutDescriptor*>(this, _MTL_PRIVATE_SEL(objectAtIndexedSubscript_), index);
}

_MTL_INLINE void MTL::VertexBufferLayoutDescriptorArray::setObject(const VertexBufferLayoutDescriptor* bufferDesc,
                                                                   const NS::UInteger                  index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setObject_atIndexedSubscript_), bufferDesc, index);
}

_MTL_INLINE MTL::VertexAttributeDescriptor* MTL::VertexAttributeDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<VertexAttributeDescriptor>(_MTL_PRIVATE_CLS(MTLVertexAttributeDescriptor));
}

_MTL_INLINE NS::UInteger MTL::VertexAttributeDescriptor::bufferIndex() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(bufferIndex));
}

_MTL_INLINE MTL::VertexFormat MTL::VertexAttributeDescriptor::format() const
{
    return sendMessage<VertexFormat>(this, _MTL_PRIVATE_SEL(format));
}

_MTL_INLINE MTL::VertexAttributeDescriptor* MTL::VertexAttributeDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<VertexAttributeDescriptor>();
}

_MTL_INLINE NS::UInteger MTL::VertexAttributeDescriptor::offset() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(offset));
}

_MTL_INLINE void MTL::VertexAttributeDescriptor::setBufferIndex(const NS::UInteger bufferIndex) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBufferIndex_), bufferIndex);
}

_MTL_INLINE void MTL::VertexAttributeDescriptor::setFormat(const VertexFormat format) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFormat_), format);
}

_MTL_INLINE void MTL::VertexAttributeDescriptor::setOffset(const NS::UInteger offset) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setOffset_), offset);
}

_MTL_INLINE MTL::VertexAttributeDescriptorArray* MTL::VertexAttributeDescriptorArray::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<VertexAttributeDescriptorArray>(_MTL_PRIVATE_CLS(MTLVertexAttributeDescriptorArray));
}

_MTL_INLINE MTL::VertexAttributeDescriptorArray* MTL::VertexAttributeDescriptorArray::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<VertexAttributeDescriptorArray>();
}

_MTL_INLINE MTL::VertexAttributeDescriptor* MTL::VertexAttributeDescriptorArray::object(const NS::UInteger index) const
{
    return sendMessage<VertexAttributeDescriptor*>(this, _MTL_PRIVATE_SEL(objectAtIndexedSubscript_), index);
}

_MTL_INLINE void MTL::VertexAttributeDescriptorArray::setObject(const VertexAttributeDescriptor* attributeDesc,
                                                                const NS::UInteger               index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setObject_atIndexedSubscript_), attributeDesc, index);
}

_MTL_INLINE MTL::VertexDescriptor* MTL::VertexDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<VertexDescriptor>(_MTL_PRIVATE_CLS(MTLVertexDescriptor));
}

_MTL_INLINE MTL::VertexAttributeDescriptorArray* MTL::VertexDescriptor::attributes() const
{
    return sendMessage<VertexAttributeDescriptorArray*>(this, _MTL_PRIVATE_SEL(attributes));
}

_MTL_INLINE MTL::VertexDescriptor* MTL::VertexDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<VertexDescriptor>();
}

_MTL_INLINE MTL::VertexBufferLayoutDescriptorArray* MTL::VertexDescriptor::layouts() const
{
    return sendMessage<VertexBufferLayoutDescriptorArray*>(this, _MTL_PRIVATE_SEL(layouts));
}

_MTL_INLINE void MTL::VertexDescriptor::reset() const { sendMessage<void>(this, _MTL_PRIVATE_SEL(reset)); }

_MTL_INLINE MTL::VertexDescriptor* MTL::VertexDescriptor::vertexDescriptor()
{
    return sendMessage<VertexDescriptor*>(_MTL_PRIVATE_CLS(MTLVertexDescriptor), _MTL_PRIVATE_SEL(vertexDescriptor));
}
