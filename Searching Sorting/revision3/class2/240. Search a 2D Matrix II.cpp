#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int r = 0;
    int c = m - 1;

    while (r >= 0 and c >= 0 and r < n and c < m)
    {
        int curEle = matrix[r][c];
        if (curEle == target)
        {
            return true;
        }
        if (curEle > target)
        {
            c += -1;
        }
        else
        {
            r += 1;
        }
    }
    return false;
}

int main()
{
    return 0;
}