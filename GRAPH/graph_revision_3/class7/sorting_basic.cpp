#include <bits/stdc++.h>
using namespace std;

void display2d(vector<vector<int>> &arr)
{
    for (auto &vec : arr)
    {
        for (int e : vec)
        {
            cout << e << " ";
        }
        cout << endl;
    }
}

void sortArray(vector<vector<int>> &arr)
{
    sort(arr.begin(), arr.end(), [](vector<int> &a, vector<int> &b)
         { return a[2] < b[2]; }); // this - other = a-b(in java) a<b (in C++) =default behaviour

    display2d(arr);
}

int main()
{
    vector<vector<int>> vec = {{1, 2, 4}, {3, 6, 2}, {2, -1, -3}, {34, 1, 34}};
    sortArray(vec);
    return 0;
}