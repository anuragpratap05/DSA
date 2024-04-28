#include <bits/stdc++.h>
using namespace std;

int segregate(vector<int> &arr, int si, int ei, int pivot)
{
    swap(arr[pivot], arr[ei]);

    int p = si - 1;
    int itr = si;
    while (itr <= ei)
    {
        if (arr[itr] <= arr[ei])
        {
            p++;
            swap(arr[p], arr[itr]);
        }
        itr++;
    }
    return p;
}

void quicksort(vector<int> &arr, int si, int ei)
{
    if (si >= ei)
    {
        return;
    }
    int pivot = (si + ei) / 2;

    int pidx = segregate(arr, si, ei, pivot);

    quicksort(arr, si, pidx - 1);
    quicksort(arr, pidx + 1, ei);
}

int main()
{
    // vector<int> vec = {1, 4, 2, 5, 8, 4, 7, 4, 7, 34, 65, 56, 23, 86, 87, 34};
    vector<int> vec = {5, 2, 3, 1};

    quicksort(vec, 0, vec.size() - 1);
    for (int ele : vec)
    {
        cout << ele << " ";
    }
    return 0;
}