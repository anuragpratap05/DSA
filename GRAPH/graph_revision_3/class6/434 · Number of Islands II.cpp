#include <bits/stdc++.h>
using namespace std;
struct Point
{
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

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
vector<int> numIslands2(int n, int m, vector<Point> &operators)
{
    par.resize(n * m);
    size.resize(n * m, 1);

    for (int i = 0; i < n * m; i++)
    {
        par[i] = i;
    }
    int ones = 0;
    vector<int> ans;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (auto p : operators)
    {
        int i = p.x;
        int j = p.y;
        if (grid[i][j] == 1)
        {
            ans.push_back(ones);
            continue;
        }
        grid[i][j] = 1;
        ones++;
        for (vector<int> &vec : dir)
        {
            int r = i + vec[0];
            int c = j + vec[1];
            if (r >= 0 and c >= 0 and r < n and c < m and grid[r][c] == 1)
            {
                int p1 = find(i * m + j);
                int p2 = find(r * m + c);
                if (p1 != p2)
                {
                    ones--;
                    unite(p1, p2);
                }
            }
        }
        ans.push_back(ones);
    }
    return ans;
}
int main()
{
    return 0;
}