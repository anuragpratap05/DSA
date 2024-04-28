// const { sortArray } = require("./helper");
const sortArray = (arr, val) => {
	return arr.sort((a, b) => {
		if (a.name < b.name) return -1;
		return 1;
	});
};
let array = [
	{ name: "James Hooper", age: 33, title: "Designer" },
	{ name: "Ronnie Thomas", age: 24, title: "Analyst" },
	{ name: "Taylor Hayes", age: 45, title: "Technician" },
	{ name: "Mary Green", age: 23, title: "Coordinator" },
	{ name: "Amber Roberts", age: 31, title: "Designer" },
	{ name: "Lee Moreno", age: 38, title: "Administrator" },
	{ name: "Edward Johnson", age: 46, title: "Consultant" },
	{ name: "Jamie Spencer", age: 56, title: "Engineer" },
	{ name: "Katie Robinson", age: 23, title: "Consultant" },
	{ name: "John Trevino", age: 52, title: "Specialist" },
];

let key = "age";

// sortArray(array, key);
console.log(sortArray(array, key));
