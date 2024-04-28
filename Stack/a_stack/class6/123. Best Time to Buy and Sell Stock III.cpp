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
    vector<int>buy1(n);
    vector<int>sell1(n);
    vector<int>buy2(n);
    vector<int>sell2(n);
    buy1[0]=0-prices[0];
    sell1[0]=0;
    buy2[0]=buy1[0];
    sell2[0]=sell1[0];
    for(int i=1;i<n;i++)
    {
        buy1[i]=max(buy1[i-1],0-prices[i]);
        sell1[i] = max(sell1[i - 1], buy1[i - 1] + prices[i]);

        buy2[i]=max(buy2[i-1],sell1[i-1]-prices[i]);
        sell2[i]=max(sell2[i-1],buy2[i-1]+prices[i]);

        

    }
    return sell2[n-1];
}
//O(1) Space
int maxProfit2(vector<int> &prices)
{
    int n = prices.size();
    // vector<int>buy1(n);
    // vector<int>sell1(n);
    // vector<int>buy2(n);
    // vector<int>sell2(n);
    int buy1_p = 0 - prices[0];
    int sell1_p = 0;
    int buy2_p = buy1_p;
    int sell2_p = sell1_p;
    for (int i = 1; i < n; i++)
    {
        int buy1 = max(buy1_p, 0 - prices[i]);
        int sell1 = max(sell1_p, buy1_p + prices[i]);

        int buy2 = max(buy2_p, sell1_p - prices[i]);
        int sell2 = max(sell2_p, buy2_p + prices[i]);

        buy1_p = buy1;
        sell1_p = sell1;
        buy2_p = buy2;
        sell2_p = sell2;
    }
    return sell2_p;
}
int main()
{
    return 0;
}