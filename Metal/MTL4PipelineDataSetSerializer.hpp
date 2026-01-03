//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTL4PipelineDataSetSerializer.hpp
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
    class PipelineDataSetSerializerDescriptor;

    _MTL_OPTIONS(NS::UInteger, PipelineDataSetSerializerConfiguration){
        PipelineDataSetSerializerConfigurationCaptureDescriptors = 1,
        PipelineDataSetSerializerConfigurationCaptureBinaries    = 1 << 1,
    };

    /// @see https://developer.apple.com/documentation/metal/mtl4pipelinedatasetserializerdescriptor
    class PipelineDataSetSerializerDescriptor : public NS::Copying<PipelineDataSetSerializerDescriptor>
    {
    public:
        [[nodiscard]] static PipelineDataSetSerializerDescriptor* alloc();

        [[nodiscard]] PipelineDataSetSerializerConfiguration configuration() const;

        [[nodiscard]] PipelineDataSetSerializerDescriptor* init();

        void setConfiguration(PipelineDataSetSerializerConfiguration configuration) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtl4pipelinedatasetserializer
    class PipelineDataSetSerializer : public NS::Referencing<PipelineDataSetSerializer>
    {
    public:
        [[nodiscard]] bool serializeAsArchiveAndFlushToURL(const NS::URL* url, NS::Error** error) const;

        [[nodiscard]] NS::Data* serializeAsPipelinesScript(NS::Error** error) const;
    };

} // namespace MTL4
_MTL_INLINE MTL4::PipelineDataSetSerializerDescriptor* MTL4::PipelineDataSetSerializerDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<PipelineDataSetSerializerDescriptor>(
        _MTL_PRIVATE_CLS(MTL4PipelineDataSetSerializerDescriptor));
}

_MTL_INLINE MTL4::PipelineDataSetSerializerConfiguration MTL4::PipelineDataSetSerializerDescriptor::configuration()
    const
{
    return sendMessage<PipelineDataSetSerializerConfiguration>(this, _MTL_PRIVATE_SEL(configuration));
}

_MTL_INLINE MTL4::PipelineDataSetSerializerDescriptor* MTL4::PipelineDataSetSerializerDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<PipelineDataSetSerializerDescriptor>();
}

_MTL_INLINE void MTL4::PipelineDataSetSerializerDescriptor::setConfiguration(
    const PipelineDataSetSerializerConfiguration configuration) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setConfiguration_), configuration);
}

_MTL_INLINE bool MTL4::PipelineDataSetSerializer::serializeAsArchiveAndFlushToURL(const NS::URL* url,
                                                                                  NS::Error**    error) const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(serializeAsArchiveAndFlushToURL_error_), url, error);
}

_MTL_INLINE NS::Data* MTL4::PipelineDataSetSerializer::serializeAsPipelinesScript(NS::Error** error) const
{
    return sendMessage<NS::Data*>(this, _MTL_PRIVATE_SEL(serializeAsPipelinesScriptWithError_), error);
}
