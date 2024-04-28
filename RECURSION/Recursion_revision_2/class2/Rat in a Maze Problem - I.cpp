#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<string> dirs = {"U", "R", "D", "L"};

int findPathhelper(int sr, int sc, int er, int ec, vector<string> &ans, string psf, vector<vector<int>> &m)
{
    if (sc == ec and sr == er)
    {
        ans.push_back(psf);
        return 1;
    }
    int cnt = 0;
    m[sr][sc] = 0;
    for (int i = 0; i < dir.size(); i++)
    {
        vector<int> &vec = dir[i];
        int r = sr + vec[0];
        int c = sc + vec[1];
        if (r >= 0 and c >= 0 and r <= er and c <= ec and m[r][c] == 1)
        {
            cnt += findPathhelper(r, c, er, ec, ans, psf + dirs[i], m);
        }
    }
    m[sr][sc] = 1;
    return cnt;
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> ans;
    if (m[0][0] == 0 or m[n - 1][n - 1] == 0)
    {
        return ans;
    }
    findPathhelper(0, 0, n - 1, n - 1, ans, "", m);
    return ans;
}

int main()
{
    return 0;
}