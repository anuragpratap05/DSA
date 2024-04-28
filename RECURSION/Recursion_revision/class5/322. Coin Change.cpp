#include <bits/stdc++.h>
using namespace std;

int coinChangeHelper(vector<int> &coins, int amount, int idx)
{
    if (amount == 0)
    {
        return 0;
    }

    int myAns = 1e7;
    for (int i = idx; i < coins.size(); i++)
    {
        int ele = coins[i];
        int smallAmt = amount - ele;
        if (smallAmt >= 0)
        {
            int recAns = coinChangeHelper(coins, smallAmt, i);
            if (recAns != 1e7 and recAns + 1 < myAns)
            {
                myAns = recAns + 1;
            }
        }
    }
    return myAns;
}

int coinChange(vector<int> &coins, int amount)
{
    int ans = coinChangeHelper(coins, amount, 0);
    if (ans == 1e7)
    {
        return -1;
    }
    return ans;
}

int main()
{
    return 0;
}