#include<bits/stdc++.h>
using namespace std;

bool compare_to(int i, int j,vector<int>& arr,bool is_maxheap)
{
    if (arr[i] > arr[j] and is_maxheap)
    {
        return true;
    }

    if (arr[i] < arr[j] and !is_maxheap)
    {
        return true;
    }
    return false;
}
void down_heapify(int pi, vector<int> &arr, bool is_maxheap,int li)
{
    int maxidx = pi;
    int lc = (pi * 2) + 1;
    int rc = (pi * 2) + 2;

    if (lc <=li and compare_to(lc, maxidx,arr,is_maxheap))
    {
        maxidx = lc;
    }

    if (rc <= li and compare_to(rc, maxidx, arr, is_maxheap))
    {
        maxidx = rc;
    }

    if (maxidx != pi)
    {
        swap(arr[pi], arr[maxidx]);
        down_heapify(maxidx, arr, is_maxheap,li);
    }
}
void heap_sort(vector<int>&nums,bool is_maxheap)
{
    int li = nums.size() - 1;
    for (int i = li; i >= 0;i--)
    {
        down_heapify(i, nums, is_maxheap, li);
    }
    while(li>=0)
    {
        swap(nums[0], nums[li--]);
        down_heapify(0, nums, is_maxheap, li);
    }
}

int main()
{
    vector<int> nums = {10, 20, 30, -2, -3, -4, 5, 6, 7, 8, 9, 22, 11, 13};
    heap_sort(nums, true);
    for(int e:nums)
    {
        cout << e << " ";
    }
    return 0;
}