// edges ke vector ko sort krke union find chla do ho gya kruskal
#include<bits/stdc++.h>
using namespace std;
vector<int> par;
vector<int> size;
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
    else
    {
        par[p2]=p1;
        size[p1]+=size[p2];
    }
}



void union_find(vector<vector<int>>& edges,int n)
{
    par.resize(n+1);
    size.resize(n+1,1);
    for(int i=0;i<=n;i++)
    {
        par[i]=i;
    }
    int sum=0;
    for(vector<int>& edge:edges)
    {
        int u=edge[0];
        int v=edge[1];
        int w=edge[2];
        int p1=find(u);
        int p2=find(v);
        if(p1!=p2)
        {
            sum+=w;
            unite(p1,p2);
        }

    }
}

void kruskal(vector<vector<int>>& edges)
{

}

int main()
{
    return 0;
}