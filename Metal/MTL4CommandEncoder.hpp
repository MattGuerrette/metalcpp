//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTL4CommandEncoder.hpp
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
#include "MTLCommandEncoder.hpp"
#include "MTLDefines.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"

namespace MTL4
{
    class CommandBuffer;
}

namespace MTL
{
    class Fence;
}

namespace MTL4
{
    _MTL_OPTIONS(NS::UInteger, VisibilityOptions){
        VisibilityOptionNone          = 0,
        VisibilityOptionDevice        = 1,
        VisibilityOptionResourceAlias = 1 << 1,
    };

    /// @see https://developer.apple.com/documentation/metal/mtl4commandencoder
    class CommandEncoder : public NS::Referencing<CommandEncoder>
    {
    public:
        void barrierAfterEncoderStages(MTL::Stages       afterEncoderStages,
                                       MTL::Stages       beforeEncoderStages,
                                       VisibilityOptions visibilityOptions) const;

        void barrierAfterQueueStages(MTL::Stages       afterQueueStages,
                                     MTL::Stages       beforeStages,
                                     VisibilityOptions visibilityOptions) const;

        void barrierAfterStages(MTL::Stages       afterStages,
                                MTL::Stages       beforeQueueStages,
                                VisibilityOptions visibilityOptions) const;

        [[nodiscard]] CommandBuffer* commandBuffer() const;

        void endEncoding() const;

        void insertDebugSignpost(const NS::String* string) const;

        [[nodiscard]] NS::String* label() const;

        void popDebugGroup() const;

        void pushDebugGroup(const NS::String* string) const;

        void setLabel(const NS::String* label) const;

        void updateFence(const MTL::Fence* fence, MTL::Stages afterEncoderStages) const;

        void waitForFence(const MTL::Fence* fence, MTL::Stages beforeEncoderStages) const;
    };

} // namespace MTL4
_MTL_INLINE void MTL4::CommandEncoder::barrierAfterEncoderStages(const MTL::Stages       afterEncoderStages,
                                                                 const MTL::Stages       beforeEncoderStages,
                                                                 const VisibilityOptions visibilityOptions) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(barrierAfterEncoderStages_beforeEncoderStages_visibilityOptions_),
                      afterEncoderStages,
                      beforeEncoderStages,
                      visibilityOptions);
}

_MTL_INLINE void MTL4::CommandEncoder::barrierAfterQueueStages(const MTL::Stages       afterQueueStages,
                                                               const MTL::Stages       beforeStages,
                                                               const VisibilityOptions visibilityOptions) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(barrierAfterQueueStages_beforeStages_visibilityOptions_),
                      afterQueueStages,
                      beforeStages,
                      visibilityOptions);
}

_MTL_INLINE void MTL4::CommandEncoder::barrierAfterStages(const MTL::Stages       afterStages,
                                                          const MTL::Stages       beforeQueueStages,
                                                          const VisibilityOptions visibilityOptions) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(barrierAfterStages_beforeQueueStages_visibilityOptions_),
                      afterStages,
                      beforeQueueStages,
                      visibilityOptions);
}

_MTL_INLINE MTL4::CommandBuffer* MTL4::CommandEncoder::commandBuffer() const
{
    return sendMessage<CommandBuffer*>(this, _MTL_PRIVATE_SEL(commandBuffer));
}

_MTL_INLINE void MTL4::CommandEncoder::endEncoding() const { sendMessage<void>(this, _MTL_PRIVATE_SEL(endEncoding)); }

_MTL_INLINE void MTL4::CommandEncoder::insertDebugSignpost(const NS::String* string) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(insertDebugSignpost_), string);
}

_MTL_INLINE NS::String* MTL4::CommandEncoder::label() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
}

_MTL_INLINE void MTL4::CommandEncoder::popDebugGroup() const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(popDebugGroup));
}

_MTL_INLINE void MTL4::CommandEncoder::pushDebugGroup(const NS::String* string) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(pushDebugGroup_), string);
}

_MTL_INLINE void MTL4::CommandEncoder::setLabel(const NS::String* label) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLabel_), label);
}

_MTL_INLINE void MTL4::CommandEncoder::updateFence(const MTL::Fence* fence, const MTL::Stages afterEncoderStages) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(updateFence_afterEncoderStages_), fence, afterEncoderStages);
}

_MTL_INLINE void MTL4::CommandEncoder::waitForFence(const MTL::Fence* fence,
                                                    const MTL::Stages beforeEncoderStages) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(waitForFence_beforeEncoderStages_), fence, beforeEncoderStages);
}
