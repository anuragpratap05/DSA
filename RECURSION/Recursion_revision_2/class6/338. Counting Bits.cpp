#include <bits/stdc++.h>
using namespace std;

vector<int> countBits(int n)
{
    if (n == 0 or n == 1)
    {
        if (n == 0)
        {
            return {0};
        }
        return {0, 1};
    }
    vector<int> vec(n + 1);
    vec[0] = 0;
    vec[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int prev = (i & (i - 1));
        vec[i] = vec[prev] + 1;
    }
    return vec;
}

int main()
{
    return 0;
}