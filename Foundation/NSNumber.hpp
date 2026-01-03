//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Foundation/NSNumber.hpp
//
// Copyright 2020-2024 Apple Inc.
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

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#include "NSObjCRuntime.hpp"
#include "NSObject.hpp"
#include "NSTypes.hpp"

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

namespace NS
{
    class Value : public Copying<Value>
    {
    public:
        static Value* value(const void* pValue, const char* pType);
        static Value* value(const void* pPointer);

        static Value* alloc();

        Value* init(const void* pValue, const char* pType) const;
        Value* init(const Coder* pCoder) const;

        void                      getValue(void* pValue, UInteger size) const;
        [[nodiscard]] const char* objCType() const;

        bool                isEqualToValue(Value* pValue) const;
        [[nodiscard]] void* pointerValue() const;
    };

    class Number : public Copying<Number, Value>
    {
    public:
        [[nodiscard]] static Number* number(char value);
        [[nodiscard]] static Number* number(unsigned char value);
        [[nodiscard]] static Number* number(short value);
        [[nodiscard]] static Number* number(unsigned short value);
        [[nodiscard]] static Number* number(int value);
        [[nodiscard]] static Number* number(unsigned int value);
        [[nodiscard]] static Number* number(long value);
        [[nodiscard]] static Number* number(unsigned long value);
        [[nodiscard]] static Number* number(long long value);
        [[nodiscard]] static Number* number(unsigned long long value);
        [[nodiscard]] static Number* number(float value);
        [[nodiscard]] static Number* number(double value);
        [[nodiscard]] static Number* number(bool value);

        [[nodiscard]] static Number* alloc();

        [[nodiscard]] Number* init(const Coder* pCoder) const;
        [[nodiscard]] Number* init(char value) const;
        [[nodiscard]] Number* init(unsigned char value) const;
        [[nodiscard]] Number* init(short value) const;
        [[nodiscard]] Number* init(unsigned short value) const;
        [[nodiscard]] Number* init(int value) const;
        [[nodiscard]] Number* init(unsigned int value) const;
        [[nodiscard]] Number* init(long value) const;
        [[nodiscard]] Number* init(unsigned long value) const;
        [[nodiscard]] Number* init(long long value) const;
        [[nodiscard]] Number* init(unsigned long long value) const;
        [[nodiscard]] Number* init(float value) const;
        [[nodiscard]] Number* init(double value) const;
        [[nodiscard]] Number* init(bool value) const;

        [[nodiscard]] char               charValue() const;
        [[nodiscard]] unsigned char      unsignedCharValue() const;
        [[nodiscard]] short              shortValue() const;
        [[nodiscard]] unsigned short     unsignedShortValue() const;
        [[nodiscard]] int                intValue() const;
        [[nodiscard]] unsigned int       unsignedIntValue() const;
        [[nodiscard]] long               longValue() const;
        [[nodiscard]] unsigned long      unsignedLongValue() const;
        [[nodiscard]] long long          longLongValue() const;
        [[nodiscard]] unsigned long long unsignedLongLongValue() const;
        [[nodiscard]] float              floatValue() const;
        [[nodiscard]] double             doubleValue() const;
        [[nodiscard]] bool               boolValue() const;
        [[nodiscard]] Integer            integerValue() const;
        [[nodiscard]] UInteger           unsignedIntegerValue() const;
        [[nodiscard]] String*            stringValue() const;

        [[nodiscard]] ComparisonResult compare(const Number* pOtherNumber) const;
        [[nodiscard]] bool             isEqualToNumber(const Number* pNumber) const;
        [[nodiscard]] String*          descriptionWithLocale(const Object* pLocale) const;
    };
} // namespace NS

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Value* NS::Value::value(const void* pValue, const char* pType)
{
    return sendMessage<Value*>(_NS_PRIVATE_CLS(NSValue), _NS_PRIVATE_SEL(valueWithBytes_objCType_), pValue, pType);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Value* NS::Value::value(const void* pPointer)
{
    return sendMessage<Value*>(_NS_PRIVATE_CLS(NSValue), _NS_PRIVATE_SEL(valueWithPointer_), pPointer);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Value* NS::Value::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<Value>(_NS_PRIVATE_CLS(NSValue));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Value* NS::Value::init(const void* pValue, const char* pType) const
{
    return sendMessage<Value*>(this, _NS_PRIVATE_SEL(initWithBytes_objCType_), pValue, pType);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Value* NS::Value::init(const Coder* pCoder) const
{
    return sendMessage<Value*>(this, _NS_PRIVATE_SEL(initWithCoder_), pCoder);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE void NS::Value::getValue(void* pValue, const UInteger size) const
{
    sendMessage<void>(this, _NS_PRIVATE_SEL(getValue_size_), pValue, size);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE const char* NS::Value::objCType() const { return sendMessage<const char*>(this, _NS_PRIVATE_SEL(objCType)); }

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE bool NS::Value::isEqualToValue(Value* pValue) const
{
    return sendMessage<bool>(this, _NS_PRIVATE_SEL(isEqualToValue_), pValue);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE void* NS::Value::pointerValue() const { return sendMessage<void*>(this, _NS_PRIVATE_SEL(pointerValue)); }

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Number* NS::Number::number(const char value)
{
    return sendMessage<Number*>(_NS_PRIVATE_CLS(NSNumber), _NS_PRIVATE_SEL(numberWithChar_), value);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Number* NS::Number::number(const unsigned char value)
{
    return sendMessage<Number*>(_NS_PRIVATE_CLS(NSNumber), _NS_PRIVATE_SEL(numberWithUnsignedChar_), value);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Number* NS::Number::number(const short value)
{
    return sendMessage<Number*>(_NS_PRIVATE_CLS(NSNumber), _NS_PRIVATE_SEL(numberWithShort_), value);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Number* NS::Number::number(const unsigned short value)
{
    return sendMessage<Number*>(_NS_PRIVATE_CLS(NSNumber), _NS_PRIVATE_SEL(numberWithUnsignedShort_), value);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Number* NS::Number::number(const int value)
{
    return sendMessage<Number*>(_NS_PRIVATE_CLS(NSNumber), _NS_PRIVATE_SEL(numberWithInt_), value);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Number* NS::Number::number(const unsigned int value)
{
    return sendMessage<Number*>(_NS_PRIVATE_CLS(NSNumber), _NS_PRIVATE_SEL(numberWithUnsignedInt_), value);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Number* NS::Number::number(const long value)
{
    return sendMessage<Number*>(_NS_PRIVATE_CLS(NSNumber), _NS_PRIVATE_SEL(numberWithLong_), value);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Number* NS::Number::number(const unsigned long value)
{
    return sendMessage<Number*>(_NS_PRIVATE_CLS(NSNumber), _NS_PRIVATE_SEL(numberWithUnsignedLong_), value);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Number* NS::Number::number(const long long value)
{
    return sendMessage<Number*>(_NS_PRIVATE_CLS(NSNumber), _NS_PRIVATE_SEL(numberWithLongLong_), value);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Number* NS::Number::number(const unsigned long long value)
{
    return sendMessage<Number*>(_NS_PRIVATE_CLS(NSNumber), _NS_PRIVATE_SEL(numberWithUnsignedLongLong_), value);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Number* NS::Number::number(const float value)
{
    return sendMessage<Number*>(_NS_PRIVATE_CLS(NSNumber), _NS_PRIVATE_SEL(numberWithFloat_), value);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Number* NS::Number::number(const double value)
{
    return sendMessage<Number*>(_NS_PRIVATE_CLS(NSNumber), _NS_PRIVATE_SEL(numberWithDouble_), value);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Number* NS::Number::number(const bool value)
{
    return sendMessage<Number*>(_NS_PRIVATE_CLS(NSNumber), _NS_PRIVATE_SEL(numberWithBool_), value);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Number* NS::Number::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return NS::Object::alloc<Number>(_NS_PRIVATE_CLS(NSNumber));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Number* NS::Number::init(const Coder* pCoder) const
{
    return sendMessage<Number*>(this, _NS_PRIVATE_SEL(initWithCoder_), pCoder);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Number* NS::Number::init(const char value) const
{
    return sendMessage<Number*>(this, _NS_PRIVATE_SEL(initWithChar_), value);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Number* NS::Number::init(const unsigned char value) const
{
    return sendMessage<Number*>(this, _NS_PRIVATE_SEL(initWithUnsignedChar_), value);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Number* NS::Number::init(const short value) const
{
    return sendMessage<Number*>(this, _NS_PRIVATE_SEL(initWithShort_), value);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Number* NS::Number::init(const unsigned short value) const
{
    return sendMessage<Number*>(this, _NS_PRIVATE_SEL(initWithUnsignedShort_), value);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Number* NS::Number::init(const int value) const
{
    return sendMessage<Number*>(this, _NS_PRIVATE_SEL(initWithInt_), value);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Number* NS::Number::init(const unsigned int value) const
{
    return sendMessage<Number*>(this, _NS_PRIVATE_SEL(initWithUnsignedInt_), value);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Number* NS::Number::init(const long value) const
{
    return sendMessage<Number*>(this, _NS_PRIVATE_SEL(initWithLong_), value);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Number* NS::Number::init(const unsigned long value) const
{
    return sendMessage<Number*>(this, _NS_PRIVATE_SEL(initWithUnsignedLong_), value);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Number* NS::Number::init(const long long value) const
{
    return sendMessage<Number*>(this, _NS_PRIVATE_SEL(initWithLongLong_), value);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Number* NS::Number::init(const unsigned long long value) const
{
    return sendMessage<Number*>(this, _NS_PRIVATE_SEL(initWithUnsignedLongLong_), value);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Number* NS::Number::init(const float value) const
{
    return sendMessage<Number*>(this, _NS_PRIVATE_SEL(initWithFloat_), value);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Number* NS::Number::init(const double value) const
{
    return sendMessage<Number*>(this, _NS_PRIVATE_SEL(initWithDouble_), value);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Number* NS::Number::init(const bool value) const
{
    return sendMessage<Number*>(this, _NS_PRIVATE_SEL(initWithBool_), value);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE char NS::Number::charValue() const { return sendMessage<char>(this, _NS_PRIVATE_SEL(charValue)); }

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE unsigned char NS::Number::unsignedCharValue() const
{
    return sendMessage<unsigned char>(this, _NS_PRIVATE_SEL(unsignedCharValue));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE short NS::Number::shortValue() const { return sendMessage<short>(this, _NS_PRIVATE_SEL(shortValue)); }

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE unsigned short NS::Number::unsignedShortValue() const
{
    return sendMessage<unsigned short>(this, _NS_PRIVATE_SEL(unsignedShortValue));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE int NS::Number::intValue() const { return sendMessage<int>(this, _NS_PRIVATE_SEL(intValue)); }

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE unsigned int NS::Number::unsignedIntValue() const
{
    return sendMessage<unsigned int>(this, _NS_PRIVATE_SEL(unsignedIntValue));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE long NS::Number::longValue() const { return sendMessage<long>(this, _NS_PRIVATE_SEL(longValue)); }

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE unsigned long NS::Number::unsignedLongValue() const
{
    return sendMessage<unsigned long>(this, _NS_PRIVATE_SEL(unsignedLongValue));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE long long NS::Number::longLongValue() const
{
    return sendMessage<long long>(this, _NS_PRIVATE_SEL(longLongValue));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE unsigned long long NS::Number::unsignedLongLongValue() const
{
    return sendMessage<unsigned long long>(this, _NS_PRIVATE_SEL(unsignedLongLongValue));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE float NS::Number::floatValue() const { return sendMessage<float>(this, _NS_PRIVATE_SEL(floatValue)); }

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE double NS::Number::doubleValue() const { return sendMessage<double>(this, _NS_PRIVATE_SEL(doubleValue)); }

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE bool NS::Number::boolValue() const { return sendMessage<bool>(this, _NS_PRIVATE_SEL(boolValue)); }

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Integer NS::Number::integerValue() const
{
    return sendMessage<Integer>(this, _NS_PRIVATE_SEL(integerValue));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::UInteger NS::Number::unsignedIntegerValue() const
{
    return sendMessage<UInteger>(this, _NS_PRIVATE_SEL(unsignedIntegerValue));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::String* NS::Number::stringValue() const
{
    return sendMessage<String*>(this, _NS_PRIVATE_SEL(stringValue));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::ComparisonResult NS::Number::compare(const Number* pOtherNumber) const
{
    return sendMessage<ComparisonResult>(this, _NS_PRIVATE_SEL(compare_), pOtherNumber);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE bool NS::Number::isEqualToNumber(const Number* pNumber) const
{
    return sendMessage<bool>(this, _NS_PRIVATE_SEL(isEqualToNumber_), pNumber);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::String* NS::Number::descriptionWithLocale(const Object* pLocale) const
{
    return sendMessage<String*>(this, _NS_PRIVATE_SEL(descriptionWithLocale_), pLocale);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------
