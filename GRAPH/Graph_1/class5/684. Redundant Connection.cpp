class Solution {
public:
    vector<int> par,size;
    int find(int u)
    {
        if(par[u]==u)
        {
            return u;

        }
        par[u]=find(par[u]);
        return par[u];
    }
    void Union(int p1,int p2)
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        par.resize(n+1);
        size.resize(n+1);
        for(int i=1;i<=n;i++)
        {
            par[i]=i;
            size[i]=1;
        }
        
        for(vector<int>& vec:edges)
        {
            int u=vec[0];
            int v=vec[1];

            int p1=find(u);
            int p2=find(v);

            if(p1!=p2)
            {
                Union(p1,p2);
                //addedge(graph,u,v);
            }
            else
            {
                return vec;
            }
        }
        vector<int> v;
        return v;
    }
};