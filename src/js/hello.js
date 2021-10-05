var addon = require('bindings')('loopy');

console.time("c++");
console.log(addon.hello()); // 'world'
console.timeEnd("c++");


console.time("js");
console.log("Hello, World!"); // 'world'
console.timeEnd("js");