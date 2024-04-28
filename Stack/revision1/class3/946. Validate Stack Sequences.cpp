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

bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
{
    int n = pushed.size();
    stack<int> st;
    int j = 0;

    for (int i = 0; i < n;i++)
    {
        int ele = pushed[i];
        st.push(ele);
        while(!st.empty() and st.top()==popped[j])
        {
            st.pop();
            j++;
        }
    }
    return st.empty();
}

int main()
{
    return 0;
}