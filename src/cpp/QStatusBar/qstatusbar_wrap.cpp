#include "qstatusbar_wrap.h"

#include <nodegui/Extras/Utils/nutils.h>
#include <nodegui/QtWidgets/QWidget/qwidget_wrap.h>

#include <QWidget>

Napi::FunctionReference QStatusBarWrap::constructor;

Napi::Object QStatusBarWrap::init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "QStatusBar";
  Napi::Function func =
      DefineClass(env, CLASSNAME,
                  {InstanceMethod("showMessage", &QStatusBarWrap::showMessage),
                   QWIDGET_WRAPPED_METHODS_EXPORT_DEFINE(QStatusBarWrap)});
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  return exports;
}

NStatusBar *QStatusBarWrap::getInternalInstance() { return this->instance; }

QStatusBarWrap::QStatusBarWrap(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<QStatusBarWrap>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() == 1) {
    Napi::Object parentObject = info[0].As<Napi::Object>();
    QWidgetWrap *parentWidgetWrap =
        Napi::ObjectWrap<QWidgetWrap>::Unwrap(parentObject);
    this->instance = new NStatusBar(parentWidgetWrap->getInternalInstance());
  } else if (info.Length() == 0) {
    this->instance = new NStatusBar();
  } else {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  // Adds measure function on yoga node so that widget size is calculated based
  // on its text also.
  YGNodeSetMeasureFunc(this->instance->getFlexNode(),
                       &extrautils::measureQtWidget);
}

QStatusBarWrap::~QStatusBarWrap() { extrautils::safeDelete(this->instance); }

Napi::Value QStatusBarWrap::showMessage(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  Napi::String message = info[0].As<Napi::String>();
  Napi::Number timeout = info[1].As<Napi::Number>();
  this->instance->showMessage(QString::fromStdString(message.Utf8Value()),
                              timeout.Int32Value());

  return env.Null();
}
