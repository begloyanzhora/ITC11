const { Users, Cities, Offices } = require('../models');

const getAllUsers = async (req, res) => {
  try {
    const users = await Users.findAll({
      include: [ {model: Cities, attributes: ['name'] }, {model: Offices, attributes: ['name'] }],
      attributes: {exclude: ['cityId', 'officeId']}
    });
    res.send(users);

  } catch (error) {
    res.status(500);
    res.send('Internal Error' + error);
  }
}

const getUserById = async (req, res) => {
  try {
    const user = await Users.findOne({
      include: [ {model: Cities, attributes: ['name'] }, {model: Offices, attributes: ['name'] }],
      attributes: {exclude: ['cityId', 'officeId']},
      where: {
        id: req.params.id
      }
    });

    if(!user) {
      res.status(404);
      res.send('Not Found');
    }

    res.send(user);

  } catch (error) {
    res.status(500);
    res.send('Internal Error' + error);
  }
}

const getAllCities = async (req, res) => {
  try {
    const cities = await Cities.findAll();
    res.send(cities);
  } catch (error) {
    res.status(500);
    res.send('Internal Error' + error);
  }
}

const getAllOffices = async (req, res) => {
  try {
    const offices = await Offices.findAll();
    res.send(offices);
  } catch (error) {
    res.status(500);
    res.send('Internal Error' + error);
  }
}

const addUser = async (req, res) => {
  try {
    const { name, surname, age, job, url, city: cityName, office: officeName } = req.body;

    const cityId = await Cities.findOne({
      where: {
        name: cityName
      },
      attributes: ['id']
    })

    const officeId = await Offices.findOne({
      where: {
        name: officeName
      },
      attributes: ['id']
    })

    if(!cityId || !officeId) {
      res.status(404);
      res.send("Can't find City or office.");
    }

    const newUser = await Users.create({
      name, surname, age, job, url, cityId: cityId.dataValues.id, officeId: officeId.dataValues.id
    })
    res.send(newUser);

  } catch (error) {
    res.status(500);
    res.send('Internal Error' + error);
  }
}

const addCity = async (req, res) => {
  try {
    const { name, isCapital, population } = req.body;

    if(!name) {
      res.status(400);
      res.send('Invalid Name');
    }
    const newCity = await Cities.create({ name, isCapital, population });
    res.send(newCity);

  } catch (error) {
    res.status(500);
    res.send('Internal Error' + error);
  }
}

const addOffice = async (req, res) => {
  try {
    const { name } = req.body;

    if(!name) {
      res.status(400);
      res.send('Invalid Name');
    }
    const newOffice = await Offices.create({ name });
    res.send(newOffice);

  } catch (error) {
    res.status(500);
    res.send('Internal Error' + error);
  }
}

module.exports = {
  getAllUsers,
  addUser,
  addCity,
  addOffice,
  getUserById,
  getAllOffices,
  getAllCities
}