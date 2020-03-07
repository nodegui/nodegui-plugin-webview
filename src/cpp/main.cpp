#include <napi.h>
#include <QtWebEngine>

#include "src/cpp/QWebEngineSettings/qwebenginesettings_wrap.h"
#include "src/cpp/QWebEngineView/qwebengineview_wrap.h"

Napi::Object Main(Napi::Env env, Napi::Object exports) {
  QtWebEngine::initialize();
  QWebEngineViewWrap::init(env, exports);
  QWebEngineSettingsWrap::init(env, exports);
  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Main)
