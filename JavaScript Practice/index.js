const EventEmitter = require('events');
var emitter = new EventEmitter();

emitter.on('consoleLogger', (arg) => {
    console.log("Event is " + arg);
});

emitter.emit('consoleLogger', {id: 1, url: "https://"});

