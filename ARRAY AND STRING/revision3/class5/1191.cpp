#include <bits/stdc++.h>
using namespace std;
#define modu 1000000007;
int kadanes(vector<int> arr)
{
    int n = arr.size();
    long long csum = 0;
    long long gsum = 0;
    for (int i = 0; i < n; i++)
    {
        int ele = arr[i];
        csum += ele;
        csum %= modu;
        if (csum <= 0)
        {
            csum = 0;
        }
        if (csum > gsum)
        {
            gsum = csum;
        }
    }
    return gsum;
}

int kConcatenationMaxSum(vector<int> &arr, int k)
{
    long long kadaneAns = kadanes(arr);
    long long overAllMax = INT_MIN;
    int n = arr.size();
    if (k == 1)
    {
        return kadaneAns;
    }

    if (kadaneAns > overAllMax)
    {
        overAllMax = kadaneAns;
    }

    long long frontMax = 0, backMax = 0, cumSum = 0, arrSum = 0;
    for (int i = 0; i < n; i++)
    {
        cumSum += arr[i];
        cumSum %= modu;
        if (cumSum > frontMax)
        {
            frontMax = cumSum;
        }
    }
    arrSum = cumSum;
    cumSum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        cumSum += arr[i];
        cumSum %= modu;
        if (cumSum > backMax)
        {
            backMax = cumSum;
        }
    }

    if (arrSum < 0)
    {
        long backPlusFront = (backMax + frontMax) % modu;
        if (backPlusFront > overAllMax)
        {
            return backPlusFront;
        }
        return overAllMax;
    }
                                                                               
    long backPlusFront = (backMax + ((k - 2) * arrSum) % 1000000007 + frontMax);

    if (backPlusFront > overAllMax)
    {
        overAllMax = backPlusFront;
    }
    return overAllMax % modu;
}

int main()
{
    return 0;
}