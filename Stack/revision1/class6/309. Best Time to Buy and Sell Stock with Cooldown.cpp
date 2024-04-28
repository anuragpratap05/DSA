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
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<int> sell_profit;
    vector<int> best_buy;
    sell_profit.push_back(0);
    best_buy.push_back(-(prices[0]));
    for (int i = 1; i < n; i++)
    {
        int buy = max(best_buy[i - 1], (i - 2 >= 0 ? sell_profit[i - 2] : 0) - prices[i]);
        best_buy.push_back(buy);
        int sell = max(sell_profit[i - 1], best_buy[i - 1] + prices[i]);
        sell_profit.push_back(sell);
    }
    return sell_profit[n - 1];
}
int main()
{
    return 0;
}