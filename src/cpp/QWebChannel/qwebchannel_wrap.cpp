#include "qwebchannel_wrap.h"

#include <QDebug>
#include <QObject>
#include <QWebChannel>

#include "nodegui/Extras/Utils/nutils.h"
#include "nodegui/QtCore/QObject/qobject_wrap.h"

Napi::FunctionReference QWebChannelWrap::constructor;

Napi::Object QWebChannelWrap::init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "QWebChannel";
  Napi::Function func = DefineClass(
      env, CLASSNAME,
      {InstanceMethod("registerObject", &QWebChannelWrap::registerObject),
       InstanceMethod("deregisterObject", &QWebChannelWrap::deregisterObject),
       COMPONENT_WRAPPED_METHODS_EXPORT_DEFINE(QWebChannelWrap)});
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  return exports;
}

QWebChannelWrap::QWebChannelWrap(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<QWebChannelWrap>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info[0].IsExternal()) {
    this->instance = info[0].As<Napi::External<NWebChannel>>().Data();
  } else if (info.Length() == 1) {
    Napi::Object parentObject = info[0].As<Napi::Object>();
    QObjectWrap* parentWrap =
        Napi::ObjectWrap<QObjectWrap>::Unwrap(parentObject);
    this->instance = new NWebChannel(parentWrap->getInternalInstance());
  } else if (info.Length() == 0) {
    this->instance = new NWebChannel();
  } else {
    Napi::TypeError::New(env, "Incorrect initialization of QWebChannelWrap")
        .ThrowAsJavaScriptException();
  }
  this->rawData = extrautils::configureComponent(this->getInternalInstance());
}

QWebChannelWrap::~QWebChannelWrap() { extrautils::safeDelete(this->instance); }

NWebChannel* QWebChannelWrap::getInternalInstance() { return this->instance; }

Napi::Value QWebChannelWrap::registerObject(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  Napi::String napiName = info[0].As<Napi::String>();
  std::string name = napiName.Utf8Value();

  Napi::Object napiObject = info[1].As<Napi::Object>();
  QObjectWrap* objectWrap = Napi::ObjectWrap<QObjectWrap>::Unwrap(napiObject);

  this->instance->registerObject(QString::fromUtf8(name.c_str()),
                                 objectWrap->getInternalInstance());
  return env.Null();
}

Napi::Value QWebChannelWrap::deregisterObject(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  Napi::Object napiObject = info[0].As<Napi::Object>();
  QObjectWrap* objectWrap = Napi::ObjectWrap<QObjectWrap>::Unwrap(napiObject);

  this->instance->deregisterObject(objectWrap->getInternalInstance());
  return env.Null();
}
