//leetcode785
class Solution {
public:
    bool is_bipartite(vector<vector<int>>& graph,int src,vector<int>& vis)
{
    queue<int> q;
    q.push(src);
    int color=0;
    bool cycle=false;
    bool is_bipartite=true;

    while(!q.empty())
    {
        int size=q.size();
        color=(color+1)%2;
        while(size--)
        {
            int vtx=q.front();
            q.pop();
            if(vis[vtx]!=-1)
            {
                if(vis[vtx]!=color)
                {
                    is_bipartite=false;
                    return false;
                }
                cycle=true;
                continue;

            }

            vis[vtx]=color;
            for(int e:graph[vtx])
            {
                if(vis[e]==-1)
                {
                    q.push(e);
                }
            }

        }
    }
    return is_bipartite;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,-1);
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==-1)
            {
                bool ans=is_bipartite(graph,i,vis);
                if(!ans)
                {
                    return false;
                }  
            }
            
            
        }
        return true;
    }
};