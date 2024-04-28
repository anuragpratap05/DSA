#include<bits/stdc++.h>
using namespace std;

void bellman_ford(vector<vector<int>>& edges,int n,int src)
{



    vector<int> prev(n,INT_MAX);
    prev[src]=0;
    vector<int> cur(n);
    //cur[src]=0;

    for(int i=1;i<=n;i++)
    {
        for(int i=0;i<n;i++)
        {
            cur[i]=prev[i];
        }
        bool ischange=false;
        for(vector<int>& vec:edges)
        {
            int u=vec[0];
            int v=vec[1];
            int w=vec[2];
            
            if(prev[u]+w<cur[v])
            {
                cur[v]=prev[u]+w;
                ischange=true;
            }
            if(i==n and ischange)
            {
                cout<<"negative cycle is present";
            }
            if(!ischange)
            {
                break;
            }

        }
        for(int i=0;i<n;i++)
        {
            prev[i]=cur[i];
            cout<<prev[i]<<" ";
        }
        cout<<endl;
    }

}


int main()
{
    int V=5;
    vector<vector<int>>vec={{0,1,-1},{0,2,4},{1,2,3},{1,4,2},{4,2,5},{4,1,-1},{1,3,2},{3,4,-3}};
    bellman_ford(vec,V,0);
    return 0;
}