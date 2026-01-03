//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTL4MachineLearningPipeline.hpp
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
#include "MTL4PipelineState.hpp"
#include "MTLAllocation.hpp"
#include "MTLDefines.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"

namespace MTL4
{
    class FunctionDescriptor;
    class MachineLearningPipelineDescriptor;
    class MachineLearningPipelineReflection;
} // namespace MTL4

namespace MTL
{
    class Device;
    class TensorExtents;
} // namespace MTL

namespace MTL4
{
    /// @see https://developer.apple.com/documentation/metal/mtl4machinelearningpipelinedescriptor
    class MachineLearningPipelineDescriptor : public NS::Copying<MachineLearningPipelineDescriptor, PipelineDescriptor>
    {
    public:
        [[nodiscard]] static MachineLearningPipelineDescriptor* alloc();

        [[nodiscard]] MachineLearningPipelineDescriptor* init();

        [[nodiscard]] MTL::TensorExtents* inputDimensionsAtBufferIndex(NS::Integer bufferIndex) const;

        [[nodiscard]] NS::String* label() const;

        [[nodiscard]] FunctionDescriptor* machineLearningFunctionDescriptor() const;

        void reset() const;

        void setInputDimensions(const MTL::TensorExtents* dimensions, NS::Integer bufferIndex) const;
        void setInputDimensions(const NS::Array* dimensions, NS::Range range) const;

        void setLabel(const NS::String* label) const;

        void setMachineLearningFunctionDescriptor(const FunctionDescriptor* machineLearningFunctionDescriptor) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtl4machinelearningpipelinereflection
    class MachineLearningPipelineReflection : public NS::Referencing<MachineLearningPipelineReflection>
    {
    public:
        [[nodiscard]] static MachineLearningPipelineReflection* alloc();

        [[nodiscard]] NS::Array* bindings() const;

        [[nodiscard]] MachineLearningPipelineReflection* init();
    };

    /// @see https://developer.apple.com/documentation/metal/mtl4machinelearningpipelinestate
    class MachineLearningPipelineState : public NS::Referencing<MachineLearningPipelineState, MTL::Allocation>
    {
    public:
        [[nodiscard]] MTL::Device* device() const;

        [[nodiscard]] NS::UInteger intermediatesHeapSize() const;

        [[nodiscard]] NS::String* label() const;

        [[nodiscard]] MachineLearningPipelineReflection* reflection() const;
    };

} // namespace MTL4


_MTL_INLINE MTL4::MachineLearningPipelineDescriptor* MTL4::MachineLearningPipelineDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<MachineLearningPipelineDescriptor>(
        _MTL_PRIVATE_CLS(MTL4MachineLearningPipelineDescriptor));
}

_MTL_INLINE MTL4::MachineLearningPipelineDescriptor* MTL4::MachineLearningPipelineDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<MachineLearningPipelineDescriptor>();
}

_MTL_INLINE MTL::TensorExtents* MTL4::MachineLearningPipelineDescriptor::inputDimensionsAtBufferIndex(
    const NS::Integer bufferIndex) const
{
    return sendMessage<MTL::TensorExtents*>(this, _MTL_PRIVATE_SEL(inputDimensionsAtBufferIndex_), bufferIndex);
}

_MTL_INLINE NS::String* MTL4::MachineLearningPipelineDescriptor::label() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
}

_MTL_INLINE MTL4::FunctionDescriptor* MTL4::MachineLearningPipelineDescriptor::machineLearningFunctionDescriptor() const
{
    return sendMessage<FunctionDescriptor*>(this, _MTL_PRIVATE_SEL(machineLearningFunctionDescriptor));
}

_MTL_INLINE void MTL4::MachineLearningPipelineDescriptor::reset() const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(reset));
}

_MTL_INLINE void MTL4::MachineLearningPipelineDescriptor::setInputDimensions(const MTL::TensorExtents* dimensions,
                                                                             const NS::Integer bufferIndex) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setInputDimensions_atBufferIndex_), dimensions, bufferIndex);
}

_MTL_INLINE void MTL4::MachineLearningPipelineDescriptor::setInputDimensions(const NS::Array* dimensions,
                                                                             const NS::Range  range) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setInputDimensions_withRange_), dimensions, range);
}

_MTL_INLINE void MTL4::MachineLearningPipelineDescriptor::setLabel(const NS::String* label) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLabel_), label);
}

_MTL_INLINE void MTL4::MachineLearningPipelineDescriptor::setMachineLearningFunctionDescriptor(
    const FunctionDescriptor* machineLearningFunctionDescriptor) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMachineLearningFunctionDescriptor_), machineLearningFunctionDescriptor);
}

_MTL_INLINE MTL4::MachineLearningPipelineReflection* MTL4::MachineLearningPipelineReflection::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<MachineLearningPipelineReflection>(
        _MTL_PRIVATE_CLS(MTL4MachineLearningPipelineReflection));
}

_MTL_INLINE NS::Array* MTL4::MachineLearningPipelineReflection::bindings() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(bindings));
}

_MTL_INLINE MTL4::MachineLearningPipelineReflection* MTL4::MachineLearningPipelineReflection::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<MachineLearningPipelineReflection>();
}

_MTL_INLINE MTL::Device* MTL4::MachineLearningPipelineState::device() const
{
    return sendMessage<MTL::Device*>(this, _MTL_PRIVATE_SEL(device));
}

_MTL_INLINE NS::UInteger MTL4::MachineLearningPipelineState::intermediatesHeapSize() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(intermediatesHeapSize));
}

_MTL_INLINE NS::String* MTL4::MachineLearningPipelineState::label() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
}

_MTL_INLINE MTL4::MachineLearningPipelineReflection* MTL4::MachineLearningPipelineState::reflection() const
{
    return sendMessage<MachineLearningPipelineReflection*>(this, _MTL_PRIVATE_SEL(reflection));
}
