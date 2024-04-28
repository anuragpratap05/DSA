#include <bits/stdc++.h>
using namespace std;
// return type se nhi hua

// ho gya bhaiwa

// void prepare(int ele, vector<vector<int>> &myans, vector<int> &vec)
// {
//     vector<int> v;
//     v.push_back(ele);
//     for (int e : vec)
//     {
//         v.push_back(e);
//     }
//     myans.push_back(v);
// }

// vector<vector<int>> combinationSum_help(vector<int> &candidates, int target, int idx)
// {
//     if (target <= 0)
//     {
//         if (target == 0)
//         {
//             return {{}};
//         }
//         return {};
//     }
//     vector<vector<int>> myans;
//     for (int i = idx; i < candidates.size(); i++)
//     {
//         vector<vector<int>> sa = combinationSum_help(candidates, target - candidates[i], i);
//         for (auto &vec : sa)
//         {
//             prepare(candidates[i], myans, vec);
//         }
//     }
//     return myans;
// }

// vector<vector<int>> combinationSum(vector<int> &candidates, int target)
// {

//     return combinationSum_help(candidates, target, 0);
// }

int combinationSum_help(vector<int> &candidates, int target, int sum, int idx, vector<vector<int>> &ans, vector<int> &sa)
{
    if (sum >= target)
    {
        if (sum == target)
        {
            ans.push_back(sa);
            return 1;
        }
        return 0;
    }
    int count = 0;
    for (int i = idx; i < candidates.size(); i++)
    {
        sa.push_back(candidates[i]);
        count += combinationSum_help(candidates, target, sum + candidates[i], i, ans, sa);
        sa.pop_back();
    }
    return count;
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> vec;
    combinationSum_help(candidates, target, 0, 0, ans, vec);
    return ans;
}
int main()
{
    vector<int> vec = {2, 3, 5, 7};

    vector<vector<int>> ans = combinationSum(vec, 10);
    for (auto &vec : ans)
    {
        for (int ele : vec)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}