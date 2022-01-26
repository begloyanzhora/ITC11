const { decode } = require('jwt-simple');
const { secretKey } = require('../configs');

const auth = (req, res, next) => {
  const token = req.headers.authorization;
  if(!token) {
    res.status(401);
    res.send('Unauthorized');
  } else {
    try {
      const decoded = decode(token, secretKey);
      next();
    } catch (error) {
      res.status(401);
      res.send('Invalid token');
    }
  }
}

const checkBody = (err, req, res, next) => {
  if(err) {
    res.status(400);
    res.send('Invalid JSON');

  } else {
    next();
  }
}

module.exports = {
  auth,
  checkBody
};