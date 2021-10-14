// Bindings is a helper module for loading shared libs. it searches a bunch of locations to find the closedLoop.node lib.
const {echo} = require('bindings')('closedLoop');

// Call our static function to print hello
console.log(echo("hi from node.js!"));