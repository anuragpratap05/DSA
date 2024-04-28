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
    vector<int>ans(n,1);
    stack<int>s;
    s.push(0);
    int i=1;
    while(i<n)
    {
        while(!s.empty() and price[s.top()]<=price[i])
        {
            ans[i]+=ans[s.top()];
            s.pop();
        }
        s.push(i);
        i++;
    }
    return ans;
}

int main()
{
    return 0;
}