//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLComputePipeline.hpp
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
#include "MTLAllocation.hpp"
#include "MTLDefines.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPipeline.hpp"
#include "MTLPrivate.hpp"
#include "MTLTypes.hpp"

namespace MTL
{
    class ComputePipelineDescriptor;
    class ComputePipelineReflection;
    class ComputePipelineState;
    class Device;
    class Function;
    class FunctionHandle;
    class IntersectionFunctionTable;
    class IntersectionFunctionTableDescriptor;
    class LinkedFunctions;
    class PipelineBufferDescriptorArray;
    class StageInputOutputDescriptor;
    class VisibleFunctionTable;
    class VisibleFunctionTableDescriptor;

} // namespace MTL
namespace MTL4
{
    class BinaryFunction;

}
namespace MTL
{

    /// @see https://developer.apple.com/documentation/metal/mtlcomputepipelinereflection?language=objc
    class ComputePipelineReflection : public NS::Referencing<ComputePipelineReflection>
    {
    public:
        [[nodiscard]] static ComputePipelineReflection* alloc();

        [[nodiscard]] NS::Array* arguments() const;

        [[nodiscard]] NS::Array* bindings() const;

        [[nodiscard]] ComputePipelineReflection* init();
    };

    /// @see https://developer.apple.com/documentation/metal/mtlcomputepipelinedescriptor?language=objc
    class ComputePipelineDescriptor : public NS::Copying<ComputePipelineDescriptor>
    {
    public:
        [[nodiscard]] static ComputePipelineDescriptor* alloc();

        [[nodiscard]] NS::Array* binaryArchives() const;

        [[nodiscard]] PipelineBufferDescriptorArray* buffers() const;

        [[nodiscard]] Function* computeFunction() const;

        [[nodiscard]] ComputePipelineDescriptor* init();

        [[nodiscard]] NS::Array* insertLibraries() const;

        [[nodiscard]] NS::String* label() const;

        [[nodiscard]] LinkedFunctions* linkedFunctions() const;

        [[nodiscard]] NS::UInteger maxCallStackDepth() const;

        [[nodiscard]] NS::UInteger maxTotalThreadsPerThreadgroup() const;

        [[nodiscard]] NS::Array* preloadedLibraries() const;

        [[nodiscard]] Size requiredThreadsPerThreadgroup() const;

        void reset() const;

        void setBinaryArchives(const NS::Array* binaryArchives) const;

        void setComputeFunction(const Function* computeFunction) const;

        void setInsertLibraries(const NS::Array* insertLibraries) const;

        void setLabel(const NS::String* label) const;

        void setLinkedFunctions(const LinkedFunctions* linkedFunctions) const;

        void setMaxCallStackDepth(NS::UInteger maxCallStackDepth) const;

        void setMaxTotalThreadsPerThreadgroup(NS::UInteger maxTotalThreadsPerThreadgroup) const;

        void setPreloadedLibraries(const NS::Array* preloadedLibraries) const;

        void setRequiredThreadsPerThreadgroup(const Size& requiredThreadsPerThreadgroup) const;

        void setShaderValidation(ShaderValidation shaderValidation) const;

        void setStageInputDescriptor(const StageInputOutputDescriptor* stageInputDescriptor) const;

        void setSupportAddingBinaryFunctions(bool supportAddingBinaryFunctions) const;

        void setSupportIndirectCommandBuffers(bool supportIndirectCommandBuffers) const;

        void setThreadGroupSizeIsMultipleOfThreadExecutionWidth(
            bool threadGroupSizeIsMultipleOfThreadExecutionWidth) const;

        [[nodiscard]] ShaderValidation shaderValidation() const;

        [[nodiscard]] StageInputOutputDescriptor* stageInputDescriptor() const;

        [[nodiscard]] bool supportAddingBinaryFunctions() const;

        [[nodiscard]] bool supportIndirectCommandBuffers() const;

        [[nodiscard]] bool threadGroupSizeIsMultipleOfThreadExecutionWidth() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlcomputepipelinestate?language=objc
    class ComputePipelineState : public NS::Referencing<ComputePipelineState, Allocation>
    {
    public:
        [[nodiscard]] Device* device() const;

        [[nodiscard]] FunctionHandle* functionHandle(const NS::String* name) const;
        [[nodiscard]] FunctionHandle* functionHandle(const MTL4::BinaryFunction* function) const;
        [[nodiscard]] FunctionHandle* functionHandle(const Function* function) const;

        [[nodiscard]] ResourceID gpuResourceID() const;

        [[nodiscard]] NS::UInteger imageblockMemoryLength(const Size& imageblockDimensions) const;

        [[nodiscard]] NS::String* label() const;

        [[nodiscard]] NS::UInteger maxTotalThreadsPerThreadgroup() const;

        [[nodiscard]] ComputePipelineState* newComputePipelineStateWithBinaryFunctions(
            const NS::Array* additionalBinaryFunctions, NS::Error** error) const;
        [[nodiscard]] ComputePipelineState* newComputePipelineState(const NS::Array* functions,
                                                                    NS::Error**      error) const;

        [[nodiscard]] IntersectionFunctionTable* newIntersectionFunctionTable(
            const IntersectionFunctionTableDescriptor* descriptor) const;

        [[nodiscard]] VisibleFunctionTable* newVisibleFunctionTable(
            const VisibleFunctionTableDescriptor* descriptor) const;

        [[nodiscard]] ComputePipelineReflection* reflection() const;

        [[nodiscard]] Size requiredThreadsPerThreadgroup() const;

        [[nodiscard]] ShaderValidation shaderValidation() const;

        [[nodiscard]] NS::UInteger staticThreadgroupMemoryLength() const;

        [[nodiscard]] bool supportIndirectCommandBuffers() const;

        [[nodiscard]] NS::UInteger threadExecutionWidth() const;
    };

} // namespace MTL
_MTL_INLINE MTL::ComputePipelineReflection* MTL::ComputePipelineReflection::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<ComputePipelineReflection>(_MTL_PRIVATE_CLS(MTLComputePipelineReflection));
}

_MTL_INLINE NS::Array* MTL::ComputePipelineReflection::arguments() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(arguments));
}

_MTL_INLINE NS::Array* MTL::ComputePipelineReflection::bindings() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(bindings));
}

_MTL_INLINE MTL::ComputePipelineReflection* MTL::ComputePipelineReflection::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<ComputePipelineReflection>();
}

_MTL_INLINE MTL::ComputePipelineDescriptor* MTL::ComputePipelineDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<ComputePipelineDescriptor>(_MTL_PRIVATE_CLS(MTLComputePipelineDescriptor));
}

_MTL_INLINE NS::Array* MTL::ComputePipelineDescriptor::binaryArchives() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(binaryArchives));
}

_MTL_INLINE MTL::PipelineBufferDescriptorArray* MTL::ComputePipelineDescriptor::buffers() const
{
    return sendMessage<PipelineBufferDescriptorArray*>(this, _MTL_PRIVATE_SEL(buffers));
}

_MTL_INLINE MTL::Function* MTL::ComputePipelineDescriptor::computeFunction() const
{
    return sendMessage<Function*>(this, _MTL_PRIVATE_SEL(computeFunction));
}

_MTL_INLINE MTL::ComputePipelineDescriptor* MTL::ComputePipelineDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<ComputePipelineDescriptor>();
}

_MTL_INLINE NS::Array* MTL::ComputePipelineDescriptor::insertLibraries() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(insertLibraries));
}

_MTL_INLINE NS::String* MTL::ComputePipelineDescriptor::label() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
}

_MTL_INLINE MTL::LinkedFunctions* MTL::ComputePipelineDescriptor::linkedFunctions() const
{
    return sendMessage<LinkedFunctions*>(this, _MTL_PRIVATE_SEL(linkedFunctions));
}

_MTL_INLINE NS::UInteger MTL::ComputePipelineDescriptor::maxCallStackDepth() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxCallStackDepth));
}

_MTL_INLINE NS::UInteger MTL::ComputePipelineDescriptor::maxTotalThreadsPerThreadgroup() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxTotalThreadsPerThreadgroup));
}

_MTL_INLINE NS::Array* MTL::ComputePipelineDescriptor::preloadedLibraries() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(preloadedLibraries));
}

_MTL_INLINE MTL::Size MTL::ComputePipelineDescriptor::requiredThreadsPerThreadgroup() const
{
    return sendMessage<Size>(this, _MTL_PRIVATE_SEL(requiredThreadsPerThreadgroup));
}

_MTL_INLINE void MTL::ComputePipelineDescriptor::reset() const { sendMessage<void>(this, _MTL_PRIVATE_SEL(reset)); }

_MTL_INLINE void MTL::ComputePipelineDescriptor::setBinaryArchives(const NS::Array* binaryArchives) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBinaryArchives_), binaryArchives);
}

_MTL_INLINE void MTL::ComputePipelineDescriptor::setComputeFunction(const Function* computeFunction) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setComputeFunction_), computeFunction);
}

_MTL_INLINE void MTL::ComputePipelineDescriptor::setInsertLibraries(const NS::Array* insertLibraries) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setInsertLibraries_), insertLibraries);
}

_MTL_INLINE void MTL::ComputePipelineDescriptor::setLabel(const NS::String* label) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLabel_), label);
}

_MTL_INLINE void MTL::ComputePipelineDescriptor::setLinkedFunctions(const LinkedFunctions* linkedFunctions) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLinkedFunctions_), linkedFunctions);
}

_MTL_INLINE void MTL::ComputePipelineDescriptor::setMaxCallStackDepth(const NS::UInteger maxCallStackDepth) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxCallStackDepth_), maxCallStackDepth);
}

_MTL_INLINE void MTL::ComputePipelineDescriptor::setMaxTotalThreadsPerThreadgroup(
    const NS::UInteger maxTotalThreadsPerThreadgroup) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxTotalThreadsPerThreadgroup_), maxTotalThreadsPerThreadgroup);
}

_MTL_INLINE void MTL::ComputePipelineDescriptor::setPreloadedLibraries(const NS::Array* preloadedLibraries) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setPreloadedLibraries_), preloadedLibraries);
}

_MTL_INLINE void MTL::ComputePipelineDescriptor::setRequiredThreadsPerThreadgroup(
    const Size& requiredThreadsPerThreadgroup) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRequiredThreadsPerThreadgroup_), requiredThreadsPerThreadgroup);
}

_MTL_INLINE void MTL::ComputePipelineDescriptor::setShaderValidation(const ShaderValidation shaderValidation) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setShaderValidation_), shaderValidation);
}

_MTL_INLINE void MTL::ComputePipelineDescriptor::setStageInputDescriptor(
    const StageInputOutputDescriptor* stageInputDescriptor) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setStageInputDescriptor_), stageInputDescriptor);
}

_MTL_INLINE void MTL::ComputePipelineDescriptor::setSupportAddingBinaryFunctions(
    const bool supportAddingBinaryFunctions) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSupportAddingBinaryFunctions_), supportAddingBinaryFunctions);
}

_MTL_INLINE void MTL::ComputePipelineDescriptor::setSupportIndirectCommandBuffers(
    const bool supportIndirectCommandBuffers) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setSupportIndirectCommandBuffers_), supportIndirectCommandBuffers);
}

_MTL_INLINE void MTL::ComputePipelineDescriptor::setThreadGroupSizeIsMultipleOfThreadExecutionWidth(
    const bool threadGroupSizeIsMultipleOfThreadExecutionWidth) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(setThreadGroupSizeIsMultipleOfThreadExecutionWidth_),
                      threadGroupSizeIsMultipleOfThreadExecutionWidth);
}

_MTL_INLINE MTL::ShaderValidation MTL::ComputePipelineDescriptor::shaderValidation() const
{
    return sendMessage<ShaderValidation>(this, _MTL_PRIVATE_SEL(shaderValidation));
}

_MTL_INLINE MTL::StageInputOutputDescriptor* MTL::ComputePipelineDescriptor::stageInputDescriptor() const
{
    return sendMessage<StageInputOutputDescriptor*>(this, _MTL_PRIVATE_SEL(stageInputDescriptor));
}

_MTL_INLINE bool MTL::ComputePipelineDescriptor::supportAddingBinaryFunctions() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supportAddingBinaryFunctions));
}

_MTL_INLINE bool MTL::ComputePipelineDescriptor::supportIndirectCommandBuffers() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supportIndirectCommandBuffers));
}

_MTL_INLINE bool MTL::ComputePipelineDescriptor::threadGroupSizeIsMultipleOfThreadExecutionWidth() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(threadGroupSizeIsMultipleOfThreadExecutionWidth));
}

_MTL_INLINE MTL::Device* MTL::ComputePipelineState::device() const
{
    return sendMessage<Device*>(this, _MTL_PRIVATE_SEL(device));
}

_MTL_INLINE MTL::FunctionHandle* MTL::ComputePipelineState::functionHandle(const NS::String* name) const
{
    return sendMessage<FunctionHandle*>(this, _MTL_PRIVATE_SEL(functionHandleWithName_), name);
}

_MTL_INLINE MTL::FunctionHandle* MTL::ComputePipelineState::functionHandle(const MTL4::BinaryFunction* function) const
{
    return sendMessage<FunctionHandle*>(this, _MTL_PRIVATE_SEL(functionHandleWithBinaryFunction_), function);
}

_MTL_INLINE MTL::FunctionHandle* MTL::ComputePipelineState::functionHandle(const Function* function) const
{
    return sendMessage<FunctionHandle*>(this, _MTL_PRIVATE_SEL(functionHandleWithFunction_), function);
}

_MTL_INLINE MTL::ResourceID MTL::ComputePipelineState::gpuResourceID() const
{
    return sendMessage<ResourceID>(this, _MTL_PRIVATE_SEL(gpuResourceID));
}

_MTL_INLINE NS::UInteger MTL::ComputePipelineState::imageblockMemoryLength(const Size& imageblockDimensions) const
{
    return sendMessage<NS::UInteger>(
        this, _MTL_PRIVATE_SEL(imageblockMemoryLengthForDimensions_), imageblockDimensions);
}

_MTL_INLINE NS::String* MTL::ComputePipelineState::label() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
}

_MTL_INLINE NS::UInteger MTL::ComputePipelineState::maxTotalThreadsPerThreadgroup() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxTotalThreadsPerThreadgroup));
}

_MTL_INLINE MTL::ComputePipelineState* MTL::ComputePipelineState::newComputePipelineStateWithBinaryFunctions(
    const NS::Array* additionalBinaryFunctions, NS::Error** error) const
{
    return sendMessage<ComputePipelineState*>(
        this, _MTL_PRIVATE_SEL(newComputePipelineStateWithBinaryFunctions_error_), additionalBinaryFunctions, error);
}

_MTL_INLINE MTL::ComputePipelineState* MTL::ComputePipelineState::newComputePipelineState(const NS::Array* functions,
                                                                                          NS::Error**      error) const
{
    return sendMessage<ComputePipelineState*>(
        this, _MTL_PRIVATE_SEL(newComputePipelineStateWithAdditionalBinaryFunctions_error_), functions, error);
}

_MTL_INLINE MTL::IntersectionFunctionTable* MTL::ComputePipelineState::newIntersectionFunctionTable(
    const IntersectionFunctionTableDescriptor* descriptor) const
{
    return sendMessage<IntersectionFunctionTable*>(
        this, _MTL_PRIVATE_SEL(newIntersectionFunctionTableWithDescriptor_), descriptor);
}

_MTL_INLINE MTL::VisibleFunctionTable* MTL::ComputePipelineState::newVisibleFunctionTable(
    const VisibleFunctionTableDescriptor* descriptor) const
{
    return sendMessage<VisibleFunctionTable*>(
        this, _MTL_PRIVATE_SEL(newVisibleFunctionTableWithDescriptor_), descriptor);
}

_MTL_INLINE MTL::ComputePipelineReflection* MTL::ComputePipelineState::reflection() const
{
    return sendMessage<ComputePipelineReflection*>(this, _MTL_PRIVATE_SEL(reflection));
}

_MTL_INLINE MTL::Size MTL::ComputePipelineState::requiredThreadsPerThreadgroup() const
{
    return sendMessage<Size>(this, _MTL_PRIVATE_SEL(requiredThreadsPerThreadgroup));
}

_MTL_INLINE MTL::ShaderValidation MTL::ComputePipelineState::shaderValidation() const
{
    return sendMessage<ShaderValidation>(this, _MTL_PRIVATE_SEL(shaderValidation));
}

_MTL_INLINE NS::UInteger MTL::ComputePipelineState::staticThreadgroupMemoryLength() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(staticThreadgroupMemoryLength));
}

_MTL_INLINE bool MTL::ComputePipelineState::supportIndirectCommandBuffers() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supportIndirectCommandBuffers));
}

_MTL_INLINE NS::UInteger MTL::ComputePipelineState::threadExecutionWidth() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(threadExecutionWidth));
}
