#include <bits/stdc++.h>
using namespace std;

int perfectInsertPos(vector<long long> &nums, long long tar)
{
    int n = nums.size();
    int s = 0, e = n - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (nums[mid] <= tar)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return s;
}

pair<long, long> indexes(vector<long long> v, long long x)
{
    int insertPosLast = perfectInsertPos(v, x);
    if (insertPosLast - 1 < 0 or v[insertPosLast - 1] != x)
    {
        return {-1, -1};
    }
    int insertPosFirst = perfectInsertPos(v, x - 1);
    return {insertPosFirst, insertPosLast - 1};
}

int main()
{
    return 0;
}