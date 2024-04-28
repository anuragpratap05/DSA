#include <bits/stdc++.h>
using namespace std;

int maxProfit2(vector<int> &prices)
{
    int n = prices.size();
    vector<int> buy1MaxPro(n);
    vector<int> sell1MaxPro(n);
    vector<int> buy2MaxPro(n);
    vector<int> sell2MaxPro(n);

    buy1MaxPro[0] = 0 - prices[0];
    sell1MaxPro[0] = 0;
    buy2MaxPro[0] = buy1MaxPro[0];
    sell2MaxPro[0] = sell1MaxPro[0];

    for (int day = 1; day < n; day++)
    {
        int curDayPrice = prices[day];
        buy1MaxPro[day] = max(buy1MaxPro[day - 1], 0 - curDayPrice);
        sell1MaxPro[day] = max(sell1MaxPro[day - 1], buy1MaxPro[day - 1] + curDayPrice);

        buy2MaxPro[day] = max(buy2MaxPro[day - 1], sell1MaxPro[day - 1] - curDayPrice);
        sell2MaxPro[day] = max(sell2MaxPro[day - 1], buy2MaxPro[day - 1] + curDayPrice);
    }
    return sell2MaxPro[n - 1];
}


// spcae optimization
int maxProfit(vector<int> &prices)
{
    int n = prices.size();

    int maxProByBuy1AtPrevDay = 0 - prices[0];
    int maxProBySale1AtPrevDay = 0;
    int maxProByBuy2AtPrevDay = maxProByBuy1AtPrevDay;
    int maxProBySale2AtPrevDay = maxProBySale1AtPrevDay;

    for (int day = 1; day < n; day++)
    {
        int curDayPrice = prices[day];
        int maxProByBuy1AtCurDay = max(maxProByBuy1AtPrevDay, 0 - curDayPrice);
        int maxProBySale1AtCurDay = max(maxProBySale1AtPrevDay, maxProByBuy1AtPrevDay + curDayPrice);

        int maxProByBuy2AtCurDay = max(maxProByBuy2AtPrevDay, maxProBySale1AtPrevDay - curDayPrice);
        int maxProBySale2AtCurDay = max(maxProBySale2AtPrevDay, maxProByBuy2AtPrevDay + curDayPrice);

        maxProByBuy1AtPrevDay = maxProByBuy1AtCurDay;
        maxProBySale1AtPrevDay = maxProBySale1AtCurDay;
        maxProByBuy2AtPrevDay = maxProByBuy2AtCurDay;
        maxProBySale2AtPrevDay = maxProBySale2AtCurDay;
    }
    return maxProBySale2AtPrevDay;
}

int main()
{
    return 0;
}