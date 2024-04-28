#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007;
// agar pehle mod kr doge to bda wala affect kho jaega

//see below
int kadans(vector<int> &nums)
{

    long long csum = 0, gsum = 0;

    for (int ele : nums)
    {
        csum += ele;
        // csum %= mod;
        if (csum > gsum)
        {
            gsum = csum;
        }

        if (csum < 0)
        {
            csum = 0;
        }
    }
    return gsum % mod;
}

int kConcatenationMaxSum(vector<int> &arr, int k)
{
    int n = arr.size();
    cout << n << endl;

    if (k == 1)
    {
        return kadans(arr) % mod;
    }
    else
    {
        long long mss = 0, mps = 0;
        long long csum = 0;
        for (long long ele : arr)
        {
            csum += ele;
            csum %= mod;
            if (csum > mps)
            {
                mps = csum;
            }
        }
        csum = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            long long ele = arr[i];
            csum += ele;
            csum %= mod;
            if (csum > mss)
            {
                mss = csum;
            }
        }
        long long arsum = 0;
        for (int e : arr)
        {
            arsum += e;
            arsum %= mod;
        }
        if (k == 2 or (k > 2 and arsum < 0))
        {
            long long ksum = kadans(arr);
            long long ans2 = (mss + mps);
            long long ans3 = max(ksum, ans2);
            // agar pehle mod kr doge to bda wala affect kho jaega
            return ans3 % mod;
         
        }
        else
        {
            long long ksum = kadans(arr);
            long long bichka_sum = (arsum * (k - 2)) % mod;
            long long ans3 = (mss + bichka_sum + mps) % mod;
            return max(ksum, ans3);
        }
    }
}
int main()
{
    return 0;
}