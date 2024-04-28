#include<bits/stdc++.h>
using namespace std;

int kadans(vector<int> &arr)
{
    int n = arr.size();
    int csum = 0;
    int gsum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int ele = arr[i];
        csum = max(ele, csum + ele);
        gsum = max(csum, gsum);
    }
    return gsum;
}

int maximumSumRectangle(int R, int C, vector<vector<int>> M)
{
    vector<int> vec;
    int ans = 0;

    for (int i = 0; i < R;i++)
    {
        vec.clear();
        vec.resize(C, 0);
        for (int r = i; r < R; r++)
        {
            for (int j = 0; j < C; j++)
            {
                vec[j] += M[r][j];
            }
            ans = max(ans, kadans(vec));
        }
            
    }
    return ans;
}

int main()
{
    return 0;
}