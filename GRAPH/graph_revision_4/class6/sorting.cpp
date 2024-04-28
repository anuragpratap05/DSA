#include <bits/stdc++.h>
using namespace std;
void display(vector<vector<int>> &arr)
{
    for (vector<int> &vec : arr)
    {
        for (int e : vec)
        {
            cout << e << " ";
        }
        cout << endl;
    }
}

void sortArray(vector<vector<int>> &vec)
{
    sort(vec.begin(), vec.end(), [](vector<int> &a, vector<int> &b)
        { 
            return a[2] < b[2];// this - other ->default behavior
            return b[2] < a[2];// other - this -> rev of def behaviour
        });

    display(vec);
}

int main()
{
    vector<vector<int>> vec = {{1, 2, 14}, {12, 3, 2}, {-1, 3, -2}, {2, 44, 43}};
    sortArray(vec);
    return 0;
}