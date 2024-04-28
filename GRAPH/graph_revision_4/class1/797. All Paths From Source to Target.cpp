#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &graph, int src, int dest, vector<int> &sa, vector<vector<int>> &ans)
{
    if (src == dest)
    {
        sa.push_back(src);
        ans.push_back(sa);
        sa.pop_back();
        return 1;
    }
    int cnt = 0;
    sa.push_back(src);
    for (int e : graph[src])
    {
        cnt += dfs(graph, e, dest, sa, ans);
    }
    sa.pop_back();
    return cnt;
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> sa;
    vector<vector<int>> ans;
    dfs(graph, 0, n - 1, sa, ans);
    return ans;
}

int main()
{
    return 0;
}