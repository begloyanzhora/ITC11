const { Users, Cities } = require('../models');

const getAllUsers = async (req, res) => {
  try {
    const users = await Users.findAll({
      include: [{ model: Cities, as: 'city', attributes: ['name'] }],
      attributes: {exclude: ['cityId']}
    });
    res.send(users);

  } catch (error) {
    res.status(500);
    res.send('Internal Error' + error);
  }
}

const createUser = async (req, res) => {
  try {
    const { name, surname, age, job, url, city: cityName } = req.body;

    const cityId = await Cities.findOne({
      where: {
        name: cityName
      },
      attributes: ['id']
    })

    if(!cityId) {
      res.status(400);
      res.send('No Such City');
    }

    const newUser = await Users.create({
      name, surname, age, job, url, cityId: cityId.dataValues.id
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