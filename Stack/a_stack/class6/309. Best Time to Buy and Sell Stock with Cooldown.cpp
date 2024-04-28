#include<bits/stdc++.h>
using namespace std;

// leetcode 188 is HW
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

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<int> buy(n);
    vector<int> sell(n);
    buy[0] = 0 - prices[0];
    sell[0] = 0;
    for (int i = 1; i < n; i++)
    {
        sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
        buy[i] = max(buy[i - 1], (i - 2 >= 0 ? sell[i - 2] : sell[i - 1]) - prices[i]);
    }
    return sell[n - 1];
}

int main()
{
    return 0;
}