class ReadJson {
    readJ() {
        return 'Can read JSON';
    }
}

class ReadXML {
    readX() {
        return 'Can read XML';
    }
}

class XMLAdapter extends ReadJson {
    constructor(readXML) {
        super();
        this.readXML = readXML;
    }

    readJ() {
        return this.readXML.readX();
    }
}

let xml = new ReadXML();
let xmlToJson = new XMLAdapter(xml);
console.log(xmlToJson.readJ());