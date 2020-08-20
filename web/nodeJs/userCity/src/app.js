const { Users, Cities, Offices } = require('./models');
const { getAllUsers, createUser } = require('./controllers');
const { port } = require('./configs');
const express = require('express');
const bodyParser = require('body-parser');

const app = express();
app.use(bodyParser.json());

app.get('/users', getAllUsers);
app.post('/users', createUser);

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