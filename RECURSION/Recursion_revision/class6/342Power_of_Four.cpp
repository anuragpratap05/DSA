#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n)
{
    long x = n;
    if (x == 0 or (x & (x - 1)) != 0)
        return false;
    return true;
}

bool isPositionOdd(uint32_t n)
{
    int cnt = 0;
    while (n)
    {
        cnt++;
        n = (n >> 1);
    }
    if ((cnt & 1))
    {
        return true;
    }
    return false;
}

bool isPowerOfFour(int n)
{
    if (isPowerOfTwo(n) and isPositionOdd(n))
    {
        return true;
    }
    return false;
}

int main()
{
    if (isPositionOdd(64))
    {
        cout << "odd";
    }
    return 0;
}