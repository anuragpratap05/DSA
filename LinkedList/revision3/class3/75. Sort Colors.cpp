#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int> &nums)
{
    int zero = -1;
    int two = nums.size();
    int cur = 0;

    while (cur != two)
    {
        int ele = nums[cur];
        if (ele == 0)
        {
            zero++;
            swap(nums[cur], nums[zero]);
            cur++;
        }
        else if (ele == 2)
        {
            two--;
            swap(nums[cur], nums[two]);
        }
        else
            cur++;
    }
}

int main()
{
    return 0;
}