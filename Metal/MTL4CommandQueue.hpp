//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTL4CommandQueue.hpp
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
#include <dispatch/dispatch.h>
#include "../Foundation/Foundation.hpp"
#include "MTL4CommitFeedback.hpp"
#include "MTLDefines.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"
#include "MTLResourceStateCommandEncoder.hpp"
#include "MTLTypes.hpp"

namespace MTL
{
    class Buffer;
    class Device;
    class Drawable;
    class Event;
    class Heap;
    class ResidencySet;
    class Texture;
} // namespace MTL

namespace MTL4
{
    class CommandBuffer;
    class CommandQueueDescriptor;
    class CommitOptions;
    struct CopySparseBufferMappingOperation;
    struct CopySparseTextureMappingOperation;
    struct UpdateSparseBufferMappingOperation;
    struct UpdateSparseTextureMappingOperation;
    _MTL_ENUM(NS::Integer, CommandQueueError){
        CommandQueueErrorNone = 0,        CommandQueueErrorTimeout = 1,       CommandQueueErrorNotPermitted = 2,
        CommandQueueErrorOutOfMemory = 3, CommandQueueErrorDeviceRemoved = 4, CommandQueueErrorAccessRevoked = 5,
        CommandQueueErrorInternal = 6,
    };

    /// @see https://developer.apple.com/documentation/metal/mtl4updatesparsetexturemappingoperation
    struct UpdateSparseTextureMappingOperation
    {
        MTL::SparseTextureMappingMode mode;
        MTL::Region                   textureRegion;
        NS::UInteger                  textureLevel;
        NS::UInteger                  textureSlice;
        NS::UInteger                  heapOffset;
    } _MTL_PACKED;

    /// @see https://developer.apple.com/documentation/metal/mtl4copysparsetexturemappingoperation
    struct CopySparseTextureMappingOperation
    {
        MTL::Region  sourceRegion;
        NS::UInteger sourceLevel;
        NS::UInteger sourceSlice;
        MTL::Origin  destinationOrigin;
        NS::UInteger destinationLevel;
        NS::UInteger destinationSlice;
    } _MTL_PACKED;

    /// @see https://developer.apple.com/documentation/metal/mtl4updatesparsebuffermappingoperation
    struct UpdateSparseBufferMappingOperation
    {
        MTL::SparseTextureMappingMode mode;
        NS::Range                     bufferRange;
        NS::UInteger                  heapOffset;
    } _MTL_PACKED;

    /// @see https://developer.apple.com/documentation/metal/mtl4copysparsebuffermappingoperation
    struct CopySparseBufferMappingOperation
    {
        NS::Range    sourceRange;
        NS::UInteger destinationOffset;
    } _MTL_PACKED;

    /// @see https://developer.apple.com/documentation/metal/mtl4commitoptions
    class CommitOptions : public NS::Referencing<CommitOptions>
    {
    public:
        void addFeedbackHandler(CommitFeedbackHandler block);
        void addFeedbackHandler(const CommitFeedbackHandlerFunction& function);

        static CommitOptions* alloc();

        CommitOptions* init();
    };

    /// @see https://developer.apple.com/documentation/metal/mtl4commandqueuedescriptor
    class CommandQueueDescriptor : public NS::Copying<CommandQueueDescriptor>
    {
    public:
        [[nodiscard]] static CommandQueueDescriptor* alloc();

        [[nodiscard]] dispatch_queue_t feedbackQueue() const;

        [[nodiscard]] CommandQueueDescriptor* init();

        [[nodiscard]] NS::String* label() const;

        void setFeedbackQueue(dispatch_queue_t feedbackQueue) const;

        void setLabel(const NS::String* label) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtl4commandqueue
    class CommandQueue : public NS::Referencing<CommandQueue>
    {
    public:
        void addResidencySet(const MTL::ResidencySet* residencySet) const;
        void addResidencySets(const MTL::ResidencySet* const residencySets[], NS::UInteger count) const;

        void commit(const CommandBuffer* const commandBuffers[], NS::UInteger count) const;
        void commit(const CommandBuffer* const commandBuffers[],
                    NS::UInteger               count,
                    const CommitOptions*       options) const;

        void copyBufferMappingsFromBuffer(const MTL::Buffer*                      sourceBuffer,
                                          const MTL::Buffer*                      destinationBuffer,
                                          const CopySparseBufferMappingOperation* operations,
                                          NS::UInteger                            count) const;

        void copyTextureMappingsFromTexture(const MTL::Texture*                      sourceTexture,
                                            const MTL::Texture*                      destinationTexture,
                                            const CopySparseTextureMappingOperation* operations,
                                            NS::UInteger                             count) const;

        [[nodiscard]] MTL::Device* device() const;

        [[nodiscard]] NS::String* label() const;

        void removeResidencySet(const MTL::ResidencySet* residencySet) const;
        void removeResidencySets(const MTL::ResidencySet* const residencySets[], NS::UInteger count) const;

        void signalDrawable(const MTL::Drawable* drawable) const;

        void signalEvent(const MTL::Event* event, uint64_t value) const;

        void updateBufferMappings(const MTL::Buffer*                        buffer,
                                  const MTL::Heap*                          heap,
                                  const UpdateSparseBufferMappingOperation* operations,
                                  NS::UInteger                              count) const;

        void updateTextureMappings(const MTL::Texture*                        texture,
                                   const MTL::Heap*                           heap,
                                   const UpdateSparseTextureMappingOperation* operations,
                                   NS::UInteger                               count) const;

        void wait(const MTL::Event* event, uint64_t value) const;
        void wait(const MTL::Drawable* drawable) const;
    };

} // namespace MTL4

_MTL_INLINE void MTL4::CommitOptions::addFeedbackHandler(const CommitFeedbackHandler block)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(addFeedbackHandler_), block);
}

_MTL_INLINE void MTL4::CommitOptions::addFeedbackHandler(const CommitFeedbackHandlerFunction& function)
{
    __block CommitFeedbackHandlerFunction blockFunction = function;
    addFeedbackHandler(^(CommitFeedback* pFeedback) {
      blockFunction(pFeedback);
    });
}

_MTL_INLINE MTL4::CommitOptions* MTL4::CommitOptions::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<CommitOptions>(_MTL_PRIVATE_CLS(MTL4CommitOptions));
}

_MTL_INLINE MTL4::CommitOptions* MTL4::CommitOptions::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<CommitOptions>();
}

_MTL_INLINE MTL4::CommandQueueDescriptor* MTL4::CommandQueueDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<CommandQueueDescriptor>(_MTL_PRIVATE_CLS(MTL4CommandQueueDescriptor));
}

_MTL_INLINE dispatch_queue_t MTL4::CommandQueueDescriptor::feedbackQueue() const
{
    return sendMessage<dispatch_queue_t>(this, _MTL_PRIVATE_SEL(feedbackQueue));
}

_MTL_INLINE MTL4::CommandQueueDescriptor* MTL4::CommandQueueDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<CommandQueueDescriptor>();
}

_MTL_INLINE NS::String* MTL4::CommandQueueDescriptor::label() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
}

_MTL_INLINE void MTL4::CommandQueueDescriptor::setFeedbackQueue(const dispatch_queue_t feedbackQueue) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFeedbackQueue_), feedbackQueue);
}

_MTL_INLINE void MTL4::CommandQueueDescriptor::setLabel(const NS::String* label) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLabel_), label);
}

_MTL_INLINE void MTL4::CommandQueue::addResidencySet(const MTL::ResidencySet* residencySet) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(addResidencySet_), residencySet);
}

_MTL_INLINE void MTL4::CommandQueue::addResidencySets(const MTL::ResidencySet* const residencySets[],
                                                      const NS::UInteger             count) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(addResidencySets_count_), residencySets, count);
}

_MTL_INLINE void MTL4::CommandQueue::commit(const CommandBuffer* const commandBuffers[], const NS::UInteger count) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(commit_count_), commandBuffers, count);
}

_MTL_INLINE void MTL4::CommandQueue::commit(const CommandBuffer* const commandBuffers[],
                                            const NS::UInteger         count,
                                            const CommitOptions*       options) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(commit_count_options_), commandBuffers, count, options);
}

_MTL_INLINE void MTL4::CommandQueue::copyBufferMappingsFromBuffer(const MTL::Buffer* sourceBuffer,
                                                                  const MTL::Buffer* destinationBuffer,
                                                                  const CopySparseBufferMappingOperation* operations,
                                                                  const NS::UInteger                      count) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(copyBufferMappingsFromBuffer_toBuffer_operations_count_),
                      sourceBuffer,
                      destinationBuffer,
                      operations,
                      count);
}

_MTL_INLINE void MTL4::CommandQueue::copyTextureMappingsFromTexture(const MTL::Texture* sourceTexture,
                                                                    const MTL::Texture* destinationTexture,
                                                                    const CopySparseTextureMappingOperation* operations,
                                                                    const NS::UInteger count) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(copyTextureMappingsFromTexture_toTexture_operations_count_),
                      sourceTexture,
                      destinationTexture,
                      operations,
                      count);
}

_MTL_INLINE MTL::Device* MTL4::CommandQueue::device() const
{
    return sendMessage<MTL::Device*>(this, _MTL_PRIVATE_SEL(device));
}

_MTL_INLINE NS::String* MTL4::CommandQueue::label() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
}

_MTL_INLINE void MTL4::CommandQueue::removeResidencySet(const MTL::ResidencySet* residencySet) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(removeResidencySet_), residencySet);
}

_MTL_INLINE void MTL4::CommandQueue::removeResidencySets(const MTL::ResidencySet* const residencySets[],
                                                         const NS::UInteger             count) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(removeResidencySets_count_), residencySets, count);
}

_MTL_INLINE void MTL4::CommandQueue::signalDrawable(const MTL::Drawable* drawable) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(signalDrawable_), drawable);
}

_MTL_INLINE void MTL4::CommandQueue::signalEvent(const MTL::Event* event, const uint64_t value) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(signalEvent_value_), event, value);
}

_MTL_INLINE void MTL4::CommandQueue::updateBufferMappings(const MTL::Buffer*                        buffer,
                                                          const MTL::Heap*                          heap,
                                                          const UpdateSparseBufferMappingOperation* operations,
                                                          const NS::UInteger                        count) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(updateBufferMappings_heap_operations_count_), buffer, heap, operations, count);
}

_MTL_INLINE void MTL4::CommandQueue::updateTextureMappings(const MTL::Texture*                        texture,
                                                           const MTL::Heap*                           heap,
                                                           const UpdateSparseTextureMappingOperation* operations,
                                                           const NS::UInteger                         count) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(updateTextureMappings_heap_operations_count_), texture, heap, operations, count);
}

_MTL_INLINE void MTL4::CommandQueue::wait(const MTL::Event* event, const uint64_t value) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(waitForEvent_value_), event, value);
}

_MTL_INLINE void MTL4::CommandQueue::wait(const MTL::Drawable* drawable) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(waitForDrawable_), drawable);
}
