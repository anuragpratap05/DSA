#include <bits/stdc++.h>
using namespace std;

bool canShipInGivenDays(vector<int> &weights, int days, int probableWt)
{
    int n = weights.size();
    int i = 0;
    int myDays = 0;
    while (i < n)
    {
        int ele;
        int curWt = 0;
        while (i < n and curWt <= probableWt)
        {
            ele = weights[i];
            curWt += ele;
            i++;
        }
        if (curWt > probableWt)
            i--;
        myDays++;
        if (myDays > days)
            return false;
    }

    return true;
}

int shipWithinDays(vector<int> &weights, int days)
{
    int s = 1;
    int maxSum = 0;
    for (int e : weights)
    {
        maxSum += e;
    }
    int e = maxSum;

    while (s < e)
    {
        int probableMinWt = (s + e) / 2;
        if (canShipInGivenDays(weights, probableMinWt, days))
        {
            e = probableMinWt;
        }
        else
        {
            s = probableMinWt + 1;
        }
    }
    return s;
}

int main()
{
    vector<int> wts = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;
    int probableWt = 14;

    bool canShip = canShipInGivenDays(wts, days, probableWt);
    if (canShip)
    {
        cout << "canShip";
    }
    else
    {
        cout << "can not ship";
    }

    return 0;
}