#include<bits/stdc++.h>
using namespace std;



//my method
int kthSmallest(vector<vector<int>> &matrix, int k)
{
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    int ans;
    int n = matrix.size();
    int m = matrix[0].size();
    pq.push({matrix[0][0], 0, 0});
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    while (k--)
    {
        vector<int> vec = pq.top();
        pq.pop();
        ans = vec[0];
        int i = vec[1];
        int j = vec[2];

        int tempi;
        int tempj;
        tempj = j + 1;
        if(tempj<m and !vis[i][tempj])
        {
            vis[i][tempj] = true;
            pq.push({matrix[i][tempj], i, tempj});
        }
        tempi = i + 1;
        if (tempi < n and !vis[tempi][j])
        {
            vis[tempi][j] = false;
            pq.push({matrix[tempi][j], tempi, j});
        }
    }
    return ans;
}

//btr
// sir method
int kthSmallest2(vector<vector<int>> &matrix, int k)
{
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    int ans;
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n;i++)
    {
        pq.push({matrix[i][0], i, 0});
    }

    while(k--)
    {
        vector<int> vec = pq.top();
        pq.pop();
        ans = vec[0];
        int i = vec[1];
        int j = vec[2];

        if(j+1<m)
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