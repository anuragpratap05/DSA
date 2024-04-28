#include <bits/stdc++.h>
using namespace std;



void dfs(vector<vector<int>> &graph, int s, int d, vector<int> &sa, vector<vector<int>> &ans)
{
    if (s == d)
    {
        sa.push_back(s);
        ans.push_back(sa);
        sa.pop_back();
        return;
    }

    sa.push_back(s);

    for(int e:graph[s])
    {
        dfs(graph, e, d, sa, ans);
    }
    sa.pop_back();
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    vector<int> sa;
    vector<vector<int>> ans;

    dfs(graph, 0, graph.size() - 1, sa, ans);
    return ans;
}

int main()
{
    return 0;
}