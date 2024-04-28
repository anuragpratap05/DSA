#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}, {0, 0}};

long long getCountMemo(int n, int m, int i, int j, int k, vector<vector<vector<long long>>> &dp)
{
    if (k == 1)
        return dp[i][j][k] = 1;
    if (dp[i][j][k] != -1)
        return dp[i][j][k];
    long long cnt = 0;
    for (vector<int> &vec : dir)
    {
        int r = i + vec[0];
        int c = j + vec[1];

        if ((r == 3 and c == 0) or (r == 3 and c == 2))
            continue;

        if (r >= 0 and c >= 0 and r < n and c < m)
            cnt += getCountMemo(n, m, r, c, k - 1, dp);
    }
    return dp[i][j][k] = cnt;
}

long long getCount(int N)
{
    int n = 4, m = 3, k = N;
    long long totalNumbers = 0;

    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(k + 1, -1)));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i == 3 and j == 0) or (i == 3 and j == 2))
                continue;
            totalNumbers += getCountMemo(n, m, i, j, k, dp);
            // cout << "(" << i << "," << j << ") -->" << numbers << endl;
        }
    }
    return totalNumbers;
}

int main()
{
    int N = 3;
    int totalNumbers = getCount(N);
    cout << "TotalNumbers = " << totalNumbers << endl;
    return 0;
}