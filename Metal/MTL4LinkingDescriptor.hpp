//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTL4LinkingDescriptor.hpp
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
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"

namespace MTL4
{
    class PipelineStageDynamicLinkingDescriptor;
    class RenderPipelineDynamicLinkingDescriptor;
    class StaticLinkingDescriptor;

    /// @see https://developer.apple.com/documentation/metal/mtl4staticlinkingdescriptor
    class StaticLinkingDescriptor : public NS::Copying<StaticLinkingDescriptor>
    {
    public:
        [[nodiscard]] static StaticLinkingDescriptor* alloc();

        [[nodiscard]] NS::Array* functionDescriptors() const;

        [[nodiscard]] NS::Dictionary* groups() const;

        [[nodiscard]] StaticLinkingDescriptor* init();

        [[nodiscard]] NS::Array* privateFunctionDescriptors() const;

        void setFunctionDescriptors(const NS::Array* functionDescriptors) const;

        void setGroups(const NS::Dictionary* groups) const;

        void setPrivateFunctionDescriptors(const NS::Array* privateFunctionDescriptors) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtl4pipelinestagedynamiclinkingdescriptor
    class PipelineStageDynamicLinkingDescriptor : public NS::Copying<PipelineStageDynamicLinkingDescriptor>
    {
    public:
        [[nodiscard]] static PipelineStageDynamicLinkingDescriptor* alloc();

        [[nodiscard]] NS::Array* binaryLinkedFunctions() const;

        [[nodiscard]] PipelineStageDynamicLinkingDescriptor* init();

        [[nodiscard]] NS::UInteger maxCallStackDepth() const;

        [[nodiscard]] NS::Array* preloadedLibraries() const;

        void setBinaryLinkedFunctions(const NS::Array* binaryLinkedFunctions) const;

        void setMaxCallStackDepth(NS::UInteger maxCallStackDepth) const;

        void setPreloadedLibraries(const NS::Array* preloadedLibraries) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtl4renderpipelinedynamiclinkingdescriptor
    class RenderPipelineDynamicLinkingDescriptor : public NS::Copying<RenderPipelineDynamicLinkingDescriptor>
    {
    public:
        [[nodiscard]] static RenderPipelineDynamicLinkingDescriptor* alloc();

        [[nodiscard]] PipelineStageDynamicLinkingDescriptor* fragmentLinkingDescriptor() const;

        [[nodiscard]] RenderPipelineDynamicLinkingDescriptor* init();

        [[nodiscard]] PipelineStageDynamicLinkingDescriptor* meshLinkingDescriptor() const;

        [[nodiscard]] PipelineStageDynamicLinkingDescriptor* objectLinkingDescriptor() const;

        [[nodiscard]] PipelineStageDynamicLinkingDescriptor* tileLinkingDescriptor() const;

        [[nodiscard]] PipelineStageDynamicLinkingDescriptor* vertexLinkingDescriptor() const;
    };

} // namespace MTL4
_MTL_INLINE MTL4::StaticLinkingDescriptor* MTL4::StaticLinkingDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<StaticLinkingDescriptor>(_MTL_PRIVATE_CLS(MTL4StaticLinkingDescriptor));
}

_MTL_INLINE NS::Array* MTL4::StaticLinkingDescriptor::functionDescriptors() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(functionDescriptors));
}

_MTL_INLINE NS::Dictionary* MTL4::StaticLinkingDescriptor::groups() const
{
    return sendMessage<NS::Dictionary*>(this, _MTL_PRIVATE_SEL(groups));
}

_MTL_INLINE MTL4::StaticLinkingDescriptor* MTL4::StaticLinkingDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<StaticLinkingDescriptor>();
}

_MTL_INLINE NS::Array* MTL4::StaticLinkingDescriptor::privateFunctionDescriptors() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(privateFunctionDescriptors));
}

_MTL_INLINE void MTL4::StaticLinkingDescriptor::setFunctionDescriptors(const NS::Array* functionDescriptors) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFunctionDescriptors_), functionDescriptors);
}

_MTL_INLINE void MTL4::StaticLinkingDescriptor::setGroups(const NS::Dictionary* groups) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setGroups_), groups);
}

_MTL_INLINE void MTL4::StaticLinkingDescriptor::setPrivateFunctionDescriptors(
    const NS::Array* privateFunctionDescriptors) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setPrivateFunctionDescriptors_), privateFunctionDescriptors);
}

_MTL_INLINE MTL4::PipelineStageDynamicLinkingDescriptor* MTL4::PipelineStageDynamicLinkingDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<PipelineStageDynamicLinkingDescriptor>(
        _MTL_PRIVATE_CLS(MTL4PipelineStageDynamicLinkingDescriptor));
}

_MTL_INLINE NS::Array* MTL4::PipelineStageDynamicLinkingDescriptor::binaryLinkedFunctions() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(binaryLinkedFunctions));
}

_MTL_INLINE MTL4::PipelineStageDynamicLinkingDescriptor* MTL4::PipelineStageDynamicLinkingDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<PipelineStageDynamicLinkingDescriptor>();
}

_MTL_INLINE NS::UInteger MTL4::PipelineStageDynamicLinkingDescriptor::maxCallStackDepth() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxCallStackDepth));
}

_MTL_INLINE NS::Array* MTL4::PipelineStageDynamicLinkingDescriptor::preloadedLibraries() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(preloadedLibraries));
}

_MTL_INLINE void MTL4::PipelineStageDynamicLinkingDescriptor::setBinaryLinkedFunctions(
    const NS::Array* binaryLinkedFunctions) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBinaryLinkedFunctions_), binaryLinkedFunctions);
}

_MTL_INLINE void MTL4::PipelineStageDynamicLinkingDescriptor::setMaxCallStackDepth(NS::UInteger maxCallStackDepth) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxCallStackDepth_), maxCallStackDepth);
}

_MTL_INLINE void MTL4::PipelineStageDynamicLinkingDescriptor::setPreloadedLibraries(
    const NS::Array* preloadedLibraries) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setPreloadedLibraries_), preloadedLibraries);
}

_MTL_INLINE MTL4::RenderPipelineDynamicLinkingDescriptor* MTL4::RenderPipelineDynamicLinkingDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<RenderPipelineDynamicLinkingDescriptor>(
        _MTL_PRIVATE_CLS(MTL4RenderPipelineDynamicLinkingDescriptor));
}

_MTL_INLINE MTL4::PipelineStageDynamicLinkingDescriptor*
            MTL4::RenderPipelineDynamicLinkingDescriptor::fragmentLinkingDescriptor() const
{
    return sendMessage<PipelineStageDynamicLinkingDescriptor*>(this, _MTL_PRIVATE_SEL(fragmentLinkingDescriptor));
}

_MTL_INLINE MTL4::RenderPipelineDynamicLinkingDescriptor* MTL4::RenderPipelineDynamicLinkingDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<RenderPipelineDynamicLinkingDescriptor>();
}

_MTL_INLINE MTL4::PipelineStageDynamicLinkingDescriptor*
            MTL4::RenderPipelineDynamicLinkingDescriptor::meshLinkingDescriptor() const
{
    return sendMessage<PipelineStageDynamicLinkingDescriptor*>(this, _MTL_PRIVATE_SEL(meshLinkingDescriptor));
}

_MTL_INLINE MTL4::PipelineStageDynamicLinkingDescriptor*
            MTL4::RenderPipelineDynamicLinkingDescriptor::objectLinkingDescriptor() const
{
    return sendMessage<PipelineStageDynamicLinkingDescriptor*>(this, _MTL_PRIVATE_SEL(objectLinkingDescriptor));
}

_MTL_INLINE MTL4::PipelineStageDynamicLinkingDescriptor*
            MTL4::RenderPipelineDynamicLinkingDescriptor::tileLinkingDescriptor() const
{
    return sendMessage<PipelineStageDynamicLinkingDescriptor*>(this, _MTL_PRIVATE_SEL(tileLinkingDescriptor));
}

_MTL_INLINE MTL4::PipelineStageDynamicLinkingDescriptor*
            MTL4::RenderPipelineDynamicLinkingDescriptor::vertexLinkingDescriptor() const
{
    return sendMessage<PipelineStageDynamicLinkingDescriptor*>(this, _MTL_PRIVATE_SEL(vertexLinkingDescriptor));
}
