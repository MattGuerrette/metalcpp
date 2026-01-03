//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTL4AccelerationStructure.hpp
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
#include "MTLAccelerationStructure.hpp"
#include "MTLAccelerationStructureTypes.hpp"
#include "MTLArgument.hpp"
#include "MTLDefines.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"
#include "MTLStageInputOutputDescriptor.hpp"

namespace MTL4
{
    class AccelerationStructureBoundingBoxGeometryDescriptor;
    class AccelerationStructureCurveGeometryDescriptor;
    class AccelerationStructureDescriptor;
    class AccelerationStructureGeometryDescriptor;
    class AccelerationStructureMotionBoundingBoxGeometryDescriptor;
    class AccelerationStructureMotionCurveGeometryDescriptor;
    class AccelerationStructureMotionTriangleGeometryDescriptor;
    class AccelerationStructureTriangleGeometryDescriptor;
    class IndirectInstanceAccelerationStructureDescriptor;
    class InstanceAccelerationStructureDescriptor;
    class PrimitiveAccelerationStructureDescriptor;

    class AccelerationStructureDescriptor
        : public NS::Copying<AccelerationStructureDescriptor, MTL::AccelerationStructureDescriptor>
    {
    public:
        [[nodiscard]] static AccelerationStructureDescriptor* alloc();

        [[nodiscard]] AccelerationStructureDescriptor* init();
    };
    class AccelerationStructureGeometryDescriptor : public NS::Copying<AccelerationStructureGeometryDescriptor>
    {
    public:
        [[nodiscard]] static AccelerationStructureGeometryDescriptor* alloc();

        [[nodiscard]] bool allowDuplicateIntersectionFunctionInvocation() const;

        [[nodiscard]] AccelerationStructureGeometryDescriptor* init();

        [[nodiscard]] NS::UInteger intersectionFunctionTableOffset() const;

        [[nodiscard]] NS::String* label() const;

        [[nodiscard]] bool opaque() const;

        [[nodiscard]] BufferRange primitiveDataBuffer() const;

        [[nodiscard]] NS::UInteger primitiveDataElementSize() const;

        [[nodiscard]] NS::UInteger primitiveDataStride() const;

        void setAllowDuplicateIntersectionFunctionInvocation(bool allowDuplicateIntersectionFunctionInvocation) const;

        void setIntersectionFunctionTableOffset(NS::UInteger intersectionFunctionTableOffset) const;

        void setLabel(const NS::String* label) const;

        void setOpaque(bool opaque) const;

        void setPrimitiveDataBuffer(BufferRange primitiveDataBuffer) const;

        void setPrimitiveDataElementSize(NS::UInteger primitiveDataElementSize) const;

        void setPrimitiveDataStride(NS::UInteger primitiveDataStride) const;
    };
    class PrimitiveAccelerationStructureDescriptor
        : public NS::Copying<PrimitiveAccelerationStructureDescriptor, AccelerationStructureDescriptor>
    {
    public:
        [[nodiscard]] static PrimitiveAccelerationStructureDescriptor* alloc();

        [[nodiscard]] NS::Array* geometryDescriptors() const;

        [[nodiscard]] PrimitiveAccelerationStructureDescriptor* init();

        [[nodiscard]] MTL::MotionBorderMode motionEndBorderMode() const;

        [[nodiscard]] float motionEndTime() const;

        [[nodiscard]] NS::UInteger motionKeyframeCount() const;

        [[nodiscard]] MTL::MotionBorderMode motionStartBorderMode() const;

        [[nodiscard]] float motionStartTime() const;

        void setGeometryDescriptors(const NS::Array* geometryDescriptors) const;

        void setMotionEndBorderMode(MTL::MotionBorderMode motionEndBorderMode) const;

        void setMotionEndTime(float motionEndTime) const;

        void setMotionKeyframeCount(NS::UInteger motionKeyframeCount) const;

        void setMotionStartBorderMode(MTL::MotionBorderMode motionStartBorderMode) const;

        void setMotionStartTime(float motionStartTime) const;
    };
    class AccelerationStructureTriangleGeometryDescriptor
        : public NS::Copying<AccelerationStructureTriangleGeometryDescriptor, AccelerationStructureGeometryDescriptor>
    {
    public:
        [[nodiscard]] static AccelerationStructureTriangleGeometryDescriptor* alloc();

        [[nodiscard]] BufferRange indexBuffer() const;

        [[nodiscard]] MTL::IndexType indexType() const;

        [[nodiscard]] AccelerationStructureTriangleGeometryDescriptor* init();

        [[nodiscard]] BufferRange transformationMatrixBuffer() const;

        [[nodiscard]] MTL::MatrixLayout transformationMatrixLayout() const;

        [[nodiscard]] NS::UInteger triangleCount() const;

        [[nodiscard]] BufferRange vertexBuffer() const;

        [[nodiscard]] MTL::AttributeFormat vertexFormat() const;

        [[nodiscard]] NS::UInteger vertexStride() const;

        void setIndexBuffer(BufferRange indexBuffer) const;

        void setIndexType(MTL::IndexType indexType) const;

        void setTransformationMatrixBuffer(BufferRange transformationMatrixBuffer) const;

        void setTransformationMatrixLayout(MTL::MatrixLayout transformationMatrixLayout) const;

        void setTriangleCount(NS::UInteger triangleCount) const;

        void setVertexBuffer(BufferRange vertexBuffer) const;

        void setVertexFormat(MTL::AttributeFormat vertexFormat) const;

        void setVertexStride(NS::UInteger vertexStride) const;
    };
    class AccelerationStructureBoundingBoxGeometryDescriptor
        : public NS::Copying<AccelerationStructureBoundingBoxGeometryDescriptor,
                             AccelerationStructureGeometryDescriptor>
    {
    public:
        [[nodiscard]] static AccelerationStructureBoundingBoxGeometryDescriptor* alloc();

        [[nodiscard]] BufferRange boundingBoxBuffer() const;

        [[nodiscard]] NS::UInteger boundingBoxCount() const;

        [[nodiscard]] NS::UInteger boundingBoxStride() const;

        [[nodiscard]] AccelerationStructureBoundingBoxGeometryDescriptor* init();

        void setBoundingBoxBuffer(BufferRange boundingBoxBuffer) const;

        void setBoundingBoxCount(NS::UInteger boundingBoxCount) const;

        void setBoundingBoxStride(NS::UInteger boundingBoxStride) const;
    };
    class AccelerationStructureMotionTriangleGeometryDescriptor
        : public NS::Copying<AccelerationStructureMotionTriangleGeometryDescriptor,
                             AccelerationStructureGeometryDescriptor>
    {
    public:
        [[nodiscard]] static AccelerationStructureMotionTriangleGeometryDescriptor* alloc();

        [[nodiscard]] BufferRange indexBuffer() const;

        [[nodiscard]] MTL::IndexType indexType() const;

        [[nodiscard]] AccelerationStructureMotionTriangleGeometryDescriptor* init();

        [[nodiscard]] BufferRange transformationMatrixBuffer() const;

        [[nodiscard]] MTL::MatrixLayout transformationMatrixLayout() const;

        [[nodiscard]] NS::UInteger triangleCount() const;

        [[nodiscard]] BufferRange vertexBuffers() const;

        [[nodiscard]] MTL::AttributeFormat vertexFormat() const;

        [[nodiscard]] NS::UInteger vertexStride() const;

        void setIndexBuffer(BufferRange indexBuffer) const;

        void setIndexType(MTL::IndexType indexType) const;

        void setTransformationMatrixBuffer(BufferRange transformationMatrixBuffer) const;

        void setTransformationMatrixLayout(MTL::MatrixLayout transformationMatrixLayout) const;

        void setTriangleCount(NS::UInteger triangleCount) const;

        void setVertexBuffers(BufferRange vertexBuffers) const;

        void setVertexFormat(MTL::AttributeFormat vertexFormat) const;

        void setVertexStride(NS::UInteger vertexStride) const;
    };
    class AccelerationStructureMotionBoundingBoxGeometryDescriptor
        : public NS::Copying<AccelerationStructureMotionBoundingBoxGeometryDescriptor,
                             AccelerationStructureGeometryDescriptor>
    {
    public:
        [[nodiscard]] static AccelerationStructureMotionBoundingBoxGeometryDescriptor* alloc();

        [[nodiscard]] BufferRange boundingBoxBuffers() const;

        [[nodiscard]] NS::UInteger boundingBoxCount() const;

        [[nodiscard]] NS::UInteger boundingBoxStride() const;

        [[nodiscard]] AccelerationStructureMotionBoundingBoxGeometryDescriptor* init();

        void setBoundingBoxBuffers(BufferRange boundingBoxBuffers) const;

        void setBoundingBoxCount(NS::UInteger boundingBoxCount) const;

        void setBoundingBoxStride(NS::UInteger boundingBoxStride) const;
    };
    class AccelerationStructureCurveGeometryDescriptor
        : public NS::Copying<AccelerationStructureCurveGeometryDescriptor, AccelerationStructureGeometryDescriptor>
    {
    public:
        [[nodiscard]] static AccelerationStructureCurveGeometryDescriptor* alloc();

        [[nodiscard]] BufferRange controlPointBuffer() const;

        [[nodiscard]] NS::UInteger controlPointCount() const;

        [[nodiscard]] MTL::AttributeFormat controlPointFormat() const;

        [[nodiscard]] NS::UInteger controlPointStride() const;

        [[nodiscard]] MTL::CurveBasis curveBasis() const;

        [[nodiscard]] MTL::CurveEndCaps curveEndCaps() const;

        [[nodiscard]] MTL::CurveType curveType() const;

        [[nodiscard]] BufferRange indexBuffer() const;

        [[nodiscard]] MTL::IndexType indexType() const;

        [[nodiscard]] AccelerationStructureCurveGeometryDescriptor* init();

        [[nodiscard]] BufferRange radiusBuffer() const;

        [[nodiscard]] MTL::AttributeFormat radiusFormat() const;

        [[nodiscard]] NS::UInteger radiusStride() const;

        [[nodiscard]] NS::UInteger segmentControlPointCount() const;

        [[nodiscard]] NS::UInteger segmentCount() const;

        void setControlPointBuffer(BufferRange controlPointBuffer) const;

        void setControlPointCount(NS::UInteger controlPointCount) const;

        void setControlPointFormat(MTL::AttributeFormat controlPointFormat) const;

        void setControlPointStride(NS::UInteger controlPointStride) const;

        void setCurveBasis(MTL::CurveBasis curveBasis) const;

        void setCurveEndCaps(MTL::CurveEndCaps curveEndCaps) const;

        void setCurveType(MTL::CurveType curveType) const;

        void setIndexBuffer(BufferRange indexBuffer) const;

        void setIndexType(MTL::IndexType indexType) const;

        void setRadiusBuffer(BufferRange radiusBuffer) const;

        void setRadiusFormat(MTL::AttributeFormat radiusFormat) const;

        void setRadiusStride(NS::UInteger radiusStride) const;

        void setSegmentControlPointCount(NS::UInteger segmentControlPointCount) const;

        void setSegmentCount(NS::UInteger segmentCount) const;
    };
    class AccelerationStructureMotionCurveGeometryDescriptor
        : public NS::Copying<AccelerationStructureMotionCurveGeometryDescriptor,
                             AccelerationStructureGeometryDescriptor>
    {
    public:
        [[nodiscard]] static AccelerationStructureMotionCurveGeometryDescriptor* alloc();

        [[nodiscard]] BufferRange controlPointBuffers() const;

        [[nodiscard]] NS::UInteger controlPointCount() const;

        [[nodiscard]] MTL::AttributeFormat controlPointFormat() const;

        [[nodiscard]] NS::UInteger controlPointStride() const;

        [[nodiscard]] MTL::CurveBasis curveBasis() const;

        [[nodiscard]] MTL::CurveEndCaps curveEndCaps() const;

        [[nodiscard]] MTL::CurveType curveType() const;

        [[nodiscard]] BufferRange indexBuffer() const;

        [[nodiscard]] MTL::IndexType indexType() const;

        [[nodiscard]] AccelerationStructureMotionCurveGeometryDescriptor* init();

        [[nodiscard]] BufferRange radiusBuffers() const;

        [[nodiscard]] MTL::AttributeFormat radiusFormat() const;

        [[nodiscard]] NS::UInteger radiusStride() const;

        [[nodiscard]] NS::UInteger segmentControlPointCount() const;

        [[nodiscard]] NS::UInteger segmentCount() const;

        void setControlPointBuffers(BufferRange controlPointBuffers) const;

        void setControlPointCount(NS::UInteger controlPointCount) const;

        void setControlPointFormat(MTL::AttributeFormat controlPointFormat) const;

        void setControlPointStride(NS::UInteger controlPointStride) const;

        void setCurveBasis(MTL::CurveBasis curveBasis) const;

        void setCurveEndCaps(MTL::CurveEndCaps curveEndCaps) const;

        void setCurveType(MTL::CurveType curveType) const;

        void setIndexBuffer(BufferRange indexBuffer) const;

        void setIndexType(MTL::IndexType indexType) const;

        void setRadiusBuffers(BufferRange radiusBuffers) const;

        void setRadiusFormat(MTL::AttributeFormat radiusFormat) const;

        void setRadiusStride(NS::UInteger radiusStride) const;

        void setSegmentControlPointCount(NS::UInteger segmentControlPointCount) const;

        void setSegmentCount(NS::UInteger segmentCount) const;
    };
    class InstanceAccelerationStructureDescriptor
        : public NS::Copying<InstanceAccelerationStructureDescriptor, AccelerationStructureDescriptor>
    {
    public:
        [[nodiscard]] static InstanceAccelerationStructureDescriptor* alloc();

        [[nodiscard]] InstanceAccelerationStructureDescriptor* init();

        [[nodiscard]] NS::UInteger instanceCount() const;

        [[nodiscard]] BufferRange instanceDescriptorBuffer() const;

        [[nodiscard]] NS::UInteger instanceDescriptorStride() const;

        [[nodiscard]] MTL::AccelerationStructureInstanceDescriptorType instanceDescriptorType() const;

        [[nodiscard]] MTL::MatrixLayout instanceTransformationMatrixLayout() const;

        [[nodiscard]] BufferRange motionTransformBuffer() const;

        [[nodiscard]] NS::UInteger motionTransformCount() const;

        [[nodiscard]] NS::UInteger motionTransformStride() const;

        [[nodiscard]] MTL::TransformType motionTransformType() const;

        void setInstanceCount(NS::UInteger instanceCount) const;

        void setInstanceDescriptorBuffer(BufferRange instanceDescriptorBuffer) const;

        void setInstanceDescriptorStride(NS::UInteger instanceDescriptorStride) const;

        void setInstanceDescriptorType(MTL::AccelerationStructureInstanceDescriptorType instanceDescriptorType) const;

        void setInstanceTransformationMatrixLayout(MTL::MatrixLayout instanceTransformationMatrixLayout) const;

        void setMotionTransformBuffer(BufferRange motionTransformBuffer) const;

        void setMotionTransformCount(NS::UInteger motionTransformCount) const;

        void setMotionTransformStride(NS::UInteger motionTransformStride) const;

        void setMotionTransformType(MTL::TransformType motionTransformType) const;
    };
    class IndirectInstanceAccelerationStructureDescriptor
        : public NS::Copying<IndirectInstanceAccelerationStructureDescriptor, AccelerationStructureDescriptor>
    {
    public:
        [[nodiscard]] static IndirectInstanceAccelerationStructureDescriptor* alloc();

        [[nodiscard]] IndirectInstanceAccelerationStructureDescriptor* init();

        [[nodiscard]] BufferRange instanceCountBuffer() const;

        [[nodiscard]] BufferRange instanceDescriptorBuffer() const;

        [[nodiscard]] NS::UInteger instanceDescriptorStride() const;

        [[nodiscard]] MTL::AccelerationStructureInstanceDescriptorType instanceDescriptorType() const;

        [[nodiscard]] MTL::MatrixLayout instanceTransformationMatrixLayout() const;

        [[nodiscard]] NS::UInteger maxInstanceCount() const;

        [[nodiscard]] NS::UInteger maxMotionTransformCount() const;

        [[nodiscard]] BufferRange motionTransformBuffer() const;

        [[nodiscard]] BufferRange motionTransformCountBuffer() const;

        [[nodiscard]] NS::UInteger motionTransformStride() const;

        [[nodiscard]] MTL::TransformType motionTransformType() const;

        void setInstanceCountBuffer(BufferRange instanceCountBuffer) const;

        void setInstanceDescriptorBuffer(BufferRange instanceDescriptorBuffer) const;

        void setInstanceDescriptorStride(NS::UInteger instanceDescriptorStride) const;

        void setInstanceDescriptorType(MTL::AccelerationStructureInstanceDescriptorType instanceDescriptorType) const;

        void setInstanceTransformationMatrixLayout(MTL::MatrixLayout instanceTransformationMatrixLayout) const;

        void setMaxInstanceCount(NS::UInteger maxInstanceCount) const;

        void setMaxMotionTransformCount(NS::UInteger maxMotionTransformCount) const;

        void setMotionTransformBuffer(BufferRange motionTransformBuffer) const;

        void setMotionTransformCountBuffer(BufferRange motionTransformCountBuffer) const;

        void setMotionTransformStride(NS::UInteger motionTransformStride) const;

        void setMotionTransformType(MTL::TransformType motionTransformType) const;
    };

} // namespace MTL4
_MTL_INLINE MTL4::AccelerationStructureDescriptor* MTL4::AccelerationStructureDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return Object::alloc<AccelerationStructureDescriptor>(_MTL_PRIVATE_CLS(MTL4AccelerationStructureDescriptor));
}

_MTL_INLINE MTL4::AccelerationStructureDescriptor* MTL4::AccelerationStructureDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return Object::init<AccelerationStructureDescriptor>();
}

_MTL_INLINE MTL4::AccelerationStructureGeometryDescriptor* MTL4::AccelerationStructureGeometryDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return Object::alloc<AccelerationStructureGeometryDescriptor>(
        _MTL_PRIVATE_CLS(MTL4AccelerationStructureGeometryDescriptor));
}

_MTL_INLINE bool MTL4::AccelerationStructureGeometryDescriptor::allowDuplicateIntersectionFunctionInvocation() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(allowDuplicateIntersectionFunctionInvocation));
}

_MTL_INLINE MTL4::AccelerationStructureGeometryDescriptor* MTL4::AccelerationStructureGeometryDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return Object::init<AccelerationStructureGeometryDescriptor>();
}

_MTL_INLINE NS::UInteger MTL4::AccelerationStructureGeometryDescriptor::intersectionFunctionTableOffset() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(intersectionFunctionTableOffset));
}

_MTL_INLINE NS::String* MTL4::AccelerationStructureGeometryDescriptor::label() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
}

_MTL_INLINE bool MTL4::AccelerationStructureGeometryDescriptor::opaque() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(opaque));
}

_MTL_INLINE MTL4::BufferRange MTL4::AccelerationStructureGeometryDescriptor::primitiveDataBuffer() const
{
    return sendMessage<BufferRange>(this, _MTL_PRIVATE_SEL(primitiveDataBuffer));
}

_MTL_INLINE NS::UInteger MTL4::AccelerationStructureGeometryDescriptor::primitiveDataElementSize() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(primitiveDataElementSize));
}

_MTL_INLINE NS::UInteger MTL4::AccelerationStructureGeometryDescriptor::primitiveDataStride() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(primitiveDataStride));
}

_MTL_INLINE void MTL4::AccelerationStructureGeometryDescriptor::setAllowDuplicateIntersectionFunctionInvocation(
    const bool allowDuplicateIntersectionFunctionInvocation) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(setAllowDuplicateIntersectionFunctionInvocation_),
                      allowDuplicateIntersectionFunctionInvocation);
}

_MTL_INLINE void MTL4::AccelerationStructureGeometryDescriptor::setIntersectionFunctionTableOffset(
    const NS::UInteger intersectionFunctionTableOffset) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setIntersectionFunctionTableOffset_), intersectionFunctionTableOffset);
}

_MTL_INLINE void MTL4::AccelerationStructureGeometryDescriptor::setLabel(const NS::String* label) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLabel_), label);
}

_MTL_INLINE void MTL4::AccelerationStructureGeometryDescriptor::setOpaque(const bool opaque) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setOpaque_), opaque);
}

_MTL_INLINE void MTL4::AccelerationStructureGeometryDescriptor::setPrimitiveDataBuffer(
    const BufferRange primitiveDataBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setPrimitiveDataBuffer_), primitiveDataBuffer);
}

_MTL_INLINE void MTL4::AccelerationStructureGeometryDescriptor::setPrimitiveDataElementSize(
    const NS::UInteger primitiveDataElementSize) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setPrimitiveDataElementSize_), primitiveDataElementSize);
}

_MTL_INLINE void MTL4::AccelerationStructureGeometryDescriptor::setPrimitiveDataStride(
    const NS::UInteger primitiveDataStride) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setPrimitiveDataStride_), primitiveDataStride);
}

_MTL_INLINE MTL4::PrimitiveAccelerationStructureDescriptor* MTL4::PrimitiveAccelerationStructureDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return Object::alloc<PrimitiveAccelerationStructureDescriptor>(
        _MTL_PRIVATE_CLS(MTL4PrimitiveAccelerationStructureDescriptor));
}

_MTL_INLINE NS::Array* MTL4::PrimitiveAccelerationStructureDescriptor::geometryDescriptors() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(geometryDescriptors));
}

_MTL_INLINE MTL4::PrimitiveAccelerationStructureDescriptor* MTL4::PrimitiveAccelerationStructureDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return Object::init<PrimitiveAccelerationStructureDescriptor>();
}

_MTL_INLINE MTL::MotionBorderMode MTL4::PrimitiveAccelerationStructureDescriptor::motionEndBorderMode() const
{
    return sendMessage<MTL::MotionBorderMode>(this, _MTL_PRIVATE_SEL(motionEndBorderMode));
}

_MTL_INLINE float MTL4::PrimitiveAccelerationStructureDescriptor::motionEndTime() const
{
    return sendMessage<float>(this, _MTL_PRIVATE_SEL(motionEndTime));
}

_MTL_INLINE NS::UInteger MTL4::PrimitiveAccelerationStructureDescriptor::motionKeyframeCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(motionKeyframeCount));
}

_MTL_INLINE MTL::MotionBorderMode MTL4::PrimitiveAccelerationStructureDescriptor::motionStartBorderMode() const
{
    return sendMessage<MTL::MotionBorderMode>(this, _MTL_PRIVATE_SEL(motionStartBorderMode));
}

_MTL_INLINE float MTL4::PrimitiveAccelerationStructureDescriptor::motionStartTime() const
{
    return sendMessage<float>(this, _MTL_PRIVATE_SEL(motionStartTime));
}

_MTL_INLINE void MTL4::PrimitiveAccelerationStructureDescriptor::setGeometryDescriptors(
    const NS::Array* geometryDescriptors) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setGeometryDescriptors_), geometryDescriptors);
}

_MTL_INLINE void MTL4::PrimitiveAccelerationStructureDescriptor::setMotionEndBorderMode(
    const MTL::MotionBorderMode motionEndBorderMode) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMotionEndBorderMode_), motionEndBorderMode);
}

_MTL_INLINE void MTL4::PrimitiveAccelerationStructureDescriptor::setMotionEndTime(const float motionEndTime) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMotionEndTime_), motionEndTime);
}

_MTL_INLINE void MTL4::PrimitiveAccelerationStructureDescriptor::setMotionKeyframeCount(
    const NS::UInteger motionKeyframeCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMotionKeyframeCount_), motionKeyframeCount);
}

_MTL_INLINE void MTL4::PrimitiveAccelerationStructureDescriptor::setMotionStartBorderMode(
    const MTL::MotionBorderMode motionStartBorderMode) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMotionStartBorderMode_), motionStartBorderMode);
}

_MTL_INLINE void MTL4::PrimitiveAccelerationStructureDescriptor::setMotionStartTime(const float motionStartTime) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMotionStartTime_), motionStartTime);
}

_MTL_INLINE MTL4::AccelerationStructureTriangleGeometryDescriptor*
            MTL4::AccelerationStructureTriangleGeometryDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return Object::alloc<AccelerationStructureTriangleGeometryDescriptor>(
        _MTL_PRIVATE_CLS(MTL4AccelerationStructureTriangleGeometryDescriptor));
}

_MTL_INLINE MTL4::BufferRange MTL4::AccelerationStructureTriangleGeometryDescriptor::indexBuffer() const
{
    return sendMessage<BufferRange>(this, _MTL_PRIVATE_SEL(indexBuffer));
}

_MTL_INLINE MTL::IndexType MTL4::AccelerationStructureTriangleGeometryDescriptor::indexType() const
{
    return sendMessage<MTL::IndexType>(this, _MTL_PRIVATE_SEL(indexType));
}

_MTL_INLINE MTL4::AccelerationStructureTriangleGeometryDescriptor*
            MTL4::AccelerationStructureTriangleGeometryDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return Object::init<AccelerationStructureTriangleGeometryDescriptor>();
}

_MTL_INLINE void MTL4::AccelerationStructureTriangleGeometryDescriptor::setIndexBuffer(
    const BufferRange indexBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setIndexBuffer_), indexBuffer);
}

_MTL_INLINE void MTL4::AccelerationStructureTriangleGeometryDescriptor::setIndexType(
    const MTL::IndexType indexType) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setIndexType_), indexType);
}

_MTL_INLINE void MTL4::AccelerationStructureTriangleGeometryDescriptor::setTransformationMatrixBuffer(
    const BufferRange transformationMatrixBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTransformationMatrixBuffer_), transformationMatrixBuffer);
}

_MTL_INLINE void MTL4::AccelerationStructureTriangleGeometryDescriptor::setTransformationMatrixLayout(
    const MTL::MatrixLayout transformationMatrixLayout) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTransformationMatrixLayout_), transformationMatrixLayout);
}

_MTL_INLINE void MTL4::AccelerationStructureTriangleGeometryDescriptor::setTriangleCount(
    const NS::UInteger triangleCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTriangleCount_), triangleCount);
}

_MTL_INLINE void MTL4::AccelerationStructureTriangleGeometryDescriptor::setVertexBuffer(
    const BufferRange vertexBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVertexBuffer_), vertexBuffer);
}

_MTL_INLINE void MTL4::AccelerationStructureTriangleGeometryDescriptor::setVertexFormat(
    const MTL::AttributeFormat vertexFormat) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVertexFormat_), vertexFormat);
}

_MTL_INLINE void MTL4::AccelerationStructureTriangleGeometryDescriptor::setVertexStride(
    const NS::UInteger vertexStride) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVertexStride_), vertexStride);
}

_MTL_INLINE MTL4::BufferRange MTL4::AccelerationStructureTriangleGeometryDescriptor::transformationMatrixBuffer() const
{
    return sendMessage<BufferRange>(this, _MTL_PRIVATE_SEL(transformationMatrixBuffer));
}

_MTL_INLINE MTL::MatrixLayout MTL4::AccelerationStructureTriangleGeometryDescriptor::transformationMatrixLayout() const
{
    return sendMessage<MTL::MatrixLayout>(this, _MTL_PRIVATE_SEL(transformationMatrixLayout));
}

_MTL_INLINE NS::UInteger MTL4::AccelerationStructureTriangleGeometryDescriptor::triangleCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(triangleCount));
}

_MTL_INLINE MTL4::BufferRange MTL4::AccelerationStructureTriangleGeometryDescriptor::vertexBuffer() const
{
    return sendMessage<BufferRange>(this, _MTL_PRIVATE_SEL(vertexBuffer));
}

_MTL_INLINE MTL::AttributeFormat MTL4::AccelerationStructureTriangleGeometryDescriptor::vertexFormat() const
{
    return sendMessage<MTL::AttributeFormat>(this, _MTL_PRIVATE_SEL(vertexFormat));
}

_MTL_INLINE NS::UInteger MTL4::AccelerationStructureTriangleGeometryDescriptor::vertexStride() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(vertexStride));
}

_MTL_INLINE MTL4::AccelerationStructureBoundingBoxGeometryDescriptor*
            MTL4::AccelerationStructureBoundingBoxGeometryDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return Object::alloc<AccelerationStructureBoundingBoxGeometryDescriptor>(
        _MTL_PRIVATE_CLS(MTL4AccelerationStructureBoundingBoxGeometryDescriptor));
}

_MTL_INLINE MTL4::BufferRange MTL4::AccelerationStructureBoundingBoxGeometryDescriptor::boundingBoxBuffer() const
{
    return sendMessage<BufferRange>(this, _MTL_PRIVATE_SEL(boundingBoxBuffer));
}

_MTL_INLINE NS::UInteger MTL4::AccelerationStructureBoundingBoxGeometryDescriptor::boundingBoxCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(boundingBoxCount));
}

_MTL_INLINE NS::UInteger MTL4::AccelerationStructureBoundingBoxGeometryDescriptor::boundingBoxStride() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(boundingBoxStride));
}

_MTL_INLINE MTL4::AccelerationStructureBoundingBoxGeometryDescriptor*
            MTL4::AccelerationStructureBoundingBoxGeometryDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return Object::init<AccelerationStructureBoundingBoxGeometryDescriptor>();
}

_MTL_INLINE void MTL4::AccelerationStructureBoundingBoxGeometryDescriptor::setBoundingBoxBuffer(
    const BufferRange boundingBoxBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBoundingBoxBuffer_), boundingBoxBuffer);
}

_MTL_INLINE void MTL4::AccelerationStructureBoundingBoxGeometryDescriptor::setBoundingBoxCount(
    const NS::UInteger boundingBoxCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBoundingBoxCount_), boundingBoxCount);
}

_MTL_INLINE void MTL4::AccelerationStructureBoundingBoxGeometryDescriptor::setBoundingBoxStride(
    const NS::UInteger boundingBoxStride) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBoundingBoxStride_), boundingBoxStride);
}

_MTL_INLINE MTL4::AccelerationStructureMotionTriangleGeometryDescriptor*
            MTL4::AccelerationStructureMotionTriangleGeometryDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return Object::alloc<AccelerationStructureMotionTriangleGeometryDescriptor>(
        _MTL_PRIVATE_CLS(MTL4AccelerationStructureMotionTriangleGeometryDescriptor));
}

_MTL_INLINE MTL4::BufferRange MTL4::AccelerationStructureMotionTriangleGeometryDescriptor::indexBuffer() const
{
    return sendMessage<BufferRange>(this, _MTL_PRIVATE_SEL(indexBuffer));
}

_MTL_INLINE MTL::IndexType MTL4::AccelerationStructureMotionTriangleGeometryDescriptor::indexType() const
{
    return sendMessage<MTL::IndexType>(this, _MTL_PRIVATE_SEL(indexType));
}

_MTL_INLINE MTL4::AccelerationStructureMotionTriangleGeometryDescriptor*
            MTL4::AccelerationStructureMotionTriangleGeometryDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return Object::init<AccelerationStructureMotionTriangleGeometryDescriptor>();
}

_MTL_INLINE void MTL4::AccelerationStructureMotionTriangleGeometryDescriptor::setIndexBuffer(
    const BufferRange indexBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setIndexBuffer_), indexBuffer);
}

_MTL_INLINE void MTL4::AccelerationStructureMotionTriangleGeometryDescriptor::setIndexType(
    const MTL::IndexType indexType) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setIndexType_), indexType);
}

_MTL_INLINE void MTL4::AccelerationStructureMotionTriangleGeometryDescriptor::setTransformationMatrixBuffer(
    const BufferRange transformationMatrixBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTransformationMatrixBuffer_), transformationMatrixBuffer);
}

_MTL_INLINE void MTL4::AccelerationStructureMotionTriangleGeometryDescriptor::setTransformationMatrixLayout(
    const MTL::MatrixLayout transformationMatrixLayout) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTransformationMatrixLayout_), transformationMatrixLayout);
}

_MTL_INLINE void MTL4::AccelerationStructureMotionTriangleGeometryDescriptor::setTriangleCount(
    const NS::UInteger triangleCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTriangleCount_), triangleCount);
}

_MTL_INLINE void MTL4::AccelerationStructureMotionTriangleGeometryDescriptor::setVertexBuffers(
    const BufferRange vertexBuffers) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVertexBuffers_), vertexBuffers);
}

_MTL_INLINE void MTL4::AccelerationStructureMotionTriangleGeometryDescriptor::setVertexFormat(
    const MTL::AttributeFormat vertexFormat) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVertexFormat_), vertexFormat);
}

_MTL_INLINE void MTL4::AccelerationStructureMotionTriangleGeometryDescriptor::setVertexStride(
    const NS::UInteger vertexStride) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVertexStride_), vertexStride);
}

_MTL_INLINE MTL4::BufferRange MTL4::AccelerationStructureMotionTriangleGeometryDescriptor::transformationMatrixBuffer()
    const
{
    return sendMessage<BufferRange>(this, _MTL_PRIVATE_SEL(transformationMatrixBuffer));
}

_MTL_INLINE MTL::MatrixLayout MTL4::AccelerationStructureMotionTriangleGeometryDescriptor::transformationMatrixLayout()
    const
{
    return sendMessage<MTL::MatrixLayout>(this, _MTL_PRIVATE_SEL(transformationMatrixLayout));
}

_MTL_INLINE NS::UInteger MTL4::AccelerationStructureMotionTriangleGeometryDescriptor::triangleCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(triangleCount));
}

_MTL_INLINE MTL4::BufferRange MTL4::AccelerationStructureMotionTriangleGeometryDescriptor::vertexBuffers() const
{
    return sendMessage<BufferRange>(this, _MTL_PRIVATE_SEL(vertexBuffers));
}

_MTL_INLINE MTL::AttributeFormat MTL4::AccelerationStructureMotionTriangleGeometryDescriptor::vertexFormat() const
{
    return sendMessage<MTL::AttributeFormat>(this, _MTL_PRIVATE_SEL(vertexFormat));
}

_MTL_INLINE NS::UInteger MTL4::AccelerationStructureMotionTriangleGeometryDescriptor::vertexStride() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(vertexStride));
}

_MTL_INLINE MTL4::AccelerationStructureMotionBoundingBoxGeometryDescriptor*
            MTL4::AccelerationStructureMotionBoundingBoxGeometryDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return Object::alloc<AccelerationStructureMotionBoundingBoxGeometryDescriptor>(
        _MTL_PRIVATE_CLS(MTL4AccelerationStructureMotionBoundingBoxGeometryDescriptor));
}

_MTL_INLINE MTL4::BufferRange MTL4::AccelerationStructureMotionBoundingBoxGeometryDescriptor::boundingBoxBuffers() const
{
    return sendMessage<BufferRange>(this, _MTL_PRIVATE_SEL(boundingBoxBuffers));
}

_MTL_INLINE NS::UInteger MTL4::AccelerationStructureMotionBoundingBoxGeometryDescriptor::boundingBoxCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(boundingBoxCount));
}

_MTL_INLINE NS::UInteger MTL4::AccelerationStructureMotionBoundingBoxGeometryDescriptor::boundingBoxStride() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(boundingBoxStride));
}

_MTL_INLINE MTL4::AccelerationStructureMotionBoundingBoxGeometryDescriptor*
            MTL4::AccelerationStructureMotionBoundingBoxGeometryDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return Object::init<AccelerationStructureMotionBoundingBoxGeometryDescriptor>();
}

_MTL_INLINE void MTL4::AccelerationStructureMotionBoundingBoxGeometryDescriptor::setBoundingBoxBuffers(
    const BufferRange boundingBoxBuffers) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBoundingBoxBuffers_), boundingBoxBuffers);
}

_MTL_INLINE void MTL4::AccelerationStructureMotionBoundingBoxGeometryDescriptor::setBoundingBoxCount(
    const NS::UInteger boundingBoxCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBoundingBoxCount_), boundingBoxCount);
}

_MTL_INLINE void MTL4::AccelerationStructureMotionBoundingBoxGeometryDescriptor::setBoundingBoxStride(
    const NS::UInteger boundingBoxStride) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBoundingBoxStride_), boundingBoxStride);
}

_MTL_INLINE MTL4::AccelerationStructureCurveGeometryDescriptor*
            MTL4::AccelerationStructureCurveGeometryDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return Object::alloc<AccelerationStructureCurveGeometryDescriptor>(
        _MTL_PRIVATE_CLS(MTL4AccelerationStructureCurveGeometryDescriptor));
}

_MTL_INLINE MTL4::BufferRange MTL4::AccelerationStructureCurveGeometryDescriptor::controlPointBuffer() const
{
    return sendMessage<BufferRange>(this, _MTL_PRIVATE_SEL(controlPointBuffer));
}

_MTL_INLINE NS::UInteger MTL4::AccelerationStructureCurveGeometryDescriptor::controlPointCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(controlPointCount));
}

_MTL_INLINE MTL::AttributeFormat MTL4::AccelerationStructureCurveGeometryDescriptor::controlPointFormat() const
{
    return sendMessage<MTL::AttributeFormat>(this, _MTL_PRIVATE_SEL(controlPointFormat));
}

_MTL_INLINE NS::UInteger MTL4::AccelerationStructureCurveGeometryDescriptor::controlPointStride() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(controlPointStride));
}

_MTL_INLINE MTL::CurveBasis MTL4::AccelerationStructureCurveGeometryDescriptor::curveBasis() const
{
    return sendMessage<MTL::CurveBasis>(this, _MTL_PRIVATE_SEL(curveBasis));
}

_MTL_INLINE MTL::CurveEndCaps MTL4::AccelerationStructureCurveGeometryDescriptor::curveEndCaps() const
{
    return sendMessage<MTL::CurveEndCaps>(this, _MTL_PRIVATE_SEL(curveEndCaps));
}

_MTL_INLINE MTL::CurveType MTL4::AccelerationStructureCurveGeometryDescriptor::curveType() const
{
    return sendMessage<MTL::CurveType>(this, _MTL_PRIVATE_SEL(curveType));
}

_MTL_INLINE MTL4::BufferRange MTL4::AccelerationStructureCurveGeometryDescriptor::indexBuffer() const
{
    return sendMessage<BufferRange>(this, _MTL_PRIVATE_SEL(indexBuffer));
}

_MTL_INLINE MTL::IndexType MTL4::AccelerationStructureCurveGeometryDescriptor::indexType() const
{
    return sendMessage<MTL::IndexType>(this, _MTL_PRIVATE_SEL(indexType));
}

_MTL_INLINE MTL4::AccelerationStructureCurveGeometryDescriptor*
            MTL4::AccelerationStructureCurveGeometryDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return Object::init<AccelerationStructureCurveGeometryDescriptor>();
}

_MTL_INLINE MTL4::BufferRange MTL4::AccelerationStructureCurveGeometryDescriptor::radiusBuffer() const
{
    return sendMessage<BufferRange>(this, _MTL_PRIVATE_SEL(radiusBuffer));
}

_MTL_INLINE MTL::AttributeFormat MTL4::AccelerationStructureCurveGeometryDescriptor::radiusFormat() const
{
    return sendMessage<MTL::AttributeFormat>(this, _MTL_PRIVATE_SEL(radiusFormat));
}

_MTL_INLINE NS::UInteger MTL4::AccelerationStructureCurveGeometryDescriptor::radiusStride() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(radiusStride));
}

_MTL_INLINE NS::UInteger MTL4::AccelerationStructureCurveGeometryDescriptor::segmentControlPointCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(segmentControlPointCount));
}

_MTL_INLINE NS::UInteger MTL4::AccelerationStructureCurveGeometryDescriptor::segmentCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(segmentCount));
}

_MTL_INLINE void MTL4::AccelerationStructureCurveGeometryDescriptor::setControlPointBuffer(
    const BufferRange controlPointBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setControlPointBuffer_), controlPointBuffer);
}

_MTL_INLINE void MTL4::AccelerationStructureCurveGeometryDescriptor::setControlPointCount(
    const NS::UInteger controlPointCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setControlPointCount_), controlPointCount);
}

_MTL_INLINE void MTL4::AccelerationStructureCurveGeometryDescriptor::setControlPointFormat(
    const MTL::AttributeFormat controlPointFormat) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setControlPointFormat_), controlPointFormat);
}

_MTL_INLINE void MTL4::AccelerationStructureCurveGeometryDescriptor::setControlPointStride(
    const NS::UInteger controlPointStride) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setControlPointStride_), controlPointStride);
}

_MTL_INLINE void MTL4::AccelerationStructureCurveGeometryDescriptor::setCurveBasis(
    const MTL::CurveBasis curveBasis) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setCurveBasis_), curveBasis);
}

_MTL_INLINE void MTL4::AccelerationStructureCurveGeometryDescriptor::setCurveEndCaps(
    const MTL::CurveEndCaps curveEndCaps) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setCurveEndCaps_), curveEndCaps);
}

_MTL_INLINE void MTL4::AccelerationStructureCurveGeometryDescriptor::setCurveType(const MTL::CurveType curveType) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setCurveType_), curveType);
}

_MTL_INLINE void MTL4::AccelerationStructureCurveGeometryDescriptor::setIndexBuffer(const BufferRange indexBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setIndexBuffer_), indexBuffer);
}

_MTL_INLINE void MTL4::AccelerationStructureCurveGeometryDescriptor::setIndexType(const MTL::IndexType indexType) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setIndexType_), indexType);
}

_MTL_INLINE void MTL4::AccelerationStructureCurveGeometryDescriptor::setRadiusBuffer(
    const BufferRange radiusBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRadiusBuffer_), radiusBuffer);
}

_MTL_INLINE void MTL4::AccelerationStructureCurveGeometryDescriptor::setRadiusFormat(
    const MTL::AttributeFormat radiusFormat) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRadiusFormat_), radiusFormat);
}

_MTL_INLINE void MTL4::AccelerationStructureCurveGeometryDescriptor::setRadiusStride(
    const NS::UInteger radiusStride) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRadiusStride_), radiusStride);
}

_MTL_INLINE void MTL4::AccelerationStructureCurveGeometryDescriptor::setSegmentControlPointCount(
    const NS::UInteger segmentControlPointCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSegmentControlPointCount_), segmentControlPointCount);
}

_MTL_INLINE void MTL4::AccelerationStructureCurveGeometryDescriptor::setSegmentCount(
    const NS::UInteger segmentCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSegmentCount_), segmentCount);
}

_MTL_INLINE MTL4::AccelerationStructureMotionCurveGeometryDescriptor*
            MTL4::AccelerationStructureMotionCurveGeometryDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return Object::alloc<AccelerationStructureMotionCurveGeometryDescriptor>(
        _MTL_PRIVATE_CLS(MTL4AccelerationStructureMotionCurveGeometryDescriptor));
}

_MTL_INLINE MTL4::BufferRange MTL4::AccelerationStructureMotionCurveGeometryDescriptor::controlPointBuffers() const
{
    return sendMessage<BufferRange>(this, _MTL_PRIVATE_SEL(controlPointBuffers));
}

_MTL_INLINE NS::UInteger MTL4::AccelerationStructureMotionCurveGeometryDescriptor::controlPointCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(controlPointCount));
}

_MTL_INLINE MTL::AttributeFormat MTL4::AccelerationStructureMotionCurveGeometryDescriptor::controlPointFormat() const
{
    return sendMessage<MTL::AttributeFormat>(this, _MTL_PRIVATE_SEL(controlPointFormat));
}

_MTL_INLINE NS::UInteger MTL4::AccelerationStructureMotionCurveGeometryDescriptor::controlPointStride() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(controlPointStride));
}

_MTL_INLINE MTL::CurveBasis MTL4::AccelerationStructureMotionCurveGeometryDescriptor::curveBasis() const
{
    return sendMessage<MTL::CurveBasis>(this, _MTL_PRIVATE_SEL(curveBasis));
}

_MTL_INLINE MTL::CurveEndCaps MTL4::AccelerationStructureMotionCurveGeometryDescriptor::curveEndCaps() const
{
    return sendMessage<MTL::CurveEndCaps>(this, _MTL_PRIVATE_SEL(curveEndCaps));
}

_MTL_INLINE MTL::CurveType MTL4::AccelerationStructureMotionCurveGeometryDescriptor::curveType() const
{
    return sendMessage<MTL::CurveType>(this, _MTL_PRIVATE_SEL(curveType));
}

_MTL_INLINE MTL4::BufferRange MTL4::AccelerationStructureMotionCurveGeometryDescriptor::indexBuffer() const
{
    return sendMessage<BufferRange>(this, _MTL_PRIVATE_SEL(indexBuffer));
}

_MTL_INLINE MTL::IndexType MTL4::AccelerationStructureMotionCurveGeometryDescriptor::indexType() const
{
    return sendMessage<MTL::IndexType>(this, _MTL_PRIVATE_SEL(indexType));
}

_MTL_INLINE MTL4::AccelerationStructureMotionCurveGeometryDescriptor*
            MTL4::AccelerationStructureMotionCurveGeometryDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return Object::init<AccelerationStructureMotionCurveGeometryDescriptor>();
}

_MTL_INLINE MTL4::BufferRange MTL4::AccelerationStructureMotionCurveGeometryDescriptor::radiusBuffers() const
{
    return sendMessage<BufferRange>(this, _MTL_PRIVATE_SEL(radiusBuffers));
}

_MTL_INLINE MTL::AttributeFormat MTL4::AccelerationStructureMotionCurveGeometryDescriptor::radiusFormat() const
{
    return sendMessage<MTL::AttributeFormat>(this, _MTL_PRIVATE_SEL(radiusFormat));
}

_MTL_INLINE NS::UInteger MTL4::AccelerationStructureMotionCurveGeometryDescriptor::radiusStride() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(radiusStride));
}

_MTL_INLINE NS::UInteger MTL4::AccelerationStructureMotionCurveGeometryDescriptor::segmentControlPointCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(segmentControlPointCount));
}

_MTL_INLINE NS::UInteger MTL4::AccelerationStructureMotionCurveGeometryDescriptor::segmentCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(segmentCount));
}

_MTL_INLINE void MTL4::AccelerationStructureMotionCurveGeometryDescriptor::setControlPointBuffers(
    const BufferRange controlPointBuffers) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setControlPointBuffers_), controlPointBuffers);
}

_MTL_INLINE void MTL4::AccelerationStructureMotionCurveGeometryDescriptor::setControlPointCount(
    const NS::UInteger controlPointCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setControlPointCount_), controlPointCount);
}

_MTL_INLINE void MTL4::AccelerationStructureMotionCurveGeometryDescriptor::setControlPointFormat(
    const MTL::AttributeFormat controlPointFormat) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setControlPointFormat_), controlPointFormat);
}

_MTL_INLINE void MTL4::AccelerationStructureMotionCurveGeometryDescriptor::setControlPointStride(
    const NS::UInteger controlPointStride) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setControlPointStride_), controlPointStride);
}

_MTL_INLINE void MTL4::AccelerationStructureMotionCurveGeometryDescriptor::setCurveBasis(
    const MTL::CurveBasis curveBasis) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setCurveBasis_), curveBasis);
}

_MTL_INLINE void MTL4::AccelerationStructureMotionCurveGeometryDescriptor::setCurveEndCaps(
    const MTL::CurveEndCaps curveEndCaps) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setCurveEndCaps_), curveEndCaps);
}

_MTL_INLINE void MTL4::AccelerationStructureMotionCurveGeometryDescriptor::setCurveType(
    const MTL::CurveType curveType) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setCurveType_), curveType);
}

_MTL_INLINE void MTL4::AccelerationStructureMotionCurveGeometryDescriptor::setIndexBuffer(
    const BufferRange indexBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setIndexBuffer_), indexBuffer);
}

_MTL_INLINE void MTL4::AccelerationStructureMotionCurveGeometryDescriptor::setIndexType(
    const MTL::IndexType indexType) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setIndexType_), indexType);
}

_MTL_INLINE void MTL4::AccelerationStructureMotionCurveGeometryDescriptor::setRadiusBuffers(
    const BufferRange radiusBuffers) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRadiusBuffers_), radiusBuffers);
}

_MTL_INLINE void MTL4::AccelerationStructureMotionCurveGeometryDescriptor::setRadiusFormat(
    const MTL::AttributeFormat radiusFormat) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRadiusFormat_), radiusFormat);
}

_MTL_INLINE void MTL4::AccelerationStructureMotionCurveGeometryDescriptor::setRadiusStride(
    const NS::UInteger radiusStride) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRadiusStride_), radiusStride);
}

_MTL_INLINE void MTL4::AccelerationStructureMotionCurveGeometryDescriptor::setSegmentControlPointCount(
    const NS::UInteger segmentControlPointCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSegmentControlPointCount_), segmentControlPointCount);
}

_MTL_INLINE void MTL4::AccelerationStructureMotionCurveGeometryDescriptor::setSegmentCount(
    const NS::UInteger segmentCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSegmentCount_), segmentCount);
}

_MTL_INLINE MTL4::InstanceAccelerationStructureDescriptor* MTL4::InstanceAccelerationStructureDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return Object::alloc<InstanceAccelerationStructureDescriptor>(
        _MTL_PRIVATE_CLS(MTL4InstanceAccelerationStructureDescriptor));
}

_MTL_INLINE MTL4::InstanceAccelerationStructureDescriptor* MTL4::InstanceAccelerationStructureDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return Object::init<InstanceAccelerationStructureDescriptor>();
}

_MTL_INLINE NS::UInteger MTL4::InstanceAccelerationStructureDescriptor::instanceCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(instanceCount));
}

_MTL_INLINE MTL4::BufferRange MTL4::InstanceAccelerationStructureDescriptor::instanceDescriptorBuffer() const
{
    return sendMessage<BufferRange>(this, _MTL_PRIVATE_SEL(instanceDescriptorBuffer));
}

_MTL_INLINE NS::UInteger MTL4::InstanceAccelerationStructureDescriptor::instanceDescriptorStride() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(instanceDescriptorStride));
}

_MTL_INLINE MTL::AccelerationStructureInstanceDescriptorType
            MTL4::InstanceAccelerationStructureDescriptor::instanceDescriptorType() const
{
    return sendMessage<MTL::AccelerationStructureInstanceDescriptorType>(this,
                                                                         _MTL_PRIVATE_SEL(instanceDescriptorType));
}

_MTL_INLINE MTL::MatrixLayout MTL4::InstanceAccelerationStructureDescriptor::instanceTransformationMatrixLayout() const
{
    return sendMessage<MTL::MatrixLayout>(this, _MTL_PRIVATE_SEL(instanceTransformationMatrixLayout));
}

_MTL_INLINE MTL4::BufferRange MTL4::InstanceAccelerationStructureDescriptor::motionTransformBuffer() const
{
    return sendMessage<BufferRange>(this, _MTL_PRIVATE_SEL(motionTransformBuffer));
}

_MTL_INLINE NS::UInteger MTL4::InstanceAccelerationStructureDescriptor::motionTransformCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(motionTransformCount));
}

_MTL_INLINE NS::UInteger MTL4::InstanceAccelerationStructureDescriptor::motionTransformStride() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(motionTransformStride));
}

_MTL_INLINE MTL::TransformType MTL4::InstanceAccelerationStructureDescriptor::motionTransformType() const
{
    return sendMessage<MTL::TransformType>(this, _MTL_PRIVATE_SEL(motionTransformType));
}

_MTL_INLINE void MTL4::InstanceAccelerationStructureDescriptor::setInstanceCount(const NS::UInteger instanceCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setInstanceCount_), instanceCount);
}

_MTL_INLINE void MTL4::InstanceAccelerationStructureDescriptor::setInstanceDescriptorBuffer(
    const BufferRange instanceDescriptorBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setInstanceDescriptorBuffer_), instanceDescriptorBuffer);
}

_MTL_INLINE void MTL4::InstanceAccelerationStructureDescriptor::setInstanceDescriptorStride(
    const NS::UInteger instanceDescriptorStride) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setInstanceDescriptorStride_), instanceDescriptorStride);
}

_MTL_INLINE void MTL4::InstanceAccelerationStructureDescriptor::setInstanceDescriptorType(
    const MTL::AccelerationStructureInstanceDescriptorType instanceDescriptorType) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setInstanceDescriptorType_), instanceDescriptorType);
}

_MTL_INLINE void MTL4::InstanceAccelerationStructureDescriptor::setInstanceTransformationMatrixLayout(
    const MTL::MatrixLayout instanceTransformationMatrixLayout) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setInstanceTransformationMatrixLayout_), instanceTransformationMatrixLayout);
}

_MTL_INLINE void MTL4::InstanceAccelerationStructureDescriptor::setMotionTransformBuffer(
    const BufferRange motionTransformBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMotionTransformBuffer_), motionTransformBuffer);
}

_MTL_INLINE void MTL4::InstanceAccelerationStructureDescriptor::setMotionTransformCount(
    const NS::UInteger motionTransformCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMotionTransformCount_), motionTransformCount);
}

_MTL_INLINE void MTL4::InstanceAccelerationStructureDescriptor::setMotionTransformStride(
    const NS::UInteger motionTransformStride) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMotionTransformStride_), motionTransformStride);
}

_MTL_INLINE void MTL4::InstanceAccelerationStructureDescriptor::setMotionTransformType(
    const MTL::TransformType motionTransformType) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMotionTransformType_), motionTransformType);
}

_MTL_INLINE MTL4::IndirectInstanceAccelerationStructureDescriptor*
            MTL4::IndirectInstanceAccelerationStructureDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return Object::alloc<IndirectInstanceAccelerationStructureDescriptor>(
        _MTL_PRIVATE_CLS(MTL4IndirectInstanceAccelerationStructureDescriptor));
}

_MTL_INLINE MTL4::IndirectInstanceAccelerationStructureDescriptor*
            MTL4::IndirectInstanceAccelerationStructureDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return Object::init<IndirectInstanceAccelerationStructureDescriptor>();
}

_MTL_INLINE MTL4::BufferRange MTL4::IndirectInstanceAccelerationStructureDescriptor::instanceCountBuffer() const
{
    return sendMessage<BufferRange>(this, _MTL_PRIVATE_SEL(instanceCountBuffer));
}

_MTL_INLINE MTL4::BufferRange MTL4::IndirectInstanceAccelerationStructureDescriptor::instanceDescriptorBuffer() const
{
    return sendMessage<BufferRange>(this, _MTL_PRIVATE_SEL(instanceDescriptorBuffer));
}

_MTL_INLINE NS::UInteger MTL4::IndirectInstanceAccelerationStructureDescriptor::instanceDescriptorStride() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(instanceDescriptorStride));
}

_MTL_INLINE MTL::AccelerationStructureInstanceDescriptorType
            MTL4::IndirectInstanceAccelerationStructureDescriptor::instanceDescriptorType() const
{
    return sendMessage<MTL::AccelerationStructureInstanceDescriptorType>(this,
                                                                         _MTL_PRIVATE_SEL(instanceDescriptorType));
}

_MTL_INLINE MTL::MatrixLayout
            MTL4::IndirectInstanceAccelerationStructureDescriptor::instanceTransformationMatrixLayout() const
{
    return sendMessage<MTL::MatrixLayout>(this, _MTL_PRIVATE_SEL(instanceTransformationMatrixLayout));
}

_MTL_INLINE NS::UInteger MTL4::IndirectInstanceAccelerationStructureDescriptor::maxInstanceCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxInstanceCount));
}

_MTL_INLINE NS::UInteger MTL4::IndirectInstanceAccelerationStructureDescriptor::maxMotionTransformCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxMotionTransformCount));
}

_MTL_INLINE MTL4::BufferRange MTL4::IndirectInstanceAccelerationStructureDescriptor::motionTransformBuffer() const
{
    return sendMessage<BufferRange>(this, _MTL_PRIVATE_SEL(motionTransformBuffer));
}

_MTL_INLINE MTL4::BufferRange MTL4::IndirectInstanceAccelerationStructureDescriptor::motionTransformCountBuffer() const
{
    return sendMessage<BufferRange>(this, _MTL_PRIVATE_SEL(motionTransformCountBuffer));
}

_MTL_INLINE NS::UInteger MTL4::IndirectInstanceAccelerationStructureDescriptor::motionTransformStride() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(motionTransformStride));
}

_MTL_INLINE MTL::TransformType MTL4::IndirectInstanceAccelerationStructureDescriptor::motionTransformType() const
{
    return sendMessage<MTL::TransformType>(this, _MTL_PRIVATE_SEL(motionTransformType));
}

_MTL_INLINE void MTL4::IndirectInstanceAccelerationStructureDescriptor::setInstanceCountBuffer(
    const BufferRange instanceCountBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setInstanceCountBuffer_), instanceCountBuffer);
}

_MTL_INLINE void MTL4::IndirectInstanceAccelerationStructureDescriptor::setInstanceDescriptorBuffer(
    const BufferRange instanceDescriptorBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setInstanceDescriptorBuffer_), instanceDescriptorBuffer);
}

_MTL_INLINE void MTL4::IndirectInstanceAccelerationStructureDescriptor::setInstanceDescriptorStride(
    const NS::UInteger instanceDescriptorStride) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setInstanceDescriptorStride_), instanceDescriptorStride);
}

_MTL_INLINE void MTL4::IndirectInstanceAccelerationStructureDescriptor::setInstanceDescriptorType(
    const MTL::AccelerationStructureInstanceDescriptorType instanceDescriptorType) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setInstanceDescriptorType_), instanceDescriptorType);
}

_MTL_INLINE void MTL4::IndirectInstanceAccelerationStructureDescriptor::setInstanceTransformationMatrixLayout(
    const MTL::MatrixLayout instanceTransformationMatrixLayout) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setInstanceTransformationMatrixLayout_), instanceTransformationMatrixLayout);
}

_MTL_INLINE void MTL4::IndirectInstanceAccelerationStructureDescriptor::setMaxInstanceCount(
    const NS::UInteger maxInstanceCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxInstanceCount_), maxInstanceCount);
}

_MTL_INLINE void MTL4::IndirectInstanceAccelerationStructureDescriptor::setMaxMotionTransformCount(
    const NS::UInteger maxMotionTransformCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxMotionTransformCount_), maxMotionTransformCount);
}

_MTL_INLINE void MTL4::IndirectInstanceAccelerationStructureDescriptor::setMotionTransformBuffer(
    const BufferRange motionTransformBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMotionTransformBuffer_), motionTransformBuffer);
}

_MTL_INLINE void MTL4::IndirectInstanceAccelerationStructureDescriptor::setMotionTransformCountBuffer(
    const BufferRange motionTransformCountBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMotionTransformCountBuffer_), motionTransformCountBuffer);
}

_MTL_INLINE void MTL4::IndirectInstanceAccelerationStructureDescriptor::setMotionTransformStride(
    const NS::UInteger motionTransformStride) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMotionTransformStride_), motionTransformStride);
}

_MTL_INLINE void MTL4::IndirectInstanceAccelerationStructureDescriptor::setMotionTransformType(
    const MTL::TransformType motionTransformType) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMotionTransformType_), motionTransformType);
}
