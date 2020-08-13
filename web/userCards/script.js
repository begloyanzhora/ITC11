async function fn () {
    let response1 = await fetch('https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Zhora-Begloyan/web/jsPromises/investments.json');
    let data1 = await response1.json();
    let response2 = await fetch('https://raw.githubusercontent.com/Instigate-Training-Center-11/ITC11/Zhora-Begloyan/web/jsPromises/people.json');
    let data2 = await response2.json();

    Promise.all([data1, data2])
    .then(data => {
        const investments = data[0].investmentsData;
        const persons = data[1].peoplesData;
        let finalData = [];

        investments.forEach(invest => {
            let id = invest.id;
            persons.forEach(person => {
                if (person.id === id){
                    finalData.push(Object.assign({}, invest, person));
                }
            });
        });

        finalData.forEach(elem => {

            const root = document.getElementById('root');
            let userCard = document.createElement('div');
            userCard.classList.add('user-card');

            let infoBlock = document.createElement('div');
            let id = document.createElement('p');
            let name = document.createElement('p');
            let surname = document.createElement('p');
            let age = document.createElement('p');
            let invest = document.createElement('p');
            let job = document.createElement('p');
            let img = document.createElement('img');

            id.innerHTML = `ID: ${elem.id}`;
            name.innerHTML = `Name: ${elem.name}`;
            surname.innerHTML = `Name: ${elem.surname}`;
            age.innerHTML = `Age: ${elem.age}`;
            invest.innerHTML = `Investments: ${elem.investments}`;
            job.innerHTML = `Job: ${elem.job}`;
            img.src = elem.url;

            infoBlock.append(id);
            infoBlock.append(name);
            infoBlock.append(surname);
            infoBlock.append(age);
            infoBlock.append(invest);
            infoBlock.append(job);

            userCard.append(img);
            userCard.append(infoBlock);

            root.append(userCard);
        });
    });
}

const load = () => {
    fn();
}

const btn = document.getElementById('for-load');
btn.addEventListener('click', load);