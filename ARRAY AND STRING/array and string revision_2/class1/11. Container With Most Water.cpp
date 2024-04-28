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

int maxArea(vector<int> &height)
{
    int s = 0;
    int e = height.size() - 1;
    int maxi = 0;
    while (s < e)
    {
        int b = (e - s);
        int l = min(height[s], height[e]);

        maxi = max(maxi, l * b);
        if(height[s]<height[e])
        {
            s++;
        }
        else
        {
            e--;
        }
    }
    return maxi;
}

int main()
{
    return 0;
}