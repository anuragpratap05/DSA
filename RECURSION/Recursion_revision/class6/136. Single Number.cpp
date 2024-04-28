#include <bits/stdc++.h>
using namespace std;
// 137 and 260 is H.W.
int singleNumber(vector<int> &nums)
{
    int res = 0;
    for (int ele : nums)
    {
        res = (res ^ ele);
    }
    return res;
}

int main()
{
    return 0;
}