#include<bits/stdc++.h>
using namespace std;

void createit(vector<vector<int>>& graph,int u,int v)
{
    graph[u].push_back(v);
    //graph[v].push_back(u);
}
vector<vector<int>> ans;
int print_all(vector<vector<int>>& graph,int src,int dest,vector<bool>& vis,string psf,vector<int>& v)
{
    if(src==dest)
    {
        psf+=to_string(dest);
        //cout<<psf<<endl;
        
        // for(int e:v)
        // {
        //     cout<<e<<" ";
        // }
        for(auto x:psf)
        {
            v.push_back(x-'0');
        }
        for(int e:v)
        {
            cout<<e<<" ";
        }
        cout<<endl;
        ans.push_back(v);
        v.clear();

        return 1;
    }
    vis[src]=true;
    int c=0;
    for(int i=0;i<graph[src].size();i++)
    {
        int e=graph[src][i];
        if(!vis[e])
        {
            //v.push_back(src);
            c+=print_all(graph,e,dest,vis,psf+to_string(src),v);
        }
    }
    vis[src]=false;
    return c;
}
void printit(vector<vector<int>>& graph)
{
    for(int i=0;i<graph.size();i++)
    {
        cout<<i<<"-->";
        for(int e:graph[i])
        {
            cout<<e<<" ";
        }
        cout<<endl;
    }
}
int possible_paths(vector<vector<int>>edges, int n, int s, int d)
{
    vector<bool> vis(n,false);
    vector<vector<int>> graph(n,vector<int>());
    // for(auto edge:edges)
    // {
    //     createit(graph,edge[0],edge[1]);
    // }
    for(int i=0;i<n;i++)
    {
        int u=i;
        for(int v:edges[i])
        {
           createit(graph,u,v); 
        }
    }
    //printit(graph);
    vector<int> v;
    return print_all(graph,s,d,vis,"",v);
}

int main()
{
   
    vector<vector<int>> input={{1,2},{3},{3},{}};
    int n=input.size();
        possible_paths(input,n,0,n-1);
        // for(vector<int>& vec:ans)
        // {
        //     for(int e:vec)
        //     {
        //         cout<<e<<" ";
        //     }
        //     cout<<endl;
        // }
  
    // int V=9;
    // vector<vector<edge>> graph(V,vector<edge>());

    // addedge(graph,0,1,10);
    // addedge(graph,0,3,10);
    // addedge(graph,1,2,10);
    // addedge(graph,2,3,40);

    // addedge(graph,2,7,2);
    // addedge(graph,2,8,4);
    // addedge(graph,7,8,3);
    

    

    // addedge(graph,3,4,2);
    // addedge(graph,4,5,2);
    // addedge(graph,4,6,8);
    // addedge(graph,5,6,3);
    //   vector<bool> visited(V,false);
    // // if(haspath(graph,0,10,visited))
    // // {
    // //     cout<<"path found";
    // // }
    // // else
    // // {
    // //     cout<<"path not found";
    // // }

    // cout<<print_all(graph,0,6,visited,"");
    return 0;
}