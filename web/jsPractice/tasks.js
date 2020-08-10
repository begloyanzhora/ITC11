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

    /* TASK 11 */
const fromCelToFaren = tem => tem * 9 / 5 + 32;
const fromFarenToCel = tem => (tem - 32) * 5 / 9;

    /* TASK 12 */
const getURL = () => window.location.href;

    /* TASK 13 */
const createVar = () => {
    varName = prompt('Ente variable name', '');
    window[varName] = '';
}

    /* TASK 14 */
const getExtension = filename => filename.split('.').pop();

    /* TASK 15 */
const getDiff13 = num => num > 13 ? 2 * (num - 13) :13 - num;

    /* TASK 16 */
const checkAndGetSum = (a, b) => a === b ? (a + b) * 3 : a + b;

    /* TASK 17 */
const checkDiff19 = num => num > 19 ? Math.abs(num - 19) * 3 : Math.abs(num - 19);

    /* TASK 18 */
const checkTwoNum = (a, b) => {
    return a === 50 || b === 50 || a + b === 50;
}

    /* TASK 19 */
const checkWithin = num => Math.abs(num - 100) <= 20 || Math.abs(num - 400) <= 20;

    /* TASK 20 */
const checkIsPosAndNeg = (a, b) => (a > 0 && b < 0) || (a < 0 && b > 0);

    /* TASK 21 */
const addPy = str => {
    if (str.startsWith('Py')) {
        return str;
    }

    return 'Py' + str;
}

    /* TASK 22 */
const removeChar = (str, pos) => str.slice(0, pos) + str.slice(pos + 1);

    /* TASK 23 */
const changePos = str => str.charAt(str.length - 1) + str.slice(1, -1) + str.charAt(0);

    /* TASK 24 */
const addFirstChar = str => str.charAt(0) + str + str.charAt(0);

    /* TASK 25 */
const checkMul = num => num % 3 === 0 || num % 7 === 0;

    /* TASK 26 */
const addLastChars = str => str.slice(-3) + str + str.slice(-3);

    /* TASK 27 */
const isStartsWithJava = str => str.startsWith('Java');

    /* TASK 28 */
const isInRange = (a, b) => (a >= 50 && a <= 99) || (b >= 50 && b <= 99);

    /* TASK 29 */
const isInRangeThree = (a, b, c) => (a >= 50 && a <= 99) || (b >= 50 && b <= 99) || (c >= 50 && c <= 99);

    /* TASK 30 */
const containsScript = str => {
    if (str.indexOf('Script') === 4) {
        return str.slice(0, 4) + str.slice(10);
    }

    return str;
}

    /* TASK 31 */
const getMax = (a, b, c) => {
    let max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    return max;
}

    /* TASK 32 */
const getNearest = (a, b) => Math.abs(a - 100) < Math.abs(b - 100) ? a : b;

    /* TASK 33 */
const checkRange = (a, b) => ((a => 40 && a <=60) && (b => 40 && b <=60)) || ((a => 70 && a <=100) && (b => 70 && b <=100));

    /* TASK 34 */
const getMaxCheckRange = (a, b) => {
    if (a < 40 || b < 40 || a > 60 || b >60) {
        return;
    }

    return a > b ? a : b;
}

    /* TASK 35 */
const checkPos = (str, char) => str.indexOf(char) >= 2 && str.indexOf(char) <= 4;

    /* TASK 36 */
const checkLastDig = (a, b, c) => (a % 10 === b % 10) && (b % 10 === c % 10);

    /* TASK 37 */
const first3Lower = str => {
    if (str.length < 3) {
        return str.toUpperCase();
    }

    return str.slice(0, 3).toLowerCase();
}

    /* 38. Write a JavaScript program to check the total marks of a student in various examinations. The student will get A+ grade if the total marks are in the range 89..100 inclusive, if the examination is "Final-exam." the student will get A+ grade and total marks must be greater than or equal to 90. Return true if the student get A+ grade or false otherwise. */
