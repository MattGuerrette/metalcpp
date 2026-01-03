//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLDevice.hpp
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

#include <IOSurface/IOSurfaceRef.h>
#include <cstdint>
#include <dispatch/dispatch.h>
#include "../Foundation/Foundation.hpp"
#include "MTL4Counters.hpp"
#include "MTLArgument.hpp"
#include "MTLDataType.hpp"
#include "MTLDefines.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPixelFormat.hpp"
#include "MTLPrivate.hpp"
#include "MTLResource.hpp"
#include "MTLTexture.hpp"
#include "MTLTypes.hpp"

#include <functional>

namespace MTL
{
    class AccelerationStructure;
    class AccelerationStructureDescriptor;
    class Architecture;
    class ArgumentDescriptor;
    class ArgumentEncoder;
    class BinaryArchive;
    class BinaryArchiveDescriptor;
    class Buffer;
    class BufferBinding;
    class CommandQueue;
    class CommandQueueDescriptor;
    class CompileOptions;
    class ComputePipelineDescriptor;
    class ComputePipelineReflection;
    class ComputePipelineState;
    class CounterSampleBuffer;
    class CounterSampleBufferDescriptor;
    class DepthStencilDescriptor;
    class DepthStencilState;
    class Device;
    class DynamicLibrary;
    class Event;
    class Fence;
    class Function;
    class FunctionConstantValues;
    class FunctionHandle;
    class Heap;
    class HeapDescriptor;
    class IOCommandQueue;
    class IOCommandQueueDescriptor;
    class IOFileHandle;
    class IndirectCommandBuffer;
    class IndirectCommandBufferDescriptor;
    class Library;
    class LogState;
    class LogStateDescriptor;
    class MeshRenderPipelineDescriptor;
    class RasterizationRateMap;
    class RasterizationRateMapDescriptor;
    struct Region;
    class RenderPipelineDescriptor;
    class RenderPipelineReflection;
    class RenderPipelineState;
    class ResidencySet;
    class ResidencySetDescriptor;
    class ResourceViewPoolDescriptor;
    struct SamplePosition;
    class SamplerDescriptor;
    class SamplerState;
    class SharedEvent;
    class SharedEventHandle;
    class SharedTextureHandle;
    class StitchedLibraryDescriptor;
    class Tensor;
    class TensorDescriptor;
    class Texture;
    class TextureDescriptor;
    class TextureViewPool;
    class TileRenderPipelineDescriptor;

} // namespace MTL
namespace MTL4
{
    class Archive;
    class ArgumentTable;
    class ArgumentTableDescriptor;
    class BinaryFunction;
    class CommandAllocator;
    class CommandAllocatorDescriptor;
    class CommandBuffer;
    class CommandQueue;
    class CommandQueueDescriptor;
    class Compiler;
    class CompilerDescriptor;
    class CounterHeap;
    class CounterHeapDescriptor;
    class PipelineDataSetSerializer;
    class PipelineDataSetSerializerDescriptor;

} // namespace MTL4
namespace MTL
{
    /// @see https://developer.apple.com/documentation/metal/mtliocompressionmethod?language=objc
    _MTL_ENUM(NS::Integer, IOCompressionMethod){
        IOCompressionMethodZlib = 0, IOCompressionMethodLZFSE = 1,    IOCompressionMethodLZ4 = 2,
        IOCompressionMethodLZMA = 3, IOCompressionMethodLZBitmap = 4,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlfeatureset?language=objc
    _MTL_ENUM(NS::UInteger, FeatureSet){
        FeatureSet_iOS_GPUFamily1_v1           = 0,
        FeatureSet_iOS_GPUFamily2_v1           = 1,
        FeatureSet_iOS_GPUFamily1_v2           = 2,
        FeatureSet_iOS_GPUFamily2_v2           = 3,
        FeatureSet_iOS_GPUFamily3_v1           = 4,
        FeatureSet_iOS_GPUFamily1_v3           = 5,
        FeatureSet_iOS_GPUFamily2_v3           = 6,
        FeatureSet_iOS_GPUFamily3_v2           = 7,
        FeatureSet_iOS_GPUFamily1_v4           = 8,
        FeatureSet_iOS_GPUFamily2_v4           = 9,
        FeatureSet_iOS_GPUFamily3_v3           = 10,
        FeatureSet_iOS_GPUFamily4_v1           = 11,
        FeatureSet_iOS_GPUFamily1_v5           = 12,
        FeatureSet_iOS_GPUFamily2_v5           = 13,
        FeatureSet_iOS_GPUFamily3_v4           = 14,
        FeatureSet_iOS_GPUFamily4_v2           = 15,
        FeatureSet_iOS_GPUFamily5_v1           = 16,
        FeatureSet_macOS_GPUFamily1_v1         = 10000,
        FeatureSet_OSX_GPUFamily1_v1           = 10000,
        FeatureSet_macOS_GPUFamily1_v2         = 10001,
        FeatureSet_OSX_GPUFamily1_v2           = 10001,
        FeatureSet_macOS_ReadWriteTextureTier2 = 10002,
        FeatureSet_OSX_ReadWriteTextureTier2   = 10002,
        FeatureSet_macOS_GPUFamily1_v3         = 10003,
        FeatureSet_macOS_GPUFamily1_v4         = 10004,
        FeatureSet_macOS_GPUFamily2_v1         = 10005,
        FeatureSet_watchOS_GPUFamily1_v1       = 20000,
        FeatureSet_WatchOS_GPUFamily1_v1       = 20000,
        FeatureSet_watchOS_GPUFamily2_v1       = 20001,
        FeatureSet_WatchOS_GPUFamily2_v1       = 20001,
        FeatureSet_tvOS_GPUFamily1_v1          = 30000,
        FeatureSet_TVOS_GPUFamily1_v1          = 30000,
        FeatureSet_tvOS_GPUFamily1_v2          = 30001,
        FeatureSet_tvOS_GPUFamily1_v3          = 30002,
        FeatureSet_tvOS_GPUFamily2_v1          = 30003,
        FeatureSet_tvOS_GPUFamily1_v4          = 30004,
        FeatureSet_tvOS_GPUFamily2_v2          = 30005,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlgpufamily?language=objc
    _MTL_ENUM(NS::Integer, GPUFamily){
        GPUFamilyApple1 = 1001,       GPUFamilyApple2 = 1002,  GPUFamilyApple3 = 1003,  GPUFamilyApple4 = 1004,
        GPUFamilyApple5 = 1005,       GPUFamilyApple6 = 1006,  GPUFamilyApple7 = 1007,  GPUFamilyApple8 = 1008,
        GPUFamilyApple9 = 1009,       GPUFamilyApple10 = 1010, GPUFamilyMac1 = 2001,    GPUFamilyMac2 = 2002,
        GPUFamilyCommon1 = 3001,      GPUFamilyCommon2 = 3002, GPUFamilyCommon3 = 3003, GPUFamilyMacCatalyst1 = 4001,
        GPUFamilyMacCatalyst2 = 4002, GPUFamilyMetal3 = 5001,  GPUFamilyMetal4 = 5002,
    };

    /// @see https://developer.apple.com/documentation/metal/mtldevicelocation?language=objc
    _MTL_ENUM(NS::UInteger, DeviceLocation){
        DeviceLocationBuiltIn     = 0,
        DeviceLocationSlot        = 1,
        DeviceLocationExternal    = 2,
        DeviceLocationUnspecified = NS::UIntegerMax,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlreadwritetexturetier?language=objc
    _MTL_ENUM(NS::UInteger, ReadWriteTextureTier){
        ReadWriteTextureTierNone = 0,
        ReadWriteTextureTier1    = 1,
        ReadWriteTextureTier2    = 2,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlargumentbufferstier?language=objc
    _MTL_ENUM(NS::UInteger, ArgumentBuffersTier){
        ArgumentBuffersTier1 = 0,
        ArgumentBuffersTier2 = 1,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlsparsetextureregionalignmentmode?language=objc
    _MTL_ENUM(NS::UInteger, SparseTextureRegionAlignmentMode){
        SparseTextureRegionAlignmentModeOutward = 0,
        SparseTextureRegionAlignmentModeInward  = 1,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlcountersamplingpoint?language=objc
    _MTL_ENUM(NS::UInteger, CounterSamplingPoint){
        CounterSamplingPointAtStageBoundary = 0,    CounterSamplingPointAtDrawBoundary = 1,
        CounterSamplingPointAtDispatchBoundary = 2, CounterSamplingPointAtTileDispatchBoundary = 3,
        CounterSamplingPointAtBlitBoundary = 4,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlpipelineoption?language=objc
    _MTL_OPTIONS(NS::UInteger, PipelineOption){
        PipelineOptionNone                    = 0,
        PipelineOptionArgumentInfo            = 1,
        PipelineOptionBindingInfo             = 1,
        PipelineOptionBufferTypeInfo          = 1 << 1,
        PipelineOptionFailOnBinaryArchiveMiss = 1 << 2,
    };

    using DeviceNotificationName            = const NS::String*;
    using DeviceNotificationHandlerBlock    = void (^)(MTL::Device* pDevice, DeviceNotificationName notifyName);
    using DeviceNotificationHandlerFunction = std::function<void(Device* pDevice, DeviceNotificationName notifyName)>;
    using AutoreleasedComputePipelineReflection                 = ComputePipelineReflection*;
    using AutoreleasedRenderPipelineReflection                  = RenderPipelineReflection*;
    using NewLibraryCompletionHandler                           = void (^)(MTL::Library*, NS::Error*);
    using NewLibraryCompletionHandlerFunction                   = std::function<void(Library*, NS::Error*)>;
    using NewRenderPipelineStateCompletionHandler               = void (^)(MTL::RenderPipelineState*, NS::Error*);
    using NewRenderPipelineStateCompletionHandlerFunction       = std::function<void(RenderPipelineState*, NS::Error*)>;
    using NewRenderPipelineStateWithReflectionCompletionHandler = void (^)(MTL::RenderPipelineState*,
                                                                           RenderPipelineReflection*,
                                                                           NS::Error*);
    using NewRenderPipelineStateWithReflectionCompletionHandlerFunction =
        std::function<void(RenderPipelineState*, RenderPipelineReflection*, NS::Error*)>;
    using NewComputePipelineStateCompletionHandler         = void (^)(MTL::ComputePipelineState*, NS::Error*);
    using NewComputePipelineStateCompletionHandlerFunction = std::function<void(ComputePipelineState*, NS::Error*)>;
    using NewComputePipelineStateWithReflectionCompletionHandler = void (^)(MTL::ComputePipelineState*,
                                                                            ComputePipelineReflection*,
                                                                            NS::Error*);
    using NewComputePipelineStateWithReflectionCompletionHandlerFunction =
        std::function<void(ComputePipelineState*, ComputePipelineReflection*, NS::Error*)>;
    using Timestamp = std::uint64_t;

    _MTL_CONST(DeviceNotificationName, DeviceWasAddedNotification);
    _MTL_CONST(DeviceNotificationName, DeviceRemovalRequestedNotification);
    _MTL_CONST(DeviceNotificationName, DeviceWasRemovedNotification);
    _MTL_CONST(NS::ErrorUserInfoKey, CommandBufferEncoderInfoErrorKey);
    [[nodiscard]] Device*    CreateSystemDefaultDevice();
    [[nodiscard]] NS::Array* CopyAllDevices();
    [[nodiscard]] NS::Array* CopyAllDevicesWithObserver(NS::Object**                   pOutObserver,
                                                        DeviceNotificationHandlerBlock handler);
    [[nodiscard]] NS::Array* CopyAllDevicesWithObserver(NS::Object**                             pOutObserver,
                                                        const DeviceNotificationHandlerFunction& handler);
    void                     RemoveDeviceObserver(const NS::Object* pObserver);

    /// @see https://developer.apple.com/documentation/metal/mtlaccelerationstructuresizes?language=objc
    struct AccelerationStructureSizes
    {
        NS::UInteger accelerationStructureSize;
        NS::UInteger buildScratchBufferSize;
        NS::UInteger refitScratchBufferSize;
    } _MTL_PACKED;

    /// @see https://developer.apple.com/documentation/metal/mtlsizeandalign?language=objc
    struct SizeAndAlign
    {
        NS::UInteger size;
        NS::UInteger align;
    } _MTL_PACKED;

    /// @see https://developer.apple.com/documentation/metal/mtlargumentdescriptor?language=objc
    class ArgumentDescriptor : public NS::Copying<ArgumentDescriptor>
    {
    public:
        [[nodiscard]] BindingAccess access() const;

        [[nodiscard]] static ArgumentDescriptor* alloc();

        [[nodiscard]] static ArgumentDescriptor* argumentDescriptor();

        [[nodiscard]] NS::UInteger arrayLength() const;

        [[nodiscard]] NS::UInteger constantBlockAlignment() const;

        [[nodiscard]] DataType dataType() const;

        [[nodiscard]] NS::UInteger index() const;

        [[nodiscard]] ArgumentDescriptor* init();

        void setAccess(BindingAccess access) const;

        void setArrayLength(NS::UInteger arrayLength) const;

        void setConstantBlockAlignment(NS::UInteger constantBlockAlignment) const;

        void setDataType(DataType dataType) const;

        void setIndex(NS::UInteger index) const;

        void                      setTextureType(TextureType textureType) const;
        [[nodiscard]] TextureType textureType() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlarchitecture?language=objc
    class Architecture : public NS::Copying<Architecture>
    {
    public:
        [[nodiscard]] static Architecture* alloc();

        [[nodiscard]] Architecture* init();

        [[nodiscard]] NS::String* name() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtldevice?language=objc
    class Device : public NS::Referencing<Device>
    {
    public:
        [[nodiscard]] AccelerationStructureSizes accelerationStructureSizes(
            const AccelerationStructureDescriptor* descriptor) const;

        [[nodiscard]] Architecture* architecture() const;

        [[nodiscard]] bool areBarycentricCoordsSupported() const;

        [[nodiscard]] bool areProgrammableSamplePositionsSupported() const;

        [[nodiscard]] bool areRasterOrderGroupsSupported() const;

        [[nodiscard]] ArgumentBuffersTier argumentBuffersSupport() const;

        [[deprecated("please use areBarycentricCoordsSupported instead")]] [[nodiscard]] bool
        barycentricCoordsSupported() const;

        void convertSparsePixelRegions(const Region*                    pixelRegions,
                                       Region*                          tileRegions,
                                       const Size&                      tileSize,
                                       SparseTextureRegionAlignmentMode mode,
                                       NS::UInteger                     numRegions) const;

        void convertSparseTileRegions(const Region* tileRegions,
                                      Region*       pixelRegions,
                                      const Size&   tileSize,
                                      NS::UInteger  numRegions) const;

        [[nodiscard]] NS::Array* counterSets() const;

        [[nodiscard]] NS::UInteger currentAllocatedSize() const;

        [[deprecated("please use isDepth24Stencil8PixelFormatSupported instead")]] [[nodiscard]] bool
        depth24Stencil8PixelFormatSupported() const;

        [[nodiscard]] FunctionHandle* functionHandle(const Function* function) const;
        [[nodiscard]] FunctionHandle* functionHandle(const MTL4::BinaryFunction* function) const;

        void getDefaultSamplePositions(SamplePosition* positions, NS::UInteger count) const;

        [[nodiscard]] bool hasUnifiedMemory() const;

        [[deprecated("please use isHeadless instead")]] [[nodiscard]] bool headless() const;

        [[nodiscard]] SizeAndAlign heapAccelerationStructureSizeAndAlign(NS::UInteger size) const;
        [[nodiscard]] SizeAndAlign heapAccelerationStructureSizeAndAlign(
            const AccelerationStructureDescriptor* descriptor) const;

        [[nodiscard]] SizeAndAlign heapBufferSizeAndAlign(NS::UInteger length, ResourceOptions options) const;

        [[nodiscard]] SizeAndAlign heapTextureSizeAndAlign(const TextureDescriptor* desc) const;

        [[nodiscard]] bool isDepth24Stencil8PixelFormatSupported() const;

        [[nodiscard]] bool isHeadless() const;

        [[nodiscard]] bool isLowPower() const;

        [[nodiscard]] bool isRemovable() const;

        [[nodiscard]] DeviceLocation location() const;
        [[nodiscard]] NS::UInteger   locationNumber() const;

        [[deprecated("please use isLowPower instead")]] [[nodiscard]] bool lowPower() const;

        [[nodiscard]] NS::UInteger maxArgumentBufferSamplerCount() const;

        [[nodiscard]] NS::UInteger maxBufferLength() const;

        [[nodiscard]] NS::UInteger maxThreadgroupMemoryLength() const;

        [[nodiscard]] Size maxThreadsPerThreadgroup() const;

        [[nodiscard]] uint64_t maxTransferRate() const;

        [[nodiscard]] NS::UInteger maximumConcurrentCompilationTaskCount() const;

        [[nodiscard]] NS::UInteger minimumLinearTextureAlignmentForPixelFormat(PixelFormat format) const;

        [[nodiscard]] NS::UInteger minimumTextureBufferAlignmentForPixelFormat(PixelFormat format) const;

        [[nodiscard]] NS::String* name() const;

        [[nodiscard]] AccelerationStructure* newAccelerationStructure(NS::UInteger size) const;
        [[nodiscard]] AccelerationStructure* newAccelerationStructure(
            const AccelerationStructureDescriptor* descriptor) const;

        [[nodiscard]] MTL4::Archive* newArchive(const NS::URL* url, NS::Error** error) const;

        [[nodiscard]] ArgumentEncoder* newArgumentEncoder(const NS::Array* arguments) const;
        [[nodiscard]] ArgumentEncoder* newArgumentEncoder(const BufferBinding* bufferBinding) const;

        [[nodiscard]] MTL4::ArgumentTable* newArgumentTable(const MTL4::ArgumentTableDescriptor* descriptor,
                                                            NS::Error**                          error) const;

        [[nodiscard]] BinaryArchive* newBinaryArchive(const BinaryArchiveDescriptor* descriptor,
                                                      NS::Error**                    error) const;

        [[nodiscard]] Buffer* newBuffer(NS::UInteger length, ResourceOptions options) const;
        [[nodiscard]] Buffer* newBuffer(const void* pointer, NS::UInteger length, ResourceOptions options) const;
        [[nodiscard]] Buffer* newBuffer(const void*     pointer,
                                        NS::UInteger    length,
                                        ResourceOptions options,
                                        void (^deallocator)(void*, NS::UInteger));
        [[nodiscard]] Buffer* newBuffer(NS::UInteger    length,
                                        ResourceOptions options,
                                        SparsePageSize  placementSparsePageSize) const;

        [[nodiscard]] MTL4::CommandAllocator* newCommandAllocator() const;
        [[nodiscard]] MTL4::CommandAllocator* newCommandAllocator(const MTL4::CommandAllocatorDescriptor* descriptor,
                                                                  NS::Error**                             error) const;

        [[nodiscard]] MTL4::CommandBuffer* newCommandBuffer() const;

        [[nodiscard]] CommandQueue* newCommandQueue() const;
        [[nodiscard]] CommandQueue* newCommandQueue(NS::UInteger maxCommandBufferCount) const;
        [[nodiscard]] CommandQueue* newCommandQueue(const CommandQueueDescriptor* descriptor) const;

        [[nodiscard]] MTL4::Compiler* newCompiler(const MTL4::CompilerDescriptor* descriptor, NS::Error** error) const;

        [[nodiscard]] ComputePipelineState* newComputePipelineState(const Function* computeFunction,
                                                                    NS::Error**     error) const;
        [[nodiscard]] ComputePipelineState* newComputePipelineState(
            const Function*                              computeFunction,
            PipelineOption                               options,
            const AutoreleasedComputePipelineReflection* reflection,
            NS::Error**                                  error) const;
        void                                newComputePipelineState(const Function*                          computeFunction,
                                                                    NewComputePipelineStateCompletionHandler completionHandler);
        void                                newComputePipelineState(const Function*                                        computeFunction,
                                                                    PipelineOption                                         options,
                                                                    NewComputePipelineStateWithReflectionCompletionHandler completionHandler);
        [[nodiscard]] ComputePipelineState* newComputePipelineState(
            const ComputePipelineDescriptor*             descriptor,
            PipelineOption                               options,
            const AutoreleasedComputePipelineReflection* reflection,
            NS::Error**                                  error) const;
        void newComputePipelineState(const ComputePipelineDescriptor*                       descriptor,
                                     PipelineOption                                         options,
                                     NewComputePipelineStateWithReflectionCompletionHandler completionHandler);
        void newComputePipelineState(const Function*                                         pFunction,
                                     const NewComputePipelineStateCompletionHandlerFunction& completionHandler);
        void newComputePipelineState(
            const Function*                                                       pFunction,
            PipelineOption                                                        options,
            const NewComputePipelineStateWithReflectionCompletionHandlerFunction& completionHandler);
        void newComputePipelineState(
            const ComputePipelineDescriptor*                                      pDescriptor,
            PipelineOption                                                        options,
            const NewComputePipelineStateWithReflectionCompletionHandlerFunction& completionHandler);

        [[nodiscard]] MTL4::CounterHeap* newCounterHeap(const MTL4::CounterHeapDescriptor* descriptor,
                                                        NS::Error**                        error) const;

        [[nodiscard]] CounterSampleBuffer* newCounterSampleBuffer(const CounterSampleBufferDescriptor* descriptor,
                                                                  NS::Error**                          error) const;

        [[nodiscard]] Library* newDefaultLibrary() const;
        [[nodiscard]] Library* newDefaultLibrary(const NS::Bundle* bundle, NS::Error** error) const;

        [[nodiscard]] DepthStencilState* newDepthStencilState(const DepthStencilDescriptor* descriptor) const;

        [[nodiscard]] DynamicLibrary* newDynamicLibrary(const Library* library, NS::Error** error) const;
        [[nodiscard]] DynamicLibrary* newDynamicLibrary(const NS::URL* url, NS::Error** error) const;

        [[nodiscard]] Event* newEvent() const;

        [[nodiscard]] Fence* newFence() const;

        [[nodiscard]] Heap* newHeap(const HeapDescriptor* descriptor) const;

        [[nodiscard]] IOCommandQueue* newIOCommandQueue(const IOCommandQueueDescriptor* descriptor,
                                                        NS::Error**                     error) const;

        [[nodiscard]] IOFileHandle* newIOFileHandle(const NS::URL* url, NS::Error** error) const;
        [[nodiscard]] IOFileHandle* newIOFileHandle(const NS::URL*      url,
                                                    IOCompressionMethod compressionMethod,
                                                    NS::Error**         error) const;

        [[nodiscard]] IOFileHandle* newIOHandle(const NS::URL* url, NS::Error** error) const;
        [[nodiscard]] IOFileHandle* newIOHandle(const NS::URL*      url,
                                                IOCompressionMethod compressionMethod,
                                                NS::Error**         error) const;

        [[nodiscard]] IndirectCommandBuffer* newIndirectCommandBuffer(const IndirectCommandBufferDescriptor* descriptor,
                                                                      NS::UInteger                           maxCount,
                                                                      ResourceOptions options) const;

        [[nodiscard]] Library* newLibrary(const NS::String* filepath, NS::Error** error) const;
        [[nodiscard]] Library* newLibrary(const NS::URL* url, NS::Error** error) const;
        [[nodiscard]] Library* newLibrary(dispatch_data_t data, NS::Error** error) const;
        [[nodiscard]] Library* newLibrary(const NS::String*     source,
                                          const CompileOptions* options,
                                          NS::Error**           error) const;
        void                   newLibrary(const NS::String*           source,
                                          const CompileOptions*       options,
                                          NewLibraryCompletionHandler completionHandler);
        [[nodiscard]] Library* newLibrary(const StitchedLibraryDescriptor* descriptor, NS::Error** error) const;
        void newLibrary(const StitchedLibraryDescriptor* descriptor, NewLibraryCompletionHandler completionHandler);
        void newLibrary(const NS::String*                          pSource,
                        const CompileOptions*                      pOptions,
                        const NewLibraryCompletionHandlerFunction& completionHandler);
        void newLibrary(const StitchedLibraryDescriptor*           pDescriptor,
                        const NewLibraryCompletionHandlerFunction& completionHandler);

        [[nodiscard]] LogState* newLogState(const LogStateDescriptor* descriptor, NS::Error** error) const;

        [[nodiscard]] MTL4::CommandQueue* newMTL4CommandQueue() const;
        [[nodiscard]] MTL4::CommandQueue* newMTL4CommandQueue(const MTL4::CommandQueueDescriptor* descriptor,
                                                              NS::Error**                         error) const;

        [[nodiscard]] MTL4::PipelineDataSetSerializer* newPipelineDataSetSerializer(
            const MTL4::PipelineDataSetSerializerDescriptor* descriptor) const;

        [[nodiscard]] RasterizationRateMap* newRasterizationRateMap(
            const RasterizationRateMapDescriptor* descriptor) const;

        [[nodiscard]] RenderPipelineState* newRenderPipelineState(const RenderPipelineDescriptor* descriptor,
                                                                  NS::Error**                     error) const;
        [[nodiscard]] RenderPipelineState* newRenderPipelineState(
            const RenderPipelineDescriptor*             descriptor,
            PipelineOption                              options,
            const AutoreleasedRenderPipelineReflection* reflection,
            NS::Error**                                 error) const;
        void                               newRenderPipelineState(const RenderPipelineDescriptor*         descriptor,
                                                                  NewRenderPipelineStateCompletionHandler completionHandler);
        void                               newRenderPipelineState(const RenderPipelineDescriptor*                       descriptor,
                                                                  PipelineOption                                        options,
                                                                  NewRenderPipelineStateWithReflectionCompletionHandler completionHandler);
        [[nodiscard]] RenderPipelineState* newRenderPipelineState(
            const TileRenderPipelineDescriptor*         descriptor,
            PipelineOption                              options,
            const AutoreleasedRenderPipelineReflection* reflection,
            NS::Error**                                 error) const;
        void                               newRenderPipelineState(const TileRenderPipelineDescriptor*                   descriptor,
                                                                  PipelineOption                                        options,
                                                                  NewRenderPipelineStateWithReflectionCompletionHandler completionHandler);
        [[nodiscard]] RenderPipelineState* newRenderPipelineState(
            const MeshRenderPipelineDescriptor*         descriptor,
            PipelineOption                              options,
            const AutoreleasedRenderPipelineReflection* reflection,
            NS::Error**                                 error) const;
        void newRenderPipelineState(const MeshRenderPipelineDescriptor*                   descriptor,
                                    PipelineOption                                        options,
                                    NewRenderPipelineStateWithReflectionCompletionHandler completionHandler);
        void newRenderPipelineState(const RenderPipelineDescriptor*                        pDescriptor,
                                    const NewRenderPipelineStateCompletionHandlerFunction& completionHandler);
        void newRenderPipelineState(
            const RenderPipelineDescriptor*                                      pDescriptor,
            PipelineOption                                                       options,
            const NewRenderPipelineStateWithReflectionCompletionHandlerFunction& completionHandler);
        void newRenderPipelineState(
            const TileRenderPipelineDescriptor*                                  pDescriptor,
            PipelineOption                                                       options,
            const NewRenderPipelineStateWithReflectionCompletionHandlerFunction& completionHandler);

        [[nodiscard]] ResidencySet* newResidencySet(const ResidencySetDescriptor* desc, NS::Error** error) const;

        [[nodiscard]] SamplerState* newSamplerState(const SamplerDescriptor* descriptor) const;

        [[nodiscard]] SharedEvent* newSharedEvent() const;
        [[nodiscard]] SharedEvent* newSharedEvent(const SharedEventHandle* sharedEventHandle) const;

        [[nodiscard]] Texture* newSharedTexture(const TextureDescriptor* descriptor) const;
        [[nodiscard]] Texture* newSharedTexture(const SharedTextureHandle* sharedHandle) const;

        [[nodiscard]] Tensor* newTensor(const TensorDescriptor* descriptor, NS::Error** error) const;

        [[nodiscard]] Texture*         newTexture(const TextureDescriptor* descriptor) const;
        [[nodiscard]] Texture*         newTexture(const TextureDescriptor* descriptor,
                                                  IOSurfaceRef             iosurface,
                                                  NS::UInteger             plane) const;
        [[nodiscard]] TextureViewPool* newTextureViewPool(const ResourceViewPoolDescriptor* descriptor,
                                                          NS::Error**                       error) const;

        [[nodiscard]] uint32_t peerCount() const;

        [[nodiscard]] uint64_t peerGroupID() const;

        [[nodiscard]] uint32_t peerIndex() const;

        [[deprecated("please use areProgrammableSamplePositionsSupported instead")]] [[nodiscard]] bool
        programmableSamplePositionsSupported() const;

        [[nodiscard]] uint64_t queryTimestampFrequency() const;

        [[deprecated("please use areRasterOrderGroupsSupported instead")]] [[nodiscard]] bool
        rasterOrderGroupsSupported() const;

        [[nodiscard]] ReadWriteTextureTier readWriteTextureSupport() const;

        [[nodiscard]] uint64_t recommendedMaxWorkingSetSize() const;

        [[nodiscard]] uint64_t registryID() const;

        [[deprecated("please use isRemovable instead")]] [[nodiscard]] bool removable() const;

        void sampleTimestamps(Timestamp* cpuTimestamp, Timestamp* gpuTimestamp) const;

        void               setShouldMaximizeConcurrentCompilation(bool shouldMaximizeConcurrentCompilation) const;
        [[nodiscard]] bool shouldMaximizeConcurrentCompilation() const;

        [[nodiscard]] NS::UInteger sizeOfCounterHeapEntry(MTL4::CounterHeapType type) const;

        [[nodiscard]] Size         sparseTileSize(TextureType  textureType,
                                                  PixelFormat  pixelFormat,
                                                  NS::UInteger sampleCount) const;
        [[nodiscard]] Size         sparseTileSize(TextureType    textureType,
                                                  PixelFormat    pixelFormat,
                                                  NS::UInteger   sampleCount,
                                                  SparsePageSize sparsePageSize) const;
        [[nodiscard]] NS::UInteger sparseTileSizeInBytes() const;
        [[nodiscard]] NS::UInteger sparseTileSizeInBytes(SparsePageSize sparsePageSize) const;

        [[nodiscard]] bool supports32BitFloatFiltering() const;

        [[nodiscard]] bool supports32BitMSAA() const;

        [[nodiscard]] bool supportsBCTextureCompression() const;

        [[nodiscard]] bool supportsCounterSampling(CounterSamplingPoint samplingPoint) const;

        [[nodiscard]] bool supportsDynamicLibraries() const;

        [[nodiscard]] bool supportsFamily(GPUFamily gpuFamily) const;

        [[nodiscard]] bool supportsFeatureSet(FeatureSet featureSet) const;

        [[nodiscard]] bool supportsFunctionPointers() const;
        [[nodiscard]] bool supportsFunctionPointersFromRender() const;

        [[nodiscard]] bool supportsPrimitiveMotionBlur() const;

        [[nodiscard]] bool supportsPullModelInterpolation() const;

        [[nodiscard]] bool supportsQueryTextureLOD() const;

        [[nodiscard]] bool supportsRasterizationRateMap(NS::UInteger layerCount) const;

        [[nodiscard]] bool supportsRaytracing() const;
        [[nodiscard]] bool supportsRaytracingFromRender() const;

        [[nodiscard]] bool supportsRenderDynamicLibraries() const;

        [[nodiscard]] bool supportsShaderBarycentricCoordinates() const;

        [[nodiscard]] bool supportsTextureSampleCount(NS::UInteger sampleCount) const;

        [[nodiscard]] bool supportsVertexAmplificationCount(NS::UInteger count) const;

        [[nodiscard]] SizeAndAlign tensorSizeAndAlign(const TensorDescriptor* descriptor) const;
    };

} // namespace MTL

#if defined(MTL_PRIVATE_IMPLEMENTATION)
extern "C" MTL::Device* MTLCreateSystemDefaultDevice();
extern "C" NS::Array*   MTLCopyAllDevices();
extern "C" NS::Array*   MTLCopyAllDevicesWithObserver(NS::Object**, MTL::DeviceNotificationHandlerBlock);
extern "C" void         MTLRemoveDeviceObserver(const NS::Object*);
_MTL_PRIVATE_DEF_WEAK_CONST(MTL::DeviceNotificationName, DeviceWasAddedNotification);
_MTL_PRIVATE_DEF_WEAK_CONST(MTL::DeviceNotificationName, DeviceRemovalRequestedNotification);
_MTL_PRIVATE_DEF_WEAK_CONST(MTL::DeviceNotificationName, DeviceWasRemovedNotification);
_MTL_PRIVATE_DEF_CONST(NS::ErrorUserInfoKey, CommandBufferEncoderInfoErrorKey);
_NS_EXPORT MTL::Device* MTL::CreateSystemDefaultDevice() { return ::MTLCreateSystemDefaultDevice(); }

_NS_EXPORT NS::Array* MTL::CopyAllDevices()
{
#if (__IPHONE_OS_VERSION_MIN_REQUIRED >= 180000) || (__MAC_OS_X_VERSION_MIN_REQUIRED >= 101100)
    return ::MTLCopyAllDevices();
#else
    return nullptr;
#endif
}

_NS_EXPORT NS::Array* MTL::CopyAllDevicesWithObserver(NS::Object**                        pOutObserver,
                                                      MTL::DeviceNotificationHandlerBlock handler)
{
#if TARGET_OS_OSX
    return ::MTLCopyAllDevicesWithObserver(pOutObserver, handler);
#else
    (void)pOutObserver;
    (void)handler;
    return nullptr;
#endif // TARGET_OS_OSX
}

_NS_EXPORT NS::Array* MTL::CopyAllDevicesWithObserver(NS::Object**                                  pOutObserver,
                                                      const MTL::DeviceNotificationHandlerFunction& handler)
{
    __block DeviceNotificationHandlerFunction function = handler;
    return CopyAllDevicesWithObserver(pOutObserver, ^(Device* pDevice, DeviceNotificationName pNotificationName) {
      function(pDevice, pNotificationName);
    });
}

_NS_EXPORT void MTL::RemoveDeviceObserver(const NS::Object* pObserver)
{
    (void)pObserver;
#if TARGET_OS_OSX
    ::MTLRemoveDeviceObserver(pObserver);
#endif // TARGET_OS_OSX
}

#endif // MTL_PRIVATE_IMPLEMENTATION

_MTL_INLINE MTL::BindingAccess MTL::ArgumentDescriptor::access() const
{
    return sendMessage<BindingAccess>(this, _MTL_PRIVATE_SEL(access));
}

_MTL_INLINE MTL::ArgumentDescriptor* MTL::ArgumentDescriptor::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<ArgumentDescriptor>(_MTL_PRIVATE_CLS(MTLArgumentDescriptor));
}

_MTL_INLINE MTL::ArgumentDescriptor* MTL::ArgumentDescriptor::argumentDescriptor()
{
    return sendMessage<ArgumentDescriptor*>(_MTL_PRIVATE_CLS(MTLArgumentDescriptor),
                                            _MTL_PRIVATE_SEL(argumentDescriptor));
}

_MTL_INLINE NS::UInteger MTL::ArgumentDescriptor::arrayLength() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(arrayLength));
}

_MTL_INLINE NS::UInteger MTL::ArgumentDescriptor::constantBlockAlignment() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(constantBlockAlignment));
}

_MTL_INLINE MTL::DataType MTL::ArgumentDescriptor::dataType() const
{
    return sendMessage<DataType>(this, _MTL_PRIVATE_SEL(dataType));
}

_MTL_INLINE NS::UInteger MTL::ArgumentDescriptor::index() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(index));
}

_MTL_INLINE MTL::ArgumentDescriptor* MTL::ArgumentDescriptor::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<ArgumentDescriptor>();
}

_MTL_INLINE void MTL::ArgumentDescriptor::setAccess(const BindingAccess access) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setAccess_), access);
}

_MTL_INLINE void MTL::ArgumentDescriptor::setArrayLength(const NS::UInteger arrayLength) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setArrayLength_), arrayLength);
}

_MTL_INLINE void MTL::ArgumentDescriptor::setConstantBlockAlignment(const NS::UInteger constantBlockAlignment) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setConstantBlockAlignment_), constantBlockAlignment);
}

_MTL_INLINE void MTL::ArgumentDescriptor::setDataType(const DataType dataType) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setDataType_), dataType);
}

_MTL_INLINE void MTL::ArgumentDescriptor::setIndex(const NS::UInteger index) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setIndex_), index);
}

_MTL_INLINE void MTL::ArgumentDescriptor::setTextureType(const TextureType textureType) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(setTextureType_), textureType);
}

_MTL_INLINE MTL::TextureType MTL::ArgumentDescriptor::textureType() const
{
    return sendMessage<TextureType>(this, _MTL_PRIVATE_SEL(textureType));
}

_MTL_INLINE MTL::Architecture* MTL::Architecture::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<Architecture>(_MTL_PRIVATE_CLS(MTLArchitecture));
}

_MTL_INLINE MTL::Architecture* MTL::Architecture::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<Architecture>();
}

_MTL_INLINE NS::String* MTL::Architecture::name() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(name));
}

_MTL_INLINE MTL::AccelerationStructureSizes MTL::Device::accelerationStructureSizes(
    const AccelerationStructureDescriptor* descriptor) const
{
    return sendMessage<AccelerationStructureSizes>(
        this, _MTL_PRIVATE_SEL(accelerationStructureSizesWithDescriptor_), descriptor);
}

_MTL_INLINE MTL::Architecture* MTL::Device::architecture() const
{
    return sendMessage<Architecture*>(this, _MTL_PRIVATE_SEL(architecture));
}

_MTL_INLINE bool MTL::Device::areBarycentricCoordsSupported() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(areBarycentricCoordsSupported));
}

_MTL_INLINE bool MTL::Device::areProgrammableSamplePositionsSupported() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(areProgrammableSamplePositionsSupported));
}

_MTL_INLINE bool MTL::Device::areRasterOrderGroupsSupported() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(areRasterOrderGroupsSupported));
}

_MTL_INLINE MTL::ArgumentBuffersTier MTL::Device::argumentBuffersSupport() const
{
    return sendMessage<ArgumentBuffersTier>(this, _MTL_PRIVATE_SEL(argumentBuffersSupport));
}

_MTL_INLINE bool MTL::Device::barycentricCoordsSupported() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(areBarycentricCoordsSupported));
}

_MTL_INLINE void MTL::Device::convertSparsePixelRegions(const Region*                          pixelRegions,
                                                        Region*                                tileRegions,
                                                        const Size&                            tileSize,
                                                        const SparseTextureRegionAlignmentMode mode,
                                                        const NS::UInteger                     numRegions) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(convertSparsePixelRegions_toTileRegions_withTileSize_alignmentMode_numRegions_),
                      pixelRegions,
                      tileRegions,
                      tileSize,
                      mode,
                      numRegions);
}

_MTL_INLINE void MTL::Device::convertSparseTileRegions(const Region*      tileRegions,
                                                       Region*            pixelRegions,
                                                       const Size&        tileSize,
                                                       const NS::UInteger numRegions) const
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(convertSparseTileRegions_toPixelRegions_withTileSize_numRegions_),
                      tileRegions,
                      pixelRegions,
                      tileSize,
                      numRegions);
}

_MTL_INLINE NS::Array* MTL::Device::counterSets() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(counterSets));
}

_MTL_INLINE NS::UInteger MTL::Device::currentAllocatedSize() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(currentAllocatedSize));
}

_MTL_INLINE bool MTL::Device::depth24Stencil8PixelFormatSupported() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(isDepth24Stencil8PixelFormatSupported));
}

_MTL_INLINE MTL::FunctionHandle* MTL::Device::functionHandle(const Function* function) const
{
    return sendMessage<FunctionHandle*>(this, _MTL_PRIVATE_SEL(functionHandleWithFunction_), function);
}

_MTL_INLINE MTL::FunctionHandle* MTL::Device::functionHandle(const MTL4::BinaryFunction* function) const
{
    return sendMessage<FunctionHandle*>(this, _MTL_PRIVATE_SEL(functionHandleWithBinaryFunction_), function);
}

_MTL_INLINE void MTL::Device::getDefaultSamplePositions(SamplePosition* positions, const NS::UInteger count) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(getDefaultSamplePositions_count_), positions, count);
}

_MTL_INLINE bool MTL::Device::hasUnifiedMemory() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(hasUnifiedMemory));
}

_MTL_INLINE bool MTL::Device::headless() const { return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isHeadless)); }

_MTL_INLINE MTL::SizeAndAlign MTL::Device::heapAccelerationStructureSizeAndAlign(const NS::UInteger size) const
{
    return sendMessage<SizeAndAlign>(this, _MTL_PRIVATE_SEL(heapAccelerationStructureSizeAndAlignWithSize_), size);
}

_MTL_INLINE MTL::SizeAndAlign MTL::Device::heapAccelerationStructureSizeAndAlign(
    const AccelerationStructureDescriptor* descriptor) const
{
    return sendMessage<SizeAndAlign>(
        this, _MTL_PRIVATE_SEL(heapAccelerationStructureSizeAndAlignWithDescriptor_), descriptor);
}

_MTL_INLINE MTL::SizeAndAlign MTL::Device::heapBufferSizeAndAlign(const NS::UInteger    length,
                                                                  const ResourceOptions options) const
{
    return sendMessage<SizeAndAlign>(
        this, _MTL_PRIVATE_SEL(heapBufferSizeAndAlignWithLength_options_), length, options);
}

_MTL_INLINE MTL::SizeAndAlign MTL::Device::heapTextureSizeAndAlign(const TextureDescriptor* desc) const
{
    return sendMessage<SizeAndAlign>(this, _MTL_PRIVATE_SEL(heapTextureSizeAndAlignWithDescriptor_), desc);
}

_MTL_INLINE bool MTL::Device::isDepth24Stencil8PixelFormatSupported() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(isDepth24Stencil8PixelFormatSupported));
}

_MTL_INLINE bool MTL::Device::isHeadless() const { return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isHeadless)); }

_MTL_INLINE bool MTL::Device::isLowPower() const { return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isLowPower)); }

_MTL_INLINE bool MTL::Device::isRemovable() const { return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isRemovable)); }

_MTL_INLINE MTL::DeviceLocation MTL::Device::location() const
{
    return sendMessage<DeviceLocation>(this, _MTL_PRIVATE_SEL(location));
}

_MTL_INLINE NS::UInteger MTL::Device::locationNumber() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(locationNumber));
}

_MTL_INLINE bool MTL::Device::lowPower() const { return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isLowPower)); }

_MTL_INLINE NS::UInteger MTL::Device::maxArgumentBufferSamplerCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxArgumentBufferSamplerCount));
}

_MTL_INLINE NS::UInteger MTL::Device::maxBufferLength() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxBufferLength));
}

_MTL_INLINE NS::UInteger MTL::Device::maxThreadgroupMemoryLength() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maxThreadgroupMemoryLength));
}

_MTL_INLINE MTL::Size MTL::Device::maxThreadsPerThreadgroup() const
{
    return sendMessage<Size>(this, _MTL_PRIVATE_SEL(maxThreadsPerThreadgroup));
}

_MTL_INLINE uint64_t MTL::Device::maxTransferRate() const
{
    return sendMessage<uint64_t>(this, _MTL_PRIVATE_SEL(maxTransferRate));
}

_MTL_INLINE NS::UInteger MTL::Device::maximumConcurrentCompilationTaskCount() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(maximumConcurrentCompilationTaskCount));
}

_MTL_INLINE NS::UInteger MTL::Device::minimumLinearTextureAlignmentForPixelFormat(const PixelFormat format) const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(minimumLinearTextureAlignmentForPixelFormat_), format);
}

_MTL_INLINE NS::UInteger MTL::Device::minimumTextureBufferAlignmentForPixelFormat(const PixelFormat format) const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(minimumTextureBufferAlignmentForPixelFormat_), format);
}

_MTL_INLINE NS::String* MTL::Device::name() const { return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(name)); }

_MTL_INLINE MTL::AccelerationStructure* MTL::Device::newAccelerationStructure(const NS::UInteger size) const
{
    return sendMessage<AccelerationStructure*>(this, _MTL_PRIVATE_SEL(newAccelerationStructureWithSize_), size);
}

_MTL_INLINE MTL::AccelerationStructure* MTL::Device::newAccelerationStructure(
    const AccelerationStructureDescriptor* descriptor) const
{
    return sendMessage<AccelerationStructure*>(
        this, _MTL_PRIVATE_SEL(newAccelerationStructureWithDescriptor_), descriptor);
}

_MTL_INLINE MTL4::Archive* MTL::Device::newArchive(const NS::URL* url, NS::Error** error) const
{
    return sendMessage<MTL4::Archive*>(this, _MTL_PRIVATE_SEL(newArchiveWithURL_error_), url, error);
}

_MTL_INLINE MTL::ArgumentEncoder* MTL::Device::newArgumentEncoder(const NS::Array* arguments) const
{
    return sendMessage<ArgumentEncoder*>(this, _MTL_PRIVATE_SEL(newArgumentEncoderWithArguments_), arguments);
}

_MTL_INLINE MTL::ArgumentEncoder* MTL::Device::newArgumentEncoder(const BufferBinding* bufferBinding) const
{
    return sendMessage<ArgumentEncoder*>(this, _MTL_PRIVATE_SEL(newArgumentEncoderWithBufferBinding_), bufferBinding);
}

_MTL_INLINE MTL4::ArgumentTable* MTL::Device::newArgumentTable(const MTL4::ArgumentTableDescriptor* descriptor,
                                                               NS::Error**                          error) const
{
    return sendMessage<MTL4::ArgumentTable*>(
        this, _MTL_PRIVATE_SEL(newArgumentTableWithDescriptor_error_), descriptor, error);
}

_MTL_INLINE MTL::BinaryArchive* MTL::Device::newBinaryArchive(const BinaryArchiveDescriptor* descriptor,
                                                              NS::Error**                    error) const
{
    return sendMessage<BinaryArchive*>(
        this, _MTL_PRIVATE_SEL(newBinaryArchiveWithDescriptor_error_), descriptor, error);
}

_MTL_INLINE MTL::Buffer* MTL::Device::newBuffer(const NS::UInteger length, const ResourceOptions options) const
{
    return sendMessage<Buffer*>(this, _MTL_PRIVATE_SEL(newBufferWithLength_options_), length, options);
}

_MTL_INLINE MTL::Buffer* MTL::Device::newBuffer(const void*           pointer,
                                                const NS::UInteger    length,
                                                const ResourceOptions options) const
{
    return sendMessage<Buffer*>(this, _MTL_PRIVATE_SEL(newBufferWithBytes_length_options_), pointer, length, options);
}

_MTL_INLINE MTL::Buffer* MTL::Device::newBuffer(const void*     pointer,
                                                NS::UInteger    length,
                                                ResourceOptions options,
                                                void (^deallocator)(void*, NS::UInteger))
{
    return Object::sendMessage<MTL::Buffer*>(this,
                                             _MTL_PRIVATE_SEL(newBufferWithBytesNoCopy_length_options_deallocator_),
                                             pointer,
                                             length,
                                             options,
                                             deallocator);
}

_MTL_INLINE MTL::Buffer* MTL::Device::newBuffer(const NS::UInteger    length,
                                                const ResourceOptions options,
                                                const SparsePageSize  placementSparsePageSize) const
{
    return sendMessage<Buffer*>(this,
                                _MTL_PRIVATE_SEL(newBufferWithLength_options_placementSparsePageSize_),
                                length,
                                options,
                                placementSparsePageSize);
}

_MTL_INLINE MTL4::CommandAllocator* MTL::Device::newCommandAllocator() const
{
    return sendMessage<MTL4::CommandAllocator*>(this, _MTL_PRIVATE_SEL(newCommandAllocator));
}

_MTL_INLINE MTL4::CommandAllocator* MTL::Device::newCommandAllocator(const MTL4::CommandAllocatorDescriptor* descriptor,
                                                                     NS::Error** error) const
{
    return sendMessage<MTL4::CommandAllocator*>(
        this, _MTL_PRIVATE_SEL(newCommandAllocatorWithDescriptor_error_), descriptor, error);
}

_MTL_INLINE MTL4::CommandBuffer* MTL::Device::newCommandBuffer() const
{
    return sendMessage<MTL4::CommandBuffer*>(this, _MTL_PRIVATE_SEL(newCommandBuffer));
}

_MTL_INLINE MTL::CommandQueue* MTL::Device::newCommandQueue() const
{
    return sendMessage<CommandQueue*>(this, _MTL_PRIVATE_SEL(newCommandQueue));
}

_MTL_INLINE MTL::CommandQueue* MTL::Device::newCommandQueue(const NS::UInteger maxCommandBufferCount) const
{
    return sendMessage<CommandQueue*>(
        this, _MTL_PRIVATE_SEL(newCommandQueueWithMaxCommandBufferCount_), maxCommandBufferCount);
}

_MTL_INLINE MTL::CommandQueue* MTL::Device::newCommandQueue(const CommandQueueDescriptor* descriptor) const
{
    return sendMessage<CommandQueue*>(this, _MTL_PRIVATE_SEL(newCommandQueueWithDescriptor_), descriptor);
}

_MTL_INLINE MTL4::Compiler* MTL::Device::newCompiler(const MTL4::CompilerDescriptor* descriptor,
                                                     NS::Error**                     error) const
{
    return sendMessage<MTL4::Compiler*>(this, _MTL_PRIVATE_SEL(newCompilerWithDescriptor_error_), descriptor, error);
}

_MTL_INLINE MTL::ComputePipelineState* MTL::Device::newComputePipelineState(const Function* computeFunction,
                                                                            NS::Error**     error) const
{
    return sendMessage<ComputePipelineState*>(
        this, _MTL_PRIVATE_SEL(newComputePipelineStateWithFunction_error_), computeFunction, error);
}

_MTL_INLINE MTL::ComputePipelineState* MTL::Device::newComputePipelineState(
    const Function*                              computeFunction,
    const PipelineOption                         options,
    const AutoreleasedComputePipelineReflection* reflection,
    NS::Error**                                  error) const
{
    return sendMessage<ComputePipelineState*>(
        this,
        _MTL_PRIVATE_SEL(newComputePipelineStateWithFunction_options_reflection_error_),
        computeFunction,
        options,
        reflection,
        error);
}

_MTL_INLINE void MTL::Device::newComputePipelineState(const Function*                                computeFunction,
                                                      const NewComputePipelineStateCompletionHandler completionHandler)
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(newComputePipelineStateWithFunction_completionHandler_),
                      computeFunction,
                      completionHandler);
}

_MTL_INLINE void MTL::Device::newComputePipelineState(
    const Function*                                              computeFunction,
    PipelineOption                                               options,
    const NewComputePipelineStateWithReflectionCompletionHandler completionHandler)
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(newComputePipelineStateWithFunction_options_completionHandler_),
                      computeFunction,
                      options,
                      completionHandler);
}

_MTL_INLINE MTL::ComputePipelineState* MTL::Device::newComputePipelineState(
    const ComputePipelineDescriptor*             descriptor,
    const PipelineOption                         options,
    const AutoreleasedComputePipelineReflection* reflection,
    NS::Error**                                  error) const
{
    return sendMessage<ComputePipelineState*>(
        this,
        _MTL_PRIVATE_SEL(newComputePipelineStateWithDescriptor_options_reflection_error_),
        descriptor,
        options,
        reflection,
        error);
}

_MTL_INLINE void MTL::Device::newComputePipelineState(
    const ComputePipelineDescriptor*                             descriptor,
    PipelineOption                                               options,
    const NewComputePipelineStateWithReflectionCompletionHandler completionHandler)
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(newComputePipelineStateWithDescriptor_options_completionHandler_),
                      descriptor,
                      options,
                      completionHandler);
}

_MTL_INLINE void MTL::Device::newComputePipelineState(
    const Function* pFunction, const NewComputePipelineStateCompletionHandlerFunction& completionHandler)
{
    __block NewComputePipelineStateCompletionHandlerFunction blockCompletionHandler = completionHandler;
    newComputePipelineState(pFunction, ^(ComputePipelineState* pPipelineState, NS::Error* pError) {
      blockCompletionHandler(pPipelineState, pError);
    });
}

_MTL_INLINE void MTL::Device::newComputePipelineState(
    const Function*                                                       pFunction,
    const PipelineOption                                                  options,
    const NewComputePipelineStateWithReflectionCompletionHandlerFunction& completionHandler)
{
    __block NewComputePipelineStateWithReflectionCompletionHandlerFunction blockCompletionHandler = completionHandler;
    newComputePipelineState(
        pFunction,
        options,
        ^(ComputePipelineState* pPipelineState, ComputePipelineReflection* pReflection, NS::Error* pError) {
          blockCompletionHandler(pPipelineState, pReflection, pError);
        });
}

_MTL_INLINE void MTL::Device::newComputePipelineState(
    const ComputePipelineDescriptor*                                      pDescriptor,
    const PipelineOption                                                  options,
    const NewComputePipelineStateWithReflectionCompletionHandlerFunction& completionHandler)
{
    __block NewComputePipelineStateWithReflectionCompletionHandlerFunction blockCompletionHandler = completionHandler;
    newComputePipelineState(
        pDescriptor,
        options,
        ^(ComputePipelineState* pPipelineState, ComputePipelineReflection* pReflection, NS::Error* pError) {
          blockCompletionHandler(pPipelineState, pReflection, pError);
        });
}

_MTL_INLINE MTL4::CounterHeap* MTL::Device::newCounterHeap(const MTL4::CounterHeapDescriptor* descriptor,
                                                           NS::Error**                        error) const
{
    return sendMessage<MTL4::CounterHeap*>(
        this, _MTL_PRIVATE_SEL(newCounterHeapWithDescriptor_error_), descriptor, error);
}

_MTL_INLINE MTL::CounterSampleBuffer* MTL::Device::newCounterSampleBuffer(
    const CounterSampleBufferDescriptor* descriptor, NS::Error** error) const
{
    return sendMessage<CounterSampleBuffer*>(
        this, _MTL_PRIVATE_SEL(newCounterSampleBufferWithDescriptor_error_), descriptor, error);
}

_MTL_INLINE MTL::Library* MTL::Device::newDefaultLibrary() const
{
    return sendMessage<Library*>(this, _MTL_PRIVATE_SEL(newDefaultLibrary));
}

_MTL_INLINE MTL::Library* MTL::Device::newDefaultLibrary(const NS::Bundle* bundle, NS::Error** error) const
{
    return sendMessage<Library*>(this, _MTL_PRIVATE_SEL(newDefaultLibraryWithBundle_error_), bundle, error);
}

_MTL_INLINE MTL::DepthStencilState* MTL::Device::newDepthStencilState(const DepthStencilDescriptor* descriptor) const
{
    return sendMessage<DepthStencilState*>(this, _MTL_PRIVATE_SEL(newDepthStencilStateWithDescriptor_), descriptor);
}

_MTL_INLINE MTL::DynamicLibrary* MTL::Device::newDynamicLibrary(const Library* library, NS::Error** error) const
{
    return sendMessage<DynamicLibrary*>(this, _MTL_PRIVATE_SEL(newDynamicLibrary_error_), library, error);
}

_MTL_INLINE MTL::DynamicLibrary* MTL::Device::newDynamicLibrary(const NS::URL* url, NS::Error** error) const
{
    return sendMessage<DynamicLibrary*>(this, _MTL_PRIVATE_SEL(newDynamicLibraryWithURL_error_), url, error);
}

_MTL_INLINE MTL::Event* MTL::Device::newEvent() const { return sendMessage<Event*>(this, _MTL_PRIVATE_SEL(newEvent)); }

_MTL_INLINE MTL::Fence* MTL::Device::newFence() const { return sendMessage<Fence*>(this, _MTL_PRIVATE_SEL(newFence)); }

_MTL_INLINE MTL::Heap* MTL::Device::newHeap(const HeapDescriptor* descriptor) const
{
    return sendMessage<Heap*>(this, _MTL_PRIVATE_SEL(newHeapWithDescriptor_), descriptor);
}

_MTL_INLINE MTL::IOCommandQueue* MTL::Device::newIOCommandQueue(const IOCommandQueueDescriptor* descriptor,
                                                                NS::Error**                     error) const
{
    return sendMessage<IOCommandQueue*>(
        this, _MTL_PRIVATE_SEL(newIOCommandQueueWithDescriptor_error_), descriptor, error);
}

_MTL_INLINE MTL::IOFileHandle* MTL::Device::newIOFileHandle(const NS::URL* url, NS::Error** error) const
{
    return sendMessage<IOFileHandle*>(this, _MTL_PRIVATE_SEL(newIOFileHandleWithURL_error_), url, error);
}

_MTL_INLINE MTL::IOFileHandle* MTL::Device::newIOFileHandle(const NS::URL*            url,
                                                            const IOCompressionMethod compressionMethod,
                                                            NS::Error**               error) const
{
    return sendMessage<IOFileHandle*>(
        this, _MTL_PRIVATE_SEL(newIOFileHandleWithURL_compressionMethod_error_), url, compressionMethod, error);
}

_MTL_INLINE MTL::IOFileHandle* MTL::Device::newIOHandle(const NS::URL* url, NS::Error** error) const
{
    return sendMessage<IOFileHandle*>(this, _MTL_PRIVATE_SEL(newIOHandleWithURL_error_), url, error);
}

_MTL_INLINE MTL::IOFileHandle* MTL::Device::newIOHandle(const NS::URL*            url,
                                                        const IOCompressionMethod compressionMethod,
                                                        NS::Error**               error) const
{
    return sendMessage<IOFileHandle*>(
        this, _MTL_PRIVATE_SEL(newIOHandleWithURL_compressionMethod_error_), url, compressionMethod, error);
}

_MTL_INLINE MTL::IndirectCommandBuffer* MTL::Device::newIndirectCommandBuffer(
    const IndirectCommandBufferDescriptor* descriptor, const NS::UInteger maxCount, const ResourceOptions options) const
{
    return sendMessage<IndirectCommandBuffer*>(
        this,
        _MTL_PRIVATE_SEL(newIndirectCommandBufferWithDescriptor_maxCommandCount_options_),
        descriptor,
        maxCount,
        options);
}

_MTL_INLINE MTL::Library* MTL::Device::newLibrary(const NS::String* filepath, NS::Error** error) const
{
    return sendMessage<Library*>(this, _MTL_PRIVATE_SEL(newLibraryWithFile_error_), filepath, error);
}

_MTL_INLINE MTL::Library* MTL::Device::newLibrary(const NS::URL* url, NS::Error** error) const
{
    return sendMessage<Library*>(this, _MTL_PRIVATE_SEL(newLibraryWithURL_error_), url, error);
}

_MTL_INLINE MTL::Library* MTL::Device::newLibrary(const dispatch_data_t data, NS::Error** error) const
{
    return sendMessage<Library*>(this, _MTL_PRIVATE_SEL(newLibraryWithData_error_), data, error);
}

_MTL_INLINE MTL::Library* MTL::Device::newLibrary(const NS::String*     source,
                                                  const CompileOptions* options,
                                                  NS::Error**           error) const
{
    return sendMessage<Library*>(this, _MTL_PRIVATE_SEL(newLibraryWithSource_options_error_), source, options, error);
}

_MTL_INLINE void MTL::Device::newLibrary(const NS::String*                 source,
                                         const CompileOptions*             options,
                                         const NewLibraryCompletionHandler completionHandler)
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(newLibraryWithSource_options_completionHandler_), source, options, completionHandler);
}

_MTL_INLINE MTL::Library* MTL::Device::newLibrary(const StitchedLibraryDescriptor* descriptor, NS::Error** error) const
{
    return sendMessage<Library*>(this, _MTL_PRIVATE_SEL(newLibraryWithStitchedDescriptor_error_), descriptor, error);
}

_MTL_INLINE void MTL::Device::newLibrary(const StitchedLibraryDescriptor*  descriptor,
                                         const NewLibraryCompletionHandler completionHandler)
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(newLibraryWithStitchedDescriptor_completionHandler_), descriptor, completionHandler);
}

_MTL_INLINE void MTL::Device::newLibrary(const NS::String*                          pSource,
                                         const CompileOptions*                      pOptions,
                                         const NewLibraryCompletionHandlerFunction& completionHandler)
{
    __block NewLibraryCompletionHandlerFunction blockCompletionHandler = completionHandler;
    newLibrary(pSource, pOptions, ^(Library* pLibrary, NS::Error* pError) {
      blockCompletionHandler(pLibrary, pError);
    });
}

_MTL_INLINE void MTL::Device::newLibrary(const StitchedLibraryDescriptor*           pDescriptor,
                                         const NewLibraryCompletionHandlerFunction& completionHandler)
{
    __block NewLibraryCompletionHandlerFunction blockCompletionHandler = completionHandler;
    newLibrary(pDescriptor, ^(Library* pLibrary, NS::Error* pError) {
      blockCompletionHandler(pLibrary, pError);
    });
}

_MTL_INLINE MTL::LogState* MTL::Device::newLogState(const LogStateDescriptor* descriptor, NS::Error** error) const
{
    return sendMessage<LogState*>(this, _MTL_PRIVATE_SEL(newLogStateWithDescriptor_error_), descriptor, error);
}

_MTL_INLINE MTL4::CommandQueue* MTL::Device::newMTL4CommandQueue() const
{
    return sendMessage<MTL4::CommandQueue*>(this, _MTL_PRIVATE_SEL(newMTL4CommandQueue));
}

_MTL_INLINE MTL4::CommandQueue* MTL::Device::newMTL4CommandQueue(const MTL4::CommandQueueDescriptor* descriptor,
                                                                 NS::Error**                         error) const
{
    return sendMessage<MTL4::CommandQueue*>(
        this, _MTL_PRIVATE_SEL(newMTL4CommandQueueWithDescriptor_error_), descriptor, error);
}

_MTL_INLINE MTL4::PipelineDataSetSerializer* MTL::Device::newPipelineDataSetSerializer(
    const MTL4::PipelineDataSetSerializerDescriptor* descriptor) const
{
    return sendMessage<MTL4::PipelineDataSetSerializer*>(
        this, _MTL_PRIVATE_SEL(newPipelineDataSetSerializerWithDescriptor_), descriptor);
}

_MTL_INLINE MTL::RasterizationRateMap* MTL::Device::newRasterizationRateMap(
    const RasterizationRateMapDescriptor* descriptor) const
{
    return sendMessage<RasterizationRateMap*>(
        this, _MTL_PRIVATE_SEL(newRasterizationRateMapWithDescriptor_), descriptor);
}

_MTL_INLINE MTL::RenderPipelineState* MTL::Device::newRenderPipelineState(const RenderPipelineDescriptor* descriptor,
                                                                          NS::Error**                     error) const
{
    return sendMessage<RenderPipelineState*>(
        this, _MTL_PRIVATE_SEL(newRenderPipelineStateWithDescriptor_error_), descriptor, error);
}

_MTL_INLINE MTL::RenderPipelineState* MTL::Device::newRenderPipelineState(
    const RenderPipelineDescriptor*             descriptor,
    const PipelineOption                        options,
    const AutoreleasedRenderPipelineReflection* reflection,
    NS::Error**                                 error) const
{
    return sendMessage<RenderPipelineState*>(
        this,
        _MTL_PRIVATE_SEL(newRenderPipelineStateWithDescriptor_options_reflection_error_),
        descriptor,
        options,
        reflection,
        error);
}

_MTL_INLINE void MTL::Device::newRenderPipelineState(const RenderPipelineDescriptor*               descriptor,
                                                     const NewRenderPipelineStateCompletionHandler completionHandler)
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(newRenderPipelineStateWithDescriptor_completionHandler_), descriptor, completionHandler);
}

_MTL_INLINE void MTL::Device::newRenderPipelineState(
    const RenderPipelineDescriptor*                             descriptor,
    PipelineOption                                              options,
    const NewRenderPipelineStateWithReflectionCompletionHandler completionHandler)
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(newRenderPipelineStateWithDescriptor_options_completionHandler_),
                      descriptor,
                      options,
                      completionHandler);
}

_MTL_INLINE MTL::RenderPipelineState* MTL::Device::newRenderPipelineState(
    const TileRenderPipelineDescriptor*         descriptor,
    const PipelineOption                        options,
    const AutoreleasedRenderPipelineReflection* reflection,
    NS::Error**                                 error) const
{
    return sendMessage<RenderPipelineState*>(
        this,
        _MTL_PRIVATE_SEL(newRenderPipelineStateWithTileDescriptor_options_reflection_error_),
        descriptor,
        options,
        reflection,
        error);
}

_MTL_INLINE void MTL::Device::newRenderPipelineState(
    const TileRenderPipelineDescriptor*                         descriptor,
    PipelineOption                                              options,
    const NewRenderPipelineStateWithReflectionCompletionHandler completionHandler)
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(newRenderPipelineStateWithTileDescriptor_options_completionHandler_),
                      descriptor,
                      options,
                      completionHandler);
}

_MTL_INLINE MTL::RenderPipelineState* MTL::Device::newRenderPipelineState(
    const MeshRenderPipelineDescriptor*         descriptor,
    const PipelineOption                        options,
    const AutoreleasedRenderPipelineReflection* reflection,
    NS::Error**                                 error) const
{
    return sendMessage<RenderPipelineState*>(
        this,
        _MTL_PRIVATE_SEL(newRenderPipelineStateWithMeshDescriptor_options_reflection_error_),
        descriptor,
        options,
        reflection,
        error);
}

_MTL_INLINE void MTL::Device::newRenderPipelineState(
    const MeshRenderPipelineDescriptor*                         descriptor,
    PipelineOption                                              options,
    const NewRenderPipelineStateWithReflectionCompletionHandler completionHandler)
{
    sendMessage<void>(this,
                      _MTL_PRIVATE_SEL(newRenderPipelineStateWithMeshDescriptor_options_completionHandler_),
                      descriptor,
                      options,
                      completionHandler);
}

_MTL_INLINE void MTL::Device::newRenderPipelineState(
    const RenderPipelineDescriptor*                        pDescriptor,
    const NewRenderPipelineStateCompletionHandlerFunction& completionHandler)
{
    __block NewRenderPipelineStateCompletionHandlerFunction blockCompletionHandler = completionHandler;
    newRenderPipelineState(pDescriptor, ^(RenderPipelineState* pPipelineState, NS::Error* pError) {
      blockCompletionHandler(pPipelineState, pError);
    });
}

_MTL_INLINE void MTL::Device::newRenderPipelineState(
    const RenderPipelineDescriptor*                                      pDescriptor,
    const PipelineOption                                                 options,
    const NewRenderPipelineStateWithReflectionCompletionHandlerFunction& completionHandler)
{
    __block NewRenderPipelineStateWithReflectionCompletionHandlerFunction blockCompletionHandler = completionHandler;
    newRenderPipelineState(
        pDescriptor,
        options,
        ^(RenderPipelineState* pPipelineState, RenderPipelineReflection* pReflection, NS::Error* pError) {
          blockCompletionHandler(pPipelineState, pReflection, pError);
        });
}

_MTL_INLINE void MTL::Device::newRenderPipelineState(
    const TileRenderPipelineDescriptor*                                  pDescriptor,
    const PipelineOption                                                 options,
    const NewRenderPipelineStateWithReflectionCompletionHandlerFunction& completionHandler)
{
    __block NewRenderPipelineStateWithReflectionCompletionHandlerFunction blockCompletionHandler = completionHandler;
    newRenderPipelineState(
        pDescriptor,
        options,
        ^(RenderPipelineState* pPipelineState, RenderPipelineReflection* pReflection, NS::Error* pError) {
          blockCompletionHandler(pPipelineState, pReflection, pError);
        });
}

_MTL_INLINE MTL::ResidencySet* MTL::Device::newResidencySet(const ResidencySetDescriptor* desc, NS::Error** error) const
{
    return sendMessage<ResidencySet*>(this, _MTL_PRIVATE_SEL(newResidencySetWithDescriptor_error_), desc, error);
}

_MTL_INLINE MTL::SamplerState* MTL::Device::newSamplerState(const SamplerDescriptor* descriptor) const
{
    return sendMessage<SamplerState*>(this, _MTL_PRIVATE_SEL(newSamplerStateWithDescriptor_), descriptor);
}

_MTL_INLINE MTL::SharedEvent* MTL::Device::newSharedEvent() const
{
    return sendMessage<SharedEvent*>(this, _MTL_PRIVATE_SEL(newSharedEvent));
}

_MTL_INLINE MTL::SharedEvent* MTL::Device::newSharedEvent(const SharedEventHandle* sharedEventHandle) const
{
    return sendMessage<SharedEvent*>(this, _MTL_PRIVATE_SEL(newSharedEventWithHandle_), sharedEventHandle);
}

_MTL_INLINE MTL::Texture* MTL::Device::newSharedTexture(const TextureDescriptor* descriptor) const
{
    return sendMessage<Texture*>(this, _MTL_PRIVATE_SEL(newSharedTextureWithDescriptor_), descriptor);
}

_MTL_INLINE MTL::Texture* MTL::Device::newSharedTexture(const SharedTextureHandle* sharedHandle) const
{
    return sendMessage<Texture*>(this, _MTL_PRIVATE_SEL(newSharedTextureWithHandle_), sharedHandle);
}

_MTL_INLINE MTL::Tensor* MTL::Device::newTensor(const TensorDescriptor* descriptor, NS::Error** error) const
{
    return sendMessage<Tensor*>(this, _MTL_PRIVATE_SEL(newTensorWithDescriptor_error_), descriptor, error);
}

_MTL_INLINE MTL::Texture* MTL::Device::newTexture(const TextureDescriptor* descriptor) const
{
    return sendMessage<Texture*>(this, _MTL_PRIVATE_SEL(newTextureWithDescriptor_), descriptor);
}

_MTL_INLINE MTL::Texture* MTL::Device::newTexture(const TextureDescriptor* descriptor,
                                                  const IOSurfaceRef       iosurface,
                                                  const NS::UInteger       plane) const
{
    return sendMessage<Texture*>(
        this, _MTL_PRIVATE_SEL(newTextureWithDescriptor_iosurface_plane_), descriptor, iosurface, plane);
}

_MTL_INLINE MTL::TextureViewPool* MTL::Device::newTextureViewPool(const ResourceViewPoolDescriptor* descriptor,
                                                                  NS::Error**                       error) const
{
    return sendMessage<TextureViewPool*>(
        this, _MTL_PRIVATE_SEL(newTextureViewPoolWithDescriptor_error_), descriptor, error);
}

_MTL_INLINE uint32_t MTL::Device::peerCount() const { return sendMessage<uint32_t>(this, _MTL_PRIVATE_SEL(peerCount)); }

_MTL_INLINE uint64_t MTL::Device::peerGroupID() const
{
    return sendMessage<uint64_t>(this, _MTL_PRIVATE_SEL(peerGroupID));
}

_MTL_INLINE uint32_t MTL::Device::peerIndex() const { return sendMessage<uint32_t>(this, _MTL_PRIVATE_SEL(peerIndex)); }

_MTL_INLINE bool MTL::Device::programmableSamplePositionsSupported() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(areProgrammableSamplePositionsSupported));
}

_MTL_INLINE uint64_t MTL::Device::queryTimestampFrequency() const
{
    return sendMessage<uint64_t>(this, _MTL_PRIVATE_SEL(queryTimestampFrequency));
}

_MTL_INLINE bool MTL::Device::rasterOrderGroupsSupported() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(areRasterOrderGroupsSupported));
}

_MTL_INLINE MTL::ReadWriteTextureTier MTL::Device::readWriteTextureSupport() const
{
    return sendMessage<ReadWriteTextureTier>(this, _MTL_PRIVATE_SEL(readWriteTextureSupport));
}

_MTL_INLINE uint64_t MTL::Device::recommendedMaxWorkingSetSize() const
{
    return sendMessage<uint64_t>(this, _MTL_PRIVATE_SEL(recommendedMaxWorkingSetSize));
}

_MTL_INLINE uint64_t MTL::Device::registryID() const
{
    return sendMessage<uint64_t>(this, _MTL_PRIVATE_SEL(registryID));
}

_MTL_INLINE bool MTL::Device::removable() const { return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isRemovable)); }

_MTL_INLINE void MTL::Device::sampleTimestamps(Timestamp* cpuTimestamp, Timestamp* gpuTimestamp) const
{
    sendMessage<void>(this, _MTL_PRIVATE_SEL(sampleTimestamps_gpuTimestamp_), cpuTimestamp, gpuTimestamp);
}

_MTL_INLINE void MTL::Device::setShouldMaximizeConcurrentCompilation(
    const bool shouldMaximizeConcurrentCompilation) const
{
    sendMessage<void>(
        this, _MTL_PRIVATE_SEL(setShouldMaximizeConcurrentCompilation_), shouldMaximizeConcurrentCompilation);
}

_MTL_INLINE bool MTL::Device::shouldMaximizeConcurrentCompilation() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(shouldMaximizeConcurrentCompilation));
}

_MTL_INLINE NS::UInteger MTL::Device::sizeOfCounterHeapEntry(const MTL4::CounterHeapType type) const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(sizeOfCounterHeapEntry_), type);
}

_MTL_INLINE MTL::Size MTL::Device::sparseTileSize(const TextureType  textureType,
                                                  const PixelFormat  pixelFormat,
                                                  const NS::UInteger sampleCount) const
{
    return sendMessage<Size>(this,
                             _MTL_PRIVATE_SEL(sparseTileSizeWithTextureType_pixelFormat_sampleCount_),
                             textureType,
                             pixelFormat,
                             sampleCount);
}

_MTL_INLINE MTL::Size MTL::Device::sparseTileSize(const TextureType    textureType,
                                                  const PixelFormat    pixelFormat,
                                                  const NS::UInteger   sampleCount,
                                                  const SparsePageSize sparsePageSize) const
{
    return sendMessage<Size>(this,
                             _MTL_PRIVATE_SEL(sparseTileSizeWithTextureType_pixelFormat_sampleCount_sparsePageSize_),
                             textureType,
                             pixelFormat,
                             sampleCount,
                             sparsePageSize);
}

_MTL_INLINE NS::UInteger MTL::Device::sparseTileSizeInBytes() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(sparseTileSizeInBytes));
}

_MTL_INLINE NS::UInteger MTL::Device::sparseTileSizeInBytes(const SparsePageSize sparsePageSize) const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(sparseTileSizeInBytesForSparsePageSize_), sparsePageSize);
}

_MTL_INLINE bool MTL::Device::supports32BitFloatFiltering() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supports32BitFloatFiltering));
}

_MTL_INLINE bool MTL::Device::supports32BitMSAA() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supports32BitMSAA));
}

_MTL_INLINE bool MTL::Device::supportsBCTextureCompression() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supportsBCTextureCompression));
}

_MTL_INLINE bool MTL::Device::supportsCounterSampling(const CounterSamplingPoint samplingPoint) const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supportsCounterSampling_), samplingPoint);
}

_MTL_INLINE bool MTL::Device::supportsDynamicLibraries() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supportsDynamicLibraries));
}

_MTL_INLINE bool MTL::Device::supportsFamily(const GPUFamily gpuFamily) const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supportsFamily_), gpuFamily);
}

_MTL_INLINE bool MTL::Device::supportsFeatureSet(const FeatureSet featureSet) const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supportsFeatureSet_), featureSet);
}

_MTL_INLINE bool MTL::Device::supportsFunctionPointers() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supportsFunctionPointers));
}

_MTL_INLINE bool MTL::Device::supportsFunctionPointersFromRender() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supportsFunctionPointersFromRender));
}

_MTL_INLINE bool MTL::Device::supportsPrimitiveMotionBlur() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supportsPrimitiveMotionBlur));
}

_MTL_INLINE bool MTL::Device::supportsPullModelInterpolation() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supportsPullModelInterpolation));
}

_MTL_INLINE bool MTL::Device::supportsQueryTextureLOD() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supportsQueryTextureLOD));
}

_MTL_INLINE bool MTL::Device::supportsRasterizationRateMap(const NS::UInteger layerCount) const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supportsRasterizationRateMapWithLayerCount_), layerCount);
}

_MTL_INLINE bool MTL::Device::supportsRaytracing() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supportsRaytracing));
}

_MTL_INLINE bool MTL::Device::supportsRaytracingFromRender() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supportsRaytracingFromRender));
}

_MTL_INLINE bool MTL::Device::supportsRenderDynamicLibraries() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supportsRenderDynamicLibraries));
}

_MTL_INLINE bool MTL::Device::supportsShaderBarycentricCoordinates() const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supportsShaderBarycentricCoordinates));
}

_MTL_INLINE bool MTL::Device::supportsTextureSampleCount(const NS::UInteger sampleCount) const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supportsTextureSampleCount_), sampleCount);
}

_MTL_INLINE bool MTL::Device::supportsVertexAmplificationCount(const NS::UInteger count) const
{
    return sendMessageSafe<bool>(this, _MTL_PRIVATE_SEL(supportsVertexAmplificationCount_), count);
}

_MTL_INLINE MTL::SizeAndAlign MTL::Device::tensorSizeAndAlign(const TensorDescriptor* descriptor) const
{
    return sendMessage<SizeAndAlign>(this, _MTL_PRIVATE_SEL(tensorSizeAndAlignWithDescriptor_), descriptor);
}
