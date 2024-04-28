#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dir = {{0, 1}, {1, 0}};

int FindWaysHelper(int sr, int sc, int n, int m, vector<vector<int>> &dp)
{
	if (sr == n - 1 and sc == m - 1)
	{
		dp[sr][sc] = 1;
		return 1;
	}
	if (dp[sr][sc] != -1)
	{
		return dp[sr][sc];
	}
	int cnt = 0;
	for (vector<int> &vec : dir)
	{
		int r = sr + vec[0];
		int c = sc + vec[1];
		if (r >= 0 and c >= 0 and r < n and c < m and dp[r][c] != -2)
		{
			cnt += FindWaysHelper(r, c, n, m, dp);
			cnt %= 1000000007;
		}
	}
	dp[sr][sc] = cnt;
	return cnt;
}

int FindWays(int n, int m, vector<vector<int>> blocked_cells)
{

	vector<vector<int>> dp(n, vector<int>(m, -1));
	for (vector<int> &vec : blocked_cells)
	{
		int x = vec[0];
		int y = vec[1];

		dp[x - 1][y - 1] = -2;
	}
	if (dp[0][0] == -2 or dp[n - 1][m - 1] == -2)
	{
		return 0;
	}
	return FindWaysHelper(0, 0, n, m, dp);
}

int main()
{
	return 0;
}