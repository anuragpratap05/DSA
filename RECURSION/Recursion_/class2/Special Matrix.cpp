#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dir1 = {{0, 1}, {1, 0}};
vector<string> moves1 = {"R", "D"};

int help(int sr, int sc, int er, int ec, vector<vector<bool>> &vis)
{
    if(sr==er and sc==ec)
    {
        return 1;
    }
    int count=0;
    for(int i=0;i<dir1.size();i++)
    {
        int r=sr+dir1[i][0];
        int c=sc+dir1[i][1];
        if(r<er and c<ec and !vis[r][c])
        {
            count+=help(r,c,er,ec,vis);
        }
    }
    return count;

}

int FindWays(int n, int m, vector<vector<int>> blocked_cells)
{
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (auto &vec : blocked_cells)
    {
        int i = vec[0];
        int j = vec[1];
        vis[i - 1][j - 1] = true;
    }

    return help(0,0,n-1,m-1,vis);
}

int main()
{
    return 0;
}