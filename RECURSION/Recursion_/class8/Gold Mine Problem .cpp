#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>dir={{-1,1},{0,1},{1,1}};

int maxgold_help(vector<vector<int>> M, int i, int j)
{
    int n=M.size();
    int m=M[0].size();
    if(j==m-1)
    {
        return M[i][j];
    }
    int myans=0;
    for(auto& vec:dir)
    {
        int r=i+vec[0];
        int c=j+vec[1];
        if(r>=0 and c>=0 and r<n and c<m)
        {
            int rec_ans=maxgold_help(M,r,c);
            if (rec_ans + M[r][c] > myans)
            {
                myans=rec_ans+M[r][c];
            }
        }
    }
    return myans;


}

int maxGold(int n, int m, vector<vector<int>> M)
{
    int ans=0;
    for(int i=0;i<m;i++)
    {
        ans = max(ans, maxgold_help(M,i,0));
    }
    return ans;
}

int main()
{
    return 0;
}