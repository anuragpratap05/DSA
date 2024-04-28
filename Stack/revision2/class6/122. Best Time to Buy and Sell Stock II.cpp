#include <bits/stdc++.h>
using namespace std;

int maxProfit2(vector<int> &prices)
{
    int profit = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        int curDayPrice = prices[i];
        int prevDayPrice = prices[i - 1];
        if (prevDayPrice < curDayPrice)
            profit += curDayPrice - prevDayPrice;
    }
    return profit;
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<int> maxProByBuy(n);
    vector<int> maxProBysale(n);
    maxProByBuy[0] = -(prices[0]);
    maxProBysale[0] = 0;

    for (int day = 1; day < n; day++)
    {
        int curDayPrice = prices[day];
        maxProByBuy[day] = max(maxProByBuy[day - 1], maxProBysale[day - 1] - curDayPrice);

        maxProBysale[day] = max(maxProBysale[day - 1], maxProByBuy[day - 1] + curDayPrice);
    }
    return maxProBysale[n - 1];
}

int main()
{
    return 0;
}