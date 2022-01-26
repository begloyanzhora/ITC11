const div = exp => {
    const numbersStrArr = exp.split('/');
    const numbers = numbersStrArr.map(elem => +elem);

    return numbers.reduce((res, current) => res /= current);
}
const divMul = exp => {
    const numbersStrArr = exp.split('*');
    const numbers = numbersStrArr.map(elem => div(elem));

    return numbers.reduce((res, current) => res *= current);
}
const divMulSub = exp => {
    const numbersStrArr = exp.split('-');
    const numbers = numbersStrArr.map(elem => divMul(elem));

    return numbers.reduce((res, current) => res -= current);
}
const calc = exp => {
    const numbersStrArr = exp.split('+');
    const numbers = numbersStrArr.map(elem => divMulSub(elem));

    return numbers.reduce((res, current) => res += current);
}

const input = document.getElementById('myinput');
const buttons = document.querySelectorAll('.numOp');
const cleanBtn = document.getElementById('clean');
const equalBtn = document.getElementById('equal');

const write = () => {
    const val = event.currentTarget.innerHTML;
    input.value += val;
}
const clean = () => {
    input.value = "";
}
const calculate = () => {
    const exp = input.value;
    input.value = calc(exp);
}

buttons.forEach(button => {
    button.addEventListener('click', write);
});
equalBtn.addEventListener('click', calculate);
cleanBtn.addEventListener('click', clean);