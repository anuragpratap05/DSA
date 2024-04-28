#include <bits/stdc++.h>
using namespace std;

bool canFinishEating(vector<int> &piles, int h, int eatingSpeed)
{
    int hoursTaken = 0;
    for (int ele : piles)
    {
        int wholeHrs = ele / eatingSpeed;
        int fractnHrs = ele % eatingSpeed;
        wholeHrs += fractnHrs > 0 ? 1 : 0;
        hoursTaken += wholeHrs;
        if (hoursTaken > h)
            return false;
    }
    return true;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    int maxEle = 0;
    for (int ele : piles)
    {
        maxEle = max(maxEle, ele);
    }
    int s = 1, e = maxEle;
    while (s < e)
    {
        int eatingSpeed = (s + e) / 2;
        if (canFinishEating(piles, h, eatingSpeed))
        {
            e = eatingSpeed;
        }
        else
        {
            s = eatingSpeed + 1;
        }
    }
    return s;
}

int main()
{
    return 0;
}