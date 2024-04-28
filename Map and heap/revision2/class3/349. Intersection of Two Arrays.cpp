#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    vector<bool> present(1001, false);
    for (int ele : nums1)
    {
        present[ele] = true;
    }
    vector<int> ans;
    for (int ele : nums2)
    {
        if (present[ele])
        {
            ans.push_back(ele);
            present[ele] = false;
        }
    }
    return ans;
}

int main()
{
    return 0;
}