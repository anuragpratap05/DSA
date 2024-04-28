#include <bits/stdc++.h>
using namespace std;

void offOn(int num, int k)
{
    int mask = (1 << k);
    num |= mask;
}

void onOff(int num, int k)
{
    int mask = (~(1 << k));
    num &= mask;
}

int main()
{

    return 0;
}