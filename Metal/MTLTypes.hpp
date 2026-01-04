//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLTypes.hpp
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

namespace MTL
{
    struct SamplePosition;

    using Coordinate2D = SamplePosition;

    /// @see https://developer.apple.com/documentation/metal/mtlorigin?language=objc
    struct Origin
    {
        Origin() = default;

        Origin(NS::UInteger x, NS::UInteger y, NS::UInteger z);

        static Origin Make(NS::UInteger x, NS::UInteger y, NS::UInteger z);

        NS::UInteger x;
        NS::UInteger y;
        NS::UInteger z;
    } _MTL_PACKED;

    /// @see https://developer.apple.com/documentation/metal/mtlsize?language=objc
    struct Size
    {
        Size() = default;

        Size(NS::UInteger width, NS::UInteger height, NS::UInteger depth);

        [[nodiscard]] static Size Make(NS::UInteger width, NS::UInteger height, NS::UInteger depth);

        NS::UInteger width;
        NS::UInteger height;
        NS::UInteger depth;
    } _MTL_PACKED;

    /// @see https://developer.apple.com/documentation/metal/mtlregion?language=objc
    struct Region
    {
        Region() = default;

        Region(NS::UInteger x, NS::UInteger width);

        Region(NS::UInteger x, NS::UInteger y, NS::UInteger width, NS::UInteger height);

        Region(NS::UInteger x,
               NS::UInteger y,
               NS::UInteger z,
               NS::UInteger width,
               NS::UInteger height,
               NS::UInteger depth);

        [[nodiscard]] static Region Make1D(NS::UInteger x, NS::UInteger width);

        [[nodiscard]] static Region Make2D(NS::UInteger x, NS::UInteger y, NS::UInteger width, NS::UInteger height);

        [[nodiscard]] static Region Make3D(NS::UInteger x,
                                           NS::UInteger y,
                                           NS::UInteger z,
                                           NS::UInteger width,
                                           NS::UInteger height,
                                           NS::UInteger depth);

        Origin origin;
        Size   size;
    } _MTL_PACKED;

    /// @see https://developer.apple.com/documentation/metal/mtlsampleposition?language=objc
    struct SamplePosition
    {
        SamplePosition() = default;

        SamplePosition(float x, float y);

        [[nodiscard]] static SamplePosition Make(float x, float y);

        float x;
        float y;
    } _MTL_PACKED;

    /// @see https://developer.apple.com/documentation/metal/mtlresourceid?language=objc
    struct ResourceID
    {
        uint64_t _impl;
    } _MTL_PACKED;

} // namespace MTL
_MTL_INLINE MTL::Origin::Origin(const NS::UInteger x, const NS::UInteger y, const NS::UInteger z) : x(x), y(y), z(z) {}

_MTL_INLINE MTL::Origin MTL::Origin::Make(const NS::UInteger x, const NS::UInteger y, const NS::UInteger z)
{
    return { x, y, z };
}

_MTL_INLINE MTL::Size::Size(const NS::UInteger width, const NS::UInteger height, const NS::UInteger depth)
    : width(width), height(height), depth(depth)
{
}

_MTL_INLINE MTL::Size MTL::Size::Make(const NS::UInteger width, const NS::UInteger height, const NS::UInteger depth)
{
    return { width, height, depth };
}

_MTL_INLINE MTL::Region::Region(const NS::UInteger x, const NS::UInteger width) : origin(x, 0, 0), size(width, 1, 1) {}

_MTL_INLINE MTL::Region::Region(const NS::UInteger x,
                                const NS::UInteger y,
                                const NS::UInteger width,
                                const NS::UInteger height)
    : origin(x, y, 0), size(width, height, 1)
{
}

_MTL_INLINE MTL::Region::Region(const NS::UInteger x,
                                const NS::UInteger y,
                                const NS::UInteger z,
                                const NS::UInteger width,
                                const NS::UInteger height,
                                const NS::UInteger depth)
    : origin(x, y, z), size(width, height, depth)
{
}

_MTL_INLINE MTL::Region MTL::Region::Make1D(const NS::UInteger x, const NS::UInteger width) { return { x, width }; }

_MTL_INLINE MTL::Region MTL::Region::Make2D(const NS::UInteger x,
                                            const NS::UInteger y,
                                            const NS::UInteger width,
                                            const NS::UInteger height)
{
    return { x, y, width, height };
}

_MTL_INLINE MTL::Region MTL::Region::Make3D(const NS::UInteger x,
                                            const NS::UInteger y,
                                            const NS::UInteger z,
                                            const NS::UInteger width,
                                            const NS::UInteger height,
                                            const NS::UInteger depth)
{
    return { x, y, z, width, height, depth };
}

_MTL_INLINE MTL::SamplePosition::SamplePosition(const float x, const float y) : x(x), y(y) {}

_MTL_INLINE MTL::SamplePosition MTL::SamplePosition::Make(const float x, const float y) { return { x, y }; }
