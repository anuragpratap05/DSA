#include<bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    queue<int> q;
    vector<int> ans;
    q.push(0);
  

    vector<bool> vis(V, false);
    vis[0] = true;
    while (!q.empty())
    {
        int rn = q.front();
        q.pop();

        ans.push_back(rn);
        
        for (int e : adj[rn])
        {
            if (!vis[e])
            {
                vis[e] = true;
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