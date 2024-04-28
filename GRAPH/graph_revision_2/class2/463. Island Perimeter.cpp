#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dir = { {0, 1}, {1, 0}};

int islandPerimeter(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    int links = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j< m; j++)
        {
            if(grid[i][j]==1)
            {
                for(auto& vec:dir)
                {
                    int r = i + vec[0];
                    int c = j + vec[1];
                    if(r<n and c<m and grid[r][c]==1)
                    {
                        links++;
                    }
                }
            }
        }
    }
    int ans = (links * 4) - 2 * links;
    return ans;
}

int main()
{
    return 0;
}