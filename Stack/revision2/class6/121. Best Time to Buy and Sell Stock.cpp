#include <bits/stdc++.h>
using namespace std;

int maxProfit2(vector<int> &prices)
{
    int n = prices.size();
    int maxOnRight;

    int maxProfit = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            maxOnRight = prices[i];
            continue;
        }
        if (prices[i] < maxOnRight)
        {
            maxProfit = max(maxProfit, maxOnRight - prices[i]);
        }
        else
            maxOnRight = prices[i];
    }
    return maxProfit;
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<int> bestBuySf(n);
    vector<int> bestSaleSf(n);
    bestBuySf[0] = -(prices[0]);
    bestSaleSf[0] = 0;

    for (int day = 1; day < n; day++)
    {
        int curDayPrice = prices[day];

        bestBuySf[day] = max(bestBuySf[day - 1], -(curDayPrice));
        bestSaleSf[day] = max(bestSaleSf[day - 1], bestBuySf[day - 1] + curDayPrice);
    }
    return bestSaleSf[n - 1];
}

int main()
{
    return 0;
}