#include<bits/stdc++.h>
using namespace std;


class edge
{
    public:
    int v,w;
    edge(int v,int w)
    {
        this->v=v;
        this->w=w;
    }
};

void addedge(vector<vector<edge>>& graph,int u,int v,int w)
{
    graph[u].push_back(edge(v,w));
    graph[v].push_back(edge(u,w));


    
}

void display(vector<vector<edge>>& graph,int v)
{
    int n=graph.size();

    for(int i=0;i<n;i++)
    {
        cout<<i<<"-->";
        vector<edge> x=graph[i];
        for(auto ele:x)
        {
            
            cout<<"("<<ele.v<<","<<ele.w<<")  ";
        }
        cout<<endl;
    }
}

int findedge(vector<vector<edge>>& graph,int u,int v)
{
    int n=graph[u].size();
    for(int i=0;i<n;i++)
    {
        edge ele=graph[u][i];
        if(ele.v==v)
        {
            return i;
        }
    }
    return -1;
}

void removeedge(vector<vector<edge>>& graph,int u,int v)
{
    int idx=findedge(graph,u,v);
    //cout<<"idx="<<idx<<endl;
    graph[u].erase(graph[u].begin()+idx);
}

void removevertex(vector<vector<edge>>& graph,int u)
{
    int n=graph[u].size();
    for(int i=n-1;i>=0;i--)
    {
        edge e=graph[u][i];
        int v=e.v;
        removeedge(graph,u,v);

    }
}

bool haspath(vector<vector<edge>>& graph,int src,int dest,vector<bool>& visited)
{
    if(src== dest)
    {
        return true;
    }
    visited[src]=true;

    for(int i=0;i<graph[src].size();i++)
    {
        int nsrc=graph[src][i].v;
        if(!visited[nsrc])
        {
            
            bool isfound=haspath(graph,nsrc,dest,visited);
            
            if(isfound)
            {
                return true;
            }
        }

    }
    //visited[src]=false;
    return false;
}
int allpath(vector<vector<edge>>& graph,int src,int dest,string psf,vector<bool>& visited)
{
    if(src==dest)
    {
        psf+=to_string(dest);
        cout<<psf<<endl;
        return 1;
    }
    visited[src]=true;
    int c=0;

    for(int i=0;i<graph[src].size();i++)
    {
        int nsrc=graph[src][i].v;
        if(!visited[nsrc])
        {
            
            c+= allpath(graph,nsrc,dest,psf+to_string(src), visited);
            
            
        }

    }
    visited[src]=false;
    return c;


}

class pair_
{
    public:
    int heavy=0;
    string psf="";
    pair_()
    {

    }

    pair_(int heavy,string psf)
    {
        this->heavy=heavy;
        this->psf=psf;
    }
    
};

pair_ heaviestpath(vector<vector<edge>>& graph,int src,int dest,vector<bool>& visited)
{
    if(src==dest)
    {
       pair_ base(0,  to_string(src)+ "");
       return base; 
    }

    visited[src]=true;
    pair_ myans=pair_(-1,"");

    for(edge e:graph[src])
    {
        if(!visited[e.v])
        {
            pair_ recans=heaviestpath(graph,e.v,dest,visited);
            if(recans.heavy!=-1 and recans.heavy+e.w>myans.heavy)
            {
                myans.heavy=recans.heavy+e.w;
                myans.psf=  to_string(src) +recans.psf;
            }
        }
    }

    visited[src]=false;
    return myans;
    

}

void hamiltonion_pathandcycle(vector<vector<edge>>& graph,int src,int osrc,int c,string psf,vector<bool>& visited,vector<string>& vec)
{
    //cout<<"aya";
    if(c==graph.size()-1)
    {
        psf+=to_string(src);
        

        int idx=findedge(graph,src,osrc);
        if(idx!=-1)
        {
            psf+= "*";
        }
        vec.push_back(psf);
    }
    visited[src]=true;
    for(edge e:graph[src])
    {
        if(!visited[e.v])
        {
            hamiltonion_pathandcycle(graph,e.v,osrc,c+1,psf+ to_string(src), visited,vec);
        }
    }
    visited[src]=false;
    return;
}
int main()
{
    int V=9;
    vector<vector<edge>> graph(V,vector<edge>());

    addedge(graph,0,1,10);
    addedge(graph,0,3,10);
    addedge(graph,1,2,10);
    addedge(graph,2,3,40);

    addedge(graph,2,7,2);
    addedge(graph,2,8,4);
    addedge(graph,7,8,3);
    

    

    addedge(graph,3,4,2);
    addedge(graph,4,5,2);
    addedge(graph,4,6,8);
    addedge(graph,5,6,3);
    //addedge(graph,0,6,5);

    display(graph,V);
    // cout<<endl;
    // removeedge(graph,2,7);
    // cout<<endl;
    // display(graph,V);
    vector<bool> visited(V,false);
    // if(haspath(graph,0,10,visited))
    // {
    //     cout<<"path found";
    // }
    // else
    // {
    //     cout<<"path not found";
    // }

    cout<<allpath(graph,0,6,"",visited);
    //pair_  x =heaviestpath(graph,0,5,visited);


    // cout<<x.heavy<<endl;
    // cout<<x.psf<<endl;
    vector<string> vec;

    hamiltonion_pathandcycle(graph,0,0,0,"",visited,vec);

    for(auto e:vec)
    {
        cout<<e<<" ";
    }

    return 0;
}//Lost my family members due to which i was going through serious anxiety and depression.Had to look after home,office,my seriously ill father and post surgery complications making it  quiet tough.