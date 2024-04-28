#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dir = {{0, 1}, {1, 0}};

bool ShortestDistanceHelper(int sr, int sc, int er, int ec, vector<vector<int>> &matrix, vector<vector<int>> &ans)
{
    if (sr == er and sc == ec)
    {
        ans[sr][sc] = 1;
        return true;
    }
    int digit = matrix[sr][sc];
    ans[sr][sc] = 1;
    // bool res = false;
    for (int jump = 1; jump <= digit; jump++)
    {
        for (vector<int> &vec : dir)
        {
            int r = sr + jump * vec[0];
            int c = sc + jump * vec[1];
            if (r == er and c == ec)
            {
                ans[r][c] = 1;
                return true;
            }
            if (r >= 0 and c >= 0 and r <= er and c <= ec and matrix[r][c] != 0)
            {
                bool res = ShortestDistanceHelper(r, c, er, ec, matrix, ans);
                if (res)
                {
                    return true;
                }
            }
        }
    }
    // if(!res)
    ans[sr][sc] = 0;
    return false;
}

vector<vector<int>> ShortestDistance(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    // if(matrix[0][0]==0 or matrix[n-1][m-1]==0)
    // {
    //     return {{-1}};
    // }
    vector<vector<int>> ans(n, vector<int>(m, 0));
    bool x = ShortestDistanceHelper(0, 0, n - 1, m - 1, matrix, ans);
    if (x)
        return ans;
    return {{-1}};
}

int main()
{
    return 0;
}