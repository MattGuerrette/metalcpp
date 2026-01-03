//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTL4StitchedFunctionDescriptor.hpp
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
#include "MTL4FunctionDescriptor.hpp"
#include "MTLDefines.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"

namespace MTL4
{
    class StitchedFunctionDescriptor;
}

namespace MTL
{
    class FunctionStitchingGraph;
}

namespace MTL4
{
    /// @see https://developer.apple.com/documentation/metal/mtl4stitchedfunctiondescriptor
    class StitchedFunctionDescriptor : public NS::Copying<StitchedFunctionDescriptor, FunctionDescriptor>
    {
    public:
        [[nodiscard]] static StitchedFunctionDescriptor* alloc();

        [[nodiscard]] NS::Array* functionDescriptors() const;

        [[nodiscard]] MTL::FunctionStitchingGraph* functionGraph() const;

        [[nodiscard]] StitchedFunctionDescriptor* init();

        void setFunctionDescriptors(const NS::Array* functionDescriptors) const;

        void setFunctionGraph(const MTL::FunctionStitchingGraph* functionGraph) const;
    };

} // namespace MTL4
_MTL_INLINE MTL4::StitchedFunctionDescriptor* MTL4::StitchedFunctionDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<StitchedFunctionDescriptor>(_MTL_PRIVATE_CLS(MTL4StitchedFunctionDescriptor));
}

_MTL_INLINE NS::Array* MTL4::StitchedFunctionDescriptor::functionDescriptors() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(functionDescriptors));
}

_MTL_INLINE MTL::FunctionStitchingGraph* MTL4::StitchedFunctionDescriptor::functionGraph() const
{
    return sendMessage<MTL::FunctionStitchingGraph*>(this, _MTL_PRIVATE_SEL(functionGraph));
}

_MTL_INLINE MTL4::StitchedFunctionDescriptor* MTL4::StitchedFunctionDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<StitchedFunctionDescriptor>();
}

_MTL_INLINE void MTL4::StitchedFunctionDescriptor::setFunctionDescriptors(const NS::Array* functionDescriptors) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFunctionDescriptors_), functionDescriptors);
}

_MTL_INLINE void MTL4::StitchedFunctionDescriptor::setFunctionGraph(
    const MTL::FunctionStitchingGraph* functionGraph) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFunctionGraph_), functionGraph);
}
