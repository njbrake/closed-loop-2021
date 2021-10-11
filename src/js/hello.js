// Bindings is a helper module for loading shared libs. it searches a bunch of locations to find the closedLoop.node lib.
var addon = require('bindings')('closedLoop');

// Time our request just for fun.
console.time("c++");
// Call our static function to print hello
console.log(addon.hello());

const thing = new addon();
console.timeEnd("c++");