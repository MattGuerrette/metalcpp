//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLTensor.hpp
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
#include "MTLResource.hpp"
#include "MTLTypes.hpp"

namespace MTL
{
    class Buffer;
    class TensorDescriptor;
    class TensorExtents;

    _MTL_CONST(NS::ErrorDomain, TensorDomain);

    /// @see https://developer.apple.com/documentation/metal/mtltensordatatype?language=objc
    _MTL_ENUM(NS::Integer, TensorDataType){
        TensorDataTypeNone = 0,   TensorDataTypeFloat32 = 3, TensorDataTypeFloat16 = 16, TensorDataTypeBFloat16 = 121,
        TensorDataTypeInt8 = 45,  TensorDataTypeUInt8 = 49,  TensorDataTypeInt16 = 37,   TensorDataTypeUInt16 = 41,
        TensorDataTypeInt32 = 29, TensorDataTypeUInt32 = 33,
    };

    /// @see https://developer.apple.com/documentation/metal/mtltensorerror-swift.struct/code?language=objc
    _MTL_ENUM(NS::Integer, TensorError){
        TensorErrorNone              = 0,
        TensorErrorInternalError     = 1,
        TensorErrorInvalidDescriptor = 2,
    };

    /// @see https://developer.apple.com/documentation/metal/mtltensorusage?language=objc
    _MTL_OPTIONS(NS::UInteger, TensorUsage){
        TensorUsageCompute         = 1,
        TensorUsageRender          = 1 << 1,
        TensorUsageMachineLearning = 1 << 2,
    };

    /// @see https://developer.apple.com/documentation/metal/mtltensorextents?language=objc
    class TensorExtents : public NS::Referencing<TensorExtents>
    {
    public:
        [[nodiscard]] static TensorExtents* alloc();

        [[nodiscard]] NS::Integer extentAtDimensionIndex(NS::UInteger dimensionIndex) const;

        [[nodiscard]] TensorExtents* init();
        [[nodiscard]] TensorExtents* init(NS::UInteger rank, const NS::Integer* values) const;

        [[nodiscard]] NS::UInteger rank() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtltensordescriptor?language=objc
    class TensorDescriptor : public NS::Copying<TensorDescriptor>
    {
    public:
        [[nodiscard]] static TensorDescriptor* alloc();

        [[nodiscard]] CPUCacheMode cpuCacheMode() const;

        [[nodiscard]] TensorDataType dataType() const;

        [[nodiscard]] TensorExtents* dimensions() const;

        [[nodiscard]] HazardTrackingMode hazardTrackingMode() const;

        [[nodiscard]] TensorDescriptor* init();

        [[nodiscard]] ResourceOptions resourceOptions() const;

        void setCpuCacheMode(CPUCacheMode cpuCacheMode) const;

        void setDataType(TensorDataType dataType) const;

        void setDimensions(const TensorExtents* dimensions) const;

        void setHazardTrackingMode(HazardTrackingMode hazardTrackingMode) const;

        void setResourceOptions(ResourceOptions resourceOptions) const;

        void setStorageMode(StorageMode storageMode) const;

        void setStrides(const TensorExtents* strides) const;

        void setUsage(TensorUsage usage) const;

        [[nodiscard]] StorageMode storageMode() const;

        [[nodiscard]] TensorExtents* strides() const;

        [[nodiscard]] TensorUsage usage() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtltensor?language=objc
    class Tensor : public NS::Referencing<Tensor, Resource>
    {
    public:
        [[nodiscard]] Buffer*      buffer() const;
        [[nodiscard]] NS::UInteger bufferOffset() const;

        [[nodiscard]] TensorDataType dataType() const;

        [[nodiscard]] TensorExtents* dimensions() const;

        void getBytes(void*                bytes,
                      const TensorExtents* strides,
                      const TensorExtents* sliceOrigin,
                      const TensorExtents* sliceDimensions) const;

        [[nodiscard]] ResourceID gpuResourceID() const;

        void replaceSliceOrigin(const TensorExtents* sliceOrigin,
                                const TensorExtents* sliceDimensions,
                                const void*          bytes,
                                const TensorExtents* strides) const;

        [[nodiscard]] TensorExtents* strides() const;

        [[nodiscard]] TensorUsage usage() const;
    };

} // namespace MTL

_MTL_PRIVATE_DEF_CONST(NS::ErrorDomain, TensorDomain);

_MTL_INLINE MTL::TensorExtents* MTL::TensorExtents::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<TensorExtents>(_MTL_PRIVATE_CLS(MTLTensorExtents));
}

_MTL_INLINE NS::Integer MTL::TensorExtents::extentAtDimensionIndex(const NS::UInteger dimensionIndex) const
{
    return sendMessage<NS::Integer>(this, _MTL_PRIVATE_SEL(extentAtDimensionIndex_), dimensionIndex);
}

_MTL_INLINE MTL::TensorExtents* MTL::TensorExtents::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<TensorExtents>();
}

_MTL_INLINE MTL::TensorExtents* MTL::TensorExtents::init(const NS::UInteger rank, const NS::Integer* values) const
{
    return sendMessage<TensorExtents*>(this, _MTL_PRIVATE_SEL(initWithRank_values_), rank, values);
}

_MTL_INLINE NS::UInteger MTL::TensorExtents::rank() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(rank));
}

_MTL_INLINE MTL::TensorDescriptor* MTL::TensorDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<TensorDescriptor>(_MTL_PRIVATE_CLS(MTLTensorDescriptor));
}

_MTL_INLINE MTL::CPUCacheMode MTL::TensorDescriptor::cpuCacheMode() const
{
    return sendMessage<CPUCacheMode>(this, _MTL_PRIVATE_SEL(cpuCacheMode));
}

_MTL_INLINE MTL::TensorDataType MTL::TensorDescriptor::dataType() const
{
    return sendMessage<TensorDataType>(this, _MTL_PRIVATE_SEL(dataType));
}

_MTL_INLINE MTL::TensorExtents* MTL::TensorDescriptor::dimensions() const
{
    return sendMessage<TensorExtents*>(this, _MTL_PRIVATE_SEL(dimensions));
}

_MTL_INLINE MTL::HazardTrackingMode MTL::TensorDescriptor::hazardTrackingMode() const
{
    return sendMessage<HazardTrackingMode>(this, _MTL_PRIVATE_SEL(hazardTrackingMode));
}

_MTL_INLINE MTL::TensorDescriptor* MTL::TensorDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<TensorDescriptor>();
}

_MTL_INLINE MTL::ResourceOptions MTL::TensorDescriptor::resourceOptions() const
{
    return sendMessage<ResourceOptions>(this, _MTL_PRIVATE_SEL(resourceOptions));
}

_MTL_INLINE void MTL::TensorDescriptor::setCpuCacheMode(const CPUCacheMode cpuCacheMode) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setCpuCacheMode_), cpuCacheMode);
}

_MTL_INLINE void MTL::TensorDescriptor::setDataType(const TensorDataType dataType) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDataType_), dataType);
}

_MTL_INLINE void MTL::TensorDescriptor::setDimensions(const TensorExtents* dimensions) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDimensions_), dimensions);
}

_MTL_INLINE void MTL::TensorDescriptor::setHazardTrackingMode(const HazardTrackingMode hazardTrackingMode) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setHazardTrackingMode_), hazardTrackingMode);
}

_MTL_INLINE void MTL::TensorDescriptor::setResourceOptions(const ResourceOptions resourceOptions) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setResourceOptions_), resourceOptions);
}

_MTL_INLINE void MTL::TensorDescriptor::setStorageMode(const StorageMode storageMode) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setStorageMode_), storageMode);
}

_MTL_INLINE void MTL::TensorDescriptor::setStrides(const TensorExtents* strides) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setStrides_), strides);
}

_MTL_INLINE void MTL::TensorDescriptor::setUsage(const TensorUsage usage) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setUsage_), usage);
}

_MTL_INLINE MTL::StorageMode MTL::TensorDescriptor::storageMode() const
{
    return sendMessage<StorageMode>(this, _MTL_PRIVATE_SEL(storageMode));
}

_MTL_INLINE MTL::TensorExtents* MTL::TensorDescriptor::strides() const
{
    return sendMessage<TensorExtents*>(this, _MTL_PRIVATE_SEL(strides));
}

_MTL_INLINE MTL::TensorUsage MTL::TensorDescriptor::usage() const
{
    return sendMessage<TensorUsage>(this, _MTL_PRIVATE_SEL(usage));
}

_MTL_INLINE MTL::Buffer* MTL::Tensor::buffer() const { return sendMessage<Buffer*>(this, _MTL_PRIVATE_SEL(buffer)); }

_MTL_INLINE NS::UInteger MTL::Tensor::bufferOffset() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(bufferOffset));
}

_MTL_INLINE MTL::TensorDataType MTL::Tensor::dataType() const
{
    return sendMessage<TensorDataType>(this, _MTL_PRIVATE_SEL(dataType));
}

_MTL_INLINE MTL::TensorExtents* MTL::Tensor::dimensions() const
{
    return sendMessage<TensorExtents*>(this, _MTL_PRIVATE_SEL(dimensions));
}

_MTL_INLINE void MTL::Tensor::getBytes(void*                bytes,
                                       const TensorExtents* strides,
                                       const TensorExtents* sliceOrigin,
                                       const TensorExtents* sliceDimensions) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(getBytes_strides_fromSliceOrigin_sliceDimensions_),
                      bytes,
                      strides,
                      sliceOrigin,
                      sliceDimensions);
}

_MTL_INLINE MTL::ResourceID MTL::Tensor::gpuResourceID() const
{
    return sendMessage<ResourceID>(this, _MTL_PRIVATE_SEL(gpuResourceID));
}

_MTL_INLINE void MTL::Tensor::replaceSliceOrigin(const TensorExtents* sliceOrigin,
                                                 const TensorExtents* sliceDimensions,
                                                 const void*          bytes,
                                                 const TensorExtents* strides) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(replaceSliceOrigin_sliceDimensions_withBytes_strides_),
                      sliceOrigin,
                      sliceDimensions,
                      bytes,
                      strides);
}

_MTL_INLINE MTL::TensorExtents* MTL::Tensor::strides() const
{
    return sendMessage<TensorExtents*>(this, _MTL_PRIVATE_SEL(strides));
}

_MTL_INLINE MTL::TensorUsage MTL::Tensor::usage() const
{
    return sendMessage<TensorUsage>(this, _MTL_PRIVATE_SEL(usage));
}
