
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// AppKit/NSView.hpp
//
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#pragma once

#include "AppKitPrivate.hpp"
#include <Foundation/NSObject.hpp>

namespace NS
{
_NS_ENUM(NS::UInteger, ModalResponseType) {
    ModalResponseOk = 0,
};

using BeginSheetModelCompletionHandler = void (^)(NS::ModalResponseType response);
class OpenPanel : public NS::Referencing<OpenPanel>
{
public:
    static NS::OpenPanel* openPanel();

    NS::Array*            urls() const;
    void                  beginSheetModal(NS::Window* window, BeginSheetModelCompletionHandler handler);
};
}

_NS_INLINE NS::OpenPanel* NS::OpenPanel::openPanel()
{
    return Object::sendMessage<NS::OpenPanel*>(_NS_PRIVATE_CLS(NSOpenPanel), _APPKIT_PRIVATE_SEL(openPanel_));
}

_NS_INLINE void NS::OpenPanel::beginSheetModal(NS::Window* window, BeginSheetModelCompletionHandler handler)
{
    Object::sendMessage<void>(this, _NS_PRIVATE_SEL(beginSheetModalForWindow_completionHandler_), window, handler);
}

_NS_INLINE NS::Array* NS::OpenPanel::urls() const
{
    return Object::sendMessage<NS::Array*>(this, _NS_PRIVATE_SEL(urls_));
}