class Cell {
    constructor (styles) {
        this._styles = styles;
    }

    clone() {
        return new Cell(this.styles)
    }

    get styles(){
        return this._styles;
    }
    set styles(style){
        this._styles = style;
    }
}

const cell = new Cell('myStyles');
const anotherCell = cell.clone();

console.log(cell.styles);
console.log(anotherCell.styles);