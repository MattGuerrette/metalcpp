//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Foundation/NSString.hpp
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

#include "NSDefines.hpp"
#include "NSObjCRuntime.hpp"
#include "NSObject.hpp"
#include "NSPrivate.hpp"
#include "NSRange.hpp"
#include "NSTypes.hpp"

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

namespace NS
{
    _NS_ENUM(NS::UInteger, StringEncoding){ ASCIIStringEncoding         = 1,
                                            NEXTSTEPStringEncoding      = 2,
                                            JapaneseEUCStringEncoding   = 3,
                                            UTF8StringEncoding          = 4,
                                            ISOLatin1StringEncoding     = 5,
                                            SymbolStringEncoding        = 6,
                                            NonLossyASCIIStringEncoding = 7,
                                            ShiftJISStringEncoding      = 8,
                                            ISOLatin2StringEncoding     = 9,
                                            UnicodeStringEncoding       = 10,
                                            WindowsCP1251StringEncoding = 11,
                                            WindowsCP1252StringEncoding = 12,
                                            WindowsCP1253StringEncoding = 13,
                                            WindowsCP1254StringEncoding = 14,
                                            WindowsCP1250StringEncoding = 15,
                                            ISO2022JPStringEncoding     = 21,
                                            MacOSRomanStringEncoding    = 30,

                                            UTF16StringEncoding = UnicodeStringEncoding,

                                            UTF16BigEndianStringEncoding    = 0x90000100,
                                            UTF16LittleEndianStringEncoding = 0x94000100,

                                            UTF32StringEncoding             = 0x8c000100,
                                            UTF32BigEndianStringEncoding    = 0x98000100,
                                            UTF32LittleEndianStringEncoding = 0x9c000100 };

    _NS_OPTIONS(NS::UInteger, StringCompareOptions){
        CaseInsensitiveSearch = 1,    LiteralSearch = 2,          BackwardsSearch = 4,
        AnchoredSearch = 8,           NumericSearch = 64,         DiacriticInsensitiveSearch = 128,
        WidthInsensitiveSearch = 256, ForcedOrderingSearch = 512, RegularExpressionSearch = 1024
    };

    using unichar = unsigned short;

    class String : public Copying<String>
    {
    public:
        static String* string();
        static String* string(const String* pString);
        static String* string(const char* pString, StringEncoding encoding);

        static String* alloc();
        String*        init();
        String*        init(const String* pString) const;
        String*        init(const char* pString, StringEncoding encoding) const;
        String*        init(void* pBytes, UInteger len, StringEncoding encoding, bool freeBuffer) const;

        [[nodiscard]] unichar  character(UInteger index) const;
        [[nodiscard]] UInteger length() const;

        [[nodiscard]] const char* cString(StringEncoding encoding) const;
        [[nodiscard]] const char* utf8String() const;
        [[nodiscard]] UInteger    maximumLengthOfBytes(StringEncoding encoding) const;
        [[nodiscard]] UInteger    lengthOfBytes(StringEncoding encoding) const;

        bool  isEqualToString(const String* pString) const;
        Range rangeOfString(const String* pString, StringCompareOptions options) const;

        [[nodiscard]] const char* fileSystemRepresentation() const;

        String*          stringByAppendingString(const String* pString) const;
        ComparisonResult caseInsensitiveCompare(const String* pString) const;
    };

/// Create an NS::String* from a string literal.
#define MTLSTR(literal) (NS::String*)__builtin___CFStringMakeConstantString("" literal "")

    template<std::size_t _StringLen> // NOLINT(*-reserved-identifier)
    [[deprecated("please use MTLSTR(str)")]] constexpr const String* MakeConstantString(const char (&str)[_StringLen])
    {
        return reinterpret_cast<const String*>(__CFStringMakeConstantString(str));
    }

} // namespace NS

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::String* NS::String::string()
{
    return sendMessage<String*>(_NS_PRIVATE_CLS(NSString), _NS_PRIVATE_SEL(string));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::String* NS::String::string(const String* pString)
{
    return sendMessage<String*>(_NS_PRIVATE_CLS(NSString), _NS_PRIVATE_SEL(stringWithString_), pString);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::String* NS::String::string(const char* pString, const StringEncoding encoding)
{
    return sendMessage<String*>(
        _NS_PRIVATE_CLS(NSString), _NS_PRIVATE_SEL(stringWithCString_encoding_), pString, encoding);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::String* NS::String::alloc()
{
    // ReSharper disable once CppRedundantQualifier
    return Object::alloc<String>(_NS_PRIVATE_CLS(NSString));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::String* NS::String::init()
{
    // ReSharper disable once CppRedundantQualifier
    return Object::init<String>();
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::String* NS::String::init(const String* pString) const
{
    return sendMessage<String*>(this, _NS_PRIVATE_SEL(initWithString_), pString);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::String* NS::String::init(const char* pString, const StringEncoding encoding) const
{
    return sendMessage<String*>(this, _NS_PRIVATE_SEL(initWithCString_encoding_), pString, encoding);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::String* NS::String::init(void*                pBytes,
                                        const UInteger       len,
                                        const StringEncoding encoding,
                                        const bool           freeBuffer) const
{
    return sendMessage<String*>(
        this, _NS_PRIVATE_SEL(initWithBytesNoCopy_length_encoding_freeWhenDone_), pBytes, len, encoding, freeBuffer);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::unichar NS::String::character(const UInteger index) const
{
    return sendMessage<unichar>(this, _NS_PRIVATE_SEL(characterAtIndex_), index);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::UInteger NS::String::length() const { return sendMessage<UInteger>(this, _NS_PRIVATE_SEL(length)); }

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE const char* NS::String::cString(const StringEncoding encoding) const
{
    return sendMessage<const char*>(this, _NS_PRIVATE_SEL(cStringUsingEncoding_), encoding);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE const char* NS::String::utf8String() const
{
    return sendMessage<const char*>(this, _NS_PRIVATE_SEL(UTF8String));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::UInteger NS::String::maximumLengthOfBytes(const StringEncoding encoding) const
{
    return sendMessage<UInteger>(this, _NS_PRIVATE_SEL(maximumLengthOfBytesUsingEncoding_), encoding);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::UInteger NS::String::lengthOfBytes(const StringEncoding encoding) const
{
    return sendMessage<UInteger>(this, _NS_PRIVATE_SEL(lengthOfBytesUsingEncoding_), encoding);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE bool NS::String::isEqualToString(const String* pString) const
{
    return sendMessage<bool>(this, _NS_PRIVATE_SEL(isEqualToString_), pString);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Range NS::String::rangeOfString(const String* pString, const StringCompareOptions options) const
{
    return sendMessage<Range>(this, _NS_PRIVATE_SEL(rangeOfString_options_), pString, options);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE const char* NS::String::fileSystemRepresentation() const
{
    return sendMessage<const char*>(this, _NS_PRIVATE_SEL(fileSystemRepresentation));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::String* NS::String::stringByAppendingString(const String* pString) const
{
    return sendMessage<String*>(this, _NS_PRIVATE_SEL(stringByAppendingString_), pString);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::ComparisonResult NS::String::caseInsensitiveCompare(const String* pString) const
{
    return sendMessage<ComparisonResult>(this, _NS_PRIVATE_SEL(caseInsensitiveCompare_), pString);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------
