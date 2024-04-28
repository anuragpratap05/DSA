#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dir1 = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<string> moves1 = {"Up", "Right", "Down", "Left"};
pair<int, string> longest(int sr, int sc, int er, int ec, vector<vector<int>> &mat, string psf)
{
    if (sr == er and sc == ec)
    {
        return {1, psf};
    }
    mat[sr][sc] = 0;
    pair<int, string> myans = {-1, ""};
    for (int i = 0; i < dir1.size(); i++)
    {

        int r = sr + dir1[i][0];
        int c = sc + dir1[i][1];
        if (r >= 0 and c >= 0 and r <= er and c <= ec)
        {
            if (mat[r][c] == 1)
            {
                pair<int, string> p = longest(r, c, er, ec, mat, psf +  moves1[i] + " ");
                if (p.first != -1 and p.first + 1 > myans.first)
                {
                    myans.first = p.first + 1;
                    myans.second = p.second;
                }
            }
        }
       
    }
    mat[sr][sc] = 1;
    return myans;
}

int main()
{
    vector<vector<int>> vec(4, vector<int>(4, 1));
    vec[2][3] = 0;
    //vec[3][2] = 0;
    pair<int, string> ans = longest(0, 0, 3, 3, vec, "");

    cout << ans.first << endl;
    cout << ans.second;

    return 0;
}