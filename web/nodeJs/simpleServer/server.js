const http = require('http');
const url = require('url');
const users = require('./people.json').peoplesData;
const investments = require('./investments.json').investmentsData;

const server = http.createServer();
server.listen(3002, '192.168.5.8');

server.on('request', function (req, res) {
    const reqURL = url.parse(req.url, true);
    const pathName = reqURL.pathname;

    let resData = [];
    if (pathName === '/users') {
        resData = users;

    } else if (pathName === '/investments') {
        resData = investments;

    } else if (pathName === '/') {
        const { name, age } = reqURL.query;
        let combined = [];
        users.forEach(user => {
            investments.forEach(invest => {
                if (invest.id === user.id){
                    combined.push(Object.assign({}, user, invest));
                }
            });
        });

        if (name) {
            resData = combined.filter(elem => elem.name === name);
            if(age) {
                resData = resData.filter(elem => elem.age == age);
            }
        } else {
            resData = combined;
        }

    } else {
        resData = 'Invalid request';
    }
    res.end(JSON.stringify(resData));
})