#include<bits/stdc++.h>
using namespace std;

int hammingWeight_btr(uint32_t n)
{
    int c = 0;
    while (n != 0)
    {
        c++;
        n = (n & (n - 1));
    }
    return c;
}
vector<int> countBits(int n)
{
    vector<int> ans(n + 1, 0);
    // ans[1]=1;
    for (int i = 0; i <= n; i++)
    {
        ans[i] = hammingWeight_btr(i);
    }
    return ans;
}

vector<int> countBits_btr(int n)
{
    vector<int> ans(n + 1, 0);
    // ans[1]=1;
    for (int i = 1; i <= n; i++)
    {
        ans[i] = ans[(i & (i - 1))] + 1;
    }
    return ans;
}

int main()
{
    return 0;
}