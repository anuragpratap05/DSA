#include<bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    vector<bool> vis(1001, false);
    for(int e:nums1)
    {
        vis[e] = true;
    }
    vector<int> ans;
    for (int e : nums2)
    {
        if(vis[e])
        {
            ans.push_back(e);
            vis[e] = false;
        }
    }
    return ans;
}

int main()
{
    return 0;
}