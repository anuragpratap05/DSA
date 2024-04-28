#include <bits/stdc++.h>
using namespace std;

int equal_set(vector<int> &nums, int sum1, int sum2, string set1, string set2, int idx)
{
    if (idx == nums.size())
    {
        if (sum1 == sum2)
        {
            cout << set1 << " = " << set2 << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;
    count += equal_set(nums, sum1 + nums[idx], sum2, set1 + to_string(nums[idx])+" ", set2, idx + 1);
    count += equal_set(nums, sum1, sum2 + nums[idx], set1, set2 + to_string(nums[idx])+" ", idx + 1);
    return count;
}

int main()
{
    vector<int>nums={10,20,30,40,50,60,70,80};
    cout << equal_set(nums, 10, 0, " 10 ", "", 1);
    return 0;
}