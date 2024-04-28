function flattenArray(arr) {
	let outputArr = [];
	for (let entity of arr) {
		if (entity.length) {
			let recFlattenArr = flattenArray(entity);
			for (let ele of recFlattenArr) {
				outputArr.push(ele);
			}
		} else {
			outputArr.push(entity);
		}
	}
	return outputArr;
}

var arr = [1, 2, 3, 4, [5, 6, 7, 8, [9, 10]]];

const flatenArr = flattenArray(arr);
console.log("flatenArr-->", flatenArr);

const nums = [10, 9, 2, 5, 3];

function longestIncSub(arr) {
	const dp = [1];
	let ans = 0;
	for (let i = 1; i < arr.length; i++) {//n
		let curEle = arr[i];
		let maxSubTillNow = 0;
		for (let j = i - 1; j >= 0; j--) {
			if (arr[j] < curEle && dp[j] > maxSubTillNow) {
				maxSubTillNow = dp[j];
			}
		}
		ans = Math.max(ans, maxSubTillNow + 1);
		dp.push(maxSubTillNow + 1);
	}
	return ans;
}

const ans = longestIncSub(nums);

console.log("Ans-->", ans);

