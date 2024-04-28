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

int maxProfit(vector<int> &prices)
{
    int buy1 = -(prices[0]);
    int sell1 = 0;

    int buy2 = -(prices[0]);
    int sell2 = 0;
    int n = prices.size();
    for (int i = 1; i < n; i++)
    {
        buy1 = max(buy1, 0 - prices[i]);
        sell2 = max(sell2, buy2 + prices[i]);
        buy2 = max(buy2, sell1 - prices[i]);
        sell1 = max(sell1, buy1 + prices[i]);
        
    }
    return sell2;
}

int main()
{
    return 0;
}