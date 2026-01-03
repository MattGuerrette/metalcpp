//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLAccelerationStructure.hpp
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
#include "MTLAccelerationStructureTypes.hpp"
#include "MTLArgument.hpp"
#include "MTLDefines.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"
#include "MTLResource.hpp"
#include "MTLStageInputOutputDescriptor.hpp"
#include "MTLTypes.hpp"

namespace MTL
{
    class AccelerationStructureBoundingBoxGeometryDescriptor;
    class AccelerationStructureCurveGeometryDescriptor;
    class AccelerationStructureDescriptor;
    class AccelerationStructureGeometryDescriptor;
    class AccelerationStructureMotionBoundingBoxGeometryDescriptor;
    class AccelerationStructureMotionCurveGeometryDescriptor;
    class AccelerationStructureMotionTriangleGeometryDescriptor;
    class AccelerationStructureTriangleGeometryDescriptor;
    class Buffer;
    class IndirectInstanceAccelerationStructureDescriptor;
    class InstanceAccelerationStructureDescriptor;
    class MotionKeyframeData;
    class PrimitiveAccelerationStructureDescriptor;
} // namespace MTL

namespace MTL
{
    _MTL_ENUM(NS::Integer, MatrixLayout){
        MatrixLayoutColumnMajor = 0,
        MatrixLayoutRowMajor    = 1,
    };

    _MTL_ENUM(uint32_t, MotionBorderMode){
        MotionBorderModeClamp  = 0,
        MotionBorderModeVanish = 1,
    };

    _MTL_ENUM(NS::Integer, CurveType){
        CurveTypeRound = 0,
        CurveTypeFlat  = 1,
    };

    _MTL_ENUM(NS::Integer, CurveBasis){
        CurveBasisBSpline    = 0,
        CurveBasisCatmullRom = 1,
        CurveBasisLinear     = 2,
        CurveBasisBezier     = 3,
    };

    _MTL_ENUM(NS::Integer, CurveEndCaps){
        CurveEndCapsNone   = 0,
        CurveEndCapsDisk   = 1,
        CurveEndCapsSphere = 2,
    };

    _MTL_ENUM(NS::UInteger, AccelerationStructureInstanceDescriptorType){
        AccelerationStructureInstanceDescriptorTypeDefault        = 0,
        AccelerationStructureInstanceDescriptorTypeUserID         = 1,
        AccelerationStructureInstanceDescriptorTypeMotion         = 2,
        AccelerationStructureInstanceDescriptorTypeIndirect       = 3,
        AccelerationStructureInstanceDescriptorTypeIndirectMotion = 4,
    };

    _MTL_ENUM(NS::Integer, TransformType){
        TransformTypePackedFloat4x3 = 0,
        TransformTypeComponent      = 1,
    };

    _MTL_OPTIONS(NS::UInteger, AccelerationStructureRefitOptions){
        AccelerationStructureRefitOptionVertexData       = 1,
        AccelerationStructureRefitOptionPerPrimitiveData = 1 << 1,
    };

    _MTL_OPTIONS(NS::UInteger, AccelerationStructureUsage){
        AccelerationStructureUsageNone                   = 0,
        AccelerationStructureUsageRefit                  = 1,
        AccelerationStructureUsagePreferFastBuild        = 1 << 1,
        AccelerationStructureUsageExtendedLimits         = 1 << 2,
        AccelerationStructureUsagePreferFastIntersection = 1 << 4,
        AccelerationStructureUsageMinimizeMemory         = 1 << 5,
    };

    _MTL_OPTIONS(uint32_t, AccelerationStructureInstanceOptions){
        AccelerationStructureInstanceOptionNone                                       = 0,
        AccelerationStructureInstanceOptionDisableTriangleCulling                     = 1,
        AccelerationStructureInstanceOptionTriangleFrontFacingWindingCounterClockwise = 1 << 1,
        AccelerationStructureInstanceOptionOpaque                                     = 1 << 2,
        AccelerationStructureInstanceOptionNonOpaque                                  = 1 << 3,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlaccelerationstructureinstancedescriptor
    struct AccelerationStructureInstanceDescriptor
    {
        PackedFloat4x3                       transformationMatrix;
        AccelerationStructureInstanceOptions options;
        uint32_t                             mask;
        uint32_t                             intersectionFunctionTableOffset;
        uint32_t                             accelerationStructureIndex;
    } _MTL_PACKED;

    /// @see https://developer.apple.com/documentation/metal/mtlaccelerationstructureuseridinstancedescriptor
    struct AccelerationStructureUserIDInstanceDescriptor
    {
        PackedFloat4x3                       transformationMatrix;
        AccelerationStructureInstanceOptions options;
        uint32_t                             mask;
        uint32_t                             intersectionFunctionTableOffset;
        uint32_t                             accelerationStructureIndex;
        uint32_t                             userID;
    } _MTL_PACKED;

    /// @see https://developer.apple.com/documentation/metal/mtlaccelerationstructuremotioninstancedescriptor
    struct AccelerationStructureMotionInstanceDescriptor
    {
        AccelerationStructureInstanceOptions options;
        uint32_t                             mask;
        uint32_t                             intersectionFunctionTableOffset;
        uint32_t                             accelerationStructureIndex;
        uint32_t                             userID;
        uint32_t                             motionTransformsStartIndex;
        uint32_t                             motionTransformsCount;
        MotionBorderMode                     motionStartBorderMode;
        MotionBorderMode                     motionEndBorderMode;
        float                                motionStartTime;
        float                                motionEndTime;
    } _MTL_PACKED;

    /// @see https://developer.apple.com/documentation/metal/mtlindirectaccelerationstructureinstancedescriptor
    struct IndirectAccelerationStructureInstanceDescriptor
    {
        PackedFloat4x3                       transformationMatrix;
        AccelerationStructureInstanceOptions options;
        uint32_t                             mask;
        uint32_t                             intersectionFunctionTableOffset;
        uint32_t                             userID;
        ResourceID                           accelerationStructureID;
    } _MTL_PACKED;

    /// @see https://developer.apple.com/documentation/metal/mtlindirectaccelerationstructuremotioninstancedescriptor
    struct IndirectAccelerationStructureMotionInstanceDescriptor
    {
        AccelerationStructureInstanceOptions options;
        uint32_t                             mask;
        uint32_t                             intersectionFunctionTableOffset;
        uint32_t                             userID;
        ResourceID                           accelerationStructureID;
        uint32_t                             motionTransformsStartIndex;
        uint32_t                             motionTransformsCount;
        MotionBorderMode                     motionStartBorderMode;
        MotionBorderMode                     motionEndBorderMode;
        float                                motionStartTime;
        float                                motionEndTime;
    } _MTL_PACKED;

    /// @see https://developer.apple.com/documentation/metal/mtlaccelerationstructuredescriptor
    class AccelerationStructureDescriptor : public NS::Copying<AccelerationStructureDescriptor>
    {
    public:
        static AccelerationStructureDescriptor* alloc();

        AccelerationStructureDescriptor* init();

        void                       setUsage(AccelerationStructureUsage usage) const;
        AccelerationStructureUsage usage() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlaccelerationstructuregeometrydescriptor
    class AccelerationStructureGeometryDescriptor : public NS::Copying<AccelerationStructureGeometryDescriptor>
    {
    public:
        static AccelerationStructureGeometryDescriptor* alloc();

        bool allowDuplicateIntersectionFunctionInvocation() const;

        AccelerationStructureGeometryDescriptor* init();

        NS::UInteger intersectionFunctionTableOffset() const;

        NS::String* label() const;

        bool opaque() const;

        Buffer*      primitiveDataBuffer() const;
        NS::UInteger primitiveDataBufferOffset() const;

        NS::UInteger primitiveDataElementSize() const;

        NS::UInteger primitiveDataStride() const;

        void setAllowDuplicateIntersectionFunctionInvocation(bool allowDuplicateIntersectionFunctionInvocation) const;

        void setIntersectionFunctionTableOffset(NS::UInteger intersectionFunctionTableOffset) const;

        void setLabel(const NS::String* label) const;

        void setOpaque(bool opaque) const;

        void setPrimitiveDataBuffer(const Buffer* primitiveDataBuffer) const;
        void setPrimitiveDataBufferOffset(NS::UInteger primitiveDataBufferOffset) const;

        void setPrimitiveDataElementSize(NS::UInteger primitiveDataElementSize) const;

        void setPrimitiveDataStride(NS::UInteger primitiveDataStride) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlindirectinstanceaccelerationstructuredescriptor
    class PrimitiveAccelerationStructureDescriptor
        : public NS::Copying<PrimitiveAccelerationStructureDescriptor, AccelerationStructureDescriptor>
    {
    public:
        static PrimitiveAccelerationStructureDescriptor* alloc();

        static PrimitiveAccelerationStructureDescriptor* descriptor();
        NS::Array*                                       geometryDescriptors() const;

        PrimitiveAccelerationStructureDescriptor* init();

        MotionBorderMode motionEndBorderMode() const;

        float motionEndTime() const;

        NS::UInteger motionKeyframeCount() const;

        MotionBorderMode motionStartBorderMode() const;

        float motionStartTime() const;

        void setGeometryDescriptors(const NS::Array* geometryDescriptors) const;

        void setMotionEndBorderMode(MotionBorderMode motionEndBorderMode) const;

        void setMotionEndTime(float motionEndTime) const;

        void setMotionKeyframeCount(NS::UInteger motionKeyframeCount) const;

        void setMotionStartBorderMode(MotionBorderMode motionStartBorderMode) const;

        void setMotionStartTime(float motionStartTime) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlaccelerationstructuretrianglegeometrydescriptor
    class AccelerationStructureTriangleGeometryDescriptor
        : public NS::Copying<AccelerationStructureTriangleGeometryDescriptor, AccelerationStructureGeometryDescriptor>
    {
    public:
        static AccelerationStructureTriangleGeometryDescriptor* alloc();

        static AccelerationStructureTriangleGeometryDescriptor* descriptor();

        Buffer*      indexBuffer() const;
        NS::UInteger indexBufferOffset() const;

        IndexType indexType() const;

        AccelerationStructureTriangleGeometryDescriptor* init();

        void setIndexBuffer(const Buffer* indexBuffer) const;
        void setIndexBufferOffset(NS::UInteger indexBufferOffset) const;

        void setIndexType(IndexType indexType) const;

        void setTransformationMatrixBuffer(const Buffer* transformationMatrixBuffer) const;
        void setTransformationMatrixBufferOffset(NS::UInteger transformationMatrixBufferOffset) const;

        void setTransformationMatrixLayout(MatrixLayout transformationMatrixLayout) const;

        void setTriangleCount(NS::UInteger triangleCount) const;

        void setVertexBuffer(const Buffer* vertexBuffer) const;
        void setVertexBufferOffset(NS::UInteger vertexBufferOffset) const;

        void setVertexFormat(AttributeFormat vertexFormat) const;

        void setVertexStride(NS::UInteger vertexStride) const;

        Buffer*      transformationMatrixBuffer() const;
        NS::UInteger transformationMatrixBufferOffset() const;

        MatrixLayout transformationMatrixLayout() const;

        NS::UInteger triangleCount() const;

        Buffer*      vertexBuffer() const;
        NS::UInteger vertexBufferOffset() const;

        AttributeFormat vertexFormat() const;

        NS::UInteger vertexStride() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlaccelerationstructureboundingboxgeometrydescriptor
    class AccelerationStructureBoundingBoxGeometryDescriptor
        : public NS::Copying<AccelerationStructureBoundingBoxGeometryDescriptor,
                             AccelerationStructureGeometryDescriptor>
    {
    public:
        static AccelerationStructureBoundingBoxGeometryDescriptor* alloc();

        Buffer*      boundingBoxBuffer() const;
        NS::UInteger boundingBoxBufferOffset() const;

        NS::UInteger boundingBoxCount() const;

        NS::UInteger boundingBoxStride() const;

        static AccelerationStructureBoundingBoxGeometryDescriptor* descriptor();

        AccelerationStructureBoundingBoxGeometryDescriptor* init();

        void setBoundingBoxBuffer(const Buffer* boundingBoxBuffer) const;
        void setBoundingBoxBufferOffset(NS::UInteger boundingBoxBufferOffset) const;

        void setBoundingBoxCount(NS::UInteger boundingBoxCount) const;

        void setBoundingBoxStride(NS::UInteger boundingBoxStride) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlmotionkeyframedata
    class MotionKeyframeData : public NS::Referencing<MotionKeyframeData>
    {
    public:
        static MotionKeyframeData* alloc();

        Buffer* buffer() const;

        static MotionKeyframeData* data();

        MotionKeyframeData* init();

        NS::UInteger offset() const;

        void setBuffer(const Buffer* buffer) const;

        void setOffset(NS::UInteger offset) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlaccelerationstructuremotiontrianglegeometrydescriptor
    class AccelerationStructureMotionTriangleGeometryDescriptor
        : public NS::Copying<AccelerationStructureMotionTriangleGeometryDescriptor,
                             AccelerationStructureGeometryDescriptor>
    {
    public:
        static AccelerationStructureMotionTriangleGeometryDescriptor* alloc();

        static AccelerationStructureMotionTriangleGeometryDescriptor* descriptor();

        Buffer*      indexBuffer() const;
        NS::UInteger indexBufferOffset() const;

        IndexType indexType() const;

        AccelerationStructureMotionTriangleGeometryDescriptor* init();

        void setIndexBuffer(const Buffer* indexBuffer) const;
        void setIndexBufferOffset(NS::UInteger indexBufferOffset) const;

        void setIndexType(IndexType indexType) const;

        void setTransformationMatrixBuffer(const Buffer* transformationMatrixBuffer) const;
        void setTransformationMatrixBufferOffset(NS::UInteger transformationMatrixBufferOffset) const;

        void setTransformationMatrixLayout(MatrixLayout transformationMatrixLayout) const;

        void setTriangleCount(NS::UInteger triangleCount) const;

        void setVertexBuffers(const NS::Array* vertexBuffers) const;

        void setVertexFormat(AttributeFormat vertexFormat) const;

        void setVertexStride(NS::UInteger vertexStride) const;

        Buffer*      transformationMatrixBuffer() const;
        NS::UInteger transformationMatrixBufferOffset() const;

        MatrixLayout transformationMatrixLayout() const;

        NS::UInteger triangleCount() const;

        NS::Array* vertexBuffers() const;

        AttributeFormat vertexFormat() const;

        NS::UInteger vertexStride() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlaccelerationstructuremotionboundingboxgeometrydescriptor
    class AccelerationStructureMotionBoundingBoxGeometryDescriptor
        : public NS::Copying<AccelerationStructureMotionBoundingBoxGeometryDescriptor,
                             AccelerationStructureGeometryDescriptor>
    {
    public:
        static AccelerationStructureMotionBoundingBoxGeometryDescriptor* alloc();

        NS::Array* boundingBoxBuffers() const;

        NS::UInteger boundingBoxCount() const;

        NS::UInteger boundingBoxStride() const;

        static AccelerationStructureMotionBoundingBoxGeometryDescriptor* descriptor();

        AccelerationStructureMotionBoundingBoxGeometryDescriptor* init();

        void setBoundingBoxBuffers(const NS::Array* boundingBoxBuffers) const;

        void setBoundingBoxCount(NS::UInteger boundingBoxCount) const;

        void setBoundingBoxStride(NS::UInteger boundingBoxStride) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlaccelerationstructurecurvegeometrydescriptor
    class AccelerationStructureCurveGeometryDescriptor
        : public NS::Copying<AccelerationStructureCurveGeometryDescriptor, AccelerationStructureGeometryDescriptor>
    {
    public:
        static AccelerationStructureCurveGeometryDescriptor* alloc();

        Buffer*      controlPointBuffer() const;
        NS::UInteger controlPointBufferOffset() const;

        NS::UInteger controlPointCount() const;

        AttributeFormat controlPointFormat() const;

        NS::UInteger controlPointStride() const;

        CurveBasis curveBasis() const;

        CurveEndCaps curveEndCaps() const;

        CurveType curveType() const;

        static AccelerationStructureCurveGeometryDescriptor* descriptor();

        Buffer*      indexBuffer() const;
        NS::UInteger indexBufferOffset() const;

        IndexType indexType() const;

        AccelerationStructureCurveGeometryDescriptor* init();

        Buffer*      radiusBuffer() const;
        NS::UInteger radiusBufferOffset() const;

        AttributeFormat radiusFormat() const;

        NS::UInteger radiusStride() const;

        NS::UInteger segmentControlPointCount() const;

        NS::UInteger segmentCount() const;

        void setControlPointBuffer(const Buffer* controlPointBuffer) const;
        void setControlPointBufferOffset(NS::UInteger controlPointBufferOffset) const;

        void setControlPointCount(NS::UInteger controlPointCount) const;

        void setControlPointFormat(AttributeFormat controlPointFormat) const;

        void setControlPointStride(NS::UInteger controlPointStride) const;

        void setCurveBasis(CurveBasis curveBasis) const;

        void setCurveEndCaps(CurveEndCaps curveEndCaps) const;

        void setCurveType(CurveType curveType) const;

        void setIndexBuffer(const Buffer* indexBuffer) const;
        void setIndexBufferOffset(NS::UInteger indexBufferOffset) const;

        void setIndexType(IndexType indexType) const;

        void setRadiusBuffer(const Buffer* radiusBuffer) const;
        void setRadiusBufferOffset(NS::UInteger radiusBufferOffset) const;

        void setRadiusFormat(AttributeFormat radiusFormat) const;

        void setRadiusStride(NS::UInteger radiusStride) const;

        void setSegmentControlPointCount(NS::UInteger segmentControlPointCount) const;

        void setSegmentCount(NS::UInteger segmentCount) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlaccelerationstructuremotioncurvegeometrydescriptor
    class AccelerationStructureMotionCurveGeometryDescriptor
        : public NS::Copying<AccelerationStructureMotionCurveGeometryDescriptor,
                             AccelerationStructureGeometryDescriptor>
    {
    public:
        static AccelerationStructureMotionCurveGeometryDescriptor* alloc();

        NS::Array* controlPointBuffers() const;

        NS::UInteger controlPointCount() const;

        AttributeFormat controlPointFormat() const;

        NS::UInteger controlPointStride() const;

        CurveBasis curveBasis() const;

        CurveEndCaps curveEndCaps() const;

        CurveType curveType() const;

        static AccelerationStructureMotionCurveGeometryDescriptor* descriptor();

        Buffer*      indexBuffer() const;
        NS::UInteger indexBufferOffset() const;

        IndexType indexType() const;

        AccelerationStructureMotionCurveGeometryDescriptor* init();

        NS::Array* radiusBuffers() const;

        AttributeFormat radiusFormat() const;

        NS::UInteger radiusStride() const;

        NS::UInteger segmentControlPointCount() const;

        NS::UInteger segmentCount() const;

        void setControlPointBuffers(const NS::Array* controlPointBuffers) const;

        void setControlPointCount(NS::UInteger controlPointCount) const;

        void setControlPointFormat(AttributeFormat controlPointFormat) const;

        void setControlPointStride(NS::UInteger controlPointStride) const;

        void setCurveBasis(CurveBasis curveBasis) const;

        void setCurveEndCaps(CurveEndCaps curveEndCaps) const;

        void setCurveType(CurveType curveType) const;

        void setIndexBuffer(const Buffer* indexBuffer) const;
        void setIndexBufferOffset(NS::UInteger indexBufferOffset) const;

        void setIndexType(IndexType indexType) const;

        void setRadiusBuffers(const NS::Array* radiusBuffers) const;

        void setRadiusFormat(AttributeFormat radiusFormat) const;

        void setRadiusStride(NS::UInteger radiusStride) const;

        void setSegmentControlPointCount(NS::UInteger segmentControlPointCount) const;

        void setSegmentCount(NS::UInteger segmentCount) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlinstanceaccelerationstructuredescriptor
    class InstanceAccelerationStructureDescriptor
        : public NS::Copying<InstanceAccelerationStructureDescriptor, AccelerationStructureDescriptor>
    {
    public:
        static InstanceAccelerationStructureDescriptor* alloc();

        static InstanceAccelerationStructureDescriptor* descriptor();

        InstanceAccelerationStructureDescriptor* init();

        NS::UInteger instanceCount() const;

        Buffer*      instanceDescriptorBuffer() const;
        NS::UInteger instanceDescriptorBufferOffset() const;

        NS::UInteger instanceDescriptorStride() const;

        AccelerationStructureInstanceDescriptorType instanceDescriptorType() const;

        MatrixLayout instanceTransformationMatrixLayout() const;

        NS::Array* instancedAccelerationStructures() const;

        Buffer*      motionTransformBuffer() const;
        NS::UInteger motionTransformBufferOffset() const;

        NS::UInteger motionTransformCount() const;

        NS::UInteger motionTransformStride() const;

        TransformType motionTransformType() const;

        void setInstanceCount(NS::UInteger instanceCount) const;

        void setInstanceDescriptorBuffer(const Buffer* instanceDescriptorBuffer) const;
        void setInstanceDescriptorBufferOffset(NS::UInteger instanceDescriptorBufferOffset) const;

        void setInstanceDescriptorStride(NS::UInteger instanceDescriptorStride) const;

        void setInstanceDescriptorType(AccelerationStructureInstanceDescriptorType instanceDescriptorType) const;

        void setInstanceTransformationMatrixLayout(MatrixLayout instanceTransformationMatrixLayout) const;

        void setInstancedAccelerationStructures(const NS::Array* instancedAccelerationStructures) const;

        void setMotionTransformBuffer(const Buffer* motionTransformBuffer) const;
        void setMotionTransformBufferOffset(NS::UInteger motionTransformBufferOffset) const;

        void setMotionTransformCount(NS::UInteger motionTransformCount) const;

        void setMotionTransformStride(NS::UInteger motionTransformStride) const;

        void setMotionTransformType(TransformType motionTransformType) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlindirectinstanceaccelerationstructuredescriptor
    class IndirectInstanceAccelerationStructureDescriptor
        : public NS::Copying<IndirectInstanceAccelerationStructureDescriptor, AccelerationStructureDescriptor>
    {
    public:
        static IndirectInstanceAccelerationStructureDescriptor* alloc();

        static IndirectInstanceAccelerationStructureDescriptor* descriptor();

        IndirectInstanceAccelerationStructureDescriptor* init();

        Buffer*      instanceCountBuffer() const;
        NS::UInteger instanceCountBufferOffset() const;

        Buffer*      instanceDescriptorBuffer() const;
        NS::UInteger instanceDescriptorBufferOffset() const;

        NS::UInteger instanceDescriptorStride() const;

        AccelerationStructureInstanceDescriptorType instanceDescriptorType() const;

        MatrixLayout instanceTransformationMatrixLayout() const;

        NS::UInteger maxInstanceCount() const;

        NS::UInteger maxMotionTransformCount() const;

        Buffer*      motionTransformBuffer() const;
        NS::UInteger motionTransformBufferOffset() const;

        Buffer*      motionTransformCountBuffer() const;
        NS::UInteger motionTransformCountBufferOffset() const;

        NS::UInteger motionTransformStride() const;

        TransformType motionTransformType() const;

        void setInstanceCountBuffer(const Buffer* instanceCountBuffer) const;
        void setInstanceCountBufferOffset(NS::UInteger instanceCountBufferOffset) const;

        void setInstanceDescriptorBuffer(const Buffer* instanceDescriptorBuffer) const;
        void setInstanceDescriptorBufferOffset(NS::UInteger instanceDescriptorBufferOffset) const;

        void setInstanceDescriptorStride(NS::UInteger instanceDescriptorStride) const;

        void setInstanceDescriptorType(AccelerationStructureInstanceDescriptorType instanceDescriptorType) const;

        void setInstanceTransformationMatrixLayout(MatrixLayout instanceTransformationMatrixLayout) const;

        void setMaxInstanceCount(NS::UInteger maxInstanceCount) const;

        void setMaxMotionTransformCount(NS::UInteger maxMotionTransformCount) const;

        void setMotionTransformBuffer(const Buffer* motionTransformBuffer) const;
        void setMotionTransformBufferOffset(NS::UInteger motionTransformBufferOffset) const;

        void setMotionTransformCountBuffer(const Buffer* motionTransformCountBuffer) const;
        void setMotionTransformCountBufferOffset(NS::UInteger motionTransformCountBufferOffset) const;

        void setMotionTransformStride(NS::UInteger motionTransformStride) const;

        void setMotionTransformType(TransformType motionTransformType) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlaccelerationstructure
    class AccelerationStructure : public NS::Referencing<AccelerationStructure, Resource>
    {
    public:
        ResourceID gpuResourceID() const;

        NS::UInteger size() const;
    };

} // namespace MTL

_MTL_INLINE MTL::AccelerationStructureDescriptor* MTL::AccelerationStructureDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<AccelerationStructureDescriptor>(_MTL_PRIVATE_CLS(MTLAccelerationStructureDescriptor));
}

_MTL_INLINE MTL::AccelerationStructureDescriptor* MTL::AccelerationStructureDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<AccelerationStructureDescriptor>();
}

_MTL_INLINE void MTL::AccelerationStructureDescriptor::setUsage(const AccelerationStructureUsage usage) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setUsage_), usage);
}

_MTL_INLINE MTL::AccelerationStructureUsage MTL::AccelerationStructureDescriptor::usage() const
{
    return sendMessage<AccelerationStructureUsage>(this, _MTL_PRIVATE_SEL(usage));
}

_MTL_INLINE MTL::AccelerationStructureGeometryDescriptor* MTL::AccelerationStructureGeometryDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<AccelerationStructureGeometryDescriptor>(
        _MTL_PRIVATE_CLS(MTLAccelerationStructureGeometryDescriptor));
}

_MTL_INLINE bool MTL::AccelerationStructureGeometryDescriptor::allowDuplicateIntersectionFunctionInvocation() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(allowDuplicateIntersectionFunctionInvocation));
}

_MTL_INLINE MTL::AccelerationStructureGeometryDescriptor* MTL::AccelerationStructureGeometryDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<AccelerationStructureGeometryDescriptor>();
}

_MTL_INLINE NS::UInteger MTL::AccelerationStructureGeometryDescriptor::intersectionFunctionTableOffset() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(intersectionFunctionTableOffset));
}

_MTL_INLINE NS::String* MTL::AccelerationStructureGeometryDescriptor::label() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
}

_MTL_INLINE bool MTL::AccelerationStructureGeometryDescriptor::opaque() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(opaque));
}

_MTL_INLINE MTL::Buffer* MTL::AccelerationStructureGeometryDescriptor::primitiveDataBuffer() const
{
    return sendMessage<Buffer*>(this, _MTL_PRIVATE_SEL(primitiveDataBuffer));
}

_MTL_INLINE NS::UInteger MTL::AccelerationStructureGeometryDescriptor::primitiveDataBufferOffset() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(primitiveDataBufferOffset));
}

_MTL_INLINE NS::UInteger MTL::AccelerationStructureGeometryDescriptor::primitiveDataElementSize() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(primitiveDataElementSize));
}

_MTL_INLINE NS::UInteger MTL::AccelerationStructureGeometryDescriptor::primitiveDataStride() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(primitiveDataStride));
}

_MTL_INLINE void MTL::AccelerationStructureGeometryDescriptor::setAllowDuplicateIntersectionFunctionInvocation(
    const bool allowDuplicateIntersectionFunctionInvocation) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(setAllowDuplicateIntersectionFunctionInvocation_),
                      allowDuplicateIntersectionFunctionInvocation);
}

_MTL_INLINE void MTL::AccelerationStructureGeometryDescriptor::setIntersectionFunctionTableOffset(
    const NS::UInteger intersectionFunctionTableOffset) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setIntersectionFunctionTableOffset_), intersectionFunctionTableOffset);
}

_MTL_INLINE void MTL::AccelerationStructureGeometryDescriptor::setLabel(const NS::String* label) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLabel_), label);
}

_MTL_INLINE void MTL::AccelerationStructureGeometryDescriptor::setOpaque(const bool opaque) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setOpaque_), opaque);
}

_MTL_INLINE void MTL::AccelerationStructureGeometryDescriptor::setPrimitiveDataBuffer(
    const Buffer* primitiveDataBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setPrimitiveDataBuffer_), primitiveDataBuffer);
}

_MTL_INLINE void MTL::AccelerationStructureGeometryDescriptor::setPrimitiveDataBufferOffset(
    const NS::UInteger primitiveDataBufferOffset) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setPrimitiveDataBufferOffset_), primitiveDataBufferOffset);
}

_MTL_INLINE void MTL::AccelerationStructureGeometryDescriptor::setPrimitiveDataElementSize(
    const NS::UInteger primitiveDataElementSize) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setPrimitiveDataElementSize_), primitiveDataElementSize);
}

_MTL_INLINE void MTL::AccelerationStructureGeometryDescriptor::setPrimitiveDataStride(
    const NS::UInteger primitiveDataStride) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setPrimitiveDataStride_), primitiveDataStride);
}

_MTL_INLINE MTL::PrimitiveAccelerationStructureDescriptor* MTL::PrimitiveAccelerationStructureDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<PrimitiveAccelerationStructureDescriptor>(
        _MTL_PRIVATE_CLS(MTLPrimitiveAccelerationStructureDescriptor));
}

_MTL_INLINE MTL::PrimitiveAccelerationStructureDescriptor* MTL::PrimitiveAccelerationStructureDescriptor::descriptor()
{
    return sendMessage<PrimitiveAccelerationStructureDescriptor*>(
        _MTL_PRIVATE_CLS(MTLPrimitiveAccelerationStructureDescriptor), _MTL_PRIVATE_SEL(descriptor));
}

_MTL_INLINE NS::Array* MTL::PrimitiveAccelerationStructureDescriptor::geometryDescriptors() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(geometryDescriptors));
}

_MTL_INLINE MTL::PrimitiveAccelerationStructureDescriptor* MTL::PrimitiveAccelerationStructureDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<PrimitiveAccelerationStructureDescriptor>();
}

_MTL_INLINE MTL::MotionBorderMode MTL::PrimitiveAccelerationStructureDescriptor::motionEndBorderMode() const
{
    return sendMessage<MotionBorderMode>(this, _MTL_PRIVATE_SEL(motionEndBorderMode));
}

_MTL_INLINE float MTL::PrimitiveAccelerationStructureDescriptor::motionEndTime() const
{
    return sendMessage<float>(this, _MTL_PRIVATE_SEL(motionEndTime));
}

_MTL_INLINE NS::UInteger MTL::PrimitiveAccelerationStructureDescriptor::motionKeyframeCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(motionKeyframeCount));
}

_MTL_INLINE MTL::MotionBorderMode MTL::PrimitiveAccelerationStructureDescriptor::motionStartBorderMode() const
{
    return sendMessage<MotionBorderMode>(this, _MTL_PRIVATE_SEL(motionStartBorderMode));
}

_MTL_INLINE float MTL::PrimitiveAccelerationStructureDescriptor::motionStartTime() const
{
    return sendMessage<float>(this, _MTL_PRIVATE_SEL(motionStartTime));
}

_MTL_INLINE void MTL::PrimitiveAccelerationStructureDescriptor::setGeometryDescriptors(
    const NS::Array* geometryDescriptors) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setGeometryDescriptors_), geometryDescriptors);
}

_MTL_INLINE void MTL::PrimitiveAccelerationStructureDescriptor::setMotionEndBorderMode(
    const MotionBorderMode motionEndBorderMode) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMotionEndBorderMode_), motionEndBorderMode);
}

_MTL_INLINE void MTL::PrimitiveAccelerationStructureDescriptor::setMotionEndTime(const float motionEndTime) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMotionEndTime_), motionEndTime);
}

_MTL_INLINE void MTL::PrimitiveAccelerationStructureDescriptor::setMotionKeyframeCount(
    const NS::UInteger motionKeyframeCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMotionKeyframeCount_), motionKeyframeCount);
}

_MTL_INLINE void MTL::PrimitiveAccelerationStructureDescriptor::setMotionStartBorderMode(
    const MotionBorderMode motionStartBorderMode) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMotionStartBorderMode_), motionStartBorderMode);
}

_MTL_INLINE void MTL::PrimitiveAccelerationStructureDescriptor::setMotionStartTime(const float motionStartTime) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMotionStartTime_), motionStartTime);
}

_MTL_INLINE MTL::AccelerationStructureTriangleGeometryDescriptor*
            MTL::AccelerationStructureTriangleGeometryDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<AccelerationStructureTriangleGeometryDescriptor>(
        _MTL_PRIVATE_CLS(MTLAccelerationStructureTriangleGeometryDescriptor));
}

_MTL_INLINE MTL::AccelerationStructureTriangleGeometryDescriptor*
            MTL::AccelerationStructureTriangleGeometryDescriptor::descriptor()
{
    return sendMessage<AccelerationStructureTriangleGeometryDescriptor*>(
        _MTL_PRIVATE_CLS(MTLAccelerationStructureTriangleGeometryDescriptor), _MTL_PRIVATE_SEL(descriptor));
}

_MTL_INLINE MTL::Buffer* MTL::AccelerationStructureTriangleGeometryDescriptor::indexBuffer() const
{
    return sendMessage<Buffer*>(this, _MTL_PRIVATE_SEL(indexBuffer));
}

_MTL_INLINE NS::UInteger MTL::AccelerationStructureTriangleGeometryDescriptor::indexBufferOffset() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(indexBufferOffset));
}

_MTL_INLINE MTL::IndexType MTL::AccelerationStructureTriangleGeometryDescriptor::indexType() const
{
    return sendMessage<IndexType>(this, _MTL_PRIVATE_SEL(indexType));
}

_MTL_INLINE MTL::AccelerationStructureTriangleGeometryDescriptor*
            MTL::AccelerationStructureTriangleGeometryDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<AccelerationStructureTriangleGeometryDescriptor>();
}

_MTL_INLINE void MTL::AccelerationStructureTriangleGeometryDescriptor::setIndexBuffer(const Buffer* indexBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setIndexBuffer_), indexBuffer);
}

_MTL_INLINE void MTL::AccelerationStructureTriangleGeometryDescriptor::setIndexBufferOffset(
    const NS::UInteger indexBufferOffset) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setIndexBufferOffset_), indexBufferOffset);
}

_MTL_INLINE void MTL::AccelerationStructureTriangleGeometryDescriptor::setIndexType(const IndexType indexType) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setIndexType_), indexType);
}

_MTL_INLINE void MTL::AccelerationStructureTriangleGeometryDescriptor::setTransformationMatrixBuffer(
    const Buffer* transformationMatrixBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTransformationMatrixBuffer_), transformationMatrixBuffer);
}

_MTL_INLINE void MTL::AccelerationStructureTriangleGeometryDescriptor::setTransformationMatrixBufferOffset(
    const NS::UInteger transformationMatrixBufferOffset) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTransformationMatrixBufferOffset_), transformationMatrixBufferOffset);
}

_MTL_INLINE void MTL::AccelerationStructureTriangleGeometryDescriptor::setTransformationMatrixLayout(
    const MatrixLayout transformationMatrixLayout) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTransformationMatrixLayout_), transformationMatrixLayout);
}

_MTL_INLINE void MTL::AccelerationStructureTriangleGeometryDescriptor::setTriangleCount(
    const NS::UInteger triangleCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTriangleCount_), triangleCount);
}

_MTL_INLINE void MTL::AccelerationStructureTriangleGeometryDescriptor::setVertexBuffer(const Buffer* vertexBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVertexBuffer_), vertexBuffer);
}

_MTL_INLINE void MTL::AccelerationStructureTriangleGeometryDescriptor::setVertexBufferOffset(
    const NS::UInteger vertexBufferOffset) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVertexBufferOffset_), vertexBufferOffset);
}

_MTL_INLINE void MTL::AccelerationStructureTriangleGeometryDescriptor::setVertexFormat(
    const AttributeFormat vertexFormat) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVertexFormat_), vertexFormat);
}

_MTL_INLINE void MTL::AccelerationStructureTriangleGeometryDescriptor::setVertexStride(
    const NS::UInteger vertexStride) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVertexStride_), vertexStride);
}

_MTL_INLINE MTL::Buffer* MTL::AccelerationStructureTriangleGeometryDescriptor::transformationMatrixBuffer() const
{
    return sendMessage<Buffer*>(this, _MTL_PRIVATE_SEL(transformationMatrixBuffer));
}

_MTL_INLINE NS::UInteger MTL::AccelerationStructureTriangleGeometryDescriptor::transformationMatrixBufferOffset() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(transformationMatrixBufferOffset));
}

_MTL_INLINE MTL::MatrixLayout MTL::AccelerationStructureTriangleGeometryDescriptor::transformationMatrixLayout() const
{
    return sendMessage<MatrixLayout>(this, _MTL_PRIVATE_SEL(transformationMatrixLayout));
}

_MTL_INLINE NS::UInteger MTL::AccelerationStructureTriangleGeometryDescriptor::triangleCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(triangleCount));
}

_MTL_INLINE MTL::Buffer* MTL::AccelerationStructureTriangleGeometryDescriptor::vertexBuffer() const
{
    return sendMessage<Buffer*>(this, _MTL_PRIVATE_SEL(vertexBuffer));
}

_MTL_INLINE NS::UInteger MTL::AccelerationStructureTriangleGeometryDescriptor::vertexBufferOffset() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(vertexBufferOffset));
}

_MTL_INLINE MTL::AttributeFormat MTL::AccelerationStructureTriangleGeometryDescriptor::vertexFormat() const
{
    return sendMessage<AttributeFormat>(this, _MTL_PRIVATE_SEL(vertexFormat));
}

_MTL_INLINE NS::UInteger MTL::AccelerationStructureTriangleGeometryDescriptor::vertexStride() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(vertexStride));
}

_MTL_INLINE MTL::AccelerationStructureBoundingBoxGeometryDescriptor*
            MTL::AccelerationStructureBoundingBoxGeometryDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<AccelerationStructureBoundingBoxGeometryDescriptor>(
        _MTL_PRIVATE_CLS(MTLAccelerationStructureBoundingBoxGeometryDescriptor));
}

_MTL_INLINE MTL::Buffer* MTL::AccelerationStructureBoundingBoxGeometryDescriptor::boundingBoxBuffer() const
{
    return sendMessage<Buffer*>(this, _MTL_PRIVATE_SEL(boundingBoxBuffer));
}

_MTL_INLINE NS::UInteger MTL::AccelerationStructureBoundingBoxGeometryDescriptor::boundingBoxBufferOffset() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(boundingBoxBufferOffset));
}

_MTL_INLINE NS::UInteger MTL::AccelerationStructureBoundingBoxGeometryDescriptor::boundingBoxCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(boundingBoxCount));
}

_MTL_INLINE NS::UInteger MTL::AccelerationStructureBoundingBoxGeometryDescriptor::boundingBoxStride() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(boundingBoxStride));
}

_MTL_INLINE MTL::AccelerationStructureBoundingBoxGeometryDescriptor*
            MTL::AccelerationStructureBoundingBoxGeometryDescriptor::descriptor()
{
    return sendMessage<AccelerationStructureBoundingBoxGeometryDescriptor*>(
        _MTL_PRIVATE_CLS(MTLAccelerationStructureBoundingBoxGeometryDescriptor), _MTL_PRIVATE_SEL(descriptor));
}

_MTL_INLINE MTL::AccelerationStructureBoundingBoxGeometryDescriptor*
            MTL::AccelerationStructureBoundingBoxGeometryDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<AccelerationStructureBoundingBoxGeometryDescriptor>();
}

_MTL_INLINE void MTL::AccelerationStructureBoundingBoxGeometryDescriptor::setBoundingBoxBuffer(
    const Buffer* boundingBoxBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBoundingBoxBuffer_), boundingBoxBuffer);
}

_MTL_INLINE void MTL::AccelerationStructureBoundingBoxGeometryDescriptor::setBoundingBoxBufferOffset(
    const NS::UInteger boundingBoxBufferOffset) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBoundingBoxBufferOffset_), boundingBoxBufferOffset);
}

_MTL_INLINE void MTL::AccelerationStructureBoundingBoxGeometryDescriptor::setBoundingBoxCount(
    const NS::UInteger boundingBoxCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBoundingBoxCount_), boundingBoxCount);
}

_MTL_INLINE void MTL::AccelerationStructureBoundingBoxGeometryDescriptor::setBoundingBoxStride(
    const NS::UInteger boundingBoxStride) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBoundingBoxStride_), boundingBoxStride);
}

_MTL_INLINE MTL::MotionKeyframeData* MTL::MotionKeyframeData::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<MotionKeyframeData>(_MTL_PRIVATE_CLS(MTLMotionKeyframeData));
}

_MTL_INLINE MTL::Buffer* MTL::MotionKeyframeData::buffer() const
{
    return sendMessage<Buffer*>(this, _MTL_PRIVATE_SEL(buffer));
}

_MTL_INLINE MTL::MotionKeyframeData* MTL::MotionKeyframeData::data()
{
    return sendMessage<MotionKeyframeData*>(_MTL_PRIVATE_CLS(MTLMotionKeyframeData), _MTL_PRIVATE_SEL(data));
}

_MTL_INLINE MTL::MotionKeyframeData* MTL::MotionKeyframeData::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<MotionKeyframeData>();
}

_MTL_INLINE NS::UInteger MTL::MotionKeyframeData::offset() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(offset));
}

_MTL_INLINE void MTL::MotionKeyframeData::setBuffer(const Buffer* buffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBuffer_), buffer);
}

_MTL_INLINE void MTL::MotionKeyframeData::setOffset(const NS::UInteger offset) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setOffset_), offset);
}

_MTL_INLINE MTL::AccelerationStructureMotionTriangleGeometryDescriptor*
            MTL::AccelerationStructureMotionTriangleGeometryDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<AccelerationStructureMotionTriangleGeometryDescriptor>(
        _MTL_PRIVATE_CLS(MTLAccelerationStructureMotionTriangleGeometryDescriptor));
}

_MTL_INLINE MTL::AccelerationStructureMotionTriangleGeometryDescriptor*
            MTL::AccelerationStructureMotionTriangleGeometryDescriptor::descriptor()
{
    return sendMessage<AccelerationStructureMotionTriangleGeometryDescriptor*>(
        _MTL_PRIVATE_CLS(MTLAccelerationStructureMotionTriangleGeometryDescriptor), _MTL_PRIVATE_SEL(descriptor));
}

_MTL_INLINE MTL::Buffer* MTL::AccelerationStructureMotionTriangleGeometryDescriptor::indexBuffer() const
{
    return sendMessage<Buffer*>(this, _MTL_PRIVATE_SEL(indexBuffer));
}

_MTL_INLINE NS::UInteger MTL::AccelerationStructureMotionTriangleGeometryDescriptor::indexBufferOffset() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(indexBufferOffset));
}

_MTL_INLINE MTL::IndexType MTL::AccelerationStructureMotionTriangleGeometryDescriptor::indexType() const
{
    return sendMessage<IndexType>(this, _MTL_PRIVATE_SEL(indexType));
}

_MTL_INLINE MTL::AccelerationStructureMotionTriangleGeometryDescriptor*
            MTL::AccelerationStructureMotionTriangleGeometryDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<AccelerationStructureMotionTriangleGeometryDescriptor>();
}

_MTL_INLINE void MTL::AccelerationStructureMotionTriangleGeometryDescriptor::setIndexBuffer(
    const Buffer* indexBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setIndexBuffer_), indexBuffer);
}

_MTL_INLINE void MTL::AccelerationStructureMotionTriangleGeometryDescriptor::setIndexBufferOffset(
    const NS::UInteger indexBufferOffset) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setIndexBufferOffset_), indexBufferOffset);
}

_MTL_INLINE void MTL::AccelerationStructureMotionTriangleGeometryDescriptor::setIndexType(
    const IndexType indexType) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setIndexType_), indexType);
}

_MTL_INLINE void MTL::AccelerationStructureMotionTriangleGeometryDescriptor::setTransformationMatrixBuffer(
    const Buffer* transformationMatrixBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTransformationMatrixBuffer_), transformationMatrixBuffer);
}

_MTL_INLINE void MTL::AccelerationStructureMotionTriangleGeometryDescriptor::setTransformationMatrixBufferOffset(
    const NS::UInteger transformationMatrixBufferOffset) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTransformationMatrixBufferOffset_), transformationMatrixBufferOffset);
}

_MTL_INLINE void MTL::AccelerationStructureMotionTriangleGeometryDescriptor::setTransformationMatrixLayout(
    const MatrixLayout transformationMatrixLayout) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTransformationMatrixLayout_), transformationMatrixLayout);
}

_MTL_INLINE void MTL::AccelerationStructureMotionTriangleGeometryDescriptor::setTriangleCount(
    const NS::UInteger triangleCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTriangleCount_), triangleCount);
}

_MTL_INLINE void MTL::AccelerationStructureMotionTriangleGeometryDescriptor::setVertexBuffers(
    const NS::Array* vertexBuffers) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVertexBuffers_), vertexBuffers);
}

_MTL_INLINE void MTL::AccelerationStructureMotionTriangleGeometryDescriptor::setVertexFormat(
    const AttributeFormat vertexFormat) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVertexFormat_), vertexFormat);
}

_MTL_INLINE void MTL::AccelerationStructureMotionTriangleGeometryDescriptor::setVertexStride(
    const NS::UInteger vertexStride) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setVertexStride_), vertexStride);
}

_MTL_INLINE MTL::Buffer* MTL::AccelerationStructureMotionTriangleGeometryDescriptor::transformationMatrixBuffer() const
{
    return sendMessage<Buffer*>(this, _MTL_PRIVATE_SEL(transformationMatrixBuffer));
}

_MTL_INLINE NS::UInteger MTL::AccelerationStructureMotionTriangleGeometryDescriptor::transformationMatrixBufferOffset()
    const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(transformationMatrixBufferOffset));
}

_MTL_INLINE MTL::MatrixLayout MTL::AccelerationStructureMotionTriangleGeometryDescriptor::transformationMatrixLayout()
    const
{
    return sendMessage<MatrixLayout>(this, _MTL_PRIVATE_SEL(transformationMatrixLayout));
}

_MTL_INLINE NS::UInteger MTL::AccelerationStructureMotionTriangleGeometryDescriptor::triangleCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(triangleCount));
}

_MTL_INLINE NS::Array* MTL::AccelerationStructureMotionTriangleGeometryDescriptor::vertexBuffers() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(vertexBuffers));
}

_MTL_INLINE MTL::AttributeFormat MTL::AccelerationStructureMotionTriangleGeometryDescriptor::vertexFormat() const
{
    return sendMessage<AttributeFormat>(this, _MTL_PRIVATE_SEL(vertexFormat));
}

_MTL_INLINE NS::UInteger MTL::AccelerationStructureMotionTriangleGeometryDescriptor::vertexStride() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(vertexStride));
}

_MTL_INLINE MTL::AccelerationStructureMotionBoundingBoxGeometryDescriptor*
            MTL::AccelerationStructureMotionBoundingBoxGeometryDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<AccelerationStructureMotionBoundingBoxGeometryDescriptor>(
        _MTL_PRIVATE_CLS(MTLAccelerationStructureMotionBoundingBoxGeometryDescriptor));
}

_MTL_INLINE NS::Array* MTL::AccelerationStructureMotionBoundingBoxGeometryDescriptor::boundingBoxBuffers() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(boundingBoxBuffers));
}

_MTL_INLINE NS::UInteger MTL::AccelerationStructureMotionBoundingBoxGeometryDescriptor::boundingBoxCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(boundingBoxCount));
}

_MTL_INLINE NS::UInteger MTL::AccelerationStructureMotionBoundingBoxGeometryDescriptor::boundingBoxStride() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(boundingBoxStride));
}

_MTL_INLINE MTL::AccelerationStructureMotionBoundingBoxGeometryDescriptor*
            MTL::AccelerationStructureMotionBoundingBoxGeometryDescriptor::descriptor()
{
    return sendMessage<AccelerationStructureMotionBoundingBoxGeometryDescriptor*>(
        _MTL_PRIVATE_CLS(MTLAccelerationStructureMotionBoundingBoxGeometryDescriptor), _MTL_PRIVATE_SEL(descriptor));
}

_MTL_INLINE MTL::AccelerationStructureMotionBoundingBoxGeometryDescriptor*
            MTL::AccelerationStructureMotionBoundingBoxGeometryDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<AccelerationStructureMotionBoundingBoxGeometryDescriptor>();
}

_MTL_INLINE void MTL::AccelerationStructureMotionBoundingBoxGeometryDescriptor::setBoundingBoxBuffers(
    const NS::Array* boundingBoxBuffers) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBoundingBoxBuffers_), boundingBoxBuffers);
}

_MTL_INLINE void MTL::AccelerationStructureMotionBoundingBoxGeometryDescriptor::setBoundingBoxCount(
    const NS::UInteger boundingBoxCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBoundingBoxCount_), boundingBoxCount);
}

_MTL_INLINE void MTL::AccelerationStructureMotionBoundingBoxGeometryDescriptor::setBoundingBoxStride(
    const NS::UInteger boundingBoxStride) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBoundingBoxStride_), boundingBoxStride);
}

_MTL_INLINE MTL::AccelerationStructureCurveGeometryDescriptor*
            MTL::AccelerationStructureCurveGeometryDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<AccelerationStructureCurveGeometryDescriptor>(
        _MTL_PRIVATE_CLS(MTLAccelerationStructureCurveGeometryDescriptor));
}

_MTL_INLINE MTL::Buffer* MTL::AccelerationStructureCurveGeometryDescriptor::controlPointBuffer() const
{
    return sendMessage<Buffer*>(this, _MTL_PRIVATE_SEL(controlPointBuffer));
}

_MTL_INLINE NS::UInteger MTL::AccelerationStructureCurveGeometryDescriptor::controlPointBufferOffset() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(controlPointBufferOffset));
}

_MTL_INLINE NS::UInteger MTL::AccelerationStructureCurveGeometryDescriptor::controlPointCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(controlPointCount));
}

_MTL_INLINE MTL::AttributeFormat MTL::AccelerationStructureCurveGeometryDescriptor::controlPointFormat() const
{
    return sendMessage<AttributeFormat>(this, _MTL_PRIVATE_SEL(controlPointFormat));
}

_MTL_INLINE NS::UInteger MTL::AccelerationStructureCurveGeometryDescriptor::controlPointStride() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(controlPointStride));
}

_MTL_INLINE MTL::CurveBasis MTL::AccelerationStructureCurveGeometryDescriptor::curveBasis() const
{
    return sendMessage<CurveBasis>(this, _MTL_PRIVATE_SEL(curveBasis));
}

_MTL_INLINE MTL::CurveEndCaps MTL::AccelerationStructureCurveGeometryDescriptor::curveEndCaps() const
{
    return sendMessage<CurveEndCaps>(this, _MTL_PRIVATE_SEL(curveEndCaps));
}

_MTL_INLINE MTL::CurveType MTL::AccelerationStructureCurveGeometryDescriptor::curveType() const
{
    return sendMessage<CurveType>(this, _MTL_PRIVATE_SEL(curveType));
}

_MTL_INLINE MTL::AccelerationStructureCurveGeometryDescriptor*
            MTL::AccelerationStructureCurveGeometryDescriptor::descriptor()
{
    return sendMessage<AccelerationStructureCurveGeometryDescriptor*>(
        _MTL_PRIVATE_CLS(MTLAccelerationStructureCurveGeometryDescriptor), _MTL_PRIVATE_SEL(descriptor));
}

_MTL_INLINE MTL::Buffer* MTL::AccelerationStructureCurveGeometryDescriptor::indexBuffer() const
{
    return sendMessage<Buffer*>(this, _MTL_PRIVATE_SEL(indexBuffer));
}

_MTL_INLINE NS::UInteger MTL::AccelerationStructureCurveGeometryDescriptor::indexBufferOffset() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(indexBufferOffset));
}

_MTL_INLINE MTL::IndexType MTL::AccelerationStructureCurveGeometryDescriptor::indexType() const
{
    return sendMessage<IndexType>(this, _MTL_PRIVATE_SEL(indexType));
}

_MTL_INLINE MTL::AccelerationStructureCurveGeometryDescriptor* MTL::AccelerationStructureCurveGeometryDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<AccelerationStructureCurveGeometryDescriptor>();
}

_MTL_INLINE MTL::Buffer* MTL::AccelerationStructureCurveGeometryDescriptor::radiusBuffer() const
{
    return sendMessage<Buffer*>(this, _MTL_PRIVATE_SEL(radiusBuffer));
}

_MTL_INLINE NS::UInteger MTL::AccelerationStructureCurveGeometryDescriptor::radiusBufferOffset() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(radiusBufferOffset));
}

_MTL_INLINE MTL::AttributeFormat MTL::AccelerationStructureCurveGeometryDescriptor::radiusFormat() const
{
    return sendMessage<AttributeFormat>(this, _MTL_PRIVATE_SEL(radiusFormat));
}

_MTL_INLINE NS::UInteger MTL::AccelerationStructureCurveGeometryDescriptor::radiusStride() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(radiusStride));
}

_MTL_INLINE NS::UInteger MTL::AccelerationStructureCurveGeometryDescriptor::segmentControlPointCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(segmentControlPointCount));
}

_MTL_INLINE NS::UInteger MTL::AccelerationStructureCurveGeometryDescriptor::segmentCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(segmentCount));
}

_MTL_INLINE void MTL::AccelerationStructureCurveGeometryDescriptor::setControlPointBuffer(
    const Buffer* controlPointBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setControlPointBuffer_), controlPointBuffer);
}

_MTL_INLINE void MTL::AccelerationStructureCurveGeometryDescriptor::setControlPointBufferOffset(
    const NS::UInteger controlPointBufferOffset) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setControlPointBufferOffset_), controlPointBufferOffset);
}

_MTL_INLINE void MTL::AccelerationStructureCurveGeometryDescriptor::setControlPointCount(
    const NS::UInteger controlPointCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setControlPointCount_), controlPointCount);
}

_MTL_INLINE void MTL::AccelerationStructureCurveGeometryDescriptor::setControlPointFormat(
    const AttributeFormat controlPointFormat) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setControlPointFormat_), controlPointFormat);
}

_MTL_INLINE void MTL::AccelerationStructureCurveGeometryDescriptor::setControlPointStride(
    const NS::UInteger controlPointStride) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setControlPointStride_), controlPointStride);
}

_MTL_INLINE void MTL::AccelerationStructureCurveGeometryDescriptor::setCurveBasis(const CurveBasis curveBasis) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setCurveBasis_), curveBasis);
}

_MTL_INLINE void MTL::AccelerationStructureCurveGeometryDescriptor::setCurveEndCaps(
    const CurveEndCaps curveEndCaps) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setCurveEndCaps_), curveEndCaps);
}

_MTL_INLINE void MTL::AccelerationStructureCurveGeometryDescriptor::setCurveType(const CurveType curveType) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setCurveType_), curveType);
}

_MTL_INLINE void MTL::AccelerationStructureCurveGeometryDescriptor::setIndexBuffer(const Buffer* indexBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setIndexBuffer_), indexBuffer);
}

_MTL_INLINE void MTL::AccelerationStructureCurveGeometryDescriptor::setIndexBufferOffset(
    const NS::UInteger indexBufferOffset) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setIndexBufferOffset_), indexBufferOffset);
}

_MTL_INLINE void MTL::AccelerationStructureCurveGeometryDescriptor::setIndexType(const IndexType indexType) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setIndexType_), indexType);
}

_MTL_INLINE void MTL::AccelerationStructureCurveGeometryDescriptor::setRadiusBuffer(const Buffer* radiusBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRadiusBuffer_), radiusBuffer);
}

_MTL_INLINE void MTL::AccelerationStructureCurveGeometryDescriptor::setRadiusBufferOffset(
    const NS::UInteger radiusBufferOffset) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRadiusBufferOffset_), radiusBufferOffset);
}

_MTL_INLINE void MTL::AccelerationStructureCurveGeometryDescriptor::setRadiusFormat(
    const AttributeFormat radiusFormat) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRadiusFormat_), radiusFormat);
}

_MTL_INLINE void MTL::AccelerationStructureCurveGeometryDescriptor::setRadiusStride(
    const NS::UInteger radiusStride) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRadiusStride_), radiusStride);
}

_MTL_INLINE void MTL::AccelerationStructureCurveGeometryDescriptor::setSegmentControlPointCount(
    const NS::UInteger segmentControlPointCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSegmentControlPointCount_), segmentControlPointCount);
}

_MTL_INLINE void MTL::AccelerationStructureCurveGeometryDescriptor::setSegmentCount(
    const NS::UInteger segmentCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSegmentCount_), segmentCount);
}

_MTL_INLINE MTL::AccelerationStructureMotionCurveGeometryDescriptor*
            MTL::AccelerationStructureMotionCurveGeometryDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<AccelerationStructureMotionCurveGeometryDescriptor>(
        _MTL_PRIVATE_CLS(MTLAccelerationStructureMotionCurveGeometryDescriptor));
}

_MTL_INLINE NS::Array* MTL::AccelerationStructureMotionCurveGeometryDescriptor::controlPointBuffers() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(controlPointBuffers));
}

_MTL_INLINE NS::UInteger MTL::AccelerationStructureMotionCurveGeometryDescriptor::controlPointCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(controlPointCount));
}

_MTL_INLINE MTL::AttributeFormat MTL::AccelerationStructureMotionCurveGeometryDescriptor::controlPointFormat() const
{
    return sendMessage<AttributeFormat>(this, _MTL_PRIVATE_SEL(controlPointFormat));
}

_MTL_INLINE NS::UInteger MTL::AccelerationStructureMotionCurveGeometryDescriptor::controlPointStride() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(controlPointStride));
}

_MTL_INLINE MTL::CurveBasis MTL::AccelerationStructureMotionCurveGeometryDescriptor::curveBasis() const
{
    return sendMessage<CurveBasis>(this, _MTL_PRIVATE_SEL(curveBasis));
}

_MTL_INLINE MTL::CurveEndCaps MTL::AccelerationStructureMotionCurveGeometryDescriptor::curveEndCaps() const
{
    return sendMessage<CurveEndCaps>(this, _MTL_PRIVATE_SEL(curveEndCaps));
}

_MTL_INLINE MTL::CurveType MTL::AccelerationStructureMotionCurveGeometryDescriptor::curveType() const
{
    return sendMessage<CurveType>(this, _MTL_PRIVATE_SEL(curveType));
}

_MTL_INLINE MTL::AccelerationStructureMotionCurveGeometryDescriptor*
            MTL::AccelerationStructureMotionCurveGeometryDescriptor::descriptor()
{
    return sendMessage<AccelerationStructureMotionCurveGeometryDescriptor*>(
        _MTL_PRIVATE_CLS(MTLAccelerationStructureMotionCurveGeometryDescriptor), _MTL_PRIVATE_SEL(descriptor));
}

_MTL_INLINE MTL::Buffer* MTL::AccelerationStructureMotionCurveGeometryDescriptor::indexBuffer() const
{
    return sendMessage<Buffer*>(this, _MTL_PRIVATE_SEL(indexBuffer));
}

_MTL_INLINE NS::UInteger MTL::AccelerationStructureMotionCurveGeometryDescriptor::indexBufferOffset() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(indexBufferOffset));
}

_MTL_INLINE MTL::IndexType MTL::AccelerationStructureMotionCurveGeometryDescriptor::indexType() const
{
    return sendMessage<IndexType>(this, _MTL_PRIVATE_SEL(indexType));
}

_MTL_INLINE MTL::AccelerationStructureMotionCurveGeometryDescriptor*
            MTL::AccelerationStructureMotionCurveGeometryDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<AccelerationStructureMotionCurveGeometryDescriptor>();
}

_MTL_INLINE NS::Array* MTL::AccelerationStructureMotionCurveGeometryDescriptor::radiusBuffers() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(radiusBuffers));
}

_MTL_INLINE MTL::AttributeFormat MTL::AccelerationStructureMotionCurveGeometryDescriptor::radiusFormat() const
{
    return sendMessage<AttributeFormat>(this, _MTL_PRIVATE_SEL(radiusFormat));
}

_MTL_INLINE NS::UInteger MTL::AccelerationStructureMotionCurveGeometryDescriptor::radiusStride() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(radiusStride));
}

_MTL_INLINE NS::UInteger MTL::AccelerationStructureMotionCurveGeometryDescriptor::segmentControlPointCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(segmentControlPointCount));
}

_MTL_INLINE NS::UInteger MTL::AccelerationStructureMotionCurveGeometryDescriptor::segmentCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(segmentCount));
}

_MTL_INLINE void MTL::AccelerationStructureMotionCurveGeometryDescriptor::setControlPointBuffers(
    const NS::Array* controlPointBuffers) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setControlPointBuffers_), controlPointBuffers);
}

_MTL_INLINE void MTL::AccelerationStructureMotionCurveGeometryDescriptor::setControlPointCount(
    const NS::UInteger controlPointCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setControlPointCount_), controlPointCount);
}

_MTL_INLINE void MTL::AccelerationStructureMotionCurveGeometryDescriptor::setControlPointFormat(
    const AttributeFormat controlPointFormat) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setControlPointFormat_), controlPointFormat);
}

_MTL_INLINE void MTL::AccelerationStructureMotionCurveGeometryDescriptor::setControlPointStride(
    const NS::UInteger controlPointStride) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setControlPointStride_), controlPointStride);
}

_MTL_INLINE void MTL::AccelerationStructureMotionCurveGeometryDescriptor::setCurveBasis(
    const CurveBasis curveBasis) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setCurveBasis_), curveBasis);
}

_MTL_INLINE void MTL::AccelerationStructureMotionCurveGeometryDescriptor::setCurveEndCaps(
    const CurveEndCaps curveEndCaps) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setCurveEndCaps_), curveEndCaps);
}

_MTL_INLINE void MTL::AccelerationStructureMotionCurveGeometryDescriptor::setCurveType(const CurveType curveType) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setCurveType_), curveType);
}

_MTL_INLINE void MTL::AccelerationStructureMotionCurveGeometryDescriptor::setIndexBuffer(
    const Buffer* indexBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setIndexBuffer_), indexBuffer);
}

_MTL_INLINE void MTL::AccelerationStructureMotionCurveGeometryDescriptor::setIndexBufferOffset(
    const NS::UInteger indexBufferOffset) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setIndexBufferOffset_), indexBufferOffset);
}

_MTL_INLINE void MTL::AccelerationStructureMotionCurveGeometryDescriptor::setIndexType(const IndexType indexType) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setIndexType_), indexType);
}

_MTL_INLINE void MTL::AccelerationStructureMotionCurveGeometryDescriptor::setRadiusBuffers(
    const NS::Array* radiusBuffers) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRadiusBuffers_), radiusBuffers);
}

_MTL_INLINE void MTL::AccelerationStructureMotionCurveGeometryDescriptor::setRadiusFormat(
    const AttributeFormat radiusFormat) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRadiusFormat_), radiusFormat);
}

_MTL_INLINE void MTL::AccelerationStructureMotionCurveGeometryDescriptor::setRadiusStride(
    const NS::UInteger radiusStride) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRadiusStride_), radiusStride);
}

_MTL_INLINE void MTL::AccelerationStructureMotionCurveGeometryDescriptor::setSegmentControlPointCount(
    const NS::UInteger segmentControlPointCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSegmentControlPointCount_), segmentControlPointCount);
}

_MTL_INLINE void MTL::AccelerationStructureMotionCurveGeometryDescriptor::setSegmentCount(
    const NS::UInteger segmentCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSegmentCount_), segmentCount);
}

_MTL_INLINE MTL::InstanceAccelerationStructureDescriptor* MTL::InstanceAccelerationStructureDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<InstanceAccelerationStructureDescriptor>(
        _MTL_PRIVATE_CLS(MTLInstanceAccelerationStructureDescriptor));
}

_MTL_INLINE MTL::InstanceAccelerationStructureDescriptor* MTL::InstanceAccelerationStructureDescriptor::descriptor()
{
    return sendMessage<InstanceAccelerationStructureDescriptor*>(
        _MTL_PRIVATE_CLS(MTLInstanceAccelerationStructureDescriptor), _MTL_PRIVATE_SEL(descriptor));
}

_MTL_INLINE MTL::InstanceAccelerationStructureDescriptor* MTL::InstanceAccelerationStructureDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<InstanceAccelerationStructureDescriptor>();
}

_MTL_INLINE NS::UInteger MTL::InstanceAccelerationStructureDescriptor::instanceCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(instanceCount));
}

_MTL_INLINE MTL::Buffer* MTL::InstanceAccelerationStructureDescriptor::instanceDescriptorBuffer() const
{
    return sendMessage<Buffer*>(this, _MTL_PRIVATE_SEL(instanceDescriptorBuffer));
}

_MTL_INLINE NS::UInteger MTL::InstanceAccelerationStructureDescriptor::instanceDescriptorBufferOffset() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(instanceDescriptorBufferOffset));
}

_MTL_INLINE NS::UInteger MTL::InstanceAccelerationStructureDescriptor::instanceDescriptorStride() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(instanceDescriptorStride));
}

_MTL_INLINE MTL::AccelerationStructureInstanceDescriptorType
            MTL::InstanceAccelerationStructureDescriptor::instanceDescriptorType() const
{
    return sendMessage<AccelerationStructureInstanceDescriptorType>(this, _MTL_PRIVATE_SEL(instanceDescriptorType));
}

_MTL_INLINE MTL::MatrixLayout MTL::InstanceAccelerationStructureDescriptor::instanceTransformationMatrixLayout() const
{
    return sendMessage<MatrixLayout>(this, _MTL_PRIVATE_SEL(instanceTransformationMatrixLayout));
}

_MTL_INLINE NS::Array* MTL::InstanceAccelerationStructureDescriptor::instancedAccelerationStructures() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(instancedAccelerationStructures));
}

_MTL_INLINE MTL::Buffer* MTL::InstanceAccelerationStructureDescriptor::motionTransformBuffer() const
{
    return sendMessage<Buffer*>(this, _MTL_PRIVATE_SEL(motionTransformBuffer));
}

_MTL_INLINE NS::UInteger MTL::InstanceAccelerationStructureDescriptor::motionTransformBufferOffset() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(motionTransformBufferOffset));
}

_MTL_INLINE NS::UInteger MTL::InstanceAccelerationStructureDescriptor::motionTransformCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(motionTransformCount));
}

_MTL_INLINE NS::UInteger MTL::InstanceAccelerationStructureDescriptor::motionTransformStride() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(motionTransformStride));
}

_MTL_INLINE MTL::TransformType MTL::InstanceAccelerationStructureDescriptor::motionTransformType() const
{
    return sendMessage<TransformType>(this, _MTL_PRIVATE_SEL(motionTransformType));
}

_MTL_INLINE void MTL::InstanceAccelerationStructureDescriptor::setInstanceCount(const NS::UInteger instanceCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setInstanceCount_), instanceCount);
}

_MTL_INLINE void MTL::InstanceAccelerationStructureDescriptor::setInstanceDescriptorBuffer(
    const Buffer* instanceDescriptorBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setInstanceDescriptorBuffer_), instanceDescriptorBuffer);
}

_MTL_INLINE void MTL::InstanceAccelerationStructureDescriptor::setInstanceDescriptorBufferOffset(
    const NS::UInteger instanceDescriptorBufferOffset) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setInstanceDescriptorBufferOffset_), instanceDescriptorBufferOffset);
}

_MTL_INLINE void MTL::InstanceAccelerationStructureDescriptor::setInstanceDescriptorStride(
    const NS::UInteger instanceDescriptorStride) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setInstanceDescriptorStride_), instanceDescriptorStride);
}

_MTL_INLINE void MTL::InstanceAccelerationStructureDescriptor::setInstanceDescriptorType(
    const AccelerationStructureInstanceDescriptorType instanceDescriptorType) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setInstanceDescriptorType_), instanceDescriptorType);
}

_MTL_INLINE void MTL::InstanceAccelerationStructureDescriptor::setInstanceTransformationMatrixLayout(
    const MatrixLayout instanceTransformationMatrixLayout) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setInstanceTransformationMatrixLayout_), instanceTransformationMatrixLayout);
}

_MTL_INLINE void MTL::InstanceAccelerationStructureDescriptor::setInstancedAccelerationStructures(
    const NS::Array* instancedAccelerationStructures) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setInstancedAccelerationStructures_), instancedAccelerationStructures);
}

_MTL_INLINE void MTL::InstanceAccelerationStructureDescriptor::setMotionTransformBuffer(
    const Buffer* motionTransformBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMotionTransformBuffer_), motionTransformBuffer);
}

_MTL_INLINE void MTL::InstanceAccelerationStructureDescriptor::setMotionTransformBufferOffset(
    const NS::UInteger motionTransformBufferOffset) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMotionTransformBufferOffset_), motionTransformBufferOffset);
}

_MTL_INLINE void MTL::InstanceAccelerationStructureDescriptor::setMotionTransformCount(
    const NS::UInteger motionTransformCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMotionTransformCount_), motionTransformCount);
}

_MTL_INLINE void MTL::InstanceAccelerationStructureDescriptor::setMotionTransformStride(
    const NS::UInteger motionTransformStride) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMotionTransformStride_), motionTransformStride);
}

_MTL_INLINE void MTL::InstanceAccelerationStructureDescriptor::setMotionTransformType(
    const TransformType motionTransformType) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMotionTransformType_), motionTransformType);
}

_MTL_INLINE MTL::IndirectInstanceAccelerationStructureDescriptor*
            MTL::IndirectInstanceAccelerationStructureDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<IndirectInstanceAccelerationStructureDescriptor>(
        _MTL_PRIVATE_CLS(MTLIndirectInstanceAccelerationStructureDescriptor));
}

_MTL_INLINE MTL::IndirectInstanceAccelerationStructureDescriptor*
            MTL::IndirectInstanceAccelerationStructureDescriptor::descriptor()
{
    return sendMessage<IndirectInstanceAccelerationStructureDescriptor*>(
        _MTL_PRIVATE_CLS(MTLIndirectInstanceAccelerationStructureDescriptor), _MTL_PRIVATE_SEL(descriptor));
}

_MTL_INLINE MTL::IndirectInstanceAccelerationStructureDescriptor*
            MTL::IndirectInstanceAccelerationStructureDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<IndirectInstanceAccelerationStructureDescriptor>();
}

_MTL_INLINE MTL::Buffer* MTL::IndirectInstanceAccelerationStructureDescriptor::instanceCountBuffer() const
{
    return sendMessage<Buffer*>(this, _MTL_PRIVATE_SEL(instanceCountBuffer));
}

_MTL_INLINE NS::UInteger MTL::IndirectInstanceAccelerationStructureDescriptor::instanceCountBufferOffset() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(instanceCountBufferOffset));
}

_MTL_INLINE MTL::Buffer* MTL::IndirectInstanceAccelerationStructureDescriptor::instanceDescriptorBuffer() const
{
    return sendMessage<Buffer*>(this, _MTL_PRIVATE_SEL(instanceDescriptorBuffer));
}

_MTL_INLINE NS::UInteger MTL::IndirectInstanceAccelerationStructureDescriptor::instanceDescriptorBufferOffset() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(instanceDescriptorBufferOffset));
}

_MTL_INLINE NS::UInteger MTL::IndirectInstanceAccelerationStructureDescriptor::instanceDescriptorStride() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(instanceDescriptorStride));
}

_MTL_INLINE MTL::AccelerationStructureInstanceDescriptorType
            MTL::IndirectInstanceAccelerationStructureDescriptor::instanceDescriptorType() const
{
    return sendMessage<AccelerationStructureInstanceDescriptorType>(this, _MTL_PRIVATE_SEL(instanceDescriptorType));
}

_MTL_INLINE MTL::MatrixLayout MTL::IndirectInstanceAccelerationStructureDescriptor::instanceTransformationMatrixLayout()
    const
{
    return sendMessage<MatrixLayout>(this, _MTL_PRIVATE_SEL(instanceTransformationMatrixLayout));
}

_MTL_INLINE NS::UInteger MTL::IndirectInstanceAccelerationStructureDescriptor::maxInstanceCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxInstanceCount));
}

_MTL_INLINE NS::UInteger MTL::IndirectInstanceAccelerationStructureDescriptor::maxMotionTransformCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxMotionTransformCount));
}

_MTL_INLINE MTL::Buffer* MTL::IndirectInstanceAccelerationStructureDescriptor::motionTransformBuffer() const
{
    return sendMessage<Buffer*>(this, _MTL_PRIVATE_SEL(motionTransformBuffer));
}

_MTL_INLINE NS::UInteger MTL::IndirectInstanceAccelerationStructureDescriptor::motionTransformBufferOffset() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(motionTransformBufferOffset));
}

_MTL_INLINE MTL::Buffer* MTL::IndirectInstanceAccelerationStructureDescriptor::motionTransformCountBuffer() const
{
    return sendMessage<Buffer*>(this, _MTL_PRIVATE_SEL(motionTransformCountBuffer));
}

_MTL_INLINE NS::UInteger MTL::IndirectInstanceAccelerationStructureDescriptor::motionTransformCountBufferOffset() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(motionTransformCountBufferOffset));
}

_MTL_INLINE NS::UInteger MTL::IndirectInstanceAccelerationStructureDescriptor::motionTransformStride() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(motionTransformStride));
}

_MTL_INLINE MTL::TransformType MTL::IndirectInstanceAccelerationStructureDescriptor::motionTransformType() const
{
    return sendMessage<TransformType>(this, _MTL_PRIVATE_SEL(motionTransformType));
}

_MTL_INLINE void MTL::IndirectInstanceAccelerationStructureDescriptor::setInstanceCountBuffer(
    const Buffer* instanceCountBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setInstanceCountBuffer_), instanceCountBuffer);
}

_MTL_INLINE void MTL::IndirectInstanceAccelerationStructureDescriptor::setInstanceCountBufferOffset(
    const NS::UInteger instanceCountBufferOffset) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setInstanceCountBufferOffset_), instanceCountBufferOffset);
}

_MTL_INLINE void MTL::IndirectInstanceAccelerationStructureDescriptor::setInstanceDescriptorBuffer(
    const Buffer* instanceDescriptorBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setInstanceDescriptorBuffer_), instanceDescriptorBuffer);
}

_MTL_INLINE void MTL::IndirectInstanceAccelerationStructureDescriptor::setInstanceDescriptorBufferOffset(
    const NS::UInteger instanceDescriptorBufferOffset) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setInstanceDescriptorBufferOffset_), instanceDescriptorBufferOffset);
}

_MTL_INLINE void MTL::IndirectInstanceAccelerationStructureDescriptor::setInstanceDescriptorStride(
    const NS::UInteger instanceDescriptorStride) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setInstanceDescriptorStride_), instanceDescriptorStride);
}

_MTL_INLINE void MTL::IndirectInstanceAccelerationStructureDescriptor::setInstanceDescriptorType(
    const AccelerationStructureInstanceDescriptorType instanceDescriptorType) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setInstanceDescriptorType_), instanceDescriptorType);
}

_MTL_INLINE void MTL::IndirectInstanceAccelerationStructureDescriptor::setInstanceTransformationMatrixLayout(
    const MatrixLayout instanceTransformationMatrixLayout) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setInstanceTransformationMatrixLayout_), instanceTransformationMatrixLayout);
}

_MTL_INLINE void MTL::IndirectInstanceAccelerationStructureDescriptor::setMaxInstanceCount(
    const NS::UInteger maxInstanceCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxInstanceCount_), maxInstanceCount);
}

_MTL_INLINE void MTL::IndirectInstanceAccelerationStructureDescriptor::setMaxMotionTransformCount(
    const NS::UInteger maxMotionTransformCount) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxMotionTransformCount_), maxMotionTransformCount);
}

_MTL_INLINE void MTL::IndirectInstanceAccelerationStructureDescriptor::setMotionTransformBuffer(
    const Buffer* motionTransformBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMotionTransformBuffer_), motionTransformBuffer);
}

_MTL_INLINE void MTL::IndirectInstanceAccelerationStructureDescriptor::setMotionTransformBufferOffset(
    const NS::UInteger motionTransformBufferOffset) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMotionTransformBufferOffset_), motionTransformBufferOffset);
}

_MTL_INLINE void MTL::IndirectInstanceAccelerationStructureDescriptor::setMotionTransformCountBuffer(
    const Buffer* motionTransformCountBuffer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMotionTransformCountBuffer_), motionTransformCountBuffer);
}

_MTL_INLINE void MTL::IndirectInstanceAccelerationStructureDescriptor::setMotionTransformCountBufferOffset(
    const NS::UInteger motionTransformCountBufferOffset) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMotionTransformCountBufferOffset_), motionTransformCountBufferOffset);
}

_MTL_INLINE void MTL::IndirectInstanceAccelerationStructureDescriptor::setMotionTransformStride(
    const NS::UInteger motionTransformStride) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMotionTransformStride_), motionTransformStride);
}

_MTL_INLINE void MTL::IndirectInstanceAccelerationStructureDescriptor::setMotionTransformType(
    const TransformType motionTransformType) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMotionTransformType_), motionTransformType);
}

_MTL_INLINE MTL::ResourceID MTL::AccelerationStructure::gpuResourceID() const
{
    return sendMessage<ResourceID>(this, _MTL_PRIVATE_SEL(gpuResourceID));
}

_MTL_INLINE NS::UInteger MTL::AccelerationStructure::size() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(size));
}
