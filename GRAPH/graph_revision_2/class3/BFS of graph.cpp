#include<bits/stdc++.h>
using namespace std;

// jb bhi cycle se related koi kam krna  ho to ye wala bfs lagan hai


vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    queue<int> q;
    vector<int> ans;
    q.push(0);

    vector<bool> vis(V, false);

    while(!q.empty())
    {
        int rn = q.front();
        q.pop();

        if(vis[rn])
        {
            //cycle
            continue;
        }
        ans.push_back(rn);
        vis[rn] = true;
        for(int e:adj[rn])
        {
            if(!vis[e])
            {
                q.push(e);
            }
        }
    }
    return ans;
}

int main()
{
    return 0;
}