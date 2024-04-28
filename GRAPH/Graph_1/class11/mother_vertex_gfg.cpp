#include<bits/stdc++.h>
using namespace std;


class Solution 
{
    public:
    vector<int> ans;
    void dfs(vector<int> graph[],int src,vector<bool>& vis)
    {
        vis[src]=true;
        for(int e:graph[src])
        {
            if(!vis[e])
            {
                dfs(graph,e,vis);
            }
        }
        ans.push_back(src);
    }
    void topological_dfs(vector<int> graph[],int n)
    {
        //int n=graph.size();
        vector<bool> vis(n,false);
        
    
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(graph,i,vis);
            }
        }
        // for(int e:ans)
        // {
        //     cout<<e<<" ";
        // }
    }
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    topological_dfs(adj,V);
	    vector<bool>vis(V,false);
	    int src=ans[ans.size()-1];
	    
	    dfs(adj,src,vis);
	    for(int i=0;i<vis.size();i++)
	    {
	        if(vis[i]==false)
	        {
	            return -1;
	        }
	    }
	    return src;
	}

};

int main()
{
    return 0;
}