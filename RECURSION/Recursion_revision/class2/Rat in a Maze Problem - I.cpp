#include <bits/stdc++.h>
using namespace std;
int floodFill(int sr, int sc, int er, int ec, vector<string> &ans, vector<vector<bool>> &vis, string psf, vector<vector<int>> &dir, vector<string> &dirs, vector<vector<int>> &m)
{
    if (sr == er and sc == ec)
    {
        ans.push_back(psf);
        return 1;
    }
    vis[sr][sc] = true;
    int cnt = 0;
    for (int i = 0; i < dir.size(); i++)
    {
        vector<int> &vec = dir[i];
        int r = sr + vec[0];
        int c = sc + vec[1];
        if (r >= 0 and c >= 0 and r <= er and c <= ec and !vis[r][c] and m[r][c] == 1)
        {
            cnt += floodFill(r, c, er, ec, ans, vis, psf + dirs[i], dir, dirs, m);
        }
    }
    vis[sr][sc] = false;
    return cnt;
}
vector<string> findPath(vector<vector<int>> &m, int n)
{
    if (m[0][0] == 0 or m[n - 1][n - 1] == 0)
    {
        return {};
    }
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (m[i][j] == 0)
            {
                vis[i][j] = true;
            }
        }
    }
    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<string> dirs = {"U", "R", "D", "L"};
    vector<string> ans;
    floodFill(0, 0, n - 1, n - 1, ans, vis, "", dir, dirs, m);
    return ans;
}

int main()
{
    return 0;
}