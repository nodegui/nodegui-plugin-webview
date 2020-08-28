#pragma once

#include <napi.h>
#include <nodegui/Extras/Export/export.h>

#include <QPointer>

#include "QtCore/QObject/qobject_macro.h"
#include "nwebchannel.hpp"

class DLL_EXPORT QWebChannelWrap : public Napi::ObjectWrap<QWebChannelWrap> {
  QOBJECT_WRAPPED_METHODS_DECLARATION
 private:
  QPointer<NWebChannel> instance;

 public:
  static Napi::FunctionReference constructor;
  static Napi::Object init(Napi::Env env, Napi::Object exports);
  QWebChannelWrap(const Napi::CallbackInfo& info);
  ~QWebChannelWrap();
  NWebChannel* getInternalInstance();
  // Wrapped methods
  Napi::Value registerObject(const Napi::CallbackInfo& info);
  Napi::Value deregisterObject(const Napi::CallbackInfo& info);
};
