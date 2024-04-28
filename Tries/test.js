const mongo = { a: 1, b: 2 }
const payload = { b: 4 }

const returnedTarget = Object.assign(mongo, payload)
console.log(returnedTarget)
