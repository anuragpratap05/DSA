#include<bits/stdc++.h>
using namespace std;


class TreeNode
{
    public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode(int val)
    {
    this->val = val;
    }
};

vector<int> calculateSpan(int price[], int n)
{
    stack<int> st;
    vector<int>ans(n, 1);
    for (int i = 0; i < n;i++)
    {
        int ele = price[i];
        while(!st.empty() and price[st.top()]<=ele)
        {
            ans[i] += ans[st.top()];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

int main()
{
    return 0;
}