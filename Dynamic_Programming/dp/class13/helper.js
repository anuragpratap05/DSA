const sortArray = (arr, val) => {
	return arr.sort((a, b) => a.age - b.age);
};

// export default sortArray;

module.exports = { sortArray };
