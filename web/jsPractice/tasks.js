    /* TASK 1 */
const hoursFormat = date => {
    let hour = date.getHours();
    let seconds = date.getSeconds();

    if (hour > 12) {
        hour -= 12;
        hour += ' PM';
    } else if (hour == 12 && seconds > 0) {
        hour += ' PM';
    } else {
        hour += ' AM';
    }

    return hour;
}
const weekdaysFormat = date => {
    let day = date.getDay();
    switch (day) {
        case 0:
            return 'Sunday';
        case 1:
            return 'Monday';
        case 2:
            return 'Tuesday';
        case 3:
            return 'Wednesday';
        case 4:
            return 'Thursday';
        case 5:
            return 'Friday';
        case 6:
            return 'Saturday';
    }
}
const displayDayTime = () => {
    let now = new Date();
    console.log(`Today is : ${weekdaysFormat(now)}.`);
    console.log(`Current time is : ${hoursFormat(now)} : ${now.getMinutes()} : ${now.getSeconds()}`);
}

    /* TAKS 2 */
const printWindowContents = () => {
    for (let key in window) {
        console.log (key, window[key]);
    }
}

    /* TASK 3 */
const formatMonth = (date) => {
    month = date.getMonth() + 1;
    return month < 10 ? '0' + month : month;
}
const displayDate = () => {
    let date = new Date();
    console.log(`${formatMonth(date)}-${date.getDate()}-${date.getFullYear()}`);
}

    /* TASK 4 */
const calcTriangleArea = (a, b, c) => {
    let s = (a + b + c) / 2;
    let area = Math.sqrt(s * (s - a) * (s - b) * (s - c));
    return area;
}

    /* TASK 5 */
const reverseString = str => {
    let arr = str.split('');
    for (let i = 0; i < arr.length - 1; i++) {
        arr.unshift(arr.pop());
    }
    return arr.join('');
}

    /* TASK 6 */
const isLeap = year => {
    return year % 4 === 0;
}

    /* TASK 7 */
const getSundays = () => {
    for (let i = 2014; i <= 2050; i++) {
        let date = new Date(i, 0);
        let day = date.getDay();
        if (day === 0) {
            console.log(date);
        }
    }
}

    /* TASK 8 */
const checkNum = num => {
    let userNum = +prompt('Enter the number between 1 to 10', 1);
    if (num === userNum) {
        alert('Good Job');
    } else {
        alert('Not Matched');
    }
}

    /* TASK 9 */
const calcDaysLeft = () => {
    let now = new Date();
    let christ = new Date(now.getFullYear() + 1, 0, 6);

    if (now.getMonth() == 0 && now.getDate() < 6) {
        christ.setFullYear(now.getFullYear());
    }

    let leftDays = Math.floor((christ.getTime() - now.getTime()) / 1000 / 60 / 60 / 24);
    return leftDays;
}

    /* TASK 10 */
const calcDivMul = () => {
    let a = +prompt('Enter the fisrt number', 1);
    let b = +prompt('Enter the second number', 1);

    alert('a * b = ' + a * b);
    alert('a / b = ' + a / b);
}