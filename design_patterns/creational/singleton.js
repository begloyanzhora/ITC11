class ChangeLog {
    static getInstance() {
        if(ChangeLog.instance) {
            return ChangeLog.instance
        } else {
            ChangeLog.instance = this;
            return this;
        }
    }

    static warning() {
        return 'Warning'
    }
    static error() {
        return 'error'
    }
    static info() {
        return 'info'
    }
}

const a = ChangeLog.getInstance();
console.log(a.info())