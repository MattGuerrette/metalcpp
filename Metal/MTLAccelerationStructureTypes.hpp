//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLAccelerationStructureTypes.hpp
//
// Copyright 2020-2024 Apple Inc.
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

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#include "MTLDefines.hpp"

#include <cstdint>

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

namespace MTL
{

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnested-anon-types"
    /// @see https://developer.apple.com/documentation/metal/mtlpackedfloat3-c.struct?language=objc
    struct PackedFloat3
    {
        PackedFloat3();
        PackedFloat3(float _x, float _y, float _z);

        float& operator[](int idx);
        float  operator[](int idx) const;

        union
        {
            struct
            {
                float x;
                float y;
                float z;
            };

            float elements[3]{};
        };
    } _MTL_PACKED;
#pragma clang diagnostic pop

    /// @see https://developer.apple.com/documentation/metal/mtlpackedfloat4x3-c.struct?language=objc
    struct PackedFloat4x3
    {
        PackedFloat4x3();
        PackedFloat4x3(const PackedFloat3& col0,
                       const PackedFloat3& col1,
                       const PackedFloat3& col2,
                       const PackedFloat3& col3);

        PackedFloat3&       operator[](int idx);
        const PackedFloat3& operator[](int idx) const;

        PackedFloat3 columns[4];
    } _MTL_PACKED;

    /// @see https://developer.apple.com/documentation/metal/mtlaxisalignedboundingbox-c.struct?language=objc
    struct AxisAlignedBoundingBox
    {
        AxisAlignedBoundingBox();
        explicit AxisAlignedBoundingBox(PackedFloat3 p);
        AxisAlignedBoundingBox(PackedFloat3 _min, PackedFloat3 _max);

        PackedFloat3 min;
        PackedFloat3 max;
    } _MTL_PACKED;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnested-anon-types"
    /// @see https://developer.apple.com/documentation/metal/mtlpackedfloatquaternion?language=objc
    struct PackedFloatQuaternion
    {
        PackedFloatQuaternion();
        PackedFloatQuaternion(float x, float y, float z, float w);

        float&       operator[](int idx);
        const float& operator[](int idx) const;

        union
        {
            struct
            {
                float x;
                float y;
                float z;
                float w;
            };

            float elements[4]{};
        };

    } _MTL_PACKED;
#pragma clang diagnostic pop

    /// @see https://developer.apple.com/documentation/metal/mtlcomponenttransform?language=objc
    struct ComponentTransform
    {
        PackedFloat3          scale;
        PackedFloat3          shear;
        PackedFloat3          pivot;
        PackedFloatQuaternion rotation;
        PackedFloat3          translation;
    } _MTL_PACKED;

} // namespace MTL

namespace MTL4
{
    /// @see https://developer.apple.com/documentation/metal/mtl4bufferrange?language=objc
    struct BufferRange
    {
        BufferRange() = default;
        explicit BufferRange(uint64_t bufferAddress);
        BufferRange(uint64_t bufferAddress, uint64_t length);

        static BufferRange Make(uint64_t bufferAddress, uint64_t length);

        uint64_t bufferAddress;
        uint64_t length;
    } _MTL_PACKED;

} // namespace MTL4

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_MTL_INLINE MTL::PackedFloat3::PackedFloat3() : x(0.0f), y(0.0f), z(0.0f) {}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_MTL_INLINE MTL::PackedFloat3::PackedFloat3(const float _x, const float _y, const float _z) : x(_x), y(_y), z(_z) {}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_MTL_INLINE float& MTL::PackedFloat3::operator[](const int idx) { return elements[idx]; }

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_MTL_INLINE float MTL::PackedFloat3::operator[](const int idx) const { return elements[idx]; }

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_MTL_INLINE MTL::PackedFloat4x3::PackedFloat4x3()
{
    columns[0] = PackedFloat3(0.0f, 0.0f, 0.0f);
    columns[1] = PackedFloat3(0.0f, 0.0f, 0.0f);
    columns[2] = PackedFloat3(0.0f, 0.0f, 0.0f);
    columns[3] = PackedFloat3(0.0f, 0.0f, 0.0f);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_MTL_INLINE MTL::PackedFloat4x3::PackedFloat4x3(const PackedFloat3& col0,
                                                const PackedFloat3& col1,
                                                const PackedFloat3& col2,
                                                const PackedFloat3& col3)
{
    columns[0] = col0;
    columns[1] = col1;
    columns[2] = col2;
    columns[3] = col3;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_MTL_INLINE MTL::PackedFloat3& MTL::PackedFloat4x3::operator[](const int idx) { return columns[idx]; }

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_MTL_INLINE const MTL::PackedFloat3& MTL::PackedFloat4x3::operator[](const int idx) const { return columns[idx]; }

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#if __apple_build_version__ > 16000026
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wnan-infinity-disabled"
#endif // __apple_build_version__ > 16000026
_MTL_INLINE MTL::AxisAlignedBoundingBox::AxisAlignedBoundingBox()
    : min(INFINITY, INFINITY, INFINITY), max(-INFINITY, -INFINITY, -INFINITY)
{
}
#if __apple_build_version__ > 16000026
#pragma clang diagnostic pop
#endif // if __apple_build_version__ > 16000026

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_MTL_INLINE MTL::AxisAlignedBoundingBox::AxisAlignedBoundingBox(const PackedFloat3 p) : min(p), max(p) {}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_MTL_INLINE MTL::AxisAlignedBoundingBox::AxisAlignedBoundingBox(const PackedFloat3 _min, const PackedFloat3 _max)
    : min(_min), max(_max)
{
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_MTL_INLINE MTL::PackedFloatQuaternion::PackedFloatQuaternion() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_MTL_INLINE MTL::PackedFloatQuaternion::PackedFloatQuaternion(const float x,
                                                              const float y,
                                                              const float z,
                                                              const float w)
    : x(x), y(y), z(z), w(w)
{
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_MTL_INLINE float& MTL::PackedFloatQuaternion::operator[](const int idx) { return elements[idx]; }

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_MTL_INLINE const float& MTL::PackedFloatQuaternion::operator[](const int idx) const { return elements[idx]; }

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_MTL_INLINE MTL4::BufferRange::BufferRange(const uint64_t bufferAddress) : bufferAddress(bufferAddress), length(-1) {}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_MTL_INLINE MTL4::BufferRange::BufferRange(const uint64_t bufferAddress, const uint64_t length)
    : bufferAddress(bufferAddress), length(length)
{
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_MTL_INLINE MTL4::BufferRange MTL4::BufferRange::Make(const uint64_t bufferAddress, const uint64_t length)
{
    return { bufferAddress, length };
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------
