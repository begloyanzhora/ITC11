const objCopy = (obj) => {
    return JSON.parse(JSON.stringify(obj));
}

/* -----THIS BEHAVIOURS ---- */
let user = {
    name: "John",
    age: 30
};

function sayHi() {
    console.log("Hello");
};

user.sayHi = sayHi;
user.sayHi();

let user2 = {
    name: "John",
    hi() { console.log(this.name); },
    bye() { console.log("By"); }
};

(user2.name == "John" ? user2.hi : user2.bye)(); //error

let user3 = {
    firstName: "John",
    sayHi() {
        let arrow = () => console.log(this.firstName);
        arrow();
    }
};
user3.sayHi(); //if we use the usual function declaration or exp, 'this' will refer to window or be undefined in use strict mode


let worker = {
    someMethod() {
        return 1;
    },

    slow(x) {
        console.log("Called with " + x);
        return x * this.someMethod();
    }
};

function cachingDecorator(func) {
    let cache = new Map();
    return function(x) {
        if (cache.has(x)) {
            return cache.get(x);
        }
        let result = func(x);
        cache.set(x, result);
        return result;
    };
}

console.log( worker.slow(1) ); // works normally

worker.slow = cachingDecorator(worker.slow);

console.log( worker.slow(2) ); // doesn't work beacause of losing this

/* example of losing this context */
let user = {
    firstName: "Some name",
    sayHi() {
      console.log(`Hello, ${this.firstName}!`);
    }
};
setTimeout(user.sayHi, 1000); // this = undefined
let sayHi = user.sayHi.bind(user);
setTimeout(sayHi, 1000); //works correctly