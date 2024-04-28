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

int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();
    int sell_profit = 0;
    int best_buy = -(prices[0]+fee);

    for (int i = 1; i < n; i++)
    {
        best_buy = max(best_buy, sell_profit - (prices[i]+fee));

        sell_profit = max(sell_profit, best_buy + prices[i]);
    }
    return sell_profit;
}

int main()
{
    return 0;
}