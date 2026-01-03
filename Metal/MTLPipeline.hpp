//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLPipeline.hpp
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

namespace MTL
{
    class PipelineBufferDescriptor;
    class PipelineBufferDescriptorArray;

    /// @see https://developer.apple.com/documentation/metal/mtlmutability?language=objc
    _MTL_ENUM(NS::UInteger, Mutability){
        MutabilityDefault   = 0,
        MutabilityMutable   = 1,
        MutabilityImmutable = 2,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlshadervalidation?language=objc
    _MTL_ENUM(NS::Integer, ShaderValidation){
        ShaderValidationDefault  = 0,
        ShaderValidationEnabled  = 1,
        ShaderValidationDisabled = 2,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlpipelinebufferdescriptor?language=objc
    class PipelineBufferDescriptor : public NS::Copying<PipelineBufferDescriptor>
    {
    public:
        [[nodiscard]] static PipelineBufferDescriptor* alloc();

        [[nodiscard]] PipelineBufferDescriptor* init();

        [[nodiscard]] Mutability mutability() const;
        void                     setMutability(Mutability mutability) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlpipelinebufferdescriptorarray?language=objc
    class PipelineBufferDescriptorArray : public NS::Referencing<PipelineBufferDescriptorArray>
    {
    public:
        [[nodiscard]] static PipelineBufferDescriptorArray* alloc();

        [[nodiscard]] PipelineBufferDescriptorArray* init();

        [[nodiscard]] PipelineBufferDescriptor* object(NS::UInteger bufferIndex) const;
        void setObject(const PipelineBufferDescriptor* buffer, NS::UInteger bufferIndex) const;
    };

} // namespace MTL
_MTL_INLINE MTL::PipelineBufferDescriptor* MTL::PipelineBufferDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<PipelineBufferDescriptor>(_MTL_PRIVATE_CLS(MTLPipelineBufferDescriptor));
}

_MTL_INLINE MTL::PipelineBufferDescriptor* MTL::PipelineBufferDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<PipelineBufferDescriptor>();
}

_MTL_INLINE MTL::Mutability MTL::PipelineBufferDescriptor::mutability() const
{
    return sendMessage<Mutability>(this, _MTL_PRIVATE_SEL(mutability));
}

_MTL_INLINE void MTL::PipelineBufferDescriptor::setMutability(const Mutability mutability) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMutability_), mutability);
}

_MTL_INLINE MTL::PipelineBufferDescriptorArray* MTL::PipelineBufferDescriptorArray::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<PipelineBufferDescriptorArray>(_MTL_PRIVATE_CLS(MTLPipelineBufferDescriptorArray));
}

_MTL_INLINE MTL::PipelineBufferDescriptorArray* MTL::PipelineBufferDescriptorArray::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<PipelineBufferDescriptorArray>();
}

_MTL_INLINE MTL::PipelineBufferDescriptor* MTL::PipelineBufferDescriptorArray::object(
    const NS::UInteger bufferIndex) const
{
    return sendMessage<PipelineBufferDescriptor*>(this, _MTL_PRIVATE_SEL(objectAtIndexedSubscript_), bufferIndex);
}

_MTL_INLINE void MTL::PipelineBufferDescriptorArray::setObject(const PipelineBufferDescriptor* buffer,
                                                               const NS::UInteger              bufferIndex) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setObject_atIndexedSubscript_), buffer, bufferIndex);
}
