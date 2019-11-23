#include "src/cpp/QStatusBar/qstatusbar_wrap.h"
#include <napi.h>

Napi::Object Main(Napi::Env env, Napi::Object exports) {
    QStatusBarWrap::init(env, exports);
    return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Main)
