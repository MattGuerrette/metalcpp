//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLArgument.hpp
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
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"
#include "MTLTensor.hpp"
#include "MTLTexture.hpp"

namespace MTL
{
    class Argument;
    class ArrayType;
    class PointerType;
    class StructMember;
    class StructType;
    class TensorExtents;
    class TensorReferenceType;
    class TextureReferenceType;
    class Type;

    /// @see https://developer.apple.com/documentation/metal/mtlindextype?language=objc
    _MTL_ENUM(NS::UInteger, IndexType){
        IndexTypeUInt16 = 0,
        IndexTypeUInt32 = 1,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlbindingtype?language=objc
    _MTL_ENUM(NS::Integer, BindingType){
        BindingTypeBuffer                         = 0,
        BindingTypeThreadgroupMemory              = 1,
        BindingTypeTexture                        = 2,
        BindingTypeSampler                        = 3,
        BindingTypeImageblockData                 = 16,
        BindingTypeImageblock                     = 17,
        BindingTypeVisibleFunctionTable           = 24,
        BindingTypePrimitiveAccelerationStructure = 25,
        BindingTypeInstanceAccelerationStructure  = 26,
        BindingTypeIntersectionFunctionTable      = 27,
        BindingTypeObjectPayload                  = 34,
        BindingTypeTensor                         = 37,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlargumenttype?language=objc
    _MTL_ENUM(NS::UInteger, ArgumentType){
        ArgumentTypeBuffer                         = 0,
        ArgumentTypeThreadgroupMemory              = 1,
        ArgumentTypeTexture                        = 2,
        ArgumentTypeSampler                        = 3,
        ArgumentTypeImageblockData                 = 16,
        ArgumentTypeImageblock                     = 17,
        ArgumentTypeVisibleFunctionTable           = 24,
        ArgumentTypePrimitiveAccelerationStructure = 25,
        ArgumentTypeInstanceAccelerationStructure  = 26,
        ArgumentTypeIntersectionFunctionTable      = 27,
    };

    /// @see https://developer.apple.com/documentation/metal/mtlbindingaccess?language=objc
    _MTL_ENUM(NS::UInteger, BindingAccess){
        BindingAccessReadOnly = 0,  BindingAccessReadWrite = 1,  BindingAccessWriteOnly = 2,
        ArgumentAccessReadOnly = 0, ArgumentAccessReadWrite = 1, ArgumentAccessWriteOnly = 2,
    };

    /// @see https://developer.apple.com/documentation/metal/mtltype?language=objc
    class Type : public NS::Referencing<Type>
    {
    public:
        [[nodiscard]] static Type* alloc();

        [[nodiscard]] DataType dataType() const;

        [[nodiscard]] Type* init();
    };

    /// @see https://developer.apple.com/documentation/metal/mtlstructmember?language=objc
    class StructMember : public NS::Referencing<StructMember>
    {
    public:
        [[nodiscard]] static StructMember* alloc();

        [[nodiscard]] NS::UInteger argumentIndex() const;

        [[nodiscard]] ArrayType* arrayType() const;

        [[nodiscard]] DataType dataType() const;

        [[nodiscard]] StructMember* init();

        [[nodiscard]] NS::String* name() const;

        [[nodiscard]] NS::UInteger offset() const;

        [[nodiscard]] PointerType* pointerType() const;

        [[nodiscard]] StructType* structType() const;

        [[nodiscard]] TensorReferenceType* tensorReferenceType() const;

        [[nodiscard]] TextureReferenceType* textureReferenceType() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlstructtype?language=objc
    class StructType : public NS::Referencing<StructType, Type>
    {
    public:
        [[nodiscard]] static StructType* alloc();

        [[nodiscard]] StructType* init();

        [[nodiscard]] StructMember* memberByName(const NS::String* name) const;

        [[nodiscard]] NS::Array* members() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlarraytype?language=objc
    class ArrayType : public NS::Referencing<ArrayType, Type>
    {
    public:
        [[nodiscard]] static ArrayType* alloc();

        [[nodiscard]] NS::UInteger argumentIndexStride() const;

        [[nodiscard]] NS::UInteger arrayLength() const;

        [[nodiscard]] ArrayType* elementArrayType() const;

        [[nodiscard]] PointerType* elementPointerType() const;

        [[nodiscard]] StructType* elementStructType() const;

        [[nodiscard]] TensorReferenceType* elementTensorReferenceType() const;

        [[nodiscard]] TextureReferenceType* elementTextureReferenceType() const;

        [[nodiscard]] DataType elementType() const;

        [[nodiscard]] ArrayType* init();

        [[nodiscard]] NS::UInteger stride() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlpointertype?language=objc
    class PointerType : public NS::Referencing<PointerType, Type>
    {
    public:
        [[nodiscard]] BindingAccess access() const;

        [[nodiscard]] NS::UInteger alignment() const;

        [[nodiscard]] static PointerType* alloc();

        [[nodiscard]] NS::UInteger dataSize() const;

        [[nodiscard]] ArrayType* elementArrayType() const;

        [[nodiscard]] bool elementIsArgumentBuffer() const;

        [[nodiscard]] StructType* elementStructType() const;

        [[nodiscard]] DataType elementType() const;

        [[nodiscard]] PointerType* init();
    };

    /// @see https://developer.apple.com/documentation/metal/mtltexturereferencetype?language=objc
    class TextureReferenceType : public NS::Referencing<TextureReferenceType, Type>
    {
    public:
        [[nodiscard]] BindingAccess access() const;

        [[nodiscard]] static TextureReferenceType* alloc();

        [[nodiscard]] TextureReferenceType* init();

        [[nodiscard]] bool isDepthTexture() const;

        [[nodiscard]] DataType textureDataType() const;

        [[nodiscard]] TextureType textureType() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtltensorreferencetype?language=objc
    class TensorReferenceType : public NS::Referencing<TensorReferenceType, Type>
    {
    public:
        [[nodiscard]] BindingAccess access() const;

        [[nodiscard]] static TensorReferenceType* alloc();

        [[nodiscard]] TensorExtents* dimensions() const;

        [[nodiscard]] DataType indexType() const;

        [[nodiscard]] TensorReferenceType* init();

        [[nodiscard]] TensorDataType tensorDataType() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlargument?language=objc
    class Argument : public NS::Referencing<Argument>
    {
    public:
        [[nodiscard]] BindingAccess access() const;

        [[deprecated("please use isActive instead")]] [[nodiscard]] bool active() const;

        [[nodiscard]] static Argument* alloc();

        [[nodiscard]] NS::UInteger arrayLength() const;

        [[nodiscard]] NS::UInteger bufferAlignment() const;

        [[nodiscard]] NS::UInteger bufferDataSize() const;

        [[nodiscard]] DataType bufferDataType() const;

        [[nodiscard]] PointerType* bufferPointerType() const;

        [[nodiscard]] StructType* bufferStructType() const;

        [[nodiscard]] NS::UInteger index() const;

        [[nodiscard]] Argument* init();

        [[nodiscard]] bool isActive() const;

        [[nodiscard]] bool isDepthTexture() const;

        [[nodiscard]] NS::String* name() const;

        [[nodiscard]] DataType textureDataType() const;

        [[nodiscard]] TextureType textureType() const;

        [[nodiscard]] NS::UInteger threadgroupMemoryAlignment() const;

        [[nodiscard]] NS::UInteger threadgroupMemoryDataSize() const;

        [[nodiscard]] ArgumentType type() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlbinding?language=objc
    class Binding : public NS::Referencing<Binding>
    {
    public:
        [[nodiscard]] BindingAccess access() const;

        [[deprecated("please use isArgument instead")]] [[nodiscard]] bool argument() const;

        [[nodiscard]] NS::UInteger index() const;

        [[nodiscard]] bool isArgument() const;

        [[nodiscard]] bool isUsed() const;

        [[nodiscard]] NS::String* name() const;

        [[nodiscard]] BindingType type() const;

        [[deprecated("please use isUsed instead")]] [[nodiscard]] bool used() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlbufferbinding?language=objc
    class BufferBinding : public NS::Referencing<BufferBinding, Binding>
    {
    public:
        [[nodiscard]] NS::UInteger bufferAlignment() const;

        [[nodiscard]] NS::UInteger bufferDataSize() const;

        [[nodiscard]] DataType bufferDataType() const;

        [[nodiscard]] PointerType* bufferPointerType() const;

        [[nodiscard]] StructType* bufferStructType() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlthreadgroupbinding?language=objc
    class ThreadgroupBinding : public NS::Referencing<ThreadgroupBinding, Binding>
    {
    public:
        [[nodiscard]] NS::UInteger threadgroupMemoryAlignment() const;

        [[nodiscard]] NS::UInteger threadgroupMemoryDataSize() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtltexturebinding?language=objc
    class TextureBinding : public NS::Referencing<TextureBinding, Binding>
    {
    public:
        [[nodiscard]] NS::UInteger arrayLength() const;

        [[deprecated("please use isDepthTexture instead")]] [[nodiscard]] bool depthTexture() const;
        [[nodiscard]] bool                                                     isDepthTexture() const;

        [[nodiscard]] DataType textureDataType() const;

        [[nodiscard]] TextureType textureType() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtlobjectpayloadbinding?language=objc
    class ObjectPayloadBinding : public NS::Referencing<ObjectPayloadBinding, Binding>
    {
    public:
        [[nodiscard]] NS::UInteger objectPayloadAlignment() const;

        [[nodiscard]] NS::UInteger objectPayloadDataSize() const;
    };

    /// @see https://developer.apple.com/documentation/metal/mtltensorbinding?language=objc
    class TensorBinding : public NS::Referencing<TensorBinding, Binding>
    {
    public:
        [[nodiscard]] TensorExtents* dimensions() const;

        [[nodiscard]] DataType indexType() const;

        [[nodiscard]] TensorDataType tensorDataType() const;
    };

} // namespace MTL
_MTL_INLINE MTL::Type* MTL::Type::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<Type>(_MTL_PRIVATE_CLS(MTLType));
}

_MTL_INLINE MTL::DataType MTL::Type::dataType() const
{
    return sendMessage<DataType>(this, _MTL_PRIVATE_SEL(dataType));
}

_MTL_INLINE MTL::Type* MTL::Type::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<Type>();
}

_MTL_INLINE MTL::StructMember* MTL::StructMember::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<StructMember>(_MTL_PRIVATE_CLS(MTLStructMember));
}

_MTL_INLINE NS::UInteger MTL::StructMember::argumentIndex() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(argumentIndex));
}

_MTL_INLINE MTL::ArrayType* MTL::StructMember::arrayType() const
{
    return sendMessage<ArrayType*>(this, _MTL_PRIVATE_SEL(arrayType));
}

_MTL_INLINE MTL::DataType MTL::StructMember::dataType() const
{
    return sendMessage<DataType>(this, _MTL_PRIVATE_SEL(dataType));
}

_MTL_INLINE MTL::StructMember* MTL::StructMember::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<StructMember>();
}

_MTL_INLINE NS::String* MTL::StructMember::name() const
{
    return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(name));
}

_MTL_INLINE NS::UInteger MTL::StructMember::offset() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(offset));
}

_MTL_INLINE MTL::PointerType* MTL::StructMember::pointerType() const
{
    return sendMessage<PointerType*>(this, _MTL_PRIVATE_SEL(pointerType));
}

_MTL_INLINE MTL::StructType* MTL::StructMember::structType() const
{
    return sendMessage<StructType*>(this, _MTL_PRIVATE_SEL(structType));
}

_MTL_INLINE MTL::TensorReferenceType* MTL::StructMember::tensorReferenceType() const
{
    return sendMessage<TensorReferenceType*>(this, _MTL_PRIVATE_SEL(tensorReferenceType));
}

_MTL_INLINE MTL::TextureReferenceType* MTL::StructMember::textureReferenceType() const
{
    return sendMessage<TextureReferenceType*>(this, _MTL_PRIVATE_SEL(textureReferenceType));
}

_MTL_INLINE MTL::StructType* MTL::StructType::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<StructType>(_MTL_PRIVATE_CLS(MTLStructType));
}

_MTL_INLINE MTL::StructType* MTL::StructType::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<StructType>();
}

_MTL_INLINE MTL::StructMember* MTL::StructType::memberByName(const NS::String* name) const
{
    return sendMessage<StructMember*>(this, _MTL_PRIVATE_SEL(memberByName_), name);
}

_MTL_INLINE NS::Array* MTL::StructType::members() const
{
    return sendMessage<NS::Array*>(this, _MTL_PRIVATE_SEL(members));
}

_MTL_INLINE MTL::ArrayType* MTL::ArrayType::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<ArrayType>(_MTL_PRIVATE_CLS(MTLArrayType));
}

_MTL_INLINE NS::UInteger MTL::ArrayType::argumentIndexStride() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(argumentIndexStride));
}

_MTL_INLINE NS::UInteger MTL::ArrayType::arrayLength() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(arrayLength));
}

_MTL_INLINE MTL::ArrayType* MTL::ArrayType::elementArrayType() const
{
    return sendMessage<ArrayType*>(this, _MTL_PRIVATE_SEL(elementArrayType));
}

_MTL_INLINE MTL::PointerType* MTL::ArrayType::elementPointerType() const
{
    return sendMessage<PointerType*>(this, _MTL_PRIVATE_SEL(elementPointerType));
}

_MTL_INLINE MTL::StructType* MTL::ArrayType::elementStructType() const
{
    return sendMessage<StructType*>(this, _MTL_PRIVATE_SEL(elementStructType));
}

_MTL_INLINE MTL::TensorReferenceType* MTL::ArrayType::elementTensorReferenceType() const
{
    return sendMessage<TensorReferenceType*>(this, _MTL_PRIVATE_SEL(elementTensorReferenceType));
}

_MTL_INLINE MTL::TextureReferenceType* MTL::ArrayType::elementTextureReferenceType() const
{
    return sendMessage<TextureReferenceType*>(this, _MTL_PRIVATE_SEL(elementTextureReferenceType));
}

_MTL_INLINE MTL::DataType MTL::ArrayType::elementType() const
{
    return sendMessage<DataType>(this, _MTL_PRIVATE_SEL(elementType));
}

_MTL_INLINE MTL::ArrayType* MTL::ArrayType::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<ArrayType>();
}

_MTL_INLINE NS::UInteger MTL::ArrayType::stride() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(stride));
}

_MTL_INLINE MTL::BindingAccess MTL::PointerType::access() const
{
    return sendMessage<BindingAccess>(this, _MTL_PRIVATE_SEL(access));
}

_MTL_INLINE NS::UInteger MTL::PointerType::alignment() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(alignment));
}

_MTL_INLINE MTL::PointerType* MTL::PointerType::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<PointerType>(_MTL_PRIVATE_CLS(MTLPointerType));
}

_MTL_INLINE NS::UInteger MTL::PointerType::dataSize() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(dataSize));
}

_MTL_INLINE MTL::ArrayType* MTL::PointerType::elementArrayType() const
{
    return sendMessage<ArrayType*>(this, _MTL_PRIVATE_SEL(elementArrayType));
}

_MTL_INLINE bool MTL::PointerType::elementIsArgumentBuffer() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(elementIsArgumentBuffer));
}

_MTL_INLINE MTL::StructType* MTL::PointerType::elementStructType() const
{
    return sendMessage<StructType*>(this, _MTL_PRIVATE_SEL(elementStructType));
}

_MTL_INLINE MTL::DataType MTL::PointerType::elementType() const
{
    return sendMessage<DataType>(this, _MTL_PRIVATE_SEL(elementType));
}

_MTL_INLINE MTL::PointerType* MTL::PointerType::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<PointerType>();
}

_MTL_INLINE MTL::BindingAccess MTL::TextureReferenceType::access() const
{
    return sendMessage<BindingAccess>(this, _MTL_PRIVATE_SEL(access));
}

_MTL_INLINE MTL::TextureReferenceType* MTL::TextureReferenceType::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<TextureReferenceType>(_MTL_PRIVATE_CLS(MTLTextureReferenceType));
}

_MTL_INLINE MTL::TextureReferenceType* MTL::TextureReferenceType::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<TextureReferenceType>();
}

_MTL_INLINE bool MTL::TextureReferenceType::isDepthTexture() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isDepthTexture));
}

_MTL_INLINE MTL::DataType MTL::TextureReferenceType::textureDataType() const
{
    return sendMessage<DataType>(this, _MTL_PRIVATE_SEL(textureDataType));
}

_MTL_INLINE MTL::TextureType MTL::TextureReferenceType::textureType() const
{
    return sendMessage<TextureType>(this, _MTL_PRIVATE_SEL(textureType));
}

_MTL_INLINE MTL::BindingAccess MTL::TensorReferenceType::access() const
{
    return sendMessage<BindingAccess>(this, _MTL_PRIVATE_SEL(access));
}

_MTL_INLINE MTL::TensorReferenceType* MTL::TensorReferenceType::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<TensorReferenceType>(_MTL_PRIVATE_CLS(MTLTensorReferenceType));
}

_MTL_INLINE MTL::TensorExtents* MTL::TensorReferenceType::dimensions() const
{
    return sendMessage<TensorExtents*>(this, _MTL_PRIVATE_SEL(dimensions));
}

_MTL_INLINE MTL::DataType MTL::TensorReferenceType::indexType() const
{
    return sendMessage<DataType>(this, _MTL_PRIVATE_SEL(indexType));
}

_MTL_INLINE MTL::TensorReferenceType* MTL::TensorReferenceType::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<TensorReferenceType>();
}

_MTL_INLINE MTL::TensorDataType MTL::TensorReferenceType::tensorDataType() const
{
    return sendMessage<TensorDataType>(this, _MTL_PRIVATE_SEL(tensorDataType));
}

_MTL_INLINE MTL::BindingAccess MTL::Argument::access() const
{
    return sendMessage<BindingAccess>(this, _MTL_PRIVATE_SEL(access));
}

_MTL_INLINE bool MTL::Argument::active() const { return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isActive)); }

_MTL_INLINE MTL::Argument* MTL::Argument::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<Argument>(_MTL_PRIVATE_CLS(MTLArgument));
}

_MTL_INLINE NS::UInteger MTL::Argument::arrayLength() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(arrayLength));
}

_MTL_INLINE NS::UInteger MTL::Argument::bufferAlignment() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(bufferAlignment));
}

_MTL_INLINE NS::UInteger MTL::Argument::bufferDataSize() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(bufferDataSize));
}

_MTL_INLINE MTL::DataType MTL::Argument::bufferDataType() const
{
    return sendMessage<DataType>(this, _MTL_PRIVATE_SEL(bufferDataType));
}

_MTL_INLINE MTL::PointerType* MTL::Argument::bufferPointerType() const
{
    return sendMessage<PointerType*>(this, _MTL_PRIVATE_SEL(bufferPointerType));
}

_MTL_INLINE MTL::StructType* MTL::Argument::bufferStructType() const
{
    return sendMessage<StructType*>(this, _MTL_PRIVATE_SEL(bufferStructType));
}

_MTL_INLINE NS::UInteger MTL::Argument::index() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(index));
}

_MTL_INLINE MTL::Argument* MTL::Argument::init()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::init<Argument>();
}

_MTL_INLINE bool MTL::Argument::isActive() const { return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isActive)); }

_MTL_INLINE bool MTL::Argument::isDepthTexture() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isDepthTexture));
}

_MTL_INLINE NS::String* MTL::Argument::name() const { return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(name)); }

_MTL_INLINE MTL::DataType MTL::Argument::textureDataType() const
{
    return sendMessage<DataType>(this, _MTL_PRIVATE_SEL(textureDataType));
}

_MTL_INLINE MTL::TextureType MTL::Argument::textureType() const
{
    return sendMessage<TextureType>(this, _MTL_PRIVATE_SEL(textureType));
}

_MTL_INLINE NS::UInteger MTL::Argument::threadgroupMemoryAlignment() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(threadgroupMemoryAlignment));
}

_MTL_INLINE NS::UInteger MTL::Argument::threadgroupMemoryDataSize() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(threadgroupMemoryDataSize));
}

_MTL_INLINE MTL::ArgumentType MTL::Argument::type() const
{
    return sendMessage<ArgumentType>(this, _MTL_PRIVATE_SEL(type));
}

_MTL_INLINE MTL::BindingAccess MTL::Binding::access() const
{
    return sendMessage<BindingAccess>(this, _MTL_PRIVATE_SEL(access));
}

_MTL_INLINE bool MTL::Binding::argument() const { return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isArgument)); }

_MTL_INLINE NS::UInteger MTL::Binding::index() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(index));
}

_MTL_INLINE bool MTL::Binding::isArgument() const { return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isArgument)); }

_MTL_INLINE bool MTL::Binding::isUsed() const { return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isUsed)); }

_MTL_INLINE NS::String* MTL::Binding::name() const { return sendMessage<NS::String*>(this, _MTL_PRIVATE_SEL(name)); }

_MTL_INLINE MTL::BindingType MTL::Binding::type() const
{
    return sendMessage<BindingType>(this, _MTL_PRIVATE_SEL(type));
}

_MTL_INLINE bool MTL::Binding::used() const { return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isUsed)); }

_MTL_INLINE NS::UInteger MTL::BufferBinding::bufferAlignment() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(bufferAlignment));
}

_MTL_INLINE NS::UInteger MTL::BufferBinding::bufferDataSize() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(bufferDataSize));
}

_MTL_INLINE MTL::DataType MTL::BufferBinding::bufferDataType() const
{
    return sendMessage<DataType>(this, _MTL_PRIVATE_SEL(bufferDataType));
}

_MTL_INLINE MTL::PointerType* MTL::BufferBinding::bufferPointerType() const
{
    return sendMessage<PointerType*>(this, _MTL_PRIVATE_SEL(bufferPointerType));
}

_MTL_INLINE MTL::StructType* MTL::BufferBinding::bufferStructType() const
{
    return sendMessage<StructType*>(this, _MTL_PRIVATE_SEL(bufferStructType));
}

_MTL_INLINE NS::UInteger MTL::ThreadgroupBinding::threadgroupMemoryAlignment() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(threadgroupMemoryAlignment));
}

_MTL_INLINE NS::UInteger MTL::ThreadgroupBinding::threadgroupMemoryDataSize() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(threadgroupMemoryDataSize));
}

_MTL_INLINE NS::UInteger MTL::TextureBinding::arrayLength() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(arrayLength));
}

_MTL_INLINE bool MTL::TextureBinding::depthTexture() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isDepthTexture));
}

_MTL_INLINE bool MTL::TextureBinding::isDepthTexture() const
{
    return sendMessage<bool>(this, _MTL_PRIVATE_SEL(isDepthTexture));
}

_MTL_INLINE MTL::DataType MTL::TextureBinding::textureDataType() const
{
    return sendMessage<DataType>(this, _MTL_PRIVATE_SEL(textureDataType));
}

_MTL_INLINE MTL::TextureType MTL::TextureBinding::textureType() const
{
    return sendMessage<TextureType>(this, _MTL_PRIVATE_SEL(textureType));
}

_MTL_INLINE NS::UInteger MTL::ObjectPayloadBinding::objectPayloadAlignment() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(objectPayloadAlignment));
}

_MTL_INLINE NS::UInteger MTL::ObjectPayloadBinding::objectPayloadDataSize() const
{
    return sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(objectPayloadDataSize));
}

_MTL_INLINE MTL::TensorExtents* MTL::TensorBinding::dimensions() const
{
    return sendMessage<TensorExtents*>(this, _MTL_PRIVATE_SEL(dimensions));
}

_MTL_INLINE MTL::DataType MTL::TensorBinding::indexType() const
{
    return sendMessage<DataType>(this, _MTL_PRIVATE_SEL(indexType));
}

_MTL_INLINE MTL::TensorDataType MTL::TensorBinding::tensorDataType() const
{
    return sendMessage<TensorDataType>(this, _MTL_PRIVATE_SEL(tensorDataType));
}
