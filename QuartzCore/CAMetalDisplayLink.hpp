
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// QuartzCore/CAMetalDisplayLink.hpp
//
// Copyright 2020-2023 Apple Inc.
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

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#include "../Metal/MTLDrawable.hpp"
#include "../Metal/MTLTexture.hpp"

#include "CADefines.hpp"
#include "CAPrivate.hpp"

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

namespace CA
{
    class MetalDisplayLinkDelegate
    {
    public:
        virtual ~MetalDisplayLinkDelegate() = default;

        /// @brief Metal display link callback
        /// @param [in] displayLink The display link.
        /// @param [in] update The display link update containing frame drawable.
        /// @note This method is called by the CA::MetalDisplayLink's associated NS::RunLoop
        /// which wraps the call in an NS::AutoReleasePool. Any Objective-C runtime allocated
        /// objects during this call will be automatically released and should not explicitly
        /// call release() or use NS::SharedPtr.
        virtual void metalDisplayLinkNeedsUpdate(class MetalDisplayLink* displayLink, class MetalDisplayLinkUpdate* update) = 0;
    };
    
    class MetalDisplayLinkUpdate : public NS::Referencing<MetalDisplayLinkUpdate>
    {
    public:
        [[nodiscard]] class MetalDrawable* drawable() const;
        [[nodiscard]] CFTimeInterval targetPresentationTimestamp() const;
        [[nodiscard]] CFTimeInterval targetTimestamp() const;
    };
    
    class MetalDisplayLink : public NS::Referencing<MetalDisplayLink>
    {
    public:
        static MetalDisplayLink*    alloc();
        
        MetalDisplayLink* init(class MetalLayer* layer);
        
        void                        setDelegate( const CA::MetalDisplayLinkDelegate* pDelegate );
        MetalDisplayLinkDelegate*   delegate() const;
        
        void addToRunLoop(class NS::RunLoop* runLoop, NS::RunLoopMode mode);
        void removeFromRunLoop(class NS::RunLoop* runLoop, NS::RunLoopMode mode);
    };
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_CA_INLINE CA::MetalDisplayLink* CA::MetalDisplayLink::alloc()
{
    return Object::alloc< MetalDisplayLink >( _CA_PRIVATE_CLS( CAMetalDisplayLink ) );
}

_CA_INLINE CA::MetalDisplayLink* CA::MetalDisplayLink::init(CA::MetalLayer* layer)
{
    return Object::sendMessage< MetalDisplayLink* >( this, _CA_PRIVATE_SEL( initWithMetalLayer ), layer);
}

_CA_INLINE void CA::MetalDisplayLink::setDelegate(const CA::MetalDisplayLinkDelegate *pDelegate)
{
    // TODO: Same problem as NS::Application::setDelegate.
    // Requires a similar soution
    NS::Value* pWrapper = NS::Value::value( pDelegate );

    // metalDisplayLinkNeedsUpdate:

    void (*metalDisplayLinkNeedsUpdateDispatch)( NS::Value*, SEL, id, id) = []( NS::Value* pSelf, SEL _cmd, id pDisplayLink, id pUpdate ){
        auto pDel = reinterpret_cast< CA::MetalDisplayLinkDelegate* >( pSelf->pointerValue() );
        
#ifdef __OBJC__
        pDel->metalDisplayLinkNeedsUpdate((__bridge CA::MetalDisplayLink*)pDisplayLink, (__bridge CA::MetalDisplayLinkUpdate*)pUpdate);
#else
        pDel->metalDisplayLinkNeedsUpdate((CA::MetalDisplayLink*)pDisplayLink, (CA::MetalDisplayLinkUpdate*)pUpdate);
#endif
    };

    class_addMethod( (Class)objc_lookUpClass( "NSValue" ), sel_registerName( "metalDisplayLink:needsUpdate:" ), (IMP)metalDisplayLinkNeedsUpdateDispatch, "v@:@v@:@" );

    NS::Object::sendMessage< void >( this, sel_registerName( "setDelegate:" ), pWrapper );
}

_CA_INLINE CA::MetalDisplayLinkDelegate* CA::MetalDisplayLink::delegate() const
{
    NS::Value* pWrapper = NS::Object::sendMessage< NS::Value* >( this, _CA_PRIVATE_SEL( delegate ) );
    if ( pWrapper )
    {
        return reinterpret_cast< MetalDisplayLinkDelegate* >( pWrapper->pointerValue() );
    }
    return nullptr;
}

_CA_INLINE void CA::MetalDisplayLink::addToRunLoop(class NS::RunLoop *runLoop, NS::RunLoopMode mode)
{
    NS::Object::sendMessage<void>(this, _CA_PRIVATE_SEL(addToRunLoop_), runLoop, mode);
}

_CA_INLINE void CA::MetalDisplayLink::removeFromRunLoop(class NS::RunLoop* runLoop, NS::RunLoopMode mode)
{
    NS::Object::sendMessage<void>(this, _CA_PRIVATE_SEL(removeFromRunLoop_), runLoop, mode);
}


//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_CA_INLINE CA::MetalDrawable* CA::MetalDisplayLinkUpdate::drawable() const
{
    return Object::sendMessage<class MetalDrawable*>( this, _CA_PRIVATE_SEL(drawable));
}

_CA_INLINE CFTimeInterval CA::MetalDisplayLinkUpdate::targetPresentationTimestamp() const
{
    return Object::sendMessage<CFTimeInterval>(this, _CA_PRIVATE_SEL(targetPresentationTimestamp));
}

_CA_INLINE CFTimeInterval CA::MetalDisplayLinkUpdate::targetTimestamp() const
{
    return Object::sendMessage<CFTimeInterval>(this, _CA_PRIVATE_SEL(targetTimestamp));
}
