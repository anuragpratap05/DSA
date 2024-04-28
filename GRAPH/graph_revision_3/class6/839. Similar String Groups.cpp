#include <bits/stdc++.h>
using namespace std;
vector<int> par;
vector<int> size;

int find(int i)
{
    if (par[i] == i)
    {
        return i;
    }

    return par[i] = find(par[i]);
    // return par[i];
}

void unite(int p1, int p2)
{
    if (size[p1] > size[p2])
    {
        par[p2] = p1;
        size[p1] += size[p2];
    }
    else
    {
        par[p1] = p2;
        size[p2] += size[p1];
    }
}

void unionFind(int V, vector<vector<int>> &connections)
{
    par.resize(V);
    size.resize(V, 1);
    for (int i = 0; i < V; i++)
    {
        par[i] = i;
    }
    for (vector<int> &vec : connections)
    {
        int u = vec[0];
        int v = vec[1];

        int p1 = find(u);
        int p2 = find(v);

        if (p1 != p2)
        {
            unite(p1, p2);
        }
    }
}
bool isSimilar(string &str1, string &str2)
{
    int cnt = 0;
    for (int i = 0; i < str1.size(); i++)
    {
        if (str1[i] != str2[i])
        {
            cnt++;
        }
        if (cnt > 2)
        {
            return true;
        }
    }
    return false;
}
int numSimilarGroups(vector<string> &strs)
{
    int n = strs.size();
    par.resize(n);
    size.resize(n, 1);
    for (int i = 0; i < n; i++)
    {
        par[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (isSimilar(strs[i], strs[j]))
            {
                int p1 = find(i);
                int p2 = find(j);
                if (p1 != p2)
                {
                    unite(p1, p2);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (par[i] == i)
        {
            ans++;
        }
    }
    return ans;
}

int main()
{
    return 0;
}