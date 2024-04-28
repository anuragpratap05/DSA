#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<int>> &vec)
{
    for (vector<int> &v : vec)
    {
        for (int e : v)
            cout << e << " ";
        cout << endl;
    }
}

vector<vector<int>> dir = {{-1, 1}, {0, 1}, {1, 1}};

void backEngine(vector<vector<int>> &dp, int sr, int sc)
{
    if (sc == dp[0].size() - 1)
    {
        cout << "(" << sr << " , " << sc << ")";
        return;
    }
    cout << "(" << sr << " , " << sc << ") --> ";

    int gold = 0;
    int maxR, maxC;
    for (vector<int> &vec : dir)
    {
        int r = sr + vec[0];
        int c = sc + vec[1];
        if (r >= 0 and c >= 0 and r < dp.size() and c < dp[0].size() and dp[r][c] > gold)
        {
            gold = dp[r][c];
            maxR = r;
            maxC = c;
        }
    }
    backEngine(dp, maxR, maxC);

    // int maxGold = 0;
    // for (int i = 0; i < dp.size(); i++)
    // {
    //     if (dp[i][0] > maxGold)
    //     {
    //         maxGold = dp[i][0];
    //         sr = i;
    //         sc = 0;
    //     }
    // }
}

int maxGoldMemo(vector<vector<int>> &M, int sr, int sc, int er, int ec, vector<vector<int>> &dp)
{
    if (sc == ec)
        return dp[sr][sc] = M[sr][sc];
    if (dp[sr][sc] != -1)
        return dp[sr][sc];
    int maxGold = 0;
    for (vector<int> &vec : dir)
    {
        int r = sr + vec[0];
        int c = sc + vec[1];
        if (r >= 0 and c >= 0 and r <= er and c <= ec)
        {
            int recGold = maxGoldMemo(M, r, c, er, ec, dp);
            if (recGold + M[sr][sc] > maxGold)
                maxGold = recGold + M[sr][sc];
        }
    }
    return dp[sr][sc] = maxGold;
}

void maxGoldTabu(vector<vector<int>> &M, int er, int ec, vector<vector<int>> &dp)
{

    for (int sc = ec; sc >= 0; sc--)
    {
        for (int sr = er; sr >= 0; sr--)
        {
            if (sc == ec)
            {
                dp[sr][sc] = M[sr][sc];
                continue;
            }

            int maxGold = 0;
            for (vector<int> &vec : dir)
            {
                int r = sr + vec[0];
                int c = sc + vec[1];
                if (r >= 0 and c >= 0 and r <= er and c <= ec)
                {
                    int recGold = dp[r][c];
                    if (recGold + M[sr][sc] > maxGold)
                        maxGold = recGold + M[sr][sc];
                }
            }
            dp[sr][sc] = maxGold;
        }
    }
}

int maxGold(int n, int m, vector<vector<int>> &M)
{
    int ans = 0;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    maxGoldTabu(M, n - 1, m - 1, dp);
    display(dp);
    int maxR, maxC;
    for (int i = 0; i < n; i++)
    {
        if (dp[i][0] > ans)
        {
            ans = dp[i][0];
            maxR = i;
            maxC = 0;
        }
        // ans = max(ans, dp[i][0]);
    }
    backEngine(dp, maxR, maxC);

    return ans;
}

int main()
{
    vector<vector<int>> M = {{8, 3, 2, 8, 5}, {2, 8, 3, 6, 5}, {1, 7, 5, 9, 4}, {6, 9, 8, 6, 3}};
    int ans = maxGold(4, 5, M);
    cout << "ans--> " << ans << endl;
    return 0;
}