window.onscroll = function() {
    myFunction();
}

let navbar = document.getElementById("nav");
let sticky = navbar.offsetTop;

function myFunction() {
    if (window.pageYOffset >= sticky) {
        navbar.classList.add("fixed")
    }else {
        navbar.classList.remove("fixed");
    }
}