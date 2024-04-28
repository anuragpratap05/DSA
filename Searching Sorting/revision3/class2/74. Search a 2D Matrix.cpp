#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int s = 0;
    int e = (n * m) - 1;

    while (s <= e)
    {
        int mid = (s + e) / 2;
        int r = mid / m;
        int c = mid % m;
        int ele = matrix[r][c];
        if (ele == target)
        {
            return true;
        }
        if (ele < target)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return false;
}

int main()
{
    return 0;
}