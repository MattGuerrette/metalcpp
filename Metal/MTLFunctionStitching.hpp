//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLFunctionStitching.hpp
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
    class FunctionStitchingAttributeAlwaysInline;
    class FunctionStitchingFunctionNode;
    class FunctionStitchingGraph;
    class FunctionStitchingInputNode;
    class StitchedLibraryDescriptor;

    /// @see https://developer.apple.com/documentation/metal/mtlstitchedlibraryoptions?language=objc
    _MTL_OPTIONS(NS::UInteger, StitchedLibraryOptions){
        StitchedLibraryOptionNone                               = 0,
        StitchedLibraryOptionFailOnBinaryArchiveMiss            = 1,
        StitchedLibraryOptionStoreLibraryInMetalPipelinesScript = 1 << 1,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlfunctionstitchingattribute?language=objc
    class FunctionStitchingAttribute : public NS::Referencing<FunctionStitchingAttribute>
    {
    };

    /// @see https://developer.apple.com/documentation/metal/mtlfunctionstitchingattributealwaysinline?language=objc
    class FunctionStitchingAttributeAlwaysInline
        : public NS::Referencing<FunctionStitchingAttributeAlwaysInline, FunctionStitchingAttribute>
    {
    public:
        static FunctionStitchingAttributeAlwaysInline* alloc();

        FunctionStitchingAttributeAlwaysInline* init();
    };

    /// @see https://developer.apple.com/documentation/metal/mtlfunctionstitchingnode?language=objc
    class FunctionStitchingNode : public NS::Copying<FunctionStitchingNode>
    {
    };

    /// @see https://developer.apple.com/documentation/metal/mtlfunctionstitchinginputnode?language=objc
    class FunctionStitchingInputNode : public NS::Referencing<FunctionStitchingInputNode, FunctionStitchingNode>
    {
    public:
        [[nodiscard]] static FunctionStitchingInputNode* alloc();

        [[nodiscard]] NS::UInteger argumentIndex() const;

        [[nodiscard]] FunctionStitchingInputNode* init();
        [[nodiscard]] FunctionStitchingInputNode* init(NS::UInteger argument) const;

        void setArgumentIndex(NS::UInteger argumentIndex) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlfunctionstitchingfunctionnode?language=objc
    class FunctionStitchingFunctionNode : public NS::Referencing<FunctionStitchingFunctionNode, FunctionStitchingNode>
    {
    public:
        [[nodiscard]] static FunctionStitchingFunctionNode* alloc();

        [[nodiscard]] NS::Array* arguments() const;

        [[nodiscard]] NS::Array* controlDependencies() const;

        [[nodiscard]] FunctionStitchingFunctionNode* init();
        [[nodiscard]] FunctionStitchingFunctionNode* init(const NS::String* name,
                                                          const NS::Array*  arguments,
                                                          const NS::Array*  controlDependencies) const;

        [[nodiscard]] NS::String* name() const;

        void setArguments(const NS::Array* arguments) const;

        void setControlDependencies(const NS::Array* controlDependencies) const;

        void setName(const NS::String* name) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlfunctionstitchinggraph?language=objc
    class FunctionStitchingGraph : public NS::Copying<FunctionStitchingGraph>
    {
    public:
        [[nodiscard]] static FunctionStitchingGraph* alloc();

        [[nodiscard]] NS::Array* attributes() const;

        [[nodiscard]] NS::String* functionName() const;

        [[nodiscard]] FunctionStitchingGraph* init();
        [[nodiscard]] FunctionStitchingGraph* init(const NS::String*                    functionName,
                                                   const NS::Array*                     nodes,
                                                   const FunctionStitchingFunctionNode* outputNode,
                                                   const NS::Array*                     attributes) const;

        [[nodiscard]] NS::Array* nodes() const;

        [[nodiscard]] FunctionStitchingFunctionNode* outputNode() const;

        void setAttributes(const NS::Array* attributes) const;

        void setFunctionName(const NS::String* functionName) const;

        void setNodes(const NS::Array* nodes) const;

        void setOutputNode(const FunctionStitchingFunctionNode* outputNode) const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlstitchedlibrarydescriptor?language=objc
    class StitchedLibraryDescriptor : public NS::Copying<StitchedLibraryDescriptor>
    {
    public:
        [[nodiscard]] static StitchedLibraryDescriptor* alloc();

        [[nodiscard]] NS::Array* binaryArchives() const;

        [[nodiscard]] NS::Array* functionGraphs() const;

        [[nodiscard]] NS::Array* functions() const;

        [[nodiscard]] StitchedLibraryDescriptor* init();

        [[nodiscard]] StitchedLibraryOptions options() const;

        void setBinaryArchives(const NS::Array* binaryArchives) const;

        void setFunctionGraphs(const NS::Array* functionGraphs) const;

        void setFunctions(const NS::Array* functions) const;

        void setOptions(StitchedLibraryOptions options) const;
    };

} // namespace MTL
_MTL_INLINE MTL::FunctionStitchingAttributeAlwaysInline* MTL::FunctionStitchingAttributeAlwaysInline::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<FunctionStitchingAttributeAlwaysInline>(
        _MTL_PRIVATE_CLS(MTLFunctionStitchingAttributeAlwaysInline));
}

_MTL_INLINE MTL::FunctionStitchingAttributeAlwaysInline* MTL::FunctionStitchingAttributeAlwaysInline::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<FunctionStitchingAttributeAlwaysInline>();
}

_MTL_INLINE MTL::FunctionStitchingInputNode* MTL::FunctionStitchingInputNode::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<FunctionStitchingInputNode>(_MTL_PRIVATE_CLS(MTLFunctionStitchingInputNode));
}

_MTL_INLINE NS::UInteger MTL::FunctionStitchingInputNode::argumentIndex() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(argumentIndex));
}

_MTL_INLINE MTL::FunctionStitchingInputNode* MTL::FunctionStitchingInputNode::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<FunctionStitchingInputNode>();
}

_MTL_INLINE MTL::FunctionStitchingInputNode* MTL::FunctionStitchingInputNode::init(const NS::UInteger argument) const
{
    return sendMessage<FunctionStitchingInputNode*>(this, _MTL_PRIVATE_SEL(initWithArgumentIndex_), argument);
}

_MTL_INLINE void MTL::FunctionStitchingInputNode::setArgumentIndex(const NS::UInteger argumentIndex) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setArgumentIndex_), argumentIndex);
}

_MTL_INLINE MTL::FunctionStitchingFunctionNode* MTL::FunctionStitchingFunctionNode::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<FunctionStitchingFunctionNode>(_MTL_PRIVATE_CLS(MTLFunctionStitchingFunctionNode));
}

_MTL_INLINE NS::Array* MTL::FunctionStitchingFunctionNode::arguments() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(arguments));
}

_MTL_INLINE NS::Array* MTL::FunctionStitchingFunctionNode::controlDependencies() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(controlDependencies));
}

_MTL_INLINE MTL::FunctionStitchingFunctionNode* MTL::FunctionStitchingFunctionNode::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<FunctionStitchingFunctionNode>();
}

_MTL_INLINE MTL::FunctionStitchingFunctionNode* MTL::FunctionStitchingFunctionNode::init(
    const NS::String* name, const NS::Array* arguments, const NS::Array* controlDependencies) const
{
    return sendMessage<FunctionStitchingFunctionNode*>(
        this, _MTL_PRIVATE_SEL(initWithName_arguments_controlDependencies_), name, arguments, controlDependencies);
}

_MTL_INLINE NS::String* MTL::FunctionStitchingFunctionNode::name() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(name));
}

_MTL_INLINE void MTL::FunctionStitchingFunctionNode::setArguments(const NS::Array* arguments) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setArguments_), arguments);
}

_MTL_INLINE void MTL::FunctionStitchingFunctionNode::setControlDependencies(const NS::Array* controlDependencies) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setControlDependencies_), controlDependencies);
}

_MTL_INLINE void MTL::FunctionStitchingFunctionNode::setName(const NS::String* name) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setName_), name);
}

_MTL_INLINE MTL::FunctionStitchingGraph* MTL::FunctionStitchingGraph::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<FunctionStitchingGraph>(_MTL_PRIVATE_CLS(MTLFunctionStitchingGraph));
}

_MTL_INLINE NS::Array* MTL::FunctionStitchingGraph::attributes() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(attributes));
}

_MTL_INLINE NS::String* MTL::FunctionStitchingGraph::functionName() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(functionName));
}

_MTL_INLINE MTL::FunctionStitchingGraph* MTL::FunctionStitchingGraph::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<FunctionStitchingGraph>();
}

_MTL_INLINE MTL::FunctionStitchingGraph* MTL::FunctionStitchingGraph::init(
    const NS::String*                    functionName,
    const NS::Array*                     nodes,
    const FunctionStitchingFunctionNode* outputNode,
    const NS::Array*                     attributes) const
{
    return sendMessage<FunctionStitchingGraph*>(this,
                                                _MTL_PRIVATE_SEL(initWithFunctionName_nodes_outputNode_attributes_),
                                                functionName,
                                                nodes,
                                                outputNode,
                                                attributes);
}

_MTL_INLINE NS::Array* MTL::FunctionStitchingGraph::nodes() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(nodes));
}

_MTL_INLINE MTL::FunctionStitchingFunctionNode* MTL::FunctionStitchingGraph::outputNode() const
{
    return sendMessage<FunctionStitchingFunctionNode*>(this, _MTL_PRIVATE_SEL(outputNode));
}

_MTL_INLINE void MTL::FunctionStitchingGraph::setAttributes(const NS::Array* attributes) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setAttributes_), attributes);
}

_MTL_INLINE void MTL::FunctionStitchingGraph::setFunctionName(const NS::String* functionName) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFunctionName_), functionName);
}

_MTL_INLINE void MTL::FunctionStitchingGraph::setNodes(const NS::Array* nodes) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setNodes_), nodes);
}

_MTL_INLINE void MTL::FunctionStitchingGraph::setOutputNode(const FunctionStitchingFunctionNode* outputNode) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setOutputNode_), outputNode);
}

_MTL_INLINE MTL::StitchedLibraryDescriptor* MTL::StitchedLibraryDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<StitchedLibraryDescriptor>(_MTL_PRIVATE_CLS(MTLStitchedLibraryDescriptor));
}

_MTL_INLINE NS::Array* MTL::StitchedLibraryDescriptor::binaryArchives() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(binaryArchives));
}

_MTL_INLINE NS::Array* MTL::StitchedLibraryDescriptor::functionGraphs() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(functionGraphs));
}

_MTL_INLINE NS::Array* MTL::StitchedLibraryDescriptor::functions() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(functions));
}

_MTL_INLINE MTL::StitchedLibraryDescriptor* MTL::StitchedLibraryDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<StitchedLibraryDescriptor>();
}

_MTL_INLINE MTL::StitchedLibraryOptions MTL::StitchedLibraryDescriptor::options() const
{
    return sendMessage<StitchedLibraryOptions>(this, _MTL_PRIVATE_SEL(options));
}

_MTL_INLINE void MTL::StitchedLibraryDescriptor::setBinaryArchives(const NS::Array* binaryArchives) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setBinaryArchives_), binaryArchives);
}

_MTL_INLINE void MTL::StitchedLibraryDescriptor::setFunctionGraphs(const NS::Array* functionGraphs) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFunctionGraphs_), functionGraphs);
}

_MTL_INLINE void MTL::StitchedLibraryDescriptor::setFunctions(const NS::Array* functions) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setFunctions_), functions);
}

_MTL_INLINE void MTL::StitchedLibraryDescriptor::setOptions(const StitchedLibraryOptions options) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setOptions_), options);
}
