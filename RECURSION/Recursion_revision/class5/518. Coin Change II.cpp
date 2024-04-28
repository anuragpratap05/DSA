#include <bits/stdc++.h>
using namespace std;

int changeHelper(int amount, vector<int> &coins, int idx)
{
    if (amount == 0)
    {
        return 1;
    }
    int cnt = 0;
    for (int i = idx; i < coins.size(); i++)
    {
        int ele = coins[i];
        int smallAmount = amount - ele;
        if (smallAmount >= 0)
        {
            cnt += changeHelper(smallAmount, coins, i);
        }
    }
    return cnt;
}

int change(int amount, vector<int> &coins)
{
    return changeHelper(amount, coins, 0);
}

int main()
{
    return 0;
}