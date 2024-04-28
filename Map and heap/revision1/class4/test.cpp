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



int main()
{
    unordered_set<int> s;
    s.insert(32);
    s.insert(74);
    s.insert(52);
    s.insert(35);
    s.insert(83);
    s.insert(34);
    s.insert(54);
    s.insert(99);
    srand(time(0));
    int idx = rand() % s.size();
    cout << idx<<endl;
    auto itr1 = s.begin();
    auto itr2 = s.begin(idx);
    int ele = *itr2;
    cout << ele;
    return 0;
}