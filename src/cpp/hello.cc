#include <napi.h>

static Napi::String HelloMethod(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  return Napi::String::New(env, "hello world!");
}

// This is what initializes the node addon api package and defines what the package exports.
// It's pretty much boilerplate
static Napi::Object Init(Napi::Env env, Napi::Object exports) {
  // Define an export called hello that will invoke our HelloMethod static function.
  exports.Set(Napi::String::New(env, "hello"),
              Napi::Function::New(env, HelloMethod));
  return exports;
}



// Define the module
NODE_API_MODULE(hello, Init)