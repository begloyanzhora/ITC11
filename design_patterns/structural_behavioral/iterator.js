class SumIterator {
    constructor(arr) {
        this.arr = arr;
        this.index = 0;
    }

    next () {
        return this.arr[this.index++];
    }

    hasNext () {
        return this.index < this.arr.length;
    }

    action () {
        let sum = 0;
        while(this.hasNext()) {
            sum += this.next();
        }
        return sum;
    }
}

class MulIterator extends SumIterator {
    constructor(arr) {
        super(arr);
    }

    action () {
        let mul = 1;
        while(this.hasNext()) {
            mul *= this.next();
        }
        return mul;
    }
}

const arr = [1, 2, 3, 4, 5];
const i1 = new SumIterator(arr);
const i2 = new MulIterator(arr);
console.log(i1.action());
console.log(i2.action());