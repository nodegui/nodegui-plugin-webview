#include <napi.h>

#include "src/cpp/QWebEngineView/qwebengineview_wrap.h"

Napi::Object Main(Napi::Env env, Napi::Object exports) {
  QWebEngineViewWrap::init(env, exports);
  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Main)
