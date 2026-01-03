//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Foundation/Foundation.hpp
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

#pragma once

#define METAL_CPP_CPLUSPLUS __cplusplus

#if 202002L < METAL_CPP_CPLUSPLUS
#define METAL_CPP_VERSION 23
#elif 201703L < METAL_CPP_CPLUSPLUS
#define METAL_CPP_VERSION 20
#elif 201402L < METAL_CPP_CPLUSPLUS
#define METAL_CPP_VERSION 17
#else
#error "Metal C++ requires at least C++17"
#endif

#if 23 <= METAL_CPP_VERSION && __has_include(<expected>)
#define METAL_CPP_HAS_EXPECTED 1
#include <expected>
#endif

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#include "NSArray.hpp"
#include "NSAutoreleasePool.hpp"
#include "NSBundle.hpp"
#include "NSData.hpp"
#include "NSDate.hpp"
#include "NSDefines.hpp"
#include "NSDictionary.hpp"
#include "NSEnumerator.hpp"
#include "NSError.hpp"
#include "NSLock.hpp"
#include "NSNotification.hpp"
#include "NSNumber.hpp"
#include "NSObject.hpp"
#include "NSPrivate.hpp"
#include "NSProcessInfo.hpp"
#include "NSRange.hpp"
#include "NSRunLoop.hpp"
#include "NSSet.hpp"
#include "NSSharedPtr.hpp"
#include "NSString.hpp"
#include "NSTypes.hpp"
#include "NSURL.hpp"

//-------------------------------------------------------------------------------------------------------------------------------------------------------------
