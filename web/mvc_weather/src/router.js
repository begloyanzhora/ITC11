const express = require('express');
const router = express.Router();
const controllers = require('./controllers');

router.get('/', controllers.renderHomePage)
router.post('/', controllers.getWeather);
router.get('/about', controllers.renderAboutPage);

module.exports = router;