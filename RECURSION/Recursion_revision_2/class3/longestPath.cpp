#include <bits/stdc++.h>
using namespace std;

class pair_
{
public:
    int len = 0;
    string psf = "";
};
vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<string> dirs = {"Up", "Right", "Down", "Left"};

pair_ longestPath(int sr, int sc, int er, int ec, vector<vector<bool>> &vis)
{
    if (sr == er and sc == ec)
    {
        pair_ p;
        return p;
    }
    vis[sr][sc] = true;
    pair_ myAns;
    myAns.len = -1;
    for (int i = 0; i < dir.size(); i++)
    {
        vector<int> &vec = dir[i];
        int r = sr + vec[0];
        int c = sc + vec[1];
        if (r >= 0 and c >= 0 and r <= er and c <= ec and !vis[r][c])
        {
            pair_ recAns = longestPath(r, c, er, ec, vis);
            if (recAns.len != -1 and recAns.len + 1 > myAns.len)
            {
                myAns.len = recAns.len + 1;
                myAns.psf = dirs[i] + recAns.psf;
            }
        }
    }
    vis[sr][sc] = false;

    return myAns;
}

int main()
{
    vector<vector<bool>> mat(5, vector<bool>(5, false));
    mat[1][2] = true;
    mat[2][3] = true;
    mat[3][1] = true;
    mat[4][3] = true;
    pair_ p = longestPath(0, 0, 4, 4, mat);
    cout << p.len << "  " << p.psf;
    return 0;
}