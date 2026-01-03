//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLParallelRenderCommandEncoder.hpp
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
#include "MTLRenderPass.hpp"

namespace MTL
{
    class RenderCommandEncoder;

    /// @see https://developer.apple.com/documentation/metal/mtlparallelrendercommandencoder?language=objc
    class ParallelRenderCommandEncoder : public NS::Referencing<ParallelRenderCommandEncoder, CommandEncoder>
    {
    public:
        [[nodiscard]] RenderCommandEncoder* renderCommandEncoder() const;

        void setColorStoreAction(StoreAction storeAction, NS::UInteger colorAttachmentIndex) const;
        void setColorStoreActionOptions(StoreActionOptions storeActionOptions, NS::UInteger colorAttachmentIndex) const;

        void setDepthStoreAction(StoreAction storeAction) const;
        void setDepthStoreActionOptions(StoreActionOptions storeActionOptions) const;

        void setStencilStoreAction(StoreAction storeAction) const;
        void setStencilStoreActionOptions(StoreActionOptions storeActionOptions) const;
    };

} // namespace MTL
_MTL_INLINE MTL::RenderCommandEncoder* MTL::ParallelRenderCommandEncoder::renderCommandEncoder() const
{
    return sendMessage<RenderCommandEncoder*>(this, _MTL_PRIVATE_SEL(renderCommandEncoder));
}

_MTL_INLINE void MTL::ParallelRenderCommandEncoder::setColorStoreAction(const StoreAction  storeAction,
                                                                        const NS::UInteger colorAttachmentIndex) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setColorStoreAction_atIndex_), storeAction, colorAttachmentIndex);
}

_MTL_INLINE void MTL::ParallelRenderCommandEncoder::setColorStoreActionOptions(
    const StoreActionOptions storeActionOptions, const NS::UInteger colorAttachmentIndex) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setColorStoreActionOptions_atIndex_), storeActionOptions, colorAttachmentIndex);
}

_MTL_INLINE void MTL::ParallelRenderCommandEncoder::setDepthStoreAction(const StoreAction storeAction) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDepthStoreAction_), storeAction);
}

_MTL_INLINE void MTL::ParallelRenderCommandEncoder::setDepthStoreActionOptions(
    const StoreActionOptions storeActionOptions) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDepthStoreActionOptions_), storeActionOptions);
}

_MTL_INLINE void MTL::ParallelRenderCommandEncoder::setStencilStoreAction(const StoreAction storeAction) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setStencilStoreAction_), storeAction);
}

_MTL_INLINE void MTL::ParallelRenderCommandEncoder::setStencilStoreActionOptions(
    const StoreActionOptions storeActionOptions) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setStencilStoreActionOptions_), storeActionOptions);
}
