#include <napi.h>

static Napi::String EchoMethod(const Napi::CallbackInfo& info) {
  // The opaque data structure containing the environment in which the request is being run. 
  // We will need this env when we want to create any new objects inside of the node.js env
  Napi::Env env = info.Env();

  // info is a CallbackInfo object that represents the components of the JavaScript request being made.
  // We access the first element, which should be the string that we created
  std::string str = info[0].As<Napi::String>();

  // For a toy demo, add something to the input string
  std::string result = "You said: " + str;

  // Return a string that we constructed inside of the N-API env
  return Napi::String::New(env, result);
}

// This is what initializes the node addon api package and defines what the package exports.
// It's pretty much boilerplate
static Napi::Object Init(Napi::Env env, Napi::Object exports) {
  // Define an export called echo that will invoke our EchoMethod static function.
  exports.Set(Napi::String::New(env, "echo"),
              Napi::Function::New(env, EchoMethod));


  /*
    In real life, static functions are probably of limited usefulness.
    If we wanted to have the module export a class that could be instantiated via 'new Thingy()'
    then check out this example
    https://github.com/nodejs/node-addon-examples/tree/main/object-wrap-demo/node-addon-api
  */
  return exports;
}



// Define the module
// Boilerplate Node-API macro to create the module
NODE_API_MODULE(closedLoop, Init)