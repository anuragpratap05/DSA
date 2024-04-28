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

class StockSpanner
{
public:
    stack<pair<int, int>> s;
    StockSpanner()
    {
        
    }

    int next(int price)
    {
        pair<int,int>p={price,1};
        while(!s.empty() and s.top().first<=price)
        {
            p.second += s.top().second;
            s.pop();
        }
        s.push(p);
        return p.second;

    }
};

int main()
{
    return 0;
}