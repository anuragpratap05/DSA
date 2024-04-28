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
// vector<vector<int>> dir = {{0, 1}, {1, 0}};

void unite(int p1, int p2)
{
    if (size[p1] < size[p2])
    {
        par[p1] = p2;
        size[p2] += size[p1];
    }
    else
    {
        par[p2] = p1;
        size[p1] += size[p2];
    }
}

int find(int i)
{
    if (par[i] == i)
    {
        return i;
    }

    par[i] = find(par[i]);

    return par[i];
}

vector<int> numIslands2(int n, int m, vector<Point> &operators)
{
    int len = operators.size();
    vector<vector<int>> grid(n, vector<int>(m, 0));
    int c = 0;
    vector<int> ans;
    par.resize(n * m);
    size.resize(n * m, 1);
    for (int i = 0; i < n * m; i++)
    {
        par[i] = i;
    }

    for (int i = 0; i < len; i++)
    {

        Point p = operators[i];
        int x = p.x;
        int y = p.y;
        if (grid[x][y])
        {
            continue;
        }
        grid[x][y] = 1;
        c++;
        int p1 = find((x * m) + y);
        // int lc = 0;
        for (auto &vec : dir)
        {
            int r = x + vec[0];
            int c = y + vec[1];

            if (r >= 0 and c >= 0 and r < n and c < m and grid[r][c] == 1)
            {
                int p2 = find((r * m) + c);

                if(p1!=p2)
                {
                    c--;
                    par[p2] = p1;
                }
            }
        }

        ans.push_back(c);
    }
    return ans;
}

int main()
{

    int n = 4, m = 5;

    vector<vector<int>> A = {{1, 1}, {0, 1}, {3, 3}, {3, 4}};
    

    return 0;
}