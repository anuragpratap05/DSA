const arr = [1, 5, 6, 2, 3, 4];

function mergeTwoSortedArrays(arr, si, mid, ei) {
	let s1 = si;
	let e1 = mid;

	let s2 = mid + 1;
	let e2 = ei;

	let tempArr = [];

	while (s1 <= e1 && s2 <= e2) {
		if (arr[s1] < arr[s2]) {
			tempArr.push(arr[s1]);
			s1++;
		} else {
			tempArr.push(arr[s2]);
			s2++;
		}
	}

	while (s1 <= e1) {
		tempArr.push(arr[s1]);
		s1++;
	}

	while (s2 <= e2) {
		tempArr.push(arr[s2]);
		s2++;
	}
	let k = 0;
	for (let i = si; i <= ei; i++) {
		arr[i] = tempArr[k];
		k++;
	}
}

function mergeSort(arr, si, ei) {
	int(si + ei) / 2;
	mergeSort(arr, si, mid);
	mergeSort(arr, mid + 1, ei);
	mergeTwoSortedArrays(arr, si);
}

function mergeSortOriginal() {
	mergeSort(arr, 0, arr.length - 1);
}
