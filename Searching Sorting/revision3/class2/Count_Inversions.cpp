#include <bits/stdc++.h>
using namespace std;

int invCnt = 0;
void mergeTwoSortedArrays(long long nums[], int s, int mid, int e, vector<long long> &temp)
{
    long long s1 = s, e1 = mid, s2 = mid + 1, e2 = e;
    // vector<int> temp((e - s) + 1);
    long long k = 0;
    while (s1 <= e1 and s2 <= e2)
    {
        if (nums[s1] <= nums[s2])
        {
            temp[k] = nums[s1];
            s1++;
            k++;
        }
        else
        {
            temp[k] = nums[s2];
            s2++;
            k++;
            invCnt += (e1 - s1) + 1;
        }
    }
    while (s1 <= e1)
    {
        temp[k] = nums[s1];
        s1++;
        k++;
    }
    while (s2 <= e2)
    {
        temp[k] = nums[s2];
        s2++;
        k++;
    }
    k = 0;
    for (int i = s; i <= e; i++)
    {
        nums[i] = temp[k];
        k++;
    }
}

void sortArray_(long long nums[], int s, int e, vector<long long> &temp)
{
    if (s >= e)
    {
        return;
    }

    long long mid = (s + e) / 2;
    sortArray_(nums, s, mid, temp);
    sortArray_(nums, mid + 1, e, temp);
    mergeTwoSortedArrays(nums, s, mid, e, temp);
}

long long int inversionCount(long long arr[], long long N)
{
    vector<long long> temp(N, 0);
    sortArray_(arr, 0, N - 1, temp);
    // cout << invCnt;
    return invCnt;
}

int main()
{
    long long arr[10] = {8, 5, 1, 18, 12, 13, 16, 14, 19, 5};
    inversionCount(arr, 10);
    return 0;
}