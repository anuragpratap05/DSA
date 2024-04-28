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

    vector<int> bestBuy1(n);
    vector<int> bestSell1(n);
    vector<int> bestBuy2(n);
    vector<int> bestSell2(n);

    bestBuy1[0] = -prices[0];
    bestSell1[0] = 0;

    bestBuy2[0] = bestBuy1[0];
    bestSell2[0] = bestSell1[0];

    for (int day = 1; day < n; day++)
    {
        int curDayPrice = prices[day];
        bestBuy1[day] = max(bestBuy1[day - 1], -curDayPrice);
        bestSell1[day] = max(bestSell1[day - 1], bestBuy1[day - 1] + curDayPrice);
        bestBuy2[day] = max(bestBuy2[day - 1], bestSell1[day - 1] - curDayPrice);
        bestSell2[day] = max(bestSell2[day - 1], bestBuy2[day - 1] + curDayPrice);
    }
    return bestSell2[n - 1];
}

int main()
{
    return 0;
}