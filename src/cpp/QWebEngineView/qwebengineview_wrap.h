#pragma once

#include <napi.h>

#include <QPointer>

#include "nodegui/QtWidgets/QWidget/qwidget_macro.h"
#include "nwebengineview.hpp"

class QWebEngineViewWrap : public Napi::ObjectWrap<QWebEngineViewWrap> {
  QWIDGET_WRAPPED_METHODS_DECLARATION
 private:
  NWebEngineView* instance;

 public:
  static Napi::Object init(Napi::Env env, Napi::Object exports);
  QWebEngineViewWrap(const Napi::CallbackInfo& info);
  ~QWebEngineViewWrap();
  NWebEngineView* getInternalInstance();
  // class constructor
  static Napi::FunctionReference constructor;
  // wrapped methods
  Napi::Value settings(const Napi::CallbackInfo& info);
};
