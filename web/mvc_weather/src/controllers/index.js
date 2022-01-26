const axios = require('axios');
const API_KEY = '1370646f766bd6dcca339cb8d9b680b4';

const Weather = require('../model');

const renderHomePage = (req, res) => {
  res.render('index');
}

const renderAboutPage = (req, res) => {
  res.render('about');
}

const getWeather = (req, res) => {
  const city = req.body.city;
  const url = `http://api.openweathermap.org/data/2.5/weather?q=${city}&appid=${API_KEY}&units=metric`;
  const weather = new Weather(req.body.city);
  weather.validateInput();

  if(weather.errors.length) {
    res.render('index', {
      error: weather.errors.toString()
    })

  } else {
    axios.get(url)
    .then(response => {
      const { temp: temperature } = response.data.main;
      const { name: location } = response.data;
      res.render('index', {
        weather: `It is currently ${temperature} in ${location}`
      })
    })
    .catch(err => {
      console.log(err);
    })
  }
}

module.exports = {
  renderHomePage,
  getWeather,
  renderAboutPage
}