#include<bits/stdc++.h>
using namespace std;
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

int supplyWater(int n, int k, vector<int> &wells, vector<vector<int>> &pipes) {
  	for(int i=0;i<n;i++)
    {
        pipes.push_back({0,i+1,wells[i]});
	}
    par.resize(n+1);
    
    sort(pipes.begin(),pipes.end(),[](vector<int>& a,vector<int>& b)
         {
             return a[2]<b[2];
		 });
    
    size.resize(n);
    for(int i=0;i<=n;i++)
    {
        par[i]=i;
        size[i]=1;
    }
    int cost=0;
    
    for(vector<int>& vec:pipes)
    {
        int u=vec[0];
        int v=vec[1];
        int w=vec[2];

        int p1=find(u);
        int p2=find(v);

        if(p1!=p2)
        {
            cost+=w;
            Union(p1,p2);
            //addedge(graph,u,v,w);
        }    
    }
    return cost;
    
    
    
}