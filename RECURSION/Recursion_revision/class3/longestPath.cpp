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
pair_ longestPath(vector<vector<bool>> &mat, int i, int j)
{
    int n = mat.size();
    int m = mat[0].size();
    if (i == n - 1 and j == m - 1)
    {
        pair_ p;
        return p;
    }
    mat[i][j] = true;
    pair_ myAns;
    myAns.len = -1;
    for (int itr = 0; itr < dir.size(); itr++)
    {
        vector<int> &vec = dir[itr];
        int r = i + vec[0];
        int c = j + vec[1];
        if (r >= 0 and c >= 0 and r < n and c < m and !mat[r][c])
        {
            pair_ recAns = longestPath(mat, r, c);
            if (recAns.len != -1 and recAns.len + 1 > myAns.len)
            {
                myAns.len = recAns.len + 1;
                myAns.psf = dirs[itr] + recAns.psf;
            }
        }
    }
    mat[i][j] = false;
    return myAns;
}

int main()
{
    vector<vector<bool>> mat(5, vector<bool>(5, false));
    // mat[2][3] = true;
    // mat[3][2] = true;
    mat[1][2] = true;
    mat[2][3] = true;
    mat[3][1] = true;
    mat[4][3] = true;
    mat[2][1] = true;
    pair_ p = longestPath(mat, 0, 0);
    cout << p.len << "  " << p.psf;
    return 0;
}