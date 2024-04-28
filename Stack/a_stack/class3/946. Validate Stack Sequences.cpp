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
    int i = 0, j = 0;
    stack<int> s;
    // s.push(pushed[0]);
    while (i < n)
    {
        s.push(pushed[i]);
        while (!s.empty() and popped[j] == s.top())
        {
            s.pop();
            j++;
        }

        i++;
    }
    cout << s.size();
    return s.empty();
}

int main()
{
    return 0;
}