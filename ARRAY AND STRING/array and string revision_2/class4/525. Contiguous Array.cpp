#include <bits/stdc++.h>
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

int findMaxLength(vector<int> &nums)
{
    int n = nums.size();
    vector<int> freq(n + 1, -2);
    freq[0] = -1;
    int k = n + 1;
    int sum = 0;
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        int ele = nums[i];
        if (ele == 0)
        {
            ele = -1;
        }
        sum += ele;

        // sum=(sum+k)%k;

        int rem = sum;
        if (rem < 0)
        {
            rem = (rem + k) % k;
        }

        //  cout<<rem<<endl;
        if (freq[rem] == -2)
        {
            freq[rem] = i;
        }
        else
        {
            len = max(len, i - freq[rem]);
        }
    }
    return len;
}

int main()
{
    return 0;
}