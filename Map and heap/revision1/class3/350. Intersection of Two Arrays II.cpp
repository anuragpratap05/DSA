#include<bits/stdc++.h>
using namespace std;



vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> freq(1001, 0);
    for(int e:nums1)
    {
        freq[e]++;
    }
    vector<int> ans;
    for (int e : nums2)
    {
        if(freq[e]>0)
        {
            freq[e]--;
            ans.push_back(e);
        }
    }
    return ans;
}

vector<int> intersect2(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int,int> freq;
    for (int e : nums1)
    {
        freq[e]++;
    }
    vector<int> ans;
    for (int e : nums2)
    {
        if (freq[e] > 0)
        {
            freq[e]--;
            ans.push_back(e);
        }
    }
    return ans;
}

int main()
{
    return 0;
}