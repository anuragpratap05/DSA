#include <bits/stdc++.h>
using namespace std;

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

int maxProfit(vector<int> &prices, int fee)
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

        maxProBysale[day] = max(maxProBysale[day - 1], (maxProByBuy[day - 1] + curDayPrice) - fee);
    }
    return maxProBysale[n - 1];
}

int main()
{
    return 0;
}