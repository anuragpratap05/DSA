#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > dirs; 


    dirs.push_back({-1,1});
    dirs.push_back({0,1});
    dirs.push_back({1,1});


int helper(int n, int m, vector<vector<int> >& M,int r,int c)
{
    if(c==m-1)
    {
        return M[r][c];
    }


    int myans=0;
    for(int i=0;i<dirs.size();i++)
    {
        int row=r+dirs[i][0];
        int col=c+dirs[i][1];

        if(row>=0 and row<n and col>=0 and col<m)
        {
            int recans=helper(n,m,M,row,col);
            if(recans+M[r][c] > myans )
            {
                myans=recans+M[r][c];
            }
        }
    }
    return myans;
}


int maxGold(int n, int m, vector<vector<int> > M)
    {
        int ans=-1;
        for(int i=0;i<n;i++)
        {
             ans=max(ans,helper(n,m,M,i,0));
        }

        return ans;
    }

int main()
{

}