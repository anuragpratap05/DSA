#include <bits/stdc++.h>
using namespace std;

bool camShipGivenWt(vector<int> &weights, int days, int maxWtEachDay)
{
    int n = weights.size();

    int chunkWt = 0;

    for (int i = 0; i < n; i++)
    {
        if (days <= 0)
        {
            return false;
        }
        int curWt = weights[i];
        chunkWt += curWt;
        if (chunkWt > maxWtEachDay)
        {
            days--;
            chunkWt = 0;
            i--;
        }
    }
    return true;
}

int shipWithinDays(vector<int> &weights, int days)
{
    int s = 1;
    int arrSum = 0;

    for (int wt : weights)
        arrSum += wt;
    int e = arrSum;

    while (s < e)
    {
        int pw = (s + e) / 2;
        if (camShipGivenWt(weights, days, pw))
            e = pw;
        else
            s = pw + 1;
    }
    return s;
}

int main()
{
    // vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> weights = {5, 5, 6};
    int days = 3;
    camShipGivenWt(weights, days, 12);
    return 0;
}