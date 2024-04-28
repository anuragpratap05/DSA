#include <bits/stdc++.h>
using namespace std;

//  O(Nlog(k))
int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int e : nums)
    {
        pq.push(e);
        if (pq.size() > 2)
        {
            pq.pop();
        }
    }
    return pq.top();
}


//  O(n)

bool compare_to(int i, int j, vector<int> &nums)
{
    return nums[i] > nums[j];
}

void downheapify(vector<int> &nums, int pi, int li)
{
    int maxidx = pi;
    int lc = (pi * 2) + 1;
    int rc = (pi * 2) + 2;
    // int n = nums.size();

    if (lc <= li and compare_to(lc, maxidx, nums))
    {
        maxidx = lc;
    }

    if (rc <= li and compare_to(rc, maxidx, nums))
    {
        maxidx = rc;
    }
    if (maxidx != pi)
    {
        swap(nums[maxidx], nums[pi]);
        downheapify(nums, maxidx,li);
    }
}

int findKthLargest2(vector<int> &nums, int k)
{
    int li = nums.size() - 1;
    for (int i = li; i >= 0;i--)
    {
        downheapify(nums, i, li);
    }
    for (int e : nums)
    {
        cout << e << " ";
    }
    int tempk = k;
    while (tempk--)
    {
        swap(nums[0], nums[li--]);
        downheapify(nums, 0, li);
    }
    cout << endl;
    for (int e : nums)
    {
        cout << e << " ";
    }
    return nums[nums.size() - k];
}

int main()
{

    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    findKthLargest2(nums, k);
    return 0;
}