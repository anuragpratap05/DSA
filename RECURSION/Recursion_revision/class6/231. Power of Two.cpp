#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n)
{
    long x = n;
    if (x == 0 or (x & (x - 1)) != 0)
        return false;
    return true;
}

int main()
{
    return 0;
}