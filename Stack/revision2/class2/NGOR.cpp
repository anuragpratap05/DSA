#include <bits/stdc++.h>
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

vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    stack<long long> st;
    vector<long long> ans(n, -1);
    for (int i = 0; i < n; i++)
    {
        long long ele = arr[i];

        while (!st.empty() and ele > arr[st.top()])
        {
            ans[st.top()] = ele;
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