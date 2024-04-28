#include <bits/stdc++.h>
using namespace std;

int changeHelp(int amount, vector<int> &coins, int idx)
{
    if (amount == 0)
    {
        return 1;
    }
    int cnt = 0;
    for (int i = idx; i < coins.size(); i++)
    {
        int ele = coins[i];
        if (amount - ele >= 0)
        {
            cnt += changeHelp(amount - ele, coins, i);
        }
    }
    return cnt;
}

int change(int amount, vector<int> &coins)
{
    return changeHelp(amount, coins, 0);
}

int main()
{
    vector<int> coins = {2, 3, 5, 7};
    change(10, coins);
    return 0;
}