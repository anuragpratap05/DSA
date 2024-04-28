#include<bits/stdc++.h>
using namespace std;
// TLE aa gya DP lgaw
bool solution(vector<int> &arr, int i, int n, int k, int rmsets,  vector<int> &sum)
{
    if (i == n)
    {
        if (rmsets == k)
        {
            int csum = sum[0];
            for (int i = 1; i < k; i++)
            {
                if (sum[i - 1] != sum[i])
                {
                    return false;
                }
            }

            return true;
        }

        return false;
    }
    for (int idx = 0; idx < k; idx++)
    {
        if (sum[idx] != 0)
        {
            //ans[idx].push_back(arr[i]);
            sum[idx] += arr[i];
            if(solution(arr, i + 1, n, k, rmsets,  sum))
            {
                return true;
            }
            sum[idx] -= arr[i];
            //ans[idx].pop_back();
        }
        else
        {
           // ans[idx].push_back(arr[i]);
            sum[idx] += arr[i];
            if(solution(arr, i + 1, n, k, rmsets + 1,  sum))
            {
                return true;
            }
            sum[idx] -= arr[i];
           // ans[idx].pop_back();
            break;
        }
    }
    return false;
}

bool canPartitionKSubsets(vector<int> &nums, int k)
{
   
    int n=nums.size();
    
    //vector<vector<int>> ans(k, vector<int>());
    vector<int> sum(k, 0);
    return solution(nums, 0, n, k, 0, sum);
}

int main()
{
    return 0;
}