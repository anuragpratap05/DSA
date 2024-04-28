#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<int> maxProByBuyWithCoolD(n);
    vector<int> maxProBySale(n);
    maxProByBuyWithCoolD[0] = 0 - prices[0];
    maxProBySale[0] = 0;
    if (n > 1)
    {
        maxProByBuyWithCoolD[1] = max(maxProByBuyWithCoolD[0], 0 - prices[1]);
        maxProBySale[1] = max(maxProBySale[0], maxProByBuyWithCoolD[0] + prices[1]);
    }

    for (int day = 2; day < n; day++)
    {
        int curDayPrice = prices[day];

        maxProByBuyWithCoolD[day] = max(maxProByBuyWithCoolD[day - 1], maxProBySale[day - 2] - curDayPrice);
        maxProBySale[day] = max(maxProBySale[day - 1], maxProByBuyWithCoolD[day - 1] + curDayPrice);
    }
    return maxProBySale[n - 1];
}

int main()
{
    return 0;
}