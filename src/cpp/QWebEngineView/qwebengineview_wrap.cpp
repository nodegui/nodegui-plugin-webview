#include "qwebengineview_wrap.h"

#include <nodegui/Extras/Utils/nutils.h>
#include <nodegui/QtWidgets/QWidget/qwidget_wrap.h>

#include <QWidget>

Napi::FunctionReference QWebEngineViewWrap::constructor;

Napi::Object QWebEngineViewWrap::init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "QWebEngineView";
  Napi::Function func = DefineClass(
      env, CLASSNAME,
      {// InstanceMethod("showMessage", &QWebEngineViewWrap::showMessage),
       QWIDGET_WRAPPED_METHODS_EXPORT_DEFINE(QWebEngineViewWrap)});
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  return exports;
}

NWebEngineView *QWebEngineViewWrap::getInternalInstance() {
  return this->instance;
}

QWebEngineViewWrap::QWebEngineViewWrap(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<QWebEngineViewWrap>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() == 1) {
    Napi::Object parentObject = info[0].As<Napi::Object>();
    QWidgetWrap *parentWidgetWrap =
        Napi::ObjectWrap<QWidgetWrap>::Unwrap(parentObject);
    this->instance =
        new NWebEngineView(parentWidgetWrap->getInternalInstance());
  } else if (info.Length() == 0) {
    this->instance = new NWebEngineView();
  } else {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
  }
  // Adds measure function on yoga node so that widget size is calculated based
  // on its text also.
  YGNodeSetMeasureFunc(this->instance->getFlexNode(),
                       &extrautils::measureQtWidget);
}

QWebEngineViewWrap::~QWebEngineViewWrap() {
  extrautils::safeDelete(this->instance);
}

// Napi::Value QWebEngineViewWrap::showMessage(const Napi::CallbackInfo &info) {
//   Napi::Env env = info.Env();
//   Napi::HandleScope scope(env);

//   Napi::String message = info[0].As<Napi::String>();
//   Napi::Number timeout = info[1].As<Napi::Number>();
//   this->instance->showMessage(QString::fromStdString(message.Utf8Value()),
//                               timeout.Int32Value());

//   return env.Null();
// }
