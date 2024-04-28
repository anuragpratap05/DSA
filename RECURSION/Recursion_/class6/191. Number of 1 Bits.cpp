#include<bits/stdc++.h>
using namespace std;

int hammingWeight(uint32_t n)
{
    int c=0;
    while(n!=0)
    {
        if((n&1))
        {
            c++;
        }
        n=(n>>1);
    }
    return c;
}
//btr
int hammingWeight_btr(uint32_t n)
{
    int c=0;
    while(n!=0)
    {
        c++;
        n=(n&(n-1));
    }
    return c;
}

int main()
{
    return 0;
}