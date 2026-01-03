//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLCommandBuffer.hpp
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

#include <CoreFoundation/CoreFoundation.h>
#include "../Foundation/Foundation.hpp"
#include "MTLDefines.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"

#include <cstdint>
#include <functional>

namespace MTL
{
    class AccelerationStructureCommandEncoder;
    class AccelerationStructurePassDescriptor;
    class BlitCommandEncoder;
    class BlitPassDescriptor;
    class CommandBuffer;
    class CommandBufferDescriptor;
    class CommandQueue;
    class ComputeCommandEncoder;
    class ComputePassDescriptor;
    class Device;
    class Drawable;
    class Event;
    class LogContainer;
    class LogState;
    class ParallelRenderCommandEncoder;
    class RenderCommandEncoder;
    class RenderPassDescriptor;
    class ResidencySet;
    class ResourceStateCommandEncoder;
    class ResourceStatePassDescriptor;
    _MTL_ENUM(NS::UInteger, CommandBufferStatus){
        CommandBufferStatusNotEnqueued = 0, CommandBufferStatusEnqueued = 1,  CommandBufferStatusCommitted = 2,
        CommandBufferStatusScheduled = 3,   CommandBufferStatusCompleted = 4, CommandBufferStatusError = 5,
    };

    _MTL_ENUM(NS::UInteger, CommandBufferError){
        CommandBufferErrorNone = 0,         CommandBufferErrorInternal = 1,       CommandBufferErrorTimeout = 2,
        CommandBufferErrorPageFault = 3,    CommandBufferErrorBlacklisted = 4,    CommandBufferErrorAccessRevoked = 4,
        CommandBufferErrorNotPermitted = 7, CommandBufferErrorOutOfMemory = 8,    CommandBufferErrorInvalidResource = 9,
        CommandBufferErrorMemoryless = 10,  CommandBufferErrorDeviceRemoved = 11, CommandBufferErrorStackOverflow = 12,
    };

    _MTL_ENUM(NS::Integer, CommandEncoderErrorState){
        CommandEncoderErrorStateUnknown = 0,  CommandEncoderErrorStateCompleted = 1,
        CommandEncoderErrorStateAffected = 2, CommandEncoderErrorStatePending = 3,
        CommandEncoderErrorStateFaulted = 4,
    };

    _MTL_ENUM(NS::UInteger, DispatchType){
        DispatchTypeSerial     = 0,
        DispatchTypeConcurrent = 1,
    };

    _MTL_OPTIONS(NS::UInteger, CommandBufferErrorOption){
        CommandBufferErrorOptionNone                   = 0,
        CommandBufferErrorOptionEncoderExecutionStatus = 1,
    };

    using CommandBufferHandler = void (^)(CommandBuffer*);
    using HandlerFunction      = std::function<void(CommandBuffer*)>;

    /// @see https://developer.apple.com/documentation/metal/mtlcommandbufferdescriptor?language=objc
    class CommandBufferDescriptor : public NS::Copying<CommandBufferDescriptor>
    {
    public:
        [[nodiscard]] static CommandBufferDescriptor* alloc();

        [[nodiscard]] CommandBufferErrorOption errorOptions() const;

        [[nodiscard]] CommandBufferDescriptor* init();

        [[nodiscard]] LogState* logState() const;

        [[nodiscard]] bool retainedReferences() const;

        void setErrorOptions(CommandBufferErrorOption errorOptions) const;

        void setLogState(const LogState* logState) const;

        void setRetainedReferences(bool retainedReferences) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlcommandbufferencoderinfo?language=objc
    class CommandBufferEncoderInfo : public NS::Referencing<CommandBufferEncoderInfo>
    {
    public:
        [[nodiscard]] NS::Array* debugSignposts() const;

        [[nodiscard]] CommandEncoderErrorState errorState() const;

        [[nodiscard]] NS::String* label() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlcommandbuffer?language=objc
    class CommandBuffer : public NS::Referencing<CommandBuffer>
    {
    public:
        [[nodiscard]] CFTimeInterval GPUEndTime() const;

        [[nodiscard]] CFTimeInterval GPUStartTime() const;

        [[nodiscard]] AccelerationStructureCommandEncoder* accelerationStructureCommandEncoder() const;
        [[nodiscard]] AccelerationStructureCommandEncoder* accelerationStructureCommandEncoder(
            const AccelerationStructurePassDescriptor* descriptor) const;

        void addCompletedHandler(CommandBufferHandler block);
        void addCompletedHandler(const HandlerFunction& function);

        void addScheduledHandler(CommandBufferHandler block);
        void addScheduledHandler(const HandlerFunction& function);

        [[nodiscard]] BlitCommandEncoder* blitCommandEncoder() const;
        [[nodiscard]] BlitCommandEncoder* blitCommandEncoder(const BlitPassDescriptor* blitPassDescriptor) const;

        [[nodiscard]] CommandQueue* commandQueue() const;

        void commit() const;

        [[nodiscard]] ComputeCommandEncoder* computeCommandEncoder(
            const ComputePassDescriptor* computePassDescriptor) const;
        [[nodiscard]] ComputeCommandEncoder* computeCommandEncoder() const;
        [[nodiscard]] ComputeCommandEncoder* computeCommandEncoder(DispatchType dispatchType) const;

        [[nodiscard]] Device* device() const;

        void encodeSignalEvent(const Event* event, uint64_t value) const;

        void encodeWait(const Event* event, uint64_t value) const;

        void enqueue() const;

        [[nodiscard]] NS::Error*               error() const;
        [[nodiscard]] CommandBufferErrorOption errorOptions() const;

        [[nodiscard]] CFTimeInterval kernelEndTime() const;

        [[nodiscard]] CFTimeInterval kernelStartTime() const;

        [[nodiscard]] NS::String* label() const;

        [[nodiscard]] LogContainer* logs() const;

        [[nodiscard]] ParallelRenderCommandEncoder* parallelRenderCommandEncoder(
            const RenderPassDescriptor* renderPassDescriptor) const;

        void popDebugGroup() const;

        void presentDrawable(const Drawable* drawable) const;
        void presentDrawableAfterMinimumDuration(const Drawable* drawable, CFTimeInterval duration) const;

        void presentDrawableAtTime(const Drawable* drawable, CFTimeInterval presentationTime) const;

        void pushDebugGroup(const NS::String* string) const;

        [[nodiscard]] RenderCommandEncoder* renderCommandEncoder(
            const RenderPassDescriptor* renderPassDescriptor) const;

        [[nodiscard]] ResourceStateCommandEncoder* resourceStateCommandEncoder() const;
        [[nodiscard]] ResourceStateCommandEncoder* resourceStateCommandEncoder(
            const ResourceStatePassDescriptor* resourceStatePassDescriptor) const;

        [[nodiscard]] bool retainedReferences() const;

        void setLabel(const NS::String* label) const;

        [[nodiscard]] CommandBufferStatus status() const;

        void useResidencySet(const ResidencySet* residencySet) const;
        void useResidencySets(const ResidencySet* const residencySets[], NS::UInteger count) const;

        void waitUntilCompleted() const;

        void waitUntilScheduled() const;
    };

} // namespace MTL
_MTL_INLINE MTL::CommandBufferDescriptor* MTL::CommandBufferDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<CommandBufferDescriptor>(_MTL_PRIVATE_CLS(MTLCommandBufferDescriptor));
}

_MTL_INLINE MTL::CommandBufferErrorOption MTL::CommandBufferDescriptor::errorOptions() const
{
    return sendMessage<CommandBufferErrorOption>(this, _MTL_PRIVATE_SEL(errorOptions));
}

_MTL_INLINE MTL::CommandBufferDescriptor* MTL::CommandBufferDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<CommandBufferDescriptor>();
}

_MTL_INLINE MTL::LogState* MTL::CommandBufferDescriptor::logState() const
{
    return sendMessage<LogState*>(this, _MTL_PRIVATE_SEL(logState));
}

_MTL_INLINE bool MTL::CommandBufferDescriptor::retainedReferences() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(retainedReferences));
}

_MTL_INLINE void MTL::CommandBufferDescriptor::setErrorOptions(const CommandBufferErrorOption errorOptions) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setErrorOptions_), errorOptions);
}

_MTL_INLINE void MTL::CommandBufferDescriptor::setLogState(const LogState* logState) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLogState_), logState);
}

_MTL_INLINE void MTL::CommandBufferDescriptor::setRetainedReferences(const bool retainedReferences) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRetainedReferences_), retainedReferences);
}

_MTL_INLINE NS::Array* MTL::CommandBufferEncoderInfo::debugSignposts() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(debugSignposts));
}

_MTL_INLINE MTL::CommandEncoderErrorState MTL::CommandBufferEncoderInfo::errorState() const
{
    return sendMessage<CommandEncoderErrorState>(this, _MTL_PRIVATE_SEL(errorState));
}

_MTL_INLINE NS::String* MTL::CommandBufferEncoderInfo::label() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
}

_MTL_INLINE CFTimeInterval MTL::CommandBuffer::GPUEndTime() const
{
    return sendMessage<CFTimeInterval>(this, _MTL_PRIVATE_SEL(GPUEndTime));
}

_MTL_INLINE CFTimeInterval MTL::CommandBuffer::GPUStartTime() const
{
    return sendMessage<CFTimeInterval>(this, _MTL_PRIVATE_SEL(GPUStartTime));
}

_MTL_INLINE MTL::AccelerationStructureCommandEncoder* MTL::CommandBuffer::accelerationStructureCommandEncoder() const
{
    return sendMessage<AccelerationStructureCommandEncoder*>(this,
                                                             _MTL_PRIVATE_SEL(accelerationStructureCommandEncoder));
}

_MTL_INLINE MTL::AccelerationStructureCommandEncoder* MTL::CommandBuffer::accelerationStructureCommandEncoder(
    const AccelerationStructurePassDescriptor* descriptor) const
{
    return sendMessage<AccelerationStructureCommandEncoder*>(
        this, _MTL_PRIVATE_SEL(accelerationStructureCommandEncoderWithDescriptor_), descriptor);
}

_MTL_INLINE void MTL::CommandBuffer::addCompletedHandler(const CommandBufferHandler block)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(addCompletedHandler_), block);
}

_MTL_INLINE void MTL::CommandBuffer::addCompletedHandler(const HandlerFunction& function)
{
    __block HandlerFunction blockFunction = function;
    addCompletedHandler(^(CommandBuffer* pCommandBuffer) {
      blockFunction(pCommandBuffer);
    });
}

_MTL_INLINE void MTL::CommandBuffer::addScheduledHandler(const CommandBufferHandler block)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(addScheduledHandler_), block);
}

_MTL_INLINE void MTL::CommandBuffer::addScheduledHandler(const HandlerFunction& function)
{
    __block HandlerFunction blockFunction = function;
    addScheduledHandler(^(CommandBuffer* pCommandBuffer) {
      blockFunction(pCommandBuffer);
    });
}

_MTL_INLINE MTL::BlitCommandEncoder* MTL::CommandBuffer::blitCommandEncoder() const
{
    return sendMessage<BlitCommandEncoder*>(this, _MTL_PRIVATE_SEL(blitCommandEncoder));
}

_MTL_INLINE MTL::BlitCommandEncoder* MTL::CommandBuffer::blitCommandEncoder(
    const BlitPassDescriptor* blitPassDescriptor) const
{
    return sendMessage<BlitCommandEncoder*>(
        this, _MTL_PRIVATE_SEL(blitCommandEncoderWithDescriptor_), blitPassDescriptor);
}

_MTL_INLINE MTL::CommandQueue* MTL::CommandBuffer::commandQueue() const
{
    return sendMessage<CommandQueue*>(this, _MTL_PRIVATE_SEL(commandQueue));
}

_MTL_INLINE void MTL::CommandBuffer::commit() const { sendMessage<void>(this, _MTL_PRIVATE_SEL(commit)); }

_MTL_INLINE MTL::ComputeCommandEncoder* MTL::CommandBuffer::computeCommandEncoder(
    const ComputePassDescriptor* computePassDescriptor) const
{
    return sendMessage<ComputeCommandEncoder*>(
        this, _MTL_PRIVATE_SEL(computeCommandEncoderWithDescriptor_), computePassDescriptor);
}

_MTL_INLINE MTL::ComputeCommandEncoder* MTL::CommandBuffer::computeCommandEncoder() const
{
    return sendMessage<ComputeCommandEncoder*>(this, _MTL_PRIVATE_SEL(computeCommandEncoder));
}

_MTL_INLINE MTL::ComputeCommandEncoder* MTL::CommandBuffer::computeCommandEncoder(const DispatchType dispatchType) const
{
    return sendMessage<ComputeCommandEncoder*>(
        this, _MTL_PRIVATE_SEL(computeCommandEncoderWithDispatchType_), dispatchType);
}

_MTL_INLINE MTL::Device* MTL::CommandBuffer::device() const
{
    return sendMessage<Device*>(this, _MTL_PRIVATE_SEL(device));
}

_MTL_INLINE void MTL::CommandBuffer::encodeSignalEvent(const Event* event, const uint64_t value) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(encodeSignalEvent_value_), event, value);
}

_MTL_INLINE void MTL::CommandBuffer::encodeWait(const Event* event, const uint64_t value) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(encodeWaitForEvent_value_), event, value);
}

_MTL_INLINE void MTL::CommandBuffer::enqueue() const { sendMessage<void>(this, _MTL_PRIVATE_SEL(enqueue)); }

_MTL_INLINE NS::Error* MTL::CommandBuffer::error() const
{
    return sendMessage<NS::Error*>(this, _MTL_PRIVATE_SEL(error));
}

_MTL_INLINE MTL::CommandBufferErrorOption MTL::CommandBuffer::errorOptions() const
{
    return sendMessage<CommandBufferErrorOption>(this, _MTL_PRIVATE_SEL(errorOptions));
}

_MTL_INLINE CFTimeInterval MTL::CommandBuffer::kernelEndTime() const
{
    return sendMessage<CFTimeInterval>(this, _MTL_PRIVATE_SEL(kernelEndTime));
}

_MTL_INLINE CFTimeInterval MTL::CommandBuffer::kernelStartTime() const
{
    return sendMessage<CFTimeInterval>(this, _MTL_PRIVATE_SEL(kernelStartTime));
}

_MTL_INLINE NS::String* MTL::CommandBuffer::label() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
}

_MTL_INLINE MTL::LogContainer* MTL::CommandBuffer::logs() const
{
    return sendMessage<LogContainer*>(this, _MTL_PRIVATE_SEL(logs));
}

_MTL_INLINE MTL::ParallelRenderCommandEncoder* MTL::CommandBuffer::parallelRenderCommandEncoder(
    const RenderPassDescriptor* renderPassDescriptor) const
{
    return sendMessage<ParallelRenderCommandEncoder*>(
        this, _MTL_PRIVATE_SEL(parallelRenderCommandEncoderWithDescriptor_), renderPassDescriptor);
}

_MTL_INLINE void MTL::CommandBuffer::popDebugGroup() const { sendMessage<void>(this, _MTL_PRIVATE_SEL(popDebugGroup)); }

_MTL_INLINE void MTL::CommandBuffer::presentDrawable(const Drawable* drawable) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(presentDrawable_), drawable);
}

_MTL_INLINE void MTL::CommandBuffer::presentDrawableAfterMinimumDuration(const Drawable*      drawable,
                                                                         const CFTimeInterval duration) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(presentDrawable_afterMinimumDuration_), drawable, duration);
}

_MTL_INLINE void MTL::CommandBuffer::presentDrawableAtTime(const Drawable*      drawable,
                                                           const CFTimeInterval presentationTime) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(presentDrawable_atTime_), drawable, presentationTime);
}

_MTL_INLINE void MTL::CommandBuffer::pushDebugGroup(const NS::String* string) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(pushDebugGroup_), string);
}

_MTL_INLINE MTL::RenderCommandEncoder* MTL::CommandBuffer::renderCommandEncoder(
    const RenderPassDescriptor* renderPassDescriptor) const
{
    return sendMessage<RenderCommandEncoder*>(
        this, _MTL_PRIVATE_SEL(renderCommandEncoderWithDescriptor_), renderPassDescriptor);
}

_MTL_INLINE MTL::ResourceStateCommandEncoder* MTL::CommandBuffer::resourceStateCommandEncoder() const
{
    return sendMessage<ResourceStateCommandEncoder*>(this, _MTL_PRIVATE_SEL(resourceStateCommandEncoder));
}

_MTL_INLINE MTL::ResourceStateCommandEncoder* MTL::CommandBuffer::resourceStateCommandEncoder(
    const ResourceStatePassDescriptor* resourceStatePassDescriptor) const
{
    return sendMessage<ResourceStateCommandEncoder*>(
        this, _MTL_PRIVATE_SEL(resourceStateCommandEncoderWithDescriptor_), resourceStatePassDescriptor);
}

_MTL_INLINE bool MTL::CommandBuffer::retainedReferences() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(retainedReferences));
}

_MTL_INLINE void MTL::CommandBuffer::setLabel(const NS::String* label) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLabel_), label);
}

_MTL_INLINE MTL::CommandBufferStatus MTL::CommandBuffer::status() const
{
    return sendMessage<CommandBufferStatus>(this, _MTL_PRIVATE_SEL(status));
}

_MTL_INLINE void MTL::CommandBuffer::useResidencySet(const ResidencySet* residencySet) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(useResidencySet_), residencySet);
}

_MTL_INLINE void MTL::CommandBuffer::useResidencySets(const ResidencySet* const residencySets[],
                                                      const NS::UInteger        count) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(useResidencySets_count_), residencySets, count);
}

_MTL_INLINE void MTL::CommandBuffer::waitUntilCompleted() const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(waitUntilCompleted));
}

_MTL_INLINE void MTL::CommandBuffer::waitUntilScheduled() const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(waitUntilScheduled));
}
