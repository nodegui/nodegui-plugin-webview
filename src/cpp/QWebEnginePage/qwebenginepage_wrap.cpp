#include "qwebenginepage_wrap.h"

#include "Extras/Utils/nutils.h"

Napi::FunctionReference QWebEnginePageWrap::constructor;

Napi::Object QWebEnginePageWrap::init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  char CLASSNAME[] = "QWebEnginePage";
  Napi::Function func = DefineClass(
      env, CLASSNAME,
      {InstanceMethod("runJavaScript", &QWebEnginePageWrap::runJavaScript),
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
