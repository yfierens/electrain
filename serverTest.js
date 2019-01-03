discovery = require('dns-discovery');

disc = discovery();

disc.announce('test-server', 44844); 
