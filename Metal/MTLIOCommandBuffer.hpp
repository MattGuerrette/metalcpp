//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLIOCommandBuffer.hpp
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
#include "MTLDefines.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"
#include "MTLTypes.hpp"

namespace MTL
{
    class Buffer;
    class IOCommandBuffer;
    class IOFileHandle;
    class SharedEvent;
    class Texture;

    /// @see https://developer.apple.com/documentation/metal/mtliostatus?language=objc
    _MTL_ENUM(NS::Integer, IOStatus){
        IOStatusPending   = 0,
        IOStatusCancelled = 1,
        IOStatusError     = 2,
        IOStatusComplete  = 3,
    };

    using IOCommandBufferHandler         = void (^)(MTL::IOCommandBuffer*);
    using IOCommandBufferHandlerFunction = std::function<void(IOCommandBuffer*)>;

    /// @see https://developer.apple.com/documentation/metal/mtliocommandbuffer?language=objc
    class IOCommandBuffer : public NS::Referencing<IOCommandBuffer>
    {
    public:
        void addBarrier() const;

        void addCompletedHandler(IOCommandBufferHandler block);
        void addCompletedHandler(const IOCommandBufferHandlerFunction& function);

        void commit() const;

        void copyStatusToBuffer(const Buffer* buffer, NS::UInteger offset) const;

        void enqueue() const;

        [[nodiscard]] NS::Error* error() const;

        [[nodiscard]] NS::String* label() const;

        void loadBuffer(const Buffer*       buffer,
                        NS::UInteger        offset,
                        NS::UInteger        size,
                        const IOFileHandle* sourceHandle,
                        NS::UInteger        sourceHandleOffset) const;

        void loadBytes(const void*         pointer,
                       NS::UInteger        size,
                       const IOFileHandle* sourceHandle,
                       NS::UInteger        sourceHandleOffset) const;

        void loadTexture(const Texture*      texture,
                         NS::UInteger        slice,
                         NS::UInteger        level,
                         const Size&         size,
                         NS::UInteger        sourceBytesPerRow,
                         NS::UInteger        sourceBytesPerImage,
                         const Origin&       destinationOrigin,
                         const IOFileHandle* sourceHandle,
                         NS::UInteger        sourceHandleOffset) const;

        void popDebugGroup() const;

        void pushDebugGroup(const NS::String* string) const;

        void setLabel(const NS::String* label) const;

        void signalEvent(const SharedEvent* event, uint64_t value) const;

        [[nodiscard]] IOStatus status() const;

        void tryCancel() const;

        void wait(const SharedEvent* event, uint64_t value) const;
        void waitUntilCompleted() const;
    };

} // namespace MTL
_MTL_INLINE void MTL::IOCommandBuffer::addBarrier() const { sendMessage<void>(this, _MTL_PRIVATE_SEL(addBarrier)); }

_MTL_INLINE void MTL::IOCommandBuffer::addCompletedHandler(const IOCommandBufferHandler block)
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(addCompletedHandler_), block);
}

_MTL_INLINE void MTL::IOCommandBuffer::addCompletedHandler(const IOCommandBufferHandlerFunction& function)
{
    __block IOCommandBufferHandlerFunction blockFunction = function;
    addCompletedHandler(^(IOCommandBuffer* pCommandBuffer) {
      blockFunction(pCommandBuffer);
    });
}

_MTL_INLINE void MTL::IOCommandBuffer::commit() const { sendMessage<void>(this, _MTL_PRIVATE_SEL(commit)); }

_MTL_INLINE void MTL::IOCommandBuffer::copyStatusToBuffer(const Buffer* buffer, const NS::UInteger offset) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(copyStatusToBuffer_offset_), buffer, offset);
}

_MTL_INLINE void MTL::IOCommandBuffer::enqueue() const { sendMessage<void>(this, _MTL_PRIVATE_SEL(enqueue)); }

_MTL_INLINE NS::Error* MTL::IOCommandBuffer::error() const
{
    return sendMessage<NS::Error*>(this, _MTL_PRIVATE_SEL(error));
}

_MTL_INLINE NS::String* MTL::IOCommandBuffer::label() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
}

_MTL_INLINE void MTL::IOCommandBuffer::loadBuffer(const Buffer*       buffer,
                                                  const NS::UInteger  offset,
                                                  const NS::UInteger  size,
                                                  const IOFileHandle* sourceHandle,
                                                  const NS::UInteger  sourceHandleOffset) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(loadBuffer_offset_size_sourceHandle_sourceHandleOffset_),
                      buffer,
                      offset,
                      size,
                      sourceHandle,
                      sourceHandleOffset);
}

_MTL_INLINE void MTL::IOCommandBuffer::loadBytes(const void*         pointer,
                                                 const NS::UInteger  size,
                                                 const IOFileHandle* sourceHandle,
                                                 const NS::UInteger  sourceHandleOffset) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(loadBytes_size_sourceHandle_sourceHandleOffset_),
                      pointer,
                      size,
                      sourceHandle,
                      sourceHandleOffset);
}

_MTL_INLINE void MTL::IOCommandBuffer::loadTexture(const Texture*      texture,
                                                   const NS::UInteger  slice,
                                                   const NS::UInteger  level,
                                                   const Size&         size,
                                                   const NS::UInteger  sourceBytesPerRow,
                                                   const NS::UInteger  sourceBytesPerImage,
                                                   const Origin&       destinationOrigin,
                                                   const IOFileHandle* sourceHandle,
                                                   const NS::UInteger  sourceHandleOffset) const
{
    sendMessage<void>(
        this,
        _MTL_PRIVATE_SEL(
            loadTexture_slice_level_size_sourceBytesPerRow_sourceBytesPerImage_destinationOrigin_sourceHandle_sourceHandleOffset_),
        texture,
        slice,
        level,
        size,
        sourceBytesPerRow,
        sourceBytesPerImage,
        destinationOrigin,
        sourceHandle,
        sourceHandleOffset);
}

_MTL_INLINE void MTL::IOCommandBuffer::popDebugGroup() const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(popDebugGroup));
}

_MTL_INLINE void MTL::IOCommandBuffer::pushDebugGroup(const NS::String* string) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(pushDebugGroup_), string);
}

_MTL_INLINE void MTL::IOCommandBuffer::setLabel(const NS::String* label) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLabel_), label);
}

_MTL_INLINE void MTL::IOCommandBuffer::signalEvent(const SharedEvent* event, const uint64_t value) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(signalEvent_value_), event, value);
}

_MTL_INLINE MTL::IOStatus MTL::IOCommandBuffer::status() const
{
    return sendMessage<IOStatus>(this, _MTL_PRIVATE_SEL(status));
}

_MTL_INLINE void MTL::IOCommandBuffer::tryCancel() const { sendMessage<void>(this, _MTL_PRIVATE_SEL(tryCancel)); }

_MTL_INLINE void MTL::IOCommandBuffer::wait(const SharedEvent* event, const uint64_t value) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(waitForEvent_value_), event, value);
}

_MTL_INLINE void MTL::IOCommandBuffer::waitUntilCompleted() const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(waitUntilCompleted));
}
