class ChangeLog {
    static instance = null;
    static type = null;
    constructor(type){
        this._type = type;
    }

    static getInstance() {
        if(!instance) {
            instance = new ChangeLog(type);
            return instance;
        }
    }

    set type(type) {
        this._type = type;
        this.instance = null;
    }
}

const a = new ChangeLog('error');
const b = new ChangeLog('warning');
console.log(a.getInstance == b.getInstance);