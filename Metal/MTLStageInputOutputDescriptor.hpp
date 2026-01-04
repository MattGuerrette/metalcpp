//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLStageInputOutputDescriptor.hpp
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
#include "MTLArgument.hpp"
#include "MTLDefines.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"

namespace MTL
{
    class AttributeDescriptor;
    class AttributeDescriptorArray;
    class BufferLayoutDescriptor;
    class BufferLayoutDescriptorArray;
    class StageInputOutputDescriptor;

    /// @see https://developer.apple.com/documentation/metal/mtlattributeformat?language=objc
    _MTL_ENUM(NS::UInteger, AttributeFormat){
        AttributeFormatInvalid               = 0,
        AttributeFormatUChar2                = 1,
        AttributeFormatUChar3                = 2,
        AttributeFormatUChar4                = 3,
        AttributeFormatChar2                 = 4,
        AttributeFormatChar3                 = 5,
        AttributeFormatChar4                 = 6,
        AttributeFormatUChar2Normalized      = 7,
        AttributeFormatUChar3Normalized      = 8,
        AttributeFormatUChar4Normalized      = 9,
        AttributeFormatChar2Normalized       = 10,
        AttributeFormatChar3Normalized       = 11,
        AttributeFormatChar4Normalized       = 12,
        AttributeFormatUShort2               = 13,
        AttributeFormatUShort3               = 14,
        AttributeFormatUShort4               = 15,
        AttributeFormatShort2                = 16,
        AttributeFormatShort3                = 17,
        AttributeFormatShort4                = 18,
        AttributeFormatUShort2Normalized     = 19,
        AttributeFormatUShort3Normalized     = 20,
        AttributeFormatUShort4Normalized     = 21,
        AttributeFormatShort2Normalized      = 22,
        AttributeFormatShort3Normalized      = 23,
        AttributeFormatShort4Normalized      = 24,
        AttributeFormatHalf2                 = 25,
        AttributeFormatHalf3                 = 26,
        AttributeFormatHalf4                 = 27,
        AttributeFormatFloat                 = 28,
        AttributeFormatFloat2                = 29,
        AttributeFormatFloat3                = 30,
        AttributeFormatFloat4                = 31,
        AttributeFormatInt                   = 32,
        AttributeFormatInt2                  = 33,
        AttributeFormatInt3                  = 34,
        AttributeFormatInt4                  = 35,
        AttributeFormatUInt                  = 36,
        AttributeFormatUInt2                 = 37,
        AttributeFormatUInt3                 = 38,
        AttributeFormatUInt4                 = 39,
        AttributeFormatInt1010102Normalized  = 40,
        AttributeFormatUInt1010102Normalized = 41,
        AttributeFormatUChar4Normalized_BGRA = 42,
        AttributeFormatUChar                 = 45,
        AttributeFormatChar                  = 46,
        AttributeFormatUCharNormalized       = 47,
        AttributeFormatCharNormalized        = 48,
        AttributeFormatUShort                = 49,
        AttributeFormatShort                 = 50,
        AttributeFormatUShortNormalized      = 51,
        AttributeFormatShortNormalized       = 52,
        AttributeFormatHalf                  = 53,
        AttributeFormatFloatRG11B10          = 54,
        AttributeFormatFloatRGB9E5           = 55,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlstepfunction?language=objc
    _MTL_ENUM(NS::UInteger, StepFunction){
        StepFunctionConstant                     = 0,
        StepFunctionPerVertex                    = 1,
        StepFunctionPerInstance                  = 2,
        StepFunctionPerPatch                     = 3,
        StepFunctionPerPatchControlPoint         = 4,
        StepFunctionThreadPositionInGridX        = 5,
        StepFunctionThreadPositionInGridY        = 6,
        StepFunctionThreadPositionInGridXIndexed = 7,
        StepFunctionThreadPositionInGridYIndexed = 8,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlbufferlayoutdescriptor?language=objc
    class BufferLayoutDescriptor : public NS::Copying<BufferLayoutDescriptor>
    {
    public:
        [[nodiscard]] static BufferLayoutDescriptor* alloc();

        [[nodiscard]] BufferLayoutDescriptor* init();

        void setStepFunction(StepFunction stepFunction) const;

        void setStepRate(NS::UInteger stepRate) const;

        void setStride(NS::UInteger stride) const;

        [[nodiscard]] StepFunction stepFunction() const;

        [[nodiscard]] NS::UInteger stepRate() const;

        [[nodiscard]] NS::UInteger stride() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlbufferlayoutdescriptorarray?language=objc
    class BufferLayoutDescriptorArray : public NS::Referencing<BufferLayoutDescriptorArray>
    {
    public:
        [[nodiscard]] static BufferLayoutDescriptorArray* alloc();

        [[nodiscard]] BufferLayoutDescriptorArray* init();

        [[nodiscard]] BufferLayoutDescriptor* object(NS::UInteger index) const;
        void setObject(const BufferLayoutDescriptor* bufferDesc, NS::UInteger index) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlattributedescriptor?language=objc
    class AttributeDescriptor : public NS::Copying<AttributeDescriptor>
    {
    public:
        [[nodiscard]] static AttributeDescriptor* alloc();

        [[nodiscard]] NS::UInteger bufferIndex() const;

        [[nodiscard]] AttributeFormat format() const;

        [[nodiscard]] AttributeDescriptor* init();

        [[nodiscard]] NS::UInteger offset() const;

        void setBufferIndex(NS::UInteger bufferIndex) const;

        void setFormat(AttributeFormat format) const;

        void setOffset(NS::UInteger offset) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlattributedescriptorarray?language=objc
    class AttributeDescriptorArray : public NS::Referencing<AttributeDescriptorArray>
    {
    public:
        [[nodiscard]] static AttributeDescriptorArray* alloc();

        [[nodiscard]] AttributeDescriptorArray* init();

        [[nodiscard]] AttributeDescriptor* object(NS::UInteger index) const;
        void setObject(const AttributeDescriptor* attributeDesc, NS::UInteger index) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlstageinputoutputdescriptor?language=objc
    class StageInputOutputDescriptor : public NS::Copying<StageInputOutputDescriptor>
    {
    public:
        [[nodiscard]] static StageInputOutputDescriptor* alloc();

        [[nodiscard]] AttributeDescriptorArray* attributes() const;

        [[nodiscard]] NS::UInteger indexBufferIndex() const;

        [[nodiscard]] IndexType indexType() const;

        [[nodiscard]] StageInputOutputDescriptor* init();

        [[nodiscard]] BufferLayoutDescriptorArray* layouts() const;

        void reset() const;

        void setIndexBufferIndex(NS::UInteger indexBufferIndex) const;

        void setIndexType(IndexType indexType) const;

        static StageInputOutputDescriptor* stageInputOutputDescriptor();
    };

} // namespace MTL
_MTL_INLINE MTL::BufferLayoutDescriptor* MTL::BufferLayoutDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<BufferLayoutDescriptor>(_MTL_PRIVATE_CLS(MTLBufferLayoutDescriptor));
}

_MTL_INLINE MTL::BufferLayoutDescriptor* MTL::BufferLayoutDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<BufferLayoutDescriptor>();
}

_MTL_INLINE void MTL::BufferLayoutDescriptor::setStepFunction(const StepFunction stepFunction) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setStepFunction_), stepFunction);
}

_MTL_INLINE void MTL::BufferLayoutDescriptor::setStepRate(const NS::UInteger stepRate) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setStepRate_), stepRate);
}

_MTL_INLINE void MTL::BufferLayoutDescriptor::setStride(const NS::UInteger stride) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setStride_), stride);
}

_MTL_INLINE MTL::StepFunction MTL::BufferLayoutDescriptor::stepFunction() const
{
    return sendMessage<StepFunction>(this, _MTL_PRIVATE_SEL(stepFunction));
}

_MTL_INLINE NS::UInteger MTL::BufferLayoutDescriptor::stepRate() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(stepRate));
}

_MTL_INLINE NS::UInteger MTL::BufferLayoutDescriptor::stride() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(stride));
}

_MTL_INLINE MTL::BufferLayoutDescriptorArray* MTL::BufferLayoutDescriptorArray::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<BufferLayoutDescriptorArray>(_MTL_PRIVATE_CLS(MTLBufferLayoutDescriptorArray));
}

_MTL_INLINE MTL::BufferLayoutDescriptorArray* MTL::BufferLayoutDescriptorArray::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<BufferLayoutDescriptorArray>();
}

_MTL_INLINE MTL::BufferLayoutDescriptor* MTL::BufferLayoutDescriptorArray::object(const NS::UInteger index) const
{
    return sendMessage<BufferLayoutDescriptor*>(this, _MTL_PRIVATE_SEL(objectAtIndexedSubscript_), index);
}

_MTL_INLINE void MTL::BufferLayoutDescriptorArray::setObject(const BufferLayoutDescriptor* bufferDesc,
                                                             const NS::UInteger            index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setObject_atIndexedSubscript_), bufferDesc, index);
}

_MTL_INLINE MTL::AttributeDescriptor* MTL::AttributeDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<AttributeDescriptor>(_MTL_PRIVATE_CLS(MTLAttributeDescriptor));
}

_MTL_INLINE NS::UInteger MTL::AttributeDescriptor::bufferIndex() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(bufferIndex));
}

_MTL_INLINE MTL::AttributeFormat MTL::AttributeDescriptor::format() const
{
    return sendMessage<AttributeFormat>(this, _MTL_PRIVATE_SEL(format));
}

_MTL_INLINE MTL::AttributeDescriptor* MTL::AttributeDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<AttributeDescriptor>();
}

_MTL_INLINE NS::UInteger MTL::AttributeDescriptor::offset() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(offset));
}

_MTL_INLINE void MTL::AttributeDescriptor::setBufferIndex(const NS::UInteger bufferIndex) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBufferIndex_), bufferIndex);
}

_MTL_INLINE void MTL::AttributeDescriptor::setFormat(const AttributeFormat format) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFormat_), format);
}

_MTL_INLINE void MTL::AttributeDescriptor::setOffset(const NS::UInteger offset) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setOffset_), offset);
}

_MTL_INLINE MTL::AttributeDescriptorArray* MTL::AttributeDescriptorArray::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<AttributeDescriptorArray>(_MTL_PRIVATE_CLS(MTLAttributeDescriptorArray));
}

_MTL_INLINE MTL::AttributeDescriptorArray* MTL::AttributeDescriptorArray::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<AttributeDescriptorArray>();
}

_MTL_INLINE MTL::AttributeDescriptor* MTL::AttributeDescriptorArray::object(const NS::UInteger index) const
{
    return sendMessage<AttributeDescriptor*>(this, _MTL_PRIVATE_SEL(objectAtIndexedSubscript_), index);
}

_MTL_INLINE void MTL::AttributeDescriptorArray::setObject(const AttributeDescriptor* attributeDesc,
                                                          const NS::UInteger         index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setObject_atIndexedSubscript_), attributeDesc, index);
}

_MTL_INLINE MTL::StageInputOutputDescriptor* MTL::StageInputOutputDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<StageInputOutputDescriptor>(_MTL_PRIVATE_CLS(MTLStageInputOutputDescriptor));
}

_MTL_INLINE MTL::AttributeDescriptorArray* MTL::StageInputOutputDescriptor::attributes() const
{
    return sendMessage<AttributeDescriptorArray*>(this, _MTL_PRIVATE_SEL(attributes));
}

_MTL_INLINE NS::UInteger MTL::StageInputOutputDescriptor::indexBufferIndex() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(indexBufferIndex));
}

_MTL_INLINE MTL::IndexType MTL::StageInputOutputDescriptor::indexType() const
{
    return sendMessage<IndexType>(this, _MTL_PRIVATE_SEL(indexType));
}

_MTL_INLINE MTL::StageInputOutputDescriptor* MTL::StageInputOutputDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<StageInputOutputDescriptor>();
}

_MTL_INLINE MTL::BufferLayoutDescriptorArray* MTL::StageInputOutputDescriptor::layouts() const
{
    return sendMessage<BufferLayoutDescriptorArray*>(this, _MTL_PRIVATE_SEL(layouts));
}

_MTL_INLINE void MTL::StageInputOutputDescriptor::reset() const { sendMessage<void>(this, _MTL_PRIVATE_SEL(reset)); }

_MTL_INLINE void MTL::StageInputOutputDescriptor::setIndexBufferIndex(const NS::UInteger indexBufferIndex) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setIndexBufferIndex_), indexBufferIndex);
}

_MTL_INLINE void MTL::StageInputOutputDescriptor::setIndexType(const IndexType indexType) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setIndexType_), indexType);
}

_MTL_INLINE MTL::StageInputOutputDescriptor* MTL::StageInputOutputDescriptor::stageInputOutputDescriptor()
{
    return sendMessage<StageInputOutputDescriptor*>(_MTL_PRIVATE_CLS(MTLStageInputOutputDescriptor),
                                                    _MTL_PRIVATE_SEL(stageInputOutputDescriptor));
}
