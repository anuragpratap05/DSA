#include<bits/stdc++.h>
using namespace std;

void help(string nums, int idx, vector<string> &ans, string sa, vector<bool> &vis)
{
    if (idx == nums.size())
    {
        ans.push_back(sa);
        // display(sa);

        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (vis[i])
        {
            continue;
        }
        vis[i] = true;
        // sa.push_back(nums[i]);
        help(nums, idx + 1, ans, sa + nums[i], vis);
        // sa.pop_back();
        vis[i] = false;
    }
    return;
}

vector<string> find_permutation(string S)
{
    vector<string> ans;
    vector<bool> vis(S.size(), false);
    help(S, 0, ans, "", vis);
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    return 0;
}