discovery = require('dns-discovery');

disc = discovery();

disc.on('peer', function (host, port) {
  console.log(host, port);
});