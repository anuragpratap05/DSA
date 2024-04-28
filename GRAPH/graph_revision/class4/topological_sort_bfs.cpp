#include<bits/stdc++.h>
using namespace std;

// * reverse of vector ans gives us topological order.*

vector<int> kahns_algo(vector<vector<int >>& graph,int n)
{
    vector<int> indegree(n,0);
    for(vector<int>& vec:graph)
    {
        for(int e:vec)
        {
            indegree[e]++;
        }
    }
    queue<int> q;

    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    int level=0;
    vector<int> ans;
    while(!q.empty())
    {
        int size=q.size();
        while(size--)
        {
            int vtx=q.front();
            q.pop();
            ans.push_back(vtx);
            for(int nbr:graph[vtx])
            {
                indegree[nbr]--;
                if(indegree[nbr]==0)
                {
                    q.push(nbr);
                }
            }
        }
        level++;
    }
    return ans;
}


bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
{
    int n=numCourses;
    vector<vector<int >>graph(n,vector<int>());
    for(int i=0;i<prerequisites.size();i++)
    {
        int u=prerequisites[i][0];
        int v=prerequisites[i][1];
        graph[u].push_back(v);
    }  

    vector<int> ans=kahns_algo(graph,n);
    // reverse ans to get right way of which thing is done first
    if(ans.size()==n)
    {
        return true;
    }      
    return false;
}

int main()
{
    return 0;
}