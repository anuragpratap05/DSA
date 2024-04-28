#include <bits/stdc++.h>
using namespace std;

int kDistinctSubarrays(vector<int> &arr, int n, int k)
{
    int arraySize = n;
    int prev = 0, curr = 0, len = 0;
    // vector<int> freq(1e9, 0);
    unordered_map<int, int> freq;
    int distinctCount = 0;
    while (curr < arraySize)
    {
        int ele = arr[curr];
        if (++freq[ele] == 1)
        {
            distinctCount++;
        }
        while (distinctCount > k)
        {
            int pEle = arr[prev];
            if (--freq[pEle] == 0)
            {
                distinctCount--;
            }
            prev++;
        }
        curr++;
        len += (curr - prev);
    }
    return len;
}

int main()
{
    return 0;
}