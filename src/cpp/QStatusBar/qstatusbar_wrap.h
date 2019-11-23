#pragma once
#include "nstatusbar.hpp"
#include <QPointer>
#include <napi.h>
#include <nodegui/QtWidgets/QWidget/qwidget_macro.h>
#include <stdlib.h>

class QStatusBarWrap : public Napi::ObjectWrap<QStatusBarWrap>
{
private:
  QPointer<NStatusBar> instance;

public:
  static Napi::Object init(Napi::Env env, Napi::Object exports);
  QStatusBarWrap(const Napi::CallbackInfo &info);
  ~QStatusBarWrap();
  NStatusBar *getInternalInstance();
  static Napi::FunctionReference constructor;
  //wrapped methods
  Napi::Value showMessage(const Napi::CallbackInfo &info);

  QWIDGET_WRAPPED_METHODS_DECLARATION
};
