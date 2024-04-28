#include <bits/stdc++.h>
using namespace std;

vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> freq(1001, 0);
    for (int ele : nums1)
    {
        freq[ele]++;
    }
    vector<int> ans;
    for (int ele : nums2)
    {
        if (freq[ele]-- > 0)
        {
            ans.push_back(ele);
        }
    }
    return ans;
}

int main()
{
    return 0;
}