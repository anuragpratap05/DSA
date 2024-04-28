#include <bits/stdc++.h>
using namespace std;

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

int numOfCalls = 0;
int mazePathMemo(vector<vector<int>> &mat, int i, int j, vector<vector<int>> &dp)
{
    int n = mat.size();
    int m = mat[0].size();
    numOfCalls++;
    if (i == mat.size() - 1 and j == mat[0].size() - 1)
        return dp[i][j] = 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    int ways = 0;
    for (vector<int> &vec : dirs)
    {
        int r = i + vec[0];
        int c = j + vec[1];
        if (r >= 0 and c >= 0 and r < n and c < m)
        {
            ways += mazePathMemo(mat, r, c, dp);
        }
    }
    return dp[i][j] = ways;
}

int main()
{
    int n = 4, m = 4;
    vector<vector<int>> mat(n, vector<int>(m));
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int ways = mazePathMemo(mat, 0, 0, dp);
    cout << "Ways-->" << ways << endl;
    cout << "numOfCalls-->" << numOfCalls << endl;
    display(dp);
    return 0;
}