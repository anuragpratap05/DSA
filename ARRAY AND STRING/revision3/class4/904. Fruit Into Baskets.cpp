#include <bits/stdc++.h>
using namespace std;
int kDistinctSubarrays(vector<int> &arr, int k)
{
    int arraySize = arr.size();
    int prev = 0, curr = 0, len = 0;
    vector<int> freq(1e5 + 1, 0);
    // unordered_map<int, int> freq;
    int distinctCount = 0;
    int maxLen = 0;
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
        maxLen = max(maxLen, (curr - prev));
    }
    return maxLen;
}
int totalFruit(vector<int> &fruits)
{
    return kDistinctSubarrays(fruits, 2);
}

int main()
{
    return 0;
}