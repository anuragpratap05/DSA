#include<bits/stdc++.h>
using namespace std;


    void topo_dfs(vector<vector<int>>& graph,int src,vector<int>& vis,vector<int>& ans)
{
    vis[src]=1;
    for(int e:graph[src])
    {
        if(vis[e]==0)
        {
            topo_dfs(graph,e,vis,ans);
        }
        else if(vis[e]==1)
        {
            return;
        }
    }
        //cout<<src<<" ";
        vis[src]=2;
    ans.push_back(src);
}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         int n=numCourses;
    vector<vector<int >>graph(n,vector<int>());
    for(int i=0;i<prerequisites.size();i++)
    {
        int u=prerequisites[i][0];
        int v=prerequisites[i][1];
        graph[u].push_back(v);
    } 
    vector<int> vis(n,0);
    vector<int >ans;
    for(int i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            topo_dfs(graph,i,vis,ans);
        }
    }
        
    //reverse(ans.begin(),ans.end());
    if(ans.size()==n)
    {
        return ans;
    }
    vector<int>v;
    return v;
    }

int main()
{
    return 0;
}