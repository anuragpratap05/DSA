#include<bits/stdc++.h>
using namespace std;
vector<int>par;
vector<int>size;
int find(int i)
{
    if(par[i]==i)
    {
        return i;
    }
    par[i]=find(par[i]);
    return par[i];
}
void unite(int p1,int p2)
{
    if(size[p1]<size[p2])
    {
        par[p1]=p2;
        size[p2]+=size[p1];
    }
    else{
        par[p2]=p1;
        size[p1]+=size[p2];
    }
}
int unionfind( vector<vector<int>>& edges)
{
    int sum=0;
    for(vector<int>& edge:edges)
    {
        int w=edge[0];
        int u=edge[1];
        int v=edge[2];

        int p1=find(u);
        int p2=find(v);
        if(p1!=p2)
        {
            unite(p1,p2);
            sum+=w;
        }
    }
    return sum;
}
int findwt(vector<int>& p1,vector<int>& p2)
{
    int a=abs(p1[0]-p2[0]);
    int b=abs(p1[1]-p2[1]);
    return a+b;
}
int minCostConnectPoints(vector<vector<int>>& points)
{
    int n=points.size();
    par.resize(n);
    size.resize(n,1);
    vector<vector<int>>edges;
    for(int i=0;i<n;i++)
    {
        par[i]=i;
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            edges.push_back({findwt(points[i],points[j]),i,j});
        }
    }
    sort(edges.begin(),edges.end());
    return unionfind(edges);
}

int main()
{
    return 0;
}