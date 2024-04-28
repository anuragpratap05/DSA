#include<bits/stdc++.h>
using namespace std;


void bellman_ford(vector<vector<int>> edges,int n,int src)
{
    vector<int>prev(n,1e9);
    prev[src]=0;
    vector<int> cur(n);
    for(int i=1;i<=n;i++)
    {
        bool isany_update=false;
        for(int i=0;i<n;i++)
        {
            cur[i]=prev[i];
        }
        for(vector<int>& edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            if(prev[u]+w<cur[v])
            {
                isany_update=true;
                cur[v]=prev[u]+w;
            }
        }
        for(int i=0;i<=n;i++)
        {
            prev[i]=cur[i];
        }
        for(int e:prev){
            cout<<e<<" ";
        }
        cout<<endl;
        if(i==n and isany_update)
        {
            cout<<"negative cycle is present";
        }
        if(!isany_update)
        {
            break;
        }
    }
}

int main()
{
    int V=5;
    vector<vector<int>>vec={{0,1,-1},{0,2,4},{1,2,3},{1,3,2},{3,2,5},{3,1,-1},{1,4,2},{4,3,-3}};
    bellman_ford(vec,V,0);
    return 0;
}