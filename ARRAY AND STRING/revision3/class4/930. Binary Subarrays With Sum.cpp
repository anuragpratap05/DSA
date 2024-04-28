#include <bits/stdc++.h>
using namespace std;
int kDistinctSubarrays(vector<int> &arr, int goal)
{
    int arraySize = arr.size();
    int prev = 0, curr = 0, len = 0;
    vector<int> freq(1e5 + 1, 0);
    // unordered_map<int, int> freq;
    int atMostSum = 0;
    while (curr < arraySize)
    {
        int ele = arr[curr];

        atMostSum += ele;

        while (atMostSum > goal)
        {
            int pEle = arr[prev];

            atMostSum -= pEle;

            prev++;
        }
        curr++;
        len += (curr - prev);
    }
    return len;
}
int numSubarraysWithSum(vector<int> &nums, int goal)
{
    int atMostGoal = kDistinctSubarrays(nums, goal);
    int atMostGoalMinus1 = goal - 1 > 0 ? kDistinctSubarrays(nums, goal - 1) : 0;
    return atMostGoal - atMostGoalMinus1;
}

int main()
{
    return 0;
}