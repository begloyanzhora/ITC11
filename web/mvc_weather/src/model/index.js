class Weather {
  constructor(data) {
    this.data = data;
    this.errors = [];
  }

  validateInput () {
    if(this.data == '') {
      this.errors.push('Please enter the name of the city.')
    }
  }
}

module.exports = Weather;