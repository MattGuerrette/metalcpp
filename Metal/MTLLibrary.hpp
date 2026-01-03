//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLLibrary.hpp
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
#include "MTLDataType.hpp"
#include "MTLDefines.hpp"
#include "MTLFunctionDescriptor.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"
#include "MTLTypes.hpp"

namespace MTL
{
    class Argument;
    class ArgumentEncoder;
    class Attribute;
    class CompileOptions;
    class Device;
    class Function;
    class FunctionConstant;
    class FunctionConstantValues;
    class FunctionDescriptor;
    class FunctionReflection;
    class IntersectionFunctionDescriptor;
    class VertexAttribute;

    /// @see https://developer.apple.com/documentation/metal/mtlpatchtype?language=objc
    _MTL_ENUM(NS::UInteger, PatchType){
        PatchTypeNone     = 0,
        PatchTypeTriangle = 1,
        PatchTypeQuad     = 2,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlfunctiontype?language=objc
    _MTL_ENUM(NS::UInteger, FunctionType){
        FunctionTypeVertex = 1,       FunctionTypeFragment = 2, FunctionTypeKernel = 3, FunctionTypeVisible = 5,
        FunctionTypeIntersection = 6, FunctionTypeMesh = 7,     FunctionTypeObject = 8,
    };

    /// @see https://developer.apple.com/documentation/metal/mtllanguageversion?language=objc
    _MTL_ENUM(NS::UInteger, LanguageVersion){
        LanguageVersion1_0 = 65536,  LanguageVersion1_1 = 65537,  LanguageVersion1_2 = 65538,
        LanguageVersion2_0 = 131072, LanguageVersion2_1 = 131073, LanguageVersion2_2 = 131074,
        LanguageVersion2_3 = 131075, LanguageVersion2_4 = 131076, LanguageVersion3_0 = 196608,
        LanguageVersion3_1 = 196609, LanguageVersion3_2 = 196610, LanguageVersion4_0 = 262144,
    };

    /// @see https://developer.apple.com/documentation/metal/mtllibrarytype?language=objc
    _MTL_ENUM(NS::Integer, LibraryType){
        LibraryTypeExecutable = 0,
        LibraryTypeDynamic    = 1,
    };

    /// @see https://developer.apple.com/documentation/metal/mtllibraryoptimizationlevel?language=objc
    _MTL_ENUM(NS::Integer, LibraryOptimizationLevel){
        LibraryOptimizationLevelDefault = 0,
        LibraryOptimizationLevelSize    = 1,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlcompilesymbolvisibility?language=objc
    _MTL_ENUM(NS::Integer, CompileSymbolVisibility){
        CompileSymbolVisibilityDefault = 0,
        CompileSymbolVisibilityHidden  = 1,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlmathmode?language=objc
    _MTL_ENUM(NS::Integer, MathMode){
        MathModeSafe    = 0,
        MathModeRelaxed = 1,
        MathModeFast    = 2,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlmathfloatingpointfunctions?language=objc
    _MTL_ENUM(NS::Integer, MathFloatingPointFunctions){
        MathFloatingPointFunctionsFast    = 0,
        MathFloatingPointFunctionsPrecise = 1,
    };

    /// @see https://developer.apple.com/documentation/metal/mtllibraryerror?language=objc
    _MTL_ENUM(NS::UInteger, LibraryError){
        LibraryErrorUnsupported = 1,    LibraryErrorInternal = 2,         LibraryErrorCompileFailure = 3,
        LibraryErrorCompileWarning = 4, LibraryErrorFunctionNotFound = 5, LibraryErrorFileNotFound = 6,
    };

    using AutoreleasedArgument              = Argument*;
    using FunctionCompletionHandlerFunction = std::function<void(Function* pFunction, NS::Error* pError)>;

    /// @see https://developer.apple.com/documentation/metal/mtlvertexattribute?language=objc
    class VertexAttribute : public NS::Referencing<VertexAttribute>
    {
    public:
        [[deprecated("please use isActive instead")]] [[nodiscard]] bool active() const;

        [[nodiscard]] static VertexAttribute* alloc();

        [[nodiscard]] NS::UInteger attributeIndex() const;

        [[nodiscard]] DataType attributeType() const;

        [[nodiscard]] VertexAttribute* init();

        [[nodiscard]] bool isActive() const;

        [[nodiscard]] bool isPatchControlPointData() const;

        [[nodiscard]] bool isPatchData() const;

        [[nodiscard]] NS::String* name() const;

        [[deprecated("please use isPatchControlPointData instead")]] [[nodiscard]] bool patchControlPointData() const;

        [[deprecated("please use isPatchData instead")]] [[nodiscard]] bool patchData() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlattribute?language=objc
    class Attribute : public NS::Referencing<Attribute>
    {
    public:
        [[deprecated("please use isActive instead")]] [[nodiscard]] bool active() const;

        [[nodiscard]] static Attribute* alloc();

        [[nodiscard]] NS::UInteger attributeIndex() const;

        [[nodiscard]] DataType attributeType() const;

        [[nodiscard]] Attribute* init();

        [[nodiscard]] bool isActive() const;

        [[nodiscard]] bool isPatchControlPointData() const;

        [[nodiscard]] bool isPatchData() const;

        [[nodiscard]] NS::String* name() const;

        [[deprecated("please use isPatchControlPointData instead")]] [[nodiscard]] bool patchControlPointData() const;

        [[deprecated("please use isPatchData instead")]] [[nodiscard]] bool patchData() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlfunctionconstant?language=objc
    class FunctionConstant : public NS::Referencing<FunctionConstant>
    {
    public:
        [[nodiscard]] static FunctionConstant* alloc();

        [[nodiscard]] NS::UInteger index() const;

        [[nodiscard]] FunctionConstant* init();

        [[nodiscard]] NS::String* name() const;

        [[nodiscard]] bool required() const;

        [[nodiscard]] DataType type() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlfunction?language=objc
    class Function : public NS::Referencing<Function>
    {
    public:
        [[nodiscard]] Device* device() const;

        [[nodiscard]] NS::Dictionary* functionConstantsDictionary() const;

        [[nodiscard]] FunctionType functionType() const;

        [[nodiscard]] NS::String* label() const;

        [[nodiscard]] NS::String* name() const;

        [[nodiscard]] ArgumentEncoder* newArgumentEncoder(NS::UInteger bufferIndex) const;
        [[nodiscard]] ArgumentEncoder* newArgumentEncoder(NS::UInteger                bufferIndex,
                                                          const AutoreleasedArgument* reflection) const;

        [[nodiscard]] FunctionOptions options() const;

        [[nodiscard]] NS::Integer patchControlPointCount() const;

        [[nodiscard]] PatchType patchType() const;

        void setLabel(const NS::String* label) const;

        [[nodiscard]] NS::Array* stageInputAttributes() const;

        [[nodiscard]] NS::Array* vertexAttributes() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlcompileoptions?language=objc
    class CompileOptions : public NS::Copying<CompileOptions>
    {
    public:
        [[nodiscard]] static CompileOptions* alloc();

        [[nodiscard]] bool allowReferencingUndefinedSymbols() const;

        [[nodiscard]] CompileSymbolVisibility compileSymbolVisibility() const;

        [[nodiscard]] bool enableLogging() const;

        [[nodiscard]] bool fastMathEnabled() const;

        [[nodiscard]] CompileOptions* init();

        [[nodiscard]] NS::String* installName() const;

        [[nodiscard]] LanguageVersion languageVersion() const;

        [[nodiscard]] NS::Array* libraries() const;

        [[nodiscard]] LibraryType libraryType() const;

        [[nodiscard]] MathFloatingPointFunctions mathFloatingPointFunctions() const;

        [[nodiscard]] MathMode mathMode() const;

        [[nodiscard]] NS::UInteger maxTotalThreadsPerThreadgroup() const;

        [[nodiscard]] LibraryOptimizationLevel optimizationLevel() const;

        [[nodiscard]] NS::Dictionary* preprocessorMacros() const;

        [[nodiscard]] bool preserveInvariance() const;

        [[nodiscard]] Size requiredThreadsPerThreadgroup() const;

        void setAllowReferencingUndefinedSymbols(bool allowReferencingUndefinedSymbols) const;

        void setCompileSymbolVisibility(CompileSymbolVisibility compileSymbolVisibility) const;

        void setEnableLogging(bool enableLogging) const;

        void setFastMathEnabled(bool fastMathEnabled) const;

        void setInstallName(const NS::String* installName) const;

        void setLanguageVersion(LanguageVersion languageVersion) const;

        void setLibraries(const NS::Array* libraries) const;

        void setLibraryType(LibraryType libraryType) const;

        void setMathFloatingPointFunctions(MathFloatingPointFunctions mathFloatingPointFunctions) const;

        void setMathMode(MathMode mathMode) const;

        void setMaxTotalThreadsPerThreadgroup(NS::UInteger maxTotalThreadsPerThreadgroup) const;

        void setOptimizationLevel(LibraryOptimizationLevel optimizationLevel) const;

        void setPreprocessorMacros(const NS::Dictionary* preprocessorMacros) const;

        void setPreserveInvariance(bool preserveInvariance) const;

        void setRequiredThreadsPerThreadgroup(Size requiredThreadsPerThreadgroup) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlfunctionreflection?language=objc
    class FunctionReflection : public NS::Referencing<FunctionReflection>
    {
    public:
        [[nodiscard]] static FunctionReflection* alloc();

        [[nodiscard]] NS::Array* bindings() const;

        [[nodiscard]] FunctionReflection* init();
    };

    /// @see https://developer.apple.com/documentation/metal/mtllibrary?language=objc
    class Library : public NS::Referencing<Library>
    {
    public:
        [[nodiscard]] Device* device() const;

        [[nodiscard]] NS::Array* functionNames() const;

        [[nodiscard]] NS::String* installName() const;

        [[nodiscard]] NS::String* label() const;

        [[nodiscard]] Function* newFunction(const NS::String* functionName) const;
        [[nodiscard]] Function* newFunction(const NS::String*             name,
                                            const FunctionConstantValues* constantValues,
                                            NS::Error**                   error) const;
        void                    newFunction(const NS::String*             name,
                                            const FunctionConstantValues* constantValues,
                                            void (^completionHandler)(Function*, NS::Error*));
        void newFunction(const FunctionDescriptor* descriptor, void (^completionHandler)(Function*, NS::Error*));
        [[nodiscard]] Function* newFunction(const FunctionDescriptor* descriptor, NS::Error** error) const;
        void                    newFunction(const NS::String*                        pFunctionName,
                                            const FunctionConstantValues*            pConstantValues,
                                            const FunctionCompletionHandlerFunction& completionHandler);
        void                    newFunction(const FunctionDescriptor*                pDescriptor,
                                            const FunctionCompletionHandlerFunction& completionHandler);

        void                    newIntersectionFunction(const IntersectionFunctionDescriptor* descriptor,
                                                        void (^completionHandler)(Function*, NS::Error*));
        [[nodiscard]] Function* newIntersectionFunction(const IntersectionFunctionDescriptor* descriptor,
                                                        NS::Error**                           error) const;
        void                    newIntersectionFunction(const IntersectionFunctionDescriptor*    pDescriptor,
                                                        const FunctionCompletionHandlerFunction& completionHandler);

        [[nodiscard]] FunctionReflection* reflectionForFunction(const NS::String* functionName) const;

        void setLabel(const NS::String* label) const;

        [[nodiscard]] LibraryType type() const;
    };

} // namespace MTL
_MTL_INLINE bool MTL::VertexAttribute::active() const { return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isActive)); }

_MTL_INLINE MTL::VertexAttribute* MTL::VertexAttribute::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<VertexAttribute>(_MTL_PRIVATE_CLS(MTLVertexAttribute));
}

_MTL_INLINE NS::UInteger MTL::VertexAttribute::attributeIndex() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(attributeIndex));
}

_MTL_INLINE MTL::DataType MTL::VertexAttribute::attributeType() const
{
    return sendMessage<DataType>(this, _MTL_PRIVATE_SEL(attributeType));
}

_MTL_INLINE MTL::VertexAttribute* MTL::VertexAttribute::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<VertexAttribute>();
}

_MTL_INLINE bool MTL::VertexAttribute::isActive() const { return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isActive)); }

_MTL_INLINE bool MTL::VertexAttribute::isPatchControlPointData() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isPatchControlPointData));
}

_MTL_INLINE bool MTL::VertexAttribute::isPatchData() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isPatchData));
}

_MTL_INLINE NS::String* MTL::VertexAttribute::name() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(name));
}

_MTL_INLINE bool MTL::VertexAttribute::patchControlPointData() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isPatchControlPointData));
}

_MTL_INLINE bool MTL::VertexAttribute::patchData() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isPatchData));
}

_MTL_INLINE bool MTL::Attribute::active() const { return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isActive)); }

_MTL_INLINE MTL::Attribute* MTL::Attribute::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<Attribute>(_MTL_PRIVATE_CLS(MTLAttribute));
}

_MTL_INLINE NS::UInteger MTL::Attribute::attributeIndex() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(attributeIndex));
}

_MTL_INLINE MTL::DataType MTL::Attribute::attributeType() const
{
    return sendMessage<DataType>(this, _MTL_PRIVATE_SEL(attributeType));
}

_MTL_INLINE MTL::Attribute* MTL::Attribute::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<Attribute>();
}

_MTL_INLINE bool MTL::Attribute::isActive() const { return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isActive)); }

_MTL_INLINE bool MTL::Attribute::isPatchControlPointData() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isPatchControlPointData));
}

_MTL_INLINE bool MTL::Attribute::isPatchData() const { return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isPatchData)); }

_MTL_INLINE NS::String* MTL::Attribute::name() const { return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(name)); }

_MTL_INLINE bool MTL::Attribute::patchControlPointData() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isPatchControlPointData));
}

_MTL_INLINE bool MTL::Attribute::patchData() const { return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isPatchData)); }

_MTL_INLINE MTL::FunctionConstant* MTL::FunctionConstant::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<FunctionConstant>(_MTL_PRIVATE_CLS(MTLFunctionConstant));
}

_MTL_INLINE NS::UInteger MTL::FunctionConstant::index() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(index));
}

_MTL_INLINE MTL::FunctionConstant* MTL::FunctionConstant::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<FunctionConstant>();
}

_MTL_INLINE NS::String* MTL::FunctionConstant::name() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(name));
}

_MTL_INLINE bool MTL::FunctionConstant::required() const { return sendMessage<bool>(this, _MTL_PRIVATE_SEL(required)); }

_MTL_INLINE MTL::DataType MTL::FunctionConstant::type() const
{
    return sendMessage<DataType>(this, _MTL_PRIVATE_SEL(type));
}

_MTL_INLINE MTL::Device* MTL::Function::device() const { return sendMessage<Device*>(this, _MTL_PRIVATE_SEL(device)); }

_MTL_INLINE NS::Dictionary* MTL::Function::functionConstantsDictionary() const
{
    return sendMessage<NS::Dictionary*>(this, _MTL_PRIVATE_SEL(functionConstantsDictionary));
}

_MTL_INLINE MTL::FunctionType MTL::Function::functionType() const
{
    return sendMessage<FunctionType>(this, _MTL_PRIVATE_SEL(functionType));
}

_MTL_INLINE NS::String* MTL::Function::label() const { return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label)); }

_MTL_INLINE NS::String* MTL::Function::name() const { return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(name)); }

_MTL_INLINE MTL::ArgumentEncoder* MTL::Function::newArgumentEncoder(const NS::UInteger bufferIndex) const
{
    return sendMessage<ArgumentEncoder*>(this, _MTL_PRIVATE_SEL(newArgumentEncoderWithBufferIndex_), bufferIndex);
}

_MTL_INLINE MTL::ArgumentEncoder* MTL::Function::newArgumentEncoder(const NS::UInteger          bufferIndex,
                                                                    const AutoreleasedArgument* reflection) const
{
    return sendMessage<ArgumentEncoder*>(
        this, _MTL_PRIVATE_SEL(newArgumentEncoderWithBufferIndex_reflection_), bufferIndex, reflection);
}

_MTL_INLINE MTL::FunctionOptions MTL::Function::options() const
{
    return sendMessage<FunctionOptions>(this, _MTL_PRIVATE_SEL(options));
}

_MTL_INLINE NS::Integer MTL::Function::patchControlPointCount() const
{
    return sendMessage<NS::Integer>(this, _MTL_PRIVATE_SEL(patchControlPointCount));
}

_MTL_INLINE MTL::PatchType MTL::Function::patchType() const
{
    return sendMessage<PatchType>(this, _MTL_PRIVATE_SEL(patchType));
}

_MTL_INLINE void MTL::Function::setLabel(const NS::String* label) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLabel_), label);
}

_MTL_INLINE NS::Array* MTL::Function::stageInputAttributes() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(stageInputAttributes));
}

_MTL_INLINE NS::Array* MTL::Function::vertexAttributes() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(vertexAttributes));
}

_MTL_INLINE MTL::CompileOptions* MTL::CompileOptions::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<CompileOptions>(_MTL_PRIVATE_CLS(MTLCompileOptions));
}

_MTL_INLINE bool MTL::CompileOptions::allowReferencingUndefinedSymbols() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(allowReferencingUndefinedSymbols));
}

_MTL_INLINE MTL::CompileSymbolVisibility MTL::CompileOptions::compileSymbolVisibility() const
{
    return sendMessage<CompileSymbolVisibility>(this, _MTL_PRIVATE_SEL(compileSymbolVisibility));
}

_MTL_INLINE bool MTL::CompileOptions::enableLogging() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(enableLogging));
}

_MTL_INLINE bool MTL::CompileOptions::fastMathEnabled() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(fastMathEnabled));
}

_MTL_INLINE MTL::CompileOptions* MTL::CompileOptions::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<CompileOptions>();
}

_MTL_INLINE NS::String* MTL::CompileOptions::installName() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(installName));
}

_MTL_INLINE MTL::LanguageVersion MTL::CompileOptions::languageVersion() const
{
    return sendMessage<LanguageVersion>(this, _MTL_PRIVATE_SEL(languageVersion));
}

_MTL_INLINE NS::Array* MTL::CompileOptions::libraries() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(libraries));
}

_MTL_INLINE MTL::LibraryType MTL::CompileOptions::libraryType() const
{
    return sendMessage<LibraryType>(this, _MTL_PRIVATE_SEL(libraryType));
}

_MTL_INLINE MTL::MathFloatingPointFunctions MTL::CompileOptions::mathFloatingPointFunctions() const
{
    return sendMessage<MathFloatingPointFunctions>(this, _MTL_PRIVATE_SEL(mathFloatingPointFunctions));
}

_MTL_INLINE MTL::MathMode MTL::CompileOptions::mathMode() const
{
    return sendMessage<MathMode>(this, _MTL_PRIVATE_SEL(mathMode));
}

_MTL_INLINE NS::UInteger MTL::CompileOptions::maxTotalThreadsPerThreadgroup() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxTotalThreadsPerThreadgroup));
}

_MTL_INLINE MTL::LibraryOptimizationLevel MTL::CompileOptions::optimizationLevel() const
{
    return sendMessage<LibraryOptimizationLevel>(this, _MTL_PRIVATE_SEL(optimizationLevel));
}

_MTL_INLINE NS::Dictionary* MTL::CompileOptions::preprocessorMacros() const
{
    return sendMessage<NS::Dictionary*>(this, _MTL_PRIVATE_SEL(preprocessorMacros));
}

_MTL_INLINE bool MTL::CompileOptions::preserveInvariance() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(preserveInvariance));
}

_MTL_INLINE MTL::Size MTL::CompileOptions::requiredThreadsPerThreadgroup() const
{
    return sendMessage<Size>(this, _MTL_PRIVATE_SEL(requiredThreadsPerThreadgroup));
}

_MTL_INLINE void MTL::CompileOptions::setAllowReferencingUndefinedSymbols(
    const bool allowReferencingUndefinedSymbols) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setAllowReferencingUndefinedSymbols_), allowReferencingUndefinedSymbols);
}

_MTL_INLINE void MTL::CompileOptions::setCompileSymbolVisibility(
    const CompileSymbolVisibility compileSymbolVisibility) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setCompileSymbolVisibility_), compileSymbolVisibility);
}

_MTL_INLINE void MTL::CompileOptions::setEnableLogging(const bool enableLogging) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setEnableLogging_), enableLogging);
}

_MTL_INLINE void MTL::CompileOptions::setFastMathEnabled(const bool fastMathEnabled) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFastMathEnabled_), fastMathEnabled);
}

_MTL_INLINE void MTL::CompileOptions::setInstallName(const NS::String* installName) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setInstallName_), installName);
}

_MTL_INLINE void MTL::CompileOptions::setLanguageVersion(const LanguageVersion languageVersion) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLanguageVersion_), languageVersion);
}

_MTL_INLINE void MTL::CompileOptions::setLibraries(const NS::Array* libraries) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLibraries_), libraries);
}

_MTL_INLINE void MTL::CompileOptions::setLibraryType(const LibraryType libraryType) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLibraryType_), libraryType);
}

_MTL_INLINE void MTL::CompileOptions::setMathFloatingPointFunctions(
    const MathFloatingPointFunctions mathFloatingPointFunctions) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMathFloatingPointFunctions_), mathFloatingPointFunctions);
}

_MTL_INLINE void MTL::CompileOptions::setMathMode(const MathMode mathMode) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMathMode_), mathMode);
}

_MTL_INLINE void MTL::CompileOptions::setMaxTotalThreadsPerThreadgroup(
    const NS::UInteger maxTotalThreadsPerThreadgroup) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setMaxTotalThreadsPerThreadgroup_), maxTotalThreadsPerThreadgroup);
}

_MTL_INLINE void MTL::CompileOptions::setOptimizationLevel(const LibraryOptimizationLevel optimizationLevel) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setOptimizationLevel_), optimizationLevel);
}

_MTL_INLINE void MTL::CompileOptions::setPreprocessorMacros(const NS::Dictionary* preprocessorMacros) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setPreprocessorMacros_), preprocessorMacros);
}

_MTL_INLINE void MTL::CompileOptions::setPreserveInvariance(const bool preserveInvariance) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setPreserveInvariance_), preserveInvariance);
}

_MTL_INLINE void MTL::CompileOptions::setRequiredThreadsPerThreadgroup(Size requiredThreadsPerThreadgroup) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setRequiredThreadsPerThreadgroup_), requiredThreadsPerThreadgroup);
}

_MTL_INLINE MTL::FunctionReflection* MTL::FunctionReflection::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<FunctionReflection>(_MTL_PRIVATE_CLS(MTLFunctionReflection));
}

_MTL_INLINE NS::Array* MTL::FunctionReflection::bindings() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(bindings));
}

_MTL_INLINE MTL::FunctionReflection* MTL::FunctionReflection::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<FunctionReflection>();
}

_MTL_INLINE MTL::Device* MTL::Library::device() const { return sendMessage<Device*>(this, _MTL_PRIVATE_SEL(device)); }

_MTL_INLINE NS::Array* MTL::Library::functionNames() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(functionNames));
}

_MTL_INLINE NS::String* MTL::Library::installName() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(installName));
}

_MTL_INLINE NS::String* MTL::Library::label() const { return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(label)); }

_MTL_INLINE MTL::Function* MTL::Library::newFunction(const NS::String* functionName) const
{
    return sendMessage<Function*>(this, _MTL_PRIVATE_SEL(newFunctionWithName_), functionName);
}

_MTL_INLINE MTL::Function* MTL::Library::newFunction(const NS::String*             name,
                                                     const FunctionConstantValues* constantValues,
                                                     NS::Error**                   error) const
{
    return sendMessage<Function*>(
        this, _MTL_PRIVATE_SEL(newFunctionWithName_constantValues_error_), name, constantValues, error);
}

_MTL_INLINE void MTL::Library::newFunction(const NS::String*             name,
                                           const FunctionConstantValues* constantValues,
                                           void (^completionHandler)(Function*, NS::Error*))
{
    Object::sendMessage<void>(this,
                              _MTL_PRIVATE_SEL(newFunctionWithName_constantValues_completionHandler_),
                              name,
                              constantValues,
                              completionHandler);
}

_MTL_INLINE void MTL::Library::newFunction(const FunctionDescriptor* descriptor,
                                           void (^completionHandler)(Function*, NS::Error*))
{
    Object::sendMessage<void>(
        this, _MTL_PRIVATE_SEL(newFunctionWithDescriptor_completionHandler_), descriptor, completionHandler);
}

_MTL_INLINE MTL::Function* MTL::Library::newFunction(const FunctionDescriptor* descriptor, NS::Error** error) const
{
    return sendMessage<Function*>(this, _MTL_PRIVATE_SEL(newFunctionWithDescriptor_error_), descriptor, error);
}

_MTL_INLINE void MTL::Library::newFunction(const NS::String*                        pFunctionName,
                                           const FunctionConstantValues*            pConstantValues,
                                           const FunctionCompletionHandlerFunction& completionHandler)
{
    __block FunctionCompletionHandlerFunction blockCompletionHandler = completionHandler;
    newFunction(pFunctionName, pConstantValues, ^(Function* pFunction, NS::Error* pError) {
      blockCompletionHandler(pFunction, pError);
    });
}

_MTL_INLINE void MTL::Library::newFunction(const FunctionDescriptor*                pDescriptor,
                                           const FunctionCompletionHandlerFunction& completionHandler)
{
    __block FunctionCompletionHandlerFunction blockCompletionHandler = completionHandler;
    newFunction(pDescriptor, ^(Function* pFunction, NS::Error* pError) {
      blockCompletionHandler(pFunction, pError);
    });
}

_MTL_INLINE void MTL::Library::newIntersectionFunction(const IntersectionFunctionDescriptor* descriptor,
                                                       void (^completionHandler)(Function*, NS::Error*))
{
    Object::sendMessage<void>(this,
                              _MTL_PRIVATE_SEL(newIntersectionFunctionWithDescriptor_completionHandler_),
                              descriptor,
                              completionHandler);
}

_MTL_INLINE MTL::Function* MTL::Library::newIntersectionFunction(const IntersectionFunctionDescriptor* descriptor,
                                                                 NS::Error**                           error) const
{
    return sendMessage<Function*>(
        this, _MTL_PRIVATE_SEL(newIntersectionFunctionWithDescriptor_error_), descriptor, error);
}

_MTL_INLINE void MTL::Library::newIntersectionFunction(const IntersectionFunctionDescriptor*    pDescriptor,
                                                       const FunctionCompletionHandlerFunction& completionHandler)
{
    __block FunctionCompletionHandlerFunction blockCompletionHandler = completionHandler;
    newIntersectionFunction(pDescriptor, ^(Function* pFunction, NS::Error* pError) {
      blockCompletionHandler(pFunction, pError);
    });
}

_MTL_INLINE MTL::FunctionReflection* MTL::Library::reflectionForFunction(const NS::String* functionName) const
{
    return sendMessage<FunctionReflection*>(this, _MTL_PRIVATE_SEL(reflectionForFunctionWithName_), functionName);
}

_MTL_INLINE void MTL::Library::setLabel(const NS::String* label) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setLabel_), label);
}

_MTL_INLINE MTL::LibraryType MTL::Library::type() const
{
    return sendMessage<LibraryType>(this, _MTL_PRIVATE_SEL(type));
}
