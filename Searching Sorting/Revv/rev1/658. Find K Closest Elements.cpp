#include <bits/stdc++.h>
using namespace std;

vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    int n = arr.size();
    int s = 0, e = n - k;

    while (s < e)
    {
        int mid = (s + e) / 2;
        int lastIdx = mid + k;
        if (abs(arr[mid] - x) <= abs(arr[lastIdx] - x))
        {
            e = mid;
        }
        else
            s = mid + 1;
    }
    return {arr.begin() + s, arr.begin() + (s + k)};
}

int main()
{
    return 0;
}