//

// Output: ih ym eman si garuna

function reverseWord(word) {
	return word.split("").reverse().join("");
}

function reverseString(str) {
	const words = str.split(" ");
	let reversedStr = "";
	for (let i = 0; i < words.length; i++) {
		let word = words[i];
		let reversedWord = reverseWord(word);
		reversedStr += reversedWord;
		if (i < words.length - 1) reversedStr += " ";
	}
	return reversedStr;
}

let Input = "hi my name is anurag";
const reversedString = reverseString(Input);
console.log("reversedString-->", reversedString);
// console.log(reverseWord("anurag"));
