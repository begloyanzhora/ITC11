const { Users, Cities, Offices } = require('../models');
const { saltRounds, secretKey } = require('../configs');
const { hash, compare } = require('bcrypt');
const { encode } = require('jwt-simple');

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

const signUp = async (req, res) => {
  try {
    const { name, surname, age, job, url, city: cityName, office: officeName, email, password } = req.body;

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

    hash(password, saltRounds, async (err, psw) => {
      const newUser = await Users.create({
        name,
        surname,
        age,
        job,
        url,
        email,
        password: psw,
        cityId: cityId.dataValues.id,
        officeId: officeId.dataValues.id
      })
      res.send(newUser);
    })

  } catch (error) {
    res.status(500);
    res.send('Internal Error' + error);
  }
}

const signIn = async (req, res) => {
  try {
    const { email, password } = req.body;
    const user = await Users.findOne({
      where: {email: email}
    })

    compare(password, user.dataValues.password, (err, result) => {
      if(result) {
        const payload = {
          id: user.dataValues.id
        };
        const token = encode(payload, secretKey);
        res.send(token);

      } else {
        res.status(401);
        res.send('Unauthorized');
      }
    });
  } catch (error) {
    res.status(404);
    res.send('Undefined user');
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
  signUp,
  signIn,
  addCity,
  addOffice,
  getUserById,
  getAllOffices,
  getAllCities
}