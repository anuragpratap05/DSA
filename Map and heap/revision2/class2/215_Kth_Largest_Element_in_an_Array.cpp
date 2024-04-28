#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(nums[i]);
    }
    for (int i = k; i < nums.size(); i++)
    {
        int probabale3rdLargestEle = pq.top();
        if (nums[i] > probabale3rdLargestEle)
        {
            pq.pop();
            pq.push(nums[i]);
        }
    }
    return pq.top();
}

int main()
{
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    cout << findKthLargest(nums, k);
    return 0;
}