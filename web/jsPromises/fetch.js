let investments = [];
let people = [];
let fullCombined = [];
let combined = [];
let weakMap;

const saveBestInvestors = () => {
    let result = [...investments];
    let investorsNames = [];
    result.sort((elemA, elemB) => elemB.investments - elemA.investments);
    result = result.slice(0, 3);

    result.forEach(elem => {
        let id = elem.id;
        people.forEach(people => {
            if (people.id === id){
                investorsNames.push(people.name);
            }
        });
    })
    return investorsNames;
}

let pInv = fetch('https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Zhora-Begloyan/web/jsPromises/investments.json').then(data=>data.json());
let pPople = fetch('https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Zhora-Begloyan/web/jsPromises/people.json').then(data=>data.json());

Promise.all([pInv, pPople])
.then(data => {
    investments = data[0].investmentsData;
    people = data[1].peoplesData;
    let filteredInvestments = investments.filter(elem => elem.investments >= 500);
    filteredInvestments.forEach(invest => {
        let id = invest.id;
        people.forEach(people => {
            if (people.id === id){
                combined.push(Object.assign({}, invest, people));
            }
        });
    });
})
.then(() => {
    investments.forEach(invest => {
        let id = invest.id;
        people.forEach(people => {
            if (people.id === id){
                fullCombined.push(Object.assign({}, invest, people));
            }
        });
    });
})
.then(() => {
    let entries = [];
    fullCombined.forEach(elem => {
        let entryElem = [elem, elem.name];
        entries.push(entryElem);
    });
    weakMap = new WeakMap(entries);
})
.then(() => {
    console.log(combined);
    console.log(saveBestInvestors());
    console.log(weakMap);
})
.catch((error) => {
    console.log(error);
    combined = null;
    fullCombined = null;
    investments = null;
    people = null;
    weakMap = null;
});