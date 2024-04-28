#include<bits/stdc++.h>
using namespace std;

// pas hi nhi ho rha sala

int find(int u,vector<int>& par,vector<int>& size)
{
    if(par[u]==u)
    {
        return u;

    }
    par[u]=find(par[u],par,size);
    return par[u];
}
void Union(int p1,int p2,vector<int>& par,vector<int>& size)
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
vector<int> ans;
int union_find(vector<vector<int>>& edges,vector<int>& par,vector<int>& size,int n)
{
    int sum=0;
    int num=n;
    for(vector<int>& vec:edges)
    {
        int u=vec[0];
        int v=vec[1];
        int w=vec[2];

        int p1=find(u,par,size);
        int p2=find(v,par,size);
        if(p1!=p2)
        {
            num--;
            sum+=w;
            ans.push_back(w);
            Union(p1,p2,par,size);
            //addedge(graph,u,v,w);
        }
    }
    if(num>1)
    {
        return -1;
    }
    return sum;
}
void sortvector(vector<vector<int>>& vec)
{
    // this function will sort all vectors that are inside vec on basis of index 2.
    sort(vec.begin(),vec.end(), [](vector<int>& a,vector<int>& b)
    {
        return a[2]<b[2];
    });
    //display(vec);
}



int main()
{
    int n,m,k,a,b,c;
    
    cin>>n>>m>>k;
    
    vector<int> par(n+1);
    vector<int> size(n+1);
    
    for(int i=1;i<=n;i++)
    {
        par[i]=i;
        size[i]=1;
    }
    vector<vector<int>> edges;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        edges.push_back({a,b,c});
    }
    //cout<<"sorting se phle"<<endl;
    sortvector(edges);
    //cout<<"sorting ke bad"<<endl;
    //cout<<endl;
    int sum=union_find(edges,par,size,n);
    if(sum==-1)
    {
        cout<<"-1";
        return 0;
    }
    
    // cout<<"def="<<def<<endl;
    // cout<<"sum="<<sum<<endl;
    if(sum<=k)
    {
        cout<<"0";
        return 0;
    }
    int count=0;

    
    

    sort(ans.begin(), ans.end(), greater<int>());

    for(int e:ans)
    {
        sum-=e;
        count++;
        if(sum<=k)
        {
            cout<<count;
            return 0;
        }
    }

    cout<<"-1";

    return 0;
}