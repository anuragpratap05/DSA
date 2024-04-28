#include <bits/stdc++.h>
using namespace std;

int divideIntoKHelp(int n, int k, int N, int idx)
{
    if (n == 0 or k == 0)
    {
        if (n == 0 and k == 0)
            return 1;
        return 0;
    }
    int cnt = 0;
    for (int num = idx; num <= N; num++)
    {
        if (n - num >= 0)
        {
            cnt += divideIntoKHelp(n - num, k - 1, N, num);
        }
        else
            break;
    }
    return cnt;
}

int divideIntoK(int n, int k)
{
    return divideIntoKHelp(n, k, n, 1);
}

int main()
{
    int ways = divideIntoK(24, 5);
    cout << "Ways --> " << ways << endl;
    return 0;
}