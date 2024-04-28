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
int main()
{
    int n,m,k,a,b,c;
    cin>>n>>m>>k;
    par.resize(n+1);
    size.resize(n+1,1);
    for(int i=0;i<=n;i++)
    {
        par[i]=i;
    }

    vector<vector<int>> edges(m,vector<int>());
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        edges.push_back({a,b,c});

    }

    sort_array(edges);
    int sets=n;
    int sum=0;
    vector<int>roads;
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
            roads.push_back(w);
            sets--;
            unite(p1,p2);
        }
    }
    if(sets>1)
    {
        return -1;
    }
    int ans=0;
    for(int i=roads.size()-1;i>=0;i--)
    {
        if(sum>k)
        {
            ans++;
            sum= (sum-roads[i])+1;
        }
        else{
            break;
        }
        

    }
    return (sum>k?-1:ans);

    return 0;
}