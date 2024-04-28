#include <bits/stdc++.h>
using namespace std;

int perfectInsertPosofEle(vector<int> &nums, int ele)
{
    int s = 0;
    int e = nums.size() - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (ele <= nums[mid])
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    if (s == nums.size())
        return s - 1;
    if (s - 1 >= 0 and nums[s - 1] == ele)
    {
        return s - 1;
    }
    return s;
}

vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    vector<int> ans;
    int idx = perfectInsertPosofEle(arr, x);
    cout << "idx->" << idx << endl;
    int s = idx - 1;
    int e = idx;
    while (ans.size() < k)
    {
        if (s >= 0 and e < arr.size())
        {
            if (abs(x - arr[s]) <= abs(x - arr[e]))
            {
                ans.push_back(arr[s]);
                s--;
            }
            else
            {
                ans.push_back(arr[e]);
                e++;
            }
        }
        else
        {
            if (s >= 0)
            {
                ans.push_back(arr[s]);
                s--;
            }
            else
            {
                ans.push_back(arr[e]);
                e++;
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    return 0;
}