#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &height)
{
    int si = 0;
    int ei = height.size() - 1;
    int ans = 0;
    while (si < ei)
    {
        int b = ei - si;
        int ht = min(height[si], height[ei]);
        ans = max(ans, b*ht);
        if (height[si] < height[ei])
        {
            si++;
        }
        else
        {
            ei--;
        }
    }
    return ans;
}

int main()
{
    return 0;
}