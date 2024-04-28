#include<bits/stdc++.h>
using namespace std;


class TreeNode
{
    public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode(int val)
    {
    this->val = val;
    }
};

vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    map<int, int> m;
    for (int e : nums1)
    {
        m[e]++;
    }
    vector<int> ans;
    for (int e : nums2)
    {
        if (m.find(e) != m.end() )
        {
            ans.push_back(e);
            m[e]--;
            if(m[e]==0)
            {
                m.erase(e);
            }
        }
    }
    return ans;
}

int main()
{
    return 0;
}