//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLBinaryArchive.hpp
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
    class BinaryArchiveDescriptor;
    class ComputePipelineDescriptor;
    class Device;
    class FunctionDescriptor;
    class Library;
    class MeshRenderPipelineDescriptor;
    class RenderPipelineDescriptor;
    class StitchedLibraryDescriptor;
    class TileRenderPipelineDescriptor;
    _MTL_ENUM(NS::UInteger, BinaryArchiveError){
        BinaryArchiveErrorNone               = 0,
        BinaryArchiveErrorInvalidFile        = 1,
        BinaryArchiveErrorUnexpectedElement  = 2,
        BinaryArchiveErrorCompilationFailure = 3,
        BinaryArchiveErrorInternalError      = 4,
    };

    _MTL_CONST(NS::ErrorDomain, BinaryArchiveDomain);

    /// @see https://developer.apple.com/documentation/metal/mtlbinaryarchivedescriptor?language=objc
    class BinaryArchiveDescriptor : public NS::Copying<BinaryArchiveDescriptor>
    {
    public:
        [[nodiscard]] static BinaryArchiveDescriptor* alloc();

        [[nodiscard]] BinaryArchiveDescriptor* init();

        [[nodiscard]] NS::URL* url() const;

        void setUrl(const NS::URL* url) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlbinaryarchive?language=objc
    class BinaryArchive : public NS::Referencing<BinaryArchive>
    {
    public:
        [[nodiscard]] bool addComputePipelineFunctions(const ComputePipelineDescriptor* descriptor,
                                                       NS::Error**                      error) const;

        [[nodiscard]] bool addFunction(const FunctionDescriptor* descriptor,
                                       const Library*            library,
                                       NS::Error**               error) const;

        [[nodiscard]] bool addLibrary(const StitchedLibraryDescriptor* descriptor, NS::Error** error) const;

        [[nodiscard]] bool addMeshRenderPipelineFunctions(const MeshRenderPipelineDescriptor* descriptor,
                                                          NS::Error**                         error) const;

        [[nodiscard]] bool addRenderPipelineFunctions(const RenderPipelineDescriptor* descriptor,
                                                      NS::Error**                     error) const;

        [[nodiscard]] bool addTileRenderPipelineFunctions(const TileRenderPipelineDescriptor* descriptor,
                                                          NS::Error**                         error) const;

        [[nodiscard]] Device* device() const;

        [[nodiscard]] NS::String* label() const;

        [[nodiscard]] bool serializeToURL(const NS::URL* url, NS::Error** error) const;

        void setLabel(const NS::String* label) const;
    };

} // namespace MTL
_MTL_PRIVATE_DEF_CONST(NS::ErrorDomain, BinaryArchiveDomain);
_MTL_INLINE MTL::BinaryArchiveDescriptor* MTL::BinaryArchiveDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<BinaryArchiveDescriptor>(_MTL_PRIVATE_CLS(MTLBinaryArchiveDescriptor));
}

_MTL_INLINE MTL::BinaryArchiveDescriptor* MTL::BinaryArchiveDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<BinaryArchiveDescriptor>();
}

_MTL_INLINE void MTL::BinaryArchiveDescriptor::setUrl(const NS::URL* url) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setUrl_), url);
}

_MTL_INLINE NS::URL* MTL::BinaryArchiveDescriptor::url() const
{
    return sendMessage<NS::URL*>(this, _MTL_PRIVATE_SEL(url));
}

_MTL_INLINE bool MTL::BinaryArchive::addComputePipelineFunctions(const ComputePipelineDescriptor* descriptor,
                                                                 NS::Error**                      error) const
{
    return sendMessage<bool>(
        this, _MTL_PRIVATE_SEL(addComputePipelineFunctionsWithDescriptor_error_), descriptor, error);
}

_MTL_INLINE bool MTL::BinaryArchive::addFunction(const FunctionDescriptor* descriptor,
                                                 const Library*            library,
                                                 NS::Error**               error) const
{
    return sendMessage<bool>(
        this, _MTL_PRIVATE_SEL(addFunctionWithDescriptor_library_error_), descriptor, library, error);
}

_MTL_INLINE bool MTL::BinaryArchive::addLibrary(const StitchedLibraryDescriptor* descriptor, NS::Error** error) const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(addLibraryWithDescriptor_error_), descriptor, error);
}

_MTL_INLINE bool MTL::BinaryArchive::addMeshRenderPipelineFunctions(const MeshRenderPipelineDescriptor* descriptor,
                                                                    NS::Error**                         error) const
{
    return sendMessage<bool>(
        this, _MTL_PRIVATE_SEL(addMeshRenderPipelineFunctionsWithDescriptor_error_), descriptor, error);
}

_MTL_INLINE bool MTL::BinaryArchive::addRenderPipelineFunctions(const RenderPipelineDescriptor* descriptor,
                                                                NS::Error**                     error) const
{
    return sendMessage<bool>(
        this, _MTL_PRIVATE_SEL(addRenderPipelineFunctionsWithDescriptor_error_), descriptor, error);
}

_MTL_INLINE bool MTL::BinaryArchive::addTileRenderPipelineFunctions(const TileRenderPipelineDescriptor* descriptor,
                                                                    NS::Error**                         error) const
{
    return sendMessage<bool>(
        this, _MTL_PRIVATE_SEL(addTileRenderPipelineFunctionsWithDescriptor_error_), descriptor, error);
}

_MTL_INLINE MTL::Device* MTL::BinaryArchive::device() const
{
    return sendMessage<Device*>(this, _MTL_PRIVATE_SEL(device));
}

_MTL_INLINE NS::String* MTL::BinaryArchive::label() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
}

_MTL_INLINE bool MTL::BinaryArchive::serializeToURL(const NS::URL* url, NS::Error** error) const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(serializeToURL_error_), url, error);
}

_MTL_INLINE void MTL::BinaryArchive::setLabel(const NS::String* label) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLabel_), label);
}
