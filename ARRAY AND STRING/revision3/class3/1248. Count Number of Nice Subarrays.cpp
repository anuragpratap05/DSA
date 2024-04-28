#include <bits/stdc++.h>
using namespace std;
int kDistinctSubarrays(vector<int> &arr, int k)
{
    int arraySize = arr.size();
    int prev = 0, curr = 0, len = 0;
    // vector<int> freq(1e9, 0);
    unordered_map<int, int> freq;
    int oddCount = 0;
    while (curr < arraySize)
    {
        int ele = arr[curr];
        if ((ele & 1) != 0)
        {
            oddCount++;
        }
        while (oddCount > k)
        {
            int pEle = arr[prev];
            if ((pEle & 1) != 0)
            {
                oddCount--;
            }
            prev++;
        }
        curr++;
        len += (curr - prev);
    }
    return len;
}
int numberOfSubarrays(vector<int> &nums, int k)
{
    int atMostK = kDistinctSubarrays(nums, k);
    // cout<<"atMostK "<<atMostK<<endl;
    int atMostKMinus1 = kDistinctSubarrays(nums, k - 1);
    // cout<<"atMostKMinus1 "<<atMostKMinus1<<endl;

    return atMostK - atMostKMinus1;
}

int main()
{
    return 0;
}