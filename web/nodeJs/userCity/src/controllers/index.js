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

const createUser = async (req, res) => {
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
      res.status(400);
      res.send('Not Found');
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

module.exports = {
  getAllUsers,
  createUser
}