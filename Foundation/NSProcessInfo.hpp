//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Foundation/NSProcessInfo.hpp
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
#include "NSPrivate.hpp"
#include "NSTypes.hpp"

#include <functional>

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

namespace NS
{
    _NS_CONST(NotificationName, ProcessInfoThermalStateDidChangeNotification);
    _NS_CONST(NotificationName, ProcessInfoPowerStateDidChangeNotification);
    _NS_CONST(NotificationName, ProcessInfoPerformanceProfileDidChangeNotification);

    _NS_ENUM(NS::Integer, ProcessInfoThermalState){ ProcessInfoThermalStateNominal  = 0,
                                                    ProcessInfoThermalStateFair     = 1,
                                                    ProcessInfoThermalStateSerious  = 2,
                                                    ProcessInfoThermalStateCritical = 3 };

    _NS_OPTIONS(std::uint64_t, ActivityOptions){
        ActivityIdleDisplaySleepDisabled             = 1ULL << 40,
        ActivityIdleSystemSleepDisabled              = 1ULL << 20,
        ActivitySuddenTerminationDisabled            = 1ULL << 14,
        ActivityAutomaticTerminationDisabled         = 1ULL << 15,
        ActivityUserInitiated                        = 0x00FFFFFFULL | ActivityIdleSystemSleepDisabled,
        ActivityUserInitiatedAllowingIdleSystemSleep = ActivityUserInitiated & ~ActivityIdleSystemSleepDisabled,
        ActivityBackground                           = 0x000000FFULL,
        ActivityLatencyCritical                      = 0xFF00000000ULL,
    };

    typedef Integer DeviceCertification;
    _NS_CONST(DeviceCertification, DeviceCertificationiPhonePerformanceGaming);

    typedef Integer ProcessPerformanceProfile;
    _NS_CONST(ProcessPerformanceProfile, ProcessPerformanceProfileDefault);
    _NS_CONST(ProcessPerformanceProfile, ProcessPerformanceProfileSustained);

    class ProcessInfo : public Referencing<ProcessInfo>
    {
    public:
        [[nodiscard]] static ProcessInfo* processInfo();

        [[nodiscard]] Array*      arguments() const;
        [[nodiscard]] Dictionary* environment() const;
        [[nodiscard]] String*     hostName() const;
        [[nodiscard]] String*     processName() const;
        void                      setProcessName(const String* pString) const;
        [[nodiscard]] int         processIdentifier() const;
        [[nodiscard]] String*     globallyUniqueString() const;

        [[nodiscard]] String* userName() const;
        [[nodiscard]] String* fullUserName() const;

        [[nodiscard]] UInteger               operatingSystem() const;
        [[nodiscard]] OperatingSystemVersion operatingSystemVersion() const;
        [[nodiscard]] String*                operatingSystemVersionString() const;
        [[nodiscard]] bool isOperatingSystemAtLeastVersion(const OperatingSystemVersion& version) const;

        [[nodiscard]] UInteger           processorCount() const;
        [[nodiscard]] UInteger           activeProcessorCount() const;
        [[nodiscard]] unsigned long long physicalMemory() const;
        [[nodiscard]] TimeInterval       systemUptime() const;

        void disableSuddenTermination() const;
        void enableSuddenTermination() const;

        void               disableAutomaticTermination(const String* pReason) const;
        void               enableAutomaticTermination(const String* pReason) const;
        [[nodiscard]] bool automaticTerminationSupportEnabled() const;
        void               setAutomaticTerminationSupportEnabled(bool enabled) const;

        [[nodiscard]] Object* beginActivity(ActivityOptions options, const String* pReason) const;
        void                  endActivity(Object* pActivity) const;
        void                  performActivity(ActivityOptions options, const String* pReason, void (^block)(void));
        void performActivity(ActivityOptions options, const String* pReason, const std::function<void()>& func);
        void performExpiringActivity(const String* pReason, void (^block)(bool expired));
        void performExpiringActivity(const String* pReason, const std::function<void(bool expired)>& func);

        [[nodiscard]] ProcessInfoThermalState thermalState() const;
        [[nodiscard]] bool                    isLowPowerModeEnabled() const;

        [[nodiscard]] bool isiOSAppOnMac() const;
        [[nodiscard]] bool isMacCatalystApp() const;

        [[nodiscard]] bool isDeviceCertified(DeviceCertification performanceTier) const;
        [[nodiscard]] bool hasPerformanceProfile(ProcessPerformanceProfile performanceProfile) const;
    };
} // namespace NS

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_PRIVATE_DEF_CONST(NS::NotificationName, ProcessInfoThermalStateDidChangeNotification);
_NS_PRIVATE_DEF_CONST(NS::NotificationName, ProcessInfoPowerStateDidChangeNotification);

// The linker searches for these symbols in the Metal framework, be sure to link it in as well:
_NS_PRIVATE_DEF_CONST(NS::NotificationName, ProcessInfoPerformanceProfileDidChangeNotification);
_NS_PRIVATE_DEF_CONST(NS::DeviceCertification, DeviceCertificationiPhonePerformanceGaming);
_NS_PRIVATE_DEF_CONST(NS::ProcessPerformanceProfile, ProcessPerformanceProfileDefault);
_NS_PRIVATE_DEF_CONST(NS::ProcessPerformanceProfile, ProcessPerformanceProfileSustained);

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::ProcessInfo* NS::ProcessInfo::processInfo()
{
    return sendMessage<ProcessInfo*>(_NS_PRIVATE_CLS(NSProcessInfo), _NS_PRIVATE_SEL(processInfo));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Array* NS::ProcessInfo::arguments() const
{
    return sendMessage<Array*>(this, _NS_PRIVATE_SEL(arguments));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Dictionary* NS::ProcessInfo::environment() const
{
    return sendMessage<Dictionary*>(this, _NS_PRIVATE_SEL(environment));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::String* NS::ProcessInfo::hostName() const
{
    return sendMessage<String*>(this, _NS_PRIVATE_SEL(hostName));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::String* NS::ProcessInfo::processName() const
{
    return sendMessage<String*>(this, _NS_PRIVATE_SEL(processName));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE void NS::ProcessInfo::setProcessName(const String* pString) const
{
    sendMessage<void>(this, _NS_PRIVATE_SEL(setProcessName_), pString);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE int NS::ProcessInfo::processIdentifier() const
{
    return sendMessage<int>(this, _NS_PRIVATE_SEL(processIdentifier));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::String* NS::ProcessInfo::globallyUniqueString() const
{
    return sendMessage<String*>(this, _NS_PRIVATE_SEL(globallyUniqueString));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::String* NS::ProcessInfo::userName() const
{
    return sendMessageSafe<String*>(this, _NS_PRIVATE_SEL(userName));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::String* NS::ProcessInfo::fullUserName() const
{
    return sendMessageSafe<String*>(this, _NS_PRIVATE_SEL(fullUserName));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::UInteger NS::ProcessInfo::operatingSystem() const
{
    return sendMessage<UInteger>(this, _NS_PRIVATE_SEL(operatingSystem));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::OperatingSystemVersion NS::ProcessInfo::operatingSystemVersion() const
{
    return sendMessage<OperatingSystemVersion>(this, _NS_PRIVATE_SEL(operatingSystemVersion));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::String* NS::ProcessInfo::operatingSystemVersionString() const
{
    return sendMessage<String*>(this, _NS_PRIVATE_SEL(operatingSystemVersionString));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE bool NS::ProcessInfo::isOperatingSystemAtLeastVersion(const OperatingSystemVersion& version) const
{
    return sendMessage<bool>(this, _NS_PRIVATE_SEL(isOperatingSystemAtLeastVersion_), version);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::UInteger NS::ProcessInfo::processorCount() const
{
    return sendMessage<UInteger>(this, _NS_PRIVATE_SEL(processorCount));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::UInteger NS::ProcessInfo::activeProcessorCount() const
{
    return sendMessage<UInteger>(this, _NS_PRIVATE_SEL(activeProcessorCount));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE unsigned long long NS::ProcessInfo::physicalMemory() const
{
    return sendMessage<unsigned long long>(this, _NS_PRIVATE_SEL(physicalMemory));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::TimeInterval NS::ProcessInfo::systemUptime() const
{
    return sendMessage<TimeInterval>(this, _NS_PRIVATE_SEL(systemUptime));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE void NS::ProcessInfo::disableSuddenTermination() const
{
    sendMessageSafe<void>(this, _NS_PRIVATE_SEL(disableSuddenTermination));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE void NS::ProcessInfo::enableSuddenTermination() const
{
    sendMessageSafe<void>(this, _NS_PRIVATE_SEL(enableSuddenTermination));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE void NS::ProcessInfo::disableAutomaticTermination(const String* pReason) const
{
    sendMessageSafe<void>(this, _NS_PRIVATE_SEL(disableAutomaticTermination_), pReason);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE void NS::ProcessInfo::enableAutomaticTermination(const String* pReason) const
{
    sendMessageSafe<void>(this, _NS_PRIVATE_SEL(enableAutomaticTermination_), pReason);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE bool NS::ProcessInfo::automaticTerminationSupportEnabled() const
{
    return sendMessageSafe<bool>(this, _NS_PRIVATE_SEL(automaticTerminationSupportEnabled));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE void NS::ProcessInfo::setAutomaticTerminationSupportEnabled(bool enabled) const
{
    sendMessageSafe<void>(this, _NS_PRIVATE_SEL(setAutomaticTerminationSupportEnabled_), enabled);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Object* NS::ProcessInfo::beginActivity(const ActivityOptions options, const String* pReason) const
{
    return sendMessage<Object*>(this, _NS_PRIVATE_SEL(beginActivityWithOptions_reason_), options, pReason);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE void NS::ProcessInfo::endActivity(Object* pActivity) const
{
    sendMessage<void>(this, _NS_PRIVATE_SEL(endActivity_), pActivity);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE void NS::ProcessInfo::performActivity(ActivityOptions options, const String* pReason, void (^block)(void))
{
    Object::sendMessage<void>(
        this, _NS_PRIVATE_SEL(performActivityWithOptions_reason_usingBlock_), options, pReason, block);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE void NS::ProcessInfo::performActivity(ActivityOptions              options,
                                                 const String*                pReason,
                                                 const std::function<void()>& function)
{
    __block std::function<void()> blockFunction = function;

    performActivity(options, pReason, ^{
      blockFunction();
    });
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE void NS::ProcessInfo::performExpiringActivity(const String* pReason, void (^block)(bool expired))
{
    Object::sendMessageSafe<void>(this, _NS_PRIVATE_SEL(performExpiringActivityWithReason_usingBlock_), pReason, block);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE void NS::ProcessInfo::performExpiringActivity(const String*                            pReason,
                                                         const std::function<void(bool expired)>& function)
{
    __block std::function<void(bool expired)> blockFunction = function;

    performExpiringActivity(pReason, ^(bool expired) { blockFunction(expired); });
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::ProcessInfoThermalState NS::ProcessInfo::thermalState() const
{
    return sendMessage<ProcessInfoThermalState>(this, _NS_PRIVATE_SEL(thermalState));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE bool NS::ProcessInfo::isLowPowerModeEnabled() const
{
    return sendMessageSafe<bool>(this, _NS_PRIVATE_SEL(isLowPowerModeEnabled));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE bool NS::ProcessInfo::isiOSAppOnMac() const
{
    return sendMessageSafe<bool>(this, _NS_PRIVATE_SEL(isiOSAppOnMac));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE bool NS::ProcessInfo::isMacCatalystApp() const
{
    return sendMessageSafe<bool>(this, _NS_PRIVATE_SEL(isMacCatalystApp));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE bool NS::ProcessInfo::isDeviceCertified(DeviceCertification performanceTier) const
{
    return sendMessageSafe<bool>(this, _NS_PRIVATE_SEL(isDeviceCertified_), performanceTier);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE bool NS::ProcessInfo::hasPerformanceProfile(ProcessPerformanceProfile performanceProfile) const
{
    return sendMessageSafe<bool>(this, _NS_PRIVATE_SEL(hasPerformanceProfile_), performanceProfile);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------
