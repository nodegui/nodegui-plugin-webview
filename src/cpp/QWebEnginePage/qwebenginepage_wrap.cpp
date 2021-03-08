#include "qwebenginepage_wrap.h"

#include "Extras/Utils/nutils.h"
#include "src/cpp/QWebChannel/qwebchannel_wrap.h"
#include <nodegui/QtGui/QColor/qcolor_wrap.h>


Napi::FunctionReference QWebEnginePageWrap::constructor;

Napi::Object QWebEnginePageWrap::init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "QWebEnginePage";
  Napi::Function func = DefineClass(
      env, CLASSNAME,
      {InstanceMethod("setWebChannel", &QWebEnginePageWrap::setWebChannel),
        InstanceMethod("webChannel", &QWebEnginePageWrap::webChannel),
       InstanceMethod("runJavaScript", &QWebEnginePageWrap::runJavaScript),
       InstanceMethod("setBackgroundColor", &QWebEnginePageWrap::setBackgroundColor),
       InstanceMethod("backgroundColor", &QWebEnginePageWrap::backgroundColor),
       COMPONENT_WRAPPED_METHODS_EXPORT_DEFINE(QWebEnginePageWrap)});
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  return exports;
}

QWebEnginePageWrap::QWebEnginePageWrap(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<QWebEnginePageWrap>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);
  if (info[0].IsExternal()) {
    this->instance = info[0].As<Napi::External<QWebEnginePage>>().Data();
  } else {
    Napi::TypeError::New(env, "Incorrect initialization of QWebEnginePageWrap")
        .ThrowAsJavaScriptException();
  }
  this->rawData = extrautils::configureComponent(this->getInternalInstance());
}

QWebEnginePage* QWebEnginePageWrap::getInternalInstance() {
  return this->instance;
}

Napi::Value QWebEnginePageWrap::runJavaScript(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  Napi::String napiScript = info[0].As<Napi::String>();
  std::string script = napiScript.Utf8Value();

  this->instance->runJavaScript(QString::fromUtf8(script.c_str()));
  return env.Null();
}

Napi::Value QWebEnginePageWrap::setWebChannel(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  Napi::Object channel = info[0].As<Napi::Object>();
  QWebChannelWrap* channelWrap =
      Napi::ObjectWrap<QWebChannelWrap>::Unwrap(channel);

  this->instance->setWebChannel(channelWrap->getInternalInstance());
  return env.Null();
}

Napi::Value QWebEnginePageWrap::webChannel(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  QWebChannel* webChannel = this->instance->webChannel();
  return QWebChannelWrap::constructor.New(
      {Napi::External<QWebChannel>::New(env, webChannel)});
}

Napi::Value QWebEnginePageWrap::setBackgroundColor(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);
  Napi::Object colorObject = info[0].As<Napi::Object>();
  QColorWrap* colorWrap = Napi::ObjectWrap<QColorWrap>::Unwrap(colorObject);
  this->instance->setBackgroundColor(*colorWrap->getInternalInstance());
  return env.Null();
}

Napi::Value QWebEnginePageWrap::backgroundColor(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);
  QColor color = this->instance->backgroundColor();
  auto instance = QColorWrap::constructor.New(
      {Napi::External<QColor>::New(env, new QColor(color))});
  return instance; 
}
