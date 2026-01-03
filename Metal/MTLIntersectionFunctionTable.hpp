//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLIntersectionFunctionTable.hpp
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
#include "MTLResource.hpp"
#include "MTLTypes.hpp"

namespace MTL
{
    class Buffer;
    class FunctionHandle;
    class IntersectionFunctionTableDescriptor;
    class VisibleFunctionTable;

    /// @see https://developer.apple.com/documentation/metal/mtlintersectionfunctionsignature?language=objc
    _MTL_OPTIONS(NS::UInteger, IntersectionFunctionSignature){
        IntersectionFunctionSignatureNone                       = 0,
        IntersectionFunctionSignatureInstancing                 = 1,
        IntersectionFunctionSignatureTriangleData               = 1 << 1,
        IntersectionFunctionSignatureWorldSpaceData             = 1 << 2,
        IntersectionFunctionSignatureInstanceMotion             = 1 << 3,
        IntersectionFunctionSignaturePrimitiveMotion            = 1 << 4,
        IntersectionFunctionSignatureExtendedLimits             = 1 << 5,
        IntersectionFunctionSignatureMaxLevels                  = 1 << 6,
        IntersectionFunctionSignatureCurveData                  = 1 << 7,
        IntersectionFunctionSignatureIntersectionFunctionBuffer = 1 << 8,
        IntersectionFunctionSignatureUserData                   = 1 << 9,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlintersectionfunctionbufferarguments?language=objc
    struct IntersectionFunctionBufferArguments
    {
        uint64_t intersectionFunctionBuffer;
        uint64_t intersectionFunctionBufferSize;
        uint64_t intersectionFunctionStride;
    } _MTL_PACKED;

    /// @see https://developer.apple.com/documentation/metal/mtlintersectionfunctiontabledescriptor?language=objc
    class IntersectionFunctionTableDescriptor : public NS::Copying<IntersectionFunctionTableDescriptor>
    {
    public:
        [[nodiscard]] static IntersectionFunctionTableDescriptor* alloc();

        [[nodiscard]] NS::UInteger functionCount() const;

        [[nodiscard]] IntersectionFunctionTableDescriptor* init();

        [[nodiscard]] static IntersectionFunctionTableDescriptor* intersectionFunctionTableDescriptor();

        void setFunctionCount(NS::UInteger functionCount) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlintersectionfunctiontable?language=objc
    class IntersectionFunctionTable : public NS::Referencing<IntersectionFunctionTable, Resource>
    {
    public:
        [[nodiscard]] ResourceID gpuResourceID() const;

        void setBuffer(const Buffer* buffer, NS::UInteger offset, NS::UInteger index) const;
        void setBuffers(const Buffer* const buffers[], const NS::UInteger offsets[], NS::Range range) const;

        void setFunction(const FunctionHandle* function, NS::UInteger index) const;
        void setFunctions(const FunctionHandle* const functions[], NS::Range range) const;

        void setOpaqueCurveIntersectionFunction(IntersectionFunctionSignature signature, NS::UInteger index) const;
        void setOpaqueCurveIntersectionFunction(IntersectionFunctionSignature signature, NS::Range range) const;

        void setOpaqueTriangleIntersectionFunction(IntersectionFunctionSignature signature, NS::UInteger index) const;
        void setOpaqueTriangleIntersectionFunction(IntersectionFunctionSignature signature, NS::Range range) const;

        void setVisibleFunctionTable(const VisibleFunctionTable* functionTable, NS::UInteger bufferIndex) const;
        void setVisibleFunctionTables(const VisibleFunctionTable* const functionTables[], NS::Range bufferRange) const;
    };

} // namespace MTL

_MTL_INLINE MTL::IntersectionFunctionTableDescriptor* MTL::IntersectionFunctionTableDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<IntersectionFunctionTableDescriptor>(
        _MTL_PRIVATE_CLS(MTLIntersectionFunctionTableDescriptor));
}

_MTL_INLINE NS::UInteger MTL::IntersectionFunctionTableDescriptor::functionCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(functionCount));
}

_MTL_INLINE MTL::IntersectionFunctionTableDescriptor* MTL::IntersectionFunctionTableDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<IntersectionFunctionTableDescriptor>();
}

_MTL_INLINE MTL::IntersectionFunctionTableDescriptor*
            MTL::IntersectionFunctionTableDescriptor::intersectionFunctionTableDescriptor()
{
    return sendMessage<IntersectionFunctionTableDescriptor*>(_MTL_PRIVATE_CLS(MTLIntersectionFunctionTableDescriptor),
                                                             _MTL_PRIVATE_SEL(intersectionFunctionTableDescriptor));
}

_MTL_INLINE void MTL::IntersectionFunctionTableDescriptor::setFunctionCount(const NS::UInteger functionCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFunctionCount_), functionCount);
}

_MTL_INLINE MTL::ResourceID MTL::IntersectionFunctionTable::gpuResourceID() const
{
    return sendMessage<ResourceID>(this, _MTL_PRIVATE_SEL(gpuResourceID));
}

_MTL_INLINE void MTL::IntersectionFunctionTable::setBuffer(const Buffer*      buffer,
                                                           const NS::UInteger offset,
                                                           const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBuffer_offset_atIndex_), buffer, offset, index);
}

_MTL_INLINE void MTL::IntersectionFunctionTable::setBuffers(const Buffer* const buffers[],
                                                            const NS::UInteger  offsets[],
                                                            const NS::Range     range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBuffers_offsets_withRange_), buffers, offsets, range);
}

_MTL_INLINE void MTL::IntersectionFunctionTable::setFunction(const FunctionHandle* function,
                                                             const NS::UInteger    index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFunction_atIndex_), function, index);
}

_MTL_INLINE void MTL::IntersectionFunctionTable::setFunctions(const FunctionHandle* const functions[],
                                                              const NS::Range             range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFunctions_withRange_), functions, range);
}

_MTL_INLINE void MTL::IntersectionFunctionTable::setOpaqueCurveIntersectionFunction(
    const IntersectionFunctionSignature signature, const NS::UInteger index) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setOpaqueCurveIntersectionFunctionWithSignature_atIndex_), signature, index);
}

_MTL_INLINE void MTL::IntersectionFunctionTable::setOpaqueCurveIntersectionFunction(
    const IntersectionFunctionSignature signature, const NS::Range range) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setOpaqueCurveIntersectionFunctionWithSignature_withRange_), signature, range);
}

_MTL_INLINE void MTL::IntersectionFunctionTable::setOpaqueTriangleIntersectionFunction(
    const IntersectionFunctionSignature signature, const NS::UInteger index) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setOpaqueTriangleIntersectionFunctionWithSignature_atIndex_), signature, index);
}

_MTL_INLINE void MTL::IntersectionFunctionTable::setOpaqueTriangleIntersectionFunction(
    const IntersectionFunctionSignature signature, const NS::Range range) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setOpaqueTriangleIntersectionFunctionWithSignature_withRange_), signature, range);
}

_MTL_INLINE void MTL::IntersectionFunctionTable::setVisibleFunctionTable(const VisibleFunctionTable* functionTable,
                                                                         const NS::UInteger          bufferIndex) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVisibleFunctionTable_atBufferIndex_), functionTable, bufferIndex);
}

_MTL_INLINE void MTL::IntersectionFunctionTable::setVisibleFunctionTables(
    const VisibleFunctionTable* const functionTables[], const NS::Range bufferRange) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVisibleFunctionTables_withBufferRange_), functionTables, bufferRange);
}
