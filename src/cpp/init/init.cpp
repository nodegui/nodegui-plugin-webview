#include <napi.h>
#include <QtWebEngine>

Napi::Object Main(Napi::Env env, Napi::Object exports) {
  QtWebEngine::initialize();
  return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Main)
