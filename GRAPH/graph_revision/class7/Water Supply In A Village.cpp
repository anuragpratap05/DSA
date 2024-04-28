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

void sort_array(vector<vector<int>>& arr)
{
    sort(arr.begin(),arr.end(),[](vector<int>& a,vector<int>& b)
    {
        // if(a[2]==b[2])
        // {
        //     return a[1]>b[1];
        // }
        return a[2]<b[2];
    });
    //display(arr);
}

int union_find(vector<vector<int>>& edges,int n)
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
    return sum;
}

int supplyWater(int n, int k, vector<int> &wells, vector<vector<int>> &pipes)
{
    for(int i=0;i<wells.size();i++)
    {
        pipes.push_back({0,i+1,wells[i]});
    }

    sort_array(pipes);

    return union_find(pipes,n);

      
}

int main()
{
    return 0;
}