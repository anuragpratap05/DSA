#include<bits/stdc++.h>
using namespace std;



int help(vector<int>& nums,int tar)
{
    map<int, int> m;
    int cnt = 0;

    int sum = 0;

    m[0] = 1;
    for(int ele:nums)
    {
        sum += ele;
        if(m.find(sum-tar)!=m.end())
        {
            cnt += m[sum - tar];
        }
        m[sum]++;
    }
    return cnt;
}

int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
{
    int R = matrix.size();
    int C = matrix[0].size();
    vector<int> vec;
    int cnt = 0;

    for (int i = 0; i < R; i++)
    {
        vec.clear();
        vec.resize(C, 0);
        for (int r = i; r < R; r++)
        {
            for (int j = 0; j < C; j++)
            {
                vec[j] += matrix[r][j];
            }
            cnt += help(vec,target);
        }
    }
    return cnt;
}

int main()
{
    return 0;
}