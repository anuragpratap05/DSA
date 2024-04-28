#include <bits/stdc++.h>
using namespace std;

void display(vector<int> &sa)
{
    for (int ele : sa)
    {
        cout << ele << " ";
    }
    cout << endl;
}

void help(vector<int> &nums, int idx, vector<vector<int>> &ans, vector<int> &sa, vector<bool> &vis)
{
    if (idx == nums.size())
    {
        ans.push_back(sa);
        //display(sa);

        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (vis[i])
        {
            continue;
        }
        vis[i] = true;
        sa.push_back(nums[i]);
        help(nums, idx + 1, ans, sa, vis);
        sa.pop_back();
        vis[i] = false;
    }
    return;
}

vector<vector<int>> permute(vector<int> &nums)
{
    
    
    vector<int> sa;
    vector<bool> vis(nums.size(), false);
    vector<vector<int>> ans;
    help(nums, 0, ans, sa, vis);
    return ans;
}

int main()
{
    vector<int> vec = {1, 2, 3};
    vector<int>sa;
    vector<bool>vis(3,false);
    vector<vector<int>> ans;
    help(vec,0,ans,sa,vis);
    return 0;
}