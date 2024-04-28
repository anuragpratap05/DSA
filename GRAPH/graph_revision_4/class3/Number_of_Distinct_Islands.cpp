#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<string> names = {"u", "r", "d", "l"};

string dfs(vector<vector<int>> &grid, int i, int j)
{
    int n = grid.size();
    int m = grid[0].size();
    grid[i][j] = 0;
    string str = "";
    for (int d = 0; d < dirs.size(); d++)
    {
        vector<int> &vec = dirs[d];
        int r = i + vec[0];
        int c = j + vec[1];
        if (r >= 0 and c >= 0 and r < n and c < m and grid[r][c] == 1)
        {
            str += names[d];
            string recAns = dfs(grid, r, c);
            str += recAns;
        }
    }
    str += "b";
    return str;
}

int countDistinctIslands(vector<vector<int>> &grid)
{
    unordered_set<string> st;
    int n = grid.size();
    int m = grid[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                string str = dfs(grid, i, j);
                st.insert(str);
            }
        }
    }
    return st.size();
}

int main()
{
    vector<vector<int>> grid(4, vector<int>(4, 0));
    grid[0][2] = 1;
    grid[1][1] = 1;
    grid[1][2] = 1;
    grid[2][2] = 1;
    grid[3][2] = 1;
    grid[2][3] = 1;
    cout << dfs(grid, 1, 1);

    return 0;
}