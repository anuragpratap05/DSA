class Solution {
public:
      vector<int> ans;
    void addedge(vector<vector<int>>& graph,int u,int v)
{
    graph[u].push_back(v);
}
    void kahns_topological_bfs(vector<vector<int>>& graph)
{
    int n=graph.size();
    vector<int> indegree(n,0);
    
    for(vector<int>& v:graph)
    {
        for(int e:v)
        {
            indegree[e]++;
        }
    }
    queue<int>q;

    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    
    int level=0;
    while(!q.empty())
    {
        int size=q.size();
        while(size--)
        {
            int vtx=q.front();
            q.pop();
            ans.push_back(vtx);

            for(int e:graph[vtx])
            {
                if(--indegree[e]==0)
                {
                    q.push(e);
                }
            }
        }
        level++;
    }
    
}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         int n=prerequisites.size();
        vector<vector<int>> graph(numCourses,vector<int>());

        for(int i=0;i<n;i++)
        {
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            
            addedge(graph,u,v);
        }
        kahns_topological_bfs(graph);
        if(ans.size()==numCourses)
        {
            reverse(ans.begin(),ans.end());
            return ans;
        }
        vector<int> v;
        return v;
    }
};