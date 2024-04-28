#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> par,size;
    int find(int u)
{
    if(par[u]==u)
    {
        return u;

    }
    par[u]=find(par[u]);
    return par[u];
}
    void Union(int p1,int p2)
{
    if(size[p1]<size[p2])
    {
        par[p1]=p2;
        size[p2]+=size[p1];
    }
    else
    {
        par[p2]=p1;
        size[p1]+=size[p2];
    }
}
    int findwt(vector<vector<int>>& points,int i,int j)
    {
        int a=abs(points[i][0]-points[j][0]);
        int b=abs(points[i][1]-points[j][1]);
        return a+b;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        par.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++)
        {
            size[i]=1;
            par[i]=i;
        }
        vector<vector<int>> edges;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                edges.push_back({findwt(points,i,j),i,j});
            }
        }
        
        sort(edges.begin(),edges.end());
        int sum=0;
        
        for(vector<int>& vec:edges)
        {
            int w=vec[0];
            int u=vec[1];
            int v=vec[2];
            int p1=find(u);
            int p2=find(v);
            
            if(p1!=p2)
            {
                Union(p1,p2);
                sum+=w;
            }
        }
        return sum;
        
        
    }
};

int main()
{
    return 0;
}