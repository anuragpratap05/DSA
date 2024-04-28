#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dir = {{0, 1}, {1, 0}};

int kthSmallest(vector<vector<int>> &matrix, int k)
{
    int n = matrix.size();
    int m = matrix[0].size();

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    // ele,idx
    pq.push({matrix[0][0], 0});
    int ele;

    while (k--)
    {
        vector<int> vec = pq.top();
        pq.pop();
        ele = vec[0];
        int idx = vec[1];
        int i = idx / m;
        int j = idx % m;
        for (vector<int> &dirs : dir)
        {
            int r = i + dirs[0];
            int c = j + dirs[1];
            if (r >= 0 and r < n and c >= 0 and c < m and matrix[r][c] != 1000000001)
            {

                pq.push({matrix[r][c], r * m + c});
                matrix[r][c] = 1000000001;
            }
        }
    }
    return ele;
}

// method 2
int kthSmallest2(vector<vector<int>> &matrix, int k)
{
    int n = matrix.size();
    int m = matrix[0].size();

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push({matrix[i][0], i, 0});
    }
    int ans;
    while (k--)
    {
        vector<int> vec = pq.top();
        pq.pop();
        ans = vec[0];
        int i = vec[1];
        int j = vec[2];
        if (j + 1 < m)
        {
            pq.push({matrix[i][j + 1], i, j + 1});
        }
    }
    return ans;
}

int main()
{
    return 0;
}