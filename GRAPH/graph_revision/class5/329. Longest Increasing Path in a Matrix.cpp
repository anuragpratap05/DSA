#include<bits/stdc++.h>
using namespace std;


int longestIncreasingPath(vector<vector<int>>& matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int>> dir={{-1,0},{0,1},{1,0},{0,-1}}; 
    vector<vector<int>> indegree(n,vector<int>(m,0));
    for(int i=0;i<n;i++ )
    {
        for(int j=0;j<m;j++)
        {
           for(auto vec:dir)
            {
                int r=i+vec[0];
                int c=j+vec[1];
                if(r>= 0 and c>=0 and r<n and c<m and matrix[r][c]<matrix[i][j])
                {
                    indegree[i][j]++;
                }
            }
        }
    }  
    queue<int>q;
    for(int i=0;i<n;i++ )
    {
        for(int j=0;j<m;j++)
        {
           if(indegree[i][j]==0)
           {
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
            int i=idx/m;
            int j=idx%m;
            q.pop();
            for(auto vec:dir)
            {
                int r=i+vec[0];
                int c=j+vec[1];
                if(r>= 0 and c>=0 and r<n and c<m and indegree[r][c]>0 and matrix[r][c]>matrix[i][j])
                {
                    indegree[r][c]--;
                    if(indegree[r][c]==0)
                    {
                        q.push(r*m+c);
                    }
                }
            }
        }
        level++;
    }
    return level;
     
}

int main()
{
    return 0;
}