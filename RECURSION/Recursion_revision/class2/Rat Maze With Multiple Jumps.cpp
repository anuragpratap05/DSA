#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dir = {{0, 1}, {1, 0}};

bool hasPath(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &ans)
{
    int n = matrix.size();
    int m = matrix[0].size();
    if (i == n - 1 and j == m - 1)
    {
        ans[i][j] = 1;
        return true;
    }
    ans[i][j] = 1;
    for (int jump = 1; jump <= matrix[i][j]; jump++)
    {
        for (vector<int> &vec : dir)
        {
            int r = i + jump * vec[0];
            int c = j + jump * vec[1];
            if (r == n - 1 and c == m - 1)
            {
                ans[r][c] = 1;
                return true;
            }
            if (r >= 0 and c >= 0 and r < n and c < m and matrix[r][c] > 0)
            {

                bool x = hasPath(matrix, r, c, ans);
                if (x)
                {
                    return true;
                }
            }
        }
    }
    ans[i][j] = 0;

    return false;
}
vector<vector<int>> ShortestDistance(vector<vector<int>> &matrix)
{

    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans(n, vector<int>(m, 0));
    bool x = hasPath(matrix, 0, 0, ans);
    if (x)
    {

        return ans;
    }

    return {{-1}};
}

int main()
{
    return 0;
}