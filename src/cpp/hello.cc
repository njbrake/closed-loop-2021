#include <napi.h>
#include "new.h"

static Napi::String Method(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  auto thingy = Loopy::Closed();
  auto result = thingy.getThing();
  std::string yada = std::to_string(result);
  return Napi::String::New(env, yada);
}

static Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "hello"),
              Napi::Function::New(env, Method));
  return exports;
}

NODE_API_MODULE(hello, Init)