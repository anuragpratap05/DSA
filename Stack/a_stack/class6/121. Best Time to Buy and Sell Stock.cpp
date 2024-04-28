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
    int n=prices.size();
    vector<int>sell(n);
    vector<int>buy(n);
    sell[0]=0;
    buy[0]=(0-prices[0]);
    for(int i=1;i<n;i++)
    {
        sell[i]=max(sell[i-1],buy[i-1]+prices[i]);
        buy[i]=max(buy[i-1],0-prices[i]);

    }
    return sell[n-1];
}
// O(1) Space
int maxProfit2(vector<int> &prices)
{
    int n = prices.size();
    int p_sell = 0;
    int mini = 0 - prices[0];
    // sell[0]=0;
    // buy[0]=(0-prices[0]);
    for (int i = 1; i < n; i++)
    {
        int sell = max(p_sell, mini + prices[i]);

        mini = max(mini, 0 - prices[i]);
        p_sell = sell;
    }
    return p_sell;
}
int main()
{
    return 0;
}