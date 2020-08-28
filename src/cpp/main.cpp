#include <napi.h>

#include "src/cpp/QWebEngineSettings/qwebenginesettings_wrap.h"
#include "src/cpp/QWebEnginePage/qwebenginepage_wrap.h"
#include "src/cpp/QWebEngineView/qwebengineview_wrap.h"
#include "src/cpp/QWebChannel/qwebchannel_wrap.h"

Napi::Object Main(Napi::Env env, Napi::Object exports) {
  QWebEngineViewWrap::init(env, exports);
  QWebEngineSettingsWrap::init(env, exports);
  QWebEnginePageWrap::init(env, exports);
  QWebChannelWrap::init(env, exports);
  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Main)
