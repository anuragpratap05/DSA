#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
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

vector<int> numIslands2(int m, int n, vector<vector<int>> &positions)
{
    for (int i = 0; i < n * m; i++)
    {
        par.push_back(i);
        size.push_back(1);
    }

    vector<vector<int>> mat(m, vector<int>(n, 0));
    vector<int> ans;
    int land = 0;
    for (vector<int> &cell : positions)
    {
        int i = cell[0];
        int j = cell[1];
        if (mat[i][j] == 1)
        {
            ans.push_back(land);
            continue;
        }
        mat[i][j] = 1;
        land++;
        for (vector<int> &vec : dirs)
        {
            int r = i + vec[0];
            int c = j + vec[1];
            if (r >= 0 and c >= 0 and r < m and c < n and mat[r][c] == 1)
            {
                int p1 = find((i * n) + j);
                int p2 = find((r * n) + c);

                if (p1 != p2)
                {
                    land--;
                    unite(p1, p2);
                }
            }
        }
        ans.push_back(land);
    }
    return ans;
}

int main()
{
    return 0;
}