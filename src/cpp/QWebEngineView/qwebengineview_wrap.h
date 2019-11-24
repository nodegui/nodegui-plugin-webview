#pragma once
#include <napi.h>
#include <nodegui/QtWidgets/QWidget/qwidget_macro.h>

#include <QPointer>

#include "nwebengineview.hpp"

class QWebEngineViewWrap : public Napi::ObjectWrap<QWebEngineViewWrap> {
 private:
  QPointer<NWebEngineView> instance;

 public:
  static Napi::Object init(Napi::Env env, Napi::Object exports);
  QWebEngineViewWrap(const Napi::CallbackInfo &info);
  ~QWebEngineViewWrap();
  NWebEngineView *getInternalInstance();
  static Napi::FunctionReference constructor;
  // wrapped methods
  Napi::Value settings(const Napi::CallbackInfo &info);

  QWIDGET_WRAPPED_METHODS_DECLARATION
};
