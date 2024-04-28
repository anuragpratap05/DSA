#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &height)
{
    int si = 0, ei = height.size() - 1;

    int maxWater = 0;
    while (si < ei)
    {
        int b = ei - si;
        int h = min(height[si], height[ei]);
        maxWater = max(maxWater, b * h);
        if (height[si] < height[ei])
            si++;
        else
            ei--;
    }
    return maxWater;
}

int main()
{
    return 0;
}