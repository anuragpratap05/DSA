#include<bits/stdc++.h>
using namespace std;
bool hammingWeight_btr(uint32_t n)
{
    int c = 0;
    while (n != 0)
    {
        c++;
        if (c > 1)
        {
            return false;
        }
        n = (n & (n - 1));
    }
    return true;
}

bool isPowerOfTwo(int n)
{
    if (n <= 0)
    {
        return false;
    }
    return hammingWeight_btr(n);
}
bool isPowerOfFour(int n)
{
    if (!isPowerOfTwo(n))
    {
        // cout<<"aya";
        return false;
    }
    int c = 0;
    while (n != 0)
    {

        n = n >> 1;
        c++;
    }
    c = c - 1;
    if (c & 1)
    {
        return false;
    }
    return true;
}

int main()
{
    return 0;
}