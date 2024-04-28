#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> &nums)
{
    int res=0;
    for(int e:nums)
    {
        res^=e;
    }
    return res;
}

int main()
{
    return 0;
}