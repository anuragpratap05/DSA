#include <bits/stdc++.h>
using namespace std;

vector<int> countBits(int n)
{
    vector<int> ans(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int oneLessBit = (i & (i - 1));
        ans[i] = ans[oneLessBit] + 1;
    }
    return ans;
}

int main()
{
    return 0;
}