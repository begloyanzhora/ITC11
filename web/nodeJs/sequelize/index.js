const express = require('express');
const configs = require('./configs');
const { Sequelize, DataTypes } = require('sequelize');

const app = express();
const { host_name, db_name, db_user, db_password } = configs;

const sequelize = new Sequelize(db_name, db_user, db_password, {
    host: host_name,
    dialect: 'mysql'
})

const Users = sequelize.define('users', {
    id: {
        type: DataTypes.UUID,
        primaryKey: true,
        unique: true
    },
    name: {
        type: DataTypes.STRING,
        allowNull: false
    },
    surname: {
        type: DataTypes.STRING,
        allowNull: false
    },
    job: {
        type: DataTypes.STRING,
        allowNull: true
    },
    url: {
        type: DataTypes.STRING,
        allowNull: true
    }
}, {});

const Investments = sequelize.define('investments', {
    id: {
        type: DataTypes.UUID,
        primaryKey: true,
        unique: true
    },
    investments: {
        type: DataTypes.INTEGER,
        allowNull: false
    }
}, {});

const initDB = async () => {
    try {
        await sequelize.authenticate();
        await Users.sync();
        await Investments.sync();
        console.log('Connection has been established successfull');
    } catch (error) {
        console.error('Unable to connect to the database:', error);
    }
}
initDB();

const getAllUsers = async (req, res) => {
    const users = await Users.findAll();
    res.send(users);
}
const getUserById = async (req, res) => {
    const users = await Users.findAll({
        where: {
            id: req.params.id
        }
    });
    res.send(users);
}
const getAllInvestments = async (req, res) => {
    const investments = await Investments.findAll();
    res.send(investments);
}
const getInvestmentById = async (req, res) => {
    const investments = await Investments.findAll({
        where: {
            id: req.params.id
        }
    });
    res.send(investments);
}

app.get('/users', getAllUsers);
app.get('/users/:id', getUserById);
app.get('/investments', getAllInvestments);
app.get('/investments/:id', getInvestmentById);

app.listen(3000);