//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Foundation/NSBundle.hpp
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
#include "NSNotification.hpp"
#include "NSObject.hpp"

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

namespace NS
{
    _NS_CONST(NotificationName, BundleDidLoadNotification);
    _NS_CONST(NotificationName, BundleResourceRequestLowDiskSpaceNotification);

    String* LocalizedString(const String* pKey, const String*);
    String* LocalizedStringFromTable(const String* pKey, const String* pTbl, const String*);
    String* LocalizedStringFromTableInBundle(const String*       pKey,
                                             const String*       pTbl,
                                             const class Bundle* pBdl,
                                             const String*);
    String* LocalizedStringWithDefaultValue(
        const String* pKey, const String* pTbl, const Bundle* pBdl, const String* pVal, const String*);

    class Bundle : public Referencing<Bundle>
    {
    public:
        static Bundle* mainBundle();

        static Bundle* bundle(const String* pPath);
        static Bundle* bundle(const class URL* pURL);

        static Array* allBundles();
        static Array* allFrameworks();

        static Bundle* alloc();

        Bundle* init(const String* pPath) const;
        Bundle* init(const URL* pURL) const;

        [[nodiscard]] bool load() const;
        [[nodiscard]] bool unload() const;

        [[nodiscard]] bool isLoaded() const;

        bool preflightAndReturnError(class Error** pError) const;
        bool loadAndReturnError(Error** pError) const;

        [[nodiscard]] URL* bundleURL() const;
        [[nodiscard]] URL* resourceURL() const;
        [[nodiscard]] URL* executableURL() const;
        [[nodiscard]] URL* URLForAuxiliaryExecutable(const String* pExecutableName) const;

        [[nodiscard]] URL* privateFrameworksURL() const;
        [[nodiscard]] URL* sharedFrameworksURL() const;
        [[nodiscard]] URL* sharedSupportURL() const;
        [[nodiscard]] URL* builtInPlugInsURL() const;
        [[nodiscard]] URL* appStoreReceiptURL() const;

        [[nodiscard]] String* bundlePath() const;
        [[nodiscard]] String* resourcePath() const;
        [[nodiscard]] String* executablePath() const;
        [[nodiscard]] String* pathForAuxiliaryExecutable(const String* pExecutableName) const;

        [[nodiscard]] String* privateFrameworksPath() const;
        [[nodiscard]] String* sharedFrameworksPath() const;
        [[nodiscard]] String* sharedSupportPath() const;
        [[nodiscard]] String* builtInPlugInsPath() const;

        [[nodiscard]] String*     bundleIdentifier() const;
        [[nodiscard]] Dictionary* infoDictionary() const;
        [[nodiscard]] Dictionary* localizedInfoDictionary() const;
        [[nodiscard]] Object*     objectForInfoDictionaryKey(const String* pKey) const;

        [[nodiscard]] String* localizedString(const String* pKey,
                                              const String* pValue     = nullptr,
                                              const String* pTableName = nullptr) const;
    };
} // namespace NS

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_PRIVATE_DEF_CONST(NS::NotificationName, BundleDidLoadNotification);
_NS_PRIVATE_DEF_CONST(NS::NotificationName, BundleResourceRequestLowDiskSpaceNotification);

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::String* NS::LocalizedString(const String* pKey, const String*)
{
    return Bundle::mainBundle()->localizedString(pKey, nullptr, nullptr);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::String* NS::LocalizedStringFromTable(const String* pKey, const String* pTbl, const String*)
{
    return Bundle::mainBundle()->localizedString(pKey, nullptr, pTbl);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::String* NS::LocalizedStringFromTableInBundle(const String* pKey,
                                                            const String* pTbl,
                                                            const Bundle* pBdl,
                                                            const String*)
{
    return pBdl->localizedString(pKey, nullptr, pTbl);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::String* NS::LocalizedStringWithDefaultValue(
    const String* pKey, const String* pTbl, const Bundle* pBdl, const String* pVal, const String*)
{
    return pBdl->localizedString(pKey, pVal, pTbl);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Bundle* NS::Bundle::mainBundle()
{
    return sendMessage<Bundle*>(_NS_PRIVATE_CLS(NSBundle), _NS_PRIVATE_SEL(mainBundle));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Bundle* NS::Bundle::bundle(const String* pPath)
{
    return sendMessage<Bundle*>(_NS_PRIVATE_CLS(NSBundle), _NS_PRIVATE_SEL(bundleWithPath_), pPath);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Bundle* NS::Bundle::bundle(const URL* pURL)
{
    return sendMessage<Bundle*>(_NS_PRIVATE_CLS(NSBundle), _NS_PRIVATE_SEL(bundleWithURL_), pURL);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Array* NS::Bundle::allBundles()
{
    return sendMessage<Array*>(_NS_PRIVATE_CLS(NSBundle), _NS_PRIVATE_SEL(allBundles));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Array* NS::Bundle::allFrameworks()
{
    return sendMessage<Array*>(_NS_PRIVATE_CLS(NSBundle), _NS_PRIVATE_SEL(allFrameworks));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Bundle* NS::Bundle::alloc()
{
    return sendMessage<Bundle*>(_NS_PRIVATE_CLS(NSBundle), _NS_PRIVATE_SEL(alloc));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Bundle* NS::Bundle::init(const String* pPath) const
{
    return sendMessage<Bundle*>(this, _NS_PRIVATE_SEL(initWithPath_), pPath);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Bundle* NS::Bundle::init(const URL* pURL) const
{
    return sendMessage<Bundle*>(this, _NS_PRIVATE_SEL(initWithURL_), pURL);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE bool NS::Bundle::load() const { return sendMessage<bool>(this, _NS_PRIVATE_SEL(load)); }

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE bool NS::Bundle::unload() const { return sendMessage<bool>(this, _NS_PRIVATE_SEL(unload)); }

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE bool NS::Bundle::isLoaded() const { return sendMessage<bool>(this, _NS_PRIVATE_SEL(isLoaded)); }

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE bool NS::Bundle::preflightAndReturnError(Error** pError) const
{
    return sendMessage<bool>(this, _NS_PRIVATE_SEL(preflightAndReturnError_), pError);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE bool NS::Bundle::loadAndReturnError(Error** pError) const
{
    return sendMessage<bool>(this, _NS_PRIVATE_SEL(loadAndReturnError_), pError);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::URL* NS::Bundle::bundleURL() const { return sendMessage<URL*>(this, _NS_PRIVATE_SEL(bundleURL)); }

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::URL* NS::Bundle::resourceURL() const { return sendMessage<URL*>(this, _NS_PRIVATE_SEL(resourceURL)); }

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::URL* NS::Bundle::executableURL() const
{
    return sendMessage<URL*>(this, _NS_PRIVATE_SEL(executableURL));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::URL* NS::Bundle::URLForAuxiliaryExecutable(const String* pExecutableName) const
{
    return sendMessage<URL*>(this, _NS_PRIVATE_SEL(URLForAuxiliaryExecutable_), pExecutableName);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::URL* NS::Bundle::privateFrameworksURL() const
{
    return sendMessage<URL*>(this, _NS_PRIVATE_SEL(privateFrameworksURL));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::URL* NS::Bundle::sharedFrameworksURL() const
{
    return sendMessage<URL*>(this, _NS_PRIVATE_SEL(sharedFrameworksURL));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::URL* NS::Bundle::sharedSupportURL() const
{
    return sendMessage<URL*>(this, _NS_PRIVATE_SEL(sharedSupportURL));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::URL* NS::Bundle::builtInPlugInsURL() const
{
    return sendMessage<URL*>(this, _NS_PRIVATE_SEL(builtInPlugInsURL));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::URL* NS::Bundle::appStoreReceiptURL() const
{
    return sendMessage<URL*>(this, _NS_PRIVATE_SEL(appStoreReceiptURL));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::String* NS::Bundle::bundlePath() const
{
    return sendMessage<String*>(this, _NS_PRIVATE_SEL(bundlePath));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::String* NS::Bundle::resourcePath() const
{
    return sendMessage<String*>(this, _NS_PRIVATE_SEL(resourcePath));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::String* NS::Bundle::executablePath() const
{
    return sendMessage<String*>(this, _NS_PRIVATE_SEL(executablePath));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::String* NS::Bundle::pathForAuxiliaryExecutable(const String* pExecutableName) const
{
    return sendMessage<String*>(this, _NS_PRIVATE_SEL(pathForAuxiliaryExecutable_), pExecutableName);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::String* NS::Bundle::privateFrameworksPath() const
{
    return sendMessage<String*>(this, _NS_PRIVATE_SEL(privateFrameworksPath));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::String* NS::Bundle::sharedFrameworksPath() const
{
    return sendMessage<String*>(this, _NS_PRIVATE_SEL(sharedFrameworksPath));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::String* NS::Bundle::sharedSupportPath() const
{
    return sendMessage<String*>(this, _NS_PRIVATE_SEL(sharedSupportPath));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::String* NS::Bundle::builtInPlugInsPath() const
{
    return sendMessage<String*>(this, _NS_PRIVATE_SEL(builtInPlugInsPath));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::String* NS::Bundle::bundleIdentifier() const
{
    return sendMessage<String*>(this, _NS_PRIVATE_SEL(bundleIdentifier));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Dictionary* NS::Bundle::infoDictionary() const
{
    return sendMessage<Dictionary*>(this, _NS_PRIVATE_SEL(infoDictionary));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Dictionary* NS::Bundle::localizedInfoDictionary() const
{
    return sendMessage<Dictionary*>(this, _NS_PRIVATE_SEL(localizedInfoDictionary));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Object* NS::Bundle::objectForInfoDictionaryKey(const String* pKey) const
{
    return sendMessage<Object*>(this, _NS_PRIVATE_SEL(objectForInfoDictionaryKey_), pKey);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::String* NS::Bundle::localizedString(const String* pKey,
                                                   const String* pValue /* = nullptr */,
                                                   const String* pTableName /* = nullptr */) const
{
    return sendMessage<String*>(this, _NS_PRIVATE_SEL(localizedStringForKey_value_table_), pKey, pValue, pTableName);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------
