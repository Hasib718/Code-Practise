// setTimeout(() => console.log("I'm Alive"), 3000)

// let n = 5;
// while(n--) {
//     console.log("Hello Javascript");
// }

// const add = (y) => {
//     let x=5;
//     return x+y;
// }

// console.log(add(5))

// const id = setInterval(() => console.log(Math.random()), 2000)

const results = [80, 98, 92, 78, 77, 90, 89, 84, 81, 77]

// console.log(results.every(result => result >= 80))
// console.log(results.some(result => result >= 80))
// console.log(results.reduce((sum, value) => sum+value))
// console.log(`Minimum value ${results.reduce((prev, current) => (prev <= current) ? prev : current)}`)

// setTimeout(() => clearInterval(id), 6000)

/*
    We should use 'function' keyword to create method in Objects.
    That let us to use "this" keyword in function scope.

    But if we use 'Arrow function' that has lexical scope where "this"
    always refers to 'Window' object instead of specific object.
*/
const person = {
  firstName: "Shahrin",
  lastName: "Sultana",
  callName: function () {
    return `${this.firstName} ${this.lastName}`;
  },
  fullName: function () {
    console.log(this);
    console.log(this.callName());
  },
};
person.fullName();

function print(person, msg="Hello") {
    console.log(`${msg} ${person}!`)
}

print("Shahrin")
print("Shahrin", "Love you")

console.log(..."Bellow is the Max value of the array-")
console.log(Math.max(...results))

const arr = ['a', 'b', 'c']
const ay = ['d', 'e', 'f']

//const array = [...arr, ...ay]

const {firstName: name = "Wadud"} = person
console.log(name)