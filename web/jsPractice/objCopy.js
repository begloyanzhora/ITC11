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
let user4 = {
    firstName: "Some name",
    sayHi() {
      console.log(`Hello, ${this.firstName}!`);
    }
};
setTimeout(user4.sayHi, 1000); // this = undefined
let sayHi1 = user4.sayHi.bind(user4);
setTimeout(sayHi1, 1000); //works correctly

/* Map Set WeakMap WeakSet */
let map = new Map();
map.set('name', 'Armen');
map.set(true, 'yes').set('age', 29);

console.log(map.get(true));
console.log(map.has('name'));
console.log(map.size);
for (let entry of map) {
    console.log(entry);
}
map.forEach((value, key) => console.log(`${key} : ${value}`));

let obj = {
    "test": "testvalue",
    "key": 'hello'
};

let mapFromObj = new Map(Object.entries(obj));
mapFromObj.forEach((value, key) => console.log(`${key} : ${value}`));

let arr = [['key1', 1], ['key2', 2], ['key2', 2]];

let objFromArr = Object.fromEntries(arr);

let set = new Set();
set.add(2).add(3).add(3);
console.log(set);
for(let value of set.values()) {
    console.log(value);
}

let john = {name: 'john'};
let weakMap = new WeakMap();;
weakMap.set(john, 'ok');
john = null;
console.log(weakMap.get(john));

/* Symnols */
let person = {
    name: 'Person'
};

let id = Symbol('id');
person[id] = 1;
console.log(person[id]);
console.log(person);

let globid = Symbol.for("globid");
let lidAgain = Symbol.for("globid");

console.log(globid === lidAgain);