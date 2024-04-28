#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
{
    int n=mat.size();
    int m=mat[0].size();
    queue<int>q;
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mat[i][j]==0)
            {
               q.push(i*m+j);
               vis[i][j]=true;
            }
        }
    }  
    int level=0;
    vector<vector<int>> dir={{-1,0},{0,1},{1,0},{0,-1}};

    while(!q.empty())
    {
        int size=q.size();
        while(size--)
        {
            int idx=q.front();
            q.pop();
            int i=idx/m;
            int j=idx%m;
            for(auto vec:dir)
            {
                int r=i+vec[0];
                int c=j+vec[1];
                if(r>= 0 and c>=0 and r<n and c<m and vis[r][c]==false)
                {
                    vis[r][c]=true;
                    q.push(r*m+c);
                    mat[r][c]=level+1;
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