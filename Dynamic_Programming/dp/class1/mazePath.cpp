#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode(int val)
    {
        this->val = val;
    }
};

vector<vector<int>> dirs = {{0, 1}, {1, 1}, {1, 0}};
vector<string> myDir = {"Right", "Dia", "Down"};

void display(vector<vector<int>> &dp)
{
    for (auto &vec : dp)
    {
        for (int ele : vec)
        {
            cout << ele << " , ";
        }
        cout << endl;
    }
    cout << endl;
}

void displaymatrix(vector<vector<bool>> &matrix)
{
}

int mazePaths(vector<vector<int>> &mat, int sr, int sc, int er, int ec, vector<vector<int>> &dp, string psf)
{
    if (sr == er and sc == ec)
    {
        cout << psf << endl;
        return dp[er][ec] = 1;
    }

    // if (dp[sr][sc] != -1)
    //     return dp[sr][sc];

    int n = mat.size(), m = mat[0].size();
    int ways = 0;

    for (int i = 0; i < dirs.size(); i++)
    {
        vector<int> &vec = dirs[i];
        int r = sr + vec[0];
        int c = sc + vec[1];
        if (r >= 0 and c >= 0 and r < n and c < m)
        {
            ways += mazePaths(mat, r, c, er, ec, dp, psf + myDir[i] + " ");
        }
    }
    return dp[sr][sc] = ways;
}

void mazePathsTabu(vector<vector<int>> &mat, int er, int ec, vector<vector<int>> &dp)
{

    for (int sr = er; sr >= 0; sr--)
    {
        for (int sc = ec; sc >= 0; sc--)
        {
            if (sr == er and sc == ec)
            {
                dp[sr][sc] = 1;
                continue;
            }

            int n = mat.size(), m = mat[0].size();
            int ways = 0;

            for (vector<int> &vec : dirs)
            {
                int r = sr + vec[0];
                int c = sc + vec[1];
                if (r >= 0 and c >= 0 and r < n and c < m)
                {
                    ways += dp[r][c];
                }
            }
            dp[sr][sc] = ways;
        }
    }
}

int mazePathWithJumps(vector<vector<int>> &mat, int sr, int sc, int er, int ec, vector<vector<int>> &dp)
{
    if (sr == er and sc == ec)
        return dp[er][ec] = 1;

    if (dp[sr][sc] != -1)
        return dp[sr][sc];

    int n = mat.size(), m = mat[0].size();
    int ways = 0;

    for (vector<int> &vec : dirs)
    {
        for (int jump = 1; jump <= max(er, ec); jump++)
        {
            int r = sr + jump * vec[0];
            int c = sc + jump * vec[1];
            if (r >= 0 and c >= 0 and r < n and c < m)
            {
                ways += mazePathWithJumps(mat, r, c, er, ec, dp);
            }
            else
                break;
        }
    }
    return dp[sr][sc] = ways;
}

int main()
{
    int n = 4, m = 4;
    vector<vector<int>> mat(n, vector<int>(m));
    vector<vector<int>> dp(n, vector<int>(m, -1));

    // mazePathsTabu(mat, n - 1, m - 1, dp);
    int paths = mazePaths(mat, 0, 0, n - 1, m - 1, dp, "");
    // cout << "paths--> " << paths << endl;

    // jumps

    // mazePathWithJumps(mat, 0, 0, n - 1, m - 1, dp);
    // display(dp);
    return 0;
}