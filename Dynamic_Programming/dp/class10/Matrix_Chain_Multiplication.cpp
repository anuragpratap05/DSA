#include <bits/stdc++.h>
using namespace std;

int mcmTabu(int N, int arr[], int SI, int EI)
{
    vector<vector<int>> dp(N, vector<int>(N));

    for (int gap = 0; gap < N; gap++)
    {
        for (int si = 0, ei = gap; ei < N; si++, ei++)
        {
            if (ei - si <= 1)
            {
                dp[si][ei] = 0;
                continue;
            }

            int minPro = 1e9;

            for (int cut = si + 1; cut < ei; cut++)
            {
                int left = dp[si][cut];
                int right = dp[cut][ei];

                minPro = min(minPro, left + (arr[si] * arr[cut] * arr[ei]) + right);
            }
            dp[si][ei] = minPro;
        }
    }
    return dp[SI][EI];
}

int matrixMultiplicationMemo(int N, int arr[], int si, int ei, vector<vector<int>> &dp)
{
    if (ei - si == 1)
        return dp[si][ei] = 0;
    if (dp[si][ei] != -1)
        return dp[si][ei];

    int minPro = 1e9;

    for (int cut = si + 1; cut < ei; cut++)
    {
        int left = matrixMultiplicationMemo(N, arr, si, cut, dp);
        int right = matrixMultiplicationMemo(N, arr, cut, ei, dp);

        minPro = min(minPro, left + (arr[si] * arr[cut] * arr[ei]) + right);
    }
    return dp[si][ei] = minPro;
}

int matrixMultiplication(int N, int arr[])
{
    // vector<vector<int>> dp(N, vector<int>(N, -1));
    return matrixMultiplicationMemo(N, arr, 0, N - 1, dp);
}

int main()
{
    int N = 5;
    int arr[5] = {40, 20, 30, 10, 30};
    int ans = matrixMultiplication(N, arr);
    cout << "ans--> " << ans << endl;

    return 0;
}