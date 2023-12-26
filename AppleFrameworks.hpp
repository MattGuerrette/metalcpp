#pragma once

#ifdef APPLE_FRAMEWORKS_CPP_INSIDE
#define NS_PRIVATE_IMPLEMENTATION
#define MTL_PRIVATE_IMPLEMENTATION
#define MTK_PRIVATE_IMPLEMENTATION
#define MTLFX_PRIVATE_IMPLEMENTATION
#define CA_PRIVATE_IMPLEMENTATION
#endif

#include "Foundation/Foundation.hpp"
#include "Metal/Metal.hpp"
#include "MetalKit/MetalKit.hpp"
#include "MetalFX/MetalFX.hpp"
#include "QuartzCore/QuartzCore.hpp"
#include "AppKit/AppKit.hpp"
