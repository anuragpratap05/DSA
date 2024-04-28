#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> &nums)
{
    unordered_map<int, int> mp;
    for (int ele : nums)
    {
        mp[ele]++;
    }
    for (pair<int, int> p : mp)
    {
        if (mp[p.first] == 1)
        {
            return mp[p.first];
        }
    }
    return 0;
}

int singleNumberBits(vector<int> &nums)
{
    int tn = INT_MAX;
    int tnp1 = 0;
    int tnp2 = 0;
    for (int ele : nums)
    {
        int cwtn = (tn & ele);
        int cwtnp1 = (tnp1 & ele);
        int cwtnp2 = (tnp2 & ele);

        tn = (~cwtn) & tn;
        tnp1 = (tnp1 | cwtn);

        tnp1 = (~cwtnp1 & tnp1);
        tnp2 = (tnp2 | cwtnp1);

        tnp2 = (~cwtnp2 & tnp2);
        tn = (tn | cwtnp2);
    }
    return tnp1;
}

int main()
{
    return 0;
}