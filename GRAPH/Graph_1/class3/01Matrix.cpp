#include<bits/stdc++.h>
using namespace std;


 vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
{
    int n=mat.size();
    int m=mat[0].size();
    queue<int>q;
    int truec=0;
    vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    int tt=n*m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mat[i][j]==0)
            {
                vis[i][j]=true;
                truec++;
                q.push(i*m+j);
            }
        }
    }
    int level=0;
    while(!q.empty())
    {
        int size=q.size();
        while(size--)
        {
            int idx=q.front();
            q.pop();
            int sr=idx/m;
            int sc=idx%m;

            for(int d=0;d<dir.size();d++)
            {
                int r=sr+dir[d][0];
                int c=sc+dir[d][1];

                if(r>=0 and c>=0 and r<n and c<m and vis[r][c]==false)
                {
                    vis[r][c]=true;
                    truec++;
                    mat[r][c]=level+1;
                    q.push(r*m+c);
                    if(tt==truec)
                    {

                    }
                }
            }
        }
        level++;
    }

    return mat;
}

int main()
{
    return 0;
}