#include <bits/stdc++.h>
using namespace std;

int coinChangeHelper(vector<int> &coins, int amount, int idx)
{
    if (amount == 0)
    {
        return 0;
    }

    int myAns = 1e8;

    for (int i = idx; i < coins.size(); i++)
    {
        int ele = coins[i];
        if (amount - ele >= 0)
        {
            int recAns = coinChangeHelper(coins, amount - ele, i);
            if (recAns != 1e8 and recAns + 1 < myAns)
            {
                myAns = recAns + 1;
            }
        }
    }
    return myAns;
}

int coinChange(vector<int> &coins, int amount)
{
    if (amount == 0)
    {
        return 0;
    }

    int ans = coinChangeHelper(coins, amount, 0);
    return (ans == 1e8 ? -1 : ans);
}


int main()
{
    return 0;
}