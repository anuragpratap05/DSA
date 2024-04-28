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

class StockSpanner
{
public:
    stack<pair<int, int>> st;
    StockSpanner()
    {
    }

    int next(int price)
    {
        pair<int,int> p = {price, 1};
        while (!st.empty() and st.top().first <= price)
        {
            p.second += st.top().second;
            st.pop();
        }
        st.push(p);
        return p.second;
    }
};

int main()
{
    return 0;
}