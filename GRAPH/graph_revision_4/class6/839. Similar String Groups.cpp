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

// void unionFind(vector<vector<int>> &edges, int n)
// {
//     par.resize(n);
//     size.resize(n);
//     for (int i = 0; i < n; i++)
//     {
//         par[i] = i;
//         size[i] = 1;
//     }
//     for (vector<int> &vec : edges)
//     {
//         int u = vec[0];
//         int v = vec[1];
//         int p1 = find(u);
//         int p2 = find(v);

//         if (p1 != p2)
//         {
//             unite(p1, p2);
//         }
//     }
// }
bool isSimilar(string &s1, string &s2)
{
    int n = s1.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] != s2[i])
        {
            if (++cnt > 2)
            {
                return false;
            }
        }
    }
    return true;
}
int numSimilarGroups(vector<string> &strs)
{
    int n = strs.size();
    par.resize(n);
    size.resize(n);
    for (int i = 0; i < n; i++)
    {
        par[i] = i;
        size[i] = 1;
    }
    int cnt = n;
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
                    cnt--;
                }
            }
        }
    }
    return cnt;
}

int main()
{
    return 0;
}