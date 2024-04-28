#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dis = {{-1, 1}, {0, 1}, {1, 1}};

int maxGoldHelper(int n, int m, vector<vector<int>> M, int i, int j)
{
    if (j == M[0].size() - 1)
    {
        return M[i][j];
    }
    int myAns = 0;
    for (vector<int> &vec : dis)
    {
        int r = i + vec[0];
        int c = j + vec[1];
        if (r >= 0 and c >= 0 and r < n and c < m)
        {
            int recAns = maxGoldHelper(n, m, M, r, c);
            if (recAns + M[i][j] > myAns)
            {
                myAns = recAns + M[i][j];
            }
        }
    }
    return myAns;
}

int maxGold(int n, int m, vector<vector<int>> M)
{
    int finalAns = 0;
    for (int row = 0; row < n; row++)
    {
        finalAns = max(finalAns, maxGoldHelper(n, m, M, row, 0));
    }
    return finalAns;
    // return maxGoldHelper(n, m, M, 0, 0);
}

int main()
{
    return 0;
}