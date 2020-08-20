const { Users, Cities, Offices } = require('./models');
const { getAllUsers, getUserById, getAllCities, getAllOffices, addUser, addCity, addOffice } = require('./controllers');
const { port } = require('./configs');
const express = require('express');
const bodyParser = require('body-parser');

const app = express();
app.use(bodyParser.json());

app.get('/users', getAllUsers);
app.get('/users/:id', getUserById);
app.get('/cities', getAllCities);
app.get('/offices', getAllOffices);
app.post('/users', addUser);
app.post('/cities', addCity);
app.post('/offices', addOffice);

const initDB = async () => {
  try {
    await Offices.sync();
    await Cities.sync();
    await Users.sync();
    console.log('Connection has been established successfull');
  } catch (error) {
    console.error('Unable to connect to the database:', error);
  }
}
initDB();

app.listen(port);