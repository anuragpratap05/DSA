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
    vector<int> bestBuySf(n);
    vector<int> bestSellSf(n);
    bestBuySf[0] = -prices[0];
    bestSellSf[0] = 0;

    for (int day = 1; day < n; day++)
    {
        int curDayPrice = prices[day];
        bestBuySf[day] = max(bestBuySf[day - 1], -curDayPrice);
        bestSellSf[day] = max(bestSellSf[day - 1], bestBuySf[day - 1] + curDayPrice);
    }
    return bestSellSf[n - 1];
}

int main()
{
    return 0;
}