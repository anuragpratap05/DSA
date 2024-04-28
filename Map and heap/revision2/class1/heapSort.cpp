#include <bits/stdc++.h>
using namespace std;

bool isEleAHasHigherPriority(int eleA, int eleB, bool maxHeap)
{
    if (eleA > eleB and maxHeap)
    {
        return true;
    }
    if (eleA < eleB and !maxHeap)
    {
        return true;
    }
    return false;
}

void downHeapify(vector<int> &nums, int parIdx, bool maxHeap, int n)
{
    int maxEleIdx = parIdx;

    int leftChildIdx = (parIdx * 2) + 1;
    int rightChildIdx = (parIdx * 2) + 2;

    if (leftChildIdx < n and isEleAHasHigherPriority(nums[leftChildIdx], nums[maxEleIdx], maxHeap))
    {
        maxEleIdx = leftChildIdx;
    }

    if (rightChildIdx < n and isEleAHasHigherPriority(nums[rightChildIdx], nums[maxEleIdx], maxHeap))
    {
        maxEleIdx = rightChildIdx;
    }

    if (maxEleIdx != parIdx)
    {
        swap(nums[maxEleIdx], nums[parIdx]);
        downHeapify(nums, maxEleIdx, maxHeap, n);
    }
}

void upHeapify(vector<int> &nums, int childIdx, bool maxHeap, int startingIdx)
{
    int parIdx = (childIdx - 1) / 2;
    if (parIdx >= startingIdx and isEleAHasHigherPriority(nums[childIdx], nums[parIdx], maxHeap))
    {
        swap(nums[parIdx], nums[childIdx]);
        upHeapify(nums, parIdx, maxHeap, startingIdx);
    }
}

void heapSort(vector<int> &nums, bool maxHeap)
{
    int n = nums.size();
    // for (int i = 0; i < n; i++)
    // {
    //     upHeapify(nums, i, maxHeap, 0);
    // }

    // or

    for (int i = n - 1; i >= 0; i--)
    {
        downHeapify(nums, i, maxHeap, n);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        swap(nums[0], nums[i]);
        downHeapify(nums, 0, maxHeap, i);
    }
}
// vector<int> sortArray(vector<int> &nums)
// {
//     heapSort(nums, true);
//     return nums;
// }
int main()
{
    vector<int> vec = {12, 3, 8, 7, 5, 10, 14, 1, 24};
    heapSort(vec, true);
    for (int e : vec)
    {
        cout << e << " ";
    }
    return 0;
    return 0;

    // pq.push(76);
    // pq.push(47);
    // pq.push(23);
    // pq.push(73);
    // pq.push(723);
    // pq.push(756);
    // pq.push(62);
}