(function () {
    let btn = document.getElementById('form').querySelector('button');
    let login = document.getElementById('login');
    let psw = document.getElementById('password');

    const printData = () => {
        if (login.value > 6 && psw.value > 6) {
            alert(`Login: ${login.value}, Password: ${psw.value}`);
        } else {
            alert('Invalid data');
        }
    }
    btn.addEventListener('click', printData);
})()