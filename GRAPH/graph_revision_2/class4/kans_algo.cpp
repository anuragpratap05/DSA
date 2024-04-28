#include<bits/stdc++.h>
using namespace std;

vector<int> kans_mama_algo(vector<vector<int>>& graph,vector<int>& indegree)
{
    queue<int> q;
    int n = graph.size();
    for (int i = 0; i < n; i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    int topo_velel = 0;
    vector<int> ans;

    while(!q.empty())
    {
        int size = q.size();
        while(size--)
        {
            int rn = q.front();
            q.pop();
            ans.push_back(rn);

            for(int e:graph[rn])
            {
                if(--indegree[e]==0)
                {
                    q.push(e);
                }
            }

        }
        topo_velel++;
    }
    return ans;
}

int main()
{
    return 0;
}