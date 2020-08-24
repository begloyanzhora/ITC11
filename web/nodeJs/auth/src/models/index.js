const { Sequelize, DataTypes } = require('sequelize');
const { host_name, db_name, db_user, db_password } = require('../configs');

const db = new Sequelize(db_name, db_user, db_password, {
  host: host_name,
  dialect: 'mysql'
})

const Users = db.define('users', {
  id: {
    type: DataTypes.UUID,
    primaryKey: true,
    defaultValue: Sequelize.UUIDV4
  },
  name: {
    type: DataTypes.STRING,
    allowNull: false
  },
  surname: {
    type: DataTypes.STRING,
    allowNull: false
  },
  age: {
    type: DataTypes.INTEGER,
    allowNull: false
  },
  job: {
    type: DataTypes.STRING,
    allowNull: true
  },
  url: {
    type: DataTypes.STRING,
    allowNull: true
  },
  isAdmin: {
    type: DataTypes.BOOLEAN,
    defaultValue: false,
  },
  email: {
    type: DataTypes.STRING,
    allowNull: false,
    unique: true
  },
  password: {
    type: DataTypes.STRING,
    allowNull: false
  }
}, {});

const Cities = db.define('cities', {
  id: {
    type: DataTypes.INTEGER,
    primaryKey: true,
    autoIncrement: true
  },
  name: {
    type: DataTypes.STRING,
    allowNull: false
  },
  isCapital: {
    type: DataTypes.BOOLEAN,
    allowNull: false
  },
  population: {
    type: DataTypes.INTEGER,
    allowNull: false
  }
}, {});

const Offices = db.define('offices', {
  id: {
    type: DataTypes.INTEGER,
    primaryKey: true,
    autoIncrement: true
  },
  name: {
    type: DataTypes.STRING,
    allowNull: false
  }
}, {});

Users.belongsTo(Cities, {foreignKey: 'cityId'});
Users.belongsTo(Offices, {foreignKey: 'officeId'});

module.exports = {
  Users,
  Cities,
  Offices
};