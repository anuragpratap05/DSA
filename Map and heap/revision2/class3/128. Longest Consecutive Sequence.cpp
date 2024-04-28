#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> st;
    for (int ele : nums)
    {
        st.insert(ele);
    }
    int ans = 0;

    for (int ele : nums)
    {
        if (st.find(ele) != st.end())
        {
            int tempEle = ele;
            int cnt = 0;
            while (st.find(tempEle) != st.end())
            {
                cnt++;
                st.erase(tempEle);
                tempEle--;
            }

            tempEle = ele + 1;
            while (st.find(tempEle) != st.end())
            {
                cnt++;
                st.erase(tempEle);

                tempEle++;
            }
            ans = max(ans, cnt);
        }
    }
    return ans;
}

int main()
{
    return 0;
}