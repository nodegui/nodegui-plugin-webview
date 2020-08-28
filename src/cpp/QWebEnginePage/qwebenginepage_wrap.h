#pragma once

#include <napi.h>
#include <nodegui/core/Component/component_macro.h>
#include <QWebEnginePage>

class QWebEnginePageWrap : public Napi::ObjectWrap<QWebEnginePageWrap> {
  COMPONENT_WRAPPED_METHODS_DECLARATION

 private:
  QWebEnginePage* instance;

 public:
  static Napi::FunctionReference constructor;
  static Napi::Object init(Napi::Env env, Napi::Object exports);
  QWebEnginePageWrap(const Napi::CallbackInfo& info);
  QWebEnginePage* getInternalInstance();
  // Wrapped methods
  Napi::Value runJavaScript(const Napi::CallbackInfo& info);
  Napi::Value setWebChannel(const Napi::CallbackInfo& info);
  Napi::Value webChannel(const Napi::CallbackInfo& info);
};
