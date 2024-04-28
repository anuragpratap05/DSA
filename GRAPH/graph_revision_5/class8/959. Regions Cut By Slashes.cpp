#include <bits/stdc++.h>
using namespace std;
vector<int> par;
vector<int> size;

int find(int i)
{
    if (par[i] == i)
        return i;
    return par[i] = find(par[i]);
}

void unite(int p1, int p2)
{
    int maxSize = 0;
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
int regionsBySlashes(vector<string> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    n += 1;
    m += 1;

    for (int i = 0; i < n*m; i++)
    {
        par.push_back(i);
        size.push_back(1);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 or j == 0 or i == n - 1 or j == m - 1)
            {
                if (par[(i * m) + j] != 0)
                {
                    par[(i * m) + j] = 0;
                    size[0] += 1;
                }
            }
        }
    }
    int ans = 1;
    for (int i = 0; i < grid.size(); i++)
    {
        string &str = grid[i];
        for (int j = 0; j < str.size(); j++)
        {
            char ch = str[j];
            if (ch == '/')
            {
                int r1 = i;
                int c1 = j + 1;

                int r2 = i + 1;
                int c2 = j;

                int p1 = find((r1 * m) + c1);
                int p2 = find((r2 * m) + c2);
                if (p1 != p2)
                {
                    unite(p1, p2);
                }
                else
                {
                    ans++;
                }
            }
            else if (ch == '\\')
            {
                int r1 = i;
                int c1 = j;

                int r2 = i + 1;
                int c2 = j + 1;

                int p1 = find((r1 * m) + c1);
                int p2 = find((r2 * m) + c2);
                if (p1 != p2)
                {
                    unite(p1, p2);
                }
                else
                {
                    ans++;
                }
            }
        }
    }
    return ans;
}

int main()
{
    return 0;
}