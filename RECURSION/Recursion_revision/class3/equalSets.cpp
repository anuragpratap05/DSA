#include <bits/stdc++.h>
using namespace std;

void equalSets(vector<int> &arr, int idx, int sum1, int sum2, string psf1, string psf2)
{
    if (idx == arr.size())
    {
        if (sum1 == sum2)
        {
            cout << psf1 << "  " << psf2 << endl;
        }
        return;
    }
    equalSets(arr, idx + 1, sum1 + arr[idx], sum2, psf1 + to_string(arr[idx]), psf2);
    equalSets(arr, idx + 1, sum1, sum2 + arr[idx], psf1, psf2 + to_string(arr[idx]));
}

int main()
{
    // vector<int> arr = {4, 1, 2, 3};
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80};
    equalSets(arr, 1, 10, 0, "10", "");
    return 0;
}