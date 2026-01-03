//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTL4PipelineState.hpp
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
#include "MTLPipeline.hpp"
#include "MTLPrivate.hpp"

namespace MTL4
{
    class PipelineDescriptor;
    class PipelineOptions;
    _MTL_ENUM(NS::Integer, AlphaToOneState){
        AlphaToOneStateDisabled = 0,
        AlphaToOneStateEnabled  = 1,
    };

    _MTL_ENUM(NS::Integer, AlphaToCoverageState){
        AlphaToCoverageStateDisabled = 0,
        AlphaToCoverageStateEnabled  = 1,
    };

    _MTL_ENUM(NS::Integer, BlendState){
        BlendStateDisabled      = 0,
        BlendStateEnabled       = 1,
        BlendStateUnspecialized = 2,
    };

    _MTL_ENUM(NS::Integer, IndirectCommandBufferSupportState){
        IndirectCommandBufferSupportStateDisabled = 0,
        IndirectCommandBufferSupportStateEnabled  = 1,
    };

    _MTL_OPTIONS(NS::UInteger, ShaderReflection){
        ShaderReflectionNone           = 0,
        ShaderReflectionBindingInfo    = 1,
        ShaderReflectionBufferTypeInfo = 1 << 1,
    };

    /// @see https://developer.apple.com/documentation/metal/mtl4pipelineoptions
    class PipelineOptions : public NS::Copying<PipelineOptions>
    {
    public:
        [[nodiscard]] static PipelineOptions* alloc();

        [[nodiscard]] PipelineOptions* init();

        [[nodiscard]] ShaderReflection shaderReflection() const;

        [[nodiscard]] MTL::ShaderValidation shaderValidation() const;

        void setShaderReflection(ShaderReflection shaderReflection) const;

        void setShaderValidation(MTL::ShaderValidation shaderValidation) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtl4pipelinedescriptor
    class PipelineDescriptor : public NS::Copying<PipelineDescriptor>
    {
    public:
        [[nodiscard]] static PipelineDescriptor* alloc();

        [[nodiscard]] PipelineDescriptor* init();

        [[nodiscard]] NS::String* label() const;

        [[nodiscard]] PipelineOptions* options() const;

        void setLabel(const NS::String* label) const;

        void setOptions(const PipelineOptions* options) const;
    };

} // namespace MTL4
_MTL_INLINE MTL4::PipelineOptions* MTL4::PipelineOptions::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<PipelineOptions>(_MTL_PRIVATE_CLS(MTL4PipelineOptions));
}

_MTL_INLINE MTL4::PipelineOptions* MTL4::PipelineOptions::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<PipelineOptions>();
}

_MTL_INLINE void MTL4::PipelineOptions::setShaderReflection(const ShaderReflection shaderReflection) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setShaderReflection_), shaderReflection);
}

_MTL_INLINE void MTL4::PipelineOptions::setShaderValidation(const MTL::ShaderValidation shaderValidation) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setShaderValidation_), shaderValidation);
}

_MTL_INLINE MTL4::ShaderReflection MTL4::PipelineOptions::shaderReflection() const
{
    return sendMessage<ShaderReflection>(this, _MTL_PRIVATE_SEL(shaderReflection));
}

_MTL_INLINE MTL::ShaderValidation MTL4::PipelineOptions::shaderValidation() const
{
    return sendMessage<MTL::ShaderValidation>(this, _MTL_PRIVATE_SEL(shaderValidation));
}

_MTL_INLINE MTL4::PipelineDescriptor* MTL4::PipelineDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<PipelineDescriptor>(_MTL_PRIVATE_CLS(MTL4PipelineDescriptor));
}

_MTL_INLINE MTL4::PipelineDescriptor* MTL4::PipelineDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<PipelineDescriptor>();
}

_MTL_INLINE NS::String* MTL4::PipelineDescriptor::label() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
}

_MTL_INLINE MTL4::PipelineOptions* MTL4::PipelineDescriptor::options() const
{
    return sendMessage<PipelineOptions*>(this, _MTL_PRIVATE_SEL(options));
}

_MTL_INLINE void MTL4::PipelineDescriptor::setLabel(const NS::String* label) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLabel_), label);
}

_MTL_INLINE void MTL4::PipelineDescriptor::setOptions(const PipelineOptions* options) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setOptions_), options);
}
