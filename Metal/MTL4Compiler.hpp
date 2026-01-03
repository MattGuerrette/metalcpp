//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTL4Compiler.hpp
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
#include "MTLDevice.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"

#include <functional>

namespace MTL4
{
    class BinaryFunction;
    class BinaryFunctionDescriptor;
    class CompilerDescriptor;
    class CompilerTask;
    class CompilerTaskOptions;
    class ComputePipelineDescriptor;
    class LibraryDescriptor;
    class MachineLearningPipelineDescriptor;
    class MachineLearningPipelineState;
    class PipelineDataSetSerializer;
    class PipelineDescriptor;
    class PipelineStageDynamicLinkingDescriptor;
    class RenderPipelineDynamicLinkingDescriptor;
} // namespace MTL4

namespace MTL
{
    class ComputePipelineState;
    class Device;
    class DynamicLibrary;
    class Library;
    class RenderPipelineState;

    using NewDynamicLibraryCompletionHandler         = void (^)(MTL::DynamicLibrary*, NS::Error*);
    using NewDynamicLibraryCompletionHandlerFunction = std::function<void(DynamicLibrary*, NS::Error*)>;
} // namespace MTL

namespace MTL4
{
    using NewComputePipelineStateCompletionHandler = void (^)(MTL::ComputePipelineState*, NS::Error*);
    using NewComputePipelineStateCompletionHandlerFunction =
        std::function<void(MTL::ComputePipelineState*, NS::Error*)>;
    using NewRenderPipelineStateCompletionHandler          = void (^)(MTL::RenderPipelineState*, NS::Error*);
    using NewRenderPipelineStateCompletionHandlerFunction  = std::function<void(MTL::RenderPipelineState*, NS::Error*)>;
    using NewBinaryFunctionCompletionHandler               = void (^)(MTL4::BinaryFunction*, NS::Error*);
    using NewBinaryFunctionCompletionHandlerFunction       = std::function<void(BinaryFunction*, NS::Error*)>;
    using NewMachineLearningPipelineStateCompletionHandler = void (^)(MTL4::MachineLearningPipelineState*, NS::Error*);
    using NewMachineLearningPipelineStateCompletionHandlerFunction =
        std::function<void(MachineLearningPipelineState*, NS::Error*)>;

    /// @see https://developer.apple.com/documentation/metal/mtl4compilerdescriptor
    class CompilerDescriptor : public NS::Copying<CompilerDescriptor>
    {
    public:
        [[nodiscard]] static CompilerDescriptor* alloc();

        [[nodiscard]] CompilerDescriptor* init();

        [[nodiscard]] NS::String* label() const;

        [[nodiscard]] PipelineDataSetSerializer* pipelineDataSetSerializer() const;

        void setLabel(const NS::String* label) const;

        void setPipelineDataSetSerializer(const PipelineDataSetSerializer* pipelineDataSetSerializer) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtl4compilertaskoptions
    class CompilerTaskOptions : public NS::Copying<CompilerTaskOptions>
    {
    public:
        [[nodiscard]] static CompilerTaskOptions* alloc();

        [[nodiscard]] CompilerTaskOptions* init();

        [[nodiscard]] NS::Array* lookupArchives() const;

        void setLookupArchives(const NS::Array* lookupArchives) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtl4compiler
    class Compiler : public NS::Referencing<Compiler>
    {
    public:
        [[nodiscard]] MTL::Device* device() const;

        [[nodiscard]] NS::String* label() const;

        [[nodiscard]] BinaryFunction* newBinaryFunction(const BinaryFunctionDescriptor* descriptor,
                                                        const CompilerTaskOptions*      compilerTaskOptions,
                                                        NS::Error**                     error) const;
        [[nodiscard]] CompilerTask*   newBinaryFunction(const BinaryFunctionDescriptor*    descriptor,
                                                        const CompilerTaskOptions*         compilerTaskOptions,
                                                        NewBinaryFunctionCompletionHandler completionHandler);

        [[nodiscard]] MTL::ComputePipelineState* newComputePipelineState(const ComputePipelineDescriptor* descriptor,
                                                                         const CompilerTaskOptions* compilerTaskOptions,
                                                                         NS::Error**                error) const;
        [[nodiscard]] MTL::ComputePipelineState* newComputePipelineState(
            const ComputePipelineDescriptor*             descriptor,
            const PipelineStageDynamicLinkingDescriptor* dynamicLinkingDescriptor,
            const CompilerTaskOptions*                   compilerTaskOptions,
            NS::Error**                                  error) const;
        [[nodiscard]] CompilerTask* newComputePipelineState(
            const ComputePipelineDescriptor*              descriptor,
            const CompilerTaskOptions*                    compilerTaskOptions,
            MTL::NewComputePipelineStateCompletionHandler completionHandler);
        [[nodiscard]] CompilerTask* newComputePipelineState(
            const ComputePipelineDescriptor*              descriptor,
            const PipelineStageDynamicLinkingDescriptor*  dynamicLinkingDescriptor,
            const CompilerTaskOptions*                    compilerTaskOptions,
            MTL::NewComputePipelineStateCompletionHandler completionHandler);
        [[nodiscard]] CompilerTask* newComputePipelineState(
            const ComputePipelineDescriptor*                        pDescriptor,
            const CompilerTaskOptions*                              options,
            const NewComputePipelineStateCompletionHandlerFunction& function);

        [[nodiscard]] MTL::DynamicLibrary* newDynamicLibrary(const MTL::Library* library, NS::Error** error) const;
        [[nodiscard]] MTL::DynamicLibrary* newDynamicLibrary(const NS::URL* url, NS::Error** error) const;
        [[nodiscard]] CompilerTask*        newDynamicLibrary(const MTL::Library*                     library,
                                                             MTL::NewDynamicLibraryCompletionHandler completionHandler);
        [[nodiscard]] CompilerTask*        newDynamicLibrary(const NS::URL*                          url,
                                                             MTL::NewDynamicLibraryCompletionHandler completionHandler);
        [[nodiscard]] CompilerTask*        newDynamicLibrary(const MTL::Library*                                    pLibrary,
                                                             const MTL::NewDynamicLibraryCompletionHandlerFunction& function);
        [[nodiscard]] CompilerTask*        newDynamicLibrary(const NS::URL*                                         pURL,
                                                             const MTL::NewDynamicLibraryCompletionHandlerFunction& function);

        [[nodiscard]] MTL::Library* newLibrary(const LibraryDescriptor* descriptor, NS::Error** error) const;
        [[nodiscard]] CompilerTask* newLibrary(const LibraryDescriptor*         descriptor,
                                               MTL::NewLibraryCompletionHandler completionHandler);
        [[nodiscard]] CompilerTask* newLibrary(const LibraryDescriptor*                        pDescriptor,
                                               const MTL::NewLibraryCompletionHandlerFunction& function);

        [[nodiscard]] MachineLearningPipelineState* newMachineLearningPipelineState(
            const MachineLearningPipelineDescriptor* descriptor, NS::Error** error) const;
        [[nodiscard]] CompilerTask* newMachineLearningPipelineState(
            const MachineLearningPipelineDescriptor*         descriptor,
            NewMachineLearningPipelineStateCompletionHandler completionHandler);
        [[nodiscard]] CompilerTask* newMachineLearningPipelineState(
            const MachineLearningPipelineDescriptor*                        pDescriptor,
            const NewMachineLearningPipelineStateCompletionHandlerFunction& function);

        [[nodiscard]] MTL::RenderPipelineState* newRenderPipelineState(const PipelineDescriptor*  descriptor,
                                                                       const CompilerTaskOptions* compilerTaskOptions,
                                                                       NS::Error**                error) const;
        [[nodiscard]] MTL::RenderPipelineState* newRenderPipelineState(
            const PipelineDescriptor*                     descriptor,
            const RenderPipelineDynamicLinkingDescriptor* dynamicLinkingDescriptor,
            const CompilerTaskOptions*                    compilerTaskOptions,
            NS::Error**                                   error) const;
        [[nodiscard]] CompilerTask* newRenderPipelineState(
            const PipelineDescriptor*                    descriptor,
            const CompilerTaskOptions*                   compilerTaskOptions,
            MTL::NewRenderPipelineStateCompletionHandler completionHandler);
        [[nodiscard]] CompilerTask* newRenderPipelineState(
            const PipelineDescriptor*                     descriptor,
            const RenderPipelineDynamicLinkingDescriptor* dynamicLinkingDescriptor,
            const CompilerTaskOptions*                    compilerTaskOptions,
            MTL::NewRenderPipelineStateCompletionHandler  completionHandler);
        [[nodiscard]] CompilerTask* newRenderPipelineState(
            const PipelineDescriptor*                              pDescriptor,
            const CompilerTaskOptions*                             options,
            const NewRenderPipelineStateCompletionHandlerFunction& function);
        [[nodiscard]] MTL::RenderPipelineState* newRenderPipelineStateBySpecialization(
            const PipelineDescriptor* descriptor, const MTL::RenderPipelineState* pipeline, NS::Error** error) const;
        [[nodiscard]] CompilerTask* newRenderPipelineStateBySpecialization(
            const PipelineDescriptor*                    descriptor,
            const MTL::RenderPipelineState*              pipeline,
            MTL::NewRenderPipelineStateCompletionHandler completionHandler);
        [[nodiscard]] CompilerTask* newRenderPipelineStateBySpecialization(
            const PipelineDescriptor*                              pDescriptor,
            const MTL::RenderPipelineState*                        pPipeline,
            const NewRenderPipelineStateCompletionHandlerFunction& function);

        [[nodiscard]] PipelineDataSetSerializer* pipelineDataSetSerializer() const;
    };

} // namespace MTL4
_MTL_INLINE MTL4::CompilerDescriptor* MTL4::CompilerDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<CompilerDescriptor>(_MTL_PRIVATE_CLS(MTL4CompilerDescriptor));
}

_MTL_INLINE MTL4::CompilerDescriptor* MTL4::CompilerDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<CompilerDescriptor>();
}

_MTL_INLINE NS::String* MTL4::CompilerDescriptor::label() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
}

_MTL_INLINE MTL4::PipelineDataSetSerializer* MTL4::CompilerDescriptor::pipelineDataSetSerializer() const
{
    return sendMessage<PipelineDataSetSerializer*>(this, _MTL_PRIVATE_SEL(pipelineDataSetSerializer));
}

_MTL_INLINE void MTL4::CompilerDescriptor::setLabel(const NS::String* label) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLabel_), label);
}

_MTL_INLINE void MTL4::CompilerDescriptor::setPipelineDataSetSerializer(
    const PipelineDataSetSerializer* pipelineDataSetSerializer) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setPipelineDataSetSerializer_), pipelineDataSetSerializer);
}

_MTL_INLINE MTL4::CompilerTaskOptions* MTL4::CompilerTaskOptions::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<CompilerTaskOptions>(_MTL_PRIVATE_CLS(MTL4CompilerTaskOptions));
}

_MTL_INLINE MTL4::CompilerTaskOptions* MTL4::CompilerTaskOptions::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<CompilerTaskOptions>();
}

_MTL_INLINE NS::Array* MTL4::CompilerTaskOptions::lookupArchives() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(lookupArchives));
}

_MTL_INLINE void MTL4::CompilerTaskOptions::setLookupArchives(const NS::Array* lookupArchives) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLookupArchives_), lookupArchives);
}

_MTL_INLINE MTL::Device* MTL4::Compiler::device() const
{
    return sendMessage<MTL::Device*>(this, _MTL_PRIVATE_SEL(device));
}

_MTL_INLINE NS::String* MTL4::Compiler::label() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label));
}

_MTL_INLINE MTL4::BinaryFunction* MTL4::Compiler::newBinaryFunction(const BinaryFunctionDescriptor* descriptor,
                                                                    const CompilerTaskOptions*      compilerTaskOptions,
                                                                    NS::Error**                     error) const
{
    return sendMessage<BinaryFunction*>(this,
                                        _MTL_PRIVATE_SEL(newBinaryFunctionWithDescriptor_compilerTaskOptions_error_),
                                        descriptor,
                                        compilerTaskOptions,
                                        error);
}

_MTL_INLINE MTL4::CompilerTask* MTL4::Compiler::newBinaryFunction(
    const BinaryFunctionDescriptor*          descriptor,
    const CompilerTaskOptions*               compilerTaskOptions,
    const NewBinaryFunctionCompletionHandler completionHandler)
{
    return sendMessage<CompilerTask*>(
        this,
        _MTL_PRIVATE_SEL(newBinaryFunctionWithDescriptor_compilerTaskOptions_completionHandler_),
        descriptor,
        compilerTaskOptions,
        completionHandler);
}

_MTL_INLINE MTL::ComputePipelineState* MTL4::Compiler::newComputePipelineState(
    const ComputePipelineDescriptor* descriptor,
    const CompilerTaskOptions*       compilerTaskOptions,
    NS::Error**                      error) const
{
    return sendMessage<MTL::ComputePipelineState*>(
        this,
        _MTL_PRIVATE_SEL(newComputePipelineStateWithDescriptor_compilerTaskOptions_error_),
        descriptor,
        compilerTaskOptions,
        error);
}

_MTL_INLINE MTL::ComputePipelineState* MTL4::Compiler::newComputePipelineState(
    const ComputePipelineDescriptor*             descriptor,
    const PipelineStageDynamicLinkingDescriptor* dynamicLinkingDescriptor,
    const CompilerTaskOptions*                   compilerTaskOptions,
    NS::Error**                                  error) const
{
    return sendMessage<MTL::ComputePipelineState*>(
        this,
        _MTL_PRIVATE_SEL(newComputePipelineStateWithDescriptor_dynamicLinkingDescriptor_compilerTaskOptions_error_),
        descriptor,
        dynamicLinkingDescriptor,
        compilerTaskOptions,
        error);
}

_MTL_INLINE MTL4::CompilerTask* MTL4::Compiler::newComputePipelineState(
    const ComputePipelineDescriptor*                    descriptor,
    const CompilerTaskOptions*                          compilerTaskOptions,
    const MTL::NewComputePipelineStateCompletionHandler completionHandler)
{
    return sendMessage<CompilerTask*>(
        this,
        _MTL_PRIVATE_SEL(newComputePipelineStateWithDescriptor_compilerTaskOptions_completionHandler_),
        descriptor,
        compilerTaskOptions,
        completionHandler);
}

_MTL_INLINE MTL4::CompilerTask* MTL4::Compiler::newComputePipelineState(
    const ComputePipelineDescriptor*                    descriptor,
    const PipelineStageDynamicLinkingDescriptor*        dynamicLinkingDescriptor,
    const CompilerTaskOptions*                          compilerTaskOptions,
    const MTL::NewComputePipelineStateCompletionHandler completionHandler)
{
    return sendMessage<CompilerTask*>(
        this,
        _MTL_PRIVATE_SEL(
            newComputePipelineStateWithDescriptor_dynamicLinkingDescriptor_compilerTaskOptions_completionHandler_),
        descriptor,
        dynamicLinkingDescriptor,
        compilerTaskOptions,
        completionHandler);
}

_MTL_INLINE MTL4::CompilerTask* MTL4::Compiler::newComputePipelineState(
    const ComputePipelineDescriptor*                        pDescriptor,
    const CompilerTaskOptions*                              options,
    const NewComputePipelineStateCompletionHandlerFunction& function)
{
    __block NewComputePipelineStateCompletionHandlerFunction blockFunction = function;
    return newComputePipelineState(pDescriptor, options, ^(MTL::ComputePipelineState* pPipeline, NS::Error* pError) {
      blockFunction(pPipeline, pError);
    });
}

_MTL_INLINE MTL::DynamicLibrary* MTL4::Compiler::newDynamicLibrary(const MTL::Library* library, NS::Error** error) const
{
    return sendMessage<MTL::DynamicLibrary*>(this, _MTL_PRIVATE_SEL(newDynamicLibrary_error_), library, error);
}

_MTL_INLINE MTL::DynamicLibrary* MTL4::Compiler::newDynamicLibrary(const NS::URL* url, NS::Error** error) const
{
    return sendMessage<MTL::DynamicLibrary*>(this, _MTL_PRIVATE_SEL(newDynamicLibraryWithURL_error_), url, error);
}

_MTL_INLINE MTL4::CompilerTask* MTL4::Compiler::newDynamicLibrary(
    const MTL::Library* library, const MTL::NewDynamicLibraryCompletionHandler completionHandler)
{
    return sendMessage<CompilerTask*>(
        this, _MTL_PRIVATE_SEL(newDynamicLibrary_completionHandler_), library, completionHandler);
}

_MTL_INLINE MTL4::CompilerTask* MTL4::Compiler::newDynamicLibrary(
    const NS::URL* url, const MTL::NewDynamicLibraryCompletionHandler completionHandler)
{
    return sendMessage<CompilerTask*>(
        this, _MTL_PRIVATE_SEL(newDynamicLibraryWithURL_completionHandler_), url, completionHandler);
}

_MTL_INLINE MTL4::CompilerTask* MTL4::Compiler::newDynamicLibrary(
    const MTL::Library* pLibrary, const MTL::NewDynamicLibraryCompletionHandlerFunction& function)
{
    __block MTL::NewDynamicLibraryCompletionHandlerFunction blockFunction = function;
    return newDynamicLibrary(pLibrary, ^(MTL::DynamicLibrary* pLibraryRef, NS::Error* pError) {
      blockFunction(pLibraryRef, pError);
    });
}

_MTL_INLINE MTL4::CompilerTask* MTL4::Compiler::newDynamicLibrary(
    const NS::URL* pURL, const MTL::NewDynamicLibraryCompletionHandlerFunction& function)
{
    __block MTL::NewDynamicLibraryCompletionHandlerFunction blockFunction = function;
    return newDynamicLibrary(pURL, ^(MTL::DynamicLibrary* pLibrary, NS::Error* pError) {
      blockFunction(pLibrary, pError);
    });
}

_MTL_INLINE MTL::Library* MTL4::Compiler::newLibrary(const LibraryDescriptor* descriptor, NS::Error** error) const
{
    return sendMessage<MTL::Library*>(this, _MTL_PRIVATE_SEL(newLibraryWithDescriptor_error_), descriptor, error);
}

_MTL_INLINE MTL4::CompilerTask* MTL4::Compiler::newLibrary(const LibraryDescriptor*               descriptor,
                                                           const MTL::NewLibraryCompletionHandler completionHandler)
{
    return sendMessage<CompilerTask*>(
        this, _MTL_PRIVATE_SEL(newLibraryWithDescriptor_completionHandler_), descriptor, completionHandler);
}

_MTL_INLINE MTL4::CompilerTask* MTL4::Compiler::newLibrary(const LibraryDescriptor*                        pDescriptor,
                                                           const MTL::NewLibraryCompletionHandlerFunction& function)
{
    __block MTL::NewLibraryCompletionHandlerFunction blockFunction = function;
    return newLibrary(pDescriptor, ^(MTL::Library* pLibrary, NS::Error* pError) {
      blockFunction(pLibrary, pError);
    });
}

_MTL_INLINE MTL4::MachineLearningPipelineState* MTL4::Compiler::newMachineLearningPipelineState(
    const MachineLearningPipelineDescriptor* descriptor, NS::Error** error) const
{
    return sendMessage<MachineLearningPipelineState*>(
        this, _MTL_PRIVATE_SEL(newMachineLearningPipelineStateWithDescriptor_error_), descriptor, error);
}

_MTL_INLINE MTL4::CompilerTask* MTL4::Compiler::newMachineLearningPipelineState(
    const MachineLearningPipelineDescriptor*               descriptor,
    const NewMachineLearningPipelineStateCompletionHandler completionHandler)
{
    return sendMessage<CompilerTask*>(
        this,
        _MTL_PRIVATE_SEL(newMachineLearningPipelineStateWithDescriptor_completionHandler_),
        descriptor,
        completionHandler);
}

_MTL_INLINE MTL4::CompilerTask* MTL4::Compiler::newMachineLearningPipelineState(
    const MachineLearningPipelineDescriptor*                        pDescriptor,
    const NewMachineLearningPipelineStateCompletionHandlerFunction& function)
{
    __block NewMachineLearningPipelineStateCompletionHandlerFunction blockFunction = function;
    return newMachineLearningPipelineState(pDescriptor, ^(MachineLearningPipelineState* pPipeline, NS::Error* pError) {
      blockFunction(pPipeline, pError);
    });
}

_MTL_INLINE MTL::RenderPipelineState* MTL4::Compiler::newRenderPipelineState(
    const PipelineDescriptor* descriptor, const CompilerTaskOptions* compilerTaskOptions, NS::Error** error) const
{
    return sendMessage<MTL::RenderPipelineState*>(
        this,
        _MTL_PRIVATE_SEL(newRenderPipelineStateWithDescriptor_compilerTaskOptions_error_),
        descriptor,
        compilerTaskOptions,
        error);
}

_MTL_INLINE MTL::RenderPipelineState* MTL4::Compiler::newRenderPipelineState(
    const PipelineDescriptor*                     descriptor,
    const RenderPipelineDynamicLinkingDescriptor* dynamicLinkingDescriptor,
    const CompilerTaskOptions*                    compilerTaskOptions,
    NS::Error**                                   error) const
{
    return sendMessage<MTL::RenderPipelineState*>(
        this,
        _MTL_PRIVATE_SEL(newRenderPipelineStateWithDescriptor_dynamicLinkingDescriptor_compilerTaskOptions_error_),
        descriptor,
        dynamicLinkingDescriptor,
        compilerTaskOptions,
        error);
}

_MTL_INLINE MTL4::CompilerTask* MTL4::Compiler::newRenderPipelineState(
    const PipelineDescriptor*                          descriptor,
    const CompilerTaskOptions*                         compilerTaskOptions,
    const MTL::NewRenderPipelineStateCompletionHandler completionHandler)
{
    return sendMessage<CompilerTask*>(
        this,
        _MTL_PRIVATE_SEL(newRenderPipelineStateWithDescriptor_compilerTaskOptions_completionHandler_),
        descriptor,
        compilerTaskOptions,
        completionHandler);
}

_MTL_INLINE MTL4::CompilerTask* MTL4::Compiler::newRenderPipelineState(
    const PipelineDescriptor*                          descriptor,
    const RenderPipelineDynamicLinkingDescriptor*      dynamicLinkingDescriptor,
    const CompilerTaskOptions*                         compilerTaskOptions,
    const MTL::NewRenderPipelineStateCompletionHandler completionHandler)
{
    return sendMessage<CompilerTask*>(
        this,
        _MTL_PRIVATE_SEL(
            newRenderPipelineStateWithDescriptor_dynamicLinkingDescriptor_compilerTaskOptions_completionHandler_),
        descriptor,
        dynamicLinkingDescriptor,
        compilerTaskOptions,
        completionHandler);
}

_MTL_INLINE MTL4::CompilerTask* MTL4::Compiler::newRenderPipelineState(
    const PipelineDescriptor*                              pDescriptor,
    const CompilerTaskOptions*                             options,
    const NewRenderPipelineStateCompletionHandlerFunction& function)
{
    __block NewRenderPipelineStateCompletionHandlerFunction blockFunction = function;
    return newRenderPipelineState(pDescriptor, options, ^(MTL::RenderPipelineState* pPipeline, NS::Error* pError) {
      blockFunction(pPipeline, pError);
    });
}

_MTL_INLINE MTL::RenderPipelineState* MTL4::Compiler::newRenderPipelineStateBySpecialization(
    const PipelineDescriptor* descriptor, const MTL::RenderPipelineState* pipeline, NS::Error** error) const
{
    return sendMessage<MTL::RenderPipelineState*>(
        this,
        _MTL_PRIVATE_SEL(newRenderPipelineStateBySpecializationWithDescriptor_pipeline_error_),
        descriptor,
        pipeline,
        error);
}

_MTL_INLINE MTL4::CompilerTask* MTL4::Compiler::newRenderPipelineStateBySpecialization(
    const PipelineDescriptor*                          descriptor,
    const MTL::RenderPipelineState*                    pipeline,
    const MTL::NewRenderPipelineStateCompletionHandler completionHandler)
{
    return sendMessage<CompilerTask*>(
        this,
        _MTL_PRIVATE_SEL(newRenderPipelineStateBySpecializationWithDescriptor_pipeline_completionHandler_),
        descriptor,
        pipeline,
        completionHandler);
}

_MTL_INLINE MTL4::CompilerTask* MTL4::Compiler::newRenderPipelineStateBySpecialization(
    const PipelineDescriptor*                              pDescriptor,
    const MTL::RenderPipelineState*                        pPipeline,
    const NewRenderPipelineStateCompletionHandlerFunction& function)
{
    __block NewRenderPipelineStateCompletionHandlerFunction blockFunction = function;
    return newRenderPipelineStateBySpecialization(
        pDescriptor, pPipeline, ^(MTL::RenderPipelineState* pPipelineRef, NS::Error* pError) {
          blockFunction(pPipelineRef, pError);
        });
}

_MTL_INLINE MTL4::PipelineDataSetSerializer* MTL4::Compiler::pipelineDataSetSerializer() const
{
    return sendMessage<PipelineDataSetSerializer*>(this, _MTL_PRIVATE_SEL(pipelineDataSetSerializer));
}
