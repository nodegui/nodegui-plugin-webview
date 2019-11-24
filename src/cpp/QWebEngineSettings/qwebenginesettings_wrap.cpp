#include "qwebenginesettings_wrap.h"

#include "Extras/Utils/nutils.h"

Napi::FunctionReference QWebEngineSettingsWrap::constructor;

Napi::Object QWebEngineSettingsWrap::init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "QWebEngineSettings";
  Napi::Function func = DefineClass(
      env, CLASSNAME,
      {InstanceMethod("setUnknownUrlSchemePolicy",
                      &QWebEngineSettingsWrap::setUnknownUrlSchemePolicy),
       COMPONENT_WRAPPED_METHODS_EXPORT_DEFINE});
  constructor = Napi::Persistent(func);
  exports.Set(CLASSNAME, func);
  return exports;
}

QWebEngineSettingsWrap::QWebEngineSettingsWrap(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<QWebEngineSettingsWrap>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);
  if (info[0].IsExternal()) {
    this->instance = info[0].As<Napi::External<QWebEngineSettings>>().Data();
  } else {
    Napi::TypeError::New(env,
                         "Incorrect initialization of QWebEngineSettingsWrap")
        .ThrowAsJavaScriptException();
  }
  this->rawData = extrautils::configureComponent(this->getInternalInstance());
}

QWebEngineSettings* QWebEngineSettingsWrap::getInternalInstance() {
  return this->instance;
}

Napi::Value QWebEngineSettingsWrap::setUnknownUrlSchemePolicy(
    const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);
  Napi::Number mode = info[0].As<Napi::Number>();
  this->instance->setUnknownUrlSchemePolicy(
      static_cast<QWebEngineSettings::UnknownUrlSchemePolicy>(
          mode.Int32Value()));
  return env.Null();
}
