#include<bits/stdc++.h>
using namespace std;


  int bellman_ford(vector<vector<int>>& edges,int n,int src,int dst,int k)
{

    vector<int> prev(n,1e7);
    prev[src]=0;
    vector<int> cur(n);

    for(int i=1;i<=k;i++)
    {
        for(int i=0;i<n;i++)
        {
            cur[i]=prev[i];
        }

        for(vector<int>& vec:edges)
        {
            int u=vec[0];
            int v=vec[1];
            int w=vec[2];

            if(prev[u]+w<cur[v])
            {
                cur[v]=prev[u]+w;
            }

        }
        for(int i=0;i<n;i++)
        {
            prev[i]=cur[i];
        }
    }
        if(cur[dst]==1e7)
        {
            return -1;
        }
        return cur[dst];

}
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        return bellman_ford(flights,n,src,dst,k+1);
    }

int main()
{
    return 0;
}