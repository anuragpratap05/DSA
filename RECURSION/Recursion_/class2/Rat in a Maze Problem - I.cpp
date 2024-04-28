#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dir1 = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<string> moves1 = {"U", "R", "D", "L"};
void help(int sr, int sc, int er, int ec, vector<vector<int>> &vis,vector<string>ans,string psf)
{
    if(sr==er and sc==ec)
    {
        ans.push_back(psf);
        return;
    }
    vis[sr][sc]=0;
    for(int i=0;i<dir1.size();i++)
    {
        int r=sr+dir1[i][0];
        int c=sc+dir1[i][1];
        if(r>=0 and c>=0 and r<=er and c<=ec and vis[r][c]==1)
        {
            help(r,c,er,ec,vis,ans,psf+moves1[i]);
        }
    }
    vis[sr][sc] = 1;
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    int er=n-1;
    int ec=n-1;
    vector<string>ans;
    help(0,0,er,ec,m,ans,"");
    return ans;
}

int main()
{
    return 0;
}